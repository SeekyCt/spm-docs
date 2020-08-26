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
  // unknown 0x0-7
  uint8_t flags; // bit flags, 1 seems to be the script being active?
  uint8_t curDataLength; // number of pieces of data (4 bytes each) belonging to the current instruction
  uint8_t curOpcode; // see links above for opcodes
  uint8_t priority;
  uint8_t type;
  // unknown 0xd
  uint8_t dowhileDepth; // number of do-while loops the current instruction is nexted into
  // unknown 0xf
  void * curInstructionPtr;
  void * curDataPtr;
  uint8_t labelIds[16]; // each correspond to an address in the jump table
  void * jumptable[16]; // addresses for each label
  // unknown 0x68-6b
  EvtEntry * childEntry;
  EvtEntry * brotherEntry;
  // unknown 0x74-93
  user_func * userFunc; // Function set & called by the user_func opcode
  // unknown 0x98-e3
  void * dowhileStartPtrs[8]; // pointer to do opcodes
  // unknown 0x104-157
  int id;
  float speed;
  // unknown 0x160-19f
  void * prevInstructionPtr;
  // unknown 0x1a4-7
} EvtEntry;

int evtEntryLimit; // 8050c990
int evtEntryCount; // 805ae8d8
EvtEntry * evtEntries; // 8050ca20

void * evtGetWork(); // 800d87e4
void make_pri_table(); // 800d87f0
void generateJumptable(EvtEntry * entry); // 800d890c
void evtmgrInit(); // 800d8a88
void evtmgrReInit(); // 800d8b2c
EvtEntry * evtEntry(void * script, uint8_t param_2, char flags); // 800d8b88 - inits an entry for a script
EvtEntry * evtEntryType(void * script, int param_2, int param_3, int param_4) // 800d8df4
EvtEntry * evtChildEntry(EvtEntry * entry, void * script, uint8_t flags); // 800d9060
EvtEntry * evtBrotherEntry(EvtEntry * entry, void * script, uint8_t flags); // 800d9370
EvtEntry * evtRestart(EvtEntry * entry); // 800d9634
void evtmgrMain(); // 800d9764
void evtDelete(EvtEntry * entry); // 800d9944
void evtDeleteId(int id): // 800d9b00
bool evtCheckID(int id); // 800d9b88 - returns whether an entry with that id exists
EvtEntry * evtSetPri(EvtEntry * entry, uint8_t pri); // 800d9bd4
void evtSetSpeed(EvtEntry * entry, float speed); // 800d9bdc
void evtSetType(EvtEntry * entry, uint8_t type); // 800d9bec
void evtStop(EvtEntry * entry, int param_2); // 800d9bf4
void evtStart(EvtEntry * entry, int param_2); // 800d9c98
void evtStopId(int id); // 800d9d3c
void evtStartId(int id); // 800d9dc8
void evtStopAll(int param_1); // 800d9e54
void evtStartAll(int param_1); // 800d9ed4
void evtStopOther(EvtEntry * entry, int param_2); // 800d9f54
void evtStartOther(EvtEntry * entry, int param_2); // 800d9fc8
EvtEntry * evtGetPtr(int index); // 800da03c
EvtEntry * evtGetPtrId(int id); // 800da064
