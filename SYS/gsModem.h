/**
 * @file
 *
 *
 *
 * @author Matthias Weisser<br>
 *         Graf-Syteco GmbH & Co. KG
 *
 * @date   created: 30.1 2012
 */

#ifndef GSMODEM_H_INCLUDED
#define GSMODEM_H_INCLUDED

//-----------------------------------------------------------------------------
//Includes
//-----------------------------------------------------------------------------
#include <stdint.h>

//-----------------------------------------------------------------------------
//Defines
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
//Datatypes
//-----------------------------------------------------------------------------

/**
 * Function pointer signature to be passed to gsModemSetDebugCallback
 *
 * @param fmt A printf like format string
 * @param ... Argument list mathing format
 */
typedef void(*tGsModemDebugCallback)(const char * fmt, ...);

/**
 * Interface for a modem connection
 */
typedef enum eGsModemInterface
{
    GSMODEM_INTF_SERIAL_0,
    GSMODEM_INTF_SERIAL_1,
    GSMODEM_INTF_SERIAL_2,
    GSMODEM_INTF_SERIAL_3,
    GSMODEM_INTF_SERIAL_4,
    GSMODEM_INTF_SERIAL_5,

    GSMODEM_INTF_USB_SERIAL_0 = 100,
    GSMODEM_INTF_USB_SERIAL_1,
    GSMODEM_INTF_USB_SERIAL_2,
    GSMODEM_INTF_USB_SERIAL_3,
    GSMODEM_INTF_USB_SERIAL_4,
    GSMODEM_INTF_USB_SERIAL_5,
}eGsModemInterface;

/**
 * Status codes for function results
 */
typedef enum eGsModemStatusCode
{
    GSMODEM_STATUS_NO_INIT,                 //!< The init function was not called.
    GSMODEM_STATUS_NO_SERIAL,               //!< The serial port is not available
    GSMODEM_STATUS_INIT_RUNNING,            //!< The init function is currently running
    GSMODEM_STATUS_INIT_FAILED,             //!< No modem was detected or modem is not supported
    GSMODEM_STATUS_SETTING_PIN,             //!< We are currently setting the pin of the SIM card
    GSMODEM_STATUS_IDLE,                    //!< Modem is ready to accept commands
    GSMODEM_STATUS_SENDING_SMS,             //!< Modem currently sends a SMS
    GSMODEM_STATUS_GPRS_CONNECTING,         //!< Currently in the process of GPRS connection establishing
    GSMODEM_STATUS_GPRS_CONNECTED,          //!< Modem is connected to the internet via GPRS
    GSMODEM_STATUS_GPRS_DISCONNECTING,      //!< Modem is disconnecting from the internet
    GSMODEM_STATUS_GPRS_DISCONNECT_ERROR,   //!< An error occurred disconnecting from GPRS
}eGsModemStatusCode;

/**
 * Identifiers for string information querying
 */
typedef enum eGsModemInfoQuery
{
    GSMODEM_INFOQUERY_SERIALPORT,   //!< The serial port to which the modem is connected
    GSMODEM_INFOQUERY_MANUFACTURER, //!< The manufacturer of the connected modem
    GSMODEM_INFOQUERY_MODEL,        //!< The model of the connected modem
    GSMODEM_INFOQUERY_IMEI,         //!< The IMEI of the connected modem
    GSMODEM_INFOQUERY_IMSI,         //!< The IMSI of the SIM of the modem
    GSMODEM_INFOQUERY_RSSI,         //!< The signal strength. Result is a string 0..31 where 31 is the best
    GSMODEM_INFOQUERY_OPERATOR,     //!< The currently used network operator
}eGsModemInfoQuery;

/**
 * Opaque handle for all gsModem functions
 */
typedef void * tGsModemHdl;

