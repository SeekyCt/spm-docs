/*
    Dvdmgr provides lower level file reading than Filemgr
*/

typedef (DVDMgrCallback)(int result, DVDFileInfo * fileInfo);

typedef struct {
/* 0x00 */ char path[64];
/* 0x40 */ DVDFileInfo fileInfo; // unknown size
/* ???? */ // unknown up to 0x8b
/* 0x8C */ DVDMgrCallback * readCallback;
/* 0x90 */ // unknown 0x90-97
/* 0x98 */ int entrynum;
} DVDEntry; // total size 0x9c

typedef struct {
/* 0x0 */ DVDEntry * entries; // array of entryLimit
/* 0x4 */ int entryLimit; // 0x200
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
DVDEntry * DVDMgrOpen(const char * path, int param_2, int param_3); // 8019e08c

/*
    Read from a file synchronously
*/
int DVDMgrRead(DVDEntry * entry, void * dest, size_t length, uint32_t offset); // 8019e1e4

/*
    Calls an entry's callback
*/
void _cb(int result, DVDFileInfo * fileInfo); // 8019e29c

/*
    Read from a file asynchronously
*/
int DVDMgrReadAsync(DVDEntry * entry, void * dest, size_t length, uint32_t offset, DVDMgrCallback * callback); // 8019e2ac

/*
    Close a an entry
*/
void DVDMgrClose(DVDEntry * entry); // 8019e2e0

/*
    Get the length of the file
*/
size_t DVDMgrGetLength(DVDEntry * entry); // 8019e320
