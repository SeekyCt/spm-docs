/*
    mobjdrv handles 'map objects' such as question blocks and save blocks
*/

typedef void (MobjUpdateFunc)(MobjEntry * entry);

typedef struct {
    /*
        0x10000000 is grabbable with Thoreau
        0x1 is active
        Others unknown
    */
/* 0x000 */ u32 flag0;
/* 0x004 */ u32 flag4;
/* 0x008 */ char instanceName[16];
/* 0x018 */ Vec3 pos;
/* 0x024 */ Vec3 scale;
/* 0x030 */ Vec3 rotation;
/* 0x03C */ // unknown 0x3c-47
/* 0x048 */ s32 animPoseId;
/* 0x04C */ // unknown 0x4c-5b
    /*
        These are likely an array of structs, but the exact boundaries are unknown
    */
/* 0x05c */ HitObj * joint1_HitObj; // see hitdrv.h
/* 0x060 */ char joint1_Name[16];
/* 0x070 */ // unknown 0x70-77
/* 0x078 */ MapFileJoint joint1; // see mapdrv.h
/* 0x0E0 */ // unknown 0xe0-e3
/* 0x0E4 */ HitObj * joint2_HitObj;
/* 0x0E8 */ char joint2_Name[16];
/* 0x0F8 */ // unknown 0xf8-100
/* 0x100 */ MapFileJoint joint2;
/* 0x168 */ // unknown 0x168-16b
/* 0x16C */ HitObj * joint3_HitObj;
/* 0x170 */ char joint3_Name[16];
/* 0x180 */ // unknown 0x180-187
/* 0x188 */ MapFileJoint joint3;
/* 0x1F0 */ // unknown 0x1f0-20f
/* 0x210 */ union {
/*       */     DropItem * items; // see npcdrv.h
/*       */     s32 item;
/*       */ }
/* 0x214 */ // unknown 0x214-217
/* 0x218 */ ItemEntry * itemEntry; // see itemdrv.h
/* 0x21C */ // unknown 0x21c-23b
/* 0x23C */ s32 evtId; // id of the EvtEntry from mobjRunEvent
/* 0x240 */ MobjUpdateFunc * updateFunction; // runs every frame in mobjMain
/* 0x244 */ EvtScriptCode * interactScript; // ran when the player interacts with the object
/* 0x248 */ EvtScriptCode * afterInteractScript; // usage varies by MOBJ
/* 0x24C */ s32 state; // values vary by MOBJ
/* 0x250 */ // unknown 0x250-2a7
} MobjEntry; // total size 0x2a8

typedef struct { // paired with a MobjEntry at the same index, unknown purpose
/* 0x00 */ // unknown Vec3 0x00
/* 0x0C */ // unknown Vec3 0x0C
} MobjOtherEntry; // total size 0x18

typedef struct {
/* 0x00 */ s32 entryCountMax; // 0x100
/* 0x04 */ MobjEntry * entries; // array of entryCountMax length
/* 0x08 */ // unknown 0x8-f
/* 0x10 */ MobjOtherEntry * otherEntries; // array of entryCountMax length
/* 0x14 */ bool unkFlag;
/* 0x15 */ // unknown 0x15-17
} MobjWork; // total size 0x18

// 800297c0, 80029c34, 80029e50, 8002a03c,
// 8002a0bc, 8002a150, 8002a1d4, 8002a258,
// 8002a31c unknown functions

/*
    Allocates entries and otherEntries, sets entryCountMax and initialises other unknown data
*/
void mobjInit(); // 8002a3f4

/*
    Clears entries and re-initialises other unknown data
*/
void mobjReset(); // 8002a46c

/*
    Initialises collision data for a MOBJ
*/
void mobjHitEntry(MobjEntry * entry, s32 type); // 8002a4b8

/*
    Creates a MOBJ, returns its id
*/
s32 mobjEntry(const char * instanceName, const char * animPoseName); // 8002b390

/*
    Deletes a MOBJ
*/
void mobjDelete(const char * instanceName); // 8002b664

/*
    Sets a MOBJ's position
*/
void mobjSetPosition(const char * instanceName, float x, float y, float z); // 8002b72c

/*
    Updates all MOBJs
*/
void mobjMain(); // 8002b82c

/*
    Gets a MobjEntry by instance name
    NoAssert will return a null pointer if not found, regular will kill the game
*/
void mobjNameToPtr(const char * instanceName); // 8002c834
void mobjNameToPtrNoAssert(const char * instanceName); // 8002c8e8

/*
    Runs a script as a MOBJ
*/
EvtEntry * mobjRunEvent(MobjEntry * entry, EvtScriptCode * script); // 8002c980

/*
    Calculate a collision-related matrix for a MOBJ
*/
void mobjCalcMtx(MobjEntry * entry); // 8002ca04
void mobjCalcMtx2(MobJEntry * entry); // 8002cdf4

// 8002cf0c, 8002cfcc, 8002d2c0, 8002d560,
// 8002d640, 8002d720, 8002d7d8, 8002d890,
// 8002d89c, 8002d8a8, 8002d914, 8002d9bc,
// 8002de94, 8002dfc4, 8002e278, 8002e4c8,
// 8002e940, 8002e954, 8002e968, 8002e980,
// 8002e9bc, 8002ea0c, 8002ea54, 8002eb0c,
// 8002eb38, 8002eb60, 8002ed80, 8002ed90 unknown functions
 