/*
    item_data.h defines the properties of the game's items
    See items.txt for a dump of this table
*/

typedef struct {
/* 0x00 */ const char * itemName;
/* 0x04 */ int16_t itemId;
/* 0x06 */ // unknown 0x6-7
/* 0x08 */ const char * animPoseName;
/* 0x0C */ // unknown 0xc-f
/* 0x10 */ const char * nameMsg;
/* 0x14 */ const char * descMsg;
/* 0x18 */ // unknown 0x18-2c
} ItemData; // total size 0x2c

ItemData itemDataTable[538]; // 803f5f98

