/*
    Dvdmgr provides lower level file reading than Filemgr
*/

typedef (DVDMgrCallback)(s32 result, DVDFileInfo * fileInfo);

typedef struct {
/* 0x00 */ char path[64];
/* 0x40 */ DVDFileInfo fileInfo; // unknown size
/* ???? */ // unknown up to 0x8b
/* 0x8C */ DVDMgrCallback * readCallback;
/* 0x90 */ // unknown 0x90-97
/* 0x98 */ s32 entrynum;
} DVDEntry; // total size 0x9c

typedef struct {
/* 0x0 */ DVDEntry * entries; // array of entryLimit
/* 0x4 */ s32 entryLimit; // 0x200
} DVDWork; // total size 0x8

DVDWork dvdWork; // 80516f60
DVDWork * dvdWp; // 805ae120

/*
    Initialises data used by dvdmgr functions
*/
void dvdmgrInit(); // 8019e044

/*
    Stub
*/
void dvdmgrDelete(); // 8019e088

/*
    Opens a file on the disc
*/
DVDEntry * DVDMgrOpen(const char * path, s32 param_2, s32 param_3); // 8019e08c

/*
    Read from a file synchronously
*/
s32 DVDMgrRead(DVDEntry * entry, void * dest, size_t length, u32 offset); // 8019e1e4

/*
    Calls an entry's callback
*/
void _cb(s32 result, DVDFileInfo * fileInfo); // 8019e29c

/*
    Read from a file asynchronously
*/
s32 DVDMgrReadAsync(DVDEntry * entry, void * dest, size_t length, u32 offset, DVDMgrCallback * callback); // 8019e2ac

/*
    Close a an entry
*/
void DVDMgrClose(DVDEntry * entry); // 8019e2e0

/*
    Get the length of the file
*/
size_t DVDMgrGetLength(DVDEntry * entry); // 8019e320
