/**
 * @file
 *
 * Allows a remote program to access the current state of the device
 *
 * @author Matthias Weisser<br>
 *         Graf-Syteco GmbH & Co. KG
 *
 * @date   created: 24.1 2012
 */

#ifndef GSREMOTEACCESS_H_INCLUDED
#define GSREMOTEACCESS_H_INCLUDED
 
//-----------------------------------------------------------------------------
//Includes
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
//Defines
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
//Datatypes
//-----------------------------------------------------------------------------

typedef void *tGsRemoteAccess;

/**
 * Function pointer type for the optional key preview function
 *
 * @param code  Same as SendKey UserC function
 * @param state Same as SendKey UserC function
 * 
 * @return If a value != 0 is returned the key will be passed to the application
 */
typedef int32_t (*tFpGsRemoteAccessSendKeyPreview)(uint32_t code, uint32_t state);

/**
 * Function pointer type for the optional touch preview function
 *
 * @param x     Same as SendKey UserC function
 * @param y     Same as SendKey UserC function
 * @param id    Same as SendKey UserC function
 * @param state Same as SendKey UserC function
 * @param dest  Same as SendKey UserC function
 * 
 * @return If a value != 0 is returned the touch event will be passed to the application
 */
typedef int32_t (*tFpGsRemoteAccessSendTouchPreview)(int16_t x, int16_t y, uint16_t id, uint32_t state, uint32_t dest);

typedef struct tagOfflineFileInfo
{
  uint32_t idx;        // offline file index on server
  char nameBuf[128];   // returned offline file name (available on server)
  size_t fileSize;     // returned offline file size (available on server)
  uint32_t timestamp;  // returned offline file timestamp (available on server)
}tOfflineFileInfo;

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
 * Creates the remote access library. After calling this function we will be able
 * to connect to the remote access server or to the local remote PC/accessor
 * (depending on parameter user, see below).
 * 
 * @param user Server: Username.
 *             Local:  NULL.
 * @param pw   Password (necessary for both - server or local connection).
 * @param host Server: Hostname/IP of the remote access server, NULL for GS default.
 *             Local:  Hostname/IP of the remote access PC/accessor.
 * @param port Server: Port number for the remote access server, 0 for default.
 *             Local:  Port number for the remote access PC/accessor.
 * 
 * @return The handle of the created remote access or NULL if it couln't be created.
 */
tGsRemoteAccess gsRemoteAccessCreate(const char *user, const char *pw, const char *host, uint16_t port);

/**
 * Connects for remote access. After calling this function we will be connected
 * to the remote access server (in case of using remote connection via server)
 * or to remote PC/accessor (in case of local connection) and waiting for incoming
 * protocols from remote PC/accessor.
 * 
 * @param hdl Handle to created remote access instance.
 * 
 * @return 0 on success.
 */
int gsRemoteAccessConnect(tGsRemoteAccess hdl);

/**
 * Destroys the remote access library. An open connection will be closed.
 * 
 * @param hdl Handle to created remote access instance.
 * 
 * @return void
 */
void gsRemoteAccessDestroy(tGsRemoteAccess hdl);

/**
 * Returns the ID string for the remote connection (Needed on PC/accessor side in case of using remote connection via server).
 * 
 * @param hdl Handle to created remote access instance.
 * @param buf Where the string will be copied to.
 * @param len Number of bytes available at buf.
 * 
 * @return Actual number ob bytes copied (May be 0 if not connected to server)
 */
size_t gsRemoteAccessGetId(tGsRemoteAccess hdl, char * buf, size_t len);

/**
 * Sets the (8 bit) instance Number to be able to identify the remote access instance with every incomimg event CEVT_TRANS_FILE.
 * 
 * @param hdl Handle to created remote access instance.
 * @param instNum The (8 bit) instance Number for "this" remote access instance.
 * 
 * @return void
 */
void gsRemoteAccessSetInstNum(tGsRemoteAccess hdl, uint8_t instNum);

/**
 * Sets the offline file mode. This is used for file transfer from/to a server (not connected direct to device)
 * 
 * @param hdl Handle to created remote access instance.
 * @param ofMode 1 sets created remote access instance to server/offline mode
 * 
 * @return void
 */
