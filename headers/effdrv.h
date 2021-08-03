/*
    effdrv handles effect animations
*/

typedef void (EffFunc)(EffEntry * entry);

typedef struct {
    /*
        4 soft deleted
        1 active
    */
/* 0x00 */ u16 flags;
/* 0x02 */ u16 type; // 0 or 1, groups entries for limits
/* 0x04 */ s32 releaseType; // 0 or 1, groups entries for freeing (1 means 'in battle', unused TTYD leftover)
/* 0x08 */ // unknown 0x8-b
/* 0x0C */ void * userWork;
/* 0x10 */ EffFunc * mainFunc;
/* 0x14 */ // unknown 0x14-17
/* 0x18 */ char instanceName[16];
/* 0x28 */ // unknown 0x28-2b
} EffEntry; // total size 0x2c

typedef struct {
/* 0x0 */ s32 curCount; // current number of active entries of this type
/* 0x4 */ s32 maxCount; // maximum number of active entries of this type allowed
} EffTypeStats; // total size 0x8

typedef struct {
/* 0x000 */ s32 entryCount;
/* 0x004 */ EffEntry * entries; // array of entryCount length
/* 0x008 */ FileEntry * effectTpl;
/* 0x00C */ FileEntry * effectN64Tpl;
/* 0x010 */ // unknown 0x10-11b
/* 0x11C */ EffTypeStats typeStats[2];
/* 0x12C */ // unknown 0x12c-134
} EffWork; // total size 0x134

EffWork effWork; // 8050b820
EffWork * effdrvWp; // 805adf90

/*
    Allocates entries
*/
void effInit(); // 800614e0

/*
    Gets a tex obj for a texture in the effect TPL
*/
void effGetTexObj(s32 id, GXTexObj * out); // 80061588

// 800615cc unknown function

/*
    Gets a tex obj for a texture in the effect N64 TPL
*/
void effGetTexObjN64(s32 id, GXTexObj * out); // 800615e0

/*
    Frees all entries of the specified release type
*/
void effAutoRelease(s32 releaseType); // 80061624

/*
    Creates an entry of type 0
*/
EffEntry * effEntry(); // 800616dc

/*
    Creates an entry of the specified type
*/
EffEntry * effEntryType(s32 type); // 800616e4

/*
    Sets the name of an entry
*/
void effSetName(const char * name); // 800617fc

/*
    Loads TPLs if not loaded, calls effSubMain and calls the mainFunc of each entry
*/
void effMain(); // 800618b0

// 80061a34, 80061a44 unknown functions

/*
    Delete an entry
*/
void effDelete(EffEntry * entry); // 80061a74
void effSoftDelete(EffEntry * entry); // 80061af4

/*
    Gets an entry by name
*/
EffEntry * effNameToPtr(const char * name); // 80061b90

// 80061c28, 80061cd0, 80061d78, 80061e18,
// 80061eb8, 800623f8, 80062d04, 80062f9c,
// 800630b8, 80063130, 80063198, 800631a4,
// 800631ac, 800631b8, 80063308, 80063374,
// 8006339c, 800633fc unknown functions
