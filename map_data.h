/*
    Definitions used for loading maps
*/

#define MAP_ID_MAX 0x1d4

typedef struct {
/* 0x00 */ char * name;
/* 0x04 */ char * filename;
/* 0x08 */ // unknown 0x8-17
/* 0x18 */ void * initScript; // In rel, linked by prolog function. See evtmgr.h
} MapData; // total size 0x1c

MapData * mapDataList[MAP_ID_MAX]; // 804031b8

/*
    Returns the MapData for a map by name
*/
MapData * mapDataPtr(const char * mapName); // 800294e0

/*
    Returns the init script for a map by anme
*/
EvtScriptCode * mapDataEvtPtr(const char * mapName); // 800295a8
