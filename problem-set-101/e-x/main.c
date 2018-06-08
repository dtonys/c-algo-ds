#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

/*
* Write a C function which takes a real number x and return the value of e^x
*/

int factorial(int n) {
    if (n == 0) return 1;
    int result = n;
    for (int i = 1; i < n; i++ ) {
        result *= n-i;
    }
    return result;
}

// NOTE: math.h also defines `exp` which is a standard way to calculate
float exponential(int n, float x) {
    float sum = 1.0f; // initialize sum of series

    for (int i = n - 1; i > 0; --i )
        sum = 1 + x * sum / i;

    return sum;
}

int main() {
    printf("%f", exponential(100, 4.0));
    return 0;
}