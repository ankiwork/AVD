/**
 * @file
 *
 * Types used by quBus library. This file may also used by firmware source and
 * has to contain only portable type definitions which are alignment and
 * size aware.
 *
 * @author Thomas Diener<br>
 *         Graf-Syteco GmbH & Co. KG
 *
 * @date   created: 06.10.2015
 */

#ifndef GSQUBUSTYPES_H_INCLUDED
#define GSQUBUSTYPES_H_INCLUDED

//-----------------------------------------------------------------------------
//Includes
//-----------------------------------------------------------------------------
#include <stdint.h>

//-----------------------------------------------------------------------------
//Defines
//-----------------------------------------------------------------------------
#define GSQUBUS_ADR_MAX         ((1 <<  7) - 1)
#define GSQUBUS_CONFIG_MAX      ((1 <<  4) - 1)
#define GSQUBUS_DATA_MAX        ((1 << 12) - 1)

//-----------------------------------------------------------------------------
//Data types
//-----------------------------------------------------------------------------

typedef enum eagGsQuBusError
{
    GS_QUBUS_ERROR_NONE,
    GS_QUBUS_ERROR_CHANNEL_OUT_OF_RANGE,
    GS_QUBUS_ERROR_ADR_OUT_OF_RANGE,
    GS_QUBUS_ERROR_CONFIG_OUT_OF_RANGE,
    GS_QUBUS_ERROR_DATA_OUT_OF_RANGE,
    GS_QUBUS_ERROR_INV_BITS,
    GS_QUBUS_ERROR_ACK,
    GS_QUBUS_ERROR_BUSY,
    GS_QUBUS_ERROR_BITTIME,
    GS_QUBUS_ERROR_NULL_HDL,
    GS_QUBUS_ERROR_SHMEM,
    GS_QUBUS_ERROR_SHMEM_SYNC,
}eGsQuBusError;

typedef enum eagGsQuBusCfgRead
{
    GS_QUBUS_CFG_READ_COM_TEST,         //!< Communication test telegram
    GS_QUBUS_CFG_READ_CURRENT,          //!< Read the current
    GS_QUBUS_CFG_READ_TEMP,             //!< Read the temperature
    GS_QUBUS_CFG_READ_INPUT_1,          //!< Reserved 3
    GS_QUBUS_CFG_READ_INPUT_2,          //!< Reserved 4
    GS_QUBUS_CFG_READ_FREQ_1,           //!< Reserved 5
    GS_QUBUS_CFG_READ_FREQ_2,           //!< Reserved 6
    GS_QUBUS_CFG_READ_RES_7,            //!< Reserved 7
    GS_QUBUS_CFG_READ_RES_8,            //!< Reserved 8
    GS_QUBUS_CFG_READ_RES_9,            //!< Reserved 9
    GS_QUBUS_CFG_READ_RES_10,           //!< Reserved 10
    GS_QUBUS_CFG_READ_RES_11,           //!< Reserved 11
    GS_QUBUS_CFG_READ_VIRTREG_DATA,     //!< Read data of the virtual register and increment the address by 1
    GS_QUBUS_CFG_READ_CURRENT_LIMIT,    //!< Read the configured current limit
    GS_QUBUS_CFG_READ_ERROR_CODE,       //!< Read the error code
    GS_QUBUS_CFG_READ_ADR,              //!< Read the slave address
}eGsQuBusCfgRead;

typedef enum eagGsQuBusCfgWrite
{
    GS_QUBUS_CFG_WRITE_RES_0,           //!< Reserved 0
    GS_QUBUS_CFG_WRITE_IND_LOAD_1,      //!< Inductive load between A1 and A2
    GS_QUBUS_CFG_WRITE_IND_LOAD_2,      //!< Inductive load between A1 and ground and/or A2 and ground
    GS_QUBUS_CFG_WRITE_RES_3,           //!< Reserved 3
    GS_QUBUS_CFG_WRITE_ELEC_LOAD_OFF,   //!< Electronic load off
    GS_QUBUS_CFG_WRITE_ELEC_LOAD,       //!< Electronic load
    GS_QUBUS_CFG_WRITE_RES_6,           //!< Reserved 6
    GS_QUBUS_CFG_WRITE_RES_7,           //!< Reserved 7
    GS_QUBUS_CFG_WRITE_RES_8,           //!< Reserved 8
    GS_QUBUS_CFG_WRITE_RES_9,           //!< Reserved 9
    GS_QUBUS_CFG_WRITE_RES_10,          //!< Reserved 10
    GS_QUBUS_CFG_WRITE_VIRTREG_SELECT,  //!< Select the virtual register
    GS_QUBUS_CFG_WRITE_VIRTREG_DATA,    //!< Write data to the virtual register and increment the address by 1
    GS_QUBUS_CFG_WRITE_CURRENT_LIMIT,   //!< Set the current limit
    GS_QUBUS_CFG_WRITE_ERROR_CODE,      //!< Set error code back
    GS_QUBUS_CFG_WRITE_ADR,             //!< Set slave address
}eGsQuBusCfgWrite;

typedef enum eagGsQuBusAdr
{
    GS_QUBUS_ADR_RESET          = 0,    //!< Special telegram: reset
    GS_QUBUS_ADR_START          = 1,    //!< Lowest slave address
    GS_QUBUS_ADR_END            = 0x7D, //!< Highest slave address
    GS_QUBUS_ADR_DEFAULT        = 0x7E, //!< Default slave adress
    GS_QUBUS_ADR_WRITE_ENABLE   = 0x7F, //!< Special telegram: write enable
}eGsQuBusAdr;

typedef enum eagGsQuBusRW
{
    GS_QUBUS_RW_WRITE           = 0,    //!< Write data to the slave
    GS_QUBUS_RW_READ            = 1,    //!< Read data to the slave
}eGsQuBusRW;

/**
 * QuBus virtual register
 */
typedef enum eagQuBusVirtualReg {
    GS_QUBUS_VREG_PWM_FREQ0,
    GS_QUBUS_VREG_PWM_FREQ1,
    GS_QUBUS_VREG_BUS_TIMEOUT0,
    GS_QUBUS_VREG_BUS_TIMEOUT1,
    GS_QUBUS_VREG_AI_A1_0,
    GS_QUBUS_VREG_AI_A1_1,
    GS_QUBUS_VREG_AI_A2_0,
    GS_QUBUS_VREG_AI_A2_1,
    GS_QUBUS_VREG_AI_FUSE0,
    GS_QUBUS_VREG_AI_FUSE1,
    GS_QUBUS_VREG_AI_UB0,
    GS_QUBUS_VREG_AI_UB1,
    GS_QUBUS_VREG_END,
}eQuBusVirtualReg;

//-----------------------------------------------------------------------------
//Variables
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
//Function prototypes
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
//Function implementation
//-----------------------------------------------------------------------------

#endif /* GSQUBUSTYPES_H_INCLUDED */
//-----------------------------------------------------------------------------
//EOF
//-----------------------------------------------------------------------------
