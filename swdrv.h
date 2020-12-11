int swSet(int n); // 80037fac, turns on GSWF n
int swGet(int n); // 80037fec, returns GSWF n
int swClear(int n); // 80038034, turns off GSWF n
int swByteSet(int n, int val); // 80038074, sets GSW n to val
int swByteGet(int n; // 800380f8, returns GSW n

int _swSet(int n); // 8003811c, turns on LSWF n
int _swGet(int n); // 8003815c, returns LSWF n
int _swClear(int n); // 800381a4, turns off LSWF n
int _swByteSet(int n); // 800381e4, sets LSW n to val
int _swByteGet(int n); // 800381f4, returns LSW n
