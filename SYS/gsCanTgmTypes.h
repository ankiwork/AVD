/**
 *
 * Global definition of CAN telegram types
 *
 * @author genHdrsFromCanTgmTypes.pl
 *         Graf-Syteco GmbH & Co. KG
 *
 */

#ifndef GSCANTGMTYPES_H_INCLUDED
#define GSCANTGMTYPES_H_INCLUDED

//-----------------------------------------------------------------------------
//Includes
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
//Defines
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
//Datatypes
//-----------------------------------------------------------------------------

/**
 * Global CAN telegram types supported (partially) by all devices (in u8[0])
 */
enum eGsCanTgmTypes
{
    CAN_TGM_REQUEST_VALUE             = 0x01, //!< Request value
    CAN_TGM_SET_VALUE                 = 0x02, //!< Set value
    CAN_TGM_REPORT_VARIABLE_VALUE     = 0x03, //!< Report variable value
    CAN_TGM_CONTAINER_ON              = 0x04, //!< Container on
    CAN_TGM_CONTAINER_OFF             = 0x05, //!< Container off
    CAN_TGM_MASK_ON                   = 0x06, //!< Mask on
    CAN_TGM_MASK_OFF                  = 0x07, //!< Mask off
    CAN_TGM_PRIORITY_MASK_ON          = 0x08, //!< Priority Mask on
    CAN_TGM_REQUEST_STATUS            = 0x09, //!< Request status
    CAN_TGM_REPORT_STATUS             = 0x0A, //!< Report status
    CAN_TGM_ENABLE_STATUS_REPORT      = 0x0B, //!< Enable status report
    CAN_TGM_DISABLE_STATUS_REPORT     = 0x0C, //!< Disable status report
    CAN_TGM_REQUEST_MEMORY_WRITE      = 0x0D, //!< Report memory write
    CAN_TGM_DISABLE_WRITE             = 0x0E, //!< Disable write
    CAN_TGM_WRITE_MEMORY              = 0x0F, //!< Write memory
    CAN_TGM_REQUEST_READ_MEMORY       = 0x10, //!< Request read memory
    CAN_TGM_READ_MEMORY               = 0x11, //!< Read memory
    CAN_TGM_RESET                     = 0x12, //!< Reset
    CAN_TGM_ACKNOWLEDGE               = 0x13, //!< Acknowledge
    CAN_TGM_ERROR                     = 0x14, //!< Error
    CAN_TGM_PARAM                     = 0x15, //!< Parameter
    CAN_TGM_SET_LED                   = 0x16, //!< Set LED
    CAN_TGM_KEY_DATA                  = 0x17, //!< Key data
    CAN_TGM_VERSION_REQUEST           = 0x18, //!< Version request
    CAN_TGM_VERSION_DATA              = 0x19, //!< Version data
    CAN_TGM_REQUEST_CLOCK             = 0x1A, //!< Request clock
    CAN_TGM_REQUEST_RUNTIME           = 0x1B, //!< Request runtime
    CAN_TGM_REQUEST_INTERN_VARIABLE   = 0x1C, //!< Request intern variable
    CAN_TGM_PROGRAM_CLOCK             = 0x1D, //!< Program clock
    CAN_TGM_REPORT_CLOCK              = 0x1E, //!< Report clock
    CAN_TGM_REPORT_RUNTIME            = 0x1F, //!< Report runtime
    CAN_TGM_ASCII_TELEGRAM            = 0x20, //!< ASCII telegram
    CAN_TGM_REQUEST_PROTOKOLL         = 0x21, //!< Request protokoll
    CAN_TGM_REQUEST_STATISTIK         = 0x22, //!< Request statistik
    CAN_TGM_REQUEST_GCM_MODUL_STATUS  = 0x23, //!< Request GCM modul status
    CAN_TGM_SEND_GCM_MODUL_STATUS     = 0x24, //!< Send GCM modul status
    CAN_TGM_SEND_MENU_INDEX           = 0x25, //!< Send menu index
    CAN_TGM_SEND_STATUS_OUTPUT        = 0x26, //!< Send status output
    CAN_TGM_REQUEST_CURSOR_POSITION   = 0x27, //!< Request cursor position
    CAN_TGM_SET_CURSOR_POSITION       = 0x28, //!< Set cursor position
    CAN_TGM_EXECUTE_MENUE             = 0x29, //!< Execute menue
    CAN_TGM_REPORT_CURSOR_POSITION    = 0x2A, //!< Report cursor position
    CAN_TGM_MENU_MASK_ON              = 0x2B, //!< Menu mask on
    CAN_TGM_CAN_INIT                  = 0x2C, //!< CAN init
    CAN_TGM_KEY_CODE                  = 0x2D, //!< Key code
    CAN_TGM_DRAW                      = 0x2E, //!< Draw
    CAN_TGM_INFOCONTAINER_ON          = 0x2F, //!< Infocontainer on
    CAN_TGM_INFOCONTAINER_OFF         = 0x30, //!< Infocontainer off
    CAN_TGM_VIDEO_OPTIONS             = 0x31, //!< Video options
    CAN_TGM_REPORT_MASK_CONTAINER     = 0x32, //!< Report mask container
    CAN_TGM_ANALOG_IN_ERROR           = 0x34, //!< Analog in error
    CAN_TGM_QUBUS                     = 0xD0, //!< QuBus
};

