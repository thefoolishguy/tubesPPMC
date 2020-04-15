#pragma once
#include "lib_conway_B5.c"

/*  Fungsi tick akan mencetak generasi selanjutnya dari Conway's Game of Life
    ke console.
    Input   : pointer of 2d array, row, column
*/
void tick (char **arr, int row, int column);
void delay(int number_of_milli_seconds);
