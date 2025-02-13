/**
 * @file mcm.h
 *
 * THIS HEADER FILE MUST BE USED FOR IMPLEMENTING THE GRAF MCM C LIB INTO A NORMAL C PROJECT
 *
 * @author Heiko Ackermann<br><
 *         Graf-Syteco GmbH & Co. KG
 *
 * @date   created: 11.10.2007
 */
 
/*! @mainpage My Personal Index Page
 *
 * @section intro_sec Introduction
 *
 * This is the introduction.
 *
 * @section install_sec Installation
 *
 * @subsection step1 Step 1: Opening the box
 *  
 * etc...
 */
 
//------------------------------------------------------------------------------
// HEADER GUARDS
//------------------------------------------------------------------------------
#ifndef MCM_H_INCLUDED
#define MCM_H_INCLUDED

#if defined(MCQ) || defined(GDSPROJECT)
#include <stdint.h>
//------------------------------------------------------------------------------
// For backward compatibility
//------------------------------------------------------------------------------
#if defined(GDSPROJECT) && !defined(MCQ)
typedef struct tagCanMsg
{
    uint32_t MsgID;
    uint8_t  Data[8];
    uint8_t  Flags;
}tCanMsg;
#else //defined(GDSPROJECT)
#include <string.h>
#endif //defined(GDSPROJECT)

#else //defined(MCQ) || defined(GDSPROJECT)
 #include "conv.h"
 #include "koptotos.h"

 #define uint32_t  uint32
 #define  int32_t  int32
 #define uint16_t  uint16
 #define  int16_t  int16
 #define uint8_t   uint8
 #define  int8_t   int8

