/*  EL2208 Praktikum Pemecahan Masalah dengan C 2019/2020
 *  MODUL 9 - TUGAS BESAR
 *  Kelompok            : B5
 *  Hari dan Tanggal    : Rabu, 15 April 2020
 *  Asisten (NIM)       : Berry (13216027)
 *  Nama File           : lib_conway_B5.c
 *  Deskripsi           : Mencetak generasi selanjutnya dalam Conway's Game of Life
 */

#include <stdio.h>

/*  Fungsi count_alive akan menghitung jumlah sel hidup di sekitar sel yang sedang diperiksa.
    Input   : pointer of 2d array, current row, current column, maximum row, maximum column
    Output  : sum of alive cells (integer).
*/
int count_alive (char **arr, int current_row, int current_column, int max_row, int max_column);

/*
    Prosedur delay merupakan prosedur untuk memberikan delay pada program, terdapat parameter
    berupa delay yang diinginkan dalam milli second (ms).
*/
void delay(int number_of_milli_seconds)
{
    // Menyimpan waktu mulai
    clock_t start_time = clock();

    // Looping sampai kondisi tercapai
    while (clock() < start_time + number_of_milli_seconds);
};

void tick (char **arr, int row, int column){

    // Kamus Lokal

    int arr_alive_cells[row][column];       // Array dari jumlah sel tetangga yang hidup
    int i,j;

    // Algoritma

    for (i = 0; i < row; i++){

        for (j = 0; j < column; j++){

            // Hitung jumlah sel tetangga yang hidup
            // Sel hidup adalah 'X' sedangkan sel mati adalah '-'
            arr_alive_cells[i][j] = count_alive(arr, i, j, (row-1), (column-1));

        }

    }

    // Cek sebanyak row dan column
    for (i = 0; i < row; i++){

        for (j = 0; j < column; j++){

            // Jika merupakan baris baru, maka berikan new line
            if (j == 0) {
                printf("\n");
            }

            // Jika sel saat ini merupakan sel mati
            if (arr[i][j] == '-'){

                // Jika terdapat 3 buah sel hidup di sekitar sel mati tsb.
                if (arr_alive_cells[i][j] == 3){

                    // Sel tersebut menjadi hidup (reproduction)
                    arr[i][j] = 'X';

                }

            }
            // Jika sel saat ini merupakan sel hidup
            else {

                // Jika terdapat tetangga yang hidup <=1 atau >=4
                if (arr_alive_cells[i][j] <= 1 || arr_alive_cells[i][j] >= 4){

                    // Sel tersebut menjadi mati (underpopulation/overpopulation)
                    arr[i][j] = '-';

                }

            }

            // Print sel ke console
            printf("%c", arr[i][j]);

        }

    }

}

int count_alive (char **arr, int current_row, int current_column, int max_row, int max_column){

    // Kamus Lokal

    int row_to_check;           // Baris yang akan diperiksa
    int col_to_check;           // Kolom yang akan diperiksa
    int alive;                  // Jumlah yang hidup
    int m,n;

    // Algoritma

    alive = 0;

    for (m = -1; m <= 1; m++){
        for (n = -1; n <= 1; n++){

            // Jika row saat ini di paling atas
            if (current_row + m < 0){

                // Row yang akan dicek adalah row paling bawah
                row_to_check = max_row;

            }
            // Jika row saat ini di paling bawah
            else if (current_row + m > max_row){

                // Row yang akan dicek adalah row paling atas
                row_to_check = 0;

            }
            // Jika row di tengah-tengah
            else {

                row_to_check = current_row + m;

            }

            // Jika column saat ini di paling kiri
            if (current_column + n < 0){

                // Column yang akan dicek adalah column paling kanan
                col_to_check = max_column;

            }
            // Jika column saat ini di paling kanan
            else if (current_column + n > max_column){

                // Column yang akan dicek adalah column paling kiri
                col_to_check = 0;

            }
            // Jika column di tengah-tengah
            else{

                col_to_check = current_column + n;

            }

            // Jika sel yang akan dicek hidup
            if (arr[row_to_check][col_to_check] == 'X'){

                alive += 1;

            }

        }
    }

    // Jika sel sendiri hidup, kurangi jumlah yang hidup dengan 1
    // karena sel sendiri ikut terhitung
    if (arr[current_row][current_column] == 'X'){
        alive -= 1;
    }

    // Kembalikan jumlah yang hidup
    return(alive);

}
