/*
    Integers
*/

// s64 - signed 64-bit integer
// s32 - signed 32-bit integer
// s16 - signed 16-bit integer
// s8  - signed 8-bit integer
// u64 - unsigned 64-bit integer
// u32 - unsigned 32-bit integer
// u16 - unsigned 16-bit integer
// u8  - unsigned 8-bit integer

// size_t - u32
// EvtScriptCode - s32

/*
    Maths
*/

typedef struct {
/* 0x0 */ float x;
/* 0x4 */ float y;
} Vec2; // total size 0x8

typedef struct {
/* 0x0 */ s32 x;
/* 0x4 */ s32 y;
} Vec2i; // total size 0x8

typedef struct {
/* 0x0 */ float x;
/* 0x4 */ float y;
/* 0x8 */ float z;
} Vec3; // total size 0xc

typedef struct {
/* 0x0 */ s32 x;
/* 0x4 */ s32 y;
/* 0x8 */ s32 z;
} Vec3i; // total size 0xc

typedef float Mtx34[3][4]; // total size 0x30
typedef float Mtx44[4][4]; // total size 0x40

/*
    Display
*/

typedef struct {
/* 0x0 */ u8 r;
/* 0x1 */ u8 g;
/* 0x2 */ u8 b;
/* 0x3 */ u8 a;
} RGBA; // total size 0x4
