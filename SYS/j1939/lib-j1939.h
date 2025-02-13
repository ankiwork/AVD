/*[CR]**************************************************************************
   Copyright (c) 2009 by IBV - Echtzeit- und Embedded GmbH & Co. KG, Germany
   All Rights reserved.
*/

/*[FH]**************************************************************************

   PROJECT:    ISOBUS - J1939 Protokollstack
   MODULE:     api
   FILE:       lib-j1939.h
   CONTENTS:   J1939 API
*/

/*[CL]**************************************************************************

   06-07-2009  ESA      added j1939_version.h
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

#ifndef _INCLUDE_LIB_J1939_H_
#define _INCLUDE_LIB_J1939_H_

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
#include "pg.h"
#include "transport_pg.h"
#include "nwm_event.h"
#include "j1939_err_event.h"
#include "j1939_dbg_event.h"
#include "j1939_version.h"

/*******************************************************************************
 * typedefs
 ******************************************************************************/

typedef struct __j1939 *_j1939_hdl;

/*******************************************************************************
 * prototypes
 ******************************************************************************/

/*
 * initalization/cleanup functions
 */

/* Initializes the lib-j1939 API */
_j1939_hdl  j1939_init(uint8_t *controller, unsigned controller_num);

/* Shuts lib-j1939 down */
int         j1939_exit(_j1939_hdl hdl);

/*
 * parameter group access functions
 */

/* Adds a single parameter group definition */
_j1939_pg_hdl  j1939_add_pg      (_j1939_hdl hdl, const _j1939_pg *pg);

/* Deletes a single parameter group definition */
int            j1939_del_pg      (_j1939_hdl hdl, _j1939_pg_hdl pg);

/* Adds parameter group definitions from a file */
int            j1939_add_pg_file (_j1939_hdl hdl, const char *filename);

/* Writes a single suspect parameter */
int j1939_wr_sp(_j1939_hdl hdl, _j1939_pg_hdl pg, uint32_t spn,
                const uint8_t *data, unsigned bits);

/* Reads a single suspect parameter */
int j1939_rd_sp(_j1939_hdl hdl, _j1939_pg_hdl pg, uint32_t spn, uint8_t *data,
                unsigned *bits, const _j1939_sp **sp);

/* Writes a parameter group buffer */
int j1939_wr_pg (_j1939_hdl hdl, _j1939_pg_hdl pg, uint8_t *data, unsigned len,
                 int send, _j1939_status *status);

/* Reads a parameter group buffer */
int j1939_rd_pg (_j1939_hdl hdl, _j1939_pg_hdl pg, uint8_t *data, unsigned *len,
                 int request, _j1939_status *status);

/* Sends a parameter group */
int j1939_snd_pg(_j1939_hdl hdl, _j1939_pg_hdl pg, _j1939_status *status);

/* Retrieves the handle associated with a PG’s token */
_j1939_pg_hdl     j1939_hdl_of_token(_j1939_hdl hdl, const char *token);

/* Retrieves a PG’s definition by its handle */
const _j1939_pg*  j1939_pg_by_hdl   (_j1939_hdl hdl, _j1939_pg_hdl pg);

/* Sets a generic PG receive callback */
int j1939_set_pg_rcv_cb(_j1939_hdl hdl, _j1939_pg_rcv_cb cb, void *arg);

/* Sets a generic PG request callback */
int j1939_set_pg_req_cb(_j1939_hdl hdl, _j1939_pg_req_cb cb, void *arg);

/* Transmits a raw PG */
int j1939_transmit_pg(_j1939_hdl hdl, _j1939_name target,
                      _j1939_tgt_cache *cache, _j1939_tpg *tpg,
                      _j1939_status *status);

/* Transmits a request for a raw PG */
int j1939_request_pg (_j1939_hdl hdl, _j1939_name target,
                      _j1939_tgt_cache *cache, _j1939_pgn pgn,
                      _j1939_status *status);

/* Sets a raw PG receive callback */
int j1939_set_raw_rcv_cb(_j1939_hdl hdl, _j1939_raw_rcv_callback cb, void *arg);

/* Sets a raw PG request callback */
int j1939_set_raw_req_cb(_j1939_hdl hdl, _j1939_raw_req_callback cb, void *arg);

/*
 * network management functions
 */

/* Claims an address for a NAME on all controllers */
int j1939_claim_name(_j1939_hdl hdl, _j1939_name name, _j1939_addr pref_addr);

/* Sets a network management event callback */
int j1939_set_nwm_cb(_j1939_hdl hdl, _j1939_nwm_cb cb, void *arg);

/* Adds a static address for dumb bus members not taking part in name claiming process */
int j1939_add_static_addr(_j1939_hdl hdl, int controller, _j1939_name name, 
                                                            _j1939_addr addr);

/* Looks up the NAME of a J1939 address on a specific controller */
int j1939_lkup_name(_j1939_hdl hdl, uint8_t controller,  _j1939_addr address,
                    _j1939_name *name);

/* Looks up the address and controller of a specific NAME */
int j1939_lkup_addr(_j1939_hdl hdl, _j1939_name name, uint8_t *controller, 
                    _j1939_addr *address);

/* Commands a NAME to use a certain address */
int j1939_cmd_addr(_j1939_hdl hdl, _j1939_name, _j1939_addr address);

/* Retrieves the list of claimed addresses */
int j1939_get_clmd(_j1939_hdl hdl, uint8_t controller, _j1939_name *name, 
                   _j1939_addr *address, uint8_t *entries);

/* Sends a request for claimed addresses */
int j1939_req_clmd(_j1939_hdl hdl);

/* Builds a NAME from a set of parameters */
_j1939_name j1939_name(uint8_t aa_cap,   uint8_t ind_grp,     uint8_t vsys_inst,
                       uint8_t vsys,     uint8_t func,        uint8_t func_inst,
                       uint8_t ecu_inst, uint16_t mfgr_code,  uint32_t id_num);

/* Saves claimed addresses to file */
int j1939_save_addr(_j1939_hdl hdl);

/* Saves internal cache to file */
int j1939_save_cache(_j1939_hdl hdl);

/*
 * error handling functions
 */

/* Sets an error callback */
int j1939_set_err_cb(_j1939_hdl hdl, _j1939_err_cb cb, void *arg);

/*
 * debug (data trace) functions
 */

/* Sets a callback for a particular debug event type */
int j1939_set_dbg_cb(_j1939_hdl hdl, _j1939_dbg_event type, _j1939_dbg_cb cb,
                     void *arg);

/******************************************************************************/

#ifdef __cplusplus
} /* extern "C" */
#endif

/******************************************************************************/

#endif /* _INCLUDE_... */

/*[EOF]************************************************************************/
