/****************************************************************************
 *
 * Project:   name
 *
 * @file      filename.c
 * @author    author
 * @date      [Creation date in format %02d.%02d.20%02d]
 *
 * @brief     description
 *
 ****************************************************************************/
 
#include <stdint.h>
#include <UserCAPI.h>
#include <UserCEvents.h>

#include "mcm.h"
#include "gsThread.h"
#include "gsMsgFiFo.h"

#define HANDLE_TEMP 0xFFF7
#define HANDLE_VOLT 0xFFF4

uint32_t  _numMCM = 0;
tGS_MCM *_pMCM = NULL;

tGsThread _Thread = NULL;
tGsMutex  _Mutex  = NULL;
int32_t   _Thread_Running   = 0;

uint32_t   _FiFo;

/****************************************************************************/

/* function code ************************************************************/

void SendLed(tGS_MCM *MCM, eMCM_Led_Color Color);
/****************************************************************************
**
**    Function      :
**
**    Description   :
**
**
**
**    Returnvalues  : none
**
*****************************************************************************/


void * MCM_Thread( void * arg)
{
  _Thread_Running = 1;
  while(_Thread_Running )
  {
    static uint32_t time_old = 0;
    int32_t mstick = GetMSTick();
    for(uint32_t i = 0; i < _numMCM; i++)
    {
      tGS_MCM * this = &_pMCM[i];
      if(this->polling_ms)
      {
        if(this->polling_ms < mstick - this->polling_t_old)
        {
          this->polling_t_old = mstick;
          tCanMessage tx_msg;
          tx_msg.channel = this->CAN;
          tx_msg.ext     = this->Ext;
          tx_msg.id      = this->RX_Id;
          tx_msg.len     = 8;
          tx_msg.res     = 0;
          tx_msg.data.u8[0] = 0x1C;
          tx_msg.data.u8[1] = 0xFF & HANDLE_TEMP;
          tx_msg.data.u8[2] = 0xFF & (HANDLE_TEMP >> 8);
          tx_msg.data.u8[3] = 0;
          tx_msg.data.u32[1]= 0;
          CANSendMsg(&tx_msg);
          usleep(1000);
          tx_msg.data.u8[1] = 0xFF & HANDLE_VOLT;
          tx_msg.data.u8[2] = 0xFF & (HANDLE_VOLT >> 8);
          CANSendMsg(&tx_msg);
          usleep(1000);
          switch(this->Type)
          {
            case MCMTYPE_MCM200:
              tx_msg.data.u8[0] = 0x02;
              tx_msg.data.u8[1] = 0xFF & this->MCM.MCM200.digOutHnd;
              tx_msg.data.u8[2] = 0xFF &(this->MCM.MCM200.digOutHnd>> 8);
              tx_msg.data.u8[3] = 0;
              tx_msg.data.u32[1]= this->MCM.MCM200.digOut;
              CANSendMsg(&tx_msg);
            break;
            case MCMTYPE_BT20:
              SendLed(this, MCM_LED_WHITE);
              SendLed(this, MCM_LED_RED);
            default: break;
          }


        }
        int32_t timeout = 5000;
        if(this->polling_ms)
        {
          timeout = 2 * this->polling_ms;
        }
        if(timeout  < (int32_t)(GetMSTick() - this->Last_Msg_ms))
        {
          this->state = 0;
        }
        else this->state = 1;
      }

    }

    //Zyklus 50 ms;
    int32_t usleeptime = 50000 - (GetMSTick() - time_old) * 1000;
    if(usleeptime < 0)
      usleeptime = 0;
    time_old = GetMSTick();
    usleep(usleeptime);
  }
  _Thread_Running = -1;
  _numMCM = 0;
  gsThreadExit(NULL);
  return NULL;
}

