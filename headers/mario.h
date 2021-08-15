/*
    Mario controls the player characters of the game
*/

// Returns an override for the name
typedef const char * (MarioAnimChangeHandler)(const char * newAnimName);

enum {
    PLAYER_MARIO = 0,
    PLAYER_PEACH = 1,
    PLAYER_BOWSER = 2,
    PLAYER_LUIGI = 3
};

typedef struct {
/* 0x00 */ // unknown 0x0-33
} MarioJumpFallPara; // total size 0x34;

/*
    Called every frame, fairy is deleted when true is returned
*/
typedef bool (MarioFairyFlagDeleteFunc)(void * data, bool deletionHint);

/*
    Called when deleted, unless deleted from flag delete func
*/
typedef void (MarioFairyDeleteFunc)(void * data, void * param);

/*
    Called every frame, commands unknown
*/
typedef void (MarioFairyMainFunc)(void * data, s32 command);

typedef struct {
    /*
        0x8000 deletion hint (for flag delete func)
        0x2 store data in main heap, not map heap
        0x1 active
        Others unknown
    */
/* 0x00 */ u16 flags;
/* 0x02 */ u8 id;
/* 0x03 */ u8 slotId; // index in MarioWork's array this is stored at
/* 0x04 */ void * data;
/* 0x08 */ MarioFairyFlagDeleteFunc * flagDeleteFunc;
/* 0x0C */ MarioFairyDeleteFunc * deleteFunc;
/* 0x10 */ MarioFairyMainFunc * mainFunc;
/* 0x14 */ MarioFairy * nextFairy;
/* 0x18 */ MarioFairy * prevFairy;
} MarioFairy; // total size 0x1c

/*
    Returns true if deleted, false otherwise
    Commands:
        1 start
        2 restart?
*/
typedef bool (MarioStatusMainFunc)(MarioStatus * status, Vec3 * iconPos, s32 command);

/*
    Returns true if it should be deleted, false otherwise
    Return is ignored except in marioStatusDeleteAll
*/ 
typedef bool (MarioStatusDeleteFunc)(MarioStatus * status, s32 level); 

/*
    Called on map change
*/
typedef void (MarioStatusMapChangeFunc)(MarioStatus * status);

typedef struct {
    /*
        0x1 active
        Others unknown
    */
/* 0x00 */ u32 flags;
/* 0x04 */ u32 type; // same values as MarioWork.statusFlags
/* 0x08 */ float timer; // time remaining, counts down to 0 in increments of marioSpeedScale
/* 0x0C */ void * userWork;
/* 0x10 */ MarioStatusMainFunc * mainFunc;
/* 0x14 */ MarioStatusDeleteFunc * deleteFunc;
/* 0x18 */ MarioStatusMapChangeFunc * mapChangeFunc;
/* 0x1C */ MarioStatus * prev;
/* 0x20 */ MarioStatus * next;
} MarioStatus; // total size 0x24

enum {
    GRAV_DOWN = 0,
    GRAV_UP = 1,
    GRAV_LEFT = 2,
    GRAV_RIGHT = 3
};
#define MARIO_GRAVITY_MAX 4

/*
    Commands:
        0 start
        1 update
        2 end
*/
typedef void (MarioAcrobatCallback)(s32 command);

typedef struct {
/* 0x0 */ f32 min;
/* 0x4 */ f32 max;
} MarioPaneBoundary; // total size 0x8

/*
    Returns true if the pane change is allowed
*/
typedef bool (MarioPaneChangeFunc)(s32 newPane);

