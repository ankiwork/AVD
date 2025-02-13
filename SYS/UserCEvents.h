/**
 * @file
 *
 * Event structure for UserC cyclic function
 *
 * @author Matthias Weisser<br>
 *         Graf-Syteco GmbH & Co. KG
 *
 * @date   created: 11.10 2007
 */

#ifndef USERCEVENTS_H_INCLUDED
#define USERCEVENTS_H_INCLUDED

//-----------------------------------------------------------------------------
//Includes
//-----------------------------------------------------------------------------
#include <stdint.h>

//-----------------------------------------------------------------------------
//Defines
//-----------------------------------------------------------------------------
#ifdef __GNUC__

#if (__GNUC__ > 3) && (__GNUC_MINOR__ > 4)
#define USERCAPI_DEPRECATED(x)  __attribute__ ((deprecated(x)))
#else
#define USERCAPI_DEPRECATED(x)  __attribute__ ((deprecated))
#endif

#else
#define USERCAPI_DEPRECATED(x)
#endif

#define CEVT_MENU_INDEX                0  //!< Event raised by a menu point
#define CEVT_TEXT_CHANGE               1  //!< Event telling a text change in an object
#define CEVT_EDIT_START                2  //!< Event telling an object has entered edit mode
#define CEVT_EDIT_END                  3  //!< Event telling an object has left edit mode
#define CEVT_SELECTED                  4  //!< Event telling an object has been selected
#define CEVT_UNSELECTED                5  //!< Event telling an object has been unselected
#define CEVT_MASK_ON                   6  //!< Event telling a mask was switched on
#define CEVT_MASK_OFF                  7  //!< Event telling a mask was switched off
#define CEVT_INFOCONT_ON               8  //!< Event telling a info container was switched on
#define CEVT_INFOCONT_OFF              9  //!< Event telling a info container was switched off
#define CEVT_MSGCONT_ON               10  //!< Event telling a message container was switched on
#define CEVT_MSGCONT_OFF              11  //!< Event telling a message container was switched off
#define CEVT_CAN_ERROR                12  //!< Event telling that there was an error on a CAN bus
#define CEVT_PRJ_UPDATE               13  //!< Event telling that a project update is ready
#define CEVT_VAR_CHANGE               14  //!< Event telling that a variable value has changed
#define CEVT_KEY                      15  //!< Event telling that a key was pressed/released/repeated
#define CEVT_J1939_SPBUF_CHANGE       16  //!< Event telling that a J1939 SP data buffer has changed
#define CEVT_VISOBJDATA_CHANGE        17  //!< Event telling that global data of a visual object has changed
#define CEVT_VISU_CHANGE              18  //!< Event telling that displayed mask/container has changed
#define CEVT_REMACC                   19  //!< Event telling that remote access connection is active/ready
#define CEVT_VISU_KEY                 20  //!< Event telling which keys are processed by visualization
#define CEVT_TOUCH                    21  //!< Event telling that something went on on the touch screen
#define CEVT_NETWORK                  22  //!< Event telling that a network interface changed its state
#define CEVT_TRANS_FILE               23  //!< Event telling that a file is beeing transfered to device
#define CEVT_KEY_REPEAT               24  //!< Event telling that a key is still pressed
#define CEVT_MENU_INDEX_RELEASE       25  //!< Event telling that a menu point was released (after CEVT_MENU_INDEX)
#define CEVT_MENU_ACTION              26  //!< Event telling that a menu object is pressed/released/repeated via key/touch
#define CEVT_TOUCH_KEYBOARD           27  //!< Event telling that a obj's touch keyboard was pressed/released
#define CEVT_USB_MEMORY               28  //!< Event telling that the state of USB memory changed
#define CEVT_HOTPLUG                  29  //!< Event telling that something was plugged into or removed from device
#define CEVT_TIMEDATE_CHANGE          30  //!< Event telling that time/date object has changed
#define CEVT_RCCOLOR_CHANGE           31  //!< Event telling that a resource color value has changed
#define CEVT_SEND_TO_VISU_OBJ         32  //!< Event telling that object has been changed by 'SendToVisuObj' function
#define CEVT_ANALOGIN_CHANGED         33  //!< Event telling that analog input state has changed
// Note: Add new defines here (at the end), leave existing defines unchanged !

