/**
 * @file
 *
 *Types used by gsMenu library.
 *
 * @author Pascal Lais<br>
 *         Graf-Syteco GmbH & Co. KG
 *
 * @date   created: 09.03.2017
 */

#ifndef GSMENUTYPES_H_INCLUDED
#define GSMENUTYPES_H_INCLUDED

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

/**
 * Type of a menu event send to a callback function
 */
typedef enum eagGsMenuEventType
{
	GS_MENU_EVENT_ENTER,
	GS_MENU_EVENT_LEAVE,
}eGsMenuEventType;

/**
 * Type of a menu event send to a callback function
 */
typedef enum eagGsMenuSubEventType
{
	GS_MENU_SUB_EVENT_ENTER,
	GS_MENU_SUB_EVENT_LEAVE,
}eGsMenuSubEventType;

/**
 * Type of a menu entry event send to a callback function
 */
typedef enum eagGsMenuEntryEventType
{
	GS_MENU_ENTRY_EVENT_SELECTED,
	GS_MENU_ENTRY_EVENT_UNSELECTED,
	GS_MENU_ENTRY_EVENT_ENTER,
	GS_MENU_ENTRY_EVENT_VAR_CHANGED,
}eGsMenuEntryEventType;

/**
 * Type of a menu entry
 */
typedef enum eagGsMenuEntryType
{
	GS_MENU_ENTRY_TYPE_NONE,
	GS_MENU_ENTRY_TYPE_SUBMENU,
	GS_MENU_ENTRY_TYPE_BOOL,
	GS_MENU_ENTRY_TYPE_ONOFF,
	GS_MENU_ENTRY_TYPE_INT_INC,
	GS_MENU_ENTRY_TYPE_INT_DEC,
	GS_MENU_ENTRY_TYPE_MASK,
	GS_MENU_ENTRY_TYPE_CONT,
	GS_MENU_ENTRY_TYPE_PARENTMENU,
	GS_MENU_ENTRY_TYPE_MENU,
	GS_MENU_ENTRY_TYPE_CLOSEMENU,
	GS_MENU_ENTRY_TYPE_SETVAR,
}eGsMenuEntryType;

/**
 * Objects that are used on the Menu Mask/Container
 */
typedef enum eagGsMenuObjects
{
	GS_MENU_OBJ_NONE = 0x00,
	GS_MENU_OBJ_TEXT = 0x01,
	GS_MENU_OBJ_ICON = 0x02,
	GS_MENU_OBJ_STATUSICON = 0x04,
}eGsMenuObjects;

/**
 * Type of the cursor
 */
typedef enum eagGsMenuCursor
{
	GS_MENU_CURSOR_NONE = 0x00,
	GS_MENU_CURSOR_STATIC = 0x01,
	GS_MENU_CURSOR_ICON = 0x02,
	GS_MENU_CURSOR_INVERT = 0x04,
	GS_MENU_CURSOR_UNDERLINE = 0x08,
	GS_MENU_CURSOR_BLINK = 0x10,
	GS_MENU_CURSOR_COORDS = 0x20,
	GS_MENU_CURSOR_ANIMATED = 0x40,
}eGsMenuCursor;

/**
 * Type of the menu base
 */
typedef enum eagGsMenuBase
{
	GS_MENU_BASE_MASK,
	GS_MENU_BASE_CONT,
}eGsMenuBase;

/**
 * Pointer to a menu entry
 */
typedef struct tagGsMenuEntry * tGsMenuEntryPtr;

/**
 * Pointer to a submenu
 */
typedef struct tagGsSubmenu * tGsSubmenuPtr;

/**
 * Pointer to a menu
 */
typedef struct tagGsMenu * tGsMenuPtr;

/**
 * Callback function used by the menu system to inform the application about
 * events on a list menu point
 */
typedef int32_t (*tGsMenuEntryFunc)(tGsMenuEntryPtr entry, eGsMenuEntryEventType event);

/**
 * Callback function used by the menu system to inform the application about events
 */
typedef int32_t (*tGsSubmenuFunc)(tGsSubmenuPtr submenu, eGsMenuSubEventType event);

/**
 * Callback function used by the menu system to inform the application about events
 */
typedef int32_t (*tGsMenuFunc)(tGsMenuPtr menu, eGsMenuEventType event);

/**
 * A single menu entry
 */
