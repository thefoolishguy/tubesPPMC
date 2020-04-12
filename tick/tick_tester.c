#include <stdio.h>
#include <stdlib.h>
#include "tick.h"

/* Fungsi utama, untuk mengetes fungsi tick */
int main(){

    // Kamus

    int row = 10, column = 10, i, j;
    char *arr[row];

    // Algoritma

    for (i=0; i<row; i++){
        arr[i] = (char*) malloc (column*sizeof(char));
    }
    
    for (i = 0; i < row; i ++){
        for (j = 0; j < column; j++){
            // if(j % 2 == 0 || i % 5 == 0){
            //     arr[i][j] = 'X';
            // }
            // else {
            //     arr[i][j] = '-';
            // }
            arr[i][j] = '-';
            
        }
    }

    arr[1][1] = 'X';
    arr[1][2] = 'X';
    arr[2][1] = 'X';
    arr[2][2] = 'X';
    arr[1][3] = 'X';
    arr[2][3] = 'X';

    for (i = 0; i < row; i ++){
        for (j = 0; j < column; j++){
            if(j==0){
                printf("\n");
            }
            printf("%c", arr[i][j]);
        }
    }
    printf("\n");
    
    tick(arr, row, column);

    tick(arr, row, column);

    return 0;
}