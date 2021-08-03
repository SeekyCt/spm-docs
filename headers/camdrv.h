/*
    Camdrv handles the game's cameras
*/

typedef (CamDispFunc)(CamEntry * entry);

#define CAMFLAG_LoadBin 1

typedef struct {
    /*
        0x10000000 16:9
        Others unknown
    */
/* 0x000 */ u32 flag;

/* 0x004 */ s32 cam_no;
/* 0x008 */ u16 cameraMode;
/* 0x00A */ // unknown 0xa-2f
/* 0x030 */ // unknown 0x30-33, param_5 of camEntryPersp
/* 0x034 */ // unknown 0x34-37, param_6 of camEntryPersp
/* 0x038 */ // unknown 0x38-53
/* 0x054 */ Mtx34 viewMtx;
/* 0x084 */ // unknown 0x94-93
/* 0x094 */ Mtx44 projMtx;
/* 0x0D4 */ // unknown 0xd4-ef
/* 0x0F0 */ float top;
/* 0x0F4 */ float bottom;
/* 0x0F8 */ float left;
/* 0x0FC */ float right;
/* 0x100 */ // unknown 0x100-157
/* 0x158 */ s32 isOrtho;
/* 0x15C */ Vec3 pos;
/* 0x168 */ Vec3 target;
/* 0x174 */ Vec3 up;
/* 0x180 */ // unknown 0x180-183
/* 0x184 */ float targetDistance;
/* 0x188 */ float fovY;
/* 0x18C */ float aspect;
/* 0x190 */ float near;
/* 0x194 */ float far;
/* 0x198 */ // unknown 0x198-20b
/* 0x20C */ Vec3 zoomStartPos;
/* 0x218 */ Vec3 zoomStartTarget;
/* 0x224 */ Vec3 zoomDestPos;
/* 0x230 */ Vec3 zoomDestTarget;
/* 0x23C */ // unknown 0x23c-23f
/* 0x240 */ s64 zoomStartTime;
/* 0x248 */ // unknown 0x248-253
/* 0x254 */ void * cameraRoad;
/* 0x258 */ CamDispFunc * dispFunc;
/* 0x25C */ // unknown 0x25c-2ef
} CamEntry; // total size 0x2ef

/*
    Cameras:
        0-4 unknown
        5 3d
        6-10 unknown
        11 2d
        12 fade
        13 dbg
        14 dbg3d
*/
CamEntry * camPtrTbl[15]; // 8050b580

/*
    Creates all camera entries and initialises other data used by camdrv
*/
void camInit(); // 80054804

/*
    Creates a perspective camera
*/
CamEntry * camEntryPersp(float fovY, float aspect, float near, float far, float param_5,
                         float param_6, s32 cam_no, CamDispFunc * callback); // 80054c00

/*
    Creates an orthographic camera
*/
CamEntry * camEntryOrtho(float top, float bottom, float left, float right, float near,
                         float far, s32 cam_no, CamDispFunc * callback); // 80054e60

// 800550f8 unknown function

/*
    Updates all cameras
*/
void camMain(); // 80055208

/*
    Calls dispDraw for each camera
*/
void camDraw(); // 800556f4

/*
    Loads a camera road file from disc asynchronously, returns whether it's done
*/
bool camLoadRoadAsync(const char * mapName); // 8005583c

/*
    Loads a camera road file that's already been read from disc
*/
void camLoadRoadNoRead(void * file); // 800559ac

/*
    Unloads a camera road file
*/
void camUnloadRoad(); // 80055a60

/*
    Returns a camera by cam_no
*/
CamEntry * camGetPtr(s32 id); // 80055b24

/*
    Returns the current camera
*/
CamEntry * camGetCurPtr(); // 80055b38

/*
    Returns the current cam_no
*/
CamEntry * camGetCurNo(); // 80055b50

// 80055b58, 80055bb4, 80055c10, 80055ce0, 80056948 unknown functions

/*
    CamDispFunc for the 3d camera
*/
void cam3dMain(CamEntry * cp); // 80056a60

// 80057cb0, 80057cc8, 80057ce0, 80057da0,
// 80057e4c, 80057ec4, 80057ee8, 80058128 unknown functions

/*
    Converts coordinates in the world to where they appear on screen
*/
void getScreenPoint(Vec3 * worldPos, Vec3 * screenPosOut); // 80058294
