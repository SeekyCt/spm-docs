#DEFINE MAP_ID_MAX 0x1d4

typedef struct {
  char * name;
  char * nameAgain; // initialised as the exact same pointer, maybe changed later on?
  // unknown 0x8-17
  void * evtScript; // In rel, linked by prolog function. See https://github.com/PistonMiner/ttyd-tools
} MapData;

static MapData ** MapDataList; // 804031b8

MapData * getMapData(char * mapName); // 800294e0
