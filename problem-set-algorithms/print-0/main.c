#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Write a c program which takes a number n from the standard input and print
// the following expression
// 0 = (0 + 0) recursively , the depth depends on n
// Sample input 1: 0  Sample output 1: 0 = 0
// Sample input 2: 2  Sample output 2: 0 = ((0 + 0) + (0 + 0))

void print_0s(int n) {
    if( n == 0 ) {
        printf("0");
        return;
    }
    printf("(");
    print_0s(n-1);
    printf(" + ");
    print_0s(n-1);
    printf(")");
}

int main() {
    int n = 3;
    printf("0 = ");
    print_0s(n);
    return 0;
}