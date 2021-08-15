/*
    Hitdrv handles collision with MOBJs or the map
    See also mapdrv.h and mobjdrv.h
*/

typedef struct {
    /*
        0x80000000 is belongs to MOBJ
        0x80 is deleted
        0x40 is matrix recalculated
        0x1 is disable
        Others unknown
    */
/* 0x000 */ u16 flags;
/* 0x002 */ // unknown 0x2-3
/* 0x004 */ u32 attr; // unknown bitflags
/* 0x008 */ MapFileJoint * joint;
/* 0x00C */ // unknown 0xc-cb
/* 0x0CC */ Vec3 position; 
/* 0x0D8 */ s16 totalTri;
/* 0x0DA */ s16 mapEntryIdx;
/* 0x0DC */ HitTri * tris; // array of totalTri length
/* 0x0E0 */ // unknown 0xe0-ff
/* 0x100 */ union {
/*       */ MOBJEntry * mobj;
/*       */ MapObj * mapObj;
/*       */ } owner;
/* 0x104 */ HitObj * parent;
/* 0x108 */ HitObj * child;
/* 0x10C */ HitObj * nextSibling;
/* 0x110 */ // unknown 0x110-113
} HitObj; // total size 0x114

/*
    Stub
*/
void hitInit(); // 8006aec8

/*
    Deletes all map HitObjs & their tris
*/
void hitReinit(); // 8006aecc

/*
    Creates a HitObj for a joint
*/
HitObj * _hitEnt(MapFileJoint * joint, HitObj * parent, Mtx34 * parentMtx, s32 mapEntryIdx); // 8006af6c

/*
    Recursively creates HitObjs for a joint and its children
*/
HitObj * hitEntrySub(MapFileJoint * joint, HitObj * parent, Mtx34 * parentMtx, bool ignoreSiblings, s32 mapEntryIdx); // 8006b4bc

/*
    Create HitObjs for a joint and its children
*/
HitObj * hitEntry(MapFileJoint * joint, Mtx34 * mtx, s32 mapEntryIdx); // 8006b72c
HitObj * hitEntryMOBJ(MapFileJoint * joint, Mtx34 * mtx); // 8006b8cc

/*
    Deletes a HitObj by name
*/
void hitDelete(const char * name); // 8006bac0

/*
    Updates matrices for HitObjs
*/
void hitMain(); // 8006bb8c

void hitRecalcMatrices(); // 8006bcc8

/*
    Turns on/off flags for a HitObj by name
    allowSubName matches HitObjs with the string anywhere in their name (strstr instead of strcmp)
*/
void hitObjFlagOn(bool allowSubName, const char * name, u16 mask); // 8006bd80
void hitObjFlagOff(bool allowSubName, const char * name, u16 mask); // 8006be08

/*
    Recursively turn on/off flags for a HitObj and its children by pointer/name
    allowSubName matches HitObjs with the string anywhere in their name (strstr instead of strcmp)
*/
void hitFlgOn(HitObj * hitObj, u16 mask, bool allowSiblings); // 8006be90
void hitFlgOff(HitObj * hitObj, u16 mask, bool allowSiblings); // 8006c1a0
void hitGrpFlagOn(bool allowSubName, const char * name, u16 mask); // 8006c4b4
void hitGrpFlagOff(bool allowSubName, const char * name, u16 mask); // 8006c6ac

/*
    Turns on/off attr bitflags for a HitObj by name
    allowSubName matches HitObjs with the string anywhere in their name (strstr instead of strcmp)
*/
void hitObjAttrOn(bool allowSubName, const char * name, u32 mask); // 8006c890
void hitObjAttrOff(bool allowSubName, const char * name, u32 mask); // 8006c918

/*
    Recursively turn on/off attr bitflags for a HitObj and its children by pointer/name
    allowSubName matches HitObjs with the string anywhere in their name (strstr instead of strcmp)
*/
void hitAtrOn(HitObj * hitObj, u32 mask, bool allowSiblings); // 8006c9a0
void hitAtrOff(HitObj * hitObj, u32 mask, bool allowSiblings); // 8006ccb0
void hitGrpAttrOn(bool allowSubName, const char * name, u32 mask); // 8006cfc4
void hitGrpAttrOff(bool allowSubName, const char * name, u32 mask); // 8006d1bc

void hitReCalcMatrix(HitObj *, UNK); // 8006d3a0
void hitReCalcMatrix2(HitObj *, Mtx34 *, bool); // 8006d400
void hitCalcVtxPosition(HitObj *); // 8006d560

// 8006da4c, 8006debc, 8006e160, 8006e400 unknown functions

s32 hitCheckVecFilter(UNK, UNK); // 8006e780
s32 hitCheckFilter(UNK, UNK, UNK, UNK, UNK, UNK, UNK, UNK, UNK, UNK, UNK, UNK, UNK, UNK); // 8006ee2c

// 8006ef1c unknown function

s32 chkFilterAttr(UNK, UNK); // 8006f018
s32 hitCheckAttr(UNK, UNK, UNK, UNK, UNK, UNK, UNK, UNK, UNK, UNK, UNK, UNK, UNK, UNK); // 8006f030

// 8006f128, 8006f47c, 8006f710, 8006f7cc,
// 8006f884 unknown functions

/*
    Gets a HitObj by name / a string anwyhere in its name
*/
HitObj * hitNameToPtr(const char * name); // 8006f920
HitObj * hitSubNameToPtr(const char * subname); // 8006f9cc

/*
    Gets the position vector of a HitObj
*/
void hitObjGetPosSub(HitObj *, Vec3 *, s32 *, bool); // 8006fa78
void hitObjGetPos(const char * name, Vec3 * posOut); // 8006ffe4

/*
    Gets the normal vector of a HitObj
*/
void hitObjGetNormal(const char * name, Vec3 * normalOut); // 8007035c

/*
    Returns the bounding box of the specified map entry
*/
void hitGetMapEntryBbox(s32 mapEntryIdx, Vec3 * minOut, Vec3 * maxOut); // 800703b0

// 8007058c, 80070790 unknown functions

/*
    Gets the name of a HitObj's joint
*/
const char * hitGetName(HitObj * hitObj); // 80070898

/*
    Returns the attr of a HitObj
*/
u32 hitGetAttr(HitObj * hitGetAttr); // 80070980

/*
    Sets the owner of a HitObj
*/
void hitBindMapObj(const char * hitName, const char * mapObjName); // 80070998

void hitBindUpdate(); // 80070a24
void hitCheckVecFilter2(); // 80070b1c

// 800710b4, 800717d8, 80071f44 unknown functions
