/*
    npcdrv handles the spawning, updating and deleting of NPCs ('actors') inthe game
    NPCS include enemies, friendly characters and some projectiles, but not players or objects (like question blocks)
    See also setup_data.h and setupfiles.md
*/

typedef struct {
/* 0x00 */ // unknown 0x0-48
} NPCPartDef; // total size 0x48

typedef struct {
/* 0x0 */ int id;
/* 0x4 */ const char * animName;
} NPCTribeAnimDef; // total size 0x8

typedef struct {
/* 0x0 */ int itemId;
/* 0x4 */ int chance;
} DropItem; // total size 0x4

typedef struct {
/* 0x00 */ const char * animPoseName;
/* 0x04 */ NPCTribeAnimDef * animDefs; // list terminated by one with id -1
/* 0x08 */ // unknown 0x8-17
/* 0x18 */ uint8_t maxHp;
/* 0x19 */ uint8_t partsCount;
/* 0x1A */ // unknown 0x1a-1b
/* 0x1C */ NPCPartDef * partsList; // partsCount length
/* 0x20 */ // unknown 0x20-4d
/* 0x4E */ uint16_t dropItemChance; // chance of dropping any item
/* 0x50 */ DropItem * dropItemList; // terminated by an entry with id 0
/* 0x54 */ // unknown 0x54-63
/* 0x64 */ uint8_t attackStrength; // seems to only be used for the tattle and doesn't actually affect damage
/* 0x65 */ // unknown 0x54-67
} NPCTribe; // total size 0x68

typedef struct {
/* 0x00 */ int m_nPoseId;
/* 0x04 */ char animPoseName[32];
/* 0x24 */ // unknown 0x24-47
/* 0x48 */ NPCTribeAnimDef * tribeAnims;
/* 0x4C */ // unknown
} NPCAnim; // unknown size

typedef struct {
/* 0x000 */ // unknown 0x0-397
} NPCParts; // total size 0x398

typedef struct {
/* 0x000 */ int id;
/* 0x004 */ int setupFileIndex; // 1-based index, 0 if not spawned from a setup file
/* 0x008 */ uint32_t flags_8;
/* 0x00C */ uint32_t flags_c;
/* 0x010 */ uint32_t flags_10;
/* 0x014 */ // unknown 0x14-23
/* 0x024 */ char name[32]; // name of this instance, npc_XXXXXXXX for template-spawned ones where XXXXXXXX is id in hex
/* 0x044 */ NPCAnim m_Anim;
/* ????? */ // unknown up to 0x29f
/* 0x2A0 */ Vec3 position;
/* 0x2AC */ // unknown 0x2ac-347
/* 0x348 */ EvtScriptCode * templateUnkScript1; // unkScript1 from spawning SetupEnemyTemplate (unknown for non-templated NPCs)
/* 0x34C */ // unknown 0x34c-35f
/* 0x360 */ EvtScriptCode * templateUnkScript2; // unkScript2 from spawning SetupEnemyTemplate (unknown for non-templated NPCs)
/* 0x364 */ EvtScriptCode * templateUnkScript3; // unkScript3 from spawning SetupEnemyTemplate (unknown for non-templated NPCs)
/* 0x368 */ EvtScriptCode * templateUnkScript4; // unkScript4 from spawning SetupEnemyTemplate (unknown for non-templated NPCs)
/* 0x36C */ EvtScriptCode * templateUnkScript5; // unkScript5 from spawning SetupEnemyTemplate (unknown for non-templated NPCs)
/* 0x370 */ EvtScriptCode * templateUnkScript9; // unkScript9 from spawning SetupEnemyTemplate (unknown for non-templated NPCs)
/* 0x374 */ EvtScriptCode * templateUnkScript6; // unkScript6 from spawning SetupEnemyTemplate (unknown for non-templated NPCs)
/* 0x378 */ EvtScriptCode * templateUnkScript7; // unkScript7 from spawning SetupEnemyTemplate (unknown for non-templated NPCs)
/* 0x37C */ EvtScriptCode * templateUnkScript8; // unkScript8 from spawning SetupEnemyTemplate (unknown for non-templated NPCs)
/* 0x380 */ // unknown 0x380-38f
/* 0x390 */ int onSpawnEvtId; // id of the EvtEntry running a templated npc's onSpawn scripts (unknown for non-templated NPCs)
/* 0x394 */ // unknown 0x394-39b
/* 0x39C */ float tribeField0xE; // field 0xe of spawning NPCTribe cast to float 
/* 0x3A0 */ float tribeField0x10; // field 0x10 of spawning NPCTribe cast to float
/* 0x3A4 */ float tribeField0x12; // field 0x12 of spawning NPCTribe cast to float
/* 0x3A8 */ // unknown 0x3a8-477
/* 0x478 */ uint32_t tribeField0x54; // field 0x54 of spawning NPCTribe
/* 0x47C */ // unknown 0x47c-49b
/* 0x49C */ int tribeId; // id of the NPCTribe this NPC was spawned with
/* 0x4A0 */ int tribeId2; // seemingly just a copy of tribeId 
/* 0x4A4 */ // unknown 0x4a4-4eb
/* 0x4EC */ uint32_t maxHp; // copied from spawning NPCTribe, 1 for NPCs not spawned by tribe
/* 0x4F0 */ uint32_t hp; // copied from spawning NPCTribe, 1 for NPCs not spawned by tribe
/* 0x4F4 */ // unknown 0x4F4-573
/* 0x574 */ int dropItemId; // id of the item this npc would drop if killed (determined on spawn)
/* 0x578 */ // unknown 0x578-57b
/* 0x57C */ uint32_t templateField0x5C; // field 0x5c of spawning SetupEnemyTemplate (unknown for non-templated NPCs)
/* 0x580 */ uint32_t templateField0x60; // field 0x60 of spawning SetupEnemyTemplate (unknown for non-templated NPCs)
/* 0x584 */ uint32_t templateField0x64; // field 0x64 of spawning SetupEnemyTemplate (unknown for non-templated NPCs)
/* 0x588 */ // unknown 0x588-0x713
/* 0x714 */ NPCParts * parts; // made from tribe's NPCPartDef list
/* 0x718 */ EvtScriptCode * templateUnkScript10; // unkScript10 from spawning SetupEnemyTemplate (unknown for non-templated NPCs)
/* 0x71C */ // unknown 0x71c-747
} NPCEntry; // total size 0x748

