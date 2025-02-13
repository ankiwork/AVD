/**
 * @file
 *
 * stdint.h for UserC API programs
 *
 * @author Matthias Weisser<br>
 *         Graf-Syteco GmbH & Co. KG
 *
 * @date   created: 17.3 2009
 */

#ifndef STDINT_H_INCLUDED
#define STDINT_H_INCLUDED

//-----------------------------------------------------------------------------
//Includes
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
//Defines
//-----------------------------------------------------------------------------
#define INT8_MIN      (-0x7f - 1)
#define INT16_MIN     (-0x7fff - 1)
#define INT32_MIN     (-0x7fffffff - 1)
#define INT64_MIN     (-0x7fffffffffffffff - 1)

#define INT8_MAX      (0x7f)
#define INT16_MAX     (0x7fff)
#define INT32_MAX     (0x7fffffff)
#define INT64_MAX     (0x7fffffffffffffff)

#define UINT8_MAX     (0xff)
#define UINT16_MAX    (0xffff)
#define UINT32_MAX    (0xffffffff)
#define UINT64_MAX    (0xffffffffffffffff)
//-----------------------------------------------------------------------------
//Datatypes
//-----------------------------------------------------------------------------
typedef unsigned char uint8_t;
typedef   signed char  int8_t;

typedef unsigned short uint16_t;
typedef   signed short  int16_t;

typedef unsigned int uint32_t;
typedef   signed int  int32_t;


#ifdef __aarch64__
typedef unsigned long uint64_t;
typedef          long  int64_t;

typedef uint64_t uintptr_t;
#else

typedef unsigned long long uint64_t;
typedef          long long  int64_t;

typedef uint32_t uintptr_t;
#endif

typedef uint8_t uint8;
typedef  int8_t  int8;

typedef uint16_t uint16;
typedef  int16_t  int16;

typedef uint32_t uint32;
typedef  int32_t  int32;

typedef uint64_t uint64;
typedef  int64_t  int64;

//-----------------------------------------------------------------------------
//Variables
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
//Function prototypes
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
//Function implementation
//-----------------------------------------------------------------------------

#endif //STDINT_H_INCLUDED
//-----------------------------------------------------------------------------
//EOF
//-----------------------------------------------------------------------------
