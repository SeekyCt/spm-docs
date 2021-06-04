/*
    Fontmgr allows for text to be drawn on the screen
*/

/*
    Loads the font from disc
*/
void fontmgrInit(); // 8019ffb8

/*
    Sets up drawing a new string
*/  
void FontDrawStart(); // 801a0070

/*
    Sets up drawing a new string with custom transparency
    (setting the alpha in FontDrawColor's RGBA doesn't work correctly)
*/
void FontDrawStart_alpha(u8 alpha); // 801a0150

/*
    Control drawing a border around text
*/
void FontDrawEdge(); // 801a0228
void FontDrawEdgeOff(); // 801a0234

/*
    Control text changing colour over time
*/
void FontDrawRainbowColor(); // 801a0240
void FontDrawRainbowColorOff(); // 801a02e0

/*
    Control noise of text
*/
void FontDrawNoise(); // 801a02e8
void FontDrawNoiseOff(); // 801a03f4

/*
    Set the text colour to a pre-defined or custom one
*/
void FontDrawColorIDX(u32 idx); // 801a0420
void FontDrawColor(RGBA * color); // 801a04b8

void FontDrawColor_(); // 801a0554

/*
    Returns the current text colour
*/
RGBA FontGetDrawColor(); // 801a05dc

/*
    Sets the text scale
*/
void FontDrawScale(float scale); // 801a05e4

void FontDrawCode(float x, float y, u16 code); // 801a05fc
void FontDrawCodeMtx(float matrix[3][4], u16 code); // 801a0814

/*
    Draws a string of text at a position
*/
void FontDrawString(float x, float y, const char * string); // 801a09d4

void FontDrawStringVecPitch(float position[3], float pitch, const char * string); // 801a0a18
void FontDrawStringMtx(float matrix[3][4], const char * string); // 801a0de0
void FontDrawStringCenterMtx(float matrix[3][4], const char * string); // 801a11e0
void FontDrawMessage(s32 x, s32 y, const char * message); // 801a151c
void FontDrawMessageMtx(float matrix[3][4], const char * message); // 801a1d50
u16 hankakuSearch(u8 code); // 801a24d8
u16 kanjiSearch(u16 code); // 801a24e0
u8 kanjiGetWidth(u16 code); // 801a24e4
u16 FontGetMessageWidthLine(const char * message, u16 * outlines); // 801a255c

/*
    Returns the width a string will cover when drawn
*/
u16 FontGetMessageWidth(const char * message); // 801a28ac

u32 HSV2RGB(u8 hsv[3]); // 801a28b4

// more functions, unsure about them

int fontEdge; // 805ae990, 0 or 1
float fontScale[3]; // 805173a0
