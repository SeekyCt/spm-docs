#DEFINE MAP_ID_MAX 0x1d4

typedef struct {
  char * name;
  char * nameAgain; // initialised as the exact same pointer, maybe changed later on?
  // unknown 0x8-17
  void * evtScript; // In rel, linked by prolog function. See https://github.com/PistonMiner/ttyd-tools
} MapData;
MapData * mapDataList[MAP_ID_MAX]; // 804031b8

typedef struct {
  char areaName[3]; // always(?) first 3 characters of map name
  // unknown 0x3-1f
  char mapName[32];
  char doorName[32]; // door the map was entered with
  EvtEntry * evtEntry;
  // unknown 0x64-73
} MapHandler;
MapHandler * mapHandler; // 805ae0a8

MapData * mapDataPtr(char * mapName); // 800294e0
void * mapDataEvtPtr(char * mapName); // 800295a8
