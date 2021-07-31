/*
    msgdrv handles the reading of message text files and some of the on-screen display of dialogue
*/

typedef struct {
/* 0x0 */ u32 size;
/* 0x4 */ char * contents;
/* 0x8 */ s32 messageCount;
/* 0xC */ // unknown 0xc-f
} MsgFile; // total size 0x10

typedef struct {
/* 0x00 */ MsgFile files[9]; // 0 is global.txt
/* 0x90 */ s32 hoshi_2AnimPoseId;
/* 0x94 */ bool discReadFinished;
/* 0x95 */ bool parseFinished;
/* 0x96 */ // unknown 0x96-97
} MsgWork; // total size 0x98

MsgWork * msgw; // 805adf18
MsgWork msgWork; // 80509cb8

typedef struct {
/* 0x0 */ const char * name;
/* 0x4 */ s32 iconid;
} IconNameIdDef; // total size 0x8

IconNameIdDef msgIcon[24]; // 80405bd8

/*
    Closes file and sets discReadFinished
*/
void dvdCb(s32 result, DVDFileInfo * fileInfo); // 8002eda0

/*
    Initialises data and starts the async load of global.txt
*/
void msgInit(); // 8002edd0

/*
    Parses un-parsed message files and loads hoshi_2 model
*/
void msgdrvMain(); // 8002ef48

/*
    Loads the specified text file into the specified file slot
    Language folder path is generated automatically, not included in textFileName
    .txt is appended automatically, not included in textFileName
*/
void msgLoad(const char * textFileName, s32 slot); // 8002f130

/*
    Unloads the text file in the specified slot
*/
void msgUnLoad(s32 slot); // 8002f35c

/*
    Calls fileAsyncf on the specified message file to start it being loaded from disc
    Language folder path is generated automatically, not included in textFileName
    .txt is appended automatically, not included in textFileName
*/
void msgPreLoad(const char * filename);

// 8002f3f4, 8002f51c, 8002fccc, 80030998 unknown functions

void msgDispKeyWait_render(UNK param_1); // 80030bb4
void msgAnalize(SmartAllocation * param_1, void * param_2); // 80030c34
s32 msg_compare(void * param_1, void * param_2); // 800326c4

/*
    Returns the contents of a message by name
    Returns "anna_no_message" when no message with that name is loaded
*/
char * msgSearch(const char * msgName); // 8003270c

/*
    Returns the contents of a message by name
    Returns a null pointer when no message with that name is loaded
*/
char * msgSearchNoFallback(const char * msgName); // 800327e4

bool _ismbblead(char param_1); // 800328b0

/*
    Splits a message command into tag and value
    For example, command "<col ffffff80>" writes "col" to tag and "ffffff80" to value
*/
char * msgGetCommand(const char * command, char * tag, char * value); // 800328fc

/*
    Takes an icon name (like "STICK") and returns the icon id for it
*/
s32 msgIconStr2ID(const char * iconStr); // 8003299c

// 80032a20, 80032b30 unknown functions

s32 msgWindow_entry(UNK param_1, UNK param_2, UNK param_3); // 80032c40

// 80032f40 unknown function

void msgWindow_Add(void * param_1, s32 windowId); // 80032f84
void msgWindow_Continue(s32 windowId); // 80032ff8
void msgWindow_Repeat(s32 windowId); // 80033088
void msgWindow_ForceClose(const char * param_1); // 800330fc

// 800331ac, 80033234, 80033a40, 80033d40, 80034528, 8003490c unknown functions
