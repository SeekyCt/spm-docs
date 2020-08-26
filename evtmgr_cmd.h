float evtGetFloat(EvtEntry * entry, uint32_t datapiece); // 800dedb8
int evtGetValue(EvtEntry * entry, uint32_t datapiece); // 800de594
void evtSetFloat(EvtEntry * entry, uint32_t datapiece, float value); // 800df1fc
void evtSetValue(EvtEntry * entry, uint32 datapiece, float value); // 800de9b8

int evtmgrCmd(EvtEntry * entry); // 800ddd5c - execute the script of an entry

int evt_end_evt(EvtEntry * entry); // 800da0b0
int evt_lbl(EvtEntry * entry); // 800da0d4
// function for every other instruction in the same format...
int evt_debug_bp(EvtEntry * entry); // 800ddd08
