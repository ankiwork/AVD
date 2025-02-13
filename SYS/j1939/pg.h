/*[CR]**************************************************************************
   Copyright (c) 2009 by IBV - Echtzeit- und Embedded GmbH & Co. KG, Germany
   All Rights reserved.
*/

/*[FH]**************************************************************************

   PROJECT:    ISOBUS - J1939 Protokollstack
   MODULE:     gal
   FILE:       pg.h
   CONTENTS:   J1939 Parameter Group Definitions
*/

/*[CL]**************************************************************************

   27-04-2009  DRA      creation

   ---
   DRA: Dominic Rath, IBV, www.ibv-augsburg.net
*/

/*[MP]**************************************************************************

   Compatibility:
   --------------
   Language:            ANSI-C
   Operating System:    QNX
   Architecture:        ALL
*/

#ifndef _INCLUDE_PG_H_
#define _INCLUDE_PG_H_

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

typedef uint32_t  _j1939_pg_hdl;

typedef int(*_j1939_pg_rcv_cb)(_j1939_pg_hdl pg, _j1939_name source,
                               uint8_t *data, int len, void *arg);

typedef int(*_j1939_pg_req_cb)(_j1939_pg_hdl pg, _j1939_name source, void *arg);

typedef struct __j1939_sp
{
   char     *name;            /* Descriptive name           */
   uint32_t spn;              /* Suspect parameter number   */
   unsigned len;              /* length in bits             */
   unsigned start;            /* start position in bits     */
   float    gain;             /* App. specific conversion   */
   float    offset;           /* App. specific conversion   */
} _j1939_sp;

typedef struct __j1939_pg
{
   char        *token;        /* Token name                             */
   char        *name;         /* Descriptive name                       */
   _j1939_pgn  pgn;           /* [15:0] Parameter group number          */
                              /* [16]   DP  (currently zero)            */
                              /* [17]   EDP (SBZ, reserved)             */
   uint32_t    rate;          /* 0: on request                          */
                              /* n: every n ms                          */
   int         len;           /* PG buffer length                       */
   uint8_t     prio;          /* Message priority (0-7)                 */
   _j1939_sp   *sps;          /* array of _j1939_sp                     */
   int         num_sps;       /* size of _j1939_sp array                */
   _j1939_name target;        /* 0xffffffffffffffff: broadcast          */
                              /* 0x0000000000000000: rx only            */
                              /* else: target NAME                      */
   _j1939_name source;        /* 0xffffffffffffffff: any                */
                              /* 0x0000000000000000: tx only            */
                              /* else: source NAME                      */
   _j1939_pg_req_cb req_cb;   /* Request callback (read request)        */
   void             *req_cb_arg; /* argument to request callback        */
   _j1939_pg_rcv_cb rcv_cb;   /* Receive callback                       */
   void             *rcv_cb_arg; /* argument to receive callback        */
} _j1939_pg;

/*******************************************************************************
 * defines
 ******************************************************************************/

#define J1939_PG_HDL_INVALID  (0xffffffff)

/******************************************************************************/

#ifdef __cplusplus
} /* extern "C" */
#endif

/******************************************************************************/

#endif /* _INCLUDE_... */

/*[EOF]************************************************************************/
