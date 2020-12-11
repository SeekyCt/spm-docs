/*
The script format is also used in TTYD, see ttydasm at https://github.com/PistonMiner/ttyd-tools
(Note: there's an SPM specific opcode missing in ttyd-opc-summary.txt, but the enum in ttydasm.cpp is accurate)
As a brief summary, each instruction has the following format:
  halfword dataPieceCount
  halfword opcode
  word data[dataPieceCount]
*/

typedef int (*user_func)(EvtEntry * entry, bool firstRun);

typedef struct {
  int64_t lifetime;
  uint8_t flags; // bit flags, 1 seems to be the script being active?
  uint8_t curDataLength; // number of pieces of data (4 bytes each) belonging to the current instruction
  uint8_t curOpcode; // see links above for opcodes
  uint8_t priority;
  uint8_t type;
  int8_t blocked;
  uint8_t dowhileDepth; // number of do-while loops the current instruction is nexted into
  // unknown 0xf
  void * curInstructionPtr;
  void * curDataPtr;
  uint8_t labelIds[16]; // each correspond to an address in the jump table
  void * jumptable[16]; // addresses for each label
  EvtEntry * parentEntry;
  EvtEntry * childEntry;
  EvtEntry * brotherEntry;
  // unknown 0x74-93
  user_func * userFunc; // Function set & called by the user_func opcode
  int lw[16];
  uint32_t lf[3];
  void * dowhileStartPtrs[8]; // pointer to do opcodes
  int dowhileCounters[8];
  // unknown 0x104-14f
  int * uw;
  uint32_t * uf;
  int id;
  float speed;
  // unknown 0x160-197
  int * scriptStart;
  char * name;
  void * prevInstructionPtr;
  // unknown 0x1a4-7
} EvtEntry;

typedef struct {
  int entryLimit;
  uint32_t gw[32];
  uint32_t gf[3];
  EvtEntry * entries;
  // padding 0x94-97
  int64_t time;
} EvtWork;
EvtWork evtWork; // 8050c990

int evtEntryCount; // 805ae8d8

EvtWork * evtGetWork(); // 800d87e4
void make_pri_table(); // 800d87f0
void make_jump_table(EvtEntry * entry); // 800d890c
void evtmgrInit(); // 800d8a88
void evtmgrReInit(); // 800d8b2c
EvtEntry * evtEntry(int * script, uint8_t priority, uint8_t flags); // 800d8b88 - inits an entry for a script
EvtEntry * evtEntryType(int * script, int param_2, int param_3, int param_4); // 800d8df4
EvtEntry * evtChildEntry(EvtEntry * entry, int * script, uint8_t flags); // 800d9060
EvtEntry * evtBrotherEntry(EvtEntry * entry, int * script, uint8_t flags); // 800d9370
EvtEntry * evtRestart(EvtEntry * entry); // 800d9634
void evtmgrMain(); // 800d9764
void evtDelete(EvtEntry * entry); // 800d9944
void evtDeleteId(int id); // 800d9b00
bool evtCheckID(int id); // 800d9b88 - returns whether an entry with that id exists
void evtSetPri(EvtEntry * entry, uint8_t pri); // 800d9bd4
void evtSetSpeed(EvtEntry * entry, float speed); // 800d9bdc
void evtSetType(EvtEntry * entry, uint8_t type); // 800d9bec
void evtStop(EvtEntry * entry, uint8_t mask); // 800d9bf4
void evtStart(EvtEntry * entry, uint8_t mask); // 800d9c98
void evtStopId(int id); // 800d9d3c
void evtStartId(int id); // 800d9dc8
void evtStopAll(uint8_t mask); // 800d9e54
void evtStartAll(uint8_t mask); // 800d9ed4
void evtStopOther(EvtEntry * entry, uint8_t mask); // 800d9f54
void evtStartOther(EvtEntry * entry, uint8_t mask); // 800d9fc8
EvtEntry * evtGetPtr(int index); // 800da03c
EvtEntry * evtGetPtrId(int id); // 800da064