/**
 * Subtypes for CAN_TGM_REQUEST_STATUS (in u8[1])
 */
enum eGsCanTgmReqStatus
{
    CAN_TGM_REQ_STATUS_DEVICE         = 0x00, //!< Device replies with REPORT_STATUS
    CAN_TGM_REQ_STATUS_KEY_01_TO_32   = 0x01,
    CAN_TGM_REQ_STATUS_KEY_33_TO_64   = 0x02,
    CAN_TGM_REQ_STATUS_LED_01_TO_32   = 0x03,
    CAN_TGM_REQ_STATUS_LED_33_TO_64   = 0x04,
    CAN_TGM_REQ_STATUS_MSG_IO         = 0x05,
    CAN_TGM_REQ_STATUS_CUR_MASK       = 0x06, //!< Device replies with REPORT_MASK_CONTAINER
    CAN_TGM_REQ_STATUS_CUR_MSGCONT    = 0x07, //!< Device replies with REPORT_MASK_CONTAINER
    CAN_TGM_REQ_STATUS_CUR_INFOCONT   = 0x08, //!< Device replies with REPORT_MASK_CONTAINER
    CAN_TGM_REQ_STATUS_LED_65_TO_96   = 0x09,
    CAN_TGM_REQ_STATUS_LED_97_TO_128  = 0x0A,
    CAN_TGM_REQ_STATUS_LED_HARDWARE   = 0x0F, //!< Request info about led hardware status
    CAN_TGM_REQ_STATUS_HOUR_METER     = 0x10, //!< Request the hour meter
    CAN_TGM_REQ_STATUS_HARDWARE       = 0x80, //!< Device replies with REPORT_STATUS
    CAN_TGM_REQ_STATUS_OEM            = 0xEF, //!< Device replies with REPORT_STATUS
};

/**
 * Subtypes for CAN_TGM_REQ_STATUS_OEM (in u8[2])
 */
enum eGsCanTgmDebounceTime
{
    CAN_TGM_REQ_STATUS_OEM_DEBOUNCE  = 0x00, //!< get key debounce time (Wirtgen)
};

/**
 * Subtypes for CAN_TGM_REPORT_STATUS (in u8[1])
 */
enum eGsCanTgmRepStatus
{
    CAN_TGM_REP_STATUS_LED_HARDWARE  = 0x0F, //!< Report info about led hardware status
    CAN_TGM_REP_STATUS_HOUR_METER    = 0x10, //!< Report the hour meter
    CAN_TGM_REP_STATUS_HARDWARE      = 0x80, //!< Info about hardware status
    CAN_TGM_REP_STATUS_OEM           = 0x10, //!< report OEM specific parameter (Wirtgen)
};

/**
 * Subtypes for CAN_TGM_REP_STATUS_OEM (in u8[2])
 */
enum eGsCanTgmRepStatusOem
{
    CAN_TGM_REP_STATUS_OEM_DEBOUNCE_TIME  = 0x00, //!< get key debounce time (Wirtgen)
};

/**
 * Subtypes for CAN_TGM_PARAM (in u8[1])
 */
