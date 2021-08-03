/*
    Dispdrv is a wrapper for functions that can draw to the screen
*/

#define DISP_ZOFFSET 100000.0
#define MAX_SCISSOR_NO 32

typedef void (DispCallback)(s8 cameraId, void * param);

typedef struct {
/* 0x0 */ s8 cameraId;
/* 0x1 */ s8 renderMode;
/* 0x2 */ // unknown 0x2-3
/* 0x4 */ float order;
/* 0x8 */ DispCallback * callback;
/* 0xC */ void * callbackParam;
} DispEntry; // total size 0x10

DispEntry * dispCurWork; // 805ae7d4
DispEntry * pDispEntry; // 805ae7c8, array of 2048
DispEntry ** pSortWork; // 805ae7c8, array of 2048
s32 entry_n; // 805ae7d0

typedef struct {
/* 0x0 */ // unknown 0x0-f
} DispScissor; // total size 0x10

DispScissor dispScissors[0x20]; // 8050b620

/*
    Initialise data used by dispdrv functions
*/
void dispInit(); // 8005aea4
void dispReInit(); // 8005aef4

/*
    Register a function to be displayed this frame
*/
void dispEntry(float z, s8 cameraId, s8 renderMode, DispCallback * callback, void * callbackParam); // 8005af04

void dispSetCurScissor(s32 scissorNo); // 8005b088
void dispSetScissor(s32 id, UNK field_0, UNK field_4, UNK field_8, UNK field_c); // 8005b0dc

bool _sort(DispEntry ** lhs, DispEntry ** rhs); // 8005b158
void dispSort(); // 8005b188

/*
    Runs every entry's callback
*/
void dispDraw(s32 cameraId); // 8005b1a0

float dispCalcZ(float param_1); // 8005b46c

/*
    Returns the DispEntry currently being executed
*/
DispEntry * dispGetCurWork(); // 8005b524

// 8005b52c unknown function