typedef struct tagGsMenuEntry
{
	uint32_t mId;
	eGsMenuEntryType mType;           	//!< Type of the entry
	tGsMenuEntryFunc mEntryCallBack;  	//!< Callback (may be NULL)

	uint32_t mIconIdx;          		//!< Icon index used by the menu point

	uint32_t mRCTextElement; 			//!< Text element from RCTEXT used by the menu point

	uint32_t mVariableHdl;      		//!< Variable handle used by the menu point
	uint32_t mVariableValue;
	uint32_t mMaskObj;          		//!< Mask to go to
	uint32_t mContObj;          		//!< Cont to show

	uint32_t mTag;            			//!< Generic tag which may be used by the callback
	const char * mText;      			//!< Generic text which may be used by the callback

	uint8_t mHidden;					//defines if the Entry is hidden
	uint32_t mMinUserLevel;				//defines the least user level, that is needet to display this entry

	tGsSubmenuPtr mSubMenu;  			//!< Sub menu which can be accessed from this entry
	tGsMenuPtr mMenu;           		//!< Menu to open

}tGsMenuEntry;

/**
 * Submenu "object"
 */
typedef struct tagGsSubmenu
{
	uint32_t mId;
	uint32_t mRCTitle;        			//RC Text element of Submenu Title
	size_t mCurEntry;         			//current selected Entry
	int32_t mTopVisibleEntry;  			//First Entry that is visible
	size_t mSelectedLine;     			//idx of Line that is currently selected
	uint32_t mCircleMode;   			//defines if circle Mode is enabled

	size_t mNumEntries;					//Number of Entries on the submenu
	tGsMenuEntryPtr mEntries;			//Pointer of tGsMenuEntry Array that contains the Entries for the submenu
	tGsSubmenuPtr mCurrentSub;			//Currently opened submenu (default: NULL)
	tGsSubmenuPtr mParentMenu;			//Parent Submenu
	tGsSubmenuFunc mSubmenuCallBack;	//Callback function

	uint32_t mTag;            			//!< Generic tag which may be used by the callback
	const char * mText;      			//!< Generic text which may be used by the callback
}tGsSubmenu;

/**
 * Menu "object"
 *  Concludes first Submenu of the Menu, different properties for the Menu,
 *  MASK/CONT Object and all the object and variable handles
 */
typedef struct tagGsMenu
{
	uint32_t mMenuObjects; 					//defines which Objects are used by the Menu (List, Icons, Status Icons)
	uint32_t mCursorType;                 	//defines what Type of Cursor is used.
	uint32_t mVisibleEntries;             	//Number of Visible Entries

	uint32_t * mVisibleEntryRCTextObj; 		//RC Text Object for all visible Entries (mMenuObjects)
	uint32_t mCurrentEntryRCTextObj; 		//RC Text Object where Text of current Entry shall be Displayed
	uint32_t * mVisibleEntryIconHdl;      	//IndexIcon Objects (mMenuObjects)
	uint32_t * mVisibleEntryStatusHdl; 		//Status IndexIcon Objects (mMenuObjects)

	uint32_t * mVisibleEntryCursorHdl;  	//Cursor IndexIcon Objects (mCursorType)
	uint32_t * mVisibleEntryTextAttrHdl;  	//RC Text Object Handles (mCursorType)
	int32_t mSelectedEntry; 				//Index of Selected Entry on a static Menu (mCursorType)
	uint32_t mNumCoordinates;             	//Number of Coordinates
	uint32_t * mCursorCoordHdls;          	//Coordinate Handles
	int32_t * mCursorCoords;              	//Coordinate Values
	uint32_t mCursorSpeed;                	//Speed of animation (px / 10 ms)

	uint32_t mTitleRCTextObj; 				//Text Object of Headline if available (otherwise 0)

	eGsMenuBase mMenuBaseType;            	//MASK or CONTAINER
	uint32_t mMenuBase;                   	//MASK or CONTAINER Object

	tGsSubmenuPtr mTopSubmenu;            	//Main Submenu of the Menu
	uint16_t mUserLevel;					//Current userlevel of the menu

	uint8_t mActive;						//defines if menu is currently active

	tGsMenuFunc mMenuCallBack;				//Callback function

}tGsMenu;

//-----------------------------------------------------------------------------
//Variables
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
//Function prototypes
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
//Function implementation
//-----------------------------------------------------------------------------

#endif /* GSMENUTYPES_H_INCLUDED */
//-----------------------------------------------------------------------------
//EOF
//-----------------------------------------------------------------------------