#endif
//------------------------------------------------------------------------------
// Defines for groups
//------------------------------------------------------------------------------
#define MCM_GROUP_LEFT            0
#define MCM_GROUP_RIGHT           1
#define MCM_GROUP_STOP_TRISTATE   1
#define MCM_GROUP_STOP_LOWSIDE    2
#define MCM_GROUP_STOP_HIGHSIDE   3
#define MCM_LOWSIDE               0
#define MCM_HIGHSIDE              1
#define MCM_TRISTATE              2
//------------------------------------------------------------------------------
// Defines for Error code
//------------------------------------------------------------------------------
#define MCM_ERR_NOT_IMPLEMENTED  -1
#define MCM_OK                    1
#define MCM_VALUE_TOO_BIG        -2
#define MCM_VALUE_TOO_SMALL      -3
#define MCM_UNKOWN_FUNCTION      -5
#define MCM_INVALID_VALUE        -4
#define MCM_NOT_NEW_VALUE         2
#define MCM_NO_ANSWER            -6
#define MCM_UNKOWN_TYPE          -7
#define MCM_DEVICE_NOT_READY     -8
//------------------------------------------------------------------------------
//  Defines for the LEDS
//------------------------------------------------------------------------------
#define MCM_RED_LED             0x1C
#define MCM_GREEN_LED           0x2C
#define MCM_BACKLIGHT           0x3C
#define MCM_SET_PWM          1 << 15
#define MCM_SET_MASK         1 << 15
//------------------------------------------------------------------------------
// Define for init polling
//------------------------------------------------------------------------------
#define MCM_INIT_POLL 500
//------------------------------------------------------------------------------
// Define for ms polling
//------------------------------------------------------------------------------
#define MCM_POLL_MS         1 << 15
//------------------------------------------------------------------------------
// Define for the new bus init process
//------------------------------------------------------------------------------
#define MCM_ENABLE_BUS_INIT 0x80000000
//------------------------------------------------------------------------------
// Structs
//------------------------------------------------------------------------------
typedef struct tagMCMModul tMCMModul;
//------------------------------------------------------------------------------
// Structure for storing pwm outputs
//------------------------------------------------------------------------------
typedef struct tagMCMWM
{
  uint32_t pulsewith;
  uint32_t frequency;
  uint8_t  enabled;
} tMCMPWM;
//------------------------------------------------------------------------------
// Structure for storing mcm groups
//------------------------------------------------------------------------------
typedef struct tagMCMGroup
{
   int direction;
   int stop;
} tMCMGroup;
//------------------------------------------------------------------------------
// Structure for storing mcmcounter
//------------------------------------------------------------------------------
typedef struct tagMCMCTN
{
  int32_t count;
  int32_t overflow;
} tMCMCTN;
//------------------------------------------------------------------------------
// Structure for the high current output
//------------------------------------------------------------------------------
typedef struct tagMCMHCOut
{
  int32_t  P;
  int32_t  I;
  int32_t  D;
  uint32_t time;

  uint32_t freq;
  uint32_t cursoll;
  uint32_t enabled;
  uint8_t  requestpwmcfg;

} tMCMHCOut;
//------------------------------------------------------------------------------
// Structure for the pid output
//------------------------------------------------------------------------------
typedef struct tagPID
{
  uint16_t  tar;
  uint16_t  p;
  uint16_t  i;
  uint16_t  d;
  uint16_t  freq;
  uint8_t   eng;

} tPID;
//------------------------------------------------------------------------------
//  Typedefs for function pointers
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
//      Buzzer function pointer:  Allows the using the buzzer of a device
//------------------------------------------------------------------------------
typedef int(*setBuzzerFunc)(tMCMModul* modul, int InBTrig,int InBMd,int InBOnT, int BOffT, int BNum);
//------------------------------------------------------------------------------
//   GetDigitalIn function pointer: Gets the digital input value of a device
//------------------------------------------------------------------------------
typedef int(*getDigitalInFunc)(tMCMModul* modul, uint16_t n);
//------------------------------------------------------------------------------
//   SetDigitalOut function pointer: Sets the digital output value of a device
//------------------------------------------------------------------------------
typedef int(*setDigitalOutFunc)(tMCMModul* modul, uint16_t n, uint16_t val);
//------------------------------------------------------------------------------
//   SetDigitalHCOut function pointer: Sets the digital high current output
//------------------------------------------------------------------------------
typedef int(*setDigitalHCOutFunc)(tMCMModul* modul, uint16_t n,uint8_t status );
//------------------------------------------------------------------------------
//   GetAnalogIn function pointer: Gets the analog input value
//------------------------------------------------------------------------------
typedef int(*getAnalogInFunc)(tMCMModul* modul, uint16_t n);
//------------------------------------------------------------------------------
//   SetAnalogOut function pointer: sets the analog output value
//------------------------------------------------------------------------------
typedef int(*setAnalogOutFunc)(tMCMModul* modul, uint16_t n, uint16_t val);
//------------------------------------------------------------------------------
//   GetDigitalOutErrorState function pointer: Gets the error state of a digital output
//------------------------------------------------------------------------------
typedef uint32_t(*getDigitalOutErrorStateFunc) (tMCMModul* modul);
//------------------------------------------------------------------------------
//   Receive function pointer: receives the can messages
//------------------------------------------------------------------------------
typedef int(*ReceiveFunc)(tCanMsg *MyMsg, tMCMModul* modul);
//------------------------------------------------------------------------------
//   Cycle function pointer: all cyclic processes are done in this function
//------------------------------------------------------------------------------
typedef int(*CycleFunc)(tMCMModul* modul);
//------------------------------------------------------------------------------
//   GetCounterValue function pointer: Gets the last counter value
//------------------------------------------------------------------------------
typedef int(*getCounterValueFunc)(tMCMModul* modul,uint8_t n, int32_t* val1, int32_t* val2);
//------------------------------------------------------------------------------
//   SetCounterReset function pointer: Resets the counter
//------------------------------------------------------------------------------
typedef int(*setCounterResetFunc)(tMCMModul* modul,uint16_t pos,uint32_t ctn,uint32_t overflow);
//------------------------------------------------------------------------------
//   SetPwmOutput function pointer: Sets the pwm output
//------------------------------------------------------------------------------
typedef int(*setPwmOutFunc)(tMCMModul* modul,uint8_t n, uint16_t pulswith,uint16_t frequency,uint8_t enabled);
//------------------------------------------------------------------------------
//   SetGroupOutput function pointer: Sets the analog output value
//------------------------------------------------------------------------------
typedef int(*setGroupOutFunc)(tMCMModul* modul,uint8_t n, uint8_t stop,uint8_t direction);
//------------------------------------------------------------------------------
//   SetDigitalOutDW0 function pointer: Sets the first 32 digital outputs of a device
//------------------------------------------------------------------------------
typedef int(*setDigitalOutDW0Func) (tMCMModul* modul,uint32_t value);
//------------------------------------------------------------------------------
//   GetDigitalOutDW0 function pointer: Gets the first 32 digital outputs of a device
//------------------------------------------------------------------------------
typedef uint32_t(*getDigitalInDW0Func)(tMCMModul* modul);
//------------------------------------------------------------------------------
//   GetDigitalOutDW1 function pointer: Gets the second 32 digital outputs of a device
//------------------------------------------------------------------------------
typedef uint32_t(*getDigitalInDW1Func)(tMCMModul* modul);
//------------------------------------------------------------------------------
//   GetDigitalOutDW2 function pointer: Gets the third 32 digital outputs of a device
//------------------------------------------------------------------------------
typedef uint32_t(*getDigitalInDW2Func)(tMCMModul* modul);
//------------------------------------------------------------------------------
//  SetGroupPwm function pointer: Sets the group pwm output
//------------------------------------------------------------------------------
typedef int(*setGroupPwmFunc)(tMCMModul* modul,uint8_t pos, uint16_t pulsewidth, uint16_t frequency, uint8_t stop, uint8_t direction);
//------------------------------------------------------------------------------
//     GetFrequencyValue function pointer: Sets a counter as frequency input counter
//------------------------------------------------------------------------------
typedef int(*getFrequencyValueFunc)(tMCMModul* modul,uint8_t n, uint32_t* val1, uint32_t* val2);
//------------------------------------------------------------------------------
//  SetPreset function pointer: sets the preset of a counter
//------------------------------------------------------------------------------
typedef int(*setPresetFunc)(tMCMModul* modul,uint8_t pos,uint32_t val1,uint32_t val2);
//------------------------------------------------------------------------------
//  GetAnalogOut function pointer: gets the analog output value
//------------------------------------------------------------------------------
typedef uint16_t(*getAnalogOutFunc)(tMCMModul* modul, uint16_t n);
//-----------------------------------------------------------------------------
//  GetDigitalOut function pointer: Gets the digital output value
//------------------------------------------------------------------------------
typedef uint8_t (*getDigitalOutFunc)(tMCMModul* modul, uint16_t n);
//------------------------------------------------------------------------------
//  GetPwmOut function pointer: Gets the values of the pwm output
//------------------------------------------------------------------------------
typedef int(*getPwmOutFunc) (tMCMModul* modul, uint8_t pos,uint16_t* pulswith,uint16_t* frequency,uint8_t* enabled);
//------------------------------------------------------------------------------
//  SetPwmCurCfg function pointer: Sets the configuration of the pwm output
//------------------------------------------------------------------------------
typedef int (*setPwmCurCfgFunc) (tMCMModul* modul,uint16_t ouput,int32_t P,int32_t I,int32_t D,uint32_t time,uint32_t freq);
//------------------------------------------------------------------------------
//    RequestPwmOutCfg function pointer: Requests the pwm out cfg
//------------------------------------------------------------------------------
typedef void (*requestPwmOutCfgFunc) (tMCMModul* modul,uint16_t ouput);
//------------------------------------------------------------------------------
//     GetPwmOutCfg function pointer: Gets the current value of the pwm output
//------------------------------------------------------------------------------
typedef int (*getPwmOutCfgFunc) (tMCMModul* modul,uint16_t output,int32_t* P,int32_t* I,int32_t* D,uint32_t* time,uint32_t* freq);
//------------------------------------------------------------------------------
//     SetPwmOutCur function pointer: Sets the current value of the pwm output
//------------------------------------------------------------------------------
typedef int (*setPwmOutCurFunc) (tMCMModul* modul,uint16_t output,uint32_t curSoll,uint8_t enabled);
//------------------------------------------------------------------------------
//     RepeatCounterMsg function pointer: Enables the repeat counter message
//------------------------------------------------------------------------------
typedef int (*repeatCounterMsgFunc) (tMCMModul* modul,uint8_t output,uint8_t onoff);
//------------------------------------------------------------------------------
//  SetRepeatCounter function pointer: the set Repeat CounterFunc
//------------------------------------------------------------------------------
typedef int (*setRepeatCounterFunc) (tMCMModul* modul,uint8_t output,uint16_t value);
//------------------------------------------------------------------------------
//  SetPidfunction pointer: the set pid function
//------------------------------------------------------------------------------
typedef int (*setPidFunc) (tMCMModul* modul,uint8_t pos,const uint16_t tar,const uint16_t p,const uint16_t i,const uint16_t d, const uint16_t freq,const uint8_t enabled);
//------------------------------------------------------------------------------
//     GetPid function pointer: The get pid function
//------------------------------------------------------------------------------
typedef int (*getPidFunc) (tMCMModul* modul,uint8_t pos,uint16_t* tar,uint16_t *p,uint16_t *i,uint16_t *d,uint16_t *freq,uint8_t *enabled);
//------------------------------------------------------------------------------
//    GetRepeatCounter function pointer: Gets the repeat counter value
//------------------------------------------------------------------------------
typedef int (*getRepeatCounterFunc) (tMCMModul* modul,uint8_t output);
//------------------------------------------------------------------------------
//     GetRotaryEncoder function pointer: The value of the rotate button position
//------------------------------------------------------------------------------
typedef int (*getRotaryEncoderFunc) (tMCMModul* modul,uint8_t pos);
//------------------------------------------------------------------------------
//  SetLedOut function pointer:  Sets the led of a device
//------------------------------------------------------------------------------
typedef int (*setLedOutFunc) (tMCMModul* modul,uint16_t n, uint16_t val,uint8_t type);
//------------------------------------------------------------------------------
typedef int (*getKeyPressedNewFunc) (tMCMModul* modul,uint8_t n);
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// Structure storing an at13 device
//------------------------------------------------------------------------------
typedef struct tagAT13
{
  uint32_t  digIn;  /* the digital input value  */
  uint32_t  digOut; /* the digital output value  */
  uint32_t  keyInNew;/* the digital  keys of the device*/
} tAT13;

