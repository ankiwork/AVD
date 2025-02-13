/**
 * @file
 *
 *Types used by gsTrendWriter library.
 *
 * @author Pascal Lais<br>
 *         Graf-Syteco GmbH & Co. KG
 *
 * @date   created: 10.05.2017
 */
 
#ifndef GSDROPDOWNLISTTYPES_H_INCLUDED
#define GSDROPDOWNLISTTYPES_H_INCLUDED

//-----------------------------------------------------------------------------
//Includes
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
//Defines
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
//Data types
//-----------------------------------------------------------------------------

/**
 * Events for dropdown entry callback function
 */
typedef enum eagGsDropdownEntryEvents
{
    GS_DROPDOWNENTRY_EVENT_SELECT,
    GS_DROPDOWNENTRY_EVENT_DESELECT,
}eGsDropdownEntryEvents;

/**
 * Events for dropdown list callback function
 */
typedef enum eagGsDropdownListEvents
{
    GS_DROPDOWNLIST_EVENT_SHOW,
    GS_DROPDOWNLIST_EVENT_HIDE,
    GS_DROPDOWNLIST_EVENT_VALUE_CHANGED,
}eGsDropdownListEvents;

/**
 * Parameters to set or get for dropdown list
 */
typedef enum eagGsDropdownListParameter
{
    GS_DROPDOWNLIST_PARAMETER_WIDTH,
    GS_DROPDOWNLIST_PARAMETER_HEIGHT,
	GS_DROPDOWNLIST_PARAMETER_ENTRY_WIDTH,
    GS_DROPDOWNLIST_PARAMETER_ENTRY_HEIGHT,
    GS_DROPDOWNLIST_PARAMETER_PADDING,
    GS_DROPDOWNLIST_PARAMETER_ENTRY_SPACE,
    GS_DROPDOWNLIST_PARAMETER_NUM_ENTRIES,
    GS_DROPDOWNLIST_PARAMETER_SELECTED_ENTRY,
    GS_DROPDOWNLIST_PARAMETER_VISIBLE,
}eGsDropdownListParameter;

/**
 * Pointer to a dropdown entry
 */
typedef struct tagGsDropdownEntry * tGsDropdownEntryPtr;

/**
 * Pointer to a dropdown list
 */
typedef struct tagGsDropdownList * tGsDropdownListPtr;

/**
 * Callback function for a dropdown entry
 */
typedef void (*tGsDropdownEntryCallback)(tGsDropdownEntryPtr entry, eGsDropdownEntryEvents evt);

/**
 * Callback function for a dropdown list
 */
typedef void (*tGsDropdownListCallback)(tGsDropdownListPtr list, eGsDropdownListEvents evt);

/**
 * Coordinates for a dropdown list
 */
typedef struct tagGsDropdownCoordinates
{
    int32_t mX;
    int32_t mY;
}tGsDropdownCoordinates;

/**
 * Dropdown list entry
 */
typedef struct tagGsDropdownEntry
{
	uint32_t mObjHdl;
    uint32_t mResTextObj;
    uint32_t mVarValue;
    uint32_t mAttrHdl;
    uint32_t mMenuActionObj;
    tGsDropdownEntryCallback mCallback;
}tGsDropdownEntry;

/**
 * Dropdown list
 */
typedef struct tagGsDropdownList
{
    tGsDropdownCoordinates mPosition;
    uint32_t mEntryWidth;
    uint32_t mEntryHeight;
    uint32_t mPadding;
    uint32_t mEntrySpace;
    uint32_t mEntriesPerRow;
    uint32_t mMenuActionObj;
    uint32_t mNumEntries;
    tGsDropdownEntry * mEntries;
    uint32_t mBackgroundObj;
    uint32_t mBackgroundAttrHdl;
    uint32_t mTextObj;
    uint32_t mVarHdl;
    uint32_t mSelectedEntry;
    uint8_t mIsVisible;
    tGsDropdownListCallback mCallback;
}tGsDropdownList;

//-----------------------------------------------------------------------------
//Variables
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
//Function prototypes
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
//Function implementation
//-----------------------------------------------------------------------------
#endif  // #ifndef GSDROPDOWNLISTTYPES_H_INCLUDED
//-----------------------------------------------------------------------------
//EOF
//-----------------------------------------------------------------------------
