/*
    Itemdrv handles in-world items
    See items.txt for a list of item types
*/

#define ITEM_NAME_MAX 12

typedef struct {
/* 0x00 */ uint32_t flags
/* 0x04 */ char name[ITEM_NAME_MAX];
/* 0x10 */ int16_t type; // see items.txt
/* 0x12 */ int16_t behaviour;
/* 0x14 */ Vec3 position
/* 0x20 */ // unknown 0x20-23
/* 0x24 */ IconEntry * icon;
/* 0x28 */ int animPoseId;
/* 0x2C */ int switchNumber; // evt variable
/* 0x30 */ EvtScriptCode * pickupScript;
/* 0x34 */ // unknown 0x34-87
} ItemEntry; // total size 0x80

typedef struct {
/* 0x00 */ int num; // 0x100
/* 0x04 */ ItemEntry * entries; // array of num
/* 0x08 */ // unknown 0x8-7f
} ItemWork; // total size 0x80

typedef struct {
/* 0x00 */ const char * itemName;
/* 0x04 */ // unknown 0x4-7
/* 0x08 */ const char * animPoseName;
/* 0x0C */ // unknown 0xc-f
/* 0x10 */ const char * nameMsg;
/* 0x14 */ const char * descMsg;
/* 0x18 */ // unknown 0x18-2c
} ItemData; // total size 0x2c

ItemData itemDataTable[538]; // 803f5f98

ItemWork * itemWork; // 8050bad8
ItemWork * itemWp; // 805adfe0

/*
    Returns a pointer to the ItemWork instance
*/
ItemWork * itemGetWork(); // 80077660

/*
    Initialise data used by item functions
*/
void itemInit(); // 80077668
void itemReInit(); // 800776dc

/*
    Updates items
*/
void itemMain(); // 80077cd8

/*
    Spawns an item
*/
ItemEntry * itemEntry(const char * name, int16_t type, int16_t behaviour, EvtScriptCode * pickupScript,
                      int switchNumber, float x, float y, float z); // 80078b3c

/*
    Despawns an item
*/
void itemDelete(const char * name); // 80079338

/*
    Gets an ItemEntry by name
*/
ItemEntry * itemNameToPtr(const char * name); // 800793e4

// a lot of unknown functions
