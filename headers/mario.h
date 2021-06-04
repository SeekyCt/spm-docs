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
/* 0x0000 */ u32 flags;
/* 0x0004 */ // unknown 0x4-34
/* 0x0035 */ bool disableMovement;
/* 0x0036 */ // unknown 0x36-37
/* 0x0038 */ s8 character; // see enum above
/* 0x0039 */ // unknown 0x39-5b
/* 0x005C */ Vec3 position;
/* 0x0068 */ // unknown 0x68-11f
/* 0x0120 */ s32 camId;
/* 0x0124 */ // unknown 0x124-14b
/* 0x014C */ float startSpeed;
/* 0x0150 */ float maxSpeed;
/* 0x0154 */ // unknown 0x154-193
/* 0x0194 */ float scaledHitboxWidth;
/* 0x0198 */ float scaledHitboxHeight;
/* 0x019C */ float HitboxWidth;
/* 0x01A0 */ float HitboxHeight;
/* 0x01A4 */ // unknown 0x1a4-1b3
/* 0x01B4 */ HitEntry * hitObjs1[10];
/* 0x01E4 */ // unknown 0x1e4-1fb
/* 0x01FC */ HitEntry * hitObjs2[3];
/* 0x0208 */ // unknown 0x208-24b
/* 0x024C */ s32 animPoseIds[5];
/* 0x0260 */ // unknown 0x260-3cf
/* 0x03D0 */ float scalarSpeed;
/* 0x03D4 */ // unknown 0x3d4-3d7
/* 0x03D8 */ Vec3 respawnPosition;
/* 0x03E4 */ // unknown 0x3e4-135f
/* 0x1360 */ s32 gravityType; // see enum above
/* 0x1364 */ // unknown 0x1364-156b
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
