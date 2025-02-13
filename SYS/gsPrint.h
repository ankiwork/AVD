/**
 * @file
 *
 * Public interface to ESC/P printer library.
 *
 * @author Matthias Weisser<br>
 *         Graf-Syteco GmbH & Co. KG
 *
 * @date   created: 27.10 2009
 */

#ifndef GSPRINT_H_INCLUDED
#define GSPRINT_H_INCLUDED
 
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

/**
 * Interface for a print job
 */
typedef enum eGsPrintInterface
{
    PI_UNDEFINED = 0,
    PI_SERIAL_0,
    PI_SERIAL_1,
    PI_SERIAL_2,
    PI_SERIAL_3,
    PI_SERIAL_4,
    PI_SERIAL_5,
}eGsPrintInterface;

/**
 * Protocol for a print job (Protocol used by the printer)
 */
typedef enum eGsPrintProtocoll
{
    PP_UNDEFINED = 0,
    PP_ESCP9,           //!< ESC/P for 9 pin printers
    PP_ESCP24,          //!< ESC/P for 24 pin printers (not implemented)
    PP_ESCP2,           //!< ESC/P2 (not implemented)
    PP_STAR,            //!< Starmode emulation
    PP_TEXTFILE,        //!< Prints to a text file
    PP_PRIVATE,         //!< Print protocol used when a separate init function is used
}eGsPrintProtocoll;

typedef void tGsPrintJob;   //!< Opaque print job

/**
 * Callback function for dynamic data in print forms
 *
 * @param query     The query string as given in the print template
 * @param buf       Buffer where the callback fills in its result
 *                  which is later on printed.
 * @param bufLen    Length of buf
 * @param userDate  User data as passed to PrintJobSetQueryCallback
 *
 * @return With the return value of a query callback you can enable or 
 *         disable further output to the printer. If you return a value 
 *         < 0 output to the printer will be stopped. If you return 1
 *         output will be started again. If you return 0 nothing will 
 *         change.
 */
typedef int32_t (*tGsPrintQueryCallback)(const char * query, char * buf, int32_t bufLen, void * userData);

/**
 * Callback function for graphic printing. This callback is called when a
 * graphic should be printed and has to return the value of the given
 * pixel. For black/white printing all values which are not white (0xFFFFFF)
 * will be printed black. 
 *
 * @param name      The graphic name as given in the print template
 * @param x         X coordinate of the requested pixel
 * @param y         Y coordinate of the requested pixel
 * @param color     Color of the requested pixel is passed back here
 * @param userDate  User data as passed to PrintJobSetGraphicCallback
 *
 * @return 0 needs to be returned if x/y where in range and a valid
 *         color was returned via the color parameter. Otherwise -1
 *         has to be returned.
 */
typedef int32_t(*tGsPrintGraphicCallback)(const char * name, uint32_t x, uint32_t y, uint32_t * color, void * userData);

/**
 * Callback function for print progress
 *
 * @param progress Printing progress in percent
 * @param userDate  User data as passed to PrintJobSetProgressCallback
 */
typedef void (*tGsPrintProgressCallback)(int32_t progress, void * userData);

/**
 * Callback function for print start (useful if printing in background)
 *
 * @param userDate  User data as passed to PrintJobSetStartCallback
 *
 * @return If 0 is returned the printing will be started. If != 0 printing will
 *         not happen and the end callback will be called immediately
 */
typedef int32_t (*tGsPrintStartCallback)(void * userData);

/**
 * Callback function for print end (useful if printing in background)
 *
 * @param progress Printing progress in percent
 * @param userDate  User data as passed to PrintJobSetEndCallback
 */
typedef void (*tGsPrintEndCallback)(void * userData);

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
 * Creates a new print job. The job can be used for multiple prints
 *
 * @param prot The protocol you want to use
 * 
 * @return A pointer to a print job or NULL if the print job could not
 *         be created.
 */
tGsPrintJob * PrintCreateJob(eGsPrintProtocoll prot);

/**
 * Inits the given print job handle to work with PDF file creation printers
 *
 * @param job A print job created by PrintCreateJob
 *
 * @return 0 on success. < 0 otherwise
 */
int32_t PrintPDFInit(tGsPrintJob * job);

/**
 * Destroys a print job. If the print job was started in background
 * do not call this function for that job. It will be automatically
 * destroyed when the job is done.
 *
 * @param job A print job created by PrintCreateJob
 */
void PrintDestroyJob(tGsPrintJob * job);

/**
 * Sets the interface for a print job
 *
 * @param job  The print job
 * @param intf The interface you wan't to print on (any of PI_*)
 *
 * @return 0 if the interface was set successful
 */
