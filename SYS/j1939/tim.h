/*[CR]**************************************************************************
   Copyright (c) 2008 by IBV - Echtzeit- und Embedded GmbH & Co. KG
   All Rights reserved.
*/

/*[FH]**************************************************************************

   PROJECT:    ISOBUS - J1939 Protokollstack
   MODULE:     common
   FILE:       tim.h
   CONTENTS:   timer interface
*/

/*[CL]**************************************************************************

   03-03-2008  ANO      creation

   ---
   ANO:  Arkadius Nowakowski, IBV, www.ibv-augsburg.net
*/

/*[MP]**************************************************************************

   <man page>
*/

#ifndef _INCLUDE_TIM_H_
#define _INCLUDE_TIM_H_

/*******************************************************************************
 * typedefs
 ******************************************************************************/

/* timer type */
typedef enum __tim_type
{
   TIM_TYPE_INVAL,      /* invalid timer type      */

   TIM_TYPE_ONESHOT,    /* one shot timer          */
   TIM_TYPE_CYCLIC,     /* cyclic timer            */

   TIM_TYPE_NUM         /* number of timer types   */
} _tim_type;

typedef struct __tim_hdl *_tim;

/*******************************************************************************
 * prototypes
 ******************************************************************************/

/* timer creation */
_tim tim_init(_tim_type type, void (*tmohandler)(_tim timhdl, void *arg));

/* timer destruction */
int tim_exit(_tim timhdl);

/* timer control */
int tim_start(_tim timhdl, unsigned int tmoms, void *arg);
int tim_stop (_tim timhdl);

/*******************************************************************************
 * global data
 ******************************************************************************/

/******************************************************************************/

#endif /* _INCLUDE... */

/*[EOF]************************************************************************/