typedef struct {
    /*
        General flags
        0x80000000 squashed (regrowing with dottie without space)
        0x40000000 mega star damage (double attack & breaking blocks)
        0x10000000 block motion id change
        0x2000000 bg mode
        0x800000 respawn position locked
        0x8 key off
        0x2 ctrl off
        Others unknown
    */
/* 0x0000 */ u32 flags;
    /*
        More general flags
        0x20000000 off ground in water
        0x200000 squirps enabled
        0x80000 luvbi enabled
        0x400 near top of water?
        0x200 can jump out of water?
        0x100 in water
        0x10 jumping out of water
    */
/* 0x0004 */ u32 miscFlags;
    /*
        Disp flags
        0x40000000 paper pose on
        0x20 lock facing direction towards facingTarget
    */
/* 0x0008 */ u32 dispFlags;
    /*
        Trig flags
        0x40000000 blocks clear_hitobj_ride
        0x1000 pose changed
        0x1 motion id changed
    */
/* 0x000C */ u32 trigFlags;
    /*
        Status flags
        0x8000 ghost shroom
        0x4000 pal pills
        0x2000 unused?
        0x1000 coin flower
        0x800 slow flower (including triple xp)
        0x400 speed flower (including triple xp)
        0x200 barrier
        0x100 hp regen
        0x80 electrified
        0x40 double attack
        0x20 halved damage
        0x10 flipped controls
        0x8 de-jumped
        0x4 no skills
        0x2 slow
        0x1 poison
        Others unused
    */
/* 0x0010 */ u32 statusFlags;
    /*
        Effect flags
        0x8 slow flower trail
        0x4 speed flower trail
        0x2 stylish trail
        Others unknown
    */
/* 0x0014 */ u8 effectFlags;
/* 0x0015 */ // unknown 0x15-1b
/* 0x001C */ const char * curPoseName; // current animation name
/* 0x0020 */ const char * paperPoseName;
/* 0x0024 */ s16 poseTime; // time in current animation
/* 0x0026 */ // unknown 0x26-27
/* 0x0028 */ MarioAnimChangeHandler * animChangeHandler;
    /*
        Motion ids:
        0 stay
        1 walk
        2 dash
        3 jump
        4 crouch
        6 spring
        9 jump npc
        10 fall
        14 thudley air
        15 thudley land
        16 hammer (cudge)
        17 jabara (luigi crouch)
        18 slit (slim)
        19 talk
        23 forceReset?
        25 bottomless (fall off respawn)
        26 flip into midair
        27 damage
        36 throwing thoreau
        37 placing bomb
        38 using fleep
        39 dottie shrink
        40 dottie grow
        41 piccolo
        42 barry
        44 mount carrie
        45 dismount carrie
        69 swim
        71 character change
        72 pixl change
        73 flipping
        74 peach parasol float
        75 peach parasol guard
        76 bowser fire
        Others unknown
    */
/* 0x002C */ u16 motionId;
/* 0x002E */ u16 prevMotionId;
/* 0x0030 */ // unknown 0x30-33
    // freeze the player when > 0 (for cutscenes, talking, etc)
/* 0x0034 */ u8 ctrl;
/* 0x0035 */ u8 keyOff;
/* 0x0036 */ // unknown 0x36-37
/* 0x0038 */ s8 character; // see enum above
/* 0x0039 */ // unknown 0x39-3a
/* 0x003B */ u8 wallTimer;
/* 0x003C */ s32 subMotionId; // values vary by motion id
/* 0x0040 */ // unknown 0x40-4f
/* 0x0050 */ float airTimer; // time in air
/* 0x0054 */ float jumpPeakAirTime; // value of airTimer when reaching top of jump
/* 0x0058 */ // unknown 0x58-5b
/* 0x005C */ Vec3 position;
/* 0x0068 */ // unknown 0x68-bb
/* 0x00BC */ Vec3 scale;
/* 0x00C8 */ // unknown 0xc8-11f
/* 0x0120 */ s32 camId;
/* 0x0124 */ // unknown 0x124-127
/* 0x0128 */ Vec3i framebufferPos;
/* 0x0134 */ // unknown 0x134-147
/* 0x0148 */ float xzSpeed; // current horizontal speed
/* 0x014C */ float walkSpeed; // base walk speed
/* 0x0150 */ float dashSpeed; // base dash speed
/* 0x0154 */ // unknown 0x154-15f
/* 0x0160 */ float lastGroundSpeed; // xzSpeed when last on ground
/* 0x0164 */ // unknown 0x164-173
/* 0x0174 */ float directionWorld; // degrees
/* 0x0178 */ float directionView; // degrees
/* 0x017C */ // unknown 0x17c-17f
/* 0x0180 */ float dispDirectionCurrent; // rotation of the player's model about y axis, degrees
/* 0x0184 */ float dispDirectionTarget; // dispDirectionCurrent transitions to this target value
/* 0x0188 */ // unknown 0x188-193
/* 0x0194 */ float hitboxWidth;
/* 0x0198 */ float hitboxHeight;
/* 0x019C */ float baseHitboxWidth;
/* 0x01A0 */ float baseHitboxHeight;
/* 0x01A4 */ // unknown 0x1a4-1bb
    /*
        1 is interact (in front of player)
        2 is stand on
        3 is jump from
        6 is head
        Others unknown
    */
/* 0x01BC */ HitObj * hitObjs1[10];
/* 0x01E4 */ // unknown 0x1e4-1fb
    /*
        0 is MOBJ interact
        Others unknown
    */
/* 0x01FC */ HitObj * hitObjs2[3];
/* 0x0208 */ // unknown 0x208-24b
    /*
        0 is main model
        1 is back model (Mario only)
        6 is paper pose
        8 is slim flip model
        Others unknown
    */
/* 0x024C */ s32 animPoseIds[8];
/* 0x026C */ // unknown 0x26c-30b
/* 0x030C */ u16 buttonsHeld;
/* 0x030E */ u16 buttonsPressed;
/* 0x0310 */ u16 buttonsHeldRepeat;
/* 0x0312 */ u16 buttonsReleased;
/* 0x0314 */ // unknown 0x314-315
/* 0x0316 */ u8 pseudoJoystickX;
/* 0x0317 */ u8 pseudoJoystickY;
/* 0x0318 */ // unknown 0x318-31d
    /*
        Frames 1/2 has been held
        -1 if not held
        Caps at 100
    */
/* 0x031E */ s16 held1Time;
/* 0x0320 */ s16 held2Time;
/* 0x0322 */ // unknown 0x322-347
/* 0x0348 */ s32 sfxIds[4];
/* 0x0358 */ // unknown 0x358-3a3
    /*
        Info on entity caught with Thoreau
        catchType indicates the type of caught
        0 nothing
        1 NPC
        2 Fairy
        3 MOBJ
    */
/* 0x03A4 */ union {
/*        */ NPCEntry * npc;
/*        */ FairyEntry * npc;
/*        */ MOBJEntry * npc;
/*        */ } caught;
/* 0x03A8 */ s32 catchType;
/* 0x03AC */ // unknown 0x3ac-3cf
/* 0x03D0 */ float xzSpeedFactor;
/* 0x03D4 */ // unknown 0x3d4-3d7
/* 0x03D8 */ Vec3 respawnPosition;
/* 0x03E4 */ // unknown 0x3e4-3eb
/* 0x03EC */ HitObj * hitObjRideArray[24];
/* 0x044C */ s32 numHitObjRideArray; // number of pointers in the array above
/* 0x0450 */ // unknown 0x450-693
/* 0x0694 */ HitObj * hitObjInteractArray[50];
/* 0x075C */ s32 numHitObjInteractArray; // number of pointers in the array above
/* 0x0760 */ // unknown 0x760-9b7
/* 0x09B8 */ HitObj * hitObjHeadArray[20];
/* 0x0A08 */ s32 numHitObjHeadArray; // number of pointers in the array above
/* 0x0A0C */ // unknown 0xa0c-cd7
/* 0x0CD8 */ MarioJumpFallPara jumpFallPara;
/* 0x0D0C */ // unknown 0xd0c-d57
/* 0x05D8 */ MarioFairy fairy[10];
/* 0x0E70 */ MarioFairy * firstFairy;
/* 0x0E74 */ MarioFairy * lastFairy;
/* 0x0E78 */ // unknown 0xe78-e7f
/* 0x0E80 */ MarioStatus statusTbl[32];
/* 0x1300 */ MarioStatus * firstStatus;
/* 0x1304 */ MarioStatus * lastStatus;
/* 0x1308 */ // unknown 0x1308-135f
/* 0x1360 */ s32 gravityType; // see enum above
    // Unit vectors for each direction under current gravity
/* 0x1364 */ Vec3 gravUnitRight; // positive x normally
/* 0x1370 */ Vec3 gravUnitUp; // positive y normally
/* 0x137C */ Vec3 gravUnitForward; // positive z normally
/* 0x1388 */ // unknown 0x1388-147f
/* 0x1480 */ s32 nextCharacter;
/* 0x1484 */ s32 prevPixl;
/* 0x1488 */ s32 curPixl;
/* 0x148C */ // unknown 0x148c-1497
/* 0x1498 */ u16 acrobatFlags;
/* 0x149A */ // unknown 0x149a-149b
/* 0x149C */ float stylishLevel;
/* 0x14A0 */ // unknown 0x14a0-14a3
/* 0x14A4 */ s32 lastStylishXp;
/* 0x14A8 */ s32 stylishSfxId;
/* 0x14AC */ s32 stylishCombo;
/* 0x14B0 */ // unknown 0x14b0-14b3
/* 0x14B4 */ float posLockTimer; // freezes the player in place for the stylish spin animation
/* 0x14B8 */ // unknown 0x14b8-14bf
/* 0x14C0 */ u32 acrobatJoystickFlags;
/* 0x14C4 */ // unknown 0x14c4-14db
/* 0x14DC */ MarioAcrobatCallback * acrobatCb;
/* 0x14E0 */ s32 acrobatStage;
/* 0x14E4 */ // unknown 0x14e4-154f
/* 0x1550 */ s32 pane; // row of the map on z-axis the player is in, -1 if no panes
/* 0x1554 */ MarioPaneBoundary * paneBoundaries; // null if no panes
/* 0x1558 */ MarioPaneChangeFunc * paneChangeFunc;
/* 0x155C */ Vec3 facingTarget;
/* 0x1568 */ // unknown 0x1568-156b
} MarioWork; // total size 0x156c

