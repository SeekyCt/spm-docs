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
/* 0x08 */ // unknown 0x8-63
/* 0x64 */ s32 tutorialWindowId;
/* 0x68 */ // unknown 0x68-7f
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

// 80077724 unknown function

/*
    Handles the effect on the player and sound effects of picking up an item
*/
void itemHandlePickup(Vec3 * itemPos, s32 itemType); // 800777a8

// 80077c48, 80077c90 unknown functions

/*
    Updates items
*/
void itemMain(); // 80077cd8

/*
    Spawns an item
    Switch number is the script variable (usually GSWF) indicating if it's already bene collected
*/
ItemEntry * itemEntry(const char * name, s16 type, s16 behaviour, EvtScriptCode * pickupScript,
                      EvtVar switchNumber, float x, float y, float z); // 80078b3c

/*
    Despawns an item
*/
void itemDelete(const char * name); // 80079338

/*
    Gets an ItemEntry by name
*/
ItemEntry * itemNameToPtr(const char * name); // 800793e4

// 80079468, 800795b8, 80079814, 80079df4,
// 8007a2e0, 8007a598, 8007a758 unknown functions

/*
    Handles most of the pickup behaviour for items (deletion, xp, switchNumber etc),
    and calls itemHandlePickup for the rest
*/
s32 itemCollect(int entryId, ItemEntry * entry);

// 8007bc2c unknown function

/*
    Converts an item type name to the id for that item type
    Type names are the name field from items.txt with the following prefixes
        - ITEM_ID_USE_ for items with ids in the range 65-119 (inclusive)
        - ITEM_ID_COOK_ for items with ids in the range 120-215 (inclusive)
        - ITEM_ID_CARD_ for items with ids in the range 282-537 (inclusive)
    (Items that don't fall within any of these ranges can not be used)
*/
s32 itemTypeNameToId(const char * typeNmae); // 8007bccc

// 8007be24, 8007bee4, 8007c3b8, 8007c8ec,
// 8007ce34, 8007cfc0, 8007d1f4, 8007d454,
// 8007d568, 8007d684 unknown functions

/*
    Sets the current animation of an item
*/
void itemSetAnim(char * itemName,char * animName); // 8007d7c4

// 8007d868 unknown function

/*
    Checks for the existence of any items in the world with
    the specified item type id
*/
bool itemCheckForId(s32 typeId); // 8007d8b4

// 8007d8fc, 8007dc24, 8007dd50, 8007dd60,
// 8007de50, 8007e0e4 unknown functions
