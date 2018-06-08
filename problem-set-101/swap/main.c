#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
 * Write a C program which reads two numbers a and b from the
 * standard input (Keyboard) and swap them, and then print them back on screen.
 */

int main() {
    int n1;
    int n2;
    int temp;
    printf("Num 1:\n");
    scanf("%d", &n1);
    printf("Num 2:\n");
    scanf("%d", &n2);
    temp = n1;
    n1 = n2;
    n2 = temp;
    printf("Num1:%d \tNum2:%d", n1, n2);
    return 0;
}