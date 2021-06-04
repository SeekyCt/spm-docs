/*
    swdrv handles saved work evt variables

    Note: this file has some progress in the decomp, see the link in README
*/

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
