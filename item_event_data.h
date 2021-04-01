/*
    item_event_data defines what happens when certain items are used
    See itemevent.txt for a dump of this table
*/

typedef struct {
/* 0x0 */ int itemId;
/* 0x4 */ EvtScriptCode * useScript;
/* 0x8 */ const char * useMsgName;
} ItemEventData; // total size 0xc

ItemEventData itemEventDataTable[33]; // 803fbc10