void gsRemoteAccessSetOfflineFileMode(tGsRemoteAccess hdl, uint32_t ofMode);

/**
 * Sends a file to connected server
 * 
 * @param hdl Handle to created remote access instance.
 * @param dev  File source name (path and name on device), max. 259 bytes.
 * @param srv  File destination name (name to be stored on server), max. 259 bytes.
 * 
 * @return 0 on successful file send, -1 otherwise
 */
int gsRemoteAccessSndFileToServer(tGsRemoteAccess hdl, const char *dev, const char *srv);

/**
 * Requests a file from server
 * 
 * @param hdl Handle to created remote access instance.
 * @param dev  File destination name (path and name to be stored on device), max. 259 bytes.
 * @param srv  File source name (name on server), max. 259 bytes.
 * 
 * @return 0 on successful file request, -1 otherwise
 */
int gsRemoteAccessReqFileFromServer(tGsRemoteAccess hdl, const char *dev, const char *srv);

/**
 * Requests the number of "offline" files available on server
 * 
 * @param hdl Handle to created remote access instance.
 * @param nof Pointer to number of offline files to be returned.
 * 
 * @return Number of offline files available on server, -1 on error
 */
int gsRemoteAccessReqNumOfFilesOnServer(tGsRemoteAccess hdl, size_t *nof);

/**
 * Requests the info for each of the "offline" files available on server
 * 
 * @param hdl Handle to created remote access instance.
 * @param fn  Pointer to file name of interest.
 * @param ofi Pointer to offline file info structure to be returned.
 * 
 * @return 0 on success, -1 otherwise
 */
int gsRemoteAccessReqFileInfoFromServer(tGsRemoteAccess hdl, const char *fn, tOfflineFileInfo *ofi);

/**
 * Sets the speed level. This controls the time for collecting different events
 * 
 * @param hdl    Handle to created remote access instance.
 * @param sLevel 1: LAN      (240ms for VarChange-Events, 220ms for VisObjDataChange-Events,  90ms for Key-Events)
 *               2: UMTS     (480ms for VarChange-Events, 440ms for VisObjDataChange-Events, 180ms for Key-Events)
 *               3: GSM/GPRS (720ms for VarChange-Events, 660ms for VisObjDataChange-Events, 270ms for Key-Events)
 * 
 * @return void
 */
void gsRemoteAccessSetSpeedLevel(tGsRemoteAccess hdl, uint32_t sLevel);

/**
 * Sets the debug level
 * 
 * @param hdl   Handle to created remote access instance.
 * @param level 0: disables debug window (and all debug outputs)
 *              1: enables debug window and some main outputs (Feed, Write (except VAR_CHANGE), Errors, Synchronize)
 *              2: enables debug window and some more outputs (.., Write (VAR_CHANGE), Read States, Warnings)
 *              3: enables debug window and all outputs (.., Collector)
 * 
 * @return void
 */
void gsRemoteAccessSetDebugLevel(tGsRemoteAccess hdl, uint32_t level);

/**
 * Sets the key preview function
 * 
 * @param hdl   Handle to created remote access instance.
 * @param func  Function which should be called when a key is going to be send
 *              to the application coming from the remote access client
 * 
 * @return void
 */
void gsRemoteAccessSetKeyPreviewFunc(tGsRemoteAccess hdl, tFpGsRemoteAccessSendKeyPreview func);

/**
 * Sets the touch preview function
 * 
 * @param hdl   Handle to created remote access instance.
 * @param func  Function which should be called when a touch event is going to be send
 *              to the application coming from the remote access client
 * 
 * @return void
 */
void gsRemoteAccessSetTouchPreviewFunc(tGsRemoteAccess hdl, tFpGsRemoteAccessSendTouchPreview func);

#ifdef __cplusplus
}
#endif //__cplusplus

#endif //GSREMOTEACCESS_H_INCLUDED
//-----------------------------------------------------------------------------
//EOF
//-----------------------------------------------------------------------------

