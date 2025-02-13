/**
 * @file
 *
 *Types used by gsTrendWriter library.
 *
 * @author Pascal Lais<br>
 *         Graf-Syteco GmbH & Co. KG
 *
 * @date   created: 04.04.2017
 */
 
#ifndef GSTRENDWRITERTYPES_H_INCLUDED
#define GSTRENDWRITERTYPES_H_INCLUDED

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
 * Type of a Trend-Writer Parameter
 */
typedef enum eagGsTrendWriterParameter
{
    GS_TRENDWRITER_PARAMETER_ORIGIN_X,
    GS_TRENDWRITER_PARAMETER_ORIGIN_Y,
    GS_TRENDWRITER_PARAMETER_WIDTH,
    GS_TRENDWRITER_PARAMETER_HEIGHT,
    GS_TRENDWRITER_PARAMETER_MIN,
    GS_TRENDWRITER_PARAMETER_MAX,
    GS_TRENDWRITER_PARAMETER_CURRENT_MIN,
    GS_TRENDWRITER_PARAMETER_CURRENT_MAX,
    GS_TRENDWRITER_PARAMETER_MAX_VALUES,
    GS_TRENDWRITER_PARAMETER_START_IDX,
    GS_TRENDWRITER_PARAMETER_NUM_VALUES,
    GS_TRENDWRITER_PARAMETER_AUTOSCALE,
    GS_TRENDWRITER_PARAMETER_CURRENT_START_IDX,
    GS_TRENDWRITER_PARAMETER_CURRENT_END_IDX,
}eGsTrendWriterParameter;

typedef struct tagGsTrendWriter tGsTrendWriter;
typedef tGsTrendWriter * tGsTrendWriterHdl;

//-----------------------------------------------------------------------------
//Variables
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
//Function prototypes
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
//Function implementation
//-----------------------------------------------------------------------------
#endif  // #ifndef GSTRENDWRITERTYPES_H_INCLUDED
//-----------------------------------------------------------------------------
//EOF
//-----------------------------------------------------------------------------
