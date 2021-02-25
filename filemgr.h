/*
    Filemgr gives high level access to files on the disc, loaded onto the smart heap

    Note: this file has some progress in the decomp, see the link in README
*/

enum {
    FILETYPE_0, // home button bins, rel (comp & decomp), setup dats, win/card.dat, lyt/title.bin, camera_road.bin
    FILETYPE_1,
    FILETYPE_2,
    FILETYPE_3,
    FILETYPE_TPL, // not used for bg tpls?
    FILETYPE_5, // a/%s (no dash)
    FILETYPE_6,
    FILETYPE_7,
    FILETYPE_8,
    FILETYPE_9,
    FILETYPE_10,
    FILETYPE_11 // eff/%s/%s.dat, eff/%seffdata.dat
};

typedef struct {
/* 0x00 */ uint8_t state;
/* 0x01 */ int8_t fileType;
/* 0x02 */ int16_t touchCnt;
/* 0x04 */ // unknown 0x4-1f
/* 0x20 */ char path[64]; // size is uncertain
/* 0x60 */ // unknown 0x60-a0
/* 0xA0 */ size_t length;
/* 0xA4 */ SmartAllocation sp; // smart pointer to data, see memory.h
/* 0xA8 */ FileEntry * next;
/* 0xAC */ void * readDoneCb;
/* 0xB0 */ DVDEntry * dvdEntry; // see dvdmgr.h
} FileEntry; // total size 0xb4

typedef struct {
/* 0x00 */ FileEntry * entries; // array of 1024
/* 0x04 */ FileEntry * allocatedStart; // start of allocated linked list
/* 0x08 */ FileEntry * allocatedEnd; // end of allocated linked list
/* 0x0C */ FileEntry * freeStart; // end of allocated linked list
/* 0x10 */ FileEntry * freeEnd; // end of free linked list
} FileWork; // total size 0x1c

FileWork fileWork; // 80516f88
FileWork * fileAfp; // 8019e478

/*
    Convert all offsets in a TPL file to pointers & reverse
*/
void UnpackTexPalette(void * tpl); // 8019e5a4
void PackTexPalette(void * tpl); // 8019e6c0

/*
    Converts self-pointers in file data to offsets to allow safe moving
*/
void fileGarbageDataAdrClear(FileEntry * entry); // 8019e7e0

/*
    Converts offsets in file data back to self-pointers
*/
void fileGarbageDataAdrSet(void * data, int fileType); // 8019ee2c

/*
    Safely moves memory containing file data, preserving any self-pointers
*/
void fileGarbageMoveMem(void * dest, FileEntry * sourceEntry); // 8019f498

void _fileGarbage(int param_1); // 8019f560

/*
    Reads a file into memory
    Calling on its own will be a synchronous load
    Calling after Asyncf is finished allows accessing data loaded asynchronously
    Returns -1 if there's an error
*/
FileEntry * fileAllocf(int fileType, const char * pathFormat, ...); // 8019f724
FileEntry * fileAlloc(const char * path, int fileType); // 8019f7dc
FileEntry * _fileAlloc(const char * path, int fileType, int param_3); // 8019f7e4

/*
    Unloads a file
*/
void fileFree(FileEntry * entry); // 8019fa8c

void dvdReadDoneCallback(int result, DVDFileInfo * fileInfo); // 8019fb38

/*
    Loads a file asynchronously
    Returns a null pointer if the file isn't loaded yet
*/
FileEntry * fileAsyncf(int fileType, int p2, const char * format, ...); // 8019fc5c
FileEntry * fileAsync(const char * path, int fileType, int param_3); // 8019fd24
