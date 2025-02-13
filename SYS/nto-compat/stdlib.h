/**
 * @file
 *
 * stdlib.h for UserC API programs
 *
 * @author Matthias Weisser<br>
 *         Graf-Syteco GmbH & Co. KG
 *
 * @date   created: 17.3 2009
 */

#ifndef STDLIB_H_INCLUDED
#define STDLIB_H_INCLUDED

//-----------------------------------------------------------------------------
//Includes
//-----------------------------------------------------------------------------
#include <stddef.h>
#include <stdint.h>

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
 * Puts the program into a sleep state for the given time
 *
 * @note systemfunc
 *
 * @param seconds
 *
 * @return
 */
unsigned int sleep(unsigned int seconds);

/**
 * Puts the program into a sleep state for the given time
 *
 * @note systemfunc
 *
 * @param useconds
 *
 * @return
 */
int usleep(unsigned int useconds);

/**
 * Allocates memory on the program heap
 *
 * @note systemfunc
 *
 * @param size
 *
 * @return
 */
void * malloc(size_t size);

/**
 * Allocates memory on the program heap and initializes it to 0
 *
 * @note systemfunc
 *
 * @param n
 * @param size
 *
 * @return
 */
void * calloc(size_t n, size_t size);

/**
 * Reallocates memory on the program heap.
 *
 * @note systemfunc
 *
 * @param ptr
 * @param size
 *
 * @return
 */
void * realloc(void * ptr, size_t size);

/**
 * Frees memory which was allocated with malloc, calloc, realloc,
 * strdup, ...
 *
 * @note systemfunc
 *
 * @param ptr
 *
 * @return
 */
void free(void * ptr);

/**
 * Sets a region of memory to a given value
 *
 * @note systemfunc
 *
 * @param s
 * @param c
 * @param n
 *
 * @return
 */
void * memset(void * s, int c, size_t n);

/**
 * Copies a region of memory to another
 *
 * @note systemfunc
 *
 * @param s1
 * @param s2
 * @param n
 *
 * @return
 */
void * memcpy(void * s1, const void * s2, size_t n);

/**
 * Compares two regions of memory
 *
 * @note systemfunc
 *
 * @param s1
 * @param s2
 * @param n
 *
 * @return
 */
int memcmp(const void * s1, const void * s2, size_t n);

/**
 * Sorting an array
 *
 * @note systemfunc
 *
 * @param base    Pointer to the beginning of the array to be sorted
 * @param num     Number of elements in the array
 * @param width   Size of one element of the array in bytes
 * @param compare Compare function which compares two entries. The value
 *                returned by this function tells if a is less then b (<0), a
 *                is the same then b (0) or a is bigger then b (>0)
 */
void qsort(void * base, size_t num, size_t width, int(*compare)(const void * a, const void * b));

/**
 * Binary search in a sorted array
 *
 * @note systemfunc
 *
 * @param key     The value to be searched for
 * @param base    Pointer to the beginning of the array where key should be
 *                searched in.
 * @param num     Number of elements in the array
 * @param width   Size of one element of the array in bytes
 * @param compare Compare function which compares two entries. The value
 *                returned by this function tells if a is less then b (<0), a
 *                is the same then b (0) or a is bigger then b (>0)
 *
 * @return Pointer to the entry found or NULL if key was not in base
 */
void * bsearch(const void *key, const void *base, size_t num, size_t width, int(*compare)(const void * pkey, const void * pbase));

//-----------------------------------------------------------------------------
//Function implementation
//-----------------------------------------------------------------------------

#endif //STDLIB_H_INCLUDED
//-----------------------------------------------------------------------------
//EOF
//-----------------------------------------------------------------------------
