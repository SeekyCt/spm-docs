/*
    Itemdrv handles in-world items
    See item_data.h and item_event_data.h for how item properties are defined 
*/

#define ITEM_NAME_MAX 12

typedef struct {
/* 0x00 */ u32 flags
/* 0x04 */ char name[ITEM_NAME_MAX];
/* 0x10 */ s16 type; // see items.txt
/* 0x12 */ s16 behaviour;
/* 0x14 */ Vec3 position
/* 0x20 */ // unknown 0x20-23
/* 0x24 */ IconEntry * icon;
/* 0x28 */ s32 animPoseId;
/* 0x2C */ s32 switchNumber; // evt variable
/* 0x30 */ EvtScriptCode * pickupScript;
/* 0x34 */ // unknown 0x34-87
} ItemEntry; // total size 0x80

typedef struct {
/* 0x00 */ s32 num; // 0x100
/* 0x04 */ ItemEntry * entries; // array of num
/* 0x08 */ // unknown 0x8-7f
} ItemWork; // total size 0x80

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
ItemEntry * itemEntry(const char * name, s16 type, s16 behaviour, EvtScriptCode * pickupScript,
                      s32 switchNumber, float x, float y, float z); // 80078b3c

/*
    Despawns an item
*/
void itemDelete(const char * name); // 80079338

/*
    Gets an ItemEntry by name
*/
ItemEntry * itemNameToPtr(const char * name); // 800793e4

// a lot of unknown functions
