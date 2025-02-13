/**
 * @file
 *
 * Public interface to USB serial adapters
 *
 * @author Matthias Weisser<br>
 *         Graf-Syteco GmbH & Co. KG
 *
 * @date   created: 27.6 2012
 */

#ifndef GSUSBSER_H_INCLUDED
#define GSUSBSER_H_INCLUDED

//-----------------------------------------------------------------------------
//Includes
//-----------------------------------------------------------------------------
#include <stdint.h>

//-----------------------------------------------------------------------------
//Defines
//-----------------------------------------------------------------------------
#define GS_USBSER_PARITY_NONE   'n'
#define GS_USBSER_PARITY_EVEN   'e'
#define GS_USBSER_PARITY_ODD    'o'

//-----------------------------------------------------------------------------
//Datatypes
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
//Variables
//-----------------------------------------------------------------------------
typedef struct tagGsUsbSer tGsUsbSer;
typedef tGsUsbSer * tGsUsbSerHdl;

//-----------------------------------------------------------------------------
//Function prototypes
//-----------------------------------------------------------------------------
#ifdef __cplusplus
extern "C" {
#endif //__cplusplus

/**
 * Created a handle for an USB to serial adapter
 *
 * @param idx Index of the adapter to be created
 *
 * @return A handle != NULL if an adapter with index idx is available
 */
tGsUsbSerHdl gsUsbSerCreate(uint32_t idx);

/**
 * Destroys a handle for an usb serial adapter
 *
 * @param hdl      Valid handle created with gsUsbSerCreate
 */
void gsUsbSerDestroy(tGsUsbSerHdl hdl);

/**
 * Sets the baudrate for a given usb to serial adapter
 *
 * @param hdl      Valid handle created with gsUsbSerCreate
 * @param baudrate Baudrate to be set (9600, 19200, ...)
 *
 * @return 0 if the baudrate was set successfully
 */
int32_t gsUsbSerSetBaudrate(tGsUsbSerHdl hdl, uint32_t baudrate);

/**
 * Sets the number of stopbits for a given usb to serial adapter. This function
 * can only be used if the serial interface is closed.
 *
 * @param hdl      Valid handle created with gsUsbSerCreate
 * @param stopbits Number of stopbits (1,2)
 *
 * @return 0 if the number of stopbits was set successfully
 */
int32_t gsUsbSerSetStopbits(tGsUsbSerHdl hdl, uint32_t stopbits);

/**
 * Sets the parity mode for a given usb to serial adapter. This function
 * can only be used if the serial interface is closed.
 *
 * @param hdl    Valid handle created with gsUsbSerCreate
 * @param parity Parity mode (GS_USBSER_PARITY_*)
 *
 * @return 0 if the parity mode was set successfully
 */
int32_t gsUsbSerSetParity(tGsUsbSerHdl hdl, char parity);

/**
 * Opens the usb serial adapter
 *
 * @param hdl    Valid handle created with gsUsbSerCreate
 *
 * @return 0 if the adapter was successfully opened
 */
int32_t gsUsbSerOpen(tGsUsbSerHdl hdl);

/**
 * Closes the usb serial adapter
 *
 * @param hdl    Valid handle created with gsUsbSerCreate
 *
 * @return 0 if the adapter was successfully opened
 */
int32_t gsUsbSerClose(tGsUsbSerHdl hdl);

/**
 * Sends serial data over the given interface
 *
 * @param hdl  Valid handle created with gsUsbSerCreate
 * @param data Data to be send
 * @param num  Number of bytes to send
 *
 * @return The number of actually send bytes. This may be smaller (or even 0)
 *         then num if the send buffer of the serial port is full.
 */
int gsUsbSerSend(tGsUsbSerHdl hdl, const void * data, int32_t num);

/**
 * Receives data from a serial interface. This function is non-blocking. So you may
 * receive less data (even no data) then requested.
 *
 * @param hdl  Valid handle created with gsUsbSerCreate
 * @param data Here we will store the received data
 * @param num  Number of bytes available at data
 *
 * @return Number of actually read bytes (0 to num)
 */
int32_t gsUsbSerRecv(tGsUsbSerHdl hdl, void * data, int32_t num);

#ifdef __cplusplus
}
#endif //__cplusplus

#endif //GSUSBSER_H_INCLUDED
//-----------------------------------------------------------------------------
//EOF
//-----------------------------------------------------------------------------


