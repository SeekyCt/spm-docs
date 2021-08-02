/*
    windowdrv handles some of the game's UI
*/

typedef void (WindowFunc)(WindowEntry * entry);

typedef struct {
/* 0x00 */ // unknown 0x0-1
    /*
        1 active
        Others unknown
    */
/* 0x02 */ u16 flags;
/* 0x04 */ u16 priority;
/* 0x06 */ // unknown 0x6-7
    /*
        0 - normal
        1 - small (used for crowds shouting)
        2 - sign
        3 - system
        4 - sign 2
        5 - selection
        6 - TTYD dragon style (unused?)
        7 - written on letter (used for intermission texts)
        8 - purple (used by spider Mimi)
        9 - computer
        10 - invisible (just text)
        11 - pixl
        12 - Tiptron
        13 - alternate system (used in underchomp battle)
        14 - invisible with alternate icon (using in Francis dating)
        15 - alternate selection (used in Francis dating)
    */
/* 0x08 */ s32 type;
/* 0x0C */ Vec2 pos;
/* 0x14 */ Vec2 scale;
/* 0x1C */ // unknown 0x1c-1f
/* 0x20 */ s64 lastUpdateTime;
/* 0x28 */ SmartAllocation * speakerSp; // smart pointer to MsgSpeaker
/* 0x2C */ // unknown 0x2c-2f
/* 0x30 */ Vec3 speakerPos;
/* 0x3C */ WindowFunc * mainFunc;
/* 0x40 */ WindowFunc * deleteFunc;
/* 0x44 */ // unknown 0x44-47
} WindowEntry; // total size 0x48

WindowEntry * windowWp; // array of 7

/*
    Allocates & clears entries
*/
void windowInit(); // 800388b4

/*
    Clears entries
*/
void windowReInit(); // 8003891c

/*
    Creates an empty window
*/
s32 windowEntry(u16 priority); // 80038960

/*
    Delete window entry
*/
void windowDelete(WindowEntry * entry); // 800389e8
void windowDeleteID(s32 id); // 80038a34

/*
    Call mainFunc for all active entries
*/
void windowMain(); // 80038aa0

// 80038b08, 80038cc0, 80038fb8 unknown functions

/*
    Draws the background for a sign message
*/
void windowDispGX_Kanban(float x, float y, float width, float height, s32 type, RGBA * colour); // 80039188

// 800393c8 unknown function

/*
    Draws the background for a system message
*/
void windowDispGX_System(float x, float y, float width, float height, s32 type, u8 alpha); // 800396e0

// 80039b80, 80039d40 unknown functions

/*
    Draws the background for a regular message
*/
void windowDispGX_Message(float x, float y, float width, float height, float, float, s32 type, UNK, u8 alpha); // 8003a440

/*
    Draws the background for an item list
*/
void windowDispGX_ItemBox(float x, float y, float width, float height, UNK, RGBA * colour); // 8003a5e4

/*
    Draws a solid colour rectangle with a black border
*/
void windowDispGX2_Waku_col(float x, float y, float width, float height, Mtx * mtx, u32 gxTexMapId, RGBA * colour); // 8003ab80

/*
    Checks flag & 2 for a window
*/
bool windowCheckID(s32 id); // 8003b158

/*
    Returns a window by id
*/
WindowEntry * windowGetPointer(s32 id); // 8003b170

/*
    Returns whether any window is open, excluding type 1
*/
bool windowCheckOpen(); // 8003b180 unknown function
