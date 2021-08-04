/*
    Icondrv handles the display of icons such as items and buttons
    Icon entries are handled by names, which must be unique, instead of pointers to entries
*/

#define MAX_ICONOBJ_NAME 16

typedef struct {
/* 0x00 */ u32 flags;
/* 0x04 */ Vec3 position;
/* 0x10 */ float scale;
/* 0x14 */ // unknown 0x14-23
/* 0x24 */ char name[MAX_ICONOBJ_NAME];
/* 0x34 */ s16 iconId;
/* 0x36 */ // unknown 0x36-7
/* 0x38 */ s32 offscreenId;
/* 0x3C */ // unknown 0x3c-e
/* 0x3F */ u8 alpha;
/* 0x40 */ // unknown 0x40-4b
} IconEntry; // total size 0x4c

typedef struct {
/* 0x00 */ s32 num; // 0x100
/* 0x04 */ IconEntry * entries; // array of num
/* 0x08 */ FileEntry * wiconTpl; // wicon.tpl from dvd root
/* 0x0C */ FileEntry * wiconbin; // wicon.bin from dvd root
} IconWork; // total size 0x10

IconWork iconWork; // 8050bac0
IconWork * iconWp; // 805adfd0

/*
    Initialise data used by icon functions
*/
void iconInit(); // 80072188
void iconReInit(); // 800721dc

/*
    Loads icon files if not loaded and displays icons
*/
void iconMain(); // 800721f4

/*
    Set up an icon to be displayed
*/
void iconEntry(const char * name, s32 iconId); // 80072710
void iconEntry2D(const char * name, s32 iconId); // 800729ac

/*
    Stops an icon being displayed
*/
void iconDelete(const char * name); // 80072c48

/*
    Renders an icon
*/
void iconDisp(s8 cameraId, IconEntry * entry); // 80072cdc

// 80072da0 unknown function

void iconDispGxAlpha(float scale, Vec3 * position, UNK param_3, s32 iconId, u8 alpha); // 80072ea8
void iconDispGx(float scale, Vec3 * position, UNK param_3, s32 iconId); // 800731b0
void iconDispGx2(Mtx34 * param_1, UNK param_2, s32 iconId); // 800731b8
void iconDispGxCol(Mtx34 * param_1, UNK param_2, s32 iconId, void * param_4); // 80073444
void iconGetTexObj(GXTexObj * dest, s32 iconId); // 800736b4
void iconGetTexObj2(GXTexObj * dest, s32 iconId, UNK param_3, UNK param_4); // 80073844
void iconGetWidthHeight(s16 * width, s16 * height, s32 iconId); // 80073898
void iconGX(Mtx34 * param_1, IconEntry * entry);
IconEntry * iconNameToPtr(const char * name); // 80074690
void iconSetPos(const char * name, float x, float y, float z); // 80074720
void iconFlagOn(const char * name, u32 flag); // 80074814
void iconFlagOn(const char * name, u32 flag); // 800748a0
void iconSetScale(const char * name, float scale); // 8007492c
void iconSetAlpha(const char * name, u8 alpha); // 800749d0
void iconNumberDispGx(Mtx34 * param_1, s32 number, s32 keta, UNK param_4, void * param_5, UNK param_6); // 80074a54 

// 80074f80, 80074fe8 unknown functions