//------------------------------------------------------------------------------
// Structure storing an at14 device
//------------------------------------------------------------------------------
typedef struct tagAT14
{
  uint32_t  digIn;  /* the digital input value  */
  uint32_t  keyInNew;/* the digital  keys of the device*/
  uint32_t  digOut; /* the digital output value  */
} tAT14;

//------------------------------------------------------------------------------
//  Structure storing a K1000 device
//------------------------------------------------------------------------------
typedef struct tagK1000
{
    uint8_t  keyIn;     /* the digital  keys of the device*/
    uint8_t  keyInNew;  /* the digital  keys of the device*/
    uint8_t  greenLed;  /* the green LEDs of the device*/
    uint8_t  redLed;    /* the red LEDs of the device */
    uint8_t  backLight; /* the backlight of the device*/
    uint8_t  pwm[4];    /* the pwm value of the device*/
} tK1000;
//------------------------------------------------------------------------------
//  Structure storing a K1100 device
//------------------------------------------------------------------------------
typedef struct tagK1100
{
    uint8_t   keyIn;     /* the digital  keys of the device*/
    uint8_t   keyInNew;  /* the digital  keys of the device*/
    uint16_t  greenLed;  /* the green LEDs of the device*/
    uint16_t  redLed;    /* the red LEDs of the device */
    uint8_t   backLight; /* the backlight of the device*/
    uint8_t   pwm[4];    /* the pwm value of the device*/
    uint16_t  RotaryEncoder[2];  /* the value of the rotate buttons of the device */

    uint16_t RotaryEncoderhandle[2]; /* the handles of the RotaryEncoders */
} tK1100;
//------------------------------------------------------------------------------
// Structure storing a mcm 200 device
//------------------------------------------------------------------------------
typedef struct tagMCM200
{

   uint32_t  digIn;     /* the digital input value  */
   uint32_t  digOut;    /* the digital output value */
   uint32_t  digOutErrSt; /* the digital out erro state*/

   tMCMCTN   counter[4];  /* the counter settings */

   uint16_t  anaIn[4];  /* the analog Input value */
   tMCMPWM   pwm  [4];    /* the pwm value */

   uint16_t  digInHnd;  /* the digital input handle */
   uint16_t  digOutHnd; /* the digital output handle */
   uint16_t  anaInHnd;  /* the analog input handle */
   uint16_t  ctnHnd;    /* the counter handle */



} tMCM200;
//------------------------------------------------------------------------------
// Structure storing a mcm 210 device
//------------------------------------------------------------------------------
typedef struct tagMCM210
{
   uint32_t  digIn;        /* the digital input value */
   uint32_t  digOut;       /* the digital output value */
   uint32_t  digOutErrSt;  /* the digital output error state*/
   uint32_t  hcDigOut;

   tMCMCTN   counter[4];   /* the counter settings */
   tMCMGroup groups [4];   /*the group setting */
   uint16_t  anaIn  [4]; /* the analog Input value */
   tMCMPWM   pwm    [4];   /* the pwm value */

   uint16_t  digInHnd;    /* the digital input handle */
   uint16_t  digOutHnd;   /* the digital output handle */
   uint16_t  anaInHnd;    /* the analog input handle */
   uint16_t  ctnHnd;      /* the counter handle */
   uint16_t  grpHnd;      /* the groups handle */


} tMCM210;
//------------------------------------------------------------------------------
// Structure storing a mcm 215 device
//------------------------------------------------------------------------------
typedef struct tagMCM215
{
   uint32_t  digIn;        /* the digital input value */
   uint32_t  digOut;       /* the digital output value */
   uint32_t  digOutErrSt;  /* the digital output error state*/

   tMCMCTN   counter[4];   /* the counter settings */
   uint16_t  anaIn  [12];/* the analog Input value */
   tMCMPWM   pwm    [4];   /* the pwm value */

   uint16_t  digInHnd;    /* the digital input handle */
   uint16_t  digOutHnd;   /* the digital output handle */
   uint16_t  anaInHnd;    /* the analog input handle */
   uint16_t  ctnHnd;      /* the counter handle */

} tMCM215;

//------------------------------------------------------------------------------
// Structure storing a mcm 220 device
//------------------------------------------------------------------------------
typedef struct tagMCM220
{
   uint32_t  digIn;        /* the digital input value */
   uint32_t  digOut;       /* the digital output value */
   uint32_t  digOutErrSt;  /* the digital output error state*/

   tMCMCTN   counter[4];   /* the counter settings */
   uint16_t  anaIn[12];    /* the analog Input value */
   tMCMPWM   pwm[4];       /* the pwm value */

   uint16_t  digInHnd;    /* the digital input handle */
   uint16_t  digOutHnd;   /* the digital output handle */
   uint16_t  anaInHnd;    /* the analog input handle */
   uint16_t  ctnHnd;      /* the counter handle */

} tMCM220;
//------------------------------------------------------------------------------
// Structure storing a mcm 221 device
//------------------------------------------------------------------------------
typedef struct tagMCM221
{

   uint32_t  digIn;        /* the digital input value        */
   uint32_t  digOut;       /* the digital output value       */
   uint32_t  digOutErrSt;  /* the digital output error state */

   tMCMPWM   pwm  [4];     /* the pwm value                  */
   tPID      pid  [4];     /* the pid controller             */
   uint16_t  anaIn[16+2];    /* the analog Input value         */
   tMCMCTN   counter[4];   /* the counter settings */

   uint16_t  digInHnd;     /* the digital input handle       */
   uint16_t  digOutHnd;    /* the digital output handle      */
   uint16_t  anaInHnd;     /* the analog input handle        */
   uint16_t  pidHnd;       /* the pid handle                 */
   uint16_t  pwmHnd;       /* the pwm handle                 */
   uint16_t  ctnHnd;      /* the counter handle */

} tMCM221;

