/*
  Functions used to spawn map objects with the user_func instruction in evt scripts, and the functions the objects use internally
*/

/*
  evt_mobj_blk - spawns various blocks (question, brick & variants)

  1st param: int type
    0 = brick block
    1 = question block
    the rest unknown
  2nd param: char * instanceName
  3rd param: float x
  4th param: float y
  5th param: float z
  6th param: can be 2 things
    int itemId
    or
    ChanceEntry * chanceTable
      Format is an array of the following struct, terminated by one with an id of 0
        struct ChanceEntry {
          int itemId;
          int chance;
        }
  7th param: unknown
  8th param: unknown
*/
int evt_mobj_blk(EvtEntry * entry); // 800f8be8
int mobj_blk_decideItem(MOBJEntry * entry); // 800f6754 - returns the item id, or a random id from the table if that's what the object uses

/*
  evt_mobj_kan - spawns a sign
  1st param: int rotation
    0 for facing 2d camera
    1 for perpendicular to 2d camera
  2nd param: char * instanceName
  3rd param: float x
  4th param: float y
  5th param: float z
  6th param: EvtScript * interactScript
  7th param: unknown
*/
int evt_mobj_kan(EvtEntry * entry); // 800f6440

/*
  evt_mobj_save_blk - spawns a save block
  1st param: char * instanceName
  2nd param: float x
  3rd param: float y
  4th param: float z
  5th param: EvtScript * interactScript
*/

int evt_mobj_save_blk(EvtEntry * entry); // 800fb118
