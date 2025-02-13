/**
 * @file
 *
 * Public interface Graf-Syteco debug library
 *
 * @author Matthias Weisser<br>
 *         Graf-Syteco GmbH & Co. KG
 *
 * @date   created: 16.09 2010
 */

#ifndef GSDEBUG_H_INCLUDED
#define GSDEBUG_H_INCLUDED

//-----------------------------------------------------------------------------
//Includes
//-----------------------------------------------------------------------------
#include <stdint.h>

//-----------------------------------------------------------------------------
//Defines
//-----------------------------------------------------------------------------
#define GS_DBG_STREAM_NONE      0x00000000U
#define GS_DBG_STREAM_WINDOW    (1U<<0)
#define GS_DBG_STREAM_USB_MEM   (1U<<1)
#define GS_DBG_STREAM_TCPIP     (1U<<2)
#define GS_DBG_STREAM_FILE      (1U<<3)
#define GS_DBG_STREAM_CALLBACK  (1U<<4)
#define GS_DBG_STREAM_SERIAL    (1U<<5)
#define GS_DBG_STREAM_CAN       (1U<<6)

//-----------------------------------------------------------------------------
//Datatypes
//-----------------------------------------------------------------------------
typedef uint32_t tGsDebugStream;

/**
 * Callback function type for the callback debug stream
 */
typedef int32_t(*tGsDebugStreamCallback)(const char * msg);

typedef enum eagGsDebugStreamsLineMode
{
    GS_DBG_STREAM_LINE_MODE_DISABLED,       //!< No line mode used. Output is printed as given to gsDebugStreamsPrint
    GS_DBG_STREAM_LINE_MODE_ENABLED,        //!< Line mode enabled. Each call to gsDebugStreamsPrint will be followed by a new line
    GS_DBG_STREAM_LINE_MODE_TIMESTAMP,      //!< Timestamp mode is enabled. Each call to gsDebugStreamsPrint will have a timestamp in front and a new line at the end
}eGsDebugStreamsLineMode;

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
 * Adds a TCP server to the possible debug streams. Call this before gsDebugInitStreams
 *
 * @return 0 if a TCP server was added to the possible debug streams
 */
int32_t gsDebugStreamsAddTCPIP(uint16_t port);

/**
 * Adds a debug stream which writes to an arbitrary file. Call this before
 * gsDebugInitStreams
 *
 * @param fileName Name of the file where the debug stream writes to
 *
 * @return 0 if the file can be used as output to a debug stream
 */
int32_t gsDebugStreamsAddFile(const char * fileName);

/**
 * Adds a debug stream which calls a callback function on any debug output line.
 * Call this before gsDebugInitStreams
 *
 * @param cb The function to be called
 *
 * @return Always 0
 */
int32_t gsDebugStreamsAddCallback(tGsDebugStreamCallback cb);

/**
 * Adds a debug stream which uses a serial interface as output. Call this before
 * gsDebugInitStreams
 *
 * @param intf The serial interface to be used
 *
 * @return Always 0
 */
int32_t gsDebugStreamsAddSerial(uint32_t intf);

/**
 * Adds a debug stream which uses CAN as output. Call this before gsDebugInitStreams
 *
 * @param intf Which CAN interface should be used for debug output
 * @param id   The identifier which should be used to send the debug output
 *
 * @return Always 0
 */
int32_t gsDebugStreamsAddCAN(uint32_t intf, uint32_t id);

/**
 * Inits the debug streams you want to use. Call gsDebugStreamsAdd* functions
 * before if needed. If other ones should be used you have to call gsDebugStreamsDeInit
 * before calling gsDebugStreamsInit to initialize the new debug streams added.
 *
 * @param usedStreams Logical or of all possible streams
 *
 * @return Bitwise or of all successfully initialized streams.
 */
tGsDebugStream gsDebugStreamsInit(tGsDebugStream usedStreams);

/**
 * Sets the line mode to be used when printing to debug streams
 *
 * @param mode The mode to be used
 */
void gsDebugStreamsSetLineMode(eGsDebugStreamsLineMode mode);

/**
 * Closes the debug streams which where opened previously with gsDebugInitStreams
 */
void gsDebugStreamsDeInit(void);

/**
 * printf like function for printing to debug streams
 *
 * @return 0 if the initialization of all requested streams went OK.
 */
void gsDebugStreamsPrint(const char * fmt, ...) __attribute__((format (printf, 1, 2)));

/**
 * Initializes a high resolution timer which can be used to measure times smaller
 * then one second for debug and diagnostic purposes.
 *
 * @return 0 if the timer was successfully initialized. != 0 otherwise
 */
int32_t gsDebugHighResTimerInit(void);

/**
 * Returns the number of available bits for the high res timer
 *
 * @return The number of bits valid for the high res timer
 */
int32_t gsDebugHighResTimerGetResolution(void);

/**
 * Deinits the high resolution timer.
 */
void gsDebugHighResTimerDeInit(void);

/**
 * Returns the current value of the high resolution timer. The value will reflect
 * the number of nano seconds since gsDebugHighResTimerInit was called. Resolution
 * is system dependend but always better then one �s. As we only have a 32 bit
 * value available the timer will wrap at a rate of about 4.2 seconds.
 *
 * @return The current value of the high res timer
 */
uint32_t gsDebugHighResTimerGet(void);

/**
 * Returns the current value of the high resolution timer as 64 bit value. On systems
 * that support it this will be a 64 bit value scaled in ns which wraps in about 584
 * years. If the system doesn't support 64 bit wide timestamps this function will
 * return the same 32 bit timer value as gsDebugHighResTimerGet. The return value
 * of gsDebugHighResTimerGetResolution can be used to check the number of bits available
 * for the timestamp.
 *
 * @return The current value of the high res timer
 */
uint64_t gsDebugHighResTimerGet64(void);

#ifdef __cplusplus
}
#endif //__cplusplus
//-----------------------------------------------------------------------------
//Function implementation
//-----------------------------------------------------------------------------

#endif //GSDEBUG_H_INCLUDED
//-----------------------------------------------------------------------------
//EOF
//-----------------------------------------------------------------------------