enum eGsCanTgmParam
{
    CAN_TGM_PARAM_BUZZER         = 0x0F, //!< Set buzzer
    CAN_TGM_PARAM_SETTINGS       = 0x10, //!< Change settings
    CAN_TGM_PARAM_USER_DATA      = 0x12, //!< Set user data (MCM)
    CAN_TGM_PARAM_DEVICE_STRING  = 0x13, //!< Set user device string (MCM)
    CAN_TGM_PARAM_BUZZER_FREQ    = 0x1F, //!< Set buzzer freq and duty
    CAN_TGM_PARAM_COUNTER        = 0x20, //!< counter inputs
    CAN_TGM_PARAM_PWM            = 0x21, //!< PWM outputs
    CAN_TGM_PARAM_DELAYCTRL      = 0x22, //!< extended debounce function
    CAN_TGM_PARAM_BUZZER_EXT     = 0x23, //!< Set buzzer extended
};

/**
 * Subtypes for CAN_TGM_PARAM_SETTINGS (in u8[2])
 */
enum eGsCanTgmParamSettings
{
    CAN_TGM_PARAM_SETTINGS_TXID         = 0x01, //!< CAN TxID
    CAN_TGM_PARAM_SETTINGS_RXID         = 0x02, //!< CAN RxID
    CAN_TGM_PARAM_SETTINGS_BAUDRATE     = 0x03, //!< CAN baudrate
    CAN_TGM_PARAM_SETTINGS_HANDLE       = 0x10, //!< Handles
    CAN_TGM_PARAM_SETTINGS_DIGIN        = 0x11, //!< Digital inputs
    CAN_TGM_PARAM_SETTINGS_ANAIN        = 0x13, //!< Analog inputs
    CAN_TGM_PARAM_SETTINGS_STOPSEND     = 0x15, //!< stop automated sending
    CAN_TGM_PARAM_SETTINGS_TEST_MODE    = 0xE7, //!< Switches the device into test mode
    CAN_TGM_PARAM_SETTINGS_OEM_SETTING  = 0xEF, //!< Special case for OEM devices
    CAN_TGM_PARAM_SETTINGS_SYSTEM       = 0xFF, //!< Special system command
};

/**
 * Subtypes for CAN_TGM_PARAM_SETTINGS_HANDLE (in u8[3])
 */
enum eGsCanTgmParamSettingsHandle
{
    CAN_TGM_PARAM_SETTINGS_HANDLE_DIGIN     = 0x00, //!< Base handle for digital inputs
    CAN_TGM_PARAM_SETTINGS_HANDLE_DIGOUT    = 0x01, //!< Base handle for digital outputs
    CAN_TGM_PARAM_SETTINGS_HANDLE_ANAIN     = 0x02, //!< Base handle for analog inputs
    CAN_TGM_PARAM_SETTINGS_HANDLE_ANAOUT    = 0x03, //!< Base handle for analog outputs
    CAN_TGM_PARAM_SETTINGS_HANDLE_LIFETIME  = 0x04, //!< Special case life timer
    CAN_TGM_PARAM_SETTINGS_HANDLE_COUNTER   = 0x06, //!< Base handle for counter
};

/**
 * Subtypes for CAN_TGM_PARAM_SETTINGS_DIGIN (in u8[3])
 */
enum eGsCanTgmParamSettingsDigIn
{
    CAN_TGM_PARAM_SETTINGS_DIGIN_TIMEEVENT       = 0x00, //!< Setting the timed/event sending of digital inputs
    CAN_TGM_PARAM_SETTINGS_DIGIN_DEBOUNCE_0_31   = 0x01, //!< Debounce of inputs 0 to 31
    CAN_TGM_PARAM_SETTINGS_DIGIN_DEBOUNCE_32_63  = 0x02, //!< Debounce of inputs 32 to 63
    CAN_TGM_PARAM_SETTINGS_DIGIN_DEBOUNCE_64_95  = 0x03, //!< Debounce of inputs 64 to 95
};

/**
 * Subtypes for CAN_TGM_PARAM_SETTINGS_ANAIN (in u8[3])
 */
enum eGsCanTgmParamSettingsAnaIn
{
    CAN_TGM_PARAM_SETTINGS_ANAIN_CYCLETIME       = 0x00, //!< Setting the cyclic sending time for analog inputs
    CAN_TGM_PARAM_SETTINGS_ANAIN_CYCLEEVENTBITS  = 0x01, //!< Bits for cyclic/event based sending
    CAN_TGM_PARAM_SETTINGS_ANAIN_SENDDELTA       = 0x02, //!< Setting the delta when an analog input will be send
    CAN_TGM_PARAM_SETTINGS_ANAIN_TYPEAVGBITS     = 0x03, //!< Bits for type and averaging
    CAN_TGM_PARAM_SETTINGS_ANAIN_MODE            = 0x04, //!< Setting the analog input mode
};

