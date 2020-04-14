/*  EL2208 Praktikum Pemecahan Masalah dengan C 2019/2020
 *  MODUL 9 � TUGAS BESAR
 *  Kelompok            : 5C
 *  Hari dan Tanggal    : Rabu, 7 April 2020
 *  Asisten (NIM)       : Berry (13216027)
 *  Nama File           : menu_test.c
 *  Deskripsi           : Main menu program Conway's Game of Life
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "lib_salomo.h"

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
        fileToArray(filename);



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
                //run prosedur animate
                printf("run prosedur animate\n\n");
            else if(choice==2)
                //run prosedur tick
                printf("run prosedur tick\n\n");
            else
                printf("Input salah silakan input ulang.\n");
            printf("Masukkan pilihan: "); scanf("%d", &choice);
        };
        printf("Apakah mau keluar atau pilih filename lain? (1/0): "); scanf("%d", &quit);
    }
}
