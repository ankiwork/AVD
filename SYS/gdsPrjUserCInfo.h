/**
 * @file
 *
 * @author Pascal Lais<br>
 *         Graf-Syteco GmbH & Co. KG
 *
 * @date   created: 10.03.2020
 */


#ifndef GDSPRJUSERCINFO_H_INCLUDED
#define GDSPRJUSERCINFO_H_INCLUDED

//-----------------------------------------------------------------------------
//Includes
//-----------------------------------------------------------------------------

#include <stddef.h>
#include <stdint.h>

//-----------------------------------------------------------------------------
//Defines
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
//Datatypes
//-----------------------------------------------------------------------------

typedef struct tagGsMaskInfo
{
    uint32_t mNumber;
    const char * mName;
}tGsMaskInfo;

typedef struct tagGsContInfo
{
    uint32_t mNumber;
    const char * mName;
}tGsContInfo;

typedef struct tagGsVarInfo
{
    uint32_t mHandle;
    const char * mName;
    const char * mComment;
}tGsVarInfo;

//-----------------------------------------------------------------------------
//Variables
//-----------------------------------------------------------------------------
extern const tGsMaskInfo _gs_prjusercinfo_mMaskInfo[];
extern const size_t _gs_prjusercinfo_mMaskInfoSize;
extern const tGsContInfo _gs_prjusercinfo_mContInfo[];
extern const size_t _gs_prjusercinfo_mContInfoSize;
extern const tGsVarInfo _gs_prjusercinfo_mVarInfo[];
extern const size_t _gs_prjusercinfo_mVarInfoSize;

//-----------------------------------------------------------------------------
//Function prototypes
//-----------------------------------------------------------------------------

#endif //GDSPRJUSERCINFO_H_INCLUDED
//-----------------------------------------------------------------------------
//EOF
//-----------------------------------------------------------------------------
