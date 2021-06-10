/*
    windowdrv handles some of the game's UI
*/

typedef void (WindowFunc)(WindowEntry * entry);

typedef struct {
/* 0x00 */ // unknown 0x0-1
/* 0x02 */ u16 flags;
/* 0x04 */ u16 priority; // unsure
/* 0x06 */ // unknown 0x6-3b
/* 0x3C */ WindowFunc * mainFunc;
/* 0x40 */ WindowFunc * deleteFunc;
/* 0x44 */ // unknown 0x44-47
} WindowEntry; // total size 0x48

WindowEntry * windowWp; // array of 7

void windowInit(); // 800388b4
void windowReInit(); // 8003891c
s32 windowEntry(u16 priority); // 80038960, unsure of priority
void windowDelete(WindowEntry * entry); // 800389e8
void windowDeleteID(s32 id); // 80038a34
void windowMain(); // 80038aa0

// 80038b08, 80038cc0, 80038fb8, 80039188, 800393c8, 800396e0, 80039b80, 80039d40, 8003a440, 8003a5e4 unknown functions

void windowDispGX2_Waku_col(float x, float y, float width, float height, Mtx * mtx, u32 gxTexMapId, RGBA * colour); // 8003ab80
bool windowCheckID(s32 id); // 8003b158
WindowEntry * windowGetPointer(s32 id); // 8003b170

// 8003b180 unknown function 