#define CEVT_SOURCE_MENU               0  //!< The source was a menu point
#define CEVT_SOURCE_CAN0               1  //!< The source was CAN0
#define CEVT_SOURCE_CAN1               2  //!< The source was CAN1
#define CEVT_SOURCE_KEY                3  //!< The source was a Key
#define CEVT_SOURCE_EDIT               4  //!< The source was some sort of edit object
#define CEVT_SOURCE_VISU               5  //!< The source was a state change in visualization
#define CEVT_SOURCE_GENERIC            6  //!< The source was some generic project handling
#define CEVT_SOURCE_VARTAB             7  //!< The source was the variable table
#define CEVT_SOURCE_J1939              8  //!< The source was a J1939 message
#define CEVT_SOURCE_TOUCH              9  //!< The source was the touch screen
#define CEVT_SOURCE_ETH0              10  //!< The source was network interface eth0
#define CEVT_SOURCE_PPP0              11  //!< The source was network interface ppp0
#define CEVT_SOURCE_USB               12  //!< The source was USB
#define CEVT_SOURCE_ETH1              13  //!< The source was network interface eth1
#define CEVT_SOURCE_CAN2              14  //!< The source was CAN3
#define CEVT_SOURCE_CAN3              15  //!< The source was CAN4
#define CEVT_SOURCE_IO                16  //!< The source was IO
// Note: Add new defines here (at the end), leave existing defines unchanged !

#define CEVT_TOUCH_DOWN                0  //!< A new touch point was detected
#define CEVT_TOUCH_UP                  1  //!< A touch point was removed
#define CEVT_TOUCH_ON                  2  //!< A moving touch point

#define CEVT_TD_CHANGED_NONE           0  //!< nothing changed
#define CEVT_TD_CHANGED_DATE           1  //!< in case of 'DD.MM.YY', 'DD.MM.YYYY', 'MM/DD/YY', 'MM/DD/YYYY', 'YY/MM/DD', 'YYYY/MM/DD'
#define CEVT_TD_CHANGED_TIME           2  //!< in case of 'hh:mm:ss (24h)', 'hh:mm (24h)', 'hh:mm:ss (am/pm)', 'hh:mm (am/pm)'

#define CEVT_NETWORK_STATE_UP          0  //!< Network interface is ready but communication may be not possible
#define CEVT_NETWORK_STATE_CONFIG      1  //!< Network interface is configured (has an IP)

#define CEVT_TF_STATE_BEGIN            0  //!< "Online" File transfer begin event
#define CEVT_TF_STATE_PROGRESS         1  //!< "Online" File transfer progress event
#define CEVT_TF_STATE_END              2  //!< "Online" File transfer end event
#define CEVT_TF_OFFLINE_DOWNLOAD       3  //!< "Offline" file transfer, download from server event
#define CEVT_TF_OFFLINE_UPLOAD         4  //!< "Offline" file transfer, upload to server event
#define CEVT_TF_OFFLINE_NOF            5  //!< Number of "offline" files on server event
#define CEVT_TF_OFFLINE_FILEINFO       6  //!< Servers "offline" file information event

#define CEVT_STATE_RELEASE             0  //!< Key or Touch was released
#define CEVT_STATE_PRESS               1  //!< Key or Touch was pressed
#define CEVT_STATE_REPEAT              2  //!< Key or Touch was repeated
#define CEVT_STATE_MOVEOUT             3  //!< Touch moved out of object area
#define CEVT_STATE_ESCAPE              4  //!< ESC was pressed during EDIT state
#define CEVT_STATE_BREAK               5  //!< BREAK was pressed during EDIT state
#define CEVT_STATE_ADD                 6  //!< Something was added (CEVT_HOTPLUG)
#define CEVT_STATE_REMOVED             7  //!< Something was removed (CEVT_HOTPLUG)

