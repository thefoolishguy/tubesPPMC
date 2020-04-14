#pragma once
#include "tick.c"

/*  Fungsi tick akan mencetak generasi selanjutnya dari Conway's Game of Life
    ke console.
    Input   : pointer of 2d array, row, column
*/
void tick (char **arr, int row, int column);