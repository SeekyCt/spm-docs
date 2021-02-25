/*
    Camdrv handles the game's cameras
*/

typedef (CamDispFunc)(CamEntry * entry);

#define CAMFLAG_LoadBin 1

typedef struct {
/* 0x000 */ uint32_t flag;
/* 0x004 */ int cam_no;
/* 0x008 */ uint16_t cameraMode;
/* 0x00A */ // unknown 0xa-2f
/* 0x030 */ // unknown 0x30-33, param_5 of camEntryPersp
/* 0x034 */ // unknown 0x34-37, param_6 of camEntryPersp
/* 0x038 */ // unknown 0x38-93
/* 0x094 */ Mtx44 projMtx;
/* 0x0D4 */ // unknown 0xd4-ef
/* 0x0F0 */ float top;
/* 0x0F4 */ float bottom;
/* 0x0F8 */ float left;
/* 0x0FC */ float right;
/* 0x100 */ // unknown 0x100-157
/* 0x158 */ int isOrtho;
/* 0x15C */ Vec3 pos;
/* 0x168 */ Vec3 target;
/* 0x174 */ Vec3 up;
/* 0x180 */ // unknown 0x180-183
/* 0x184 */ float targetDistance;
/* 0x188 */ float fovY;
/* 0x18C */ float aspect;
/* 0x190 */ float near;
/* 0x194 */ float far;
/* 0x198 */ // unknown 0x198-253
/* 0x254 */ void * cameraRoad;
/* 0x258 */ CamDispFunc * dispFunc;
/* 0x25c */ // unknown 0x25c-2ef
} CamEntry; // total size 0x2ef

/*
    Cameras:
        0-4 unknown
        5 3d
        6-11 unknown
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
                         float param_6, int cam_no, CamDispFunc * callback); // 80054c00

/*
    Creates an orthographic camera
*/
CamEntry * camEntryOrtho(float top, float bottom, float left, float right, float near,
                         float far, int cam_no, CamDispFunc * callback); // 80054e60

// 800550f8 unknown function

/*
    Updates all cameras
*/
void camMain(); // 80055208

/*
    Updates each camera and calls dispDraw for it
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
CamEntry * camGetPtr(int id); // 80055b24

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

// a lot of unknown functions