//-----------------------------------------------------------------------------
//Variables
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
//Function prototypes
//-----------------------------------------------------------------------------
#ifdef __cplusplus
extern "C" {
#endif //__cplusplus

/**
 * Creates a new handle for a AT command set compatible modem. No hardware
 * action will be performed here but any further call needs such a handle.
 *
 * @param intf The interface which should be used by the handle
 *
 * @return A gsModem handle or NULL if creation failed
 */
tGsModemHdl gsModemCreate(eGsModemInterface intf);

/**
 * Enables debug output via debug streams for the given modem handle
 *
 * @param hdl  Handle which should be destroyed
 * @param func Callback function which will receive the debug output
 *
 * @return A gsModem handle or NULL if creation failed
 */
void gsModemSetDebugCallback(tGsModemHdl hdl, tGsModemDebugCallback func);

/**
 * Destroys a modem handle.
 *
 * @param hdl Handle which should be destroyed
 */
void gsModemDestroy(tGsModemHdl hdl);

/**
 * Returns the current status of the modem identified by hdl
 *
 * @param hdl Handle for which the status should be returned
 *
 * @return The current status of the modem identified by hdl
 */
eGsModemStatusCode gsModemGetStatus(tGsModemHdl hdl);

/**
 * Checks if a AT command set compatible modem is available, queries some
 * informations and stores them in an internal structure. These informations
 * can then be queried after by calling gsModemGet*. Please note that the
 * function will return immediately. Command execution will take place in
 * the background. Current status can be checked by gsModemGetStatus
 *
 * @param hdl Handle of the modem to be initialized
 * @param pin The pin of the modem as a string (typically a four digit number)
 */
void gsModemInit(tGsModemHdl hdl, const char * pin);

/**
 * Sets the number of the SMS service center. Check this if SMS sending doesn't
 * work. You will find the number of the SMSC somewhere in your mobile
 * contract data.
 *
 * @param hdl  Handle of the modem
 * @param num  Phone number for the SMSC
 *
 * @return 0 if text was valid and actual sending has been started.
 */
int32_t gsModemSetSMSCNumber(tGsModemHdl hdl, const char * num);

/**
 * Sends an SMS to a given phone number. Only characters between 0x20 and 0x7F
 * are allowed in the text string. If there are any other characters the function
 * will fail. If input data is valid sending will be done in background and
 * status can be checked by gsModemGetStatus.
 *
 * @param hdl  Handle of the modem
 * @param num  Phone number for the SMS
 * @param text Text of the SMS as 0 terminated string (max. 160 characters)
 *
 * @return 0 if text was valid and actual sending has been started.
 */
int32_t gsModemSMSSend(tGsModemHdl hdl, const char * num, const char * text);

/**
 * Connects the device to the internet throug a GPRS capable GSM modem. After
 * calling this function wait until gsModemGetStatus returns
 * GSMODEM_STATUS_GPRS_CONNECTED. After that you can start pppd using gsPPP driver.
 *
 * @param hdl Handle of the modem
 * @param apn Name of the APN of the provider
 */
void gsModemGPRSConnect(tGsModemHdl hdl, const char * apn);

/**
 * After stopping pppd using gsPPP driver call this function to bring the modem
 * back to the idle state so that it can be used for other services like SMS
 * sending.
 *
 * @param hdl Handle of the modem
 */
void gsModemGPRSDisconnect(tGsModemHdl hdl);

/**
 * Gets information about the connected modem as strings
 *
 * @param hdl   Handle of the modem
 * @param query Any of GSMODEM_INFOQUERY_
 * @param buf   Where the result will be copied to
 * @param len   Maximum length of the buffer buf
 *
 * @return 0 if something was copied to buf
 */
int32_t gsModemGetInfo(tGsModemHdl hdl, eGsModemInfoQuery query, char * buf, uint32_t len);

#ifdef __cplusplus
}
#endif //__cplusplus
//-----------------------------------------------------------------------------
//Function implementation
//-----------------------------------------------------------------------------

#endif //GSMODEM_H_INCLUDED
//-----------------------------------------------------------------------------
//EOF
//-----------------------------------------------------------------------------

