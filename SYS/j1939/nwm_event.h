/*[CR]**************************************************************************
   Copyright (c) 2009 by IBV - Echtzeit- und Embedded GmbH & Co. KG, Germany
   All Rights reserved.
*/

/*[FH]**************************************************************************

   PROJECT:    ISOBUS - J1939 Protokollstack
   MODULE:     nwm
   FILE:       nwm_event.h
   CONTENTS:   J1939 Network management events
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

#ifndef _INCLUDE_NWM_EVENT_H_
#define _INCLUDE_NWM_EVENT_H_

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

typedef enum __j1939_nwm_event
{
   J1939_NWM_COMMANDED_ADDRESS,
   J1939_NWM_ADDRESS_CLAIMED,
   J1939_NWM_CANNOT_CLAIM_ADDRESS,
   J1939_NWM_LOOKUP_ADDR_FAILED,
   J1939_NWM_LOOKUP_NAME_FAILED,
} _j1939_nwm_event;

typedef struct __j1939_nwm_lookup_addr_failed
{
   _j1939_name name;
} _j1939_nwm_lookup_addr_failed;

typedef struct __j1939_nwm_lookup_name_failed
{
   _j1939_addr addr;
   uint8_t     controller;
} _j1939_nwm_lookup_name_failed;

typedef struct __j1939_nwm_cannot_claim_address
{
   _j1939_name name;
   uint8_t     controller;
} _j1939_nwm_cannot_claim_address;

typedef struct __j1939_nwm_address_claimed
{
   _j1939_name name; 
   _j1939_addr addr;
   uint8_t     controller;
} _j1939_nwm_address_claimed;

typedef struct __j1939_nwm_commanded_address
{
   /* commanded address */
   _j1939_addr commaddr;
   
   _j1939_name destname;
   _j1939_addr srcaddr;
   uint8_t     controller;
} _j1939_nwm_commanded_address;

typedef void (*_j1939_nwm_cb)(_j1939_nwm_event event, void *event_data,
                                                                     void *arg);

/******************************************************************************/

#ifdef __cplusplus
} /* extern "C" */
#endif

/******************************************************************************/

#endif /* _INCLUDE_... */

/*[EOF]************************************************************************/
