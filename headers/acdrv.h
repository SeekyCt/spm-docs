/*
    acdrv handles action commands for item usage (and possibly other things?)
*/

typedef void (AcFunc)(AcEntry * entry);
typedef void (AcDispFunc)(s8 camId, AcEntry * entry);

typedef struct {
    /*
        4 is require wii remote pointed at screen
        2 is paused
        1 is allocated
        Others unknown
    */
/* 0x00 */ u16 flags;
/* 0x02 */ // unknown 0x2-3
/* 0x04 */ s32 type;
/* 0x08 */ // unknown 0x8-f
/* 0x10 */ const char * name;
/* 0x14 */ s32 pausewinEntryId;
/* 0x18 */ s64 startTime;
/* 0x20 */ // unknown 0x20-27
/* 0x28 */ s32 state;
/* 0x2C */ AcFunc * initFunc;
/* 0x30 */ AcFunc * mainFunc;
/* 0x34 */ AcFunc * deleteFUnc;
/* 0x38 */ AcDispFunc * dispFunc;
/* 0x3C */ // unknown 0x3c-3f
} AcEntry; // total size 0x40

typedef struct {
/* 0x0 */ s32 num; // 4
/* 0x4 */ AcEntry * entries; // array of num length
} AcWork; // total size 0x8

AcWork acWork; // 8050a128
AcWork * acdrvWp; // 805adf50

typedef struct {
/* 0x00 */ AcFunc * initFunc;
/* 0x04 */ AcFunc * mainFunc;
/* 0x08 */ AcFunc * deleteFunc;
/* 0x0C */ AcDispFunc * dispFunc;
/* 0x10 */ const char * msgName;
} AcDef; // total size 0x14

AcDef acDefs[19]; // 80406ed8

SmartAllocation * acdrvLp; // 805ae7a0, unknown

/*
    Allocates entries
*/
void acInit(); // 8003eb4c

/*
    Clears entries
*/
void acReInit(); // 8003eba0

// 8003ebb8, 8003ec24 unknown functions

/*
    Updates entries based on their state, calls their mainFuncs and queues their dispFuncs
*/
void acMain(); // 8003ee44

/*
    Creates an acEntry based on the acDef of the type specified
    Types:
        0 - kirakira otoshi
        1 - pow block
        2 - barrier frame
        3 - koura de pon
        4 - kachikachi koura
        5 - biribiri kinoko
        6 - obake kinoko
        7 - nemure yoikoyo
        8 - stop watch
        9 - nemuri kaihuku
        10 - honoo sakuretsu
        11 - koori kaihuku
        12 - honoo sakuretsu 2
        13 - honoo sakuretsu 3
        14 - honoo sakuretsu 4
        15 - honoo sakuretsu 5
        16 - nomikomi kaihuku
        17 - jiwajiwa kinoko
        18 - koura de pon 2
*/
AcEntry * acEntry(s32 type); // 8003f388

// 8003f5d8 unknown function

/*
    Deletes an entry, calling its deleteFunc and deleting its pausewin entry
*/
void acDelete(AcEntry * entry); // 8003f5e0

/*
    Halts/unhalts all entries
*/
void acPauseAll(); // 8003f63c
void acUnpauseAll(); // 8003f67c

// 8003f6bc unknown function

/*
    Returns whether any entries are in use
*/
bool acIsRunning(); // 8003f730

/*
    Gets an entry by name
*/
AcEntry * acNameToPtr(const char * name); // 8003f780

/*
    Displays the message for the pausewin entry of an ac entry
*/
void acMsgDisp(PausewinEntry * entry); // 8003f818

// 8003f934, 8004077c, 80040dac, 80040eb4 unknown functions