// See also "sys_types.h"
#define CEVT_ACTION_CALLMASK           0  //!< Maske aufrufen
#define CEVT_ACTION_CALLPRIOMASK       1  //!< Prio Maske aufrufen
#define CEVT_ACTION_REMOVETOPMASK      2  //!< Top-Maske auf dem Stack l�schen
#define CEVT_ACTION_SHOWINFOCONTAINER  3  //!< Info Container anzeigen
#define CEVT_ACTION_HIDEINFOCONTAINER  4  //!< Info Container verbergen
#define CEVT_ACTION_SHOWMSGCONTAINER   5  //!< Message Container anzeigen
#define CEVT_ACTION_HIDEMSGCONTAINER   6  //!< Message Container verbergen
#define CEVT_ACTION_SENDMENUINDEX      7  //!< Sendet Men�index an User-C

//-----------------------------------------------------------------------------
//Datatypes
//-----------------------------------------------------------------------------

//Each of these event functions is limited to a size of 24 bytes. The common
//event header adds additional 8 bytes which makes 32 bytes total which is
//the maximum size we can transfer on MCP6 between the two processors

/**
 * Menu index event
 */
typedef struct tagCEvtMenuIndex
{
    uint32_t Index;  //!< Index as given in GDSDesigner
    uint32_t ObjID;  //!< ID of the object which caused the event
}tCEvtMenuIndex;

/**
 * Text change event
 */
typedef struct tagCEvtTextChange
{
    uint32_t ObjID;  //!< ID of the object which caused the event
    char Text[20];   //!< First 20 byte of the changed text
}tCEvtTextChange;

/**
 * Edit start
 *
 * An object entering edit mode sends this event
 */
typedef struct tagCEvtEditStart
{
    uint32_t ObjID;  //!< ID of the object which caused the event
}tCEvtEditStart;

/**
 * Edit end
 *
 * An object leaving edit mode sends this event
 */
typedef struct tagCEvtEditEnd
{
    uint32_t ObjID;  //!< ID of the object which caused the event
}tCEvtEditEnd;

/**
 * Selected
 *
 * An object entering selected mode sends this event
 */
typedef struct tagCEvtSelected
{
    uint32_t ObjID;  //!< ID of the object which caused the event
}tCEvtSelected;

/**
 * Unselected
 *
 * An object leaving selected mode sends this event
 */
typedef struct tagCEvtUnselected
{
    uint32_t ObjID;  //!< ID of the object which caused the event
}tCEvtUnselected;

/**
 * Send if a mask is switched on
 */
typedef struct tagCEvtMaskOn
{
    uint32_t Number;  //!< Number of the mask which was switched on
}tCEvtMaskOn;

/**
 * Send if a mask is switched off
 */
typedef struct tagCEvtMaskOff
{
    uint32_t Number;  //!< Number of the mask which was switched on
}tCEvtMaskOff;

/**
 * Send if a info container is switched on
 */
typedef struct tagCEvtInfoContOn
{
    uint32_t Number;  //!< Number of the info container which was switched on
}tCEvtInfoContOn;

/**
 * Send if a info container is switched off
 */
typedef struct tagCEvtInfoContOff
{
    uint32_t Number;  //!< Number of the info container which was switched off
}tCEvtInfoContOff;

/**
 * Send if a message container is switched on
 */
typedef struct tagCEvtMsgContOn
{
    uint32_t Number;  //!< Number of the message container which was switched on
}tCEvtMsgContOn;

/**
 * Send if a message container is switched off
 */
typedef struct tagCEvtMsgContOff
{
    uint32_t Number;  //!< Number of the message container which was switched off
}tCEvtMsgContOff;

/**
 * Send if an error on a CAN bus occurred
 */
typedef struct tagCEvtCanError
{
    uint32_t Type;  //!< Type of the error on the CAN
}tCEvtCanError;

