#include<stdio.h>
#include "utils.h"
#include "user.h"
#include "admin.h"

void menuUser(){
    int pilih;
    do {
        printf("\n=== MENU USER ===\n");
        printf("1. Lihat Alat\n");
        printf("2. Pinjam Alat\n");
        printf("3. Kembalikan Alat\n");
        printf("4. Lihat Pinjaman\n");
        printf("0. Keluar\n");
        ulang:
        printf("Pilih menu: ");
        scanf("%d", &pilih);

        switch (pilih)
        {   
        case 1:
            lihatAlat(); break;
        case 2:
            pinjamAlat(); break;
        case 3:
            kembalikanAlat(); break;
        case 4:
            lihatPinjamanUser(); break;
        case 0:
            printf("Keluar dari menu user.\n"); break;
        default:
            printf("Pilihan tidak valid.\n"); goto ulang;
        }
    } while (pilih != 0);
}