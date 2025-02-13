/*[CR]**************************************************************************
   Copyright (c) 2009 by IBV - Echtzeit- und Embedded GmbH & Co. KG, Germany
   All Rights reserved.
*/

/*[FH]**************************************************************************

   PROJECT:    ISOBUS - J1939 Protokollstack
   MODULE:     error
   FILE:       j1939_err_event.h
   CONTENTS:   J1939 Error events
*/

/*[CL]**************************************************************************

   16-12-2009  MSC      modified j1939 include pathes
   28-04-2009  DRA      creation

   ---
   DRA: Dominic Rath, IBV, www.ibv-augsburg.net
   MSC: Maximilian Schmuck, IBV, www.ibv-augsburg.net
*/

/*[MP]**************************************************************************

   Compatibility:
   --------------
   Language:            ANSI-C
   Operating System:    QNX
   Architecture:        ALL
*/

#ifndef _INCLUDE_J1939_ERR_EVENT_H_
#define _INCLUDE_J1939_ERR_EVENT_H_

/*******************************************************************************
 * extern "C"
 ******************************************************************************/

#ifdef __cplusplus
extern "C"
{
#endif

/*******************************************************************************
 * includes
 ******************************************************************************/

/* c-runtime */
#include <stdint.h>

/* project */
#include "j1939/j1939.h"

/*******************************************************************************
 * typedefs
 ******************************************************************************/

typedef enum __j1939_err_type
{
   J1939_ERR_FATAL,
   J1939_ERR_ERROR,
   J1939_ERR_WARNING
} _j1939_err_type;

typedef void(*_j1939_err_cb)(void *arg, _j1939_err_type type, const char *text);

/******************************************************************************/

#ifdef __cplusplus
} /* extern "C" */
#endif

/******************************************************************************/

#endif /* _INCLUDE_... */

/*[EOF]************************************************************************/
