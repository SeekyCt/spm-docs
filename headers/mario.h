/*
    Mario controls the player characters of the game
*/

enum {
    PLAYER_MARIO = 0,
    PLAYER_PEACH = 1,
    PLAYER_BOWSER = 2,
    PLAYER_LUIGI = 3
};

typedef struct {
/* 0x00 */ float hitboxWidth;
/* 0x04 */ float hitboxHeight;
/* 0x08 */ float startSpeed;
/* 0x0C */ float maxSpeed;
/* 0x10 */ // unknown 0x10-13
} CharacterProperties; // total size 0x14

CharacterProperties characterProperties[4]; // 804266c8, index enum above

enum {
    GRAV_DOWN = 0,
    GRAV_UP = 1,
    GRAV_LEFT = 2,
    GRAV_RIGHT = 3
};

#define MARIO_GRAVITY_MAX 4

typedef struct {
/* 0x0000 */ u32 flag0;
/* 0x0004 */ u32 flag4;
/* 0x0008 */ u32 flag8;
/* 0x000C */ u32 flagC;
/* 0x0010 */ u32 flag10;
/* 0x0014 */ u32 flag14;
/* 0x0015 */ // unknown 0x15-1b
/* 0x001C */ const char * curAnimName;
/* 0x0020 */ // unknown 0x20-2b
/* 0x002C */ u16 state;
/* 0x002E */ // unknown 0x2e-33
/* 0x0034 */ u8 ctrl;
/* 0x0035 */ u8 keyOff;
/* 0x0036 */ u16 cutsceneCount;
/* 0x0038 */ s8 character; // see enum above
/* 0x0039 */ // unknown 0x39-5b
/* 0x005C */ Vec3 position;
/* 0x0068 */ // unknown 0x68-bb
/* 0x00BC */ Vec3 playerScale;
/* 0x00C8 */ // unknown 0xc8-11f
/* 0x0120 */ s32 camId;
/* 0x0124 */ // unknown 0x124-127
/* 0x0128 */ s32 framebufferPosX;
/* 0x012C */ s32 framebufferPosY;
/* 0x0130 */ // unknown 0x130-14b
/* 0x014C */ float startSpeed;
/* 0x0150 */ float maxSpeed;
/* 0x0154 */ // unknown 0x154-193
/* 0x0194 */ float scaledHitboxWidth;
/* 0x0198 */ float scaledHitboxHeight;
/* 0x019C */ float HitboxWidth;
/* 0x01A0 */ float HitboxHeight;
/* 0x01A4 */ // unknown 0x1a4-1bb
/* 0x01BC */ HitObj * hitObjs1[10];
/* 0x01E4 */ // unknown 0x1e4-1fb
/* 0x01FC */ HitObj * hitObjs2[3];
/* 0x0208 */ // unknown 0x208-24b
/* 0x024C */ s32 animPoseIds[8]; // 8th is for slim flip model
/* 0x026C */ // unknown 0x26c-30b
/* 0x030C */ u16 buttonsHeld;
/* 0x030E */ u16 buttonsPressed;
/* 0x0310 */ u16 buttonsHeldRepeat;
/* 0x0312 */ u16 buttonsReleased;
/* 0x0314 */ // unknown 0x314-315
/* 0x0316 */ u8 pseudoJoystickX;
/* 0x0317 */ u8 pseudoJoystickY;
/* 0x0318 */ // unknown 0x318-3a3
/* 0x03A4 */ NPCEntry * caughtNpc; // Thoreau caught npc
/* 0x03A8 */ s32 catchType;
/* 0x03AC */ // unknown 0x3ac-3cf
/* 0x03D0 */ float scalarSpeed;
/* 0x03D4 */ // unknown 0x3d4-3d7
/* 0x03D8 */ Vec3 respawnPosition;
/* 0x03E4 */ // unknown 0x3e4-3eb
/* 0x03EC */ HitObj * hitObjRideArray[24];
/* 0x044C */ s32 numHitObjRideArray; // number of pointers in the array above
/* 0x0450 */ // unknown 0x450-9b7
/* 0x09B8 */ HitObj * hitObjHeadArray[20];
/* 0x0A08 */ s32 numHitObjHeadArray; // number of pointers in the array above
/* 0x0A0C */ // unknown 0xa0c-135f
/* 0x1360 */ s32 gravityType; // see enum above
/* 0x1364 */ // unknown 0x1364-147f
/* 0x1480 */ s32 nextCharacter;
/* 0x1484 */ s32 prevPixl;
/* 0x1488 */ s32 curPixl;
/* 0x148C */ // unknown 0x148c-156b
} MarioWork; // total size 0x156c

MarioWork marioWork; // 80510458

/*
    Returns a pointer to the MarioWork instance
*/
MarioWork * marioGetPtr(); // 80121f48

/*
    Returns whether player movement is blocked (true in things like dialogue)
*/
bool marioIsMovementDisabled(); // 80122b7c

bool marioChkSts(); // 80122d1c
void marioResetHitObj(const char * name);   // 80122d90
void marioReset(); // 80122fa8
void marioSoundInit(); // 80123268
void marioOfsRotReset(); // 801231c0
void marioPoseInit(); // 80123288
void marioInit(); // 8012339c
void marioMain(); // 801243a8

/*
    Sets the player's gravity direction, see enum above
*/
void marioSetGravtiy(s32 dir); // 8012b50c

/*
    Returns the player's gravity direction, see enum above
*/
s32 marioGetGravity(); // 8012b6cc

// a lot of unknown functions
