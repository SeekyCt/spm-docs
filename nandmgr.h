/*
    nandmgr handles the game's saved data

    The save files are wiimario00-3, each of which are of the formt of the SaveFile struct

    Note: this file has some progress in the decomp, see the link in README
*/

typedef struct {
/* 0x0000 */ uint16_t flags; // 2 is corrupt?
/* 0x0002 */ // unknown 0x2-7
/* 0x0008 */ SpmarioGlobals spmarioGlobals; // see spmario.h
/* 0x1b10 */ MarioPouchWork pouchWork; // see mario_pouch.h
/* 0x21b0 */ // unknown 0x21b0-25af
    // Checksums are calculated with checksum set to 0 and checksumNOT set to 0xffff
    // See decomp for checksum algorithm
/* 0x25b0 */ uint32_t checksum;
/* 0x25b4 */ uint32_t checksumNOT;
} SaveFile; // total size 0x25b8

#define NAND_FLAG_Exec 1
#define NAND_FLAG_Waiting 2
// 4 is had an error?
#define NAND_FLAG_NoSave 0x1000

enum {
    NANDMGR_TASK_NONE,
    NANDMGR_TASK_CHECK,
    NANDMGR_TASK_WRITE_BANNER,
    NANDMGR_TASK_WRITE_ALL_SAVES,
    NANDMGR_TASK_WRITE_SAVE,
    NANDMGR_TASK_WRITE_BANNER_LOAD_ALL_SAVES,
    NANDMGR_TASK_DELETE_SAVE
};

typedef struct {
/* 0x000 */ uint32_t flag;
/* 0x004 */ void * openingBuffer; // used by NANDSafeOpenAsync
/* 0x008 */ size_t openingBufferSize;
/* 0x00C */ // unknown 0xc-f
/* 0x010 */ SaveFile * saves; // array of 4
/* 0x014 */ SaveFile * tempSaveFile; // 0x25c0 bytes allocated, used while writing to NAND
/* 0x018 */ char homedir[64];
/* 0x058 */ NANDFileInfo fileInfo;
/* 0x0E4 */ NANDCommandBlock commandBlock;
/* 0x19C */ NANDBanner * banner;
/* 0x1A0 */ size_t bannerSize; // omits unused icon textures
/* 0x1A4 */ NANDBanner * tempBanner;
/* 0x1A8 */ uint32_t answer;
/* 0x1AC */ uint32_t task; // see enum above
/* 0x1B0 */ uint32_t stage; // used by task main functions to track progress
/* 0x1B4 */ int code;
/* 0x1B8 */ int saveId; // slot of save file to work on
} NandWork; // total size 0x1bc

NandWork nandWork; // 80534fa8
NandWork * nandWp; // 805ae1b0

/*
    Initialises banner, work and saves
    Saves are zerod with hashes corrected, not loaded from NAND
*/
void nandInit(); // 8023e60c

/*
    Continues the current asynchronous task
*/
void nandMain(); // 8023e97c

/*
    Checks whether an asynchronous task is still running
*/
bool nandIsExec(); // 8023e9c0

/*
    Gets the latest NAND library function return
*/
int nandGetCode(); // 8023e9e0

/*
    Returns a pointer to the array of all 4 save files
*/
SaveFile * nandGetSaveFiles(); // 8023e9ec

/*
    Starts NANDCheck being called to see that the game's files can all be created asynchronously
*/
void nandCheck(); // 8023e9f8

/*
    Starts banner.bin being written to NAND asynchronously 
*/
void nandWriteBanner(); // 8023ea70

/*
    Starts all save files being written to NAND asynchronously 
*/
void nandWriteAllSaves(); // 8023eaec

/*
    Starts a save file being written to NAND asynchronously 
*/
void nandWriteSave(int saveId); // 8023eb68

/*
    Starts writing banner.bin to and reading all save files from NAND asynchronously 
*/
void nandWriteBannerLoadAllSaves(); // 8023ebf0

/*
    Starts a save file being deleted from NAND asynchronously
    Bugged to always delete the first save file
*/
void nandDeleteSave(int saveId); // 8023ec6c

/*
    Copies the contents of one save file to another
    Changes copies in memory only, NAND is not written
*/
void nandCopySave(int sourceId, int destId); // 8023ece8

/*
    Clears the contents of a save file
    Changes the copy in memory only, NAND is not written
*/
void nandClearSave(int saveId); // 8023ed08

/*
    Updates the contents of a save file
    Changes the copy in memory only, NAND is not written
*/
void nandUpdateSave(int saveId); // 8023edcc

/*
    Loads the contents of a save file into the game's systems
    For example, SpmarioGlobals are copied to gp.
    Uses the copy in memory, NAND is not read
*/
void nandLoadSave(int saveId); // 8023efe0

/*
    Disables saving to NAND, all saves are cleared on game over.
*/
void nandDisableSaving(); // 8023f0a0

/*
    Re-enables saving to NAND
*/
void nandEnableSaving(); // 8023f0b4

/*
    Returns whether saving to NAND is disabled
*/
bool nandCheckSaving(); // 8023f0c8

/*
    Carries out the asynchronous process for nandCheck
*/
void nandCheckMain(); // 8023f0d8

/*
    Carries out the asynchronous process for nandWriteBanner
*/
void nandWriteBannerMain(); // 8023f200

/*
    Carries out the asynchronous process for nandWriteAllSaves
*/
void nandWriteAllSavesMain(); // 8023f570

/*
    Carries out the asynchronous process for nandWriteSave
*/
void nandWriteSaveMain(); // 8023fa24

/*
    Carries out the asynchronous process for nandWriteBannerLoadAllSaves
*/
void nandWriteBannerLoadAllSavesMain(); // 8023fd64

/*
    Carries out the asynchronous process for nandDeleteSave
*/
void nandDeleteSaveMain(); // 80240414

/*
    Callback for NAND library functions
*/
void genericCallback(int result, NANDCommandBlock * commandBlock); // 80240620

/*
    Unique callback for NANDCheck
*/
void checkCallback(int result, NANDCommandBlock * commandBlock); // 80240648
