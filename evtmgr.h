/*
The script format is also used in TTYD, see ttydasm at https://github.com/PistonMiner/ttyd-tools
(Note: there's an SPM specific opcode missing in ttyd-opc-summary.txt, but the enum in ttydasm.cpp is accurate)
As a brief summary, each instruction has the following format:
  halfword dataPieceCount
  halfword opcode
  word data[dataPieceCount]
*/

typedef struct {
  // unknown 0x0-7
  uint8_t flags; // bit flags, 1 seems to be the script being active?
  uint8_t curDataLength; // number of pieces of data (4 bytes each) belonging to the current instruction
  uint8_t curOpcode; // see links above for opcodes
  // unknown 0xb-d
  uint8_t dowhileDepth; // number of do-while loops the current instruction is nexted into
  // unknown 0xf
  void * curInstructionPtr;
  void * curDataPtr;
  uint8_t labelIds[16]; // each correspond to an address in the jump table
  void * jumptable[16]; // addresses for each label
  // unknown 0x68-93
  void * userFunc; // Function set & called by the user_func opcode
  // unknown 0x98-e3
  void * dowhileStartPtrs[8]; // pointer to do opcodes
  // unknown 0x104-19f
  void * prevInstructionPtr
  // unknown 0x1a4-7
} EvtEntry;

static int evtEntryLimit; // 8050c990
static EvtEntry * evtEntries; // 8050ca20

void evtInit(); // 800d8a88
int addScript(void * script, uint8_t param_2, uint8_t param_3); // 800d8b88
int executeScript(EvtEntry * entry); // 800ddd5c
