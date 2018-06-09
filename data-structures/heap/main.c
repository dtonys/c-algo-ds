#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

typedef struct heap {
    int size;
    int *arr;
} heap;

heap * create_heap(int max_size) {
    heap *h = (heap *) malloc(sizeof(heap));
    h->arr = (int *) malloc(sizeof(int) * max_size);
    h->size = 0;
    return h;
}

bool heap_empty(heap* h) {
    return h->size == 0;
}

int find_greater_index(int *arr, int left_index, int right_index) {
    return arr[left_index] > arr[right_index]
        ? left_index
        : right_index;
}

int max( int n1, int n2 ) {
    return n2 > n1 ? n2 : n1;
}

int min( int n1, int n2 ) {
    return n2 < n1 ? n2 : n1;
}

void swap(int *n1, int *n2) {
    int temp = *n1;
    *n1 = *n2;
    *n2 = temp;
}

void insert_max_heap(heap *h, int value) {
    // insert at end of list
    h->arr[h->size] = value;
    int child_index = h->size;
    h->size++;
    int parent_index = (child_index - 1) / 2;
    // heapify up
    while( child_index > 0 && h->arr[child_index] > h->arr[parent_index] ) {
        swap( &h->arr[child_index], &h->arr[parent_index] );
        child_index = parent_index;
        parent_index = (child_index - 1) / 2;
    }
}

int extract_max_heap(heap *h) {
    if( heap_empty(h) ) {
        printf("Error: heap empty");
        return -1;
    }
    int value = h->arr[0];
    h->size--;
    h->arr[0] = h->arr[h->size];

    // heapify down
    int parent_index = 0;
    int left_index = (parent_index * 2) + 1;
    int right_index = (parent_index * 2) + 2;
    bool child_within_bounds = left_index < h->size;
    bool child_greater_than_parent = h->arr[parent_index] < max(
        h->arr[left_index],
        h->arr[right_index]
    );
    while( child_within_bounds && child_greater_than_parent ) {
        int selected_index;
        if( right_index < h->size )
            selected_index = find_greater_index(
                h->arr, left_index, right_index);
        else
            selected_index = left_index;
        swap( &h->arr[selected_index], &h->arr[parent_index] );
        parent_index = selected_index;
        left_index = (parent_index * 2) + 1;
        right_index = (parent_index * 2) + 1;
        child_within_bounds = h->arr[left_index] < h->size;
        child_greater_than_parent = h->arr[parent_index] < max(
            h->arr[left_index],
            h->arr[right_index]
        );
    }
    return value;
};

void print_heap(heap* h) {
    int threshold = 0;
    int threshold_count = 1;
    for(int i = 0; i < h->size; i++) {
        printf("%d\t", h->arr[i]);
        if( i == threshold ) {
            printf("\n");
            threshold = threshold + pow(2, threshold_count);
            threshold_count++;
        }
    }
    printf("\n");
};

int main() {
    heap *h = create_heap(10);
    // insert values -> 5,2,3,1
    insert_max_heap(h, 5);
    insert_max_heap(h, 2);
    insert_max_heap(h, 3);
    insert_max_heap(h, 1);

    print_heap(h);

    // extract values -> 5, 3
     while( !heap_empty(h) )
        printf("Extract: %d\n", extract_max_heap(h));

    return 0;
}