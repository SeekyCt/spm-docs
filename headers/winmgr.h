/*
    winmgr is a higher level wrapper for windowdrv
*/

typedef struct {
/* 0x00 */ // unknown 0x0-7
/* 0x08 */ s32 cameraId;
/* 0x0C */ s32 size1;
/* 0x10 */ s32 size2;
/* 0x14 */ s32 size3;
/* 0x18 */ s32 size4;
/* 0x1C */ // unknown 0x1c-1f
/* 0x20 */ void * mainFunc;
/* 0x24 */ void * deleteFunc;
} WindowDesc; // total size 0x28

typedef struct {
/* 0x00 */ u32 flags;
/* 0x04 */ // unknown 0x4-f
/* 0x10 */ float scale;
/* 0x14 */ // unknown 0x14-17
/* 0x18 */ s32 size1;
/* 0x1C */ s32 size2;
/* 0x20 */ s32 size3;
/* 0x24 */ s32 size4;
/* 0x28 */ WindowDesc * desc;
/* 0x2C */ UNK param;
/* 0x30 */ s32 priority;
} WinmgrEntry; // total size 0x34

typedef struct {
/* 0x0 */ s32 entryCount; // 0x20
/* 0x4 */ WinmgrEntry * entries; // array of entryCount
} WinmgrWork; // total size 0x8

void winMgrInit(); // 8003b26c
void winmgrReInit(); // 8003b2b0
void winMgrDisp(s32 cameraId, WinmgrEntry * entry); // 8003b2c8
void winMgrMain(); // 8003b6b4
void winMgrSeq(WinmgrEntry * entry); // 8003b7a8
void winMgrEntry(WindowDesc * desc); // 8003baa4
void winMgrSetParam(UNK param); // 8003bb88
void winMgrOpen(s32 id); // 8003bba8
void winMgrCloseAutoDelete(s32 id); // 8003bbd8
void winMgrAction(s32 id); // 8003bc14
void winMgrSetSize(s32 id, s32 size1, s32 size2, s32 size3, s32 size4); // 8003bc2c
void winMgrSetPriority(s32 id, s32 priority); // 8003bc58

// 8003bc78, 8003c8a8, 8003c90c, 8003c9d0, 8003c9d8, 8003d2ac, 8003e5e0, 8003e954 unknown functions
