/****************************************************************************
 *
 * Project:   name
 *
 * @file      filename.h
 * @author    author
 * @date      [Creation date in format %02d.%02d.20%02d]
 *
 * @brief     description
 *
 ****************************************************************************/

#ifndef MCM_H
#define MCM_H

typedef enum eagMCM_TYPE
{
 MCMTYPE_MCM200,
 MCMTYPE_BT20,
}eMCM_TYPE;

typedef enum eagMCM_Led_Color
{
  MCM_LED_WHITE,
  MCM_LED_RED,
  MCM_LED_GREEN,
}eMCM_Led_Color;

typedef struct tagMCM_Led
{
  uint64_t Led[3];
  uint64_t Led_Old[3];
}tMCM_Led;

typedef struct tagGS_MCM200
{
  uint32_t  digIn;     /* the digital input value  */
  uint32_t  digOut;    /* the digital output value */
  uint32_t  digOutErrSt; /* the digital out erro state*/


  uint16_t  anaIn[4];  /* the analog Input value */

  uint16_t  digInHnd;  /* the digital input handle */
  uint16_t  digOutHnd; /* the digital output handle */
  uint16_t  anaInHnd;  /* the analog input handle */
  uint16_t  ctnHnd;    /* the counter handle */

} tGS_MCM200;

typedef struct tagGS_BT20
{

   uint32_t Key_Act[2];
   uint32_t Key_Old[2];
   uint8_t  KeyPressedNew;
   uint8_t  KeyReleasedNew;
   tMCM_Led Led;
   void *   msgFiFo;

}tGS_BT20;

typedef struct tagGS_MCM
{
  uint32_t   polling_ms;
  uint32_t   polling_t_old;
  uint32_t   Ext;
  uint32_t   CAN;
  uint32_t   RX_Id;
  uint32_t   TX_Id;
  uint32_t   FiFo;
  uint32_t   Temp;
  uint32_t   Volt;
  uint32_t   Last_Msg_ms;
  uint32_t   state;
  eMCM_TYPE Type;
  union
  {
    tGS_MCM200 MCM200;
    tGS_BT20   BT20;
  }MCM;
}tGS_MCM;

int32_t MCM_InitDevice(eMCM_TYPE Type, int32_t CAN, int32_t ext, int32_t MCMTX, int32_t MCMRX);
void MCM_Cycle(void);
int32_t MCM_SetPolling(uint32_t Hdl_MCM, uint32_t Polling_ms);
int32_t MCM_GetActiveStatus(uint32_t Hdl_MCM);
int32_t MCM_GetDigitalIn(uint32_t Hdl_MCM, uint32_t pos);
int32_t MCM_GetAnalogIn(uint32_t Hdl_MCM, uint32_t pos);
int32_t MCM_GetTemperature(uint32_t Hdl_MCM);
int32_t MCM_GetVoltage(uint32_t Hdl_MCM);
int32_t MCM_SetDigitalOut(uint32_t Hdl_MCM, uint32_t pos, uint32_t val);

int32_t MCM_SetKeyBacklight_White(uint32_t MCM_Hdl, uint32_t Key, uint8_t val);
int32_t MCM_SetKeyBacklight_Red  (uint32_t MCM_Hdl, uint32_t Key, uint8_t val);
int32_t MCM_SetKeyBacklight_Green(uint32_t MCM_Hdl, uint32_t Key, uint8_t val);


int32_t MCM_IsAnyKeyDown(uint32_t MCM_Hdl);
int32_t MCM_IsKeyDown(uint32_t MCM_Hdl, int32_t Key);
int32_t MCM_IsKeyReleasedNew(uint32_t MCM_Hdl, int32_t Key);
int32_t MCM_IsKeyPressedNew(uint32_t MCM_Hdl, int32_t Key);

void    MCM_DeInit(void);

#endif
