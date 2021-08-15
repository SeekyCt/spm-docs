/*
    mapdrv handles the rendering & collision of the main map model
*/

typedef struct {
/* 0x0 */ // unknown 0x0
/* 0x1 */ u8 cullMode;
/* 0x2 */ u8 flags;
/* 0x3 */ // unknown 0x3
/* 0x4 */ u32 lightMask;
/* 0x8 */ u32 attr;
/* 0xC */ // unknown 0xc-f
} MapFileJointDrawMode; // total size 0x10

typedef struct {
/* 0x0 */ UNK * material;
/* 0x4 */ UNK * mesh;
} MapFileJointPart; // total size 0x8

typedef struct {
/* 0x00 */ const char * name;
/* 0x04 */ const char * type;
/* 0x08 */ MapFileJoint * parent;
/* 0x0C */ MapFileJoint * firstChild;
/* 0x10 */ MapFileJoint * nextSibling;
/* 0x14 */ MapFileJoint * prevSibling;
/* 0x18 */ Vec3 scale;
/* 0x24 */ Vec3 rotation;
/* 0x30 */ Vec3 translation;
/* 0x3C */ Vec3 bboxMin;
/* 0x48 */ Vec3 bboxMax;
/* 0x54 */ // unknown 0x54-57
/* 0x58 */ MapFileJointDrawMode * drawMode;
/* 0x5C */ s32 partTableCount;
/* 0x60 */ MapFileJointPart partTable[]; // array of length partTableCount
} MapFileJoint; // total size varies

typedef struct {
/* 0x00 */ // unknown 0x0-3
/* 0x04 */ s32 type;
/* 0x08 */ float startZ;
/* 0x0C */ float endZ;
/* 0x10 */ RGBA colour;
} MapFileFog; // total size 0x14

typedef struct {
/* 0x00 */ u32 fileSize;
/* 0x04 */ u32 mainDataSize;
/* 0x08 */ u32 relTableCount;
/* 0x0C */ u32 chunkTableCount;
/* 0x10 */ // unknown 0x10-1f
} MapFileHeader; // total size 0x20

typedef struct {
/* 0x0 */ u32 offset; // into main data
/* 0x4 */ u32 nameOffset; // into string table
} MapFileChunk;

typedef struct {
/* 0x00 */ MapFileHeader fileHeader;
/* 0x20 */ void * mainData;
/* 0x24 */ UNK * relTable;
/* 0x28 */ MapFileChunk * chunkTable;
/* 0x2C */ // unknown 0x2c-2f
/* 0x30 */ const char * stringTable;
/* 0x34 */ // unknown 0x34-3b
/* 0x3C */ u32 flags;
/* 0x40 */ void * rawFile;
} MapFileContext; // total size 0x44

typedef struct {
/* 0x00 */ const char * name;
/* 0x04 */ const char * type;
/* 0x08 */ Vec3 position;
/* 0x14 */ Vec3 rotation;
/* 0x20 */ Vec3 scale;
/* 0x2C */ RGBA colour;
/* 0x30 */ float spotAngle;
/* 0x34 */ float angleAttenuation;
/* 0x38 */ s32 distanceAttenuationType;
/* 0x3C */ u32 flags;
/* 0x40 */ s32 version;
} MapFileLightEntry; // total size 0x44

typedef struct {
/* 0x0 */ s32 count;
/* 0x4 */ MapFileLightEntry * entries[]; // array of length count
} MapFileLightTable; // total sizevaries

typedef struct {
/* 0x00 */ const char * meshName;
/* 0x04 */ Vec3 translation;
/* 0x10 */ Vec3 rotation;
/* 0x1C */ Vec3 scale;
/* 0x28 */ // unknown 0x28-57
/* 0x58 */ s32 frameCount;
} MapFileMeshTrack; // total size 0x5c

