/*
    casedrv runs scripts when the player interacts with certain HitObjs
*/

typedef struct {
/* 0x00 */ u16 flags;
/* 0x02 */ // unknown 0x2-3
    // Touching a HitObj with either name triggers the script
/* 0x04 */ const char * name;
/* 0x08 */ const char * name2;
/* 0x0C */ // unknown 0xc-f
/* 0x10 */ s32 lw[16]; // copied into script's LW on run
/* 0x50 */ // unknown 0x50-53
/* 0x54 */ EvtScriptCode * script;
/* 0x58 */ s32 scriptPriority;
} CaseEntDef; // total size 0x5c

typedef struct {
    /*
        0x10 is script running this frame
        0x1 is active
        Others unknown
    */
/* 0x00 */ u16 flags
/* 0x02 */ // unknown 0x2-3
/* 0x04 */ s32 type; // controls the action & type of HitObj required
/* 0x08 */ char name[64];
/* 0x48 */ char name2[64];
/* 0x88 */ s32 id;
/* 0x8C */ UNK def_0xc; // 0xc-f from CaseEntDef
/* 0x90 */ s32 lw[16];
/* 0xD0 */ s32 evtId;
/* 0xD4 */ EvtScriptCode * script;
/* 0xD8 */ s32 scriptPriority;
} CaseEntry; // total size 0xdc

typedef struct {
/* 0x0 */ s32 n;
/* 0x4 */ CaseEntry * entries; // array of n length
/* 0x8 */ // unknown 0x8-f
} CaseWork; // total size 0x10

CaseWork caseWork; // 8050b610
CaseWork * casedrvWp; // 805adf88

/*
    Allocates entries
*/
void caseInit(); // 80058d58

/*
    Clears entries
*/
void caseReInit(); // 80058da8

/*
    Creates an entry from a CaseEntDef and returns its id
*/
s32 caseEntry(CaseEntDef * def); // 80058de8

/*
    Deletes an entry by id
*/
void caseDelete(s32 id); // 80059108

// 80059268 unknown function

/*
    Updates all entries
*/
void caseMain(); // 800595dc

/*
    Returns an entry by its HitObj
*/
CaseEntry * caseCheckHitObj(HitObj * hitObj); // 8005abe4
CaseEntry * caseCheckHitObj2(HitObj * hitObj); // 8005acf8

/*
    Returns an entry by id
*/
CaseEntry * caseIdToPtr(s32 id); // 8005adcc

// 8005adec, 8005ae08, 8005ae24, 8005ae64 unknown functions
