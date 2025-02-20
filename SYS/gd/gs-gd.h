/**
 * @file
 *
 * Wraper arround libgd
 *
 * @author Matthias Weisser<br>
 *         Graf-Syteco GmbH & Co. KG
 *
 * @date   created: 10.11.2014
 */

#ifndef GS_GD_H_INCLUDED
#define GS_GD_H_INCLUDED

//-----------------------------------------------------------------------------
//Includes
//-----------------------------------------------------------------------------
#ifdef _WIN32
#define BGDWIN32
#endif // WIN32

#include "gd.h"
#include "gdfonts.h"
#include "gdfontt.h"
#include "gdfontl.h"
#include "gdfontg.h"
#include "gdfx.h"
#include "gd_io.h"

#ifdef WIN32
#undef BGDWIN32
#endif // WIN32

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

//-----------------------------------------------------------------------------
//Function implementation
//-----------------------------------------------------------------------------

#endif //GS_GD_H_INCLUDED
//-----------------------------------------------------------------------------
//EOF
//-----------------------------------------------------------------------------