/**
 * Send if a project update is ready
 */
typedef struct tagCEvtPrjUpdate
{
    uint32_t Res;  //!< Currently not used
}tCEvtPrjUpdate;

/**
 * Variable change event
 */
typedef struct tagCEvtVarChange
{
    uint32_t Reserved;
    union
    {
        int32_t  s32;
        uint32_t u32;
        float    f;
        int16_t  s16;
        uint16_t u16;
    }Value;              //!< New value of the variable
    uint32_t VarHandle;  //!< Handle of changed variable
    uint32_t VarIndex;   //!< Index of changed variable
}tCEvtVarChange;

/**
 * Key event
 */
typedef struct tagCEvtKey
{
    uint32_t KeyCode;    //!< Keycode
    uint32_t ASCIICode;  //!< ASCII code (0 if there is no ASCII code for this key)
    uint32_t State;      //!< 1 if key was pressed, 0 if key was released, 2 if a key is repeated
}tCEvtKey;

/**
 * J1939 SP data buffer change event
 */
typedef struct tagCEvtJ1939SPBufChange
{
    uint32_t spID;  //!< ID of the J1939 SP which caused the event
}tCEvtJ1939SPBufChange;

/**
 * Visual object data changed event
 *
 * If the global data of an visual object changes this event will be send
 */
typedef struct tagCEvtVisObjDataChange
{
    uint32_t ObjID;    //!< ID of the object which caused the event
    uint32_t NewSize;  //!< New size of the vis object data
}tCEvtVisObjDataChange;

/**
 * Visual object data changed event
 *
 * If the global data of an visual object changes this event will be send
 */
typedef struct tagCEvtVisuChange
{
    uint32_t mRes;  //!< Currently always 0
}tCEvtVisuChange;

/**
 * Visual object data changed event
 *
 * If the remote access connection is active/ready this event will be send
 */
typedef struct tagCEvtRemAcc
{
    uint32_t mRes;  //!< Currently always 0
}tCEvtRemAcc;

/**
 * Visu key event
 */
typedef struct tagCEvtVisuKey
{
    uint32_t mKeyCode;    //!< Keycode
    uint32_t mASCIICode;  //!< ASCII code (0 if there is no ASCII code for this key)
    uint32_t mState;      //!< 1 if key was pressed, 0 if key was released, 2 if a key is repeated
    int32_t  mLogicFunc;  //!< Logical function in current visu state
}tCEvtVisuKey;

/**
 * Touch event
 */
typedef struct tagCEvtTouch
{
    uint32_t mId;     //!< Which touch point (for multi touch screens)
    uint32_t mState;  //!< CEVT_TOUCH_DOWN/CEVT_TOUCH_UP/CEVT_TOUCH_ON
    int32_t  mX;      //!< Touch coordinate X (in screen coordinates)
    int32_t  mY;      //!< Touch coordinate Y (in screen coordinates)
}tCEvtTouch;

/**
 * Network event
 */
typedef struct tagCEvtNetwork
{
    uint32_t mState;  //!< See CEVT_NETWORK_STATE_*
}tCEvtNetwork;

/**
 * Network event
 */
typedef struct tagCEvtTransFile
{
    uint8_t mState;     //!< See CEVT_FT_STATE_* (Begin, Progress, End, offline_download, offline_upload, ...)
    uint8_t mProgress;  //!< Transfer X% done (in case of "Online" file transfer)
    uint8_t mInstNum;   //!< gsRemoteAccess Instance-Number (used for sending events back to user-C thread)
    char    mName[21];  //!< First 20 byte (+ null termination) of the file beeing transfered in case of remote access (in case of "Online" file transfer)
}tCEvtTransFile;

/**
 * Key is still pressed event
 */
typedef struct tagCEvtKeyRepeat
{
    uint32_t KeyCode;    //!< Keycode
    uint32_t ASCIICode;  //!< ASCII code (0 if there is no ASCII code for this key)
    uint32_t State;      //!< 1 if key is still pressed
}tCEvtKeyRepeat;

