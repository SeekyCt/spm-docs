/*
    msgdrv handles the reading of message text files and some of the on-screen display of dialogue
*/

typedef (MsgSpeakerFunc)(s32 state, SmartAllocation * speakerSp);

typedef struct {
/* 0x0000 */ const char * msgName;
/* 0x0004 */ u32 flags;
/* 0x0008 */ // unknown 0x8-17
/* 0x0018 */ s64 openTime; // when the window was opened
/* 0x0020 */ // unknown 0x20-2f
/* 0x0030 */ s64 messageStartTime; // last time text was added
/* 0x0038 */ s32 cellCount;
/* 0x003C */ // unknown 0x3c-f1fb
/* 0xF1FC */ MsgSpeakerFunc * mainFunc; // Called multiple times in msgMain with different states
/* 0xF200 */ // unknown 0xf200-f203
/* 0xF204 */ char npcName[32];
/* 0xF224 */ // unknown 0xf224-f227
    /*
        0 normal
        1 typewriter (used in opening cutscene)
        2 writing
        3 Francis dating
        4-15 duplicates of normal
    */
/* 0xF228 */ s32 talkSfxGroup;
/* 0xF22C */ u8 talkVolume;
/* 0xF22D */ // unknown 0xf22d-f24b
/* 0xF24C */ WindowEntry * window;
/* 0xF250 */ s32 talkPoseTime; // frames remaining to be in the talking animation
/* 0xF254 */ s32 isInTalkPose; // 1 if in talking animation, 0 otherwise
} MsgSpeaker; // total size 0xf258

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

typedef struct {
/* 0x0 */ const char * name1;
/* 0x4 */ const char * name2;
/* 0x8 */ const char * name3;
/* 0xC */ const char * name4;
} MsgTalkSfxGroup; // total size 0x10

MsgTalkSfxGroup * msgTalkSfxGroups[14]; // 80405cd8, index MsgSpeaker.talkSfxGroup
const char * msgSKipSfx[16]; // 80405d10, index MsgSpeaker.talkSfxGroup

typedef struct {
/* 0x0 */ const char * openName;
/* 0x4 */ const char * closeName;
} MsgOpenCloseSfxGroup; // total size 0x8;
MsgOpenCloseSfxGroup msgOpenCloseSfxGroups[32]; // 80405d50, index WindowEntry.type

// "msg/XX"
const char * language_dir[8]; // 80405e50, index gp->language

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
void msgPreLoad(const char * filename); // 8002f37c

/*
    Creates a smart pointer to a MsgSpeaker struct
*/
SmartAllocation * msgSpeakerInit(const char * msg, MsgSpeakerFunc * mainFunc, WindowEntry * window); // 8002f3f4

/*
    Updates a MsgSpeaker
*/
void msgMain(SmartAllocation * speakerSp); // 8002f51c

/*
    Renders the window & text for a MsgSpeaker
*/
void msgDisp(); // 8002fccc

/*
    Draws the star that appears when waiting for input
*/
void msgDispKeyWait(); // 80030998

/*
    Configures GX settings for 
*/
void msgDispKeyWait_render(UNK param_1); // 80030bb4

/*
    Adds message text to a MsgSpeaker
*/
void msgAnalize(SmartAllocation * speakerSp, const char * msg); // 80030c34

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

/*
    Sets a MsgSpeaker's npc/fairy/player/item to their talking/standing animation
*/
void msgSetTalkPose(SmartAllocation * speakerSp); // 80032a20
void msgSetStayPose(SmartAllocation * speakerSp); // 80032b30

/*
    Creates a message WindowEntry and its MsgSpeaker
*/
s32 msgWindow_Entry(const char * msg, MsgSpeakerFunc * mainFunc, u16 priority); // 80032c40

/*
    Delete callback for WindowEntry, frees MsgSpeaker
*/
s32 msgWindow_Delete(WindowEntry * entry); // 80032f40

/*
    Adds text on to the end of a window
*/
void msgWindow_Add(const char * msg, s32 windowId); // 80032f84

/*
    Moves on from the window
*/
void msgWindow_Continue(s32 windowId); // 80032ff8

/*
    Restarts text in a window
*/
void msgWindow_Repeat(s32 windowId); // 80033088

/*
    Closes a window
*/
void msgWindow_ForceClose(const char * messageName); // 800330fc

/*
    Closes all text windows
*/
void msgWindow_ForceCloseAll(); // 800331ac

/*
    Main callback for WindowEntry, updates text position, handles inputs
    and schedules rendering to run this frame
*/
void msgWindow_Main(WindowEntry * window); // 80033234

void msgWindow_Clear_Main(WindowEntry * window); // 80033a40

/*
    Renders window background, text and input waiting icon
*/
void msgWindow_Disp(s8 camId, WindoWentry * window); // 80033d40

/*
    Main callback for WindowEntry, updates text position, handles inputs
    and schedules rendering to run this frame
*/
void selectWindow_Main(WindowEntry * window); // 80034528

/*
    Renders window background, text and cursor
*/
void selectWindow_Disp(s8 camId, WindowEntry * window); // 8003490c
