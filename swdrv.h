/*
    swdrv handles saved work evt variables

    Note: this file has some progress in the decomp, see the link in README
*/

/*
    Turn on / get / turn off GSWF n
*/
int swSet(int n); // 80037fac 
int swGet(int n); // 80037fec
int swClear(int n); // 80038034

/*
    Set / get GSW n (int8_t for all GSW except 0, which is a full int)
*/
int swByteSet(int n, int val); // 80038074
int swByteGet(int n); // 800380f8

/*
    Turn on / get / turn off LSWF n
*/
int _swSet(int n); // 8003811c
int _swGet(int n); // 8003815c
int _swClear(int n); // 800381a4

/*
    Set / get LSW n (all int8_t unlike GSW)
*/
int _swByteSet(int n); // 800381e4
int _swByteGet(int n); // 800381f4