MarioWork marioWork; // 80510458

typedef struct {
/* 0x00 */ float hitboxWidth;
/* 0x04 */ float hitboxHeight;
/* 0x08 */ float walkSpeed;
/* 0x0C */ float dashSpeed;
/* 0x10 */ // unknown 0x10-13
} CharacterProperties; // total size 0x14

CharacterProperties characterProperties[4]; // 804266c8, index character id

typedef void (MarioMotFunc)(MarioWork * mp);

typedef struct {
/* 0x0 */ MarioMotFunc * mainFunc;
/* 0x4 */ MarioMotFunc * deleteFunc;
} MarioMotFuncs; // total size 0x8

MarioMotFuncs marioMotTbl[78]; // 80426bb8, index motion id (see MarioWork comment)

s64 marioMainLastRunTime; // 80510450, used to adjust marioGameSpeedScale for lag

/*
    In normal gameplay, this is 1.0 for every frame
    When lagging, this will increase so the game will try catch up
    Fast & slow flowers also double/half this
*/
float marioGameSpeedScale; // 805ae8e8

// 80121e18 unknown function

/*
    Returns marioGameSpeedScale
*/
float marioGetGameSpeedScale();

// 80121e58, 80121f40 unknown functions

/*
    Returns a pointer to the MarioWork instance
*/
MarioWork * marioGetPtr(); // 80121f48

