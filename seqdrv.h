/*
Seqdrv functions control the main loops of the game. One sequence is active at
a time: its init function runs first, then its main function is ran every
frame, and its exit function runs when changing to another sequence.
*/

/*
  -1: none (boot)
   0: logo
   1: title
   2: game
   3: mapChange
   4: gameOver
   5: load
*/
int now_seq; // 805ae0b8
int next_seq; // 805ae0bc
int prev_seq; // 805ae0c0

typedef void (*SeqFunc)(SeqInfo *);

typedef struct {
  int seq;
  int stage; // number used by the seq_ functions to track their progress
  char * p0; // parameter for seq function, always map name?
  char * p1; // paramater for seq function, always door name?
  // unknown 0x10-1f
  SeqFunc * afterFunc; // ran after every call to the main SeqFunc if not null
} SeqWork;
SeqWork seqWork; // 80512360

typedef struct {
  SeqFunc * init;
  SeqFunc * main;
  SeqFunc * exit;
} SeqFuncHolder;
SeqFuncHolder[6] seqFuncs; // 804287a8 - one for each seq other than -1

void seqInit_SPMARIO(); // 8017bf2c
void seqSetSeq(int seqNum, char * mapName, char * doorName); // 8017c074
void seqMain(); // 8017bf6c - calls all init, main & exit functions based on curSeq & nextSeq
int seqGetSeq(); // 8017c084 - returns now_seq, or 0 if equal to -1
void seq_logoInit(SeqInfo * info); // 80178fd0
void seq_logoMain(SeqInfo * info); // 80179140
void seq_logoExit(SeqInfo * info); // 801790f8
void seq_titleInit(SeqInfo * info); // 8017b130
void seq_titleMain(SeqInfo * info); // 8017b250
void seq_titleExit(SeqInfo * info); // 8017b410
void seq_gameInit(SeqInfo * info); // 8017ce44
void seq_gameMain(SeqInfo * info); // 8017cf08
void seq_gameExit(SeqInfo * info); // 8017d004
void seq_mapChangeInit(SeqInfo * info); // 8017a33c
void seq_mapChangeMain(SeqInfo * info); // 8017a464
void seq_mapChangeExit(SeqInfo * info); // 8017a460
void seq_gameOverInit(SeqInfo * info); // 801789f4
void seq_gameOverMain(SeqInfo * info); // 80178b68
void seq_gameOverExit(SeqInfo * info); // 80178af4
void seq_loadInit(SeqInfo * info); // 8017c10c
void seq_loadMain(SeqInfo * info); // 8017c13c
void seq_loadExit(SeqInfo * info); // 8017c138
