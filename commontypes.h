/*
    Maths
*/
typedef struct {
/* 0x0 */ float x;
/* 0x4 */ float y;
/* 0x8 */ float z;
} Vec3; // total size 0xc

typedef float Mtx34[3][4]; // total size 0x30
typedef float Mtx44[4][4]; // total size 0x40

/*
    Display
*/
typedef struct {
/* 0x0 */ uint8_t r;
/* 0x1 */ uint8_t g;
/* 0x2 */ uint8_t b;
/* 0x3 */ uint8_t a;
} RGBA; // total size 0x4
