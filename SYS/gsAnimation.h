/**
 * @file
 *
 *
 * @author Pascal Lais<br>
 *         Graf-Syteco GmbH & Co. KG
 *
 * @date   created: 15.05.2017
 */

#ifndef GSANIMATION_H_INCLUDED
#define GSANIMATION_H_INCLUDED

//-----------------------------------------------------------------------------
//Includes
//-----------------------------------------------------------------------------

#include "gsAnimationTypes.h"

//-----------------------------------------------------------------------------
//Defines
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
//Data types
//-----------------------------------------------------------------------------
    
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
 * Starts an Animation for the corresponding Variable. Running animations for the Var Handle will get interrupted.
 *
 * @param varHdl      Variable Handle to animate
 * @param startValue  Start Value for the Variable
 * @param endValue    End Value for the Variable
 * @param delay       Delay in ms before animation starts
 * @param duration    Duration of the Animation
 * @param type        Defines the course of the value change
 * @param callback    Callback Function to call
 */
void gsAnimationStart(uint32_t varHdl, int32_t startValue, int32_t endValue, uint32_t delay, uint32_t duration, eGsAnimationType type, tGsAnimationCallback callback);

/**
 * Queues an Animation for the corresponding Variable. The Animation will start as soon as previous for the Variable are finished.
 *
 * @param varHdl      Variable Handle to animate
 * @param startValue  Start Value for the Variable
 * @param endValue    End Value for the Variable
 * @param delay       Delay in ms before animation starts
 * @param duration    Duration of the Animation
 * @param type        Defines the course of the value change
 * @param callback    Callback Function to call
 */
void gsAnimationQueue(uint32_t varHdl, int32_t startValue, int32_t endValue, uint32_t delay, uint32_t duration, eGsAnimationType type, tGsAnimationCallback callback);

/**
 * Stops all queued animations for a variable
 *
 * @param varHdl      Variable Handle to stop animation
 */
void gsAnimationStop(uint32_t varHdl);

/**
 * Service Cycle of gsAnimation. Call this in the Cycle if animations are used.
 *
 */
void gsAnimationCycle(void);

/**
 * Changes the Interval inbetween Value updates for all animations
 *
 * @param interval  Interval in ms
 */
void gsAnimationSetUpdateInterval(uint32_t interval);

/**
 * Returns the Current Interval duration. Default 10ms
 */
uint32_t gsAnimationGetUpdateInterval(void);

void gsAnimationDeInit(void);

#ifdef __cplusplus
}
#endif //__cplusplus

//-----------------------------------------------------------------------------
//Function implementation
//-----------------------------------------------------------------------------

#endif  // #ifndef GSANIMATION_H_INCLUDED
//-----------------------------------------------------------------------------
//EOF
//-----------------------------------------------------------------------------
