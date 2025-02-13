/**
 * @file
 *
 * Logical key function codes to be used by MCP/MCQ/ARGOS visualization
 *
 * @author Matthias Weisser<br>
 *         Graf-Syteco GmbH & Co. KG
 *
 * @date   created: 14.3 2012
 */

#ifndef GSLKFCODES_H_INCLUDED
#define GSLKFCODES_H_INCLUDED

//-----------------------------------------------------------------------------
//Includes
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
//Defines
//-----------------------------------------------------------------------------
#define GS_VISU_LKF_NOFUNC       0        //!< No function, Data.KeyCode has to be checked
#define GS_VISU_LKF_MOVEUP       1        //!< Moving up
#define GS_VISU_LKF_MOVEDOWN     2        //!< Moving down
#define GS_VISU_LKF_MOVELEFT     3        //!< Moving left
#define GS_VISU_LKF_MOVERIGHT    4        //!< Moving right
#define GS_VISU_LKF_ENTER        5        //!< Enter
#define GS_VISU_LKF_ESCAPE       6        //!< Escape
#define GS_VISU_LKF_INCVAL       7        //!< Increment a value
#define GS_VISU_LKF_DECVAL       8        //!< Decrement a value
#define GS_VISU_LKF_SELECT       9        //!< Object has to go to selected mode
#define GS_VISU_LKF_LEAVE       10        //!< Object have to leave any focused state
#define GS_VISU_LKF_BREAK       11        //!< Stop any process
#define GS_VISU_LKF_START1      12        //!< Currently unused
#define GS_VISU_LKF_START2      13        //!< Currently unused
#define GS_VISU_LKF_START3      14        //!< Currently unused
#define GS_VISU_LKF_SHIFT       15        //!< Shift toggle through (Used for touch keyboard)
#define GS_VISU_LKF_SHIFTQP     16        //!< Shift quick, for next touch only, fall back to previous (Used for touch keyboard)
#define GS_VISU_LKF_SHIFTQB     17        //!< Shift quick, for next touch only, fall back to basis (Used for touch keyboard)
#define GS_VISU_LKF_SHIFT0      18        //!< Shift0 direct (Used for touch keyboard)
#define GS_VISU_LKF_SHIFT1      19        //!< Shift1 direct (Used for touch keyboard)
#define GS_VISU_LKF_SHIFT2      20        //!< Shift2 direct (Used for touch keyboard)
#define GS_VISU_LKF_ASCII       1000      //!< Data.KeyCode contains a character
#define GS_VISU_LKF_TOUCH0      10000     //!< Data.Touch contains coordinates of touch point 0
#define GS_VISU_LKF_TOUCH1      10001     //!< Data.Touch contains coordinates of touch point 1
#define GS_VISU_LKF_TOUCH2      10002     //!< Data.Touch contains coordinates of touch point 2
#define GS_VISU_LKF_TOUCH3      10003     //!< Data.Touch contains coordinates of touch point 3
#define GS_VISU_LKF_TOUCH4      10004     //!< Data.Touch contains coordinates of touch point 4
#define GS_VISU_LKF_SYNC        11000     //!< Key processing will be interrupted and drawing started
#define GS_VISU_LKF_STOP_DRAW   11001     //!< Stops visualization drawing (keys will be processed)
#define GS_VISU_LKF_START_DRAW  11002     //!< Starts visualization drawing
#define GS_VISU_LKF_ONE_DRAW    11003     //!< Issues one drawing process (when in stopped state)

#define GS_VISU_LKF_INTERNAL0 -1          //!< Only for internal usage. Do not use
#define GS_VISU_LKF_INTERNAL1 -2          //!< Only for internal usage. Do not use
#define GS_VISU_LKF_INTERNAL2 -3          //!< Only for internal usage. Do not use
#define GS_VISU_LKF_INTERNAL3 -4          //!< Only for internal usage. Do not use
#define GS_VISU_LKF_INTERNAL4 -5          //!< Only for internal usage. Do not use
#define GS_VISU_LKF_INTERNAL5 -6          //!< Only for internal usage. Do not use

//-----------------------------------------------------------------------------
//Datatypes
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
//Variables
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
//Function prototypes
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
//Function implementation
//-----------------------------------------------------------------------------

#endif //GSLKFCODES_H_INCLUDED
//-----------------------------------------------------------------------------
//EOF
//-----------------------------------------------------------------------------

