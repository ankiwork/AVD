/**
 * @file
 *
 * 
 *
 * @author Matthias Weisser<br>
 *         Graf-Syteco GmbH & Co. KG
 *
 * @date   created: 30.1 2012
 */

#ifndef GSPPP_H_INCLUDED
#define GSPPP_H_INCLUDED
 
//-----------------------------------------------------------------------------
//Includes
//-----------------------------------------------------------------------------
#include <stdint.h>

#ifdef GDSPROJECT
#include <gsModem.h>
#else
#include <gs/gsModem.h>
#endif

//-----------------------------------------------------------------------------
//Defines
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
//Datatypes
//-----------------------------------------------------------------------------

/**
 * Status codes for function results
 */
typedef enum eGsPPPStatusCode
{
    GSPPP_SC_INVALID,           //!< PPPD daemon can't be started
    GSPPP_SC_FAILED,            //!< PPPD daemon exited
    GSPPP_SC_RUNNING,           //!< PPPD is running
}eGsPPPStatusCode;

/**
 * Opaque handle for all gsPPP functions
 */
typedef void * tGsPPPHdl;

//-----------------------------------------------------------------------------
//Variables
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
//Function prototypes
//-----------------------------------------------------------------------------
#ifdef __cplusplus
extern "C" {
#endif //__cplusplus

/**
 * Starts a ppp session on a modem interface. The modem has to be put into
 * GPRS mode by issuing a ATD command to dial to the GPRS endpoint.
 *
 * @param hdl     The handle of the modem
 * @param pppUser User name for the ppp session
 * @param pppPass Password for the ppp session
 *
 * @return A gsPPP handle or NULL if creation failed
 */
tGsPPPHdl gsPPPStart(tGsModemHdl hdl, const char * pppUser, const char * pppPass);

/**
 * Returns the current status of the ppp session
 *
 * @param hdl Handle for which the status should be returned
 *
 * @return The current status of the modem identified by hdl
 */
eGsPPPStatusCode gsPPPGetState(tGsPPPHdl hdl);

/**
 * Stops the given ppp session.
 *
 * @param hdl Handle of the session as returned by gsPPPStart
 */
void gsPPPStop(tGsPPPHdl hdl);

#ifdef __cplusplus
}
#endif //__cplusplus
//-----------------------------------------------------------------------------
//Function implementation
//-----------------------------------------------------------------------------

#endif //GSPPP_H_INCLUDED
//-----------------------------------------------------------------------------
//EOF
//-----------------------------------------------------------------------------

