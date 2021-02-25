/*
    Fairy controls pixl entities in game
*/

#define FAIRYRunEnd 7

typedef struct {
/* 0x00 */ // unknown 0x0-47
/* 0x48 */ Vec3 position;
/* 0x54 */ // unknown 0x54-cf
} FairyEntry; // total size 0xd0

typedef struct {
/* 0x000 */ // unknown 0x-3
/* 0x004 */ FairyEntry entries[4];
/* 0x344 */ int max; // 4
/* 0x348 */ int num;
/* 0x34C */ int numExtra;
/* 0x350 */ // unknown 0x350-367
} FairyWork; // total size 0x368

FairyWork fairyWork; // 80510030
#define fairyFrp (&fairyWork)

// 8011ceb4, 8011d300, 8011d3bc, 8011d440, unknown functions  

/*
    Creates a fairy entry based on information in pouch
*/
void fairyEntry(); // 8011d58c

// 8011d8f4 unknown function

/*
    Initialises data used in fairy code
*/
void fairyInit(); // 8011d8f8

void fairyExtraEntry(int extraNo); // 8011f6a0

/*
    Sets position of all fairies
*/
void fairySetAllPositions(Vec3 * position); // 8011f258

// a lot of unknown functions
