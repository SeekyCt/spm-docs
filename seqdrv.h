/*
    Seqdrv functions control the main loops of the game. One sequence is active at
    a time: its init function runs first, then its main function is ran every
    frame, and its exit function runs when changing to another sequence.

    Note: this file has some progress in the decomp, see the link in README
*/

typedef void (SeqFunc)(SeqWork *);

typedef struct {
/* 0x00 */ int seq;
/* 0x04 */ int stage; // number used by the seq_ functions to track their progress
/* 0x08 */ char * p0; // parameter for seq function, always map name?
/* 0x0C */ char * p1; // paramater for seq function, always door name?
/* 0x10 */ // unknown 0x10-1f
/* 0x20 */ SeqFunc * afterFunc; // ran after every call to the main SeqFunc if not null
} SeqWork; // total size 0x24
SeqWork seqWork; // 80512360

typedef struct {
/* 0x0 */ SeqFunc * init;
/* 0x4 */ SeqFunc * main;
/* 0x8 */ SeqFunc * exit;
} SeqDef; // total size 0xc
SeqDef seq_data[6]; // 804287a8 - index is enum above, SEQ_NONE doesn't have an entry

enum {
    SEQ_NONE = -1, // (boot)
    SEQ_LOGO = 0,
    SEQ_TITLE = 1,
    SEQ_GAME = 2,
    SEQ_MAPCHANGE = 3,
    SEQ_GAMEOVER = 4,
    SEQ_LOAD = 5
};

int now_seq; // 805ae0b8
int next_seq; // 805ae0bc
int prev_seq; // 805ae0c0

/*
    Initialises data used by seqdrv functions
*/
void seqInit_SPMARIO(); // 8017bf2c

/*
    Sets the current sequence and its prameters
*/
void seqSetSeq(int seqNum, const char * p0, const char * p1); // 8017c074

/*
    Calls all init, main & exit functions based on now_seq & next_seq
*/
void seqMain(); // 8017bf6c

/*
    Returns now_seq or 0 if equal to -1
*/
int seqGetSeq(); // 8017c084

// TODO: move to own headers
void seq_titleInit(SeqInfo * info); // 8017b130
void seq_titleMain(SeqInfo * info); // 8017b250
void seq_titleExit(SeqInfo * info); // 8017b410
void seq_gameInit(SeqInfo * info); // 8017ce44
void seq_gameMain(SeqInfo * info); // 8017cf08
void seq_gameExit(SeqInfo * info); // 8017d004
void seq_gameOverInit(SeqInfo * info); // 801789f4
void seq_gameOverMain(SeqInfo * info); // 80178b68
void seq_gameOverExit(SeqInfo * info); // 80178af4
void seq_loadInit(SeqInfo * info); // 8017c10c
void seq_loadMain(SeqInfo * info); // 8017c13c
void seq_loadExit(SeqInfo * info); // 8017c138
