/*
    relmgr controls the loading and execution of the game's rel file

    Rel files are all in the /rel/ folder at the root of the disk
    relF.bin is the actual rel, rel.bin and relD.bin are unused
    .bin rels are lzss10 compressed, the game also supports loading an
    uncompressed file named relF.rel if relF.bin is not found
*/

typedef struct {
/* 0x0 */ void * relFile;
/* 0x4 */ void * bss;
/* 0x8 */ bool loaded;
} RelWork; // total size 0xc

RelWork relWork; // 80534f98
RelWork * relWp; // 805ae1a0
const char * relDecompName; // 805ae1a4, "relF.rel"
const char * relCompName; // 805ae1a4, "relF.bin"

/*
    Sets the rel loaded bool to false
*/
void relInit(); // 8023e434

/*
    Attempts to continue the process of loading the rel, if it hasn't already finished
*/
void relMain(); // 8023e444

/*
    Returns whether the rel has finished loading and had its prolog run
*/
bool isRelLoaded(); // 8023e600