/**
 * Subtypes for CAN_TGM_PARAM_SETTINGS_OEM_SETTING (in u8[3])
 */
enum eGsCanTgmParamSettingsOem
{
    CAN_TGM_PARAM_SETTINGS_OEM_SETTING_ID        = 0x00, //!< change of the ID (Wirtgen)
    CAN_TGM_PARAM_SETTINGS_OEM_SETTING_DEBOUNCE  = 0x01, //!< set key debounce time (Wirtgen)
};

/**
 * Subtypes for CAN_TGM_PARAM_COUNTER (in u8[2])
 */
enum eGsCanTgmParamCounter
{
    CAN_TGM_PARAM_COUNTER_DIGITS        = 0x17, //!< Nach Handbuch: 'Senden bei Änderung der Zählerwerte'; Nach altem Code: 'send CounterValue_Difference'
    CAN_TGM_PARAM_COUNTER_CYCLETIME     = 0x18,
    CAN_TGM_PARAM_COUNTER_TA            = 0x19,
    CAN_TGM_PARAM_COUNTER_20            = 0x20, //!< Nach altem Code: 'send counter settings'
    CAN_TGM_PARAM_COUNTER_ZOUTTIME      = 0x22,
    CAN_TGM_PARAM_COUNTER_PERIODTIME    = 0x24,
    CAN_TGM_PARAM_COUNTER_FREQSENDMODE  = 0x26,
    CAN_TGM_PARAM_COUNTER_FREQ_TIMEOUT  = 0x32,
};

/**
 * Subtypes for CAN_TGM_PARAM_PWM (in u8[2])
 */
enum eGsCanTgmParamPwm
{
    CAN_TGM_PARAM_PWM_FREQANDDUTY  = 0x00, //!< Frequency and duty in one telegram
    CAN_TGM_PARAM_PWM_DUTY         = 0x01, //!< Duty only
    CAN_TGM_PARAM_PWM_GETPWM       = 0x02, //!< todo
    CAN_TGM_PARAM_PWM_PWMUP        = 0x03, //!< todo
    CAN_TGM_PARAM_PWM_PWMDOWN      = 0x04, //!< todo
};

/**
 * Subtypes for CAN_TGM_PARAM_DELAYCTRL (in u8[2])
 */
enum eGsCanTgmParamDelayControl
{
    CAN_TGM_PARAM_DELAYCTRL_SETCONTROLMASK     = 0x00, //!< set DelayControlMask
    CAN_TGM_PARAM_DELAYCTRL_GETCONTROLMASK     = 0x01, //!< get DelayControlMask
    CAN_TGM_PARAM_DELAYCTRL_SETCONTROLCOUNTER  = 0x02, //!< set DelayControlCounter
    CAN_TGM_PARAM_DELAYCTRL_GETCONTROLCOUNTER  = 0x03, //!< get DelayControlCounter
};

/**
 * Subtypes for CAN_TGM_SET_LED (in u8[1])
 */
enum eGsCanTgmLed
{
    CAN_TGM_SET_LED_CLEAR_ALL         = 0x00, //!< All LEDs will be switched off
    CAN_TGM_SET_LED_MASK_AND          = 0x01, //!< LEDs will be AND-masked with values
    CAN_TGM_SET_LED_MASK_OR           = 0x02, //!< LEDs will be OR-masked with values
    CAN_TGM_SET_LED_MASK_SET          = 0x03, //!< LEDs will be SET to values
    CAN_TGM_SET_LED_SET               = 0x04, //!< Sets a single LED
    CAN_TGM_SET_LED_CLEAR             = 0x05, //!< Clears a single LED
    CAN_TGM_SET_LED_BRIGHTNESS        = 0x06, //!< Sets the brightness of a group of LEDs
    CAN_TGM_SET_LED_MASK_XOR          = 0x07, //!< LEDs will be XOR-masked with values
    CAN_TGM_SET_LED_RGB_COLOR         = 0x08, //!< Set a Color to mask LEDs with CAN_TGM_SET_LED_RGB_MASK_COLOR
    CAN_TGM_SET_LED_MASK_RGB_COLOR    = 0x09, //!< Mask RGB-LEDs with the color set by CAN_TGM_SET_LED_RGB_COLOR
    CAN_TGM_SET_LED_RGB_SINGLE        = 0x0A, //!< Set color of a single LED
    CAN_TGM_SET_LED_MASK_RGB_LOW_RES  = 0x0B, //!< Mask RGB-LEDs with a low res color
};

