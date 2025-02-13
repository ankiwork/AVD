/**
 * @file
 *
 * QuBus-API Types
 *
 * @author Pascal Lais<br>
 *         Graf-Syteco GmbH & Co. KG
 *
 * @date   created: 09.03.2017
 */
#ifndef GSQUBUSEASYTYPES_H_INCLUDED
#define GSQUBUSEASYTYPES_H_INCLUDED

//-----------------------------------------------------------------------------
//Includes
//-----------------------------------------------------------------------------
#include <stdint.h>

//-----------------------------------------------------------------------------
//Defines
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
//Data types
//-----------------------------------------------------------------------------

typedef enum eagGsQuBusEasyLoadType
{
    GS_QUBUS_EASY_LOAD_NONE,
    GS_QUBUS_EASY_LOAD_INDUCTIVE_1,
    GS_QUBUS_EASY_LOAD_INDUCTIVE_2,
    GS_QUBUS_EASY_LOAD_ELECTRIC,
}eGsQuBusEasyLoadType;

typedef enum eagGsQuBusEasyParameters
{
    GS_QUBUS_EASY_PARAM_CURRENT,
    GS_QUBUS_EASY_PARAM_TEMP,
    GS_QUBUS_EASY_PARAM_CURRENT_LIMIT,
    GS_QUBUS_EASY_PARAM_ADRESS,
	GS_QUBUS_EASY_PARAM_CHANNEL,
    GS_QUBUS_EASY_PARAM_ERROR_CODE,
    GS_QUBUS_EASY_PARAM_LOADTYPE,
    GS_QUBUS_EASY_PARAM_LOAD,
    GS_QUBUS_EASY_PARAM_SWVERSION,
    GS_QUBUS_EASY_PARAM_BUS_TIMEOUT,
    GS_QUBUS_EASY_PARAM_PWM_FREQ,
    GS_QUBUS_EASY_PARAM_AI_A1,
    GS_QUBUS_EASY_PARAM_AI_A2,
    GS_QUBUS_EASY_PARAM_AI_FUSE,
	GS_QUBUS_EASY_PARAM_AI_UB,
}eGsQuBusEasyParameters;


#endif  // #ifndef GSQUBUSEASYTYPES_H_INCLUDED
//-----------------------------------------------------------------------------
//EOF
//-----------------------------------------------------------------------------
