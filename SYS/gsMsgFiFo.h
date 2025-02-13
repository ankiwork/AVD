/**
 * @file
 *
 * A fifo which can be used to exchange any kind of data between threads in a
 * safe way.
 *
 * @author Matthias Weisser<br>
 *         Graf-Syteco GmbH & Co. KG
 */

#ifndef GSMSGFIFO_H_INCLUDED
#define GSMSGFIFO_H_INCLUDED
 
//-----------------------------------------------------------------------------
//Includes
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
//Defines
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
//Datatypes
//-----------------------------------------------------------------------------
typedef void * tGsMsgFiFo;

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
 * Creates a new msg fifo with storage space for up to s bytes
 *
 * @param s Number of bytes the FiFo can hold
 *
 * @return Pointer to the new fifo object or NULL if an error occoured
 */
tGsMsgFiFo gsMsgFiFoCreate(size_t s);

/**
 * Removes a message fifo which was created by gsMsgFiFoCreate
 *
 * @param fifo The fifo to be destroyed
 */
void gsMsgFiFoDestroy(tGsMsgFiFo fifo);

/**
 * Writes n bytes to the msg fifo
 *
 * @param fifo Msg fifo to be used for writing the data
 * @param src  Where the data should be copied from
 * @param n    Number of bytes to be copied to the fifo
 * @param to   If >0 : Timeout of the write request in ms
 *             If  0 : The FiFo will take all elements it has storage space
 *                     for. The function will then immediately return.
 *             If <0 : Wait until the write request is completely fulfilled
 *
 * @return Number of bytes written to the fifo
 */
size_t gsMsgFiFoWrite(tGsMsgFiFo fifo, const void * src, size_t n, int32_t to);

/**
 * Reads n bytes from the msg fifo
 *
 * @param fifo Msg fifo to be used for reading the data
 * @param dst  Where the data should be copied to
 * @param n    Number of bytes to be copied from the fifo
 * @param to   If >0 : Timeout of the read request in ms
 *             If  0 : All available messages will be read and the method
 *                     returns immediately.
 *             If <0 : Wait until the read request is completly fullfilled
 *
 * @return Number of bytes read from the fifo
 */
size_t gsMsgFiFoRead(tGsMsgFiFo fifo, void * dst, size_t n, int32_t to);

#ifdef __cplusplus
}
#endif //__cplusplus
//-----------------------------------------------------------------------------
//Function implementation
//-----------------------------------------------------------------------------

#endif //GSMSGFIFO_H_INCLUDED
//-----------------------------------------------------------------------------
//EOF
//-----------------------------------------------------------------------------