/**
 * Subtypes for CAN_TGM_KEY_DATA (in u8[1])
 */
enum eGsCanTgmKeyData
{
    CAN_TGM_KEY_DATA_SINGLE         = 0x00, //!< Status of a single key
    CAN_TGM_KEY_DATA_KEY_1_32       = 0x01, //!< Status of keys 1 - 32
    CAN_TGM_KEY_DATA_KEY_33_64      = 0x02, //!< Status of keys 33 - 64
    CAN_TGM_KEY_DATA_LED_01_TO_32   = 0x03, //!< Status of leds 1 - 32
    CAN_TGM_KEY_DATA_LED_33_TO_64   = 0x04, //!< Status of leds 33 - 64
    CAN_TGM_KEY_DATA_LED_65_TO_96   = 0x09, //!< Status of leds 65 - 96
    CAN_TGM_KEY_DATA_LED_97_TO_128  = 0x0A, //!< Status of leds 97 - 128
};

/**
 * Subtypes for CAN_TGM_VERSION_REQUEST (in u8[1])
 */
enum eGsCanTgmVersionRequest
{
    CAN_TGM_VERSION_REQUEST_FW           = 0x00, //!< Requesting the BIOS version
    CAN_TGM_VERSION_REQUEST_DEVICETYPE   = 0x01, //!< Requesting the TOS version
    CAN_TGM_VERSION_REQUEST_PARAM        = 0x02, //!< Requesting parameters
    CAN_TGM_VERSION_REQUEST_FW_BIOS      = 0x00, //!< Requesting the BIOS version
    CAN_TGM_VERSION_REQUEST_FW_OS        = 0x01, //!< Requesting the TOS version
    CAN_TGM_VERSION_REQUEST_APPLICATION  = 0x02, //!< Requesting the user
};

/**
 * Subtypes for CAN_TGM_VERSION_REQUEST_PARAM (in u8[2])
 */
enum eGsCanTgmVersionRequestParam
{
    CAN_TGM_VERSION_REQUEST_PARAM_TXID      = 0x01, //!< Requesting CAN parameters
    CAN_TGM_VERSION_REQUEST_PARAM_RXID      = 0x02, //!< Requesting CAN RxID
    CAN_TGM_VERSION_REQUEST_PARAM_BAUDRATE  = 0x03, //!< Requesting CAN baudrate
    CAN_TGM_VERSION_REQUEST_PARAM_MODE      = 0x04, //!< Requesting CAN mode
    CAN_TGM_VERSION_REQUEST_PARAM_HANDLE    = 0x10, //!< Requesting base handles
    CAN_TGM_VERSION_REQUEST_PARAM_DIGIN     = 0x11, //!< Requesting digital input parameters
    CAN_TGM_VERSION_REQUEST_PARAM_DIGOUT    = 0x12, //!< Requesting digital out state
    CAN_TGM_VERSION_REQUEST_PARAM_ANAIN     = 0x13, //!< Requesting analog input parameters
};

/**
 * Subtypes for CAN_TGM_VERSION_REQUEST_PARAM_HANDLE (in u8[3])
 */
enum eGsCanTgmVersionRequestParamHandle
{
    CAN_TGM_VERSION_REQUEST_PARAM_HANDLE_DIGIN     = 0x00, //!< Requesting base handle for digital inputs
    CAN_TGM_VERSION_REQUEST_PARAM_HANDLE_DIGOUT    = 0x01, //!< Requesting base handle for digital outputs
    CAN_TGM_VERSION_REQUEST_PARAM_HANDLE_ANAIN     = 0x02, //!< Requesting base handle for analog inputs
    CAN_TGM_VERSION_REQUEST_PARAM_HANDLE_LIFETIME  = 0x04, //!< Requesting base handle for lifetime
    CAN_TGM_VERSION_REQUEST_PARAM_HANDLE_COUNTER   = 0x06, //!< Requesting base handle for counters
};

/**
 * Subtypes for CAN_TGM_VERSION_REQUEST_PARAM_DIGIN (in u8[3])
 */
