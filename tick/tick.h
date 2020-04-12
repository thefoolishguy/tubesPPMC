#pragma once

/*  Fungsi tick akan mencetak generasi selanjutnya dari Conway's Game of Life
    ke console.
    Input   : pointer of 2d array, row, column
*/
void tick (char **arr, int row, int column);

/*  Fungsi count_alive akan menghitung jumlah sel hidup di sekitar sel yang sedang diperiksa.
    Input   : pointer of 2d array, current row, current column, maximum row, maximum column
    Output  : sum of alive cells (integer)
*/
int count_alive (char **arr, int current_row, int current_column, int max_row, int max_column);