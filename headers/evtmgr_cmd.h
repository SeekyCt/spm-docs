/*
    Functions for handling evt script execution and variables

    Note: this file has some progress in the decomp, see the link in README
*/

/*
    Getters & setters for script variables
    Datapiece is the form it's in in a compiled script
*/
float evtGetFloat(EvtEntry * entry, int datapiece); // 800dedb8
int evtGetValue(EvtEntry * entry, int datapiece); // 800de594
void evtSetFloat(EvtEntry * entry, int datapiece, float value); // 800df1fc
void evtSetValue(EvtEntry * entry, int datapiece, int value); // 800de9b8

/*
    Executes an entry's script until it pauses or finishes
*/
int evtmgrCmd(EvtEntry * entry); // 800ddd5c

/*
    Individual instruction functions
*/
int evt_end_evt(EvtEntry * entry); // 800da0b0
int evt_lbl(EvtEntry * entry); // 800da0d4
// function for every other instruction in the same format...
int evt_debug_bp(EvtEntry * entry); // 800ddd08

/*
    Returns a pointer to the instruction after the next else on the
    current if else depth in an entry's script
*/
EvtScriptCode * evtSearchElse(EvtEntry * entry); // 800df55c

/*
    Returns a pointer to the instruction after the next end if on the
    current if else depth in an entry's script
*/
EvtScriptCode * evtSearchEndIf(EvtEntry * entry); // 800df620


/*
    Returns a pointer to the the next end switch on the current switch
    depth in an entry's script
*/
EvtScriptCode * evtSearchEndSwitch(EvtEntry * entry); // 800df6d8

/*
    Returns a pointer to the next case or end switch on the current
    switch depth in an entry's script
*/
EvtScriptCode * evtSearchCase(EvtEntry * entry); // 800df780

/*
    Returns a pointer to the instruction after the next while on the
    current do while depth in an entry's script
*/
EvtScriptCode * evtSearchWhile(EvtEntry * entry); // 800df84c

/*
    Returns a pointer to the next while instruction on the current do
    while depth in an entry's script
*/
EvtScriptCode * evtSearchJustBeforeWhile(EvtEntry * entry); // 800df8f8
