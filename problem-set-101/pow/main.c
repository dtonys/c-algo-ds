#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

/*
 * Write a C program which reads two numbers “base” and “expo” , and
 * calculate the power of base to the expo and print the result. Note that
 * power(base,expo) = base * base * base …. base  expo times.
 *
 * Note: Do this task in two different ways(The first way is with the pow
 * function predefined in the math.h header file , and the second way is by
 * creating your own power function).
 */

 double custom_pow(double base, double expo) {
    double result = 1;
    for(int i = 0; i < expo; i++) {
        result = result * base;
    }
    return result;
 }

int main() {
    double base;
    double expo;
    double result;
    double custom_result;
    printf("base: \n");
    scanf("%lf", &base);
    printf("expo: \n");
    scanf("%lf", &expo);
    result = pow(base, expo);
    custom_result = custom_pow(base, expo);
    printf("result: %lf\n", result);
    printf("custom_result: %lf\n", custom_result);
    return 0;
}