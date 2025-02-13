/**
 * @file
 *
 * A collection of utility functions implementing an UDP peer
 *
 * @author Matthias Weisser<br>
 *         Graf-Syteco GmbH & Co. KG
 *
 * @date   created: 8.12 2011
 */

#ifndef GSSOCKETUDPPEER_H_INCLUDED
#define GSSOCKETUDPPEER_H_INCLUDED
 
//-----------------------------------------------------------------------------
//Includes
//-----------------------------------------------------------------------------
#include <stdint.h>

//-----------------------------------------------------------------------------
//Defines
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
//Datatypes
//-----------------------------------------------------------------------------
typedef void * tGsSocketUdpPeer;

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
 * Creates a new UDP peer. UDP packets can then be send using this peer
 *
 * @param port  Which local port the peer should use
 * @param flags Currently always 0
 *
 * @return The handle of the created peer or NULL if peer couldn't be created
 */
tGsSocketUdpPeer gsSocketUdpPeerCreate(uint16_t port, uint32_t flags);

/**
 * Destroys a UDP peer.
 *
 * @param hdl Handle of the peer to be destroyed
 */
void gsSocketUdpPeerDestroy(tGsSocketUdpPeer hdl);

/**
 * Reads up to n bytes from a peer
 *
 * @param hdl       Handle of the UDP peer
 * @param buf       Buffer where the data will be read to
 * @param n         Number of bytes available in the buffer
 * @param peer      Will be filled with the IP of the peer (may be NULL)
 * @param peerLen   Length of the buffer behind peer
 * @param port      Remote port from where the data came
 *
 * @return Number of bytes read from hdl to buf (up to n)
 *         < 0 if an error occoured
 */
int32_t gsSocketUdpPeerRead(tGsSocketUdpPeer hdl, void * buf, int32_t n, char * peer, size_t peerLen, uint16_t * port);

/**
 * Writes up to n bytes to a peer
 *
 * @param hdl   Handle of the TCP server
 * @param buf   Buffer where the data will be read from
 * @param n     Number of bytes available in the buffer
 * @param peer  Name/IP of the peer where the data should be written
 * @param port  Port where the data should be written to
 *
 * @return Number of bytes written from buf to hdl (up to n)
 *         < 0 if an error occoured 
 */
int32_t gsSocketUdpPeerWrite(tGsSocketUdpPeer hdl, const void * buf, int32_t n, const char * peer, uint16_t port);

#ifdef __cplusplus
}
#endif //__cplusplus
//-----------------------------------------------------------------------------
//Function implementation
//-----------------------------------------------------------------------------

#endif //GSSOCKETUDPPEER_H_INCLUDED
//-----------------------------------------------------------------------------
//EOF
//-----------------------------------------------------------------------------

