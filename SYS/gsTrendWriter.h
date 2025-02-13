/**
 * @file
 *
 * Trend-Writer Library that uses a Bezier Object to show a 
 * Curve for a set of DataValues
 *
 * @author Pascal Lais<br>
 *         Graf-Syteco GmbH & Co. KG
 *
 * @date   created: 04.04.2017
 */
 
#ifndef GSTRENDWRITER_H_INCLUDED_INCLUDED
#define GSTRENDWRITER_H_INCLUDED_INCLUDED

//-----------------------------------------------------------------------------
//Includes
//-----------------------------------------------------------------------------
#include <stdint.h>

#include "gsTrendWriterTypes.h"

//-----------------------------------------------------------------------------
//Datatypes
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
//Function prototypes
//-----------------------------------------------------------------------------

#ifdef __cplusplus
extern "C" {
#endif //__cplusplus

/**
 * Initializes a gsTrendWriter
 *
 * @param objId       Object Id of a Bezier Object, which will be used as gsTrendWriter
 *
 * @return Handle for the initialized gsTrendWriter
 */
tGsTrendWriterHdl gsTrendWriterInit(uint32_t objId);

/**
 * Deinitializes a gsTrendWriter
 *
 * @param hdl       Handle returnded by gsTrendWriterInit()
 */
void gsTrendWriterDeInit(tGsTrendWriterHdl hdl); 

/**
 * Sets a Parameter for a gsTrendWriter
 *
 * @param hdl             Handle returnded by gsTrendWriterInit()
 * @param parameter       Defines which Parameter should get changed
 * @param value           Value to set for the Parameter
 */
void gsTrendWriterSetParameter(tGsTrendWriterHdl hdl, eGsTrendWriterParameter parameter, int32_t value);

/**
 * Returns the Value of a Parameter for a gsTrendWriter
 *
 * @param hdl           Handle returnded by gsTrendWriterInit()
 * @param parameter     Defines which Parameter should be returned
 *
 * @return Parameter which was requested
 */
int32_t gsTrendWriterGetParameter(tGsTrendWriterHdl hdl, eGsTrendWriterParameter parameter);

/**
 * Sets Data to the Bezier Object
 *
 * @param hdl       Handle returnded by gsTrendWriterInit()
 * @param data      Data Array which will get displayed by the gsTrendWriter
 */
void gsTrendWriterSetData(tGsTrendWriterHdl hdl, int32_t * data);
 
#ifdef __cplusplus
}
#endif //__cplusplus

#endif  // #ifndef GSTRENDWRITER_H_INCLUDED
//-----------------------------------------------------------------------------
//EOF
//-----------------------------------------------------------------------------
