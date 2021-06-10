/*
    swdrv handles saved work evt variables and something else unknown

    Note: this file has some progress in the decomp, see the link in README
*/

/*
    Initialises all evt variables as 0 and clears some unknown data
*/
void swInit(); // 80037eac

/*
    Re-initialises all LSW & LSWF as 0 and clears some unknown data
*/
void swReInit(); // 80037f48

/*
    Turn on / get / turn off GSWF n
*/
s32 swSet(s32 n); // 80037fac 
s32 swGet(s32 n); // 80037fec
s32 swClear(s32 n); // 80038034

/*
    Set / get GSW n (s8 for all GSW except 0, which is a full s32)
*/
s32 swByteSet(s32 n, s32 val); // 80038074
s32 swByteGet(s32 n); // 800380f8

/*
    Turn on / get / turn off LSWF n
*/
s32 _swSet(s32 n); // 8003811c
s32 _swGet(s32 n); // 8003815c
s32 _swClear(s32 n); // 800381a4

/*
    Set / get LSW n (all s8 unlike GSW)
*/
s32 _swByteSet(s32 n); // 800381e4
s32 _swByteGet(s32 n); // 800381f4

// 80038204, 800383a0, 80038478, 80038550, 8003863c, 8003864c, 8003865c, 8003875c, 800387d8 unknown functions
