/*
    item_event_data defines what happens when certain items are used
    See itemevent.txt for a dump of this table
*/

typedef struct {
/* 0x0 */ s32 itemId;
/* 0x4 */ EvtScriptCode * useScript;
/* 0x8 */ const char * useMsgName;
} ItemEventData; // total size 0xc

ItemEventData itemEventDataTable[33]; // 803fbc10

typedef struct {
/* 0x0 */ void * wp;
/* 0x4 */ // unknown 0x4-1f
} ItemEventWork; // total size 0x20

ItemEventWork itemEventWork; // 80509c80
ItemEventWork * itemEventWp; // 805adf00

/*
    Returns the script for an item in the table by id, or a fallback if the item isn't in there
*/
EvtScriptCode * getItemUseEvt(s32 itemId); // 80025164

/*
    Returns the name of the use message for an item in the table, or nulll if the item isn't in there
*/
const char * getItemUseMsg(s32 itemId); // 800251dc

// 80025250 unknown function

/*
    Frees wp->wp and sets it to null
*/
// evt_item_event_free_work()
EVT_DECLARE_USER_FUNC(evt_item_event_free_work, 0); // 80025700

/*
    Sets wp->wp to null
*/
void itemEventDataExit(); // 8002573c

// A lot of unknown functions

/*
    Gives the map & door name that the return pipe should go to
*/
// evt_itemdata_get_return_pipe_info(char * &mapNameOut, char * &doorNameOut)
EVT_DECLARE_USER_FUNC(evt_itemdata_get_return_pipe_info, 2); // 80029434
