/*
    Fairy controls Pixl entities in game (except Tippi), as well as luvbi and squirps
*/

#define FAIRYRunEnd 7

enum FairyExtraNo {
    FAIRY_EXTRA_TAMARA = 0, // Squirps
    FAIRY_EXTRA_ANGEKO = 1 // Luvbi
};

// Returns an override for the name
typedef const char * (FairyAnimChangeHandler)(FairyEntry * fairy, const char * newAnimName);

typedef struct {
    /*
        1 is hide & disable all fairies
        Others unknown
    */
/* 0x00 */ u16 flag0;
    /*
        2 is anim changed
        1 is run mode changed
        Others unknown
    */
/* 0x02 */ u16 flag2;
/* 0x04 */ s32 itemId; // 0 for extra entries
/* 0x08 */ // unknown 0x8-b
/* 0x0C */ s32 animPoseId;
/* 0x10 */ const char * curAnimName;
/* 0x14 */ FairyAnimChangeHandler * animChangeHandler;
/* 0x18 */ RGBA materialEvtColor;
/* 0x1C */ // unknown 0x1c-27
    /*
        Run modes are from 0-6
        Currently unknown what each one is
    */
/* 0x28 */ s32 runMode;
/* 0x2C */ s32 prevRunMode;
/* 0x30 */ // unknown 0x30-47
/* 0x48 */ Vec3 position;
/* 0x54 */ // unknown 0x54-cf
} FairyEntry; // total size 0xd0

typedef struct {
/* 0x000 */ u32 flags;
/* 0x004 */ FairyEntry entries[4];
/* 0x344 */ s32 max; // 4
/* 0x348 */ s32 num;
/* 0x34C */ s32 numExtra;
/* 0x350 */ s32 extraNo; // see enum above
/* 0x354 */ // unknown 0x354-367
} FairyWork; // total size 0x368

FairyWork fairyWork; // 80510030
#define fairyFrp (&fairyWork)

const char * fairyExtraAnimPoseNames[2]; // 80426548

// 8011bc08, 8011c4d8, 8011c920, 8011ceb4,
// 8011d300, 8011d3bc, 8011d440 unknown functions

/*
    Creates a fairy entry for the currently selected pixl
*/
void fairyEntry(); // 8011d58c

/*
    Calls _fairyReInit
*/
void fairyReset(); // 8011d8f4

/*
    Clears fairy work
*/
void fairyInit(); // 8011d8f8

/*
    Calls _fairyReInit
*/
void fairyReInit(); // 8011d998

/*
    Updates a fairy entry
*/
void fairyUpdate(FairyEntry * thisFairy, FairyEntry * otherFairy); // 8011d99c

/*
    Calls fairyUpdate for each entry, first with otherFairy as
    NULL and then with it as every other fairy entry one by one
*/
void fairyMain(); // 8011de6c

/*
    Renders a fairy
*/
void fairyDisp(s8 camId, FairyEntry * fairy); // 8011df28

/*
    Does unknown calculations and schedules fairyDisp to run for this fairy this frame
*/
void fairyDispMain(FairyEntry * fairy); // 8011e418

/*
    Re-creates all fairys
*/
void _fairyReInit(); // 8011e5a8

/*
    Gets a fairy entry by id
*/
FairyEntry * fairyIdToPtr(s32 id); // 8011e8bc

/*
    Gets a fairy entry by item id
*/
FairyEntry * fairyItemIdToPtr(s32 itemId); // 8011e90c

/*
    Returns a pointer to the 'extra' FairyEntries
*/
FairyEntry * fairyGetExtra(); // 8011e970

/*
    Sets curAnimName to an new name, and allows animChangeHandler to override it
*/
void fairySetAnim(FairyEntry * fairy, const char * animName); // 8011e9b4

// 8011ea48 unknown function

/*
    Functions to change the current run mode of a fairy
*/
void fairyEnterRunMode(FairyEntry * fairy, s32 runMode); // 8011ea90
void fairyIdEnterRunMode(s32 id, s32 runMode); // 8011eb54
    // Less checks & clears flag2 0x1 instead of setting
void fairyEnterRunModeAlt(FairyEntry * fairy, s32 RunMode); // 8011ec58
void fairyIdEnterRunMode0(s32 id); // 8011ecf4
void fairyIdEnterRunMode1(s32 id); // 8011ed88
void fairyAllEnterRunMode0(); // 8011ee1c
void fairyAllEnterRunMode1(); // 8011eea8
void fairyIdEnterRunMode2(); // 8011ef38
void fairyAllEnterRunMode2(); // 8011f0a8

/*
    Sets position of all fairies
*/
void fairySetAllPositions(Vec3 * position); // 8011f258

// 8011f2d4, 8011f320 unknown functions

/*
    Returns a pointer to all FairyEntries
*/
FairyEntry * fairyGetEntries(); // 8011f36c

/*
    Returns how many normal/extra fairies there are
*/
s32 fairyGetNum(); // 8011f37c
s32 fairyGetNumExtra(); // 8011f38c

// 8011f39c, 8011f3b0, 8011f45c, 8011f534 unknown functions

/*
    Configures the animPose for this fairy based on entry fields
*/
void fairyUpdateAnimPose(FairyEntry * entry); // 8011f564

/*
    Sets the alpha of materialEvtColor
*/
void fairySetMaterialEvtAlpha(FairyEntry * entry, u8 alpha); // 8011f648

/*
    Creates a 'extra' fairy entry for the character specified by extra no
*/
void fairyExtraEntry(s32 extraNo); // 8011f6a0

/*
    Deletes the 'extra' fairy entry
*/
void fairyFreeExtra(); // 8011f958

/*
    Disable & hide / enable & unhide all fairies
*/
void fairyOff(); // 8011fa04
void fairyOn(); // 8011fa18