typedef struct {
/* 0x0 */ s32 count;
/* 0x4 */ MapFileMeshTrack * tracks; // array of length count
} MapFileMeshTracks; // total size 0x8

typedef struct {
/* 0x00 */ const char * name;
/* 0x04 */ // unknown 0x4-7
/* 0x08 */ float duration;
/* 0x0C */ MapFileMeshTracks * meshTracks;
/* 0x10 */ UNK * materialTrack;
/* 0x14 */ // unknown 0x14-1f
} MapFileAnimData; // total size 0x20

typedef struct {
    /*
        0x1 is hide
        Others unknown
    */
/* 0x000 */ u32 flag0;
/* 0x004 */ u32 flag4;
/* 0x008 */ u8 blendMode;
/* 0x009 */ // unknown 0x9-b
/* 0x00C */ MapFileJoint * joint;
/* 0x010 */ RGBA colour;
/* 0x014 */ // unknown 0x14-1b
/* 0x01C */ Vec3 translation;
/* 0x028 */ Mtx34 modelWorldMtx;
/* 0x058 */ // unknown 0x58-b7
/* 0x0B8 */ Mtx34 runtimeWorldMtx;
/* 0x0E8 */ s16 offscreenId;
/* 0x0EA */ s16 mapEntryId;
/* 0x0EC */ MapObj * parent;
/* 0x0F0 */ MapObj * firstChild;
/* 0x0F4 */ MapObj * nextSibling;
/* 0x0F8 */ u16 gxBboxLeft;
/* 0x0FA */ u16 gxBboxTop;
/* 0x0FC */ u16 gxBboxRight;
/* 0x0FE */ u16 gxBboxBottom;
/* 0x100 */ void * dl_buf[8]; // display list pointers
/* 0x120 */ u32 dl_size[8]; // display list sizes
/* 0x140 */ // unknown 0x140-143
} MapObj; // total size 0x144

typedef struct {
/* 0x00 */ u16 flags;
/* 0x02 */ // unknown 0x2-f
/* 0x10 */ float timePlayed;
/* 0x14 */ float playRate;
/* 0x18 */ MapFileAnimData * fileData;
/* 0x1C */ // unknown 0x1c-27
} MapAnimObj; // total size 0x28

typedef void (MapEntryUnloadCb)();

// Internally referred to as a "kind"
typedef struct {
/* 0x000 */ s32 mapCount; // active MapEntry count (always 1?)
/* 0x004 */ u16 flags;
/* 0x006 */ char name[16];
/* 0x016 */ RGBA colour;
/* 0x01A */ RGBA blend1;
/* 0x01E */ RGBA blend2;
/* 0x022 */ // unknown 0x22-23
/* 0x024 */ MapFileFog fogDefs[2];
/* 0x04C */ s32 loadStage; // used for mapLoad
/* 0x050 */ MapFileContext mapDatContext;
/* 0x094 */ void * mapDat;
/* 0x098 */ u32 mapDatSize;
/* 0x09C */ void * tpl;
/* 0x0A0 */ u32 tplSize;
/* 0x0A4 */ UNK * textureTable;
/* 0x0A8 */ MapFileLightTable * lightTable;
/* 0x0AC */ MapFileFog * fogData;
/* 0x0B0 */ UNK * materialNameTable;
/* 0x0B4 */ UNK * vcdTable;
/* 0x0B8 */ MapObj * rootMapObj;
/* 0x0BC */ HitObj * rootHitObj;
/* 0x0C0 */ Vec3 bboxCorners[2][8];
/* 0x180 */ s32 mapObjCount;
/* 0x184 */ MapObj * mapObjs;
/* 0x188 */ s32 hitObjCount;
/* 0x18C */ HitObj * hitObj;
/* 0x190 */ s32 animCount;
/* 0x194 */ MapAnimObj * animData;
/* 0x198 */ u32 dl_size; // display list size
/* 0x19C */ void * dl_buf; // display list buffer
/* 0x1A0 */ MapEntryUnloadCb * unloadCb;
} MapEntry; // total size 0x1a4

