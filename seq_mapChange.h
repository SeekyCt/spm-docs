/*
    seq_mapChange is the sequence (see seqdrv.h) that loads a map
*/

typedef struct {
/* 0x00 */ char areaName[3]; // always(?) first 3 characters of map name
/* 0x03 */ // unknown 0x3-1f
/* 0x20 */ char mapName[32];
/* 0x40 */ char doorName[32]; // door the map was entered with
/* 0x60 */ EvtEntry * initEvtEntry;
/* 0x64 */ int initEvtEntryId;
/* 0x68 */ // unknown 0x68-73
} SeqMapChangeWork; // total size 0x74

SeqMapChangeWork * seqMapChangeWp; // 805ae0a8
SeqMapChangeWork seqMapChangeWork; // 80512240

void seq_mapChangeInit(SeqWork * p); // 8017a33c
void seq_mapChangeExit(SeqWork * p); // 8017a460
void seq_mapChangeMain(SeqWork * p); // 8017a464
void _unload(const char * curMapName, const char * nextMapName, const char * doorName); // 8017af98
