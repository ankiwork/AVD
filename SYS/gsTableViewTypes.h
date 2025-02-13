/**
 * @file
 *
 *
 * @author Pascal Lais<br>
 *         Graf-Syteco GmbH & Co. KG
 *
 * @date   created: 25.04.2017
 */
 
/************************************************************************/
 
#ifndef GSTABLEVIEWTYPES_H_INCLUDED
#define GSTABLEVIEWTYPES_H_INCLUDED

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
 * Type of the Table Column
 */
typedef enum eagGsTableViewColumnDataType
{
	GS_TABLEVIEW_COLUMN_TYPE_NONE,
    GS_TABLEVIEW_COLUMN_TYPE_INT,
    GS_TABLEVIEW_COLUMN_TYPE_UINT,
    GS_TABLEVIEW_COLUMN_TYPE_FLOAT,
    GS_TABLEVIEW_COLUMN_TYPE_DOUBLE,
    GS_TABLEVIEW_COLUMN_TYPE_CHAR,
    GS_TABLEVIEW_COLUMN_TYPE_STRING,
}eGsTableViewColumnDataType;

/**
 * Type of the Table Sort Order
 */
typedef enum eagGsTableViewSortOrder
{
	GS_TABLEVIEW_ORDER_NONE,
    GS_TABLEVIEW_ORDER_ASCENDING,
    GS_TABLEVIEW_ORDER_DESCENDING,
}eGsTableViewSortOrder;

/**
 * Type of the Table Parameter
 */
typedef enum eagGsTableViewParameter
{
    GS_TABLEVIEW_PARAMETER_NONE,
	GS_TABLEVIEW_PARAMETER_PAGE,
    GS_TABLEVIEW_PARAMETER_NUM_DATA,
    GS_TABLEVIEW_PARAMETER_NUM_PAGES,
    GS_TABLEVIEW_PARAMETER_ORDER_BY_COLUMN,
    GS_TABLEVIEW_PARAMETER_SORT_ORDER,
}eGsTableViewParameter;

/**
 *	Pointer to a TableView Column
 */
typedef struct tagGsTableViewColumn * tGsTableViewColumnPtr;

/**
 *	Pointer to a TableView
 */
typedef struct tagGsTableView * tGsTableViewPtr;

/**
 *	Function Pointer to a function that returns data of type int
 */
typedef int32_t (*tGsTableViewGetInt)(void * data, uint32_t column, uint32_t idx);

/**
 *	Function Pointer to a function that returns data of type unsigned int
 */
typedef uint32_t (*tGsTableViewGetUInt)(void * data, uint32_t column, uint32_t idx);

/**
 *	Function Pointer to a function that returns data of type float
 */
typedef float (*tGsTableViewGetFloat)(void * data, uint32_t column, uint32_t idx);

/**
 *	Function Pointer to a function that returns data of type double
 */
typedef double (*tGsTableViewGetDouble)(void * data, uint32_t column, uint32_t idx);

/**
 *	Function Pointer to a function that returns data of type char
 */
typedef char (*tGsTableViewGetChar)(void * data, uint32_t column, uint32_t idx);

/**
 *	Function Pointer to a function that returns data of type char*
 */
typedef char* (*tGsTableViewGetString)(void * data, uint32_t column, uint32_t idx);

/**
 *  Function Pointer to a function that gets called when a MenuAction event happens for a table cell
 */
typedef void (*tGsTableViewMenuActionEvent)(tGsTableViewPtr table, uint32_t column, uint32_t idx);

/**
 * Object with function pointers
 */
typedef struct tagGsTableViewFuncPtrs
{
    tGsTableViewGetInt mGetInt;
    tGsTableViewGetUInt mGetUInt;
    tGsTableViewGetFloat mGetFloat;
    tGsTableViewGetDouble mGetDouble;
    tGsTableViewGetChar mGetChar;
    tGsTableViewGetString mGetString;
    tGsTableViewMenuActionEvent mCellMenuActionEvent;
}tGsTableViewFuncPtrs;

/**
 * Table Column Object
 * Define those as an Array with all columns for each Table.
 */
typedef struct tagGsTableViewColumn
{
    eGsTableViewColumnDataType mDataType; //Datatype of data in this column
    uint32_t * mCellHdls;                 //Pointer to Array with the Handles for the data (OBJ_ or VAR_ depeinding of mType)
    uint32_t * mAttrHdls;                 //Pointer to Array with the Handles for the attributes (needed to make empty rows invisible)
    uint32_t * mCellMenuActionHdls;       //Pointer to Array with the Handles for a MenuAction for each cell
    uint32_t mSortButtonObjHdl;           //Object Handle for Sort MenuAction
    uint32_t mSortButtonVarHdl;           //VarHandle to display state of sorting data
}tGsTableViewColumn;

/**
 * Table object
 * After the gsTableViewInit() only work with the Values using
 * the gsTableViewSetParameter() or gsTableViewSetParameter() functions
 */
typedef struct tagGsTableView
{
    uint32_t mNumRows;                  //Number of Rows
    uint32_t mNumColumns;               //Number of Rows
    tGsTableViewColumnPtr mColumns;     //Pointer to an Array with the Table-Column Objects

    void * mData;                       //Pointer to the data struct Array
    uint32_t mNumData;                  //Number of Elements in the data-Array (change only via gsTableViewSetParameter())
    tGsTableViewFuncPtrs * mFuncPtrs;   //Pointer to the Object with the Function-Pointers

    uint32_t * mOrder;                  //Only used internal, dont declare this
    uint32_t mOrderByColumn;            //Index of Column whicht has the data to order after (change only via gsTableViewSetParameter())
    eGsTableViewSortOrder mSortOrder;   //Defines if Data gets sorted in ascending or descending order (change only via gsTableViewSetParameter())

    uint32_t mPage;                     //Number of Pages (set only via gsTableViewSetParameter())
    uint32_t mNumPages;                 //Number of Pages (read only, via gsTableViewGetParameter())
    uint32_t mPageVarHdl;               //VarHdl of Variable that displays the actual page of the table (0 if not used)
    uint32_t mNumPagesVarHdl;           //VarHdl of Variable that displays the number of pages of the table (0 if not used)
}tGsTableView;

//-----------------------------------------------------------------------------
//Variables
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
//Function prototypes
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
//Function implementation
//-----------------------------------------------------------------------------

#endif  // #ifndef GSTABLEVIEWTYPES_H_INCLUDED
//-----------------------------------------------------------------------------
//EOF
//-----------------------------------------------------------------------------