int32_t  MCM200_Callback(tCanMessage * msg)
{
  for(uint32_t i = 0; i < _numMCM; i++)
  {
    tGS_MCM *this = &_pMCM[i];
    if(msg->id == this->TX_Id)
    {
      this->Last_Msg_ms = GetMSTick();
      if((0x02 == msg->data.u8[0])
       ||(0x03 == msg->data.u8[0]))
      {
        int32_t Handle = msg->data.u8[1] + (msg->data.u8[2] << 8);
        int32_t Data = msg->data.u32[1];
        if(Handle == this->MCM.MCM200.digInHnd )
              this->MCM.MCM200.digIn = Data;

        else if(Handle == this->MCM.MCM200.digOutHnd )
              this->MCM.MCM200.digOut = Data;

        else if((Handle >= this->MCM.MCM200.anaInHnd)
              &&(Handle <  this->MCM.MCM200.anaInHnd + 4))
              this->MCM.MCM200.anaIn[Handle - this->MCM.MCM200.anaInHnd] = Data;

        else if(Handle  == HANDLE_VOLT)
        {
            this->Volt = Data;
        }
        else if(Handle  == HANDLE_TEMP)
        {
            this->Temp = Data;
        }
      }
    }
  }
  return 0;
}

int32_t  BT20_Callback(tCanMessage * msg)
{
  for(uint32_t i = 0; i < _numMCM; i++)
  {
    tGS_MCM *this = &_pMCM[i];
    if(msg->id == this->TX_Id)
    {
      this->Last_Msg_ms = GetMSTick();
      if((0x02 == msg->data.u8[0])
       ||(0x03 == msg->data.u8[0]))
      {
        int32_t Handle = msg->data.u8[1] + (msg->data.u8[2] << 8);
        int32_t Data = msg->data.u32[1];

        if(Handle  == HANDLE_VOLT)
        {
            this->Volt = Data;
        }
        else if(Handle  == HANDLE_TEMP)
        {
            this->Temp = Data;
        }
      }
      else if(0x17 == msg->data.u8[0])
      {
        gsMsgFiFoWrite(this->MCM.BT20.msgFiFo, &msg->data.u8[0], sizeof(msg->data), 0);
      }
    }
  }
  return 0;
}

void MCM_Cycle_BT20(tGS_MCM *pMCM)
{
  tCanMessage msg;
  tGS_BT20 *BT20;
  BT20 = &pMCM->MCM.BT20;
  BT20->KeyPressedNew  = 0;
  BT20->KeyReleasedNew = 0;
  if(gsMsgFiFoRead(BT20->msgFiFo, &msg.data.u8[0], sizeof(msg.data),0 ))
  {
    if(0x17 == msg.data.u8[0])
    {
      if(1 == msg.data.u8[1] )
      {
        BT20->Key_Act[0] = msg.data.u32[1];
      }
      else if(2 == msg.data.u8[1] )
      {
        BT20->Key_Act[1] = msg.data.u32[1];
      }
      if(msg.data.u8[2])
      {
        if(msg.data.u8[2] & 0x80)
        {
          BT20->KeyReleasedNew = msg.data.u8[2] & 0x7F;
        }
        else
        {
          BT20->KeyPressedNew  = msg.data.u8[2] & 0x7F;
        }
      }
    }
  }
  for(int32_t i = 0; i < 3; i++)
  {
    if(BT20->Led.Led[i] != BT20->Led.Led_Old[i])
    {
      BT20->Led.Led_Old[i] = BT20->Led.Led[i];
      SendLed(pMCM, i);
    }
  }
}

void MCM_Cycle(void)
{
  for(uint32_t i = 0; i < _numMCM; i++)
  {
    switch( _pMCM[i].Type)
    {
      case MCMTYPE_BT20:  MCM_Cycle_BT20(&_pMCM[i]); break;

      default:   break;
    }
  }
}

