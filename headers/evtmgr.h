/*
    Functions for managing evt scripts

    The script format is also used in TTYD, see ttydasm at https://github.com/PistonMiner/ttyd-tools
    (Note: there's an SPM-specific opcode missing in ttyd-opc-summary.txt, but the enum in ttydasm.cpp is accurate)
    As a brief summary, each instruction has the following format:
        s16 dataPieceCount
        s16 opcode
        s32 data[dataPieceCount]

    Note: this file has some progress in the decomp, see the link in README
*/

typedef s32 (user_func)(EvtEntry * entry, bool firstRun);

typedef s32 EvtScriptCode;

#define EVT_FLAG_IN_USE (1 << 0) 
#define EVT_FLAG_PAUSED (1 << 1)

typedef struct {
/* 0x000 */ s64 lifetime;
/* 0x008 */ u8 flags; // bit flags, 1 seems to be the script being active?
/* 0x009 */ u8 curDataLength; // number of pieces of data (4 bytes each) belonging to the current instruction
/* 0x00A */ u8 curOpcode; // see links above for opcodes
/* 0x00B */ u8 priority;
/* 0x00C */ u8 type;
/* 0x00D */ s8 blocked;
/* 0x00E */ u8 dowhileDepth; // number of do-while loops the current instruction is nexted into
/* 0x00F */ // unknown 0xf
/* 0x010 */ EvtScriptCode * pCurInstruction;
/* 0x014 */ EvtScriptCode * pCurData;
/* 0x018 */ s8 labelIds[16]; // each correspond to an address in the jump table
/* 0x028 */ void * jumptable[16]; // addresses for each label
/* 0x068 */ EvtEntry * parentEntry;
/* 0x06C */ EvtEntry * childEntry;
/* 0x070 */ EvtEntry * brotherEntry;
/* 0x074 */ // unknown 0x74-93
/* 0x094 */ user_func * userFunc; // Function set & called by the user_func opcode
/* 0x098 */ s32 lw[16];
/* 0x0D8 */ u32 lf[3];
/* 0x0E4 */ void * dowhileStartPtrs[8]; // pointer to instructions after do opcodes
/* 0x104 */ s32 dowhileIds[8];
/* 0x100 */ // unknown 0x104-14f
/* 0x150 */ s32 * uw;
/* 0x154 */ u32 * uf;
/* 0x158 */ s32 id;
/* 0x15C */ float speed;
/* 0x160 */ // unknown 0x160-167
/* 0x168 */ void * owner; // might always be an NPCEntry, unsure
/* 0x16C */ MobjEntry * ownerMobj;
/* 0x170 */ // unknown 0x170-173
/* 0x174 */ s32 msgWindowId;
/* 0x178 */ // unknown 0x178-187
/* 0x188 */ s32 msgPri;
/* 0x18C */ // unknown 0x18c-198
/* 0x198 */ EvtScriptCode * scriptStart;
/* 0x19C */ char * name; // debug thing, unused?
/* 0x1a0 */ void * pPrevInstruction;
/* 0x1a4 */ // unknown 0x1a4-7
} EvtEntry; // total size 0x1a8

typedef struct {
/* 0x00 */ s32 entryLimit;
/* 0x04 */ s32 gw[32];
/* 0x84 */ u32 gf[3];
/* 0x90 */ EvtEntry * entries;
/* 0x94 */ // padding 0x94-97
/* 0x98 */ s64 time;
} EvtWork; // total size 0xa0

EvtWork evtWork; // 8050c990

s32 evtMax; // 805ae8d8

EvtWork work; // 8050c990
s32 priTbl[0x80]; // 8050ca30
s32 priIdTbl[0x80]; // 8050cc30

s32 evtMax; // 805ae8d8
s32 priTblNum; // 805ae8dc
s32 runMainF; // 805ae8e0

s32 evtId = 1; // 805ae018
float evtSpd = 1.0; // 805ae01c

/*
    Returns the pointer to the instance of the EvtWork struct
*/  
EvtWork * evtGetWork(); // 800d87e4

/*
    Updates priTbl and priIdTbl with the current collection of entries
*/
void make_pri_table(); // 800d87f0

/*
    Scans through an entry's script to generate its jump table and label ids
*/
void make_jump_table(EvtEntry * entry); // 800d890c

/*
    Initialises data used in evtmgr code
*/
void evtmgrInit(); // 800d8a88
void evtmgrReInit(); // 800d8b2c

/*
    Start execution of scripts
*/
EvtEntry * evtEntry(EvtScriptCode * script, u8 priority, u8 flags); // 800d8b88
EvtEntry * evtEntryType(EvtScriptCode * script, u8 priority, u8 flags, u8 type); // 800d8df4
EvtEntry * evtChildEntry(EvtEntry * entry, EvtScriptCode * script, u8 flags); // 800d9060
EvtEntry * evtBrotherEntry(EvtEntry * entry, EvtScriptCode * script, u8 flags); // 800d9370

/*
    Restarts an entry
*/
EvtEntry * evtRestart(EvtEntry * entry); // 800d9634

/*
    Called every frame, updates each entry
*/
void evtmgrMain(); // 800d9764

/*
    Terminate an entry and all its children & brothers
    (can not be resumed, entry struct is freed)
*/
void evtDelete(EvtEntry * entry); // 800d9944
void evtDeleteId(s32 id); // 800d9b00

/*
    Returns whether an entry with this id exists
*/
bool evtCheckID(s32 id); // 800d9b88

/*
    Sets the execution priority of an entry
*/
void evtSetPri(EvtEntry * entry, u8 pri); // 800d9bd4

/*
    Sets the execution speed of an entry
*/
void evtSetSpeed(EvtEntry * entry, float speed); // 800d9bdc

/*
    Sets the type of an entry
*/
void evtSetType(EvtEntry * entry, u8 type); // 800d9bec

/*
    Stops the execution of an entry
    Unlike evtDelete, this can be resumed later
*/
void evtStop(EvtEntry * entry, u8 mask); // 800d9bf4

/*
    Resumes the execution of an entry
*/
void evtStart(EvtEntry * entry, u8 mask); // 800d9c98

/*
    Stops the execution of an entry by id
    Unlike evtDelete, this can be resumed later
*/
void evtStopId(s32 id); // 800d9d3c

/*
    Resumes the execution of an entry by id
*/
void evtStartId(s32 id); // 800d9dc8

/*
    Stops the execution of all entries
*/
void evtStopAll(u8 mask); // 800d9e54

/*
    Resumes the execution of all entries
*/
void evtStartAll(u8 mask); // 800d9ed4

/*
    Stops the execution of all other entries
*/
void evtStopOther(EvtEntry * entry, u8 mask); // 800d9f54

/*
    Resumes the execution of all other entries
*/
void evtStartOther(EvtEntry * entry, u8 mask); // 800d9fc8

/*
    Gives the pointer to an entry by its index in the array
*/
EvtEntry * evtGetPtr(s32 index); // 800da03c

/*
    Gives the pointer to an entry by its id
*/
EvtEntry * evtGetPtrId(s32 id); // 800da064
