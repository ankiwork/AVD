/**
 * @file
 *
 * Menu Logic for GDS Projects
 *
 * @author Pascal Lais<br>
 *         Graf-Syteco GmbH & Co. KG
 *
 * @date   created: 10.01.2017
 */

#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include <stdlib.h>

#include "gsMenuTypes.h"

//-----------------------------------------------------------------------------
//Datatypes
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
//Function prototypes
//-----------------------------------------------------------------------------

#ifdef __cplusplus
extern "C"
{
#endif //__cplusplus

/**
 * Blends in a gsMenu. If menu is already active, this function just updates the view of the menu.
 *
 * @param menu gsMenu to show
 */
void gsMenuShow(tGsMenu * menu);

/**
 * Hides a Menu without resetting it to its top level. 
 *
 * @param menu gsMenu to hide
 */
void gsMenuHide(tGsMenu * menu);

/**
 * Hides a Menu and resets it to its top level. 
 *
 * @param menu gsMenu to hide
 */
void gsMenuClose(tGsMenu * menu);

/**
 * Toggles a Menu.
 *
 * @param menu gsMenu to toggle
 */
void gsMenuToggle(tGsMenu * menu);

/**
 * Sets the circle Mode for a specific submenu
 *  0 = Circling is disabled
 *  1 = Circling is enabled, but after last entry ther will be empty spaces (if cursor = static)
 *  2 = Circling is enabled and after the last entry the entries from the beginning will be shown (only ha effect if cursor is static)
 *
 * @param submenu Submenu to change CircleMode
 * @param circleMode Value to set for circleMode
 */
void gsMenuSetCircleMode(tGsSubmenu * submenu, uint32_t circleMode);

/**
 * Checks if the Menu is in the top Submenu
 *
 * @param menu Menu to check
 *
 * @return 1 if active Submenu is the top submenu, 0 if not
 */
int32_t gsMenuIsOnTopLevel(tGsMenu * menu);

/**
 * Used to perform an action on the menu. 
 * Possible Actions are: 
 *  GS_VISU_LKF_MOVEUP: Move one Entry up 
 *  GS_VISU_LKF_MOVEDOWN: Move one Entry down
 *  GS_VISU_LKF_ENTER: Perform Action for currently selected Entry
 *  GS_VISU_LKF_LEAVE: Close active submenu
 *
 * @param menu Menu to perform action
 * @param lkf Action to perform
 */
void gsMenuAction(tGsMenu * menu, uint32_t lkf);

/**
 * Perform a Service Cycle for the Menu
 *
 * @param menu Menu to perform cycle
 */
void gsMenuCycle(tGsMenu * menu);

/**
 * Checks if a Menu is currently active
 *
 * @param menu Menu to check
 *
 * @return 1 if Menu is Active, 0 if not
 */
uint8_t gsMenuIsActive(tGsMenu * menu);

/**
 * Sets the user level for a specific menu
 *
 * @param menu  Menu to set user level
 * @param userLevel Value to set for user level
 */
void gsMenuSetUserLevel(tGsMenu * menu, uint16_t userLevel);

/**
 * Returns a Pointer to a Submenu with the corresponding Id
 *
 * @param menu  Menu Pointer
 * @param id Submenu-Id to search for
 *
 * @return Pointer to the Submenu with corresponding Id
 */
tGsSubmenu * gsMenuGetSubmenuById(tGsMenu * menu, uint32_t id);

/**
 * Returns a Pointer to a Menuentry with the corresponding Id
 *
 * @param menu  Menu Pointer
 * @param id Entry-Id to search for
 *
 * @return Pointer to the Entry with corresponding Id
 */
tGsMenuEntry * gsMenuGetEntryById(tGsMenu * menu, uint32_t id);

/**
 * Returns a Pointer to a Menuentry that is displayed on the view with the specific Index
 *
 * @param menu  Menu Pointer
 * @param index index of the Elemenut on the view
 *
 * @return Pointer to the Entry that is shown on the view with the specific index
 */
tGsMenuEntry * gsMenuGetEntryByIndex(tGsMenu * menu, uint32_t index);

/**
 * Returns a Pointer to the Menuentry that is displayed on the element with the ObjectID
 *
 * @param menu  Menu Pointer
 * @param ObjID ObjectId of the Object
 *
 * @return Pointer to the Entry that is shown on the view with the specific index
 */
tGsMenuEntry * gsMenuGetEntryByObjectId(tGsMenu * menu, uint32_t ObjID);

/**
 * Returns a Pointer to a Submenu which contains the given Entry
 *
 * @param menu  Menu Pointer
 * @param entry Entry to Search Submenu for
 *
 * @return Pointer to Submenu
 */
tGsSubmenu * gsMenuGetSubmenuOfEntry(tGsMenu * menu, tGsMenuEntry * entry);

/**
 * Returns a Pointer to the current Submenu
 *
 * @param menu  Menu Pointer
 *
 * @return Pointer to Submenu
 */
tGsSubmenu * gsMenuGetCurrentSubMenu(tGsMenu * menu);

/**
 * Used to Scroll to a specific Entry and Enter on it
 *
 * @param menu  Menu Pointer
 * @param ObjID Object ID of the Menu Object (Menutext, MenuBmp)
 */
void gsMenuEnterVisEntry(tGsMenu * menu, uint32_t ObjID);

/**
 * Used to Hide a MenuEntry
 *
 * @param menu  Menu Pointer
 * @param entry Menu-Entry to hide
 */
void gsMenuHideEntry(tGsMenu * menu, tGsMenuEntry * entry);

/**
 * Used to Show a MenuEntry
 *
 * @param menu  Menu Pointer
 * @param entry Menu-Entry to show
 */
void gsMenuShowEntry(tGsMenu * menu, tGsMenuEntry * entry);

/**
 * Used to go directly to a specific submenu
 *
 * @param menu  Menu Pointer
 * @param submenu Submenu to go to
 */
void gsMenuGoToSubmenu(tGsMenu * menu, tGsSubmenu * submenu);

#ifdef __cplusplus
}
#endif //__cplusplus

#endif  // #ifndef MENU_H_INCLUDED
//-----------------------------------------------------------------------------
//EOF
//-----------------------------------------------------------------------------