int32_t MCM_InitDevice(eMCM_TYPE Type, int32_t CAN, int32_t ext, int32_t MCM_TX, int32_t MCM_RX)
{
  int32_t idx = _numMCM;

  tGS_MCM * pNewMCM = realloc(_pMCM,sizeof(tGS_MCM) * (idx + 1));
  if(NULL == pNewMCM)
  {
    return -1;
  }
  _pMCM = pNewMCM;

  memset(&_pMCM[idx], 0, sizeof(tGS_MCM));
  tGS_MCM *this = &_pMCM[idx];
  this->RX_Id =MCM_RX;
  this->TX_Id =MCM_TX;
  this->Ext       = ext;
  this->CAN       = CAN;
  this->Last_Msg_ms = GetMSTick() + 10000;
  this->Type      = Type;
  _numMCM++;					//Index erst erhöhen, wenn MCM-Daten initialisiert sind.

  if(NULL == _Thread)
  {
 //     gsThreadMutexInit(&_Mutex,NULL);
      gsThreadCreate(&_Thread, NULL,MCM_Thread, NULL);
      _FiFo = CANCreateFiFo(256);
  }
  switch(this->Type)
  {
    case MCMTYPE_MCM200:
      this->MCM.MCM200.anaInHnd = 2016;
      this->MCM.MCM200.digInHnd = 2000;
      this->MCM.MCM200.digOutHnd= 2008;
      CANAddRxFilterCallBack(this->CAN,this->TX_Id,0x7FF, this->Ext,MCM200_Callback);
    break;

    case MCMTYPE_BT20:
      CANAddRxFilterCallBack(this->CAN,this->TX_Id,0x7FF, this->Ext,BT20_Callback);
      this->polling_ms = 2000;
      this->MCM.BT20.msgFiFo = gsMsgFiFoCreate(256);
    break;

    default:
    	return -1;
    break;
  }
  return idx;
}


void MCM_DeInit(void)
{
  if(NULL != _Thread)
  {
    _Thread_Running = 0;
    while(-1 != _Thread_Running)
    {
      usleep(1000);
    }
    gsThreadJoin(_Thread, NULL);
    //gsThreadMutexDestroy(_Mutex);
    _Thread = NULL;
    _numMCM = 0;
    free(_pMCM);
    _pMCM = NULL;
  }
}
int32_t MCM_SetPolling(uint32_t Hdl_MCM, uint32_t Polling_ms)
{
  if(Hdl_MCM < _numMCM)
  {
    _pMCM[Hdl_MCM].polling_ms = Polling_ms;
    return 0;
  }
  else return -1;
}

int32_t MCM_GetActiveStatus(uint32_t Hdl_MCM)
{
  if(Hdl_MCM < _numMCM)
  {
    return _pMCM[Hdl_MCM].state;
  }
  else return -1;
}

int32_t MCM_GetDigitalIn(uint32_t Hdl_MCM, uint32_t pos)
{
  if(Hdl_MCM < _numMCM)
  {
    if(MCMTYPE_MCM200 == _pMCM[Hdl_MCM].Type)
    {
      return 0x01 & (_pMCM[Hdl_MCM].MCM.MCM200.digIn >> pos);
    }
    else return -1;
  }
  return -1;
}

int32_t MCM_GetAnalogIn(uint32_t Hdl_MCM, uint32_t pos)
{
  if(Hdl_MCM < _numMCM)
  {
    if(MCMTYPE_MCM200 == _pMCM[Hdl_MCM].Type)
    {
      if(pos < 4)
      {
        return _pMCM[Hdl_MCM].MCM.MCM200.anaIn[pos];
      }
      else return -1;
    }
    else return -1;
  }
  return -1;
}

int32_t  MCM_GetTemperature(uint32_t Hdl_MCM)
{
  if(Hdl_MCM < _numMCM)
  {
    return _pMCM[Hdl_MCM].Temp;
  }
  else return -1;
}

int32_t MCM_GetVoltage(uint32_t Hdl_MCM)
{
  if(Hdl_MCM < _numMCM)
  {
    return _pMCM[Hdl_MCM].Volt;
  }
  else return -1;
}

int32_t  MCM_SetDigitalOut(uint32_t Hdl_MCM, uint32_t pos, uint32_t val)
{
  if(Hdl_MCM < _numMCM)
  {
    tGS_MCM * this = &_pMCM[Hdl_MCM];
    if(MCMTYPE_MCM200 == this->Type)
    {
      if(val)
          this->MCM.MCM200.digOut = this->MCM.MCM200.digOut | (0x1<<pos);
      else
      {
          this->MCM.MCM200.digOut = this->MCM.MCM200.digOut  &(~ (0x1<<pos) );
      }
          tCanMessage tx_msg;
          tx_msg.channel = this->CAN;
          tx_msg.ext     = this->Ext;
          tx_msg.id      = this->RX_Id;
          tx_msg.len     = 8;
          tx_msg.res     = 0;
          tx_msg.data.u8[0] = 0x02;
          tx_msg.data.u8[1] = 0xFF & this->MCM.MCM200.digOutHnd;
          tx_msg.data.u8[2] = 0xFF &(this->MCM.MCM200.digOutHnd>> 8);
          tx_msg.data.u8[3] = 0;
          tx_msg.data.u32[1]= this->MCM.MCM200.digOut;
          CANSendMsg(&tx_msg);

    }
    else return -1;
  }
  return 0;
}

