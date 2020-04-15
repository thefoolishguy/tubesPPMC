/*  EL2208 Praktikum Pemecahan Masalah dengan C 2019/2020
 *  MODUL 8 – TUGAS BESAR
 *  Kelompok            : 5C
 *  Hari dan Tanggal    : Rabu, 15 April 2020
 *  Asisten (NIM)       : Berry (13216027)
 *  Nama File           : menu_conway.c
 *  Deskripsi           : Main menu program Conway's Game of Life
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "lib_conway.h"

char buff[255], store[10], content;
int i, j, row, column, n_animate, k, m;
FILE *fp;

int main(void)
{
    int choice;                 //1. Animate, 2. Tick, 3. Quit
    int quit=0;
    char filename[20];          //File name

    printf("----------PROGRAM CONWAY'S GAME OF LIFE BY KELOMPOK C5----------\n\n");
    printf("Program ini merupakan sebuah simulator perkembangan suatu populasi\n");
    printf("berdasarkan aturan tertentu. Input file merupakan file eksternal .txt\n");
    printf("yang berisi array yang memodelkan populasi tersebut. Sel mati dimodelkan\n");
    printf("sebagai - dan sel hidup sebagai X. Pada setiap buah iterasi, populasi\n");
    printf("akan mengalami perubahan state mengikuti empat buah kondisi, yaitu\n");
    printf("underpopulation, next generation, overpopulation, dan reproduction.\n");
    printf("\nSelamat bermain!\n");


    while(quit==0)
    {
        printf("\nSilakan masukkan file seed .txt yang diinginkan: "); scanf("%s", &filename);

        //Assign dari file eksternal ke matrix dalam program
        fp = fopen(filename, "r");

        fscanf(fp,"%s",store);
        row= atoi(store);
        fscanf(fp,"%s",store);
        column= atoi(store);

        char *arr[row];
        for (i=0; i<row; i++)
        {
            arr[i] = (char *)malloc(column * sizeof(int));
        };

        //Memunculkan isi matrix dalam program
        printf("\nIsi file %s adalah:", filename);
        for (i = 0; i < row; i++)
        {
            for (j = 0; j < column+1; j++)
            {
                fscanf(fp, "%c", &content);
                arr[i][j]=content;
                printf("%c",arr[i][j]);
            };
        };

        //Looping menu
        printf("\n\nFile seed telah berhasil di-load dan di-assign ke dalam array.\n");
        printf("Pilih operasi yang akan dilakukan pada seed:\n");
        printf("1. Animate (Melakukan animasi pada seed sebanyak jumlah iterasi yang dimasukkan).\n");
        printf("2. Tick (Melakukan simulasi pada seed sebanyak satu iterasi).\n");
        printf("3. Quit (Keluar dari simulasi untuk melakukan input file seed lain atau keluar dari program).\n\n");

        printf("Masukkan pilihan: "); scanf("%d", &choice);

        if(choice==3)
        {
            quit=1;
        };
        while((choice!=3) && (quit!=1))
        {
            if(choice==1)
            {
                //run animate
                printf("Masukkan jumlah iterasi animate: ");scanf("%d",&m);
                system("cls");

                for(k=0;k<m;k++)
                {
                    system("cls");
                    tick(arr,row,column);
                    printf("\nIterasi ke %d",k+1);
                    delay(250);
                };
            }
            else if(choice==2)
            {
                //run tick
                tick(arr, row, column);
            }
            else
            {
                printf("Input salah silakan input ulang.\n");
            };
            printf("\n\nMasukkan pilihan: "); scanf("%d", &choice);
        };
        printf("Apakah mau keluar atau pilih filename lain? (1/0): "); scanf("%d", &quit);
    };
    printf("Terimakasih telah memainkan program Conway's Game of Life!\n");

    fclose(fp);
    return 0;
}