typedef struct {
/* 0x000 */ MapEntry entries[2]; // being an array is a TTYD leftover
/* 0x348 */ // unknown 0x348-34b
} MapWorkGroup; // total size 0x34c

typedef struct {
/* 0x000 */ MapWorkGroup groups[2];
/* 0x698 */ s32 activeGroup;
/* 0x69C */ // unknown 0x69c-69f
/* 0x6A0 */ s32 dispOff;
/* 0x6A4 */ // unknown 0x6a4-6a7
/* 0x6A8 */ RGBA paperAmbColor;
} MapWork; // total size 0x6ac

MapWork mapWork; // 8050bc20
MapWork * mapdrvWp; // 805adff0

/*
    Records when a MapObj/HitObj isn't found
    Types:
        0 - MapObj
        1 - HitObj
*/
void mapErrorEntry(int type, char * elementName); // 8007ec34

// 8007ecc4, 8007ee24, 8007eff0 unknown functions

/*
    Hides/unhides the map
*/
void mapDispOff(); // 8007f1bc
void mapDispOn(); // 8007f1cc

/*
    Returns the pointer to the active group in mapWork
*/
MapWorkGroup * mapGetWork(); // 8007f1dc

/*
    Counts the children of a MapFileJoint and the joint itself
*/
void mapGetJointsSub(MapFileJoint * joint, s32 countOut); // 8007f1f0
void mapGetJoints(MapFileJoint * joint); // 8007f498

/*
    Returns the bounding box of all MapObjs in the specified map entry
*/
void mapGetBoundingBox(s32 entryId, Vec3 * minOut, Vec3 * maxOut); // 8007f778

/*
    Clears work and sets entry bounding boxes to (-)1000.0
*/
void mapInit(); // 8007f95c

/*
    Clears entries
*/
void mapReset(); // 8007f95c

/*
    Initialises textures for a MapObj
*/
void mapBuildTexture(MapObj * mapObj, TPLHeader * tpl, UNK * textureTable); // 8007fbd4

/*
    Creates a MapObj from a MapFileJoint
*/
MapObj * _mapEnt(MapFileJoint * joint, MapObj * parent, Mtx34 * mtx, s32 mapEntryId); // 8007fe10

/*
    Creates MapObjs for a joint and its children
*/
MapObj * mapEntrySub(MapFileJoint * joint, MapObj * parent, Mtx34 * mtx, bool isRoot, s32 mapEntryId); // 800803f8

/*
    Creates the display list for a map entry
*/
void makeDisplayList(s32 mapEntryId); // 80080668

// 800808f0 unknown function

/*
    Gets a MapAnimObj by name
*/
MapAnimObj * mapSearchAnimObj(const char * animName); // 800809b4


/*
    Checks the progress of an animation
*/
void mapCheckAnimation(const char * animName, s32 * finishedOut, float * timeRemainingOut); // 80080a58

/*
    Plays an animation which will only progress on the specified system level or lower
*/
void mapPlayAnimationLv(const char * animName, UNK param_2, s32 level);

/*
    Creates the MapAnimObjs for a map entry
*/
void mapEntryAnimation(s32 mapEntryId);

/*
    Ends/pauses/restarts an animation
*/
void mapDeleteAnimation(const char * animName); // 800810f0
void mapPauseAnimation(const char * animName); // 800811a4
void mapReStartAnimation(const char * animName); // 80081258

/*
    Pauses/restarts all animations
*/
void mapPauseAnimationAll(); // 8008130c
void mapReStartAnimationAll(); // 8008136c

/*
    Sets the speed of an animation
*/
void mapSetPlayRate(const char * animName, float playRate); // 800813cc

/*
    Jumps to a fraction of the way through an animation
*/
void mapSetPlayProgress(const char * animName, float playProgress); // 80081484

