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
int prevSeq; // 805ae0c0
int curSeq; // 805ae0b8
int nextSeq; // 805ae0bc

typedef void (*SeqFunc)(SeqInfo *);

typedef struct {
  // unknown 0x0-1f
  SeqFunc * afterFunc; // ran after every call to the main SeqFunc if not null
} SeqInfo;

typedef struct {
  SeqFunc * init;
  SeqFunc * main;
  SeqFunc * exit;
} SeqFuncHolder;
SeqFuncHolder[6] seqFuncs; // 804287a8 - one for each seq other than -1

void seqInit_SPMARIO(); // 8017bf2c
void seqSetSeq(int seqNum, int param_2, int param_3); // 8017c074
void seqMain(); // 8017bf6c - calls all init, main & exit functions based on curSeq & nextSeq
int seqCheckSeq(); // 8017c084
void seq_logoInit(); // 80178fd0
void seq_logoMain(); // 80179140
void seq_logoExit(); // 801790f8
void seq_titleInit(); // 8017b130
void seq_titleMain(); // 8017b250
void seq_titleExit(); // 8017b410
void seq_gameInit(); // 8017ce44
void seq_gameMain(); // 8017cf08
void seq_gameExit(); // 8017d004
void seq_mapChangeInit(); // 8017a33c
void seq_mapChangeMain(); // 8017a464
void seq_mapChangeExit(); // 8017a460
void seq_gameOverInit(); // 801789f4
void seq_gameOverMain(); // 80178b68
void seq_gameOverExit(); // 80178af4
void seq_loadInit(); // 8017c10c
void seq_loadMain(); // 8017c13c
void seq_loadExit(); // 8017c138