/**
 * Menu index release event
 */
typedef struct tagCEvtMenuIndexRelease
{
    uint32_t Index;  //!< Index as given in GDSDesigner
    uint32_t ObjID;  //!< ID of the object which caused the event
}tCEvtMenuIndexRelease;

/**
 * Menu action event
 */
typedef struct tagCEvtMenuAction
{
    uint32_t mObjID;    //!< ID of the object which caused the event
    uint32_t mState;    //!< CEVT_STATE_... (1 if menu object is pressed, 0 if it is released, 2 if it is repeated (repeated for touch only))
    uint32_t mAction;   //!< Configured Action (Obj property)
    uint32_t mFuncIdx;  //!< Configured Function-Index (Obj property)
    uint32_t mRes2;     //!< Currently always 0
    uint32_t mRes1;     //!< Currently always 0
}tCEvtMenuAction;

/**
 * Touch keyboard event
 */
typedef struct tagCEvtTouchKbd
{
    uint32_t mObjID;   //!< ID of the object which caused the event
    int16_t  mPressX;  //!< Press at X (relative to display)
    int16_t  mPressY;  //!< Press at Y (relative to display)
    int16_t  mPosX;    //!< Key position X (relative to display)
    int16_t  mPosY;    //!< Key position Y (relative to display)
    int16_t  mSizeW;   //!< Key width
    int16_t  mSizeH;   //!< Key height
    uint32_t mCode;    //!< Key code
    uint32_t mState;   //!< CEVT_STATE_... (1 if touch keyboard is pressed, 0 if it is released)
}tCEvtTouchKbd;

/**
 * USB memory event
 */
typedef struct tagCEvtUsbMemory
{
    uint32_t mState;   //!< Bitfield telling which USB memory is attached
    uint32_t mRes[5];  //!< Reserved
}tCEvtUsbMemory;

/**
 * Hotplug event
 */
typedef struct tagCEvtHotplug
{
    uint16_t mVendorId;  //!< Vendor id of the device
    uint16_t mDeviceId;  //!< Device id of the device
    uint8_t  mState;     //!< CEVT_STATE_ADD or CEVT_STATE_REMOVED
}tCEvtHotplug;

/**
 * Time Date object changed event
 */
typedef struct tagCEvtTimeDateChange
{
    uint32_t mObjID;    //!< ID of the object which caused the event
    uint8_t  mChanged;  //!< CEVT_CHANGED_DATE, CEVT_CHANGED_TIME
    uint8_t  mYear;
    uint8_t  mMonth;
    uint8_t  mDay;
    uint8_t  mHours;
    uint8_t  mMinutes;
    uint8_t  mSeconds;
    uint8_t  mRes0;     //!< Reserved
    uint32_t mRes[3];   //!< Reserved
}tCEvtTimeDateChange;

/**
 * Resource color changed event
 */
typedef struct tagCEvtRCColorChange
{
    uint16_t mSchemeID;
    uint16_t mNameID;
    uint32_t mOldColor;
    uint32_t mNewColor;
    uint32_t mOffset;   //!< RCCOLOR_OFFSET
    uint32_t mRes[2];   //!< Reserved
}tCEvtRCColorChange;

/**
 * Send-To-VISU-Object event (Function SendToVisuObj(..) was called by user-C)
 */
typedef struct tagCEvtSendToVisuObj
{
    uint32_t mObjID;    //!< ID of the object which caused the event
    uint32_t mCode;     //!< e.g. GS_TO_VISU_SET_ATTR_BLINK (gstovisu.h)
    uint32_t mValue;
    uint32_t mRes[3];   //!< Reserved
}tCEvtSendToVisuObj;

/**
 * Analog input channel mode changed event
 */
typedef struct tagCEvtAnalogInChanged
{
    uint32_t mCh;       //!< channel which analog input mode has changed
    uint32_t mRes[5];   //!< Reserved
}tCEvtAnalogInChanged;

/**
 * A union to have all events in the same memory
 */
