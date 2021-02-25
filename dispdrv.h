/*
    Dispdrv is a wrapper for functions that can draw to the screen
*/

#define DISP_ZOFFSET 100000.0
#define MAX_SCISSOR_NO 32

typedef void (DispCallback)(int8_t cameraId, void * param);

typedef struct {
/* 0x0 */ int8_t cameraId;
/* 0x1 */ int8_t renderMode;
/* 0x2 */ // unknown 0x2-3
/* 0x4 */ float order;
/* 0x8 */ DispCallback * callback;
/* 0xC */ void * callbackParam;
} DispWork; // total size 0x10

DispWork * dispCurWork; // 805ae7d4
DispWork * pDispWork; // 805ae7c8, array of 2048
DispWork ** pSortWork; // 805ae7c8, array of 2048
int entry_n; // 805ae7d0

/*
    Initialise data used by dispdrv functions
*/
void dispInit(); // 8005aea4
void dispReInit(); // 8005aef4

/*
    Register a function to be displayed this frame
*/
void dispEntry(float z, int8_t cameraId, int8_t renderMode, DispCallback * callback, void * callbackParam); // 8005af04

// 8005b088, 8005b0dc unknown functions

bool _sort(DispEntry ** lhs, DispEntry ** rhs); // 8005b158
void dispSort(); // 8005b188

/*
    Runs every entry's callback
*/
void dispDraw(int cameraId); // 8005b1a0

float dispCalcZ(float param_1); // 8005b46c

/*
    Returns the DispWork currently being executed
*/
DispWork * dispGetCurWork(); // 8005b524