/*
    Returns the length of an animation
*/
float mapGetPlayDuration(const char * animName); // 80081568

/*
    Clears the current map, hit, env and light entries
*/
void mapUnload(); // 80081618

/*
    Loads a new map
*/
void mapLoad(const char * name); // 8008181c

// 80083aa4 unknown function

void mapCalcAnimMatrix(Mtx34 * dest, Mtx34 * parentMtx, MapAnimObj * obj, MapFileMeshTrack * track); // 80083abc

// 80083eb4, 80084098, 80084274 unknown functions

void mapReCalcMatrix(MapObj * mapObj, Mtx * dest, bool includeRoot); // 80084474

/*
    Updates map visuals and collision
*/
void mapMain(); // 80084594

/*
    Renders a MapObj (and its children)
*/
void _mapDispMapObj(s8 cameraId, MapObj * obj); // 80084a60
void _mapDispMapGrp(s8 cameraId, MapObj * obj); // 80085094
void mapDispMapObj(s8 cameraId, void * param); // 80085308
void mapDispMapGrp(s8 cameraId, void * param); // 80085308

/*
    Renders an offscreen MapObj (and its children)
*/
void mapDispMapObj_off(s8 cameraId, void * param); // 80085580
void mapDispMapGrp_off(s8 cameraId, void * param); // 80085604

/*
    Renders a MapObj without a material (and its children)    
*/
void _mapDispMapObj_NoMaterial(s8 cameraId, MapObj * obj); // 800858c4
void _mapDispMapGrp_NoMaterial(s8 cameraId, MapObj * obj); // 800858c4

/*
    Updates the GX bounding box of a MapObj (and its children)
*/
void mapDispMapObj_bbox(s8 cameraId, void * param); // 80085d58
void mapDispMapGrp_bbox(s8 cameraId, void * param); // 80085db8

/*
    Prepares for & schedules rendering the map
*/
void mapDisp(); // 80086154

void mapSetLight(MapObj *, UNK); // 80086980
void mapSetMaterialTev(UNK, UNK, UNK, UNK, UNK, UNK); // 80086b48
void mapSetMaterialLastStageBlend(UNK, UNK, UNK, UNK, UNK, UNK); // 8008932c
void mapSetMaterialFog(); // 800896c0
void mapSetMaterialFogMapObj(UNK); // 80089928
void mapSetTextureMatrix(UNK); // 80089ba8
void mapSetMaterial(UNK, UNK); // 80089f20
void mapSetPaperAmbColor(RGBA * colour); // 8008a628
void mapResetPaperAmbColor(); // 8008a650
void mapSetMaterialLight(UNK, UNk); // 8008a690
void mapSetPolygon(UNK, UNK); // 8008acb4
void mapSetPolygonVtxDesc(UNK, UNK); // 8008b304

// 8008b4c8 unknown function

MapFileJoint * mapSearchDmdJointSub(MapFileJoint * joint, const char * name); // 8008b95c
MapFileJoint * mapSearchDmdJointSub2(UNK, UNK, UNK); // 8008bedc
UNK * mapSearchDmdMaterial(const char * name); // 8008c2ec

/*
    Gets a MapObj by name
*/
MapObj * mapGetMapObj(const char * name); // 8008c398

/*
    Turns on/off flag0 flags for a MapObj (and its children)
    allowSubName matches MapObjs with the string anywhere in their name (strstr instead of strcmp)
*/
void mapObjFlagOn(bool allowSubName, const char * name, u32 mask); // 8008c440
void mapObjFlagOff(bool allowSubName, const char * name, u32 mask); // 8008c618
void mapFlgOn(MapObj * obj, u32 mask, bool allowSiblings); // 8008c7dc
void mapFlgOff(MapObj * obj, u32 mask, bool allowSiblings); // 8008cc1c
void mapGrpFlagOn(bool allowSubName, const char * name, u32 mask); // 8008cf30
void mapGrpFlagOff(bool allowSubName, const char * name, u32 mask); // 8008d2fc

