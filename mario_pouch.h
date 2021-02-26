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
/* 0x2 */ int16_t itemType; // see items.txt
} PouchCharOrPixlInfo; // total size 0x4

/*
    This struct is copied in full to & from the save file
*/
typedef struct {
/* 0x000 */ // unknown 0x0-3
/* 0x004 */ int level;
/* 0x008 */ int attack;
/* 0x00C */ int hp;
/* 0x010 */ int maxHp;
/* 0x014 */ // unknown 0x14-17
/* 0x018 */ int xp;
/* 0x01C */ int coins;
/* 0x020 */ int16_t keyItem[32];
/* 0x060 */ int16_t useItem[10];
/* 0x074 */ int16_t shopItem[32];
/* 0x0B4 */ PouchCharOrPixlInfo characters[4];
/* 0x0C4 */ PouchCharOrPixlInfo pixls[16];
/* 0x104 */ // unknown 0x104-69f
} MarioPouchWork; // total size 0x6a0

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
void pouchSetLevel(int level); // 8014d1bc
int pouchGetLevel(); // 8014d1f0

/*
    Returns the xp required by the next level
*/
int pouchGetnextLevelXp(); // 8014d200

/*
    Set/get/add to the player's attack power
*/
void pouchSetAttack(int attack); // 8014d394
int pouchGetAttack(); // 8014d3c8
void pouchAddAttack(int increase); // 8014d3d8

/*
    Set/get/add to the player's HP
*/
void pouchSetHp(int hp); // 8014d414
int pouchGetHp(); // 8014d458
void pouchAddHp(int increase); // 8014d468

/*
    Set/get the player's max HP
*/
void pouchSetMaxHp(int maxHp); // 8014d4b4
int pouchGetMaxHp(); // 8014d4e8

/*
    Get/add to the player's xp
*/
int pouchGetXp(); // 8014d4f8
void pouchAddXp(int increase); // 8014d508

/*
    Set/get/add to the player's coin count
*/
void pouchSetCoins(int coins); // 8014d548
int pouchGetCoins(); // 8014d57c
void pouchAddCoins(int increase); // 8014d58c

void pouchRemoveItemIdx(int itemId, int idx); // 8014e6d0

/*
    Get the information about a character slot
*/
PouchCharOrPixlInfo * pouchGetCharInfo(int slot); // 8014ef98

/*
    Make a character selectable by id, if it exists in a slot
*/
void pouchMakeCharSelectable(int itemId); // 8014efb0

/*
    Get the information about a pixl slot
*/
PouchCharOrPixlInfo * pouchGetPixlinfo(int slot); // 8014f080

/*
    Make a pixl selectable/not by id, if it exists in a slot
*/
void pouchMakePixlSelectable(int itemId); // 8014f098
void pouchMakePixlNotSelectable(int itemId); // 8014f154

/*
    Check if a pixl is selected by id
*/
void pouchIsPixlSelected(int itemId); // 8014f210

/*
    Returns the id of the currently selected pixl
*/
int pouchGetCurPixl(); // 8014f31c

/*
    Makes a pixl selected by id, if it exists in a slot
    Deselects all other pixls
*/
void pouchSetPixlSelected(int itemId); // 8014f408

/*
    Returns the number of useItem/keyItem/shopItem/char/pixl slots that aren't empty [and aren't selected]
*/
int pouchCountUseItems(); // 8014fa20
int pouchCountKeyItems(); // 8014fad0
int pouchCountShopItems(); // 8014fb78
int pouchCountChars(); // 8014fc20
int pouchCountPixls(); // 8014fc70
int pouchCountPixlsNotSelected(); // 8014fd18

/*
    Returns whether any useItem slot is emtpy
*/
bool pouchCheckFreeUseItem(); // 8014fdb0

// a lot of unknown functions
