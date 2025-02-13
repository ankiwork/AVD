/**
 * @file
 *
 * Logical key function codes to be used by MCP/MCQ/ARGOS visualization
 *
 * @author Matthias Weisser<br>
 *         Graf-Syteco GmbH & Co. KG
 *
 * @date   created: 14.3 2012
 */

#ifndef GSTOVISU_H_INCLUDED
#define GSTOVISU_H_INCLUDED

//-----------------------------------------------------------------------------
//Includes
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
//Defines
//-----------------------------------------------------------------------------
#define GS_TO_VISU_OBJ_SELECT                  0       //!< Put the given object id into selected mode
#define GS_TO_VISU_SET_VAR                     1       //!< Sets a variable to a value (objId is the handle)

#define GS_TO_VISU_SET_PROPERTY_MIN        10000       //!< = GS_TO_VISU_SYNC_PROPERTIES
#define GS_TO_VISU_SYNC_PROPERTIES         10000       //!< Synchronize all the (cahnged) object properties (used in case of remote access)
#define GS_TO_VISU_SET_FG_COLOR            10001       //!< Sets the foreground color of an object
#define GS_TO_VISU_SET_BK_COLOR            10002       //!< Sets the background color of an object
#define GS_TO_VISU_SET_SEL_FG_COLOR        10003       //!< Sets the foreground color of an object in selected state
#define GS_TO_VISU_SET_SEL_BK_COLOR        10004       //!< Sets the background color of an object in selected state
#define GS_TO_VISU_SET_ED_FG_COLOR         10005       //!< Sets the foreground color of an object in edited state
#define GS_TO_VISU_SET_ED_BK_COLOR         10006       //!< Sets the background color of an object in edited state
#define GS_TO_VISU_SET_SEL_FR_COLOR        10007       //!< Sets the frame color of an object in selected state
#define GS_TO_VISU_SET_ED_FR_COLOR         10008       //!< Sets the frame color of an object in edited state
#define GS_TO_VISU_SET_ED_CU_COLOR         10009       //!< Sets the cursor color of an object in edited state
#define GS_TO_VISU_SET_ED_SC_COLOR         10010       //!< Sets the scroll line color of an object in edited state
#define GS_TO_VISU_SET_FILL_COLOR          10011       //!< Sets the fill color of an object
#define GS_TO_VISU_SET_OUTL_COLOR          10012       //!< Sets the outline color of an object
#define GS_TO_VISU_SET_OUTL_FG_COLOR       10013       //!< Sets the outline foreground color of an object
#define GS_TO_VISU_SET_OUTL_BK_COLOR       10014       //!< Sets the outline background color of an object
#define GS_TO_VISU_SET_SEL_FILL_COLOR      10015       //!< Sets the fill color of an object in selected state
#define GS_TO_VISU_SET_SEL_OUTL_COLOR      10016       //!< Sets the outline color of an object in selected state
#define GS_TO_VISU_SET_ED_FILL_COLOR       10017       //!< Sets the fill color of an object in edited state
#define GS_TO_VISU_SET_ED_OUTL_COLOR       10018       //!< Sets the outline color of an object in edited state
#define GS_TO_VISU_SET_GR_COLOR            10019       //!< Sets the gradient color of an object
#define GS_TO_VISU_SET_OVR_FG_COLOR        10020       //!< Sets the overflow foreground color of an object
#define GS_TO_VISU_SET_OVR_BK_COLOR        10021       //!< Sets the overflow background color of an object
#define GS_TO_VISU_SET_OVR_GR_COLOR        10022       //!< Sets the overflow gradient color of an object
#define GS_TO_VISU_SET_UND_FG_COLOR        10023       //!< Sets the underflow foreground color of an object
#define GS_TO_VISU_SET_UND_BK_COLOR        10024       //!< Sets the underflow background color of an object
#define GS_TO_VISU_SET_UND_GR_COLOR        10025       //!< Sets the underflow gradient color of an object
#define GS_TO_VISU_SET_1ST_COLOR           10026       //!< Sets the first color of an object
#define GS_TO_VISU_SET_2ND_COLOR           10027       //!< Sets the second color of an object
#define GS_TO_VISU_SET_TRANS_COLOR         10028       //!< Sets the transparent color of an object
#define GS_TO_VISU_SET_ORIGIN_X            10029       //!< Sets the position/origin-X of an object
#define GS_TO_VISU_SET_ORIGIN_Y            10030       //!< Sets the position/origin-Y of an object
#define GS_TO_VISU_SET_P1_X                10031       //!< Sets the position P1-X of an object (= center for Ellipse)
#define GS_TO_VISU_SET_P1_Y                10032       //!< Sets the position P1-Y of an object (= center for Ellipse)
#define GS_TO_VISU_SET_P2_X                10033       //!< Sets the position P2-X of an object (= control P1 for Bezier)
#define GS_TO_VISU_SET_P2_Y                10034       //!< Sets the position P2-Y of an object (= control P1 for Bezier)
#define GS_TO_VISU_SET_P3_X                10035       //!< Sets the position P3-X of an object (= control P2 for Bezier)
#define GS_TO_VISU_SET_P3_Y                10036       //!< Sets the position P3-Y of an object (= control P2 for Bezier)
#define GS_TO_VISU_SET_P4_X                10037       //!< Sets the position P4-X of an object (= P2 for Bezier)
#define GS_TO_VISU_SET_P4_Y                10038       //!< Sets the position P4-Y of an object (= P2 for Bezier)
#define GS_TO_VISU_SET_ATTR_ALL            10039       //!< Sets all the attribute flags (as uint32_t, the highest 12 bits will be ignored)
#define GS_TO_VISU_SET_ATTR_INVERTED       10040       //!< Sets the attribute flag "Objekt ist invertiert"
#define GS_TO_VISU_SET_ATTR_BLINK          10041       //!< Sets the attribute flag "Objekt blinkt"
#define GS_TO_VISU_SET_ATTR_UNDERLINE      10042       //!< Sets the attribute flag "Objekt ist unterstrichen (nur Text)"
#define GS_TO_VISU_SET_ATTR_VISIBLE        10043       //!< Sets the attribute flag "Objekt ist sichtbar"
#define GS_TO_VISU_SET_ATTR_TRANSPARENT    10044       //!< Sets the attribute flag "Objekt ist Transparent (nur Text)"
#define GS_TO_VISU_SET_ATTR_SMOOTH         10045       //!< Sets the attribute flag "Glättung verwenden"
#define GS_TO_VISU_SET_ATTR_AUTOSELECTNEXT 10046       //!< Sets the attribute flag "Automatisch nächste Objekt anspringen nach <ASCII-Enter>"
#define GS_TO_VISU_SET_ATTR_NOMINALFLAG    10047       //!< Sets the attribute flag "Objekt ist Eingabeobjekt und nimmt Tastenereignisse entgegen"
#define GS_TO_VISU_SET_ATTR_LOWERBLINKFG   10048       //!< Sets the attribute flag "Text des Objekts blinkt bei Unterschreiten eines unteren Limits"
#define GS_TO_VISU_SET_ATTR_UPPERBLINKFG   10049       //!< Sets the attribute flag "Text des Objekts blinkt bei Überschreiten eines oberen Limits"
#define GS_TO_VISU_SET_ATTR_LOWERBLINKBK   10050       //!< Sets the attribute flag "Hintergrund des Objekts blinkt bei Unterschreiten eines unteren Limits"
#define GS_TO_VISU_SET_ATTR_UPPERBLINKBK   10051       //!< Sets the attribute flag "Hintergrund des Objekts blinkt bei Überschreiten eines oberen Limits"
#define GS_TO_VISU_SET_ATTR_GRABFOCUS      10052       //!< Sets the attribute flag "Das Objekt versucht beim Aufschalten der Maske den Focus zu bekommen"
#define GS_TO_VISU_SET_ATTR_UPDATEONEDIT   10053       //!< Sets the attribute flag "Die zugehörige Variable wird bei Änderung sofort aktualisiert"
#define GS_TO_VISU_SET_ATTR_ANIMATED       10054       //!< Sets the attribute flag "Animation aktiviert (TrendWriter, Einzelbildgrafik)"
#define GS_TO_VISU_SET_ATTR_ALIGN          10055       //!< Sets the attribute flag "Textobjekte Alignment 0=Left/Top 1=Center 2=Right/Bottom"
#define GS_TO_VISU_SET_ATTR_DRAWMODE       10056       //!< Sets the attribute flag "Textobjekte Zeichenrichtung 0=LeftToRight 1=BottomToTop 2=RightToLeft"
#define GS_TO_VISU_SET_WIDTH               10057       //!< Sets the width of an object"
#define GS_TO_VISU_SET_HEIGHT              10058       //!< Sets the height of an object"
#define GS_TO_VISU_SET_ALTTXT1_FG_COLOR    10059       //!< Sets the alternative text 1 foreground color of an object
#define GS_TO_VISU_SET_ALTTXT1_BK_COLOR    10060       //!< Sets the alternative text 1 background color of an object
#define GS_TO_VISU_SET_ALTTXT2_FG_COLOR    10061       //!< Sets the alternative text 2 foreground color of an object
#define GS_TO_VISU_SET_ALTTXT2_BK_COLOR    10062       //!< Sets the alternative text 2 background color of an object
//Note: ! Add new defines here !
//        Add it also to overview below
//Do not change existing defines (names and values) to keep it in line to existing OS/User-C!
#define GS_TO_VISU_SET_PROPERTY_MAX        19999

