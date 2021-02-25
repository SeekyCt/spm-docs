#define MAP_ID_MAX 0x1d4

typedef struct {
/* 0x00 */ char * name;
/* 0x04 */ char * filename;
/* 0x08 */ // unknown 0x8-17
/* 0x18 */ void * initScript; // In rel, linked by prolog function. See evtmgr.h
} MapData; // total size 0x1c

MapData * mapDataList[MAP_ID_MAX]; // 804031b8

MapData * mapDataPtr(char * mapName); // 800294e0
void * mapDataEvtPtr(char * mapName); // 800295a8
