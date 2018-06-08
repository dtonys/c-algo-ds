#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
 * Write a C program which reads two numbers n and p from the standard input
* (Keyboard) and calculate the number of combinations we can make from n if
* you chose p, and then print it on screen.
* you chose p, and then print it on screen.
*/

int factorial(int n) {
    int result = n;
    for (int i = 1; i < n; i++ ) {
        result *= n-i;
    }
    return result;
}

int main() {
    int n;
    int p;
    int num_combinations;

    printf("n: \n");
    scanf("%i", &n);
    printf("p: \n");
    scanf("%i", &p);

    num_combinations = factorial(n) / (factorial(p)*(factorial(n-p)));
    printf("num_combinations: %d", num_combinations);

    return 0;
}