/*
    Pouch stores information like xp, HP, items and unlocked pixls
    Note: unlocked characters and pixls are treat as items internally
*/

#define ITEM_ID_USE_START 0x41
#define ITEM_ID_USE_MAX 0xd8
#define ITEM_ID_MAP_START 0xea
#define ITEM_ID_MAP_MAX 0x11a
#define ITEM_ID_COOK_START 0x78
#define ITEM_ID_COOK_MAX 0xd8
#define ITEM_ID_CARD_START 0x11a
#define ITEM_ID_CARD_MAX 0x21a


typedef struct {
/* 0x0 */ bool selectable;
/* 0x1 */ bool selected;
/* 0x2 */ s16 itemType; // see items.txt
} PouchCharOrPixlInfo; // total size 0x4

typedef struct {
/* 0x00 */ s32 characterId;
/* 0x04 */ s32 score;
/* 0x08 */ // unknown 0x8-17
} PouchMinigameScore; // total size 0x18

/*
    This struct is copied in full to & from the save file
*/
typedef struct {
/* 0x000 */ // unknown 0x0-3, unused?
/* 0x004 */ s32 level;
/* 0x008 */ s32 attack;
/* 0x00C */ s32 hp;
/* 0x010 */ s32 maxHp;
/* 0x014 */ s32 flipTimer;
/* 0x018 */ s32 xp;
/* 0x01C */ s32 coins;
/* 0x020 */ s16 keyItem[32];
/* 0x060 */ s16 useItem[10];
/* 0x074 */ s16 shopItem[32];
/* 0x0B4 */ PouchCharOrPixlInfo characters[4];
/* 0x0C4 */ PouchCharOrPixlInfo pixls[16];
/* 0x104 */ s32 shopPoints;
/* 0x108 */ u32 shopPointRewardsCollected; // bit mask, index 1 << i
/* 0x10C */ s8 catchCards[256]; // value is the amount currently owned, index is item id minus the first card item id (282)
/* 0x20C */ // unknown 0x20c-30b
/* 0x30C */ u32 ownedMaps[2]; // maps currently in inventory, index [id / 32] & 1 << (id % 32)
/* 0x314 */ u32 foundMaps[2]; // maps with rewards claimed, index [id / 32] & 1 << (id % 32)
/* 0x31C */ u32 knownRecipes[3]; // index [id / 32] & 1 << (id % 32)
/* 0x328 */ u32 knownCards[8]; // flags indicating if a card was ever collected, index [id / 32] & 1 << (id % 32)
/* 0x348 */ s32 charmsRemaining;
/* 0x34C */ s32 killsBeforeNextCharm;
/* 0x350 */ // unknown 0x350-367
/* 0x368 */ PouchMinigameScore minigameScores[4][5];
/* 0x548 */ // unknown 0x548-687
/* 0x688 */ s32 arcadeTokens;
/* 0x68C */ s32 totalCoinsCollected;
/* 0x690 */ s32 maxJumpCombo;
/* 0x694 */ s32 maxStylishCombo;
/* 0x698 */ s32 enemiesDefeated;
/* 0x69C */ // unknown 0x69c-69f
} MarioPouchWork; // total size 0x6a0

MarioPouchWork marioPouchWork; // 80511a28

/*
    Returns a pointer to the MarioPouchWork instance
*/
MarioPouchWork * pouchGetPtr(); // 8014c088

/*
    Initialise data used by pouch functions
    Overwritten later once a save is loaded
*/
void pouchInit(); // 8014c094
void pouchReInit(); // 8014c728

void pouchMain(); // 8014cd90

/*
    Set/get the player's level
*/
void pouchSetLevel(s32 level); // 8014d1bc
s32 pouchGetLevel(); // 8014d1f0

/*
    Returns the xp required by the next level
*/
s32 pouchGetnextLevelXp(); // 8014d200

/*
    Set/get/add to the player's attack power
*/
void pouchSetAttack(s32 attack); // 8014d394
s32 pouchGetAttack(); // 8014d3c8
void pouchAddAttack(s32 increase); // 8014d3d8

/*
    Set/get/add to the player's HP
*/
void pouchSetHp(s32 hp); // 8014d414
s32 pouchGetHp(); // 8014d458
void pouchAddHp(s32 increase); // 8014d468

/*
    Set/get the player's max HP
*/
void pouchSetMaxHp(s32 maxHp); // 8014d4b4
s32 pouchGetMaxHp(); // 8014d4e8

/*
    Get/add to the player's xp
*/
s32 pouchGetXp(); // 8014d4f8
void pouchAddXp(s32 increase); // 8014d508

/*
    Set/get/add to the player's coin count
*/
void pouchSetCoins(s32 coins); // 8014d548
s32 pouchGetCoins(); // 8014d57c
void pouchAddCoins(s32 increase); // 8014d58c, increases totalCoinsCollected

void pouchRemoveItemIdx(s32 itemId, s32 idx); // 8014e6d0

/*
    Get the information about a character slot
*/
PouchCharOrPixlInfo * pouchGetCharInfo(s32 slot); // 8014ef98

/*
    Make a character selectable by id, if it exists in a slot
*/
void pouchMakeCharSelectable(s32 itemId); // 8014efb0

/*
    Get the information about a pixl slot
*/
PouchCharOrPixlInfo * pouchGetPixlinfo(s32 slot); // 8014f080

/*
    Make a pixl selectable/not by id, if it exists in a slot
*/
void pouchMakePixlSelectable(s32 itemId); // 8014f098
void pouchMakePixlNotSelectable(s32 itemId); // 8014f154

/*
    Check if a pixl is selected by id
*/
void pouchIsPixlSelected(s32 itemId); // 8014f210

/*
    Returns the id of the currently selected pixl
*/
s32 pouchGetCurPixl(); // 8014f31c

/*
    Makes a pixl selected by id, if it exists in a slot
    Deselects all other pixls
*/
void pouchSetPixlSelected(s32 itemId); // 8014f408

/*
    Returns how many coins have ever been collected on this save
*/
s32 pouchGetTotalCoinsCollected(); // 8014f99c

/*
    Returns/sets how many enemies have ever been defeated on this save
*/
s32 pouchGetEnemiesDefeated(); // 8014f9cc
void pouchSetEnemiesDefeated(s32 totalDefeated); // 8014f978

/*
    Returns the number of useItem/keyItem/shopItem/char/pixl slots that aren't empty [and aren't selected]
*/
s32 pouchCountUseItems(); // 8014fa20
s32 pouchCountKeyItems(); // 8014fad0
s32 pouchCountShopItems(); // 8014fb78
s32 pouchCountChars(); // 8014fc20
s32 pouchCountPixls(); // 8014fc70
s32 pouchCountPixlsNotSelected(); // 8014fd18

/*
    Returns whether any useItem slot is emtpy
*/
bool pouchCheckFreeUseItem(); // 8014fdb0

// a lot of unknown functions
