#define PARENT(i) i>>1
#define LEFT(i) i<<1
#define RIGHT(i) i<<1+1

typedef int INDEX;
typedef int element_type;

typedef struct HEAP{
    int length;
    int heap_size;
    element_type* elements;
} heap;

heap* MAX_HEAPIFY(heap* A, INDEX i);
heap* BUILD_MAX_HEAP(heap* A);
heap* HEAPSORT(heap* A);

// priority queue
MAX_HEAP_INSERT();
HEAP_EXTRACT_MAX();
HEAP_INCREASE_KEY();
HEAP_MAXIMUM();
