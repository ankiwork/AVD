/**
 * @file
 *
 * A collection of utility functions implementing an NTP client
 *
 * @author Matthias Weisser<br>
 *         Graf-Syteco GmbH & Co. KG
 *
 * @date   created: 8.12 2011
 */

#ifndef GSSOCKETNTPCLIENT_H_INCLUDED
#define GSSOCKETNTPCLIENT_H_INCLUDED
 
//-----------------------------------------------------------------------------
//Includes
//-----------------------------------------------------------------------------
#include <stdint.h>

//-----------------------------------------------------------------------------
//Defines
//-----------------------------------------------------------------------------
#define GS_SOCKET_NTP_CLIENT_FLAG_SYNC_HW_CLOCK  (1<<0) //!< If set we will sync the hw clock when a ntp packet arrives
#define GS_SOCKET_NTP_CLIENT_NO_CLOCK_SETTIME    (1<<1) //!< If set we will not set the system clock

//-----------------------------------------------------------------------------
//Datatypes
//-----------------------------------------------------------------------------
typedef void * tGsSocketNtpClient;

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
 * Creates a new ntp client
 *
 * @param ntpServer Name/address of the ntp server
 * @param flags     See GS_SOCKET_NTP_CLIENT_FLAG_*
 *
 * @return The handle of the created client or NULL if client couldn't be created
 */
tGsSocketNtpClient gsSocketNtpClientCreate(const char * ntpServer, uint32_t flags);

/**
 * Destroys a ntp client
 *
 * @param hdl Handle of the client to be destroyed
 */
void gsSocketNtpClientDestroy(tGsSocketNtpClient hdl);

/**
 * Updates the ntp client state
 *
 * @param hdl   Handle of the ntp client
 *
 * @return 0 if the client was updated wihtout any action
 *         1 if the client received a ntp packet and set the time
 */
int32_t gsSocketNtpClientUpdate(tGsSocketNtpClient hdl);

/**
 * When this function is called a ntp request will be send out when the 
 * update function is called the next time
 *
 * @param hdl   Handle of the ntp client
 *
 * @return 0 if the request will be send. < 0 otherwise.
 */
int32_t gsSocketNtpClientRequest(tGsSocketNtpClient hdl);

/**
 * Returns the time which was reported last from the NTP server in
 * unix time stamp format and UTC
 *
 * @param hdl   Handle of the ntp client
 *
 * @return The time which was reported last from the NTP server
 */
uint32_t gsSocketNtpClientGetLastTime(tGsSocketNtpClient hdl);

#ifdef __cplusplus
}
#endif //__cplusplus
//-----------------------------------------------------------------------------
//Function implementation
//-----------------------------------------------------------------------------

#endif //GSSOCKETNTPCLIENT_H_INCLUDED
//-----------------------------------------------------------------------------
//EOF
//-----------------------------------------------------------------------------

