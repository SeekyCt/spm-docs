# Setup Files
The .dat files in "./setup/" in the disc spawn items and enemies in their corresponding maps.

See also [npcdrv.h]() and [setup_data.h]().

## File structure

| Section     | Description                                           |
|-------------|-------------------------------------------------------|
| Header      | 2-byte version number and 2 bytes padding             |
| Enemies     | 100 enemy entries, size varies with version           |
| Item Header | Item count and version                                |
| Items       | Array of items of length specified in the Item Header |

Note that item data isn't present in all files and is only supported by v5 and v6

## Enemies

### evt_read_setup_file

The enemy spawning side of setup files starts with evt_read_setup_file (0x80106390) being
called by a maps init evt script. The function does a few [hardcoded spawns based on mapnames
for maps that don't exist](), then calls npcReadSetupFile and [waits until all of the onSpawn scripts
of the NPCs that spawned are complete](). 

### npcReadSetupFile

[npcReadSetupFile]() then handles loading the current map's file from the disc, [updating it to v6]()
and passing every enemy entry in it to npcEntryFromSetupEnemy.

### npcEntryFromSetupEnemy

Next, [npcEntryFromSetupEnemy]() creates a copy of the specified setupEnemyTemplate on the stack, fills
in the values that come from the SetupEnemy, assigns an automatic name (npc_XXXXXXXX where XXXXXXXX is
the instance id in hex) and calls npcEntryFromTemplate.

### npcEntryFromTemplate

[npcEntryFromTemplate]() then checks the enemy can spawn with the template's canSpawn function, and
called [npcEntry]() with its data if it can. Various fields of the NPCEntry are then filled in from
the template and the [tribe]() that template specifies.

## Items

During stage 10 of seq_MapChangeMain, the setup file is loaded and passed into [setupReadItemInfo]().
If the item count returned is more than 0, the version is asserted to be 20051201 (SETUPOBJ_FORMAT_VERSION)
and the item list is passed into setpupSpawnItems.

## setupSpawnItems

[setupSpawnItems]() then iterates through the list of items, passing each one into [itemEntry]() provided
the flags 0x1 and 0x10 are set and the item id is 0 (a coin).