/*
    Turns on/off flag4 flags for a MapObj (and its children)
    allowSubName matches MapObjs with the string anywhere in their name (strstr instead of strcmp)
*/
void mapObjFlag4On(bool allowSubName, const char * name, u32 mask); // 8008d62c
void mapObjFlag4Off(bool allowSubName, const char * name, u32 mask); // 8008d804
void mapFlg4On(MapObj * obj, u32 mask, bool allowSiblings); // 8008d9c8
void mapFlg4Off(MapObj * obj, u32 mask, bool allowSiblings); // 8008de08
void mapGrpFlag4On(bool allowSubName, const char * name, u32 mask); // 8008e11c
void mapGrpFlag4Off(bool allowSubName, const char * name, u32 mask); // 8008e4e8

/*
    Sets the offscreen id of a MapObj (and its children)
*/
void _setOffScrnId(MapObj * obj, s16 ofsId, bool allowSiblings); // 8008e818
void mapObjSetOffscreen(const char * objName, const char * ofsName); // 8008eab0
void mapGrpSetOffscreen(const char * objName, const char * ofsName); // 8008ebe0

/*
    Removes the offscreen id of a MapObj (and its children), checking the name is correct
*/
void mapObjClearOffScreen(const char * objName, const char * ofsName); // 8008ee58
void mapGrpClearOffScreen(const char * objName, const char * ofsName); // 8008efd4

// 8008f2a4, 8008f324 unknown functions

/*
    Rotates a MapObj in degrees
*/
void mapObjRotate(const char * objName, float x, float y, float z); // 8008f3a8

/*
    Moves a MapObj by the specified amount in each direction
*/
void mapObjTranslate(const char * objName, float x, float y, float z); // 8008f528

/*
    Scales a MapObj by the specified amount in each direction
*/
void mapObjRotate(const char * objName, float x, float y, float z);

/*
    Gets the centre of a MapObj and its children
*/
void mapObjGetPosSub(MapObj * obj, Vec3 * posOut, s32 * countOut, bool allowSiblings); // 8008f77c
void mapObjGetPos(const char * name, Vec3 * posOut); // 8008fce8

// 800900cc, 80090270 unknown functions

/*
    Sets the fog parameters for a map group
*/
void mapSetFog(s32 groupId, s32 type, RGBA * colour, f32 startZ, s32 endZ); // 800903f8

/*
    Enables/disables fog
*/
void mapFogOn(); // 80090448
void mapFogOff(); // 80090468

/*
    Sets/gets a blend colour of the active group's first map entry
*/
void mapSetBlend(RGBA * colour); // 80090488
void mapSetBlend2(RGBA * colour); // 800904c8
void mapGetBlend(RGBA * colour); // 80090508
void mapGetBlend2(RGBA * colour); // 80090584

/*
    Ddisables a blend colour of the active group's first map entry
*/
void mapBlendOff(); // 80090600
void mapBlendOff2(); // 80090620

/*
    Sets the colour of the active group's first map entry
*/
void mapSetColor(RGBA * colour); // 80090640

/*
    Sets the colour of a MapObj (and its children)
*/
void mapObjSetColor(const char * name, RGBA * colour); // 80090680
void setColor(MapObj * obj, RGBA * colour, bool allowSiblings); // 8009075c
void mapGrpSetColor(const char * name, RGBA * colour); // 80090a80

void spline_maketable(UNK, UNK, UNK, UNK); // 80090cbc
void spline_getvalue(UNK, UNK, UNK, UNK, UNK, UNK); // 800912a8

/*
    Applies relocations to a map.dat file and generates its context
    Returns 0 if successful, -1 if error
*/
s32 Locate(MapFileContext * outCtx, void * mapDat, u32 mapDatSize); // 80091438

bool mapTextXLU(UNK, UNK, UNK, UNK, UNK); // 80091594