int32_t PrintJobSetInterface(tGsPrintJob * job, eGsPrintInterface intf);

/**
 * Sets the output name for a print job. This may be needed if the output
 * is a file. For standard printer output this function is a nop.
 *
 * @param job  The print job
 * @param name The output name
 *
 * @return 0 if the interface was set successful
 */
int32_t PrintJobSetOutputName(tGsPrintJob * job, const char * name);

/**
 * Checks if the printer for the job is available
 *
 * @param job  The print job
 *
 * @return 0 if there is a printer available at the configured interface
 */
int32_t PrintJobCheckPrinter(tGsPrintJob * job);

/**
 * Registers a query callback. The printer template can contain dynamic
 * fields. These dynamic fields can be filled by the user when he registers
 * a query callback. In this query callback the string from the template
 * will be passed in and the callback has to fill a buffer with the 
 * dynamic data.
 *
 * @param job       The printer job
 * @param cb        The callback function
 * @param userData  Pointer which will be passed back to the callback
 */
void PrintJobSetQueryCallback(tGsPrintJob * job, tGsPrintQueryCallback cb, void * userData);

/**
 * Registers a graphic callback. See description of tGsPrintGraphicCallback
 * for a description of the usage of this callback
 *
 * @param job       The printer job
 * @param cb        The callback function
 * @param userData  Pointer which will be passed back to the callback
 */
void PrintJobSetGraphicCallback(tGsPrintJob * job, tGsPrintGraphicCallback cb, void * userData);

/**
 * Registers a progress callback. While printing the registered function
 * will be called with the current progress. This can be used to show a
 * progress bar.
 *
 * @param job       The printer job
 * @param cb        The callback function
 * @param userData  Pointer which will be passed back to the callback
 */
void PrintJobSetProgressCallback(tGsPrintJob * job, tGsPrintProgressCallback cb, void * userData);

/**
 * Registers a start callback. This function will be called before the
 * printing is started. This is useful when using background printing
 * as this function will be called from background printing thread and
 * can be used to allocate resources needed to do the actual printing.
 *
 * @param job       The printer job
 * @param cb        The callback function
 * @param userData  Pointer which will be passed back to the callback
 */
void PrintJobSetStartCallback(tGsPrintJob * job, tGsPrintStartCallback cb, void * userData);

/**
 * Registers a end callback. This function will be after all data has 
 * been passed to the printer. This is useful when using background printing
 * as this function will be called from background printing thread
 * and can be used to close resources not longer needed for printing.
 *
 * @param job       The printer job
 * @param cb        The callback function
 * @param userData  Pointer which will be passed back to the callback
 */
void PrintJobSetEndCallback(tGsPrintJob * job, tGsPrintEndCallback cb, void * userData);

/**
 * This is the actual function which does the work. This function doesn't 
 * return until all commands are sent to the printer.
 *
 * @param job         The printer job
 * @param file        The print template file
 * @param noPrnInit   If != 0 the printer won't be initialized when the print job starts
 *
 * @return 0 if the print job was done. < 0 if an error occoured
 */
int32_t PrintJobPrint(tGsPrintJob * job, const char * file, int32_t noPrnInit);

/**
 * If the print job should be started in the background use this function.
 * Currently it is only possible to have one print job running in the background.
 * If another print job is started while one is running this function will fail.
 * If a print job is started in the background it will be automatically destroyed
 * when the job is done. So do not call PrintDestroyJob for the job passed to this
 * function.
 *
 * @param job   The printer job
 * @param file  The print template file
 * @param noPrnInit   If != 0 the printer won't be initialized when the print job starts
 *
 * @return 0 if the print job was started. < 0 if an error occoured
 */
int32_t PrintJobPrintBackground(tGsPrintJob * job, const char * file, int32_t noPrnInit);

/**
 * Check if it is possible to start a new print job
 *
 * @return > 0 if the print job is done. 0 if the job is still running.
 */
int32_t PrintJobDone(void);

/**
 * Checks a print template file for correct syntax.
 *
 * @param file  The print template file
 *
 * @return 0 if the print template file has correct syntax. < 0 if there is
 *         an uncorrectable error in the file. > 0 if there is a correctable
 *         error in the file.
 */
int32_t PrintCheckTemplate(const char * file); 

#ifdef __cplusplus
}
#endif //__cplusplus
//-----------------------------------------------------------------------------
//Function implementation
//-----------------------------------------------------------------------------

#endif //GSPRINT_H_INCLUDED
//-----------------------------------------------------------------------------
//EOF
//-----------------------------------------------------------------------------

