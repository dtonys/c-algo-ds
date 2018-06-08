#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
 * Write a C program which Reads an integer N from the standard input.
 * N is the size of the array arr. Fill array arr with N integers
 * (from standard input). Print out the numbers of arr and their maximum.
 */
int main() {
    int size;
    int max;
    printf("Enter the size of the array:\n");
    scanf("%d", &size);
    int arr[size];
    for(int i = 0; i < size; i++) {
        printf("Arr[%d]\n", i);
        scanf("%i", &arr[i]);
    }
    for(int i = 0; i < size; i++) {
        printf("Arr[%i]: %i\t", i, arr[i]);
        if ( arr[i] < max ) max = arr[i];
    }
    printf("\n");
    printf("max: %d", max);
    return 0;
}