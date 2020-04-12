/*  EL2208 Praktikum Pemecahan Masalah dengan C 2019/2020
 *  MODUL 8 � TUGAS BESAR
 *  Kelompok            : 1
 *  Hari dan Tanggal    : Minggu, 12 April 2020
 *  Asisten (NIM)       : Berry (13216027)
 *  Nama File           : tick.c
 *  Deskripsi           : Mencetak generasi selanjutnya dalam Conway's Game of Life
 */

#include <stdio.h>
#include <stdlib.h>

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
            if(j % 2 == 0 || i % 5 == 0){
                arr[i][j] = 'X';
            }
            else {
                arr[i][j] = '-';
            }
            
        }
    }

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

    return 0;
}

void tick (char **arr, int row, int column){
    
    // Kamus Lokal
    
    int alive_cells;            // Jumlah sel yang hidup di sekitar sel yang diperiksa
    int i,j;

    // Algoritma

    // Cek sebanyak row dan column
    for (i = 0; i < row; i++){

        for (j = 0; j < column; j++){
            
            // Reset alive_cells
            alive_cells = 0;

            // Jika merupakan baris baru, maka berikan new line
            if (j == 0) {
                printf("\n");
            }

            // Hitung jumlah sel hidup di sekitar sel
            // Sel hidup adalah 'X' sedangkan sel mati adalah '-'
            alive_cells = count_alive(arr, i, j, (row-1), (column-1));

            // Jika sel saat ini merupakan sel mati
            if (arr[i][j] == '-'){

                // Jika terdapat 3 buah sel hidup di sekitar sel mati tsb.
                if (alive_cells == 3){

                    // Sel tersebut menjadi hidup (reproduction)
                    arr[i][j] = 'X';

                }

            }
            // Jika sel saat ini merupakan sel hidup
            else {

                // Jika terdapat tetangga yang hidup <=1 atau >=4
                if (alive_cells <= 1 || alive_cells >= 4){

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
    
    // int row_above, row_below, column_left, column_right;
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

            // Jika sel yang akan dicek hidup dan bukan merupakan diri sendiri
            if (arr[row_to_check][col_to_check] == 'X' && (m != 0 && n != 0)){

                alive += 1;

            }

        }
    }

    // Kembalikan jumlah yang hidup
    return(alive);
  
}