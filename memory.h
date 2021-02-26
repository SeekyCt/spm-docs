/*
    Memory controls the allocation and freeing of data on heaps
    The game also has one heap known as the smart heap, where data is automatically
    moved around around to reduce wasted space.

    Heap 0: main heap, MEM1
    Heap 1-2: unknown, MEM1
    Heap 3-6: unknown, MEM2
    Heap 7: smart heap
    Heap 8: unknown

    Note: this file has some progress in the decomp, see the link in README
*/

enum {
    HEAPSIZE_PERCENT_REMAINING = 0,
    HEAP_SIZE_ABSOLUTE_KB = 1
};

typedef struct {
/* 0x0 */ int type; // see enum above
/* 0x4 */ int size;
} HeapSize; // total size 0x8

HeapSize size_table[9]; // 8042a408

typedef struct {
/* 0x00 */ void * heapHandle[9]; // pointer to the MEM library's heap struct
/* 0x24 */ void * heapStart[9]; // pointer to the start of the heap
/* 0x48 */ void * heapEnd[9]; // pointer to the end of the heap
} MemWork; // total size 0x6c

MemWork memoryWork; // 805173e0
MemWork * memWp; // 805ae168

typedef struct {
/* 0x00 */ void * data; // space on the smart heap for the user to put their data, may change during lifetime
/* 0x04 */ size_t size; // size of the space for data on the smart heap
/* 0x08 */ FileEntry * fileEntry; // set if this allocation is being used for a file, gives special behaviour
/* 0x0C */ uint16_t flag; // 1 for in use, 0 otherwise
/* 0x0E */ uint8_t type; // used to group for de-allocation
/* 0x0F */ // unknown 0xf
/* 0x10 */ size_t spaceAfter; // space after the data before the next allocated data (or the end of the heap)
/* 0x14 */ SmartAllocation * next; // next item in the allocated or free linked list
/* 0x18 */ SmartAllocation * prev; // previous item in the allocated or free linked list
} SmartAllocation; // total size 0x1c

typedef struct {
/* 0x0000 */ void * heapStart;
/* 0x0004 */ SmartAllocation allocations[2048];
/* 0xE004 */ size_t heapStartSpace; // free space at the beginning of the heap
/* 0xE008 */ SmartAllocation * allocatedStart; // first item in the allocated linked list
/* 0xE00C */ SmartAllocation * allocatedEnd; // last item in the allocated linked list
/* 0xE010 */ SmartAllocation * freeStart; // first item in free allocation linked list
/* 0xE014 */ SmartAllocation * freeEnd; // last item in free allocation linked list
/* 0xE018 */ uint32_t freedThisFrame; // number of allocations freed this frame
} SmartWork; // total size 0xe01c

SmartWork smartWork; // 8051744c
SmartWork swp; // 805ae16c

int g_bFirstSmartAlloc; // 805ae9ac

/*
    Initialise heaps
*/
void memInit(); // 801a5dcc

/*
    Clear the contents of a heap
*/
void memClear(int heapId); // 801a61e4

/*
    Allocate a block of memory from a heap
*/
void * __memAlloc(int heapId, size_t size); // 801a626c

/*
    Free a block of memory back to a heap
*/
void __memFree(int heapId, void * ptr); // 801a62f0

/*
    Initialise the smart heap (requires memInit to have ran)
*/
void smartInit(); // 801a6300

/*
    Frees all allocations of a certain type
    Freeing type 3 also frees type 4
*/  
void smartAutoFree(int8_t type); // 801a64f4

/*
    Frees a smart allocation back to the smart heap
*/
void smartFree(SmartAllocation * lp); // 801a6598

/*
    Allocates memory from the smart heap of a certain type
*/
SmartAllocation * smartAlloc(size_t size, int8_t type); // 801a6794

/*
    Moves allocations forwards in the heap where possible to collect empty space
    into a larger block at the end
*/
void smartGarbage(); // 801a6b60

/*
    Sets up a GXTexObj with an image stored behind a smart allocation
*/
GXTexObj * smartTexObj(GXTexObj * texObj, SmartAllocation * imageAllocation); // 801a6cf0

// 801a6d4c, 801a6e34 unknown functions

/*
    Frees a block of memory baack to heap 0
*/
void freeToHeap0(void * ptr);