// 80121f54, 8012217c, 801222a4 unknown functions

/*
    Changes the player's model
    0 is normal
    1 is mega
*/
void marioSetAnimGroup(s32 group); // 8012230c

// 8012244c unknown function

/*
    Re-reads the characterProperties for the current character into marioWork
*/
void marioUpdateCharProperties(); // 801226f0

/*
    Returns the characterProperties hitboxWidth for the current character
*/
f32 marioGetHitboxWidthRaw(); // 8012292c

/*
    Returns the characterProperties hitboxHeight for the current character
*/
f32 marioGetHitboxHeightRaw(); // 8012292c

/*
    Returns the characterProperties hitboxHeight for the current character, or 63 for Bowser
*/
f32 marioGetHitboxHeight_BowserSpecial(); // 80122978

/*
    Returns the characterProperties dashSpeed for the current character
*/
f32 marioGetDashSpeedRaw(); // 801229b0

/*
    Updates the player on entering a new map
    Handles statuses, animations, position and unflipping from Slim
*/
void marioOnMapChange(f32 spawnX, f32 spawnY, f32 spawnZ); // 801229c8

/*
    Returns whether player movement is enabled based on keyOff
*/
bool marioChkKey(); // 80122b7c

/*
    Returns whether player movement is enabled based on ctrl
*/
bool marioCtrlOnChk(); // 80122b4c

