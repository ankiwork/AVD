/*[CR]**************************************************************************
   Copyright (c) 2009 by IBV - Echtzeit- und Embedded GmbH & Co. KG, Germany
   All Rights reserved.
*/

/*[FH]**************************************************************************

   PROJECT:    ISOBUS - J1939 Protokollstack
   MODULE:     common
   FILE:       thr.h
   CONTENTS:   thread helper functions header
*/

/*[CL]**************************************************************************

   31-08-2008  ESA      creation

   ---
   ESA:  Erwin Saumweber, IBV, www.ibv-augsburg.net
*/

#ifndef _INCLUDE_THR_H_
#define _INCLUDE_THR_H_

/*******************************************************************************
 * prototypes
 ******************************************************************************/

int thr_set_name(char *format, ...);
int thr_mod_prio(int offset);

/******************************************************************************/

#endif /* _INCLUDE... */

/*[EOF]************************************************************************/