typedef union tagCEvtContent
{
    tCEvtMenuIndex          mMenuIndex;           //!< Raised by a menu object
    tCEvtTextChange         mTextChange;          //!< Raised by a edit text object
    tCEvtEditStart          mEditStart;           //!< Raised if an object enters edit mode
    tCEvtEditEnd            mEditEnd;             //!< Raised if an object leaves edit mode
    tCEvtSelected           mSelected;            //!< Raised if an object enters selected mode
    tCEvtUnselected         mUnselected;          //!< Raised if an object leaves selected mode
    tCEvtMaskOn             mMaskOn;              //!< Raised if a mask was switched on
    tCEvtMaskOff            mMaskOff;             //!< Raised if a mask was switched off
    tCEvtInfoContOn         mInfoContOn;          //!< Raised if a info container was switched on
    tCEvtInfoContOff        mInfoContOff;         //!< Raised if a info container was switched off
    tCEvtMsgContOn          mMsgContOn;           //!< Raised if a message container was switched on
    tCEvtMsgContOff         mMsgContOff;          //!< Raised if a message container was switched off
    tCEvtCanError           mCanError;            //!< Raised if an error on a CAN bus occoured
    tCEvtPrjUpdate          mPrjUpdate;           //!< Raised if a project update is ready
    tCEvtVarChange          mVarChange;           //!< Raised if a variable has been changed
    tCEvtKey                mKey;                 //!< Raised if a key is pressed/released/repeated
    tCEvtJ1939SPBufChange   mSPBufChange;         //!< Raised if a J1939 SP data buffer has been changed (received)
    tCEvtVisObjDataChange   mVisObjDataChange;    //!< Raised if a visual object changes its data
    tCEvtVisuChange         mVisuChange;          //!< Raised if displayed mask/container has changed
    tCEvtRemAcc             mRemAcc;              //!< Raised if remote access connection is active/ready
    tCEvtVisuKey            mVisuKey;             //!< Raised for keys processed by visualization
    tCEvtTouch              mTouch;               //!< Raised if an event on the touch screen is detected
    tCEvtNetwork            mNetwork;             //!< Raised if a network caused an event
    tCEvtTransFile          mTransFile;           //!< Raised if a file is beeing transfered to device
    tCEvtKeyRepeat          mKeyRepeat;           //!< Raised if a key is still pressed
    tCEvtMenuIndexRelease   mMenuIndexRelease;    //!< Raised by a menu object with releasing key (after CEVT_MENU_INDEX)
    tCEvtMenuAction         mMenuAction;          //!< Raised if a menu object is pressed/released/repeated via key/touch
    tCEvtTouchKbd           mTouchKbd;            //!< Raised if a obj's touch keyboard is pressed/released
    tCEvtUsbMemory          mUsbMemory;           //!< Raised if something changed with USB memory
    tCEvtHotplug            mHotplug;             //!< Raised if something is plugged in or removed from the device
    tCEvtTimeDateChange     mTimeDateChange;      //!< Raised if time/date object has changed
    tCEvtRCColorChange      mRCColorChange;       //!< Raised if a resource color value has changed
    tCEvtSendToVisuObj      mSendToVisuObj;       //!< Raised if a object has been changed by 'SendToVisuObj' function
    tCEvtAnalogInChanged    mAnalogInChanged;     //!< Raised if a analog input state has changed
}tCEvtContent;

/**
 * The event structure itself
 */
typedef struct tagCEvt
{
    uint32_t Type;         //!< The type which is valid in the Content member.
    uint32_t Source;       //!< Where was the event raised.
    tCEvtContent Content;  //!< All the event types in one union. Type indicates which entry is valid
}tUserCEvt;

//-----------------------------------------------------------------------------
//Variables
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
//Function prototypes
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
//Function implementation
//-----------------------------------------------------------------------------

#endif //USERCEVENTS_H_INCLUDED
//-----------------------------------------------------------------------------
//EOF
//-----------------------------------------------------------------------------

