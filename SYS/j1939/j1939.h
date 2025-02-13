/*[CR]**************************************************************************
   Copyright (c) 2009 by IBV - Echtzeit- und Embedded GmbH & Co. KG, Germany
   All Rights reserved.
*/

/*[FH]**************************************************************************

   PROJECT:    ISOBUS - J1939 Protokollstack
   MODULE:     common
   FILE:       j1939.h
   CONTENTS:   J1939 Common Definitions
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

#ifndef _INCLUDE_J1939_H_
#define _INCLUDE_J1939_H_

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

#include <stdint.h>

/*******************************************************************************
 * typedefs
 ******************************************************************************/

typedef uint64_t _j1939_name;    /* J1939 NAME as per J1939-81                */

typedef uint8_t  _j1939_addr;    /* J1939 address                             */

typedef uint32_t _j1939_pgn;     /* [15:0]: pgn, [16]: dp, [17]: edp(rsvd)    */
                                 /* in accordance with J1939-21 §5.1.2        */ 

typedef struct __network_cache_entry *_j1939_tgt_cache;

typedef enum __j1939_status
{
   J1939_STATUS_UNDEFINED,
   J1939_STATUS_TMO,
   J1939_STATUS_LKUP_FAIL,
} _j1939_status;

/*******************************************************************************
 * defines
 ******************************************************************************/

#define J1939_NAME_INVALID       (0ULL)
#define J1939_NAME_BROADCAST     (0xFFFFFFFFFFFFFFFFULL)

#define J1939_ADDR_GLOBAL        (255)
#define J1939_ADDR_NULL          (254)

#define J1939_DATALEN_MAX        1785   /* bytes */

/******************************************************************************/

#ifdef __cplusplus
} /* extern "C" */
#endif

/******************************************************************************/

#endif /* _INCLUDE_... */

/*[EOF]************************************************************************/
