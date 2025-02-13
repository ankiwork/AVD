/**
 * @file
 *
 * Threads usable from a UserC program. Actually a limited subset of the
 * pthread API.
 *
 * @author Matthias Weisser<br>
 *         Graf-Syteco GmbH & Co. KG
 *
 * @date   created: 9.5 2012
 */

#ifndef GSTHREAD_H_INCLUDED
#define GSTHREAD_H_INCLUDED
 
//-----------------------------------------------------------------------------
//Includes
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
//Defines
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
//Datatypes
//-----------------------------------------------------------------------------
typedef void * tGsThread;
typedef void * tGsThreadAttr;

typedef void * tGsMutex;
typedef void * tGsMutexAttr;

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
 * Creates a new thread using the passed thread function. The thread will be
 * started immediately after creation.  
 *
 * @param thr           Thread handle which will be initialized if the call is successful
 * @param attr          Thread attribute (currently ignored, pass NULL)
 * @param threadFunc    The actual function to be run as a thread
 * @param arg           Parameter passed to the thread function
 *
 * @return 0 on success
 */
int gsThreadCreate(tGsThread * thr, const tGsThreadAttr * attr, void * (*threadFunc)(void *), void * arg);

/**
 * Cancels a running thread. If the thread needs to reach a cancellation point
 * to be joinable
 *
 * @param thr The thread object as initialized by gsThreadCreate
 *
 * @return 0 on success
 */
int gsThreadCancel(tGsThread thr);

/**
 * Serves as a cancellation point when gsThreadCancel was called for the 
 * current thread
 */
void gsThreadTestCancel(void);

/**
 * If a thread exits this function should be called. Do not call this function
 * from UserCCycle or UserCAPI
 *
 * @param valuePtr This value will be passed back by gsThreadJoin
 */
void gsThreadExit(void * valuePtr);

/**
 * Joins a thread. The function will return after the given thread called 
 * gsThreadExit or simply returned from the thread function
 *
 * @param thr       The thread object as initialized by gsThreadCreate
 * @param valuePtr  Value passed to gsThreadExit will be copied here
 *
 * @return 0 on success
 */
int gsThreadJoin(tGsThread thr, void ** valuePtr);

/**
 * Creates a new mutex object which can be used to synchronize data access 
 * between multiple threads.
 *
 * @param mtx  The mutex object to be initialized
 * @param attr Mutex attribute (currently ignored, pass NULL)
 *
 * @return 0 on success
 */
int gsThreadMutexInit(tGsMutex * mtx, const tGsMutexAttr * attr);

/**
 * Destroys a mutex object
 *
 * @param mtx The mutex object as initialized by gsThreadMutexInit
 *
 * @return 0 on success
 */
int gsThreadMutexDestroy(tGsMutex * mtx);

/**
 * Locks a mutex object. If the mutex is locked by another thread
 * this function will block.
 *
 * @param mtx The mutex object as initialized by gsThreadMutexInit
 *
 * @return 0 on success
 */
int gsThreadMutexLock(tGsMutex * mtx);

/**
 * Locks a mutex object. If the mutex is locked by another thread
 * this function will return an error.
 *
 * @param mtx The mutex object as initialized by gsThreadMutexInit
 *
 * @return 0 on success
 */
int gsThreadMutexTrylock(tGsMutex * mtx);

/**
 * Unlocks a mutex object.
 *
 * @param mtx The mutex object as initialized by gsThreadMutexInit
 *
 * @return 0 on success
 */
int gsThreadMutexUnlock(tGsMutex * mtx);

#ifdef __cplusplus
}
#endif //__cplusplus
//-----------------------------------------------------------------------------
//Function implementation
//-----------------------------------------------------------------------------

#endif //GSTHREAD_H_INCLUDED
//-----------------------------------------------------------------------------
//EOF
//-----------------------------------------------------------------------------

