/**
 * @file
 *
 * math.h for UserC API programs
 *
 * @author Matthias Weisser<br>
 *         Graf-Syteco GmbH & Co. KG
 *
 * @date   created: 17.3 2009
 */

#ifndef MATH_H_INCLUDED
#define MATH_H_INCLUDED

//-----------------------------------------------------------------------------
//Includes
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
//Defines
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
//Datatypes
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
//Variables
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
//Function prototypes
//-----------------------------------------------------------------------------

/**
 * Calculates inverse cosine
 *
 * @note systemfunc
 *
 * @param x
 *
 * @return
 */
double acos(double x);

/**
 * Calculates inverse sine
 *
 * @note systemfunc
 *
 * @param x
 *
 * @return
 */
double asin(double x);

/**
 * Calculates inverse tangent
 *
 * @note systemfunc
 *
 * @param x
 *
 * @return
 */
double atan(double x);

/**
 * Returns the principal value of the arc tangent of y/x
 *
 * @note systemfunc
 *
 * @param x
 * @param y
 *
 * @return
 */
double atan2(double x, double y);

/**
 * Calculates the cosine
 *
 * @note systemfunc
 *
 * @param x
 *
 * @return
 */
double cos(double x);

/**
 * Calculates the sine
 *
 * @note systemfunc
 *
 * @param x
 *
 * @return
 */
double sin(double x);

/**
 * Calculates the cosine
 *
 * @note systemfunc
 *
 * @param x
 *
 * @return
 */
double tan(double x);

/**
 * Calculates the hyperbolic cosine
 *
 * @note systemfunc
 *
 * @param x
 *
 * @return
 */
double cosh(double x);

/**
 * Calculates the hyperbolic sine
 *
 * @note systemfunc
 *
 * @param x
 *
 * @return
 */
double sinh(double x);

/**
 * Calculates the hyperbolic tangent
 *
 * @note systemfunc
 *
 * @param x
 *
 * @return
 */
double tanh(double x);

/**
 * Calculates e raised by x
 *
 * @note systemfunc
 *
 * @param x
 *
 * @return
 */
double exp(double x);

/**
 *
 *
 * @note systemfunc
 *
 * @param x
 * @param y
 *
 * @return
 */
double frexp(double x, int * y);

/**
 *
 *
 * @note systemfunc
 *
 * @param x
 * @param y
 *
 * @return
 */
double ldexp(double x, int y);

/**
 * Calculates the natural logarithm
 *
 * @note systemfunc
 *
 * @param x
 *
 * @return
 */
double log(double x);

/**
 * Calculates the base 10 logarithm
 *
 * @note systemfunc
 *
 * @param x
 *
 * @return
 */
double log10(double x);

/**
 *
 *
 * @note systemfunc
 *
 * @param x
 * @param y
 *
 * @return
 */
double modf(double x, double * y);

/**
 * Calculates x raised by y
 *
 * @note systemfunc
 *
 * @param x
 * @param y
 *
 * @return
 */
double pow(double x, double y);

/**
 * Calculates the square root
 *
 * @note systemfunc
 *
 * @param x
 *
 * @return
 */
double sqrt(double x);

/**
 * Returns the smallest integral value that is not smaller then x
 *
 * @note systemfunc
 *
 * @param x
 *
 * @return
 */
double ceil(double x);

/**
 * Returns the absolut value of x
 *
 * @note systemfunc
 *
 * @param x
 *
 * @return
 */
double fabs(double x);

/**
 * Returns the biggest integral value that is not bigger then x
 *
 * @note systemfunc
 *
 * @param x
 *
 * @return
 */
double floor(double x);

/**
 *
 *
 * @note systemfunc
 *
 * @param x
 * @param y
 *
 * @return
 */
double fmod(double x, double y);

//-----------------------------------------------------------------------------
//Function implementation
//-----------------------------------------------------------------------------

#endif //MATH_H_INCLUDED
//-----------------------------------------------------------------------------
//EOF
//-----------------------------------------------------------------------------

