#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 32

void fill_matrix( char matrix[MAX_SIZE][MAX_SIZE] ) {
    for(int i = 0; i < MAX_SIZE; i++) {
        for(int j = 0; j < MAX_SIZE; j++) {
            matrix[i][j] = ' ';
        }
    }

}

void print_matrix( char matrix[MAX_SIZE][MAX_SIZE] ) {
    for(int i = 0; i < MAX_SIZE; i++) {
        for(int j = 0; j < MAX_SIZE; j++) {
            printf("%c", matrix[i][j]);
        }
        printf("\n");
    }
}

void populate_matrix(
    char matrix[MAX_SIZE][MAX_SIZE],
    int beg_row, int end_row, int beg_col, int end_col
) {
    if ( beg_row == end_row || beg_col == end_col ) {
        matrix[beg_row][beg_col] = '#';
    }
    else {
        populate_matrix(
            matrix,
            beg_row, (beg_row+end_row)/2,
            beg_col, (beg_col+end_col)/2
        );
        populate_matrix(
            matrix,
            (beg_row+end_row)/2, end_row,
            beg_col, (beg_col+end_col)/2
        );
        populate_matrix(
            matrix,
            beg_row, (beg_row+end_row)/2,
            (beg_col+end_col)/2, end_col
        );
    }
}

int main() {
    char matrix[MAX_SIZE][MAX_SIZE];
    int n = 2;
    fill_matrix(matrix);
    populate_matrix(matrix, 0, n, 0, n);
    print_matrix(matrix);
    // printf("%d", 1/2);
    return 0;
}