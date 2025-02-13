/**
 * @file
 *
 * A collection of utility functions implementing a non-blocking tcp client
 *
 * @author Matthias Weisser<br>
 *         Graf-Syteco GmbH & Co. KG
 *
 * @date   created: 8.12 2011
 */

#ifndef GSSOCKETTCPCLIENT_H_INCLUDED
#define GSSOCKETTCPCLIENT_H_INCLUDED

//-----------------------------------------------------------------------------
//Includes
//-----------------------------------------------------------------------------
#include <stdint.h>

//-----------------------------------------------------------------------------
//Defines
//-----------------------------------------------------------------------------
/**
 * If given to gsSocketTcpClientCreate the socket will be created with
 * SO_REUSEADDR socket option which will allow the usage of a not completly
 * closed socket
 */
#define GSSOCKET_CREATE_CLIENT_REUSEADDR    (1<<0)

//-----------------------------------------------------------------------------
//Datatypes
//-----------------------------------------------------------------------------
typedef void * tGsSocketTcpClient;

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
 * Creates a new TCP client. The client can be connected to a server and is
 * in non-blocking mode by default so that it can be used safely from the UserC
 * cycle function. Connection will be opened immediately if possible.
 *
 * @param host  Which host should the client connect to
 * @param port  Which port should be used on the host
 * @param flags 0 or any combination of GSSOCKET_CREATE_CLIENT_*
 *
 * @return The handle of the created client or NULL if client couln't be created
 */
tGsSocketTcpClient gsSocketTcpClientCreate(const char * host, uint16_t port, uint32_t flags);

/**
 * Destroys a TCP client. Open connection will be closed and hdl shouldn't be
 * used after call to this function.
 *
 * @param hdl Handle of the client to be closed
 */
void gsSocketTcpClientDestroy(tGsSocketTcpClient hdl);

/**
 * Checks if the given client is connected to its host
 *
 * @param hdl Handle of the client
 *
 * @return > 0 if the client has a connection open
 */
int32_t gsSocketTcpClientIsConnected(tGsSocketTcpClient hdl);

/**
 * Reads up to n bytes from a connected server.
 *
 * @param hdl Handle of the TCP client
 * @param buf Buffer where the data will be read to
 * @param n   Number of bytes available in the buffer
 *
 * @return Number of bytes read from hdl to buf (up to n)
 *         < 0 if an error occoured (e.g. no connection)
 */
int32_t gsSocketTcpClientRead(tGsSocketTcpClient hdl, void * buf, int32_t n);

/**
 * Writes up to n bytes to a connected server.
 *
 * @param hdl Handle of the TCP server
 * @param buf Buffer where the data will be read from
 * @param n   Number of bytes available in the buffer
 *
 * @return Number of bytes written from buf to hdl (up to n)
 *         < 0 if an error occoured (e.g. no connection)
 */
int32_t gsSocketTcpClientWrite(tGsSocketTcpClient hdl, const void * buf, int32_t n);

#ifdef __cplusplus
}
#endif //__cplusplus
//-----------------------------------------------------------------------------
//Function implementation
//-----------------------------------------------------------------------------

#endif //GSSOCKETTCPCLIENT_H_INCLUDED
//-----------------------------------------------------------------------------
//EOF
//-----------------------------------------------------------------------------

