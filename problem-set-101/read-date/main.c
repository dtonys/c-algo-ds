#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Write a C program which reads the date formatted mm/dd/yyyy and then it
// prints the total number of days since 00/00/0000.
// Note : You can assume that every month has 30 days so every year has a 360
// days.

int main() {
    char date[50] = "03/04/2001";
    char days_str[5];
    char months_str[5];
    char years_str[5];

    strncpy( days_str, date, 2 );
    strncpy( months_str, date + 3, 2);
    strncpy( years_str, date + 6, 4);
    days_str[2] = '\0';
    months_str[2] = '\0';
    years_str[4] = '\0';
    int days = (int) strtol(days_str, NULL, 10);
    int months = (int) strtol(months_str, NULL, 10);
    int years = (int) strtol(years_str, NULL, 10);
    printf("%i\n", days);
    printf("%i\n", months);
    printf("%i\n", years);
    int total_days = (years * 360) + (months * 30) + days;
    printf("total days: %i\n", total_days );
    return 0;
}