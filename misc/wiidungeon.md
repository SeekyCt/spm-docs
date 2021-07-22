# wiidungeon.xml (Pit of 100 Trials Definitions)

The pit of 100 trial definitions are stored in an XML-like (the only difference from true XML being that closing tags don't name which tag they're closing, they just close the last one opened) lz-compressed text file in the dol (internally referred to as wiidungeon.xml in relD).

For more low-level detail of how this works, see my decompilation of [dan.c](https://github.com/SeekyCt/spm-decomp/blob/master/rel/dan.c).

## \<dungeon\>
Inside each `<dungeon>` tag is the definition of 1 floor of the pit.

### \<no\>
The `<no>` tag shows which floor this `<dungeon>` is referring to. (0-99 being the Flipside pit, 100-199 being the Flopside pit)

### \<item\>
The `<item>` tag sets which item should be in the reward chest for chest rooms, and is left as `ITEM_ID_NULL` elsewhere.

### \<map\>
The `<map>` tag is a set of bit flags (awkwardly left in decimal format, practice codes adds support for these to be in hex with the 0x prefix but that's not in the vanilla game) which determines the parts of the map (floors, walls & pipes) to enable in enemy rooms, and is left as 0 elsewhere. See the [map flags & door ids diagram](#map-flags--door-ids) for more.

### \<door\>
The `<door>` tag gives one pair of possible doors for the entrance and exit in this map. If more than one is present, one will be selected at random (all with equal chance).

#### \<enter\>
The `<enter>` tag gives the door id to use for the entrance if this `<door>` tag is picked. See the [map flags & door ids diagram](#map-flags--door-ids) for more.

#### \<exit\>
The `<exit>` tag gives the door id to use for the exit if this `<door>` tag is picked. See the [map flags & door ids diagram](#map-flags--door-ids) for more.

### \<enemy\>
The `<enemy>` tag spawns a group of enemies in the room.

#### \<name\>
The `<name>` tag determines the type of enemy to spawn. See [wiidungeon_names.md](https://github.com/SeekyCt/spm-docs/blob/master/misc/wiidungeon_names.md) for more.

#### \<num\>
The `<num>` tag determines how many of the enemy should be spawned.

#### \<pos\>
The `<pos>` tag sets the door id that the enemies should be spawned at. Setting this to 0 will place every enemy in the group at a random place, any other value will spawn the entire group at the specified door.

## Map Flags & Door Ids

![alt text](https://media.discordapp.net/attachments/610974864706371585/867754786870919218/pitparts3.png)
