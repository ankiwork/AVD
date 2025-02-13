/**
 * @file
 *
 * Public interface to HID devices
 *
 * @author Matthias Weisser<br>
 *         Graf-Syteco GmbH & Co. KG
 *
 * @date   created: 27.6 2012
 */

#ifndef GSUSBHID_H_INCLUDED
#define GSUSBHID_H_INCLUDED

//-----------------------------------------------------------------------------
//Includes
//-----------------------------------------------------------------------------
#include <stdint.h>

//-----------------------------------------------------------------------------
//Defines
//-----------------------------------------------------------------------------
#define GS_USB_HID_SCANCODE_CAPS_LOCK       0x39
#define GS_USB_HID_SCANCODE_F1              0x3A
#define GS_USB_HID_SCANCODE_F2              0x3B
#define GS_USB_HID_SCANCODE_F3              0x3C
#define GS_USB_HID_SCANCODE_F4              0x3D
#define GS_USB_HID_SCANCODE_F5              0x3E
#define GS_USB_HID_SCANCODE_F6              0x3F
#define GS_USB_HID_SCANCODE_F7              0x40
#define GS_USB_HID_SCANCODE_F8              0x41
#define GS_USB_HID_SCANCODE_F9              0x42
#define GS_USB_HID_SCANCODE_F10             0x43
#define GS_USB_HID_SCANCODE_F11             0x44
#define GS_USB_HID_SCANCODE_F12             0x45
#define GS_USB_HID_SCANCODE_PRINT_SCREEN    0x46
#define GS_USB_HID_SCANCODE_SCROLL_LOCK     0x47
#define GS_USB_HID_SCANCODE_PAUSE           0x48
#define GS_USB_HID_SCANCODE_INSERT          0x49
#define GS_USB_HID_SCANCODE_HOME            0x4A
#define GS_USB_HID_SCANCODE_PAGEUP          0x4B
#define GS_USB_HID_SCANCODE_DELETE          0x4C
#define GS_USB_HID_SCANCODE_END             0x4D
#define GS_USB_HID_SCANCODE_PAGEDOWN        0x4E
#define GS_USB_HID_SCANCODE_RIGHTARROW      0x4F
#define GS_USB_HID_SCANCODE_LEFTARROW       0x50
#define GS_USB_HID_SCANCODE_DOWNARROW       0x51
#define GS_USB_HID_SCANCODE_UPARROW         0x52
#define GS_USB_HID_SCANCODE_NUMLOCK         0x53
#define GS_USB_HID_SCANCODE_LEFTCONTROL     0xE0
#define GS_USB_HID_SCANCODE_LEFTSHIFT       0xE1
#define GS_USB_HID_SCANCODE_LEFTALT         0xE2
#define GS_USB_HID_SCANCODE_LEFTGUI         0xE3
#define GS_USB_HID_SCANCODE_RIGHTCONTROL    0xE4
#define GS_USB_HID_SCANCODE_RIGHTSHIFT      0xE5
#define GS_USB_HID_SCANCODE_RIGHTALT        0xE6
#define GS_USB_HID_SCANCODE_RIGHTGUI        0xE7

//-----------------------------------------------------------------------------
//Datatypes
//-----------------------------------------------------------------------------

/**
 * The different keyboard layouts available
 */
typedef enum eagGsUsbHidKeyboardLayout
{
    GS_USB_HID_KEY_LAYOUT_US,
    GS_USB_HID_KEY_LAYOUT_US_INTERNATIONAL,
    GS_USB_HID_KEY_LAYOUT_GERMAN,
    GS_USB_HID_KEY_LAYOUT_RUSSIAN_WINDOWS,

    GS_USB_HID_KEY_LAYOUT_CUSTOM0 = 1000,
    GS_USB_HID_KEY_LAYOUT_CUSTOM1,
    GS_USB_HID_KEY_LAYOUT_CUSTOM2,
    GS_USB_HID_KEY_LAYOUT_CUSTOM3,
    GS_USB_HID_KEY_LAYOUT_CUSTOM4,
    GS_USB_HID_KEY_LAYOUT_CUSTOM5,
    GS_USB_HID_KEY_LAYOUT_CUSTOM6,
    GS_USB_HID_KEY_LAYOUT_CUSTOM7,

}eGsUsbHidKeyboardLayout;

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
 * Sets the keyboard layout for a given keyboard. Other layouts may be possible
 * by setting stuff into the custom tables.
 *
 * @param n      Which keyboard should use the given layout (Currently always 0)
 * @param layout One of eGsUsbHidKeyboardLayout
 *
 * @return 0 if the layout was set successfully
 */
int32_t gsUsbHidSetLayout(uint32_t n, eGsUsbHidKeyboardLayout layout);

#ifdef __cplusplus
}
#endif //__cplusplus
//-----------------------------------------------------------------------------
//Function implementation
//-----------------------------------------------------------------------------

#endif //GSUSBHID_H_INCLUDED
//-----------------------------------------------------------------------------
//EOF
//-----------------------------------------------------------------------------


