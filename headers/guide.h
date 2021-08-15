/*
    Guide controls Tippi & Tiptron
*/

#define GUIDERunEnd 6

// Returns an override for the name
typedef const char * (GuideAnimChangeHandler)(const char * newAnimName);

typedef struct {
    /*
        0x80 is hide & disable Tippi
        Others unknown
    */
/* 0x00 */ u16 flag0;
    /*
        All unknown
    */
/* 0x02 */ u8 flag2;
    /*
        0x2 is anim changed
        0x1 is run mode changed
        Others unknown
    */
/* 0x03 */ u8 flag3;
/* 0x03 */ // unknown 0x4-7
/* 0x08 */ s32 animPoseId;
/* 0x0C */ char curAnimName[4];
/* 0x10 */ // unknown 0x10-1b
/* 0x1c */ GuideAnimChangeHandler * animChangeHandler;
    /*
        Run modes are from 0-5
        Currently unknown what each one is
    */
/* 0x20 */ s32 runMode;
/* 0x24 */ s32 prevRunMode;
/* 0x28 */ // unknown 0x28-3f
/* 0x40 */ Vec3 pos;
/* 0x4C */ // unknown 0x4c-b3
} GuideWork; // total size 0xb4

GuideWork guideWork; // 80510398

typedef void (GuideRunModeFunc)(GuideWork * work);

GuideRunModeFunc * guideRunModeMainFuncs[6]; // 80426590

/*
    Returns a pointer to guideWork
*/
GuideWork * guideGetWork(); // 8011fa2c

/*
    Clears guideWork and sets animPoseId to -1
*/  
void guideInit(); // 8011fa38

/*
    Loads the model and does other unknown tasks
*/
void guideReInit(); // 8011fa7c

/*
    Updates and calls the main func for this runMode
*/
void guideMain(); // 8011fcd4

/*
    Does unknown calculations and schedules guideDisp to run this frame
*/
void guideDispMain(); // 8011feb0

/*
    Renders Tippi/Tiptron
*/
void guideDisp(GuideWork * work); // 8012003c

/*
    Functions ran every frame based on the current runMode
*/
void runMode0Main(GuideWork * work); // 801202c4
void runMode1Main(GuideWork * work); // 80120360
void runMode2Main(GuideWork * work); // 8012040c
void runMode3Main(GuideWork * work); // 80120d08
void runMode4Main(GuideWork * work); // 8012107c
void runMode5Main(GuideWork * work); // 801213f0

// 801215f0, 8012167c, 80121900, 80121948 unknown functions

/*
    Sets curAnimName to an new name, and allows animChangeHandler to override it
*/
void guideSetAnim(const char * name); // 80121990

/*
    Functions to change the current run mode
*/
void guideEnterRunMode(int runMode); // 80121a0c
void guideEnterRunMode1(); // 80121aa4
void guideEnterRunMode2(); // 80121adc
void guideEnterRunMode5(float, float, Vec3 *); // 80121b28

// 80121ba4, 80121bc8, 80121bcc, 80121d34,
// 80121d84, 80121db4, 80121e18 unknown functions
