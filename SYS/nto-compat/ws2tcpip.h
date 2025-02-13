/**
 * @file
 *
 * ws2tcpip.h for UserC API programs
 *
 * @author Matthias Weisser<br>
 *         Graf-Syteco GmbH & Co. KG
 *
 * @date   created: 17.3 2009
 */

#ifndef WS2TCPIP_H_INCLUDED
#define WS2TCPIP_H_INCLUDED
 
//-----------------------------------------------------------------------------
//Includes
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
//Defines
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
//Datatypes
//-----------------------------------------------------------------------------
typedef unsigned char u_char;
typedef unsigned short u_short;
typedef unsigned long u_long;

struct in_addr {
	union {
		struct tagInAddr0 { u_char s_b1,s_b2,s_b3,s_b4; } S_un_b;
		struct tagInAddr1 { u_short s_w1,s_w2; } S_un_w;
		u_long S_addr;
	} S_un;
#define s_addr  S_un.S_addr
#define s_host  S_un.S_un_b.s_b2
#define s_net   S_un.S_un_b.s_b1
#define s_imp   S_un.S_un_w.s_w2
#define s_impno S_un.S_un_b.s_b4
#define s_lh    S_un.S_un_b.s_b3
};

struct sockaddr_in {
	short	sin_family;
	u_short	sin_port;
	struct	in_addr sin_addr;
	char	sin_zero[8];
};

struct sockaddr {
	u_short sa_family;
	char	sa_data[14];
};

//-----------------------------------------------------------------------------
//Variables
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
//Function prototypes
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
//Function implementation
//-----------------------------------------------------------------------------

#endif //WS2TCPIP_H_INCLUDED
//-----------------------------------------------------------------------------
//EOF
//-----------------------------------------------------------------------------
