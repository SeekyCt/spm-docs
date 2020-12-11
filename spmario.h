typedef struct {
    // unknown 0x0-f7
    int64_t time;
    // unknown 0x100-13f
    int gsw0; // the first gsw is larger
    uint8_t gswf[1024]; // evt global saved work flags
    uint8_t gsw[2048]; // evt global saved work, index 0 is unused in favour of gsw0
    uint8_t lswf[64]; // evt local saved work flags
    uint8_t lsw[1024]; // evt local saved work
    // unknown 0x1184-1ab0
} SpMarioGlobals;

SpMarioGlobals * gp; // 805ae178
SpMarioGlobals spMarioGlobals; // 80525550
