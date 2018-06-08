#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Write a C program which reads a text from the standard input (Keyboard)
// and  if its length is bigger than 10 print out a the second five letters
// (Letter at index 5,6,7,8 and 9).

int main() {
    char str1[100] = "Abcdefghijklmnop";
    char str2[100];
    printf("Enter a string:\n");
    gets(str1);
    if ( strlen(str1) < 10 ) return 0;
    strncpy(str2, str1 + 5, 5);
    str2[5] = '\0';
    puts(str2);
    return 0;
}