int32_t MCM_IsKeyPressedNew(uint32_t MCM_Hdl, int32_t Key)
{
  if(MCM_Hdl < _numMCM)
  {
    switch (_pMCM[MCM_Hdl].Type)
    {
      case MCMTYPE_BT20:
        if(Key == _pMCM[MCM_Hdl].MCM.BT20.KeyPressedNew)
          return 1;
        else return 0;
        break;

      default:
        return -1;
        break;
    }
  }
  return -1;
}

int32_t MCM_IsKeyReleasedNew(uint32_t MCM_Hdl, int32_t Key)
{
  if(MCM_Hdl < _numMCM)
  {
    switch (_pMCM[MCM_Hdl].Type)
    {
      case MCMTYPE_BT20:
        if(Key == _pMCM[MCM_Hdl].MCM.BT20.KeyReleasedNew)
          return 1;
        else return 0;
        break;

      default:
        return -1;
        break;
    }
  }
  return -1;
}

int32_t MCM_IsKeyDown(uint32_t MCM_Hdl, int32_t Key)
{
  if(MCM_Hdl < _numMCM)
  {
    switch (_pMCM[MCM_Hdl].Type)
    {
      case MCMTYPE_BT20:
        if(Key <= 32)
          return (_pMCM[MCM_Hdl].MCM.BT20.Key_Act[0] >> (Key-1)) & 0x01 ;

        else if(Key <= 64)
          return (_pMCM[MCM_Hdl].MCM.BT20.Key_Act[1] >> (Key-33)) & 0x01 ;
        break;
      default:
        return -1;
        break;
    }
  }
  return -1;
}

int32_t MCM_IsAnyKeyDown(uint32_t MCM_Hdl)
{
  if(MCM_Hdl < _numMCM)
  {
    switch (_pMCM[MCM_Hdl].Type)
    {
      case MCMTYPE_BT20:
      for(int32_t i = 0; i < 64; i++)
      {
        if(i <= 32)
        {
          if((_pMCM[MCM_Hdl].MCM.BT20.Key_Act[0] >> (i)) & 0x01)
            return i + 1;
        }
        else if(i <= 64)
        {
          if((_pMCM[MCM_Hdl].MCM.BT20.Key_Act[1] >> (i - 32)) & 0x01)
            return i +1;
        }
        break;
      default:
        return -1;
        break;
      }
    }
  }
  return -1;
}

