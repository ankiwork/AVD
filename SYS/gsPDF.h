/**
 * @file
 *
 * Public interface to GS PDF library.
 *
 * @author Matthias Weisser<br>
 *         Graf-Syteco GmbH & Co. KG
 */

#ifndef GSPDF_H_INCLUDED
#define GSPDF_H_INCLUDED
 
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
typedef void tGsPDFHdl;

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
 * Creates a new instance of gsPDF library
 * 
 * @return A handle to a library object or NULL if an error occurred
 */
tGsPDFHdl * gsPDFCreate(void);

/**
 * Destroys a gsPDF instance 
 * 
 * @param hdl     Handle of a valid gsPDF instance
 */
void gsPDFDestroy(tGsPDFHdl * hdl);

/**
 * Sets the PDF file to work with
 *
 * @param hdl     Handle of a valid gsPDF instance
 * @param pdfFile Path to a valid PDF file
 * 
 * @return 0 on success, < 0 if an error occurred
 */
int32_t gsPDFSetPDFFile(tGsPDFHdl * hdl, const char * pdfFile);

/**
 * Sets the page to be rendered
 *
 * @param hdl     Handle of a valid gsPDF instance
 * @param page    The page in the PDF to be rendered (1 to n)
 * 
 * @return 0 on success, < 0 if an error occurred
 */
int32_t gsPDFSetPage(tGsPDFHdl * hdl, uint32_t page);

/**
 * Sets the DPI for rendering the PDF
 *
 * @param hdl     Handle of a valid gsPDF instance
 * @param dpi     A number between 30 and 600 to be used as DPI (default: 72)
 * 
 * @return 0 on success, < 0 if an error occurred
 */
int32_t gsPDFSetDPI(tGsPDFHdl * hdl, uint32_t dpi);

/**
 * Starts the rendering of a page. The filename of the rendered image
 * can be queried later.
 *
 * @param hdl     Handle of a valid gsPDF instance
 * 
 * @return 0 on success, < 0 if an error occurred
 */
int32_t gsPDFStartRender(tGsPDFHdl * hdl);

/**
 * If a rendering of a page was started this function can be used to 
 * query if the rendering is done.
 *
 * @param hdl     Handle of a valid gsPDF instance
 * 
 * @return 0 if rendering is done
 *         1 if rendering is in progress 
 *         < 0 if an error occurred
 */
int32_t gsPDFRenderDone(tGsPDFHdl * hdl);

/**
 * Returns the filename of the last rendered page. gsPDF will change
 * the name of the rendered file with every call to gsPDFStartRenderPage.
 * gsPDF will also delete a once rendered page when gsPDFStartRenderPage
 * is called again or the gsPDF instance is destroyed. So, when you need
 * the file later on you have to copy it to another location.
 *
 * @param hdl     Handle of a valid gsPDF instance
 * 
 * @return Filename of the last rendered file or NULL when there is
 *         no valid rendered file available
 */
const char * gsPDFGetImageFileName(tGsPDFHdl * hdl);

#ifdef __cplusplus
}
#endif //__cplusplus
//-----------------------------------------------------------------------------
//Function implementation
//-----------------------------------------------------------------------------

#endif //GSPDF_H_INCLUDED
//-----------------------------------------------------------------------------
//EOF
//-----------------------------------------------------------------------------

