/*
    Wpadmgr handles controller inputs & vibration 

    The game reads up to 16 KPADStatuses for each controller but only ever seems to use the latest
*/

typedef struct {
/* 0x0000 */ u32 flags;
/* 0x0004 */ // unknown 0x4-43
/* 0x0044 */ bool enableRumble[4]; // index controller id, controller vibrates when true
/* 0x0048 */ bool rumblePrev[4]; // the value of enableRumble on the previous frame
/* 0x004C */ Vec2 pointingPos[4]; // coordinates of the cursor for each controller
/* 0x006C */ KPADStatus statuses[4][16]; // controller input states, major index controller id, minor index age (latest is 0)
/* 0x216C */ kpadReadRet[4]; // last return from KPADRead for each controller
/* 0x217C */ // unknown 0x217c - 0x9dc7
} WpadWork;

/*
    Returns the pointer to the WpadWork instance
*/
WpadWork * wpadGetWork(); // 8023697c

/*
    Initialises data used by wpad functions and the KPAD library
*/
void wpadInit(); // 80236998

/*
    Stops vibration of all controllers
*/
void wpadAllRumbleOff(); // 80236ab8

/*
    Updates all controllers
*/
void wpadMain(); // 80236af8

/*
    Enables/disables pointers updating on all controllers
*/
void wpadCursorOn(); // 80237618
void wpadCursorOff(); // 8023762c

/*
    Returns whether cursors are enabled
*/
bool wpadGetCursorStatus(); // 80237640

/*
    Makes a controller start/stop vibrating
*/
void wpadRumbleOn(s32 controller); // 80237650
void wpadRumbleOff(s32 controller); // 80237664

/*
    Returns whether a controller is vibrating
    (ignores SpmarioGlobals override)
*/
bool wpadGetRumbleStatus(s32 controller); // 80237678

/*
    Returns a bitmask of all buttons that are down on a controller 
*/
u32 wpadGetButtonsHeld(s32 controller); // 80237688

/*
    Returns a bitmask of all buttons that have just been released/pressed on a controller
*/
u32 wpadGetButtonsReleased(s32 controller); // 8023769c
u32 wpadGetButtonsPressed(s32 controller); // 802376b0

/*
    Returns a bitmask of buttons held long enough to trigger the 'repeat' flag
*/
u32 wpadGetButtonsHeldRepeat(s32 controller); // 802376c4

// 802376e4, 80237710, 80237750 unknown functions