typedef struct {
/* 0x000 */ uint32_t flag;
/* 0x004 */ int num;
/* 0x008 */ NPCEntry * entries;
/* 0x00C */ // unknown 0xc-13
/* 0x014 */ int nextTemplateNpcId;
/* 0x018 */ SetupFileV6 * setupFile; // always updated to be v6 on load, see setup_data.h
/* 0x01C */ // unknown 0x1c-b47
} NPCWork; // total size 0xb48

NPCWork npcWork; // 805283e0
NPCWork * npcdrvWp; // 805ae188

typedef bool (EnemyCanSpawnFunction)();

typedef struct {
/* 0x00 */ // unknown byte
/* 0x01 */ // unknown byte
/* 0x02 */ // unknown byte
/* 0x03 */ // unknown byte
/* 0x04 */ int instanceId; // left blank to be copied from SetupEnemy
/* 0x08 */ // unknown 0x8-b
/* 0x0C */ EnemyCanSpawnFunction * canSpawnFunction;
/* 0x10 */ // unknown 0x10-13
/* 0x14 */ int tribeId;
/* 0x18 */ const char * instanceName; // overrides instanceName of NPC spawned if not null
/* 0x1C */ const char * japaneseName; // unused debug information?
/* 0x20 */ Vec3 pos; // left blank to be copied from SetupEnemy
/* 0x2C */ uint32_t flags; // ORd with NPCEntry's flags after spawning
/* 0x30 */ EvtScriptCode * onSpawnScript;
/* 0x34 */ EvtScriptCode * unkScript1;
/* 0x38 */ EvtScriptCode * unkScript2;
/* 0x3C */ EvtScriptCode * unkScript3;
/* 0x40 */ EvtScriptCode * unkScript4;
/* 0x44 */ EvtScriptCode * unkScript5;
/* 0x48 */ EvtScriptCode * unkScript6;
/* 0x4C */ EvtScriptCode * unkScript7;
/* 0x50 */ EvtScriptCode * unkScript8;
/* 0x54 */ EvtScriptCode * unkScript9;
/* 0x58 */ EvtScriptCode * unkScript10;
/* 0x5C */ // unknown 0x5c-67, all left blank to be copied from SetupEnemy
} NPCEnemyTemplate;

NPCTribe npcTribes[535]; // 8043bf30, see npctribes.txt
NPCEnemyTemplate npcEnemyTemplates[435]; // 80449888, npcenemytemplates.txt

void npcInit(); // 801a96fc
void npcReset(); // 801a97b8
void npcMain(); // 801a9878
NPCEntry * npcEntry(const char * instanceName, const char * animPoseName, int instanceId, int param_4); // 801b6430
NPCEntry * npcIdToPtr(int id); // 801b6ee4
NPCEntry * npcNameToPtr(const char * instanceName); // 801b6f2c
NPCEntry * npcNameToPtr_NoAssert(const char * instanceName); // 801b6fd4
NPCEntry * npcEntryFromTemplate(NPCEnemyTemplate * enemyTemplate); // 801be198
bool npcAreOnSpawnEvtsDone(); // 801be638
NPCEntry * npcEntryFromSetupEnemy(int setupFileIndex, Vec3 * pos, int nTemplateNo, MiscSetupDataV6 * miscSetupData); // 801bf7a0
int npcGetNextTemplateNpcId(); // 801bfc08
bool npcReadSetupFile(const char * mapName, bool reAllocate); // 801c045c
void npcUpdateSetupFile0To1(SetupFileV0 * file); // 801c077c
void npcUpdateSetupFile1To2(SetupFileV1 * file); // 801c0a90
void npcUpdateSetupFile2To3(SetupFileV2 * file); // 801c0d10
void npcUpdateSetupFile3To4(SetupFileV3 * file); // 801c11ac
void npcUpdateSetupFile4To5(SetupFileV4 * file); // 801c16b0
void npcUpdateSetupFile5To6(SetupFileV5 * file); // 801c1b5c
void npcUpdateSetupFile(void * file); // 801c2074
NPCEntry * npcGetEntries(); // 801c2124
int npcGetMaxEntries(); // 801c2130
NPCParts * npcAddPart(NPCEntry * entry, NPCPartDef * partDef); // 801c2148
NPCTribe * npcGetTribe(int tribeId); // 801c9ac8
NPCWork * npcGetWorkPtr(); // 801c9adc

// a lot of unknown functions