enum eGsCanTgmVersionRequestParamDigIn
{
    CAN_TGM_VERSION_REQUEST_PARAM_DIGIN_TIMEEVENT       = 0x00, //!< Requesting the timed/event sending of digital inputs
    CAN_TGM_VERSION_REQUEST_PARAM_DIGIN_DEBOUNCE_0_31   = 0x01, //!< Requesting if the outputs 0-31 are active
    CAN_TGM_VERSION_REQUEST_PARAM_DIGIN_DEBOUNCE_31_63  = 0x02, //!< Requesting if the outputs 32-63 are active
    CAN_TGM_VERSION_REQUEST_PARAM_DIGIN_DEBOUNCE_64_95  = 0x03, //!< Requesting if the outputs 64-95 are active
};

/**
 * Subtypes for CAN_TGM_VERSION_REQUEST_PARAM_DIGOUT (in u8[3])
 */
enum eGsCanTgmVersionRequestParamDigOut
{
    CAN_TGM_VERSION_REQUEST_PARAM_DIGOUT_POWERON  = 0x00, //!< Requesting if the outputs 0-31 are active
    CAN_TGM_VERSION_REQUEST_PARAM_DIGOUT_IODIR    = 0x01, //!< Requesting the digital IO direction
};

/**
 * Subtypes for CAN_TGM_VERSION_REQUEST_PARAM_ANAIN (in u8[3])
 */
enum eGsCanTgmVersionRequestParamAnaIn
{
    CAN_TGM_VERSION_REQUEST_PARAM_ANAIN_CYCLETIME       = 0x00, //!< Requesting the time value for cyclic sending of analog inputs
    CAN_TGM_VERSION_REQUEST_PARAM_ANAIN_CYCLEEVENTBITS  = 0x01, //!< Requesting the event/time sending of analog inputs
    CAN_TGM_VERSION_REQUEST_PARAM_ANAIN_SENDDELTA       = 0x02, //!< Requesting the delta values of analog inputs
    CAN_TGM_VERSION_REQUEST_PARAM_ANAIN_TYPEAVGBITS     = 0x03, //!< Requesting the type and average values of analog inputs
};

/**
 * Subtypes for CAN_TGM_SET_CURSOR_POSITION (in u8[1])
 */
enum eGsCanTgmSetCursorPosition
{
    CAN_TGM_SET_CURSOR_POSITION_XY    = 0x01,
    CAN_TGM_SET_CURSOR_POSITION_VAR   = 0x02,
    CAN_TGM_SET_CURSOR_POSITION_MENU  = 0x03,
};

/**
 * Subtypes for CAN_TGM_REPORT_CURSOR_POSITION (in u8[1])
 */
enum eGsCanTgmReportCursorPosition
{
    CAN_TGM_REPORT_CURSOR_POSITION_XY    = 0x01,
    CAN_TGM_REPORT_CURSOR_POSITION_VAR   = 0x02,
    CAN_TGM_REPORT_CURSOR_POSITION_MENU  = 0x03,
};

/**
 * Subtypes for CAN_TGM_VIDEO_OPTIONS (in u8[1])
 */
enum eGsCanTgmVideoOptions
{
    CAN_TGM_VIDEO_OPTIONS_ENABLE_CHANNEL        = 0x0, //!< Enable Video Channel
    CAN_TGM_VIDEO_OPTIONS_DISABLE_CHANNEL       = 0x1, //!< Disable Video Channel
    CAN_TGM_VIDEO_OPTIONS_SET_DEST_VIEWPORT_XY  = 0x2,
    CAN_TGM_VIDEO_OPTIONS_SET_DEST_VIEWPORT_WH  = 0x3,
    CAN_TGM_VIDEO_OPTIONS_SET_SRC_VIEWPORT_XY   = 0x4,
    CAN_TGM_VIDEO_OPTIONS_SET_SRC_VIEWPORT_WH   = 0x5,
};

/**
 * Subtypes for CAN_TGM_REPORT_MASK_CONTAINER (in u8[1])
 */
enum eGsCanTgmRepMaskContainer
{
    CAN_TGM_REP_MASK_CONTAINER_MASK      = 0x00, //!< Info about current mask
    CAN_TGM_REP_MASK_CONTAINER_MSGCONT   = 0x01, //!< Info about current message container
    CAN_TGM_REP_MASK_CONTAINER_INFOCONT  = 0x02, //!< Info about current info container
};


//-----------------------------------------------------------------------------
//Variables
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
//Function prototypes
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
//Function implementation
//-----------------------------------------------------------------------------

#endif //GSCANTGMTYPES_H_INCLUDED
//-----------------------------------------------------------------------------
//EOF
//-----------------------------------------------------------------------------
