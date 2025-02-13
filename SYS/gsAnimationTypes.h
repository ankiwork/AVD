/**
 * @file
 *
 *
 * @author Pascal Lais<br>
 *         Graf-Syteco GmbH & Co. KG
 *
 * @date   created: 15.05.2017
 */

#ifndef GSANIMATIONTYPES_H_INCLUDED
#define GSANIMATIONTYPES_H_INCLUDED

//-----------------------------------------------------------------------------
//Includes
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
//Defines
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
//Data types
//-----------------------------------------------------------------------------

/**
 * Types of animations
 */
typedef enum eagGsAnimationType
{
    GS_ANIMATION_TYPE_WAIT,
    GS_ANIMATION_TYPE_LINEAR,
    GS_ANIMATION_TYPE_NATURAL,
    GS_ANIMATION_TYPE_ACCELERATE,
    GS_ANIMATION_TYPE_SLOWDOWN,
    GS_ANIMATION_TYPE_BOOMERANG,
    GS_ANIMATION_TYPE_BOOMERANG_NATURAL,
}eGsAnimationType;

/**
 * Types of Events for animation callback function
 */
typedef enum eagGsAnimationEvent
{
    GS_ANIMATION_EVENT_START,	/* Animation has started */
    GS_ANIMATION_EVENT_END,     /* Animation has been proceeded successfully */
    GS_ANIMATION_EVENT_STOP,    /* Animation was cancelled*/
    GS_ANIMATION_EVENT_QUEUED,  /* Animation has been queued */
}eGsAnimationEvent;

/*
 * Function pointer for animation callback function
 */
typedef void (*tGsAnimationCallback)(uint32_t varHdl, eGsAnimationEvent event);
    
//-----------------------------------------------------------------------------
//Variables
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
//Function prototypes
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
//Function implementation
//-----------------------------------------------------------------------------

#endif  // #ifndef GSANIMATIONTYPES_H_INCLUDED
//-----------------------------------------------------------------------------
//EOF
//-----------------------------------------------------------------------------
