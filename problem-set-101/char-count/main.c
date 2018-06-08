#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

// Write a program which takes a text from the user, and then print the
// occurrences of all characters in that text.
// Note : ‘C’ and ‘c’ should be considered ‘c’, in other words the text is
// case insensitive.

int main() {
    char sample[1000] = "C language is a very powerful language that allows "
                        "programmers to fully control their computers";
    int occs[256] = { 0 };
    int len = strlen(sample);
    // convert to lower case
    for(int i = 0; i < len; i++) {
        sample[i] = tolower(sample[i]);
    }

    for(int i = 0; i < len; i++) {
        char c = sample[i];
        occs[c]++;
    }
    for(int i = 0; i < 256; i++) {
        if ( occs[i] > 0 ) {
            printf("%c : %d \n", i, occs[i]);
        }
    }
    return 0;
}