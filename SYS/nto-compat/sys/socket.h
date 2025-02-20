/**
 * @file
 *
 * sys/socket.h for UserC API programs
 *
 * @author Matthias Weisser<br>
 *         Graf-Syteco GmbH & Co. KG
 *
 * @date   created: 17.3 2009
 */

#ifndef SYS_SOCKET_H_INCLUDED
#define SYS_SOCKET_H_INCLUDED
 
//-----------------------------------------------------------------------------
//Includes
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
//Defines
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
//Datatypes
//-----------------------------------------------------------------------------
typedef struct fd_set {
    int fds_bits[256];
} fd_set;

struct sockaddr {
    uint8_t sa_len;         /* total length */
    uint8_t sa_family;  /* address family */
    char        sa_data[14];    /* actually longer; address value */
};

typedef uint32_t socklen_t;

//-----------------------------------------------------------------------------
//Variables
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
//Function prototypes
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
//Function implementation
//-----------------------------------------------------------------------------

#endif //SYS_SOCKET_H_INCLUDED
//-----------------------------------------------------------------------------
//EOF
//-----------------------------------------------------------------------------
