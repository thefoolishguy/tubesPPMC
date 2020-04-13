#include <stdio.h>
#include <stdlib.h>

/*  EL2208 Praktikum Pemecahan Masalah dengan C 2019/2020

 *  MODUL 9 � TUGAS BESAR
 *  Kelompok            : 5C
 *  Hari dan Tanggal    : Senin, 12 April 2020
 *  Asisten (NIM)       : Berry (13216027)
 *  Nama File           : baca file ke array.c
 *  Deskripsi           : Konversi TXT ke array
 */
//Nama fungsi dan parameter fungsi akan disesuaikan nama variabel main di kemudian hari
void main()
{
    FILE *fp;
    char buff[255];
    fp = fopen("test.txt", "r");
    int row, column;
    char store[10];

    fscanf(fp,"%s",store);
    printf("ROW length : %s\n", store);
    row= atoi(store);

    fscanf(fp,"%s",store);
    printf("COLUMN length : %s\n", store);
    column= atoi(store);
    int i, j, count;

    char *arr[row];
    for (i=0; i<row; i++)
         arr[i] = (char *)malloc(column * sizeof(int));

    char content;
    for (i = 0; i < row; i++){
      for (j = 0; j < column+1; j++){
        fscanf(fp, "%c", &content);
        arr[i][j]=content;
        printf("%c",content);
      }
    }


}
