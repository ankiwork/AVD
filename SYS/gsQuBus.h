/**
 * @file
 *
 * Public interface to QuBus library
 *
 * @author Matthias Weisser<br>
 *         Graf-Syteco GmbH & Co. KG
 */

#ifndef GSQUBUS_H_INCLUDED
#define GSQUBUS_H_INCLUDED

//-----------------------------------------------------------------------------
//Includes
//-----------------------------------------------------------------------------
#include <stdint.h>

#include "gsQuBusTypes.h"

//-----------------------------------------------------------------------------
//Defines
//-----------------------------------------------------------------------------
#define GSQUBUS_DEFAULT_BITTIME 125000

//-----------------------------------------------------------------------------
//Datatypes
//-----------------------------------------------------------------------------

typedef struct tagGsQuBusMsg
{
    uint32_t mChannel;  //!< The channel to be used for a QuBus transmission
    uint32_t mAdr;      //!< The address to be used (0-127) TODO: Add a proper enum
    uint32_t mConfig;   //!< Configuration bits (0-15) TODO: Add a proper enum for the different configs
    uint32_t mData;     //!< Data (0-4095)
}tGsQuBusMsg;

typedef struct tagGsQuBus tGsQuBus;
typedef tGsQuBus * tGsQuBusHdl;

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
 * Inits the gsQuBus library
 *
 * @return A handle to the QuBus library
 */
tGsQuBusHdl gsQuBusInit(void);

/**
 * Deinits the library with the given handle
 *
 * @param hdl Handle of the library you initialized with gsQuBusInit
 */
void gsQuBusDeInit(tGsQuBusHdl hdl);

/**
 * Sets the bittime for the QuBus
 *
 * @param hdl Handle of the library you initialized with gsQuBusInit
 * @param t   Bittime which should be set (scaled in ns)
 */
eGsQuBusError gsQuBusSetBitTime(tGsQuBusHdl hdl, uint32_t t);

/**
 * Transmit function for QuBus messages
 *
 * @param hdl       Handle of the library you initialized with gsQuBusInit
 * @param msg       The message to be written to the bus
 * @param num       Number of messages to be transmitted
 *
 * @return Any of eGsQuBusError
 */
eGsQuBusError gsQuBusWrite(tGsQuBusHdl hdl, const tGsQuBusMsg * msg, size_t num);

/**
 * Receive function for QuBus messages
 *
 * @param hdl       Handle of the library you initialized with gsQuBusInit
 * @param msg       The message to be written/read from the bus
 * @param num       Number of messages to be read
 *
 * @return Any of eGsQuBusError
 */
eGsQuBusError gsQuBusRead(tGsQuBusHdl hdl, tGsQuBusMsg * msg, size_t num);

#ifdef __cplusplus
}
#endif //__cplusplus
//-----------------------------------------------------------------------------
//Function implementation
//-----------------------------------------------------------------------------

#endif //GSQUBUS_H_INCLUDED
//-----------------------------------------------------------------------------
//EOF
//-----------------------------------------------------------------------------

