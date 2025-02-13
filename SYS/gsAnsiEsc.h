/**
 * @file
 *
 * ANSI ESC code definitions
 *
 * @author Matthias Weisser<br>
 *         Graf-Syteco GmbH & Co. KG
 *
 * @date   created: 11.08.2010
 */

#ifndef GSANSIESC_H_INCLUDED
#define GSANSIESC_H_INCLUDED

//-----------------------------------------------------------------------------
//Includes
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
//Defines
//-----------------------------------------------------------------------------
#define ANSI_ESC               "\x1B"   //!< ESC code

#define ANSI_CMD_CU_COL        '`'      //!< Command character: Cursor column
#define ANSI_CMD_CU_ROW        'd'      //!< Command character: Cursor row
#define ANSI_CMD_CU_POS        'H'      //!< Command character: Cursor position
#define ANSI_CMD_CU_POS_ALT    'f'      //!< Command character: Cursor position (alternativ)
#define ANSI_CMD_CU_MU         'A'      //!< Command character: Cursor move up
#define ANSI_CMD_CU_MD         'B'      //!< Command character: Cursor move down
#define ANSI_CMD_CU_MR         'C'      //!< Command character: Cursor move right
#define ANSI_CMD_CU_ML         'D'      //!< Command character: Cursor move left
#define ANSI_CMD_CU_HOME       'H'      //!< Command character: Cursor home (to 0/0)
#define ANSI_CMD_FG_COL        'm'      //!< Command character: Foreground color
#define ANSI_CMD_CLR           'J'      //!< Command character: Clear all
#define ANSI_CMD_GS            'Z'      //!< Command character: Graf-Syteco specific

#define ANSI_CU_COL(col)       ANSI_ESC "[" #col "`"            //!< Set the cursor to column 'col'
#define ANSI_CU_ROW(row)       ANSI_ESC "[" #row "d"            //!< Set the cursor to row 'row'
#define ANSI_CU_POS(row, col)  ANSI_ESC "[" #row ";" #col "H"   //!< Set the cursor to row/column 'row' 'col'

#define ANSI_CU_MU(d)          ANSI_ESC "[" #d "A"              //!< Move cursor up
#define ANSI_CU_MD(d)          ANSI_ESC "[" #d "B"              //!< Move cursor down
#define ANSI_CU_MR(d)          ANSI_ESC "[" #d "C"              //!< Move cursor right
#define ANSI_CU_ML(d)          ANSI_ESC "[" #d "D"              //!< Move cursor left
#define ANSI_CU_HOME           ANSI_ESC "[" "H"                 //!< Move cursor home

#define ANSI_FG_BLACK          ANSI_ESC "[30m"                  //!< Forground color black
#define ANSI_FG_RED            ANSI_ESC "[31m"                  //!< Forground color red
#define ANSI_FG_GREEN          ANSI_ESC "[32m"                  //!< Forground color green
#define ANSI_FG_YELLOW         ANSI_ESC "[33m"                  //!< Forground color yellow
#define ANSI_FG_BLUE           ANSI_ESC "[34m"                  //!< Forground color blue
#define ANSI_FG_MAGENTA        ANSI_ESC "[35m"                  //!< Forground color magenta
#define ANSI_FG_CYAN           ANSI_ESC "[36m"                  //!< Forground color cyan
#define ANSI_FG_WHITE          ANSI_ESC "[37m"                  //!< Forground color white

#define ANSI_CLR_FROM_CU       ANSI_ESC "[0J"                   //!< Clears screen from cursor on
#define ANSI_CLR_TO_CU         ANSI_ESC "[1J"                   //!< Clears screen from home to cursor
#define ANSI_CLR_ALL           ANSI_ESC "[2J"                   //!< Clears the whole string

#define ANSI_GS_VAL0(v)        ANSI_ESC "[0;" #v "Z"            //!< Sets the value 0 to v (used in gsDiag for switch off warning)
#define ANSI_GS_VAL1(v)        ANSI_ESC "[1;" #v "Z"            //!< Sets the value 1 to v (used in gsDiag for font switching)
#define ANSI_GS_VAL2(v)        ANSI_ESC "[2;" #v "Z"            //!< Sets the value 2 to v (used in gsDiag for screen output on/off)
#define ANSI_GS_VAL3(v)        ANSI_ESC "[3;" #v "Z"            //!< Sets the value 3 to v
#define ANSI_GS_VAL4(v)        ANSI_ESC "[4;" #v "Z"            //!< Sets the value 4 to v
#define ANSI_GS_VAL5(v)        ANSI_ESC "[5;" #v "Z"            //!< Sets the value 5 to v
#define ANSI_GS_VAL6(v)        ANSI_ESC "[6;" #v "Z"            //!< Sets the value 6 to v
#define ANSI_GS_VAL7(v)        ANSI_ESC "[7;" #v "Z"            //!< Sets the value 7 to v

//-----------------------------------------------------------------------------
//Datatypes
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
//Variables
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
//Function prototypes
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
//Function implementation
//-----------------------------------------------------------------------------

#endif //GSANSIESC_H_INCLUDED
//-----------------------------------------------------------------------------
//EOF
//-----------------------------------------------------------------------------

