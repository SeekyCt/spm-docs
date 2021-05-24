/*
    spmario handles various general game tasks
    In TTYD, this file was named mariost

    Note: this file has some progress in the decomp, see the link in README
*/

/*
    The SpMarioGlobals struct contains various global variables used throughout the game
    This struct, with a few exceptions, is copied in full to & from the save file
*/
typedef struct {
/* 0x0000 */ uint32_t flags;
/* 0x0004 */ int fps; // not read from save file
/* 0x0008 */ int language; // not read from save file
/* 0x000C */ // unknown 0xc-f
/* 0x0010 */ uint32_t systemLevelFlags;
/* 0x0014 */ // unknown 0x14-17
/* 0x0018 */ uint16_t efbWidth;
/* 0x001A */ uint16_t efbHeight;
/* 0x001C */ // unknown 0x1c-1f
/* 0x0020 */ char saveName[32];
/* 0x0040 */ // unknown 0x40-43, not read from save file
/* 0x0044 */ char mapName[32];
/* 0x0064 */ char doorName[32];
/* 0x0084 */ char gameOverMapName[32];
/* 0x00A4 */ char prevMapName[32];
/* 0x00C4 */ // unknown 0xc4-c7
/* 0x00C8 */ int64_t lastSaveWriteTime;
/* 0x00D0 */ Vec3 savePosition;
/* 0x00DC */ int saveFileNum;
/* 0x00E0 */ // unknown 0xe0-e3, not read from save file
/* 0x00E4 */ // unknown 0xe4-f8
/* 0x00F8 */ int64_t time;
/* 0x0100 */ // unknown 0x100-10f
/* 0x0110 */ int64_t lastSaveLoadTime;
/* 0x0118 */ // unknown 0x118-137
/* 0x0138 */ int64_t lastButtonPressTime; // uncertain
/* 0x0140 */ int gsw0; // first GSW is a full word
/* 0x0144 */ uint32_t gswf[256]; // 8192 flags
/* 0x0544 */ int8_t gsw[2048]; // index 0 unused in favour of gsw0
/* 0x0d44 */ uint32_t lswf[16]; // 512 flags
/* 0x0d84 */ int8_t lsw[1024];
/* 0x1184 */ // unknown 0x1184-1aff
/* 0x1b00 */ bool disableRumble[4]; // overrides to force off wpadmgr's enableRumble, index controller id
/* 0x1b04 */ // unknown 0x1b04-1b07
} SpMarioGlobals;

SpMarioGlobals * gp; // 805ae178
SpMarioGlobals spMarioGlobals; // 80525550

/*
    First function to be ran in the game's main function, calls most other init functions
*/
void spmarioInit(); // 801a7ddc

/*
    Called every frame in the game's main function, calls most other main functions
*/
void spmarioMain(); // 801a84d8

/*
    Called every frame in the game's main function, main display-handling task
*/
void spmarioDisp(); // 801a8748

/*
    Sets the system level, which controls enabling various things like script execution and player movement
*/
void spmarioSystemLevel(int level); // 801a8770

/*
    Returns the current system level
*/
int spmarioGetSystemLevel(); // 801a87ec

void viPostCallback(); // 801a87f4
void wiiDvdCheckThread(); // 801a898c
void wiiRumbleCheck(); // 801a8db4

// 801a9068, 801a9074, 801a9080, 801a908c unknown functions