void SendLed(tGS_MCM *MCM, eMCM_Led_Color Color)
{
  tMCM_Led *Led = NULL;;
  switch(MCM->Type)
  {
    case MCMTYPE_BT20:
      Led = &MCM->MCM.BT20.Led;
    break;
    default:
      return;
    break;
  }
  tCanMessage msg;
  msg.id  = MCM->RX_Id;
  msg.ext = MCM->Ext;
  msg.len = 8;
  msg.res = 0;
  msg.channel = MCM->CAN;
  msg.data.u8[0]  = 0x16;
  msg.data.u8[1]  = 0x03;
  msg.data.u16[1] = 0;
  msg.data.u32[1] = 0;
  switch(Color)
  {
    case MCM_LED_RED:
    case MCM_LED_GREEN:
      msg.data.u8[2] = 0;
      for(int32_t i = 0; i < 20; i++)
      {
        int8_t val_r = (Led->Led[MCM_LED_RED]   >> i) & 0x01;
        int8_t val_g = (Led->Led[MCM_LED_GREEN] >> i) & 0x01;
        uint8_t *data = &msg.data.u8[3 + i / 4];
        if(val_r)
          *data = *data | (val_r << ((2 * i) % 8));
        else
          *data = *data & ~(val_r << ((2 * i) % 8));
        if(val_g)
          *data = *data | (val_g << ((2 * i + 1) % 8));
        else
          *data = *data & ~(val_g << ((2 * i + 1) % 8));
      }
      CANSendMsg(&msg);
      msg.data.u8[2] = 5;
      msg.data.u8[3] = 0;
      msg.data.u32[1] = 0;
      for(int32_t i = 20; i < 40; i++)
      {
        int8_t val_r = (Led->Led[MCM_LED_RED]   >> i) & 0x01;
        int8_t val_g = (Led->Led[MCM_LED_GREEN] >> i) & 0x01;
        uint8_t *data = &msg.data.u8[3 + i / 4 - 5];
        if(val_r)
          *data = *data | (val_r << ((2 * i) % 8));
        else
          *data = *data & ~(val_r << ((2 * i) % 8));
        if(val_g)
          *data = *data | (val_g << ((2 * i + 1) % 8));
        else
          *data = *data & ~(val_g << ((2 * i + 1) % 8));
      }
      CANSendMsg(&msg);
    break;

    case MCM_LED_WHITE:
      msg.data.u8[2] = 12;
      for(int32_t i = 0; i < 40; i++)
      {
        int8_t val = (Led->Led[MCM_LED_WHITE] >> i) & 0x01;
        uint8_t *data = &msg.data.u8[3 + i / 8];
        if(val)
          *data = *data | (val << ((i+4) % 8));
        else
          *data = *data & (~(val << ((i+4) % 8)));
      }
      CANSendMsg(&msg);
      msg.data.u8[2] = 17;
      for(int32_t i = 40; i < 64; i++)
      {
        int8_t val = (Led->Led[MCM_LED_WHITE] >> i) & 0x01;
        uint8_t *data = &msg.data.u8[3 + i / 8 -5];
        if(val)
          *data = *data | (val << ((i+4) % 8));
        else
          *data = *data & (~(val << ((i+4) % 8)));
      }
      CANSendMsg(&msg);
    break;
    default: break;

    break;
  }
}

void SetLed64(uint32_t MCM_Hdl, tMCM_Led *Led, uint8_t Key,eMCM_Led_Color Color,  uint8_t val)
{
  uint64_t *data = &Led->Led[Color];
  if(0 == Key)
  {
    if(val)
      *data = 0xFFFFFFFFFFFFFFFF;
    else
      *data = 0;
  }
  else
  {
    if(val)
    {
      *data = *data | ((uint64_t) 1 << (Key-1));
    }
    else
    {
     *data = *data & (~ ((uint64_t) 1 << (Key-1)));
    }
  }
}

int32_t MCM_SetKeyBacklight_White(uint32_t MCM_Hdl, uint32_t Key, uint8_t val)
{
  if(MCM_Hdl < _numMCM)
  {
    switch (_pMCM[MCM_Hdl].Type)
    {
      case MCMTYPE_BT20:     SetLed64(MCM_Hdl, &_pMCM[MCM_Hdl].MCM.BT20.Led,  Key,MCM_LED_WHITE,  val);   break;

      default:  break;
    }
  }
  return 0;
}



int32_t MCM_SetKeyBacklight_Green(uint32_t MCM_Hdl, uint32_t Key, uint8_t val)
{
  if(MCM_Hdl < _numMCM)
  {
    switch (_pMCM[MCM_Hdl].Type)
    {
      case MCMTYPE_BT20:     SetLed64(MCM_Hdl, &_pMCM[MCM_Hdl].MCM.BT20.Led,  Key,MCM_LED_GREEN,  val);   break;

      default:  break;
    }
  }
  return 0;
}


int32_t MCM_SetKeyBacklight_Red(uint32_t MCM_Hdl, uint32_t Key, uint8_t val)
{
  if(MCM_Hdl < _numMCM)
  {
    switch (_pMCM[MCM_Hdl].Type)
    {
      case MCMTYPE_BT20:     SetLed64(MCM_Hdl, &_pMCM[MCM_Hdl].MCM.BT20.Led,  Key,MCM_LED_RED,  val);   break;

      default:  break;
    }
  }
  return 0;
}
