/**
 * @file
 *
 *
 *
 * @author Pascal Lais<br>
 *         Graf-Syteco GmbH & Co. KG
 *
 * @date   created: 20.02.2020
 */


#ifndef GSOPCUASERVER_H_INCLUDED
#define GSOPCUASERVER_H_INCLUDED

//-----------------------------------------------------------------------------
//Includes
//-----------------------------------------------------------------------------

#include "gsOpcUaTypes.h"

//-----------------------------------------------------------------------------
//Defines
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
//Datatypes
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
//Variables
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
//Function prototypes
//-----------------------------------------------------------------------------

#ifdef __cplusplus
extern "C"
{
#endif //__cplusplus

/**
 * Initialize the gsOpcUa Server
 *
 * @param config The gsOpcUaServer configuration
 * @return A handle for the gsOpcUaServer
 */
tGsOpcUaServerHdl gsOpcUaServerInit(tGsOpcUaServerConfig config);

/**
 * Clean up the memory
 *
 * @param hdl The gsOpcUaServer Handle
 */
void gsOpcUaServerDeInit(tGsOpcUaServerHdl hdl);

/**
 * Start the gsOpcUaServer
 *
 * @param hdl The gsOpcUaServer Handle
 */
void gsOpcUaServerStart(tGsOpcUaServerHdl hdl);

/**
 * Stop the gsOpcUaServer
 *
 * @param hdl The gsOpcUaServer Handle
 */
void gsOpcUaServerStop(tGsOpcUaServerHdl hdl);

#ifdef __cplusplus
}
#endif //__cplusplus

#endif //GSOPCUASERVER_H_INCLUDED
//-----------------------------------------------------------------------------
//EOF
//-----------------------------------------------------------------------------