/*
    Returns whether player movement is disabled based on ctrl
*/
bool marioCtrlOffChk(); // 80122b68

/*
    Returns whether player movement is disabled based on keyOff
*/
bool marioKeyOffChk(); // 80122b7c

/*
    Disables movement, increasing ctrl by one and returning it
*/
s32 marioCtrlOff(); // 80122b90

/*
    Reduces ctrl by one and returns it, enabling movement if it's 0
*/
s32 marioCtrlOn(); // 80122bbc

/*
    Disables movement, increasing keyOff by one and returning it
    XZ speed is also removed
*/
s32 marioKeyOff(); // 80122bf4

/*
    Reduces keyOff by one and returns it, enabling movement if it's 0
*/
s32 marioKeyOn(); // 80122c2c

/*
    Sets up the player to walk in the background of the level
*/
void marioBgModeOn(); // 80122c64

/*
    Stops the player walking in the background of the level
*/
void marioBgModeOff(); // 80122cc0

/*
    Checks if any of the specified conditions in the mask are true
    0x1: marioWork.flags & 0x10000 is on
    0x2: marioWork.flags & 0x20000 is on
    0x4: marioWork.flags & 0x100000 is on
    0x8: motion id is Luigi super jump
*/
bool marioCheckSts(u32 mask); // 80122d1c

/*
    Removes references to a HitObj from hitObjs1 & hitObjs2
*/
void marioResetHitObj(const char * name);   // 80122d90

/*
    Resets marioWork for a new save file
*/
void marioReset(); // 80122fa8

void marioOfsRotReset(); // 801231c0

/*
    Clears sfx ids
*/
void marioSoundInit(); // 80123268

/*
    Asynchronously sets up front & back models for the player
    Returns true if finished
*/
bool marioPoseInit(); // 80123288

/*
    Initialises marioWork
*/
void marioInit(); // 8012339c


/*
    Re-initialises marioWork on map unload
*/
void marioReInit(); // 801236b0

// 80123f0c unknown function

/*
    Updates respawn position if in a safe location to respawn
*/
void marioUpdateRespawnPos(); // 80124034

// 80124374 unknown function

/*
    Updates the player
*/
void marioMain(); // 801243a8

// 80125854, 80125998, 80126034, 801265a0,
// 80126618, 8012662c, 80126688 unknown functions

/*
    Sets the player's current animation
*/
void marioChgPose(const char * name); // 801266e4
void marioChgPoseTime(const char * name, s16 time); // 801268b4

void marioChgPaper(const char * name); // 80126940
void marioChgPaper2(const char * name); // 801269cc
void marioSetPaperAnimeLocalTime(s16 time); // 80126a50
void marioPaperOn(const char * name); // 80126aac
void marioPaperOff(); // 80126b88
void marioPaperLightOn(); // 80126c08
void marioPaperLightOff(); // 80126c1c

/*
    Returns whether the player's current animation has finished
*/
bool marioIsAnimFinished(); // 80126c30

// 80126c98, 80126cfc unknown functions

/*
    Returns screen coordinates for a point in the 3d world
*/
void marioGetScreenPos(Vec3 * worldPos, f32 * xOut, f32 * yOut, f32 * zOut); // 80126d48

/*
    Returns whether the given screen coordinates are on screen
*/
bool marioChkInScreen(s32 x, s32 y); // 80126dcc

/*
    Returns 0.8 for bg mode, 2.0 otherwise
*/
float marioGetScale(); // 80126dfc

// 80126e1c, 80126e6c unknown functions

/*
    Updates the direction the player is facing
*/
void marioMakeDispDir(); // 80127148

// 801275dc unknown functions

/*
    Prepares for rendering the player
*/
void marioPreDisp(); // 801277f4

// 80127f5c, 801280f8 unknown functions

/*
    Enables/disables effect flags
*/
void marioEffectFlagOn(u8 mask); // 8012823c
void marioFlag14Off(u8 mask); // 80128360

// 80128378, 801289bc, 80128d1c unknown functions

/*
    Renders the player
*/
void marioDisp(); // 80128ec8

// 80128f2c, 80128fd4, 801291f8 unknown functions