//------------------------------------------------------------------------------
//  Structure storing a mcm 230 device
//------------------------------------------------------------------------------
typedef struct tagMCM230
{
   uint32_t  digIn;        /* the digital input value     */
   uint32_t  digOut;       /* the digital output value    */
   uint32_t  digOutErrSt;  /* the digital output error state*/

   tMCMPWM   pwm  [4];    /* the pwm value     */
   tMCMHCOut hcout[4];    /* the high current output      */
   uint16_t  anaIn[12+2];   /* the analog Input value */
   uint16_t  digInHnd;    /* the digital input handle     */
   uint16_t  digOutHnd;   /* the digital output handle    */
   uint16_t  anaInHnd;    /* the analog input handle      */
   uint16_t  pwmHnd;      /* the pwm handle               */

}tMCM230;


//------------------------------------------------------------------------------
// Structure storing a mcm 241 device
//------------------------------------------------------------------------------
typedef struct tagMCM241
{
   uint32_t digIn[3];    /* the digital input values    */
   uint32_t digOut;      /* the digital output value     */
   uint32_t digOutErrSt; /* the digital output error state    */

   tMCMCTN counter[4];   /* the counter settings     */

   uint16_t digInHnd;    /* the digital input handle     */
   uint16_t digOutHnd;   /* the digital output handle    */
   uint16_t ctnHnd;      /* the counter handle        */

} tMCM241;


//------------------------------------------------------------------------------
// Structure storing a mcm 221 device
//------------------------------------------------------------------------------
typedef struct tagMCM250
{

   uint32_t  digIn;        /* the digital input value        */
   uint32_t  digOut;       /* the digital output value       */
   uint32_t  digOutErrSt;  /* the digital output error state */

   tMCMPWM   pwm  [4];     /* the pwm value                  */
   tPID      pid  [4];     /* the pid controller             */
   uint16_t  anaIn[12+2];  /* the analog Input value         */
   tMCMCTN   counter[4];   /* the counter settings */

   uint16_t  digInHnd;     /* the digital input handle       */
   uint16_t  digOutHnd;    /* the digital output handle      */
   uint16_t  anaInHnd;     /* the analog input handle        */
   uint16_t  pwmHnd;       /* the pwm handle                 */
   uint16_t  ctnHnd;       /* the counter handle             */

} tMCM250;

//------------------------------------------------------------------------------
// Structure storing a mcm 300  device
 //------------------------------------------------------------------------------
typedef struct tagMCM300
{
   uint32_t  digIn;        /* the digital input value      */
   uint32_t  digOut;       /* the digital output value     */
   uint32_t  anaIn [10];   /* the analog Input value       */
   uint16_t  anaOut[6];    /* the analog output value      */


   uint16_t  digInHnd;     /* the digital input handle     */
   uint16_t  digOutHnd;    /* the digital output handle    */
   uint16_t  anaInHnd;     /* the analog input handle      */
   uint16_t  anaOutHnd;    /* the analog output handle     */

} tMCM300;

//------------------------------------------------------------------------------
// Structure storing all information of a device
//------------------------------------------------------------------------------
struct tagMCMModul
{
    //------------------------------------------------------------------------------
    //   the device is a union of all mcm device types described above
    //------------------------------------------------------------------------------
    union tagModules
    {
                tAT13   at13;    /*     the at13 device       */
                tAT13   at14;    /*     the at14 device       */
                tMCM200 mcm200;  /*     the mcm200 device     */
                tMCM210 mcm210;  /*     the mcm210 device     */
                tMCM241 mcm241;  /*     the mcm241 device     */
                tMCM300 mcm300;  /*     the mcm300 device     */
                tMCM215 mcm215;  /*     the mcm215 device     */
                tMCM220 mcm220;  /*     the mcm220 device     */
                tMCM221 mcm221;  /*     the mcm221 device     */
                tMCM230 mcm230;  /*     the mcm230 device     */
                tMCM250 mcm250;  /*     the mcm250 device     */
                tK1000  k1000;   /*     the k1000 device      */
                tK1100  k1100;   /*     the k1100 device      */

    } device;

    getDigitalInFunc getDigitalIn;         /* the getDigitalInFunc     */
    setDigitalOutFunc setDigitalOut;       /* the getDigitalOutFunc    */
    getDigitalOutFunc getDigitalOut;       /* the getDigitalOutFunc    */
    getAnalogInFunc getAnalogIn;           /* the getAnalogInFunc      */
    setAnalogOutFunc setAnalogOut;         /* the setAnalogOutFunc     */
    getAnalogOutFunc getAnalogOut;         /* the getAnalogOutFunc     */
    getCounterValueFunc getCounterValue;   /* the getCounterValueFunc  */
    setCounterResetFunc setCounterReset;   /* the getCounterResetFunc  */
    setPwmOutFunc setPwmOut;               /* the setPwmOut            */
    ReceiveFunc receive;                   /* the ReceiveFunc          */
    CycleFunc cycle;                       /* the CycleFunc            */
    setGroupOutFunc setGroupOut;           /* the setGroupOutFunc      */
    setDigitalOutDW0Func setDigitalOutDW0; /* setDigitalOutFunc        */
    getDigitalInDW0Func getDigitalInDW0;   /* the getDigitalDW0Func    */
    getDigitalInDW1Func getDigitalInDW1;   /* the getDigitalInDW1Func  */
    getDigitalInDW2Func getDigitalInDW2;   /* the getDigitalInDW2Func  */
    setGroupPwmFunc setGroupPwm;           /* the setGroupPwm          */
    setDigitalHCOutFunc setDigitalHCOut;   /* the setDigitalHCOut      */
    getDigitalOutErrorStateFunc getDigitalOutErrorState; /* the getDigitalOutErrorState   */
    getFrequencyValueFunc getFrequencyValue; /* gets the Frequency value     */
    setPresetFunc setPreset;               /* sets the preset of a counter   */
    setBuzzerFunc setBuzzer;               /* the Buzzer of the  at devices   */
    getPwmOutFunc getPwmOut;               /* the Pwm Output function     */
    setPwmCurCfgFunc setPwmCurCfg;         /* the set Pwm Current Configuration function   */
    getPwmOutCfgFunc getPwmCurOutCfg;      /* the get Pwm Current function     */
    setPwmOutCurFunc setPwmOutCur;         /* the set Pwm Output current function    */
    requestPwmOutCfgFunc requestPwmOutCfg; /* request the pwm out configuration     */
    repeatCounterMsgFunc repeatCounterMsg; /* the function for en or disabling the repeatcounter msg   */
    setRepeatCounterFunc setRepeatCounter; /* the function for setting the repeat counter     */
    getRepeatCounterFunc getRepeatCounter; /* the function for getting the repeat counter value    */
    getRotaryEncoderFunc getRotaryEncoderPos;/* the function for getting the rotate button position */
    setLedOutFunc       setLedOut;         /* this functions sets the LEDs of a device */
    setPidFunc          setPid;            /* the function for setting a pid value */
    getPidFunc          getPid;            /* the function for getting a pid value */
    getKeyPressedNewFunc getKeyPressedNew; /* the function for getting the value of a key */ 

