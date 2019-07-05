#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define PARENT(i) i>>1
#define LEFT(i) i<<1
#define RIGHT(i) i<<1+1

typedef unsigned int INDEX;
typedef int element_type;

typedef struct HEAP{
    unsigned int length;
    unsigned int heap_size;
    element_type* elements;
} heap;

bool swap(element_type* a, element_type* b) {
    element_type tmp = *a;
    *a = *b;
    *b = tmp;
    return true;
}

heap* MAX_HEAPIFY(heap* A, INDEX i) {
    INDEX l = LEFT(i);
    INDEX r = RIGHT(i);
    INDEX largest = 0;
    if (l <= A->heap_size && A->elements[l] > A->elements[i]) {
        largest = l;
    } else {
        largest = i;
    }
    if (r <= A->heap_size && A->elements[r] > A->elements[largest]) {
        largest = r;
    }
    if (largest != i) {
        swap(&(A->elements[i]), &(A->elements[largest]));
        MAX_HEAPIFY(A, largest);
    }
    return A;
}
heap* BUILD_MAX_HEAP(heap* A) {
    A->heap_size = A->length;
    for (INDEX i = A->length >> 1; i > 0; i--) {
        MAX_HEAPIFY(A, i);
    }
    return A;
}
heap* HEAPSORT(heap* A) {
    BUILD_MAX_HEAP(A);
    for (INDEX i = A->length; i > 1; i--) {
        swap(&(A->elements[1]), &(A->elements[i]));
        A->heap_size -= 1;
        MAX_HEAPIFY(A, 1);
    }
}

// related to priority queue
MAX_HEAP_INSERT();
HEAP_EXTRACT_MAX();
HEAP_INCREASE_KEY();
HEAP_MAXIMUM();

// for test
heap* HEAP_INITIALIZE(element_type[] array, unsigned int length_array) {
    heap* h = (heap*)malloc(sizeof(heap));
    h->length = length_array;
    h->heap_size = 0;
    h->elements = (element_type*)malloc(sizeof(element_type) * (length_array+1));
    for (INDEX i = 0; i < length_array; i++) {
        h->elements[i+1] = array[i];
    }
    return h;
}
bool PRINT_HEAP(heap* A) {
    printf("\n");
    for (INDEX i = 1; i <= A->length; i++) {
        printf("%d ", A->elements[i]);
    }
    printf("\n");
    return true;
}
