#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Write a C program which takes two integers n ( number ) and b ( brackets )
// and print the number n surrounded by b square brackets.
// Sample Input 1: 56 4  Sample output 1: [[[[56]]]]

void print_brackets(int num, int num_brackets) {
    if( num_brackets == 0 ) {
        printf("%d", num);
        return;
    }
    printf("[");
    print_brackets(num, num_brackets-1);
    printf("]");
}

int main() {
    int num;
    int num_brackets;
    printf("num: \n");
    scanf("%d", &num);
    printf("num_brackets: \n");
    scanf("%d", &num_brackets);
    print_brackets(num, num_brackets);
    return 0;
}