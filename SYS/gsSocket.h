/**
 * @file
 *
 * Socket interface abstraction for network access from UserC applications
 *
 * @author Matthias Weisser<br>
 *         Graf-Syteco GmbH & Co. KG
 *
 * @date   created: 8.12 2011
 */

#ifndef GSSOCKET_H_INCLUDED
#define GSSOCKET_H_INCLUDED
 
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
typedef struct tagGsSocketIntfInfo
{
    char mHwAddr[32];
    char mStatus[32];
    char mMedia[64];
    char mIpAddr[32];
}tGsSocketIntfInfo;

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
 * Network interface informations can be queried using this function. Informations
 * has to be updated prior to calling this function by gsSocketUpdateInfo
 *
 * @param intf Interface you wan't to query (NULL for primary network interface)
 * @param info Pointer to the information structure to be filled
 *
 * @return 0 if the request was successfully processed and buf was filled with the result
 */
int32_t gsSocketGetIntfInfo(const char * intf, tGsSocketIntfInfo * info);

#ifdef __cplusplus
}
#endif //__cplusplus
//-----------------------------------------------------------------------------
//Function implementation
//-----------------------------------------------------------------------------

#endif //GSSOCKET_H_INCLUDED
//-----------------------------------------------------------------------------
//EOF
//-----------------------------------------------------------------------------

