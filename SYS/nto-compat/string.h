/**
 * @file
 *
 * stdio.h for UserC API programs
 *
 * @author Matthias Weisser<br>
 *         Graf-Syteco GmbH & Co. KG
 *
 * @date   created: 17.3 2009
 */

#ifndef STRING_H_INCLUDED
#define STRING_H_INCLUDED

//-----------------------------------------------------------------------------
//Includes
//-----------------------------------------------------------------------------
#include <stdlib.h>
#include <stdarg.h>

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
 * Concatenates two strings
 *
 * @note systemfunc
 *
 * @param s1
 * @param s2
 *
 * @return
 */
char * strcat(char * s1, const char * s2);

/**
 * Compares two strings
 *
 * @note systemfunc
 *
 * @param s1
 * @param s2
 *
 * @return 0 when s1 is equal to s2
 */
int strcmp(const char * s1, const char * s2);

/**
 * Copies s2 to s1
 *
 * @note systemfunc
 *
 * @param s1
 * @param s2
 *
 * @return
 */
char * strcpy(char * s1, const char * s2);

/**
 * Calculates lenght of s
 *
 * @note systemfunc
 *
 * @param s
 *
 * @return
 */
size_t strlen( const char * s);

/**
 * Concatenetes two strings
 *
 * @note systemfunc
 *
 * @param s1
 * @param s2
 * @param n
 *
 * @return
 */
char * strncat(char * s1, const char * s2, size_t n);

/**
 * Compares two strings
 *
 * @note systemfunc
 *
 * @param s1
 * @param s2
 * @param n
 *
 * @return
 */
int strncmp(const char * s1, const char * s2, size_t n);

/**
 * Copies the content of s2 into s1
 *
 * @note systemfunc
 *
 * @param s1
 * @param s2
 * @param n
 *
 * @return
 */
char * strncpy(char * s1, const char * s2, size_t n);

/**
 * Duplicates a string. The resulting pointer points to memory
 * which has to be freed with the free() function.
 *
 * @note systemfunc
 *
 * @param s
 *
 * @return
 */
char * strdup(const char * s);

/**
 * Converts a string into a long int
 *
 * @note systemfunc
 *
 * @param nptr
 * @param endptr
 * @param base
 *
 * @return
 */
long int strtol(const char * nptr, char ** endptr, int base);

/**
 * Converts a string into a unsigned long int
 *
 * @note systemfunc
 *
 * @param nptr
 * @param endptr
 * @param base
 *
 * @return
 */
unsigned long int strtoul(const char * nptr, char ** endptr, int base);

/**
 * Splits a string into tokens. s1 is the string to be split
 * and s2 contains the characters where s1 will be split at.
 * Multiple calls are needed to split the string.
 *
 * @note systemfunc
 *
 * @param s1
 * @param s2
 *
 * @return
 */
char * strtok(char * s1, const char * s2);

/**
 * Converts a string to a floating point value
 *
 * @note systemfunc
 *
 * @param s The string to be converted
 *
 * @return The converted value
 */
double atof(const char * s);

/**
 * Converts a string to an integer value
 *
 * @note systemfunc
 *
 * @param s The string to be converted
 *
 * @return The converted value
 */
int atoi(const char * s);


/**
 * printf-like function which uses a string as output
 *
 * @note systemfunc
 *
 * @param s
 * @param size
 * @param format
 *
 * @return
 */
int snprintf(char * s, size_t size, const char * format, ...) __attribute__((format (printf, 3, 4)));

/**
 * printf-like function which uses a string as output
 *
 * @note systemfunc
 *
 * @param s
 * @param format
 *
 * @return
 */
int sprintf(char * s, const char * format, ...) __attribute__((format (printf, 2, 3)));

/**
 * printf-like function which uses a string as output. Can be used together with
 * the macros in <stdarg.h>
 *
 * @note systemfunc
 *
 * @param s
 * @param size
 * @param format
 * @param arg
 *
 * @return
 */
int vsnprintf(char * s, size_t size, const char * format, va_list arg);

/**
 * Converts a string into a floating point number
 *
 * @note systemfunc
 *
 * @param ptr
 * @param endptr
 *
 * @return
 */
double strtod(const char *ptr, char **endptr);

/**
 * Searches a string inside another string
 *
 * @note systemfunc
 *
 * @param s1
 * @param s2
 *
 * @return
 */
char * strstr(const char * s1, const char * s2);

/**
 * Searches the first occourence of a given character in a string
 *
 * @note systemfunc
 *
 * @param s The string to be searched
 * @param c The character you are searching for
 *
 * @return Pointer to the first occourence of c in s or NULL if c is not in s
 */
char * strchr(const char * s, int c);

/**
 * Searches the last occourence of a given character in a string
 *
 * @note systemfunc
 *
 * @param s The string to be searched
 * @param c The character you are searching for
 *
 * @return Pointer to the last occourence of c in s or NULL if c is not in s
 */
char * strrchr(const char * s, int c);


//-----------------------------------------------------------------------------
//Function implementation
//-----------------------------------------------------------------------------

#endif //STRING_H_INCLUDED
//-----------------------------------------------------------------------------
//EOF
//-----------------------------------------------------------------------------

