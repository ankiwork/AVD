/**
 * @file
 *
 * Simple interface to the Linux bluetooth handling. After successful
 * initializing of the library you should be able to connect to a
 * RFCOMM serial port from the outside.
 *
 * @author Matthias Weisser<br>
 *         Graf-Syteco GmbH & Co. KG
 *
 * @date   created: 30.1 2012
 */

#ifndef GSBLUETOOTH_H_INCLUDED
#define GSBLUETOOTH_H_INCLUDED

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
 * Function pointer signature to be passed to gsBluetoothSetDebugCallback
 *
 * @param fmt A printf like format string
 * @param ... Argument list mathing format
 */
typedef void(*tGsBluetoothDebugCallback)(const char * fmt, ...);

/**
 * Opaque handle for all gsBluetooth functions
 */
typedef void * tGsBluetoothHdl;

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
 * Creates a new handle for bluetooth control
 *
 * @return A gsBluetooth handle or NULL if creation failed
 */
tGsBluetoothHdl gsBluetoothCreate(void);

/**
 * Enables debug output via debug streams for the given bluetooth handle
 *
 * @param hdl  Handle which should be destroyed
 * @param func Callback function which will receive the debug output
 *
 * @return A gsBluetooth handle or NULL if creation failed
 */
void gsBluetoothSetDebugCallback(tGsBluetoothHdl hdl, tGsBluetoothDebugCallback func);

/**
 * Destroys a bluetooth handle.
 *
 * @param hdl Handle which should be destroyed
 */
void gsBluetoothDestroy(tGsBluetoothHdl hdl);

/**
 * Sets the name of the bluetooth device. Needs to be called before calling gsBluetoothInit
 *
 * @param hdl Handle for which the name should be set
 * @param name Name to be set
 */
void gsBluetoothSetName(tGsBluetoothHdl hdl, const char * name);

/**
 * Checks if a compatible bluetooth dongle is available and if so inits it so
 * that it can be used
 *
 * @param hdl Handle to be initialized
 */
void gsBluetoothInit(tGsBluetoothHdl hdl);

/**
 * Returns a value which tells about a connected or not connected bluetooth client
 *
 * @param hdl Valid handle created with gsBluetoothCreate
 *
 * @return > 0 if a device is connected via bluetooth
 */
int32_t gsBluetoothIsConnected(tGsBluetoothHdl hdl);

/**
 * Sends serial data over the given interface
 *
 * @param hdl  Valid handle created with gsBluetoothCreate
 * @param data Data to be send
 * @param num  Number of bytes to send
 *
 * @return The number of actually send bytes. This may be smaller (or even 0)
 *         then num if the send buffer of the serial port is full.
 */
int32_t gsBluetoothSend(tGsBluetoothHdl hdl, const void * data, int32_t num);

/**
 * Receives data from a serial interface. This function is non-blocking. So you may
 * receive less data (even no data) then requested.
 *
 * @param hdl  Valid handle created with gsBluetoothCreate
 * @param data Here we will store the received data
 * @param num  Number of bytes available at data
 *
 * @return Number of actually read bytes (0 to num)
 */
int32_t gsBluetoothRecv(tGsBluetoothHdl hdl, void * data, int32_t num);

#ifdef __cplusplus
}
#endif //__cplusplus
//-----------------------------------------------------------------------------
//Function implementation
//-----------------------------------------------------------------------------

#endif //GSBLUETOOTH_H_INCLUDED
//-----------------------------------------------------------------------------
//EOF
//-----------------------------------------------------------------------------

