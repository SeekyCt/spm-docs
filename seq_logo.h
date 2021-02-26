/*
    seq_logo is the sequence (see seqdrv.h) that displays the first 2
    screens of the game before the into cutscene
*/

typedef struct {
/* 0x00 */ // unknown 0x0-f
/* 0x10 */ TPL * healthAndSafetyTPL;
/* 0x14 */ TPL * holdSidewaysTPL;
/* 0x18 */ EvtEntry * nandCheckEvtEntry; // script at 804e5280
/* 0x1C */ int nandCheckEvtEntryId;
} SeqLogoWork; // total size 0x20

SeqLogoWork seqLogoWork; // 80512220
SeqLogoWork * seqLogoWp; // 805ae0a0

void seq_logoInit(SeqInfo * info); // 80178fd0
void seq_logoMain(SeqInfo * info); // 80179140
void seq_logoExit(SeqInfo * info); // 801790f8
// 801796fc unknown function
