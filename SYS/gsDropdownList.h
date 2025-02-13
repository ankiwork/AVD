/**
 * @file
 *
 *
 * @author Pascal Lais<br>
 *         Graf-Syteco GmbH & Co. KG
 *
 * @date   created: 05.05.2017
 */
 
#ifndef GSDROPDOWNLIST_H_INCLUDED
#define GSDROPDOWNLIST_H_INCLUDED

//-----------------------------------------------------------------------------
//Includes
//-----------------------------------------------------------------------------

#include "gsDropdownListTypes.h"

//-----------------------------------------------------------------------------
//Defines
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
//Data types
//-----------------------------------------------------------------------------

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
 * Initializes a dropdown list object
 *
 * @param dropdownList List object to initialize
 */
void gsDropdownListInit(tGsDropdownList * dropdownList);

/**
 * DeInitializes a dropdown list object
 *
 * @param dropdownList List object to deinitialize
 */
void gsDropdownListDeInit(tGsDropdownList * dropdownList);

/**
 * Blends in a dropdown list.
 *
 * @param dropdownList List to show
 */
void gsDropdownListShow(tGsDropdownList * dropdownList);

/**
 * Hides a dropdown list.
 *
 * @param dropdownList List to hide
 */
void gsDropdownListHide(tGsDropdownList * dropdownList);

/**
 * Cycle Function for dropdown lists. Use this in UserCCycle if dropdownlists are used.
 *
 * @param evtc
 * @param evtv
 */
void gsDropdownListCycle(uint32_t evtc, tUserCEvt * evtv);

/**
 * Sets a parameter for a list to a specific value
 *
 * @param dropdownList list object
 * @param param Requested Parameter
 * @param value Value for Parameter.
 */
void gsDropdownListSetParameter(tGsDropdownList * dropdownList, eGsDropdownListParameter param, uint32_t value);

/**
 * Returns value of a parameter for a list
 *
 * @param dropdownList list object
 * @param param Requested Parameter
 */
uint32_t gsDropdownListGetParameter(tGsDropdownList * dropdownList, eGsDropdownListParameter param);

#ifdef __cplusplus
}
#endif //__cplusplus

//-----------------------------------------------------------------------------
//Function implementation
//-----------------------------------------------------------------------------

#endif  // #ifndef GSDROPDOWNLIST_H_INCLUDED
//-----------------------------------------------------------------------------
//EOF
//-----------------------------------------------------------------------------
