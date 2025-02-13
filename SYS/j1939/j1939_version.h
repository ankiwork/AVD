/*[CR]**************************************************************************
   Copyright (c) 2009 by IBV - Echtzeit- und Embedded GmbH & Co. KG, Germany
   All Rights reserved.
*/

/*[FH]**************************************************************************

   PROJECT:    ISOBUS - J1939 Protokollstack
   MODULE:     api
   FILE:       j1939_version.h
   CONTENTS:   J1939 version and changelog
*/

/*[CL]**************************************************************************

   19-08-2011  MSC      updated
   06-08-2009  ESA      updated
   15-07-2009  DRA      updated
   06-07-2009  ESA      creation

   ---
   ESA: Erwin Saumweber, IBV, www.ibv-augsburg.net
   DRA: Dominic Rath, IBV, www.ibv-augsburg.net
   MSC: Maximilian Schmuck, IBV, www.ibv-augsburg.net
*/

/*[MP]**************************************************************************

lib-j1939 Changelog:

J1939_VERSION 1.1.1:
   - bugfix returning 0 instead of J1939_PG_HDL_INVALID
   - bugfix deadlock in gal_wr_pg()
   - applied patch replacing sscanf with strtoull
   - add missing #include <unistd.h>

J1939_VERSION 1.1.0:
   - add working sets

J1939_VERSION 1.0.1:
   - bugfix "ignoring rtr bit set can frame"
   - add manual saving of addr/cache files
   - add version file
   - bugfix connection abort
   - bugfix wrong arg returned in raw_*_cb
   - extern c guards
   - bugfix segfault on target cache
   - bugfix buffer copying of SPs

J1939_VERSION 1.0:
   - initial release

*/

#ifndef _INCLUDE_J1939_VERSION_H_
#define _INCLUDE_J1939_VERSION_H_

/*******************************************************************************
 * extern "C"
 ******************************************************************************/

#ifdef __cplusplus
extern "C"
{
#endif

/*******************************************************************************
 * defines
 ******************************************************************************/

#define J1939_VERSION "1.1.1"
   
/******************************************************************************/

#ifdef __cplusplus
} /* extern "C" */
#endif

/******************************************************************************/

#endif /* _INCLUDE_... */

/*[EOF]************************************************************************/
