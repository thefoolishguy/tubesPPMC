/*  EL2208 Praktikum Pemecahan Masalah dengan C 2019/2020
 *  MODUL 8 – TUGAS BESAR
 *  Kelompok            : 1
 *  Hari dan Tanggal    : Rabu, 7 April 2020
 *  Asisten (NIM)       : Berry (13216027)
 *  Nama File           : menu_test.c
 *  Deskripsi           : Main menu program Conway's Game of Life
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tick.h"


char buff[255], store[10], content;
int i, j, row, column;
FILE *fp;

int main(void)
{
    int choice;                //1. Animate, 2. Tick, 3. Quit
    int quit=0;
    char filename[20];          //File name

    printf("PROGRAM CONWAY'S GAME OF LIFE BY KELOMPOK C5\n\n");

    while(quit==0)
    {
        printf("Silakan masukkan file seed .txt yang diinginkan: "); scanf("%s", &filename);

        //Prosedure assign dari file eksternal ke matrix
        printf("run prosedur assign file eksternal ke matrix\n\n");
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

        printf("Isi file %s adalah:", filename);
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
                //run prosedur animate
                int k,m;
                printf("Masukkan jumlah iterasi animate: ");
                scanf(" %d",&m);
                //Mencetak isi awal
                system("cls");
                for (i = 0; i < row; i++)
                        {
                            for (j = 0; j < column+1; j++)
                            {printf("%c",arr[i][j]);
                            };
                        };
                printf("\nSeed Awal");
                //iterasi tick
                delay(1000);
                    for(k=0;k<m;k++){
                    system("cls");
                    tick(arr,row,column);
                    printf("\nIterasi ke %d",k+1);
                    delay(1000);
                    }
            }
            else if(choice==2)
            {
                //run prosedur tick
                printf("run prosedur tick\n");
                tick(arr, row, column);
            }
            else
            {
                printf("Input salah silakan input ulang.\n");
            };
            printf("\n1. Animate (Melakukan animasi pada seed sebanyak jumlah iterasi yang dimasukkan).\n");
            printf("2. Tick (Melakukan simulasi pada seed sebanyak satu iterasi).\n");
            printf("3. Quit (Keluar dari simulasi untuk melakukan input file seed lain atau keluar dari program).\n");
            printf("\n\nMasukkan pilihan: "); scanf("%d", &choice);
        };
        printf("Apakah mau keluar atau pilih filename lain? (1/0): "); scanf("%d", &quit);
    }

    fclose(fp);
    return 0;
}
