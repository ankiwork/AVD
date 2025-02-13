/**
 * @file
 *
 * A collection of utility functions implementing a non-blocking tcp server
 *
 * @author Matthias Weisser<br>
 *         Graf-Syteco GmbH & Co. KG
 *
 * @date   created: 8.12 2011
 */

#ifndef GSSOCKETTCPSERVER_H_INCLUDED
#define GSSOCKETTCPSERVER_H_INCLUDED
 
//-----------------------------------------------------------------------------
//Includes
//-----------------------------------------------------------------------------
#include <stdint.h>

//-----------------------------------------------------------------------------
//Defines
//-----------------------------------------------------------------------------
#define GSSOCKETTCPSERVER_MULTI (1<<0)

//-----------------------------------------------------------------------------
//Datatypes
//-----------------------------------------------------------------------------
typedef void * tGsSocketTcpServer;

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
 * Creates a new TCP server which is able to connect to one client at a time.
 * The server will operate in non-blocking mode by default so that it can be
 * used savely from the UserC cycle function.
 *
 * @param port  Which port should the server listen to
 * @param flags 0 or GSSOCKETTCPSERVER_MULTI
 *              If GSSOCKETTCPSERVER_MULTI is given a server which can handle
 *              multiple connections will be created. The returned handle can
 *              then be used with the function gsSocketTcpServerGetClient to
 *              access the available clients on the server
 *
 * @return The handle of the created server or NULL if server couldn't be created
 */
tGsSocketTcpServer gsSocketTcpServerCreate(uint16_t port, uint32_t flags);

/**
 * Returns the client with index n which is connected to the server. This function
 * may return different servers for the same index in consecutive calls. To keep
 * track of the connected clients you should remember the returned pointers as these
 * pointers are distinct.
 *
 * @param hdl A server handle which was returned by gsSocketTcpServerCreate 
 *            called with GSSOCKETTCPSERVER_MULTI
 * @param n   Which of the currently connected servers should be returned
 *
 * @return A handle to the single client or 0 if n >= number of connected servers or
 *         if hdl is not a server created with GSSOCKETTCPSERVER_MULTI
 */
tGsSocketTcpServer gsSocketTcpServerGetClient(tGsSocketTcpServer hdl, uint32_t n);

/**
 * Sets the user data to a given connected client
 *
 * @param hdl Handle of the connected client for which the data should be set
 * @param d   New user data to be set
 *
 * @return > 0 if the user data was set
 */
int32_t gsSocketTcpServerSetUserData(tGsSocketTcpServer hdl, void * d);

/**
 * Gets the user data off a given connected client
 *
 * @param hdl Handle of the connected client for which the data should be get
 *
 * @return > 0 if the user data was set
 */
void * gsSocketTcpServerGetUserData(tGsSocketTcpServer hdl);

/**
 * Destroys a TCP server. Open connections are closed and hdl shouldn't be
 * used after call to this function.
 *
 * @param hdl Handle of the server to be closed
 */
void gsSocketTcpServerDestroy(tGsSocketTcpServer hdl);

/**
 * Checks if the given server currently has a client connected
 *
 * @param hdl Handle of the server
 *
 * @return > 0 if the server has a connected client
 */
int32_t gsSocketTcpServerIsConnected(tGsSocketTcpServer hdl);

/**
 * Closes the current client connection (if any). The server will then listen for
 * new incoming connections.
 *
 * @param hdl Handle of the server
 */
void gsSocketTcpServerClose(tGsSocketTcpServer hdl);

/**
 * Reads up to n bytes from a connected client.
 *
 * @param hdl Handle of the TCP server
 * @param buf Buffer where the data will be read to
 * @param n   Number of bytes available in the buffer
 *
 * @return Number of bytes read from hdl to buf (up to n)
 *         < 0 if an error occoured (e.g. client connection closed)
 */
int32_t gsSocketTcpServerRead(tGsSocketTcpServer hdl, void * buf, int32_t n);

/**
 * Writes up to n bytes to a connected client.
 *
 * @param hdl Handle of the TCP server
 * @param buf Buffer where the data will be read from
 * @param n   Number of bytes available in the buffer
 *
 * @return Number of bytes written from buf to hdl (up to n)
 *         < 0 if an error occoured (e.g. client connection closed)
 */
int32_t gsSocketTcpServerWrite(tGsSocketTcpServer hdl, const void * buf, int32_t n);

#ifdef __cplusplus
}
#endif //__cplusplus
//-----------------------------------------------------------------------------
//Function implementation
//-----------------------------------------------------------------------------

#endif //GSSOCKETTCPSERVER_H_INCLUDED
//-----------------------------------------------------------------------------
//EOF
//-----------------------------------------------------------------------------