#define GS_TO_VISU_SET_ATTR_MIN            GS_TO_VISU_SET_ATTR_ALL
#define GS_TO_VISU_SET_ATTR_MAX            GS_TO_VISU_SET_ATTR_DRAWMODE
#define GS_TO_VISU_SET_ATTR_MASK           0x000FFF7F

//                                    A   A   B   C   B   E   Q   T   P   S   I   M   S   T   R   R   R   R   T   T   T   T   T   T   T   T
//                                    d   d   a   i   e   l   u   r   i   i   n   e   i   r   e   e   e   e   r   r   r   r   r   r   r   r
//                                    v   v   r   r   z   l   a   i   p   m   d   n   m   e   s   s   s   s   u   u   u   u   u   u   u   u
//                                    I   I   g   c   i   i   d   a   e   p   e   u   p   n   T   T   T   T   e   e   e   e   e   e   e   e
//                                    n   n   r   l   e   p       n   F   l   x   B   l   d   T   T   T   T   T   T   T   T   T   T   T   T
//                                    s   s   a   e   r   s   |   g   l   e   B   i   e   W   T   E   T   M   y   y   y   y   y   y   y   y
//                                    t   t   p   S       e   |   l   o   B   i   t   V   r   e   d   e   e   p   p   p   p   p   p   p   p
//                                    r   r   h   e   |       |   e   w   i   t   m   e   i   x   i   x   n   e   e   e   e   e   e   e   e
//                                    B   u       g   |   |   |           t   m   a   c   t   t   t   t   u   T   M   V   T   E   L   T   H
//                                    a   m   |   m   |   |   |   |   |   m   a   p   G   e       T   L   T   e   e   a   e   d   o   i   o
//                                    r   e   |   e   |   |   |   |   |   a   p       r   r   |   e   i   e   x   n   r   x   i   g   m   u
//                                    g   n   |   n   |   |   |   |   |   p       |   a       |   x   s   x   t   u   i   t   t   V   e   r
//                                    r   t   |   t   |   |   |   |   |       |   |   p   |   |   t   t   t       T   a   L   T   i   D   s
//                                    a       |       |   |   |   |   |   |   |   |   h   |   |               |   e   b   i   e   e   a
//                                    p   |   |   |   |   |   |   |   |   |   |   |       |   |   |   |   |   |   x   l   s   x   w   t   |
//                                    h   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   t   e   t   t       e   |
//                                        |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |                   |       |
//                                    |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
//
// GS_TO_VISU_SET_FG_COLOR            X   X   X   X   X   X   X   X   X   X   X   X   |   X   X   X   X   X   X   X   X   X   X   X   X   X
// GS_TO_VISU_SET_BK_COLOR            X   |   X   X   |   |   |   |   |   |   |   |   |   |   X   X   X   X   X   X   X   X   X   |   X   X
// GS_TO_VISU_SET_SEL_FG_COLOR        |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   X   X   X   |   X   X   X   X   X   X   |
// GS_TO_VISU_SET_SEL_BK_COLOR        |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   X   X   X   |   X   X   X   X   |   X   |
// GS_TO_VISU_SET_ED_FG_COLOR         |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   X   X   |   |   |   X   X   X   X   X   |
// GS_TO_VISU_SET_ED_BK_COLOR         |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   X   X   |   |   |   X   X   X   |   X   |
// GS_TO_VISU_SET_SEL_FR_COLOR        |   X   |   |   |   |   |   |   |   |   X   X   |   |   |   X   X   X   |   X   X   X   X   |   X   |
// GS_TO_VISU_SET_ED_FR_COLOR         |   |   X   |   |   |   |   |   |   |   X   |   |   |   |   X   X   |   |   |   X   X   X   |   X   |
// GS_TO_VISU_SET_ED_CU_COLOR         |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   X   |   |   |   |   X   |   X   X   X   |
// GS_TO_VISU_SET_ED_SC_COLOR         |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   X   |   |
// GS_TO_VISU_SET_FILL_COLOR          |   X   |   |   |   X   X   X   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
// GS_TO_VISU_SET_OUTL_COLOR          |   X   X   |   |   X   X   X   X   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
// GS_TO_VISU_SET_OUTL_FG_COLOR       |   X   |   X   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
// GS_TO_VISU_SET_OUTL_BK_COLOR       |   X   |   X   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
// GS_TO_VISU_SET_SEL_FILL_COLOR      |   X   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
// GS_TO_VISU_SET_SEL_OUTL_COLOR      |   X   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
// GS_TO_VISU_SET_ED_FILL_COLOR       |   X   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
// GS_TO_VISU_SET_ED_OUTL_COLOR       |   X   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
// GS_TO_VISU_SET_GR_COLOR            |   |   X   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
// GS_TO_VISU_SET_OVR_FG_COLOR        X   X   X   X   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   X   |   |   |   |   |
// GS_TO_VISU_SET_OVR_BK_COLOR        X   X   X   X   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   X   |   |   |   |   |
// GS_TO_VISU_SET_OVR_GR_COLOR        |   |   X   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
// GS_TO_VISU_SET_UND_FG_COLOR        X   X   X   X   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   X   |   |   |   |   |
// GS_TO_VISU_SET_UND_BK_COLOR        X   X   X   X   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   X   |   |   |   |   |
// GS_TO_VISU_SET_UND_GR_COLOR        |   |   X   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
// GS_TO_VISU_SET_1ST_COLOR           |   |   |   |   |   |   |   |   X   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
// GS_TO_VISU_SET_2ND_COLOR           |   |   |   |   |   |   |   |   X   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
// GS_TO_VISU_SET_TRANS_COLOR         |   |   |   |   |   |   |   |   |   X   X   X   |   |   |   |   |   |   |   |   |   |   |   |   |   |
// GS_TO_VISU_SET_ORIGIN_X            X   X   X   X   X   X   X   X   X   X   X   X   X   X   X   X   X   X   X   X   X   X   X   X   X   X
// GS_TO_VISU_SET_ORIGIN_Y            X   X   X   X   X   X   X   X   X   X   X   X   X   X   X   X   X   X   X   X   X   X   X   X   X   X
// GS_TO_VISU_SET_P1_X                |   |   |   |   X   X   X   X   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
// GS_TO_VISU_SET_P1_Y                |   |   |   |   X   X   X   X   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
// GS_TO_VISU_SET_P2_X                |   |   |   |   X   |   X   X   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
// GS_TO_VISU_SET_P2_Y                |   |   |   |   X   |   X   X   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
// GS_TO_VISU_SET_P3_X                |   |   |   |   X   |   X   X   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
// GS_TO_VISU_SET_P3_Y                |   |   |   |   X   |   X   X   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
// GS_TO_VISU_SET_P4_X                |   |   |   |   X   |   X   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
// GS_TO_VISU_SET_P4_Y                |   |   |   |   X   |   X   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
// GS_TO_VISU_SET_ATTR_ALL            X   X   X   X   X   X   X   X   X   X   X   X   X   X   X   X   X   X   X   X   X   X   X   X   X   X
// GS_TO_VISU_SET_ATTR_INVERTED       |   |   |   |   |   X   X   X   |   |   |   |   |   |   X   X   X   X   X   X   X   X   X   |   X   X
// GS_TO_VISU_SET_ATTR_BLINK          X   X   X   X   X   X   X   X   X   X   X   X   X   X   X   X   X   X   X   X   X   X   X   X   X   X
// GS_TO_VISU_SET_ATTR_UNDERLINE      |   |   |   |   |   |   |   |   |   |   |   |   |   |   X   X   X   X   X   X   X   X   X   X   X   X
// GS_TO_VISU_SET_ATTR_VISIBLE        X   X   X   X   X   X   X   X   X   X   X   X   X   X   X   X   X   X   X   X   X   X   X   X   X   X
// GS_TO_VISU_SET_ATTR_TRANSPARENT    X   X   X   X   |   X   X   X   X   X   X   X   X   |   X   X   X   X   X   X   X   X   X   |   X   X
// GS_TO_VISU_SET_ATTR_SMOOTH         |   |   X   |   |   |   |   |   |   |   |   |   |   |   X   X   X   X   X   X   X   X   X   X   X   X
// GS_TO_VISU_SET_ATTR_AUTOSELECTNEXT |   X   X   |   |   |   |   |   |   |   X   X   |   |   |   X   X   X   |   X   X   X   X   |   X   |
// GS_TO_VISU_SET_ATTR_NOMINALFLAG    |   X   X   |   |   |   |   |   |   |   X   X   |   |   |   X   X   X   |   X   X   X   X   |   |   |
// GS_TO_VISU_SET_ATTR_LOWERBLINKFG   X   X   X   X   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   X   |   |   |   |   |
// GS_TO_VISU_SET_ATTR_UPPERBLINKFG   X   X   X   X   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   X   |   |   |   |   |
// GS_TO_VISU_SET_ATTR_LOWERBLINKBK   X   X   X   X   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   X   |   |   |   |   |
// GS_TO_VISU_SET_ATTR_UPPERBLINKBK   X   X   X   X   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   X   |   |   |   |   |
// GS_TO_VISU_SET_ATTR_GRABFOCUS      |   X   X   |   |   |   |   |   |   |   X   X   |   |   |   X   X   X   |   X   X   X   X   X   X   |
// GS_TO_VISU_SET_ATTR_UPDATEONEDIT   |   X   X   |   |   |   |   |   |   |   X   |   |   |   |   X   X   |   |   |   X   X   X   |   |   |
// GS_TO_VISU_SET_ATTR_ANIMATED       |   |   |   |   |   |   |   |   |   |   X   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
// GS_TO_VISU_SET_ATTR_ALIGN          |   |   |   |   |   |   |   |   |   |   |   |   |   |   X   |   X   X   |   |   |   |   |   |   |   |
// GS_TO_VISU_SET_ATTR_DRAWMODE       |   |   |   |   |   |   |   |   |   |   |   |   |   |   X   |   X   X   |   |   |   |   |   |   |   |
// GS_TO_VISU_SET_WIDTH               |   |   X   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
// GS_TO_VISU_SET_HEIGHT              |   |   X   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
// GS_TO_VISU_SET_ALTTXT1_FG_COLOR    |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   X   |   |   |   |   |
// GS_TO_VISU_SET_ALTTXT1_BK_COLOR    |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   X   |   |   |   |   |
// GS_TO_VISU_SET_ALTTXT2_FG_COLOR    |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   X   |   |   |   |   |
// GS_TO_VISU_SET_ALTTXT2_BK_COLOR    |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   X   |   |   |   |   |

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

#endif //GSLKFCODES_H_INCLUDED
//-----------------------------------------------------------------------------
//EOF
//-----------------------------------------------------------------------------

