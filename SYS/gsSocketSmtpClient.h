/**
 * @file
 *
 * Simple functions for sending mails over SMTP
 *
 * @author Matthias Weisser<br>
 *         Graf-Syteco GmbH & Co. KG
 *
 * @date   created: 14.9 2012
 */

#ifndef GSSOCKETSMTPCLIENT_H_INCLUDED
#define GSSOCKETSMTPCLIENT_H_INCLUDED
 
//-----------------------------------------------------------------------------
//Includes
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
//Defines
//-----------------------------------------------------------------------------
#define GSSOCKET_SMTPCLIENT_SEND_BACKGROUND (1<<0)  //<! Mails will be send in background

//-----------------------------------------------------------------------------
//Datatypes
//-----------------------------------------------------------------------------
typedef void * tGsSocketSmtpClient;

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
 * Creates a new SMTP client. A created client can then be used to send multiple
 * eMails over a SMTP server.
 *
 * @param host  Address of the SMTP server
 * @param port  Port to be used (default is port 25)
 * @param flags See GSSOCKET_SMTPCLIENT_SEND_*
 *
 * @return The handle of the created client or NULL if client couldn't be created
 */
tGsSocketSmtpClient gsSocketSmtpClientCreate(const char * host, uint16_t port, uint32_t flags);

/**
 * Creates a new SMTP client supporting TLS encryption. A created client can 
 * then be used to send multiple eMails over a SMTP server supporting STARTTLS (port 587).
 *
 * @param host  Address of the SMTP server
 * @param port  Port to be used (default is port 25)
 * @param flags See GSSOCKET_SMTPCLIENT_SEND_*
 *
 * @return The handle of the created client or NULL if client couldn't be created
 */
tGsSocketSmtpClient gsSocketSmtpClientTLSCreate(const char * host, uint16_t port, uint32_t flags);

/**
 * Destroys a TCP client. Open connection will be closed and hdl shouldn't be
 * used after call to this function.
 *
 * @param hdl Handle of the client to be closed
 */
void gsSocketSmtpClientDestroy(tGsSocketSmtpClient hdl);

/**
 * Clears all previous set data
 *
 * @param hdl Handle of the client to be used
 */
void gsSocketSmtpClientClear(tGsSocketSmtpClient hdl);

/**
 * Sets the global timeout for result reading in ms
 *
 * @param hdl Handle of the client to be used
 * @param to Timeout for reads in ms
 */
void gsSocketSmtpClientSetTimeout(tGsSocketSmtpClient hdl, uint32_t to);

/**
 * Sets the mail address of the sender
 *
 * @param hdl Handle of the client to be used
 * @param from The mail address of the sender
 *
 * @return true if set successful
 */
int32_t gsSocketSmtpClientSetFrom(tGsSocketSmtpClient hdl, const char * from);

/**
 * Adds an additional recipient
 *
 * @param hdl Handle of the client to be used
 * @param to The mail address of the recipient to be added
 *
 * @return true if added successful
 */
int32_t gsSocketSmtpClientAddRcpt(tGsSocketSmtpClient hdl, const char * to);

/**
 * Sets the subject of the mail
 *
 * @param hdl Handle of the client to be used
 * @param subject The subject of the mail
 *
 * @return true if set successful
 */
int32_t gsSocketSmtpClientSetSubject(tGsSocketSmtpClient hdl, const char * subject);

/**
 * Adds an additional body line (newline added automatically)
 *
 * @param hdl Handle of the client to be used
 * @param line The body line to be added
 *
 * @return true if added successful
 */
int32_t gsSocketSmtpClientAddLine(tGsSocketSmtpClient hdl, const char * line);

/**
 * Adds an attachment to the mail. The file will not be read
 * when calling this method. This means that the file has to be
 * there when Send is called. A maximum of eight attachments is
 * currently possible.
 *
 * @param hdl Handle of the client to be used
 * @param name Name (including path) of the file to be send
 *
 * @return true if the file was added to the list of attachments
 */
int32_t gsSocketSmtpClientAddAttachment(tGsSocketSmtpClient hdl, const char * name);

/**
 * If the smtp client was created with background sending enabled this
 * function can be used to check if the smtp client is ready to send 
 * another mail.
 *
 * @param hdl Handle of the client to be used
 *
 * @return true if the client can send an mail (read: is currently not
 *         sending)
 */
int32_t gsSocketSmtpClientCanSend(tGsSocketSmtpClient hdl);

/**
 * Sends the mail with the settings given
 *
 * @param hdl Handle of the client to be used
 * @param user Username used for AUTH if supported (may be 0)
 * @param pass Password to be used for AUTH if supported (may be 0)
 *
 * @return true if the mail was send successfully
 */
int32_t gsSocketSmtpClientSend(tGsSocketSmtpClient hdl, const char * user, const char * pass);

#ifdef __cplusplus
}
#endif //__cplusplus
//-----------------------------------------------------------------------------
//Function implementation
//-----------------------------------------------------------------------------

#endif //GSSOCKETSMTPCLIENT_H_INCLUDED
//-----------------------------------------------------------------------------
//EOF
//-----------------------------------------------------------------------------

