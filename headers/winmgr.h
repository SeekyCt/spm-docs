/*
    winmgr is a higher level wrapper for windowdrv
*/

typedef void (WinmgrFunc)(WinmgrEntry * entry);

typedef struct {
/* 0x00 */ // unknown 0x0-7
/* 0x08 */ s32 cameraId;
/* 0x0C */ Vec2i pos;
/* 0x14 */ Vec2i scale;
/* 0x1C */ // unknown 0x1c-1f
/* 0x20 */ WinmgrFunc * mainFunc;
/* 0x24 */ WinmgrFunc * deleteFunc;
} WindowDesc; // total size 0x28

typedef struct {
/* 0x0 */ u16 entryCount; // number of winmgr entries to create
/* 0x2 */ // padding 0x2-3
/* 0x4 */ WindowDesc * descs; // array of entryCount
} WinmgrSelectDesc; // total size 0x8

WindowDesc select_desc[2]; // 80406d80
WindowDesc select_recipe_desc[3]; // 80406dd0, 3rd is unused
WindowDesc select_card_desc[2]; // 80406e48
WinmgrSelectDesc select_desc_tbl[8]; // 80406e98, index is winmgr select type

typedef struct {
/* 0x0 */ s16 itemId;
/* 0x2 */ // unknown 0x2-3
/* 0x4 */ s32 animPoseId;
/* 0x8 */ // unknown 0x8-b
} WinmgrItem; // total size 0xc

typedef struct {
/* 0x00 */ u32 flags;
/* 0x04 */ // unknown 0x4-7
/* 0x08 */ s32 typeOrItemTable;
/* 0x0C */ // unknown 0xc-f
/* 0x10 */ s32 selectedItemIdx; // index into item table currently hovered over
/* 0x14 */ // unknown 0x14-17
/* 0x18 */ Vec2 pos;
/* 0x20 */ // unknown 0x20-23
/* 0x24 */ s32 entryCount; // number of winmgr entries
/* 0x28 */ s32 entryIds[3]; // winmgr entry ids
/* 0x34 */ s32 pausewinId; // id for pausewin entry drawing background box
/* 0x38 */ WinmgrSelectItem * items;
/* 0x3C */ s32 itemCount;
/* 0x40 */ s32 extraItem;
/* 0x44 */ // unknown 0x44-6b
} WinmgrSelect; // total size 0x6c

typedef struct {
    /*
        8 is scheduled for deletion
        1 is active
        Others unknown
    */
/* 0x00 */ u32 flags;
/* 0x04 */ // unknown 0x4-f
/* 0x10 */ float scalarScale;
/* 0x14 */ // unknown 0x14-17
/* 0x18 */ Vec2i pos;
/* 0x20 */ Vec2i scale;
/* 0x28 */ WindowDesc * desc;
/* 0x2C */ void * param; // for select windows, pointer to WinmgrSelect
/* 0x30 */ s32 priority;
} WinmgrEntry; // total size 0x34

typedef struct {
/* 0x0 */ s32 entryCount; // 0x20
/* 0x4 */ WinmgrEntry * entries; // array of entryCount
} WinmgrWork; // total size 0x8

WinmgrWork winmgrWork; // 8050a120
WinmgrWork * winmgrWp; // 805adf48

/*
    Allocates entries
*/
void winMgrInit(); // 8003b26c

/*
    Clears entries
*/
void winmgrReInit(); // 8003b2b0

/*
    Displays a window & calls its disp func
*/
void winMgrDisp(s32 cameraId, WinmgrEntry * entry); // 8003b2c8

/*
    Calls winMgrSeq on each entry & its main func, and schedules winMgrDisp for each func
*/
void winMgrMain(); // 8003b6b4

void winMgrSeq(WinmgrEntry * entry); // 8003b7a8

/*
    Creates an entry from a desc and returns its id
*/
s32 winMgrEntry(WindowDesc * desc); // 8003baa4

/*
    Sets user data parameter for a window
*/
void winMgrSetParam(void * param); // 8003bb88

/*
    Opens a window
*/
void winMgrOpen(s32 id); // 8003bba8

/*
    Closes a window and schedules it to be deleted
*/
void winMgrCloseAutoDelete(s32 id); // 8003bbd8

/*
    Checks the action flag of a window
*/
void winMgrAction(s32 id); // 8003bc14

/*
    Sets the position and scale of a window
*/
void winMgrSetSize(s32 id, s32 posX, s32 posY, s32 scaleX, s32 scaleY); // 8003bc2c

/*
    Sets the priority of a window
*/
void winMgrSetPriority(s32 id, s32 priority); // 8003bc58

/*
    Creates an item selection window

    Type values: 
        0 is keyItem selection
        1 is useItem selection
        2 is useItem sale
        3 is useItem store
        4 is shopItem pickup
        5 is card selection
        6 is card sale
        7 is recipes selection 
    Type can also be a pointer to a list of s32 item ids terminated by -1 (uses type 0's properties)

    Extra item is added at the start of the list
*/
WinmgrSelect * winMgrSelectEntry(s32 type, s32 extraItem, u32 flags); // 8003bc78

/*
    Get the resulting item id of a selection window
    -1 means the user backed out
    0 means undecided
*/
s32 winMgrSelect(WinmgrSelect * select); // 8003c8a8


/*
    Deletes a selection window
*/
void winMgrSelectDelete(WinmgrSelect * select); // 8003c90c

/*
    Returns the index of the item currently selected
*/
s32 winMgrSelectGetIndex(WinmgrSelect * select); // 8003c9d0

/*
    WindowDesc.mainFunc/dispFuncs for a WinmgrSelect window
    Update & draw the main window
*/
void select_main(WinmgrEntry * entry); // 8003c9d8
void select_disp(WinmgrEntry * entry); // 8003d2ac

/*
    Displays the instruction to choose one
*/
void select_disp2(WinmgrEntry * entry); // 8003e5e0

/*
    Unused function to display "msg_window_item_cancel"
    This message is defined twice, as either a go back with 1 or 
    select with 2 instruction
    Seems to have originally been intended for recipe selection
*/
void select_disp3(WinmgrEntry * entry); // 8003e954
