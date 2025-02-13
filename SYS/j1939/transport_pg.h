/*[CR]**************************************************************************
   Copyright (c) 2009 by IBV - Echtzeit- und Embedded GmbH & Co. KG
   All Rights reserved.
*/

/*[FH]**************************************************************************

   PROJECT:  ISOBUS
   MODULE:   nwl
   FILE:     transport_pg.h
   CONTENTS: parameter group in transport format definition
*/

/*[CL]**************************************************************************

   07-07-2009  ESA      extended length to 32 bits; missing includes
   28-04-2009  ESA      creation
   ---
   ESA: Erwin Saumweber, IBV, www.ibv-augsburg.de
   
*/

#ifndef _INCLUDE_TRANSPORT_PG_H_
#define _INCLUDE_TRANSPORT_PG_H_

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
#include "j1939.h"

/*******************************************************************************
 * typedefs                             
 ******************************************************************************/

typedef struct __j1939_tpg
{
   _j1939_pgn   pgn;        /* parameter group number */
   uint8_t      prio;       /* priority */
   
   uint8_t      *data;      /* pg data */
   uint32_t     len;        /* length of PG data */
} _j1939_tpg;

typedef int (*_j1939_raw_rcv_callback)(_j1939_name source, const _j1939_tpg *pg,
                                                                     void *arg);
typedef int (*_j1939_raw_req_callback)(_j1939_name source, const _j1939_pgn pgn,
                                                                     void *arg);

/******************************************************************************/

#ifdef __cplusplus
} /* extern "C" */
#endif

/******************************************************************************/

#endif /* _INCLUDE_TRANSPORT_PG_H_ */

/*[EOF]************************************************************************/