    char firmw[16];                        /** the firmware of the device */
    int  polling;                          /* how many cycles occur before a polling operation is started     */
    int  cycles;                           /* the internal cycles counter     */
    int       temp;                        /* the temperature     */
    uint16_t  ipoll;                       /* the startup of the device */
    uint16_t  ipoll2;                      /* the startup of the device */
    uint32_t  rxID;                        /* the receive ID of the device    */
    uint32_t  txID;                        /* the transmit id of the device     */
    uint32_t  volt;                        /* the voltage      */
    uint16_t  acpoll;                      /* the cyclic counter of the active polling    */
    uint8_t   CAN01;                       /* which can port is used      */
    uint8_t   BIT29ID;                     /* if large 29 bit identifiers are used    */
    uint8_t   active;                      /* if the device is active    */
    uint8_t   inited;                      /* if the device is inited    */ 

};

#ifdef __cplusplus
extern "C" {
#endif //__cplusplus

/**
 *  MCMCycle is the cyclic function of all mcm devices.
 *  It has to be used inside the cyclic function of the designer.
 *  Only inside this function CAN messages will be received.
 */
void MCM_Cycle(void);
/**
 * MCMRLibInit inits the complete mcm lib.
 * The programmer has to generate a tMCMModul array outside of the library.
 * This array is then used inside the mcm library.
 *
 * @param m_mods    pointer of the module array
 * @param n         the number of modules if you want to use the init bus mechanismn of the mcm c lib use the MCM_ENABLE_BUS_INIT flag for enabling n | MCM_ENABLE_BUS_INIT
 *
 * @return MCM_OK else error code
 */
int MCM_LibInit(tMCMModul* m_mods, uint32_t n);
/**
* MCM_SetGroup is the function for setting a group output of a mcm device
*
* @param i          the position in the mcm modules array
* @param pos        the number of the group you want to activate
* @param stop       stops the group
* @param direction  the direction in which the motor runs
*
* @return 1 if OK else error code
*/
int MCM_SetGroup(uint16_t i,uint8_t pos,uint8_t stop, uint8_t direction);
/**
 * MCM_CounterReset is the function for setting a counter reset
 *
 * @param i         the position in the mcm modules array
 * @param pos       the counter you want to reset
 * @param ctn       the new counter value of the counter
 * @param overflow  the new overflow counter value
 *
 * @return 1 if OK else error code
 */
int MCM_CounterReset(uint16_t i,uint16_t pos,uint32_t ctn,uint32_t overflow );
/**
 * MCM_GetCounterValue is the function for getting a counter value
 *
 * @param i         the position in the mcm modules array
 * @param pos       the number of the group you want to activate
 * @param val1      the first value is the value of the counter
 * @param val2      the second value is the overflow of the counter
 *
 * @return 1 if OK else error code
 */
int MCM_GetCounterValue(uint16_t i, uint8_t pos,int32_t* val1,int32_t* val2);
/**
 * MCM_GetFrequencyValue is the function for getting a frequency value
 *
 * @param i         the position in the mcm modules array
 * @param pos       the number of the group you want to activate
 * @param val1      the first value is the frequency of the counter
 * @param val2      the second value is the period of the counter
 *
 * @return 1 if OK else error code
 */
int MCM_GetFrequencyValue(uint16_t i, uint8_t pos,uint32_t* val1,uint32_t* val2);
/**
 * MCM_ GetAnalogIn is the function for getting the value of an analog input
 *
 * @param i         the position in the mcm modules array
 * @param pos       the number of the analog input you want to activate
 *
 * @return          the analog input value
 */
int MCM_GetAnalogIn(uint16_t i, uint16_t pos);
/**
 * MCM_SetAnalogOut is the function for setting an analog output value
 *
 * @param  i        the position in the mcm modules array
 * @param  pos      the number of the analog output you want to activate
 * @param  val      the value of the analog output
 *
 * @return  1 if OK else error code
 */
int MCM_SetAnalogOut(uint16_t i, uint16_t pos, uint32_t val);
/**
 * MCM_GetAnalogOut is the function for getting a analog value
 *
 * @param i         the position in the mcm modules array
 * @param pos       the number of the analog output you want to read
 *
 * @return          the value of the analog output
 */
int MCM_GetAnalogOut(uint16_t i, uint16_t pos);

/**
 * MCM_GetDigitalIn is the function for getting a digital value
 *
 * @param i         the position in the mcm modules array
 * @param pos       the number of the digital input you want to activate
 *
 * @return          the digital input value
 */
int MCM_GetDigitalIn(uint16_t i, uint16_t pos);
/**
 * MCM_SetDigitalOut is the function for setting a digital value
 *
 * @param i         the position in the mcm modules array
 * @param pos       the number of the digital output you want to activate
 * @param val       the value of the digital output
 *
 * @return 1        if OK else error code
 */
int MCM_SetDigitalOut(uint16_t i, uint16_t pos, uint8_t val);
/**
 * MCM_GetDigitalOut is the function for getting a digital value
 *
 * @param i         the position in the mcm modules array
 * @param pos       the number of the digital output you want to activate
 *
 * @return          the value of the output
 */
int MCM_GetDigitalOut(uint16_t i,uint16_t pos);
/**
 * MCM_SetPwmOut is the function for setting a pwm output
 *
 * @param i         the position in the mcm modules array
 * @param pos       the number of pwm output you want to activate
 * @param pulswidth the pulse width of the pwm
 * @param frequency the frequency of the pwm
 * @param enabled   if the pwm output is enabled
 *
 * @return 1        if OK else error code
 */
int MCM_SetPWMOut(uint16_t i, uint8_t pos,uint16_t pulswidth,uint16_t frequency,uint8_t enabled);
/**
 * MCM_GetPwmOut is the function for getting a PWM outoput
 *
 * @param i           the position in the mcm modules array
 * @param pos         the number of pwm output you want to activate
 * @param pulswidth   the pulse width of the pulse
 * @param frequency   the frequency of the pulse
 * @param enabled     if the PWM output is enabled
 *
 * @return 1          if OK else error code
 */
int MCM_GetPWMOut(uint16_t i, uint8_t pos,uint16_t* pulswidth,uint16_t* frequency,uint8_t* enabled);
/**
 * MCM_SetPid is the function for setting a proportional–integral–derivative output
 *
 * @param i         the position in the mcm modules array
 * @param pos       the number of the output
 * @param tar       the target current
 * @param p         the proportional parameter
 * @param in        the integral parameter
 * @param d         the derivative parameter
 * @param freq      the frequency of the pid
 * @param enabled   if the pid is enabled or not
 *
 * @return 1        if OK else error code
 */
int MCM_SetPid(uint16_t i,uint8_t pos,const uint16_t tar,const uint16_t p,const uint16_t in,const uint16_t d, const uint16_t freq,const uint8_t enabled);
/**
 * MCM_GetPid is the function for getting the parameters of an used proportional–integral–derivative output
 *
 * @param i         the position in the mcm modules array
 * @param pos       the number of the output
 * @param tar       the target current
 * @param p         the proportional parameter
 * @param in        the integral parameter
 * @param d         the derivative parameter
 * @param freq      the frequency of the pid
 * @param enabled   if the pid is enabled or not
 *
 * @return 1        if OK else error code
 */
int MCM_GetPid(uint16_t i,uint8_t pos,uint16_t *tar,uint16_t *p,uint16_t *in,uint16_t *d, uint16_t *freq,uint8_t *enabled);
/**
* MCM_GetTemperature is the function for getting the temperature of the device
*
* @param i          the position in the mcm modules array
*
* @return           the temperature of the device
*/
int MCM_GetTemperature(uint16_t i);
/**
* MCM_GetVoltage is the function for getting the voltage of the device
*
* @param i          the position in the mcm modules array
*
* @return the voltage of the device
*/
int MCM_GetVoltage(uint16_t i);
/**
* MCM_SetELFoil sets the EL foil display if available
*
* @param i          the array pointer of the device
* @param enabled    if the EL is enabled or not
*
* @return 1 if OK else error code
*/
int MCM_SetELFoil(uint16_t i,uint8_t enabled);
/**
* MCM_SetDigitalOutDW0 sets the first 32 digital outputs of device at once
*
* @param i          the array pointer of the device
* @param value      value the new value of the outputs
*
* @return 1         if OK else error code
*/
int MCM_SetDigitalOutDW0(uint16_t i,uint32_t value);
/**
* MCM_GetDigitalInDW0 returns the first 32 digital inputs of device at once
*
* @param i          the array pointer of the device
*
* @return           the result are the values of the first 32 digital inputs
**/
uint32_t MCM_GetDigitalInDW0(uint16_t i);
/**
* MCM_GetDigitalInDW1 returns  the second 32 digital inputs of device at once
*
* @param i          the array pointer of the device
*
* @return           the result are the second 32 digital inputs
*/
uint32_t MCM_GetDigitalInDW1(uint16_t i);
/**
* MCM_GetDigitalInDW2 returns the last32 digital inputs of device at once
*
* @param i          the array pointer of the device
*
* @return           the result are the last digital inputs
*/
uint32_t MCM_GetDigitalInDW2(uint16_t i);
/**
* MCM_SetBuzzer sets the Buzzer of the AT13Device
*
* @param i          the position in the mcm modules array
* @param InBTrig    if the buzzer is triggered
* @param InBMd      the mode of the buzzer
* @param InBOnT     how long the buzzer is active
* @param InBOffT    the off time of the buzzer
* @param InBONum    how many times the buzzer buzzes
*
* @return           MCM_OK else error code
**/
int MCM_SetBuzzer(uint16_t i,int InBTrig,int InBMd,int InBOnT, int InBOffT, int InBONum);
/**
* MCM_LED  is the function for setting the LED's of the at13 /at14 device
*
* @param i          the position in the mcm modules array 
* @param pos        the number of the digital output if you want to set a mask use the MCM_SET_MASK flag
* @param val        enabled = 1 / disabled = 0
*
* @return           1 if OK else error code
*/
int MCM_SetLED(uint16_t i, uint16_t pos, uint8_t val);
/**
* MCM_SetGroupPWM   sets the pwm group of a mcm device
*
* @param i          the position in the mcm modules array
* @param pos        the number of pwm output you want to activate
* @param pulsewidth the pulse width of the pulse
* @param frequency  the frequency of the pulse
* @param stop       stops the group
* @param direction  the direction in which the motor runs
*
* @return           1 if OK else error code
*/
int MCM_SetGroupPWM(uint16_t i,uint8_t pos, uint16_t pulsewidth, uint16_t frequency, uint8_t stop, uint8_t direction);
/**
* MCM_SetDigitalHCOut sets the high current output of a mcm device
*
* @param i          the position in the mcm modules array
* @param n          the number of digital output you want to activate
* @param status     the status of the high current output
*
* @return           1 if OK else error code
*/
int MCM_SetDigitalHCOut(uint16_t i, uint16_t n,uint8_t status);
/**
* MCM_GetDigitalOutErrorState returns the digital out error state
*
* @param            i the position in the mcm modules array
*
* @return           the error state
*/
uint32_t MCM_GetDigitalOutErrorState(uint16_t i);
/**
* MCM_SetPreset     the set preset function for counter inputs of a mcm device
*
* @param i          the position in the mcm modules array
* @param pos        the counter
* @param value1     the first preset
* @param value2     the second preset
*
* @return           1 if OK else error code
*/
int MCM_SetPreset(uint16_t i,uint8_t pos,uint32_t value1,uint32_t value2);
/**
* MCM_GetError      the count of can receveied errors / not processed can telegrams
*
* @return           this functions returns the actual count of occurred can receive errors
*/
int MCM_GetError(void);
/**
* MCM_GetActiveStatus returns if the mcm device is active
*
* @param  i         the position in the mcm modules array
*
* @return           1 if the module is still active 0 if the module is not active
*/
int MCM_GetActiveStatus(uint16_t i);
/**
* MCM_RepeatCounter enables or disables the repeat counter
*
* @param i          the position in the mcm modules array
* @param pos        the counter position
* @param            onoff enables the repeat counter
*
* @return           1 if OK else error code
*/
int MCM_RepeatCounterMsg(uint16_t i,uint8_t pos,uint8_t onoff);
/**
* MCM_SetRepeatCounter sets the repeat counter
*
* @param i          the position in the mcm modules array
* @param pos        the counter position
* @param value      the new value of the counter
*
* @return           1 if OK else error code
*/
int MCM_SetRepeatCounter(uint16_t i,uint8_t pos,uint16_t value);
/**
* MCM_GetRepeatCounter returns the value of the repeat counte
*
* @param i          the position in the mcm modules array
* @param pos        the counter position
*
* @return           returns the value of the repeat counter
*/
int MCM_GetRepeatCounter(uint16_t i,uint8_t pos);
/**
*  MCM_SetLedOut    enables or disables the led
*
*  @param i         the position of the mcm modules array
*  @param n         the output if you want to set a mask use the MCM_SET_MASK flag
*  @param val       the value of the led if you want to set the pwm use the MCM_SET_PWM Flag
*  @param type      the type of the led
*
*  @return          1 if no error occurred else error code
*/
int MCM_SetLedOut(uint16_t i,uint16_t n, uint16_t val,uint8_t type);
/** MCM_GetRotaryEncoderPos returns the positon of the rotary button
*
*  @param i         the position in the mcm modules array
*  @param pos       the number of the rotate button
*
*  @return          the value of the rotate button
*/
int MCM_GetRotaryEncoderPos(uint16_t i,uint8_t pos);
/** MCM_GetFrmVersion  returns actual firmware version of the device
*
*   @param i         the position in the mcm modules array
*
*   @return          the firmware version NULL if invalid value i
*/
const char* MCM_GetFrmVersion(uint16_t i);
/** MCM_IsKeyPressedNew returns if the key is during one cycle pressed
*
*  @param i         the position in the mcm modules array
*  @param pos       the number of the key
*
*  @return          the value of the key
*/
int MCM_IsKeyPressedNew(uint16_t i,uint8_t pos);

/**
 * MCM_CreateK1000 is the function for generating a K1000 device
 *
 * @param i         this the position in the mcm modules array
 * @param rxID      the rxID
 * @param txID      the txID
 * @param CAN01     if CAN 0 or CAN 1 is used
 * @param BIT29ID   if 29 bit identifiers  are used
 * @param polling   how many cycles before the temperature is received (0 = polling off) if the flag MCM_POLL_MS is used polling time is in ms
 *
 * @return          MCM_OK else error code
 */
int MCM_CreateK1000(uint16_t i,uint32_t rxID, uint32_t txID,uint8_t CAN01,uint8_t BIT29ID ,uint16_t polling);
/**
 * MCM_CreateK1100 is the function for generating a K1000 device
 *
 * @param i         this the position in the mcm modules array
 * @param rxID      the rxID
 * @param txID      the txID
 * @param CAN01     if CAN 0 or CAN 1 is used
 * @param BIT29ID   if 29 bit identifiers  are used
 * @param polling   how many cycles before the temperature is received (0 = polling off) if the flag MCM_POLL_MS is used polling time is in ms
 * @param buttonHandle1 the handle of the left button
 * @param buttonHandle2 the handle of the right button
 *
 * @return          MCM_OK else error code
 */
int MCM_CreateK1100(uint16_t i,uint32_t rxID, uint32_t txID,uint8_t CAN01,uint8_t BIT29ID ,uint16_t polling,uint16_t buttonHandle1,uint16_t buttonHandle2);

/**
 * MCM_CreateAT13 is the function for generating a AT13 device
 *
 * @param i         this the position in the mcm modules array
 * @param rxID      the rxID
 * @param txID      the txID
 * @param CAN01     if CAN 0 or CAN 1 is used
 * @param BIT29ID   if 29 bit identifiers  are used
 * @param polling   how many cycles before the temperature is received (0 = polling off) if the flag MCM_POLL_MS is used polling time is in ms
 *
 * @return          MCM_OK else error code
 */
int MCM_CreateAT13(uint16_t i, uint32_t rxID, uint32_t txID,uint8_t CAN01,uint8_t BIT29ID ,uint16_t polling);
/**
 * MCM_CreateAT14 is the function for generating a AT13 device
 *
 * @param i         this the position in the mcm modules array
 * @param rxID      the rxID
 * @param txID      the txID
 * @param CAN01     if CAN 0 or CAN 1 is used
 * @param BIT29ID   if 29 bit identifiers  are used
 * @param polling   how many cycles before the temperature is received (0 = polling off) if the flag MCM_POLL_MS is used polling time is in ms
 *
 * @return          MCM_OK else error code
 */
int MCM_CreateAT14(uint16_t i, uint32_t rxID, uint32_t txID,uint8_t CAN01,uint8_t BIT29ID ,uint16_t polling);

/**
 * MCM_CreateMCM200 is the function for generating a MCM 200 device
 *
 * @param i          the position in the mcm modules array
 * @param rxID       the rxID
 * @param txID       the txID
 * @param CAN01      if CAN 0 or CAN 1 is used
 * @param BIT29ID    if 29 bit identifiers  are used
 * @param polling    how many cycles before the temperature or the voltage are received (0 = polling off) if the flag MCM_POLL_MS is used polling time is in ms
 * @param digInHnd   digital input handle
 * @param digOutHnd  digital output handle
 * @param anaInHnd   analog input handle
 * @param ctnHnd     counter input handle
 *
 * @return           MCM_OK else error code
 */
int MCM_CreateMCM200(uint16_t i,uint32_t rxID, uint32_t txID, uint8_t CAN01, uint8_t BIT29ID,uint16_t polling,uint16_t digInHnd , uint16_t digOutHnd , uint16_t anaInHnd, uint16_t ctnHnd);
/**
* MCM_CreateMCM210 is the function for generating a MCM210 device
*
* @param i          the position in the mcm modules array
* @param rxID       the rxID
* @param txID       the txID
* @param CAN01      if CAN 0 or CAN 1 is used
* @param BIT29ID    if 29 bit identifiers  are used
* @param polling    how many cycles before the temperature or the voltage are received (0 = polling off) if the flag MCM_POLL_MS is used polling time is in ms
* @param digInHnd   digital input handle
* @param digOutHnd  digital output handle
* @param anaInHnd   analog input handle
* @param ctnHnd     counter input handle
* @param grpHnd     group input handle
*
* @return           MCM_OK else error code
*/
int MCM_CreateMCM210(uint16_t i,uint32_t rxID , uint32_t txID, uint8_t CAN01, uint8_t BIT29ID, uint16_t polling, uint16_t digInHnd , uint16_t digOutHnd , uint16_t anaInHnd, uint16_t ctnHnd   , uint16_t grpHnd );
/**
* MCM_CreateMCM215 is the function for generating a MCM215 device
*
* @param i          the position in the mcm modules array
* @param rxID       the rxID
* @param txID       the txID
* @param CAN01      if CAN 0 or CAN 1 is used
* @param BIT29ID    if 29 bit identifiers  are used
* @param polling    how many cycles before the temperature or the voltage are received (0 = polling off) if the flag MCM_POLL_MS is used polling time is in ms
* @param digInHnd   digital input handle
* @param digOutHnd  digital output handle
* @param anaInHnd   analog input handle
* @param ctnHnd     counter input handle
*
* @return           MCM_OK else error code
**/
int MCM_CreateMCM215(uint16_t i,uint32_t rxID,uint32_t txID,uint8_t CAN01,uint8_t BIT29ID,uint16_t polling,uint16_t digInHnd,uint16_t digOutHnd,uint16_t anaInHnd,uint16_t ctnHnd);
/**
* MCM_CreateMCM220 is the function for generating a MCM215 device
*
* @param i          the position in the mcm modules array
* @param rxID       the rxID
* @param txID       the txID
* @param CAN01      if CAN 0 or CAN 1 is used
* @param BIT29ID    if 29 bit identifiers  are used
* @param polling    how many cycles before the temperature or the voltage are received (0 = polling off) if the flag MCM_POLL_MS is used polling time is in ms
* @param digInHnd   digital input handle
* @param digOutHnd  digital output handle
* @param anaInHnd   analog input handle
* @param ctnHnd     counter input handle
*
* @return           MCM_OK else error code
**/
int MCM_CreateMCM220(uint16_t i,uint32_t rxID,uint32_t txID,uint8_t CAN01,uint8_t BIT29ID,uint16_t polling,uint16_t digInHnd,uint16_t digOutHnd,uint16_t anaInHnd,uint16_t ctnHnd);
/**
* MCM_CreateMCM221 is the function for generating a MCM215 device
*
* @param i          the position in the mcm modules array
* @param rxID       the rxID
* @param txID       the txID
* @param CAN01      if CAN 0 or CAN 1 is used
* @param BIT29ID    if 29 bit identifiers  are used
* @param polling    how many cycles before the temperature or the voltage are received (0 = polling off) if the flag MCM_POLL_MS is used polling time is in ms
* @param digInHnd   digital input handle
* @param digOutHnd  digital output handle
* @param anaInHnd   analog input handle
* @param pwmHnd     the pwm output handle
* @param ctnHnd     counter input handle
* @param pidHnd     the pid output handle
*
* @return           MCM_OK else error code
**/
int MCM_CreateMCM221(uint16_t i,uint32_t rxID,uint32_t txID,uint8_t CAN01,uint8_t BIT29ID,uint16_t polling,uint16_t digInHnd,uint16_t digOutHnd,uint16_t anaInHnd,uint16_t pwmHnd,uint16_t ctnHnd,uint16_t pidHnd);
/**
* MCM_CreateMCM230 is the function for generating a MCM 230 device
*
* @param i          the position in the mcm modules array
* @param rxID       the rxID
* @param txID       the txID
* @param CAN01      if CAN 0 or CAN 1 is used
* @param BIT29ID    if 29 bit identifiers  are used
* @param polling    how many cycles before the temperature or the voltage are received (0 = polling off) if the flag MCM_POLL_MS is used polling time is in ms
* @param digInHnd   digital input handle
* @param digOutHnd  digital output handle
* @param anaInHnd   analog input handle
* @param pwmHnd     the pwm output handle
*
 *@return           MCM_OK else error code
*/
int MCM_CreateMCM230 (uint16_t i,uint32_t rxID,uint32_t txID,uint8_t CAN01,uint8_t BIT29ID,uint16_t polling,uint16_t digInHnd,uint16_t digOutHnd,uint16_t anaInHnd,uint16_t pwmHnd);
/**
* MCM_CreateMCM241 is the function for generating a MCM 241 device
*
* @param i          the position in the mcm modules array
* @param rxID       the rxID
* @param txID       the txID
* @param CAN01      if CAN 0 or CAN 1 is used
* @param BIT29ID    if 29 bit identifiers  are used
* @param polling    how many cycles before the temperature or the voltage are received (0 = polling off) if the flag MCM_POLL_MS is used polling time is in ms
* @param digInHnd   digital input handle
* @param digOutHnd  digital output handle
* @param ctnHnd     counter input handle
*
 *@return           MCM_OK else error code
*/
int MCM_CreateMCM241(uint16_t i,uint32_t rxID, uint32_t txID, uint8_t CAN01, uint8_t BIT29ID,uint16_t polling, uint16_t digInHnd , uint16_t digOutHnd , uint16_t ctnHnd);
/**
* MCM_CreateMCM250 is the function for generating a MCM215 device
*
* @param i          the position in the mcm modules array
* @param rxID       the rxID
* @param txID       the txID
* @param CAN01      if CAN 0 or CAN 1 is used
* @param BIT29ID    if 29 bit identifiers  are used
* @param polling    how many cycles before the temperature or the voltage are received (0 = polling off) if the flag MCM_POLL_MS is used polling time is in ms
* @param digInHnd   digital input handle
* @param digOutHnd  digital output handle
* @param anaInHnd   analog input handle
* @param pwmHnd     the pwm output handle
* @param ctnHnd     counter input handle
*
* @return           MCM_OK else error code
**/
int MCM_CreateMCM250(uint16_t i,uint32_t rxID,uint32_t txID,uint8_t CAN01,uint8_t BIT29ID,uint16_t polling,uint16_t digInHnd,uint16_t digOutHnd,uint16_t anaInHnd,uint16_t pwmHnd,uint16_t ctnHnd);
/**
* MCM_CreateMCM300 is the function for generating a MCM 300 device
*
* @param i          the position in the mcm modules array
* @param rxID       the rxID
* @param txID       the txID
* @param CAN01      if CAN 0 or CAN 1 is used
* @param BIT29ID    if 29 bit identifiers  are used
* @param polling    how many cycles before the temperature or the voltage are received (0 = polling off) if the flag MCM_POLL_MS is used polling time is in ms
* @param digInHnd   digital input handle
* @param digOutHnd  digital output handle
* @param anaInHnd   analog input handle
* @param anaOutHnd  analog output handle
*
* @return           MCM_OK else error code
*/
int MCM_CreateMCM300(uint16_t i,uint32_t rxID, uint32_t txID, uint8_t CAN01, uint8_t BIT29ID,uint16_t polling,uint16_t digInHnd , uint16_t digOutHnd , uint16_t anaInHnd,uint16_t anaOutHnd);

#ifdef __cplusplus
}
#endif //__cplusplus

#endif /* MCM_H_INCLUDED*/
//-----------------------------------------------------------------------------
//EOF
//-----------------------------------------------------------------------------