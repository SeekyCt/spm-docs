/*
    Definitions used for loading maps
*/

#define MAP_ID_MAX 0x1d4

typedef struct {
/* 0x00 */ const char * name;
/* 0x04 */ const char * filename;
/* 0x08 */ const char * fallbackDoorName; // door name used if entered with a null name, ignored if this is null
/* 0x0C */ Vec3 fallbackSpawnPos; // position to use when entered with a null door name and fallbackDoorName isn't set
/* 0x18 */ EvtScriptCode * initScript; // In rel, linked by prolog function. See evtmgr.h
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
