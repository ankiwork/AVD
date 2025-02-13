/**
 * @file
 *
 *
 * @author Pascal Lais<br>
 *         Graf-Syteco GmbH & Co. KG
 *
 * @date   created: 25.04.2017
 */
 
/************************************************************************/

#ifndef GSTABLEVIEW_H_INCLUDED
#define GSTABLEVIEW_H_INCLUDED

//-----------------------------------------------------------------------------
//Includes
//-----------------------------------------------------------------------------

#include "gsTableViewTypes.h"

//-----------------------------------------------------------------------------
//Defines
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
//Datatypes
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
 * Initializes a gsTableView.
 * After calling this function be careful when changing parameters in the gsTableView-Object.
 * To be save use the set and get functions of gsTableView.h
 *
 * @param table Pointer to gsTableView-Object
 */
void gsTableViewInit(tGsTableView * table);

/**
 * DeInitializes the gsTableView Object and Deallocates used Memory
 *
 * @param table Pointer to gsTableView-Object
 */
void gsTableViewDeInit(tGsTableView * table);

/**
 * Cycle Function of gsTableView.
 *
 * @param table Pointer to gsTableView-Object
 * @param evtc evtc of UserCCycle
 * @param evtv evtv of UserCCycle
 */
void gsTableViewCycle(tGsTableView * table, uint32_t evtc, tUserCEvt * evtv);

/**
 * Updates the View of the Table.
 *
 * @param table Pointer to gsTableView-Object
 */
void gsTableViewUpdate(tGsTableView * table);

/**
 * Sorts the data in the Table
 *
 * @param table Pointer to gsTableView-Object
 * @param column Index of Column with Data to Sort after (index beginning at 0)
 * @param order Defines if ascending or descending order
 */
void gsTableViewOrderByColumn(tGsTableView * table, uint32_t column, eGsTableViewSortOrder order);

/**
 * Set a Parameter
 * Possible Parameters are:
 * -GS_TABLEVIEW_PARAMETER_PAGE
 * -GS_TABLEVIEW_PARAMETER_NUM_DATA
 *
 * @param table Pointer to gsTableView-Object
 * @param parameter Defines which parameter gets set
 * @param value Value to set for parameter
 */
void gsTableViewSetParameter(tGsTableView * table, eGsTableViewParameter parameter, uint32_t value);

/**
 * Get value of a Parameter
 * Possible Parameters are:
 * -GS_TABLEVIEW_PARAMETER_PAGE
 * -GS_TABLEVIEW_PARAMETER_NUM_PAGES
 * -GS_TABLEVIEW_PARAMETER_NUM_DATA
 * -GS_TABLEVIEW_PARAMETER_ORDER_BY_COLUMN
 * -GS_TABLEVIEW_PARAMETER_SORT_ORDER
 *
 * @param table Pointer to gsTableView-Object
 * @param parameter Defines which parameter gets returned
 *
 * @return Value of the requested parameter
 */
uint32_t gsTableViewGetParameter(tGsTableView * table, eGsTableViewParameter parameter);

#ifdef __cplusplus
}
#endif //__cplusplus

//-----------------------------------------------------------------------------
//Function implementation
//-----------------------------------------------------------------------------

#endif  // #ifndef GSTABLEVIEW_H_INCLUDED
//-----------------------------------------------------------------------------
//EOF
//-----------------------------------------------------------------------------
