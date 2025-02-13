/**
 * @file
 *
 * QuBus-API
 *
 * @author Pascal Lais<br>
 *         Graf-Syteco GmbH & Co. KG
 *
 * @date   created: 09.03.2017
 */
#ifndef GSQUBUSEASY_H_INCLUDED
#define GSQUBUSEASY_H_INCLUDED

#include <stdlib.h>
#include "gsQuBus.h"

#include "gsQuBusEasyTypes.h"

//-----------------------------------------------------------------------------
//Datatypes
//-----------------------------------------------------------------------------

typedef struct tagGsQuBusEasyConfig
{
    uint32_t mId;                     //!< Id of the QuBus-Node.
    uint32_t mChannel;                //!< The channel to be used for a QuBus transmission
    uint32_t mAdr;                    //!< The address to be used (0-127) TODO: Add a proper enum
    eGsQuBusEasyLoadType mLoadType;   //!< Type of associated Load
}tGsQuBusEasyConfig;

typedef struct tagGsQuBusEasy tGsQuBusEasy;
typedef tGsQuBusEasy * tGsQuBusEasyHdl;

//-----------------------------------------------------------------------------
//Function prototypes
//-----------------------------------------------------------------------------

#ifdef __cplusplus
extern "C"
{
#endif //__cplusplus

/**
 * Inits the gsQuBusEasy library.
 *
 * @param cfg       Pointer to array with configuration of attached Qubus-Nodes
 * @param numNodes  Number of elements in cfg Array
 *
 * @return A handle to the QuBusEasy library
 */
tGsQuBusEasyHdl gsQuBusEasyInit(tGsQuBusEasyConfig * cfg, size_t numNodes);

/**
 * Deinits the gsQuBusEasy library with the given handle
 *
 * @param hdl       Handle to the gsQuBusEasy library
 */
void gsQuBusEasyDeInit(tGsQuBusEasyHdl hdl);

/**
 * Starts the gsQuBusEasy-Thread after it has been stopped.
 *
 * @param hdl       Handle to the gsQuBusEasy library
 */
void gsQuBusEasyStartThread(tGsQuBusEasyHdl hdl);

/**
 * Stops the gsQuBusEasy-Thread. Data won't get updated until Thread gets started again.
 *
 * @param hdl       Handle to the gsQuBusEasy library
 */
void gsQuBusEasyStopThread(tGsQuBusEasyHdl hdl);

/**
 * Detects if the Thread is running.
 *
 * @param hdl       Handle to the gsQuBusEasy library
 *
 * @return 0 if Thread is not running, 1 if it is running
 */
uint8_t gsQuBusEasyIsRunning(tGsQuBusEasyHdl hdl);

/**
 * Used to tell the library about a QuBus node
 *
 * @param hdl       Handle to the gsQuBusEasy library 
 * @param cfg       Config data of the Node to add
 *
 * @return 0 if adding was successful, 1 if it wasn't successfull
 */
uint8_t gsQuBusEasyAddNode(tGsQuBusEasyHdl hdl, tGsQuBusEasyConfig cfg);

/**
 * Used to remove a Node
 *
 * @param hdl       Handle to the gsQuBusEasy library 
 * @param id        Id of the QuBus to remove
 *
 * @return 0 if removing was successful, 1 if it wasn't successfull 
 */
uint8_t gsQuBusEasyRemoveNode(tGsQuBusEasyHdl hdl, int32_t id);

/**
 * Sends a Write Message to the QuBus
 *
 * @param hdl       Handle to the gsQuBusEasy library
 * @param msg       Message to send
 */
void gsQuBusEasyWrite(tGsQuBusEasyHdl hdl, tGsQuBusMsg * msg);

/**
 * Sends a Read Message to the QuBus (this Function is blocking)
 *
 * @param hdl       Handle to the gsQuBusEasy library
 * @param msg       Message to send
 */
void gsQuBusEasyRead(tGsQuBusEasyHdl hdl, tGsQuBusMsg * msg);

/**
 * Used to check if a new QuBus node was detectet on the bus on Adress 126
 *
 * @param hdl       Handle to the gsQuBusEasy library 
 *
 * @return 0 if no QuBus was detected, 1 if one was detected on channel 0, 2 if one was detected on channel 1, 3 if one was detected on botch channels
 */
uint8_t gsQuBusEasyIsNewNodeDetected(tGsQuBusEasyHdl hdl);

/**
 * Used to find the Id of a Node from its channel and adress
 *
 * @param hdl       Handle to the gsQuBusEasy library 
 * @param channel   Channel of the QuBus
 * @param adr       Adress of the QuBus
 *
 * @return Id of the QuBus
 */
int32_t gsQuBusEasyGetId(tGsQuBusEasyHdl hdl, uint32_t channel, uint32_t adr);

/**
 * Chechs if a QuBus is reachable
 *
 * @param hdl       Handle to the gsQuBusEasy library 
 * @param id        Id of the QuBus 
 *
 * @return 1 if QuBus is reachable, 0 if not
 */
uint8_t gsQuBusEasyIsAvailable(tGsQuBusEasyHdl hdl, int32_t id);

/**
 * Used to get any Parameter from a QuBus Node
 *
 * @param hdl       Handle to the gsQuBusEasy library 
 * @param id        Id of the QuBus 
 * @param param     Defines which parameter is requested
 *
 * @return Value of the requested Parameter
 */
uint32_t gsQuBusEasyGetParameter(tGsQuBusEasyHdl hdl, int32_t id, eGsQuBusEasyParameters param);

/**
 * Used to set the adress of a QuBus to another value
 *
 * @param hdl       Handle to the gsQuBusEasy library 
 * @param id        Id of the QuBus
 * @param adr       New Adress of the Node
 */
void gsQuBusEasySetAdress(tGsQuBusEasyHdl hdl, int32_t id, uint32_t adr);

/**
 * Used to set the currentlimit of a QuBus to another value
 *
 * @param hdl       Handle to the gsQuBusEasy library 
 * @param id        Id of the QuBus
 * @param curLimit  New currentlimit
 */
void gsQuBusEasySetCurrentLimit(tGsQuBusEasyHdl hdl, int32_t id, uint32_t curLimit);

/**
 * Resets the Error-Memory of a QuBus to 0
 *
 * @param hdl       Handle to the gsQuBusEasy library 
 * @param id        Id of the QuBus 
 */
void gsQuBusEasyResetErrorMemory(tGsQuBusEasyHdl hdl, int32_t id);

/**
 * Used to apply a Load to a QuBus node. Load is set in tents percent (Values 0 to 1000).
 * For Inductive load 1 and 2 Values from -1000 to 0 are accepted as well. 
 * Ind-Load 1: load < 0 = A1 gets pulsed and A2=Ub , load > 0 = A2 gets pulsed and A1=Ub
 * Ind-Load 2: load < 0 = A2 gets actuated, load > 0 = A1 gets actuated
 *
 * @param hdl       Handle to the gsQuBusEasy library 
 * @param id        Id of the QuBus
 * @param load      Value of the load in tenths percent (0-1000)
 */
void gsQuBusEasySetLoad(tGsQuBusEasyHdl hdl, int32_t id, int32_t load);

/**
 * Used to reset the Load
 *
 * @param hdl       Handle to the gsQuBusEasy library 
 * @param id        Id of the QuBus
 */
void gsQuBusEasyResetLoad(tGsQuBusEasyHdl hdl, int32_t id);

/**
 * Sets the Value for bus timeout
 *
 * @param hdl       Handle to the gsQuBusEasy library 
 * @param id        Id of the QuBus 
 * @param timeout   Value for bus timeout
 */
void gsQuBusEasySetTimeout(tGsQuBusEasyHdl hdl, int32_t id, int32_t timeout);

/**
 * Sets the PWM Frequency
 *
 * @param hdl       Handle to the gsQuBusEasy library 
 * @param id        Id of the QuBus
 * @param frequency Value for the frequency
 */
void gsQuBusEasySetFrequency(tGsQuBusEasyHdl hdl, int32_t id, int32_t frequency);

/**
 * Changes the Type of the Load
 *
 * @param hdl       Handle to the gsQuBusEasy library 
 * @param id        Id of the QuBus
 * @param loadtype  New type of load
 */
void gsQuBusEasySetLoadType(tGsQuBusEasyHdl hdl, int32_t id, eGsQuBusEasyLoadType loadtype);


#ifdef __cplusplus
}
#endif //__cplusplus

#endif  // #ifndef GSQUBUSEASY_H
//-----------------------------------------------------------------------------
//EOF
//-----------------------------------------------------------------------------
