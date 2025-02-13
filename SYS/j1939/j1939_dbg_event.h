/*[CR]**************************************************************************
   Copyright (c) 2009 by IBV - Echtzeit- und Embedded GmbH & Co. KG, Germany
   All Rights reserved.
*/

/*[FH]**************************************************************************

   PROJECT:    ISOBUS - J1939 Protokollstack
   MODULE:     debug
   FILE:       j1939_dbg_event.h
   CONTENTS:   J1939 Debug events
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

#ifndef _INCLUDE_J1939_DBG_EVENT_H_
#define _INCLUDE_J1939_DBG_EVENT_H_

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
#include "j1939/transport_pg.h"

/*******************************************************************************
 * defines
 ******************************************************************************/

#define  CONTROLLERS_ALL      0xFF

/*******************************************************************************
 * typedefs
 ******************************************************************************/

typedef enum __j1939_dbg_event
{
   J1939_DBG_EVENT_HAL_MSG,
   J1939_DBG_EVENT_DLL_MSG,
   J1939_DBG_EVENT_NWL_MSG,

   J1939_DBG_EVENT_TP_TIMEOUT,
   J1939_DBG_EVENT_IGNORING_MSG,
   
   J1939_DBG_EVENT_UNREGISTERED_PGN,
   J1939_DBG_EVENT_UNREGISTERED_PGN_REQ,
   J1939_DBG_EVENT_UNREGISTERED_PGN_SRC,
   
   J1939_DBG_EVENT_NUM,
} _j1939_dbg_event;

typedef enum __j1939_dbg_direction
{
   J1939_DBG_DIRECTION_NONE,
   J1939_DBG_DIRECTION_SEND,
   J1939_DBG_DIRECTION_RECV
} _j1939_dbg_direction;

typedef struct __j1939_dbg_hal_msg
{
   uint32_t   id;      /* message ID (11 or 29 bit) */
   uint8_t    eff;     /* 0: 11 bit ID, 1: 29 bit extended frame format ID */
   uint8_t    rtr;     /* remote transmission (1: request remote transmit) */
   uint8_t    len;     /* length of data */
   uint8_t    *data;   /* pointer to max 8 bytes of data */
} _j1939_dbg_hal_msg;

typedef struct _j1939_dbg_event_hal_msg
{
   uint8_t            controller;
   _j1939_dbg_hal_msg msg;
} _j1939_dbg_event_hal_msg;

/* also in J1939_DBG_EVENT_TP_TIMEOUT, J1939_DBG_EVENT_IGNORING_MSG */
typedef struct _j1939_dbg_event_dll_msg_in
{
   uint8_t           controller;
   _j1939_addr       source;
   const _j1939_tpg  *pg;
} _j1939_dbg_event_dll_msg_in;

typedef struct _j1939_dbg_event_dll_msg_out
{
   uint8_t          controller;
   const _j1939_tpg *pg;
} _j1939_dbg_event_dll_msg_out;

typedef struct _j1939_dbg_event_nwl_msg_in
{
   uint8_t           controller;
   _j1939_addr       source;
   const _j1939_tpg  *pg;
} _j1939_dbg_event_nwl_msg_in;

typedef struct _j1939_dbg_event_nwl_msg_out
{
   _j1939_name       dest;
   const _j1939_tpg  *pg;
} _j1939_dbg_event_nwl_msg_out;

typedef struct __j1939_dbg_event_gal
{
   _j1939_name src;
   _j1939_name dst;
   uint32_t    pgn; 
} _j1939_dbg_event_gal;

typedef void (*_j1939_dbg_cb)(_j1939_dbg_event event,
                              _j1939_dbg_direction direction,
                              const void *event_data, const char *comment,
                              void *arg);

/******************************************************************************/

#ifdef __cplusplus
} /* extern "C" */
#endif

/******************************************************************************/

#endif /* _INCLUDE_... */

/*[EOF]************************************************************************/