/*
    Converts a front/rear animation name to its rear/front equivalent
*/
const char * toRearPose(const char * name); // 80129438
const char * toFrontPose(const char * name); // 80129718

// 801299f8, 80129d8c, 80129db8, 80129ddc,
// 80129dfc, 8012a064, 8012a168, 8012a354 unknown functions

/*
    Calculates the damage the player will do to an enemy
*/
s32 marioCalcDamageToEnemy(s32 damageType, s32 tribeId); // 8012a3a8

/*
    Plays a random damage sound effect at the player's position
*/
void marioPlayDamageSfx(); // 8012a5e0

/*
    Handles an enemy attack
    Flags:
        0x4 don't display damage number
        0x100 inflict No Jump status
        0x200 inflict Slow status
        0x400 inflict No Skills status
        0x800 inflict Flipped Controls status
        0x1000 play Nastasia attack effect
        0x2000 freeze
        0x4000 sleep
        0x10000 inflict Poison status
        0x1, 0x10, 0x8000 unknown
*/
void marioTakeDamage(Vec3 * position, u32 flags, s32 damage); // 8012a680

/*
    Updates the entity being held with Thoreau
*/
void marioUpdateCatch(); // 8012ac28

/*
    Calculates the position for the entity being held with Thoreau
*/
void marioCalcCatchPos(Vec3 * posOut); // 8012ad1c

/*
    Drops the entity being held with Thoreau
*/
void marioDropCatch(); // 8012af74

// 8012b018 unknown function

/*
    Returns whether the player is in 3d
*/
bool marioCheck3d(); // 8012b080

// 8012b090, 8012b218, 8012b2c4, 8012b370,
// 8012b39c, 8012b498, 8012b4ac, 8012b4f8 unknown functions

/*
    Sets the player's gravity direction, see enum above
*/
void marioSetGravtiy(s32 dir); // 8012b50c

/*
    Returns the player's gravity direction, see enum above
*/
s32 marioGetGravity(); // 8012b6cc

/*
    Returns a downward unit vector for the current gravity
*/
void marioGetGravUnitDown(Vec3 * dest); // 8012b6dc

/*
    Changes the direction of a vector based on current gravity
*/
void marioApplyGravity(Vec3 * in, Vec3 * out); // 8012b6f4

/*
    Calculates the dot product of a vector with each direction's unit vector
*/
void marioGravityDotProduct(Vec3 * in, Vec3 * out); // 8012b784

// 8012b7f8, 8012ba68, 8012bb80 unknown functions

/*
    Changes the active pane boundaries and updates which pane the player is in
*/
void marioSetPaneBoundaries(MarioPaneBoundary * boundaries); // 8012bbd4 

/*
    Calculates the pane of a vector position
    -1 if no panes are defined or the position doesn't fall within any pane
*/
s32 marioGetPaneForPos(Vec3 * pos); // 8012bcec

/*
    Scales the player when they're unable to regrow fully when cancelling Dottie
*/
void marioHandleSquash(); // 8012bd5c

// 8012c0f8, 8012c188, 8012c218, 8012c948,
// 8012ca58, 8012caec, 8012cb00, 8012cb6c,
// 8012cbcc, 8012cc38, 8012cc98, 8012cd9c,
// 8012ce4c, 8012cea8, 8012cf20, 8012cf44 unknown functions

/*
    Forces respawn position
*/
void marioLockRespawnPos(Vec3 * pos, UNK); // 8012d180

/*
    Re-enables automatic respawn position calculation
*/
void marioUnlockRespawnPos(); // 8012d1c0

/*
    Forces the player model to face towards a point
*/
void marioLockFacingDir(Vec3 * target); // 8012d1e8

/*
    Re-enables free facing direction for the player model
*/
void marioUnlockFacing(); // 8012d218

// 8012d230, 8012d494 unknown functions

/*
    Spawns/removes Squirps following the player
*/
void marioAddTamara(); // 8012d81c
void marioRemoveTamara(); // 8012d890

// 8012d8b4	unknown function

/*
    Spawns/removes Luvbi following the player
*/
void marioAddAngeko(); // 8012d904
void marioRemoveAngeko(); // 8012d968

// 8012d98c, 8012d9fc, 8012dab0 unknown functions
