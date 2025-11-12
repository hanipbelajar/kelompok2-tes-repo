#include <stdio.h>
#include <stdlib.h>
#include<string.h>

 typedef  struct {
    unsigned int id;
    char nama[50];
    char merek[50];
    char model[50];
    unsigned int tahun;
    unsigned int jumlah;
    unsigned int tersedia;
}Alat; 

    void lihatPinjamanUser(){
        FILE *file;
        Alat pinjam_alat;
        file = fopen("peminjaman.txt","r");
        if (file == NULL){
            printf("belum ada yang di pinjam ");
            return;
        } 
        printf("============================================================\n");
        printf("Data Alat Laboraterium\n");
        printf("============================================================\n");
        printf("Id |Nama Alat      |Merek    |model       |tahun      |jumlah |Tersedia \n  ");
       printf("============================================================\n");
        while (fscanf(file,"%d %49s %49s %49s %d %d %d\n", pinjam_alat.id,pinjam_alat.nama, pinjam_alat.merek, pinjam_alat.model, &pinjam_alat.tahun, &pinjam_alat.jumlah,&pinjam_alat.tersedia) != EOF){
            printf("%-3d|%-15s|%-8s|%-11s|%-11d|%-6d|%-6d\n",pinjam_alat.id, pinjam_alat.nama, pinjam_alat.merek, pinjam_alat.model, pinjam_alat.tahun, pinjam_alat.jumlah, pinjam_alat.tersedia);
        }
        printf("============================================================\n");
        fclose(file);
    
    }
    int main(){
        lihat_alat();
        return 0;
    }
    

