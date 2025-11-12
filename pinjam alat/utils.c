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
        file = fopen("dipinjaman.txt","r");
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

void lihatAlat(){ 
    FILE *file;
    file = fopen("Alat.txt", "r");
    Alat alat;

    if (file == NULL){
        printf("File Alat.txt tidak dapat ditemukan");
        return;
    }
    printf("\n=== DAFTAR ALAT LABORATURIUM YANG TERSEDIA ===\n");
    printf("ID      | NAMA        | MEREK    | MODEL   | TAHUN PRODUKSI   | JUMLAH UNIT   | TERSEDIA   \n");

    while(fscanf(file, "%u, %49[^|], %49[^|], %49[^|], %u, %u, %u",
        &alat.id, alat.nama, alat.merek, alat.model, &alat.tahun, &alat.jumlah, &alat.tersedia)==7){
            
            printf("%2u | %-13s | %-10s | %9s  | %18u | %15u | %12u \n", 
                alat.id, alat.nama, alat.merek, alat.model, alat.tahun, alat.jumlah, alat.tersedia);

        }
        fclose(file);
    }

void pinjamAlat(){
    Alat alat,pinjam_alat;
    unsigned int id;
    unsigned int jumlah_ingindipinjam;
    lihatAlat();

    printf("Masukkan id alat yang ingin dipinjam : ");
    scanf("%u", &id);

    printf("Jumlah alat yang ingin dipinjam : ");
    scanf("%u", &jumlah_ingindipinjam);

    FILE *Alat;
    FILE *tempAlat;
    FILE *pinjam;
    FILE *tempPinjam;
        
    Alat = fopen("Alat.txt", "r");
        if(Alat == NULL){
            printf("Gagal membuka file!\n");
            return;}

    tempAlat = fopen("tempAlat.txt", "w");
        if(tempAlat == NULL){
            printf("Gagal membuka file!\n");
            return;}
    int i=0;
    while(fscanf(Alat, "%u, %49[^,], %49[^,], %49[^,], %u, %u, %u",
        &alat.id, alat.nama, alat.merek, alat.model, &alat.tahun, &alat.jumlah, &alat.tersedia)==7){
        if (alat.id == id && alat.tersedia >= jumlah_ingindipinjam){
            printf("alat ditemukan!\n");
                alat.tersedia -= jumlah_ingindipinjam;
                 i=1; }
        fprintf(tempAlat, "%u, %s, %s, %s, %u, %u, %u\n",
            alat.id, alat.nama, alat.merek, alat.model, alat.tahun, alat.jumlah, alat.tersedia);
            }
        
        fclose(Alat);
        fclose(tempAlat);
        remove("Alat.txt");
        rename("tempAlat.txt", "Alat.txt");

    if (i!=1)
    {
        printf("alat tidak ditemukan atau jumlah tersedia kurang!\n");
        return;
    }
    
    else if (i==1){
        pinjam = fopen("dipinjam.txt", "r");
        
        if(pinjam == NULL){
           pinjam = fopen("dipinjam.txt", "w");
           fprintf(pinjam, "%u, %s, %s, %s, %u, %u, %u\n",
            alat.id, alat.nama, alat.merek, alat.model, 
            alat.tahun, alat.jumlah, jumlah_ingindipinjam);
            fclose(pinjam);
            return;}
   
            int a=0;
            tempPinjam = fopen("tempPinjam.txt", "w");
        while(fscanf(pinjam, "%u, %49[^,], %49[^,], %49[^,], %u, %u, %u",
                &pinjam_alat.id, pinjam_alat.nama, pinjam_alat.merek, pinjam_alat.model, 
                &pinjam_alat.tahun, &pinjam_alat.jumlah, &pinjam_alat.tersedia)==7){
                     if (pinjam_alat.id == id){
                pinjam_alat.tersedia += jumlah_ingindipinjam; a=1; }
                 fprintf(tempPinjam, "%u, %s, %s, %s, %u, %u, %u\n",
            pinjam_alat.id, pinjam_alat.nama, pinjam_alat.merek, pinjam_alat.model,
            pinjam_alat.tahun, pinjam_alat.jumlah, pinjam_alat.tersedia);
    }
    if(a==1){
    fclose(pinjam);
    fclose(tempPinjam);
    remove("dipinjam.txt");
    rename("tempPinjam.txt", "dipinjam.txt");
    return;
    }
    else
    {
    fclose(pinjam);
    pinjam = fopen("dipinjam.txt", "a");
    fprintf(pinjam, "%u, %s, %s, %s, %u, %u, %u\n",
            alat.id, alat.nama, alat.merek, alat.model, 
            alat.tahun, alat.jumlah, jumlah_ingindipinjam);
    fclose(pinjam);
    fclose(tempPinjam);
    remove("tempPinjam.txt");
    return;
    }
    printf("data peminjaman telah disimpan ke lihatpinjam.txt.");
    return;
    }
}

void kembalikanAlat(){
    Alat alat,pinjam_alat;
    unsigned int id;
    unsigned int jumlah_ingindipinjam;
    lihatAlat();

    printf("Masukkan id alat yang ingin dikembalikan: ");
    scanf("%u", &id);

    printf("Jumlah alat yang ingin dikembalikan: ");
    scanf("%u", &jumlah_ingindipinjam);

    FILE *Alat;
    FILE *tempAlat;
    FILE *pinjam;
    FILE *tempPinjam;
        
    pinjam = fopen("dipinjam.txt", "r");
        if(pinjam == NULL){
            printf("Gagal membuka file!\n");
            return;}

    tempPinjam = fopen("tempPinjam.txt", "w");
        if(tempPinjam == NULL){
            printf("Gagal membuka file!\n");
            return;}
    int i=0;
    while(fscanf(pinjam, "%u, %49[^,], %49[^,], %49[^,], %u, %u, %u",
        &pinjam_alat.id, pinjam_alat.nama, pinjam_alat.merek, pinjam_alat.model, &pinjam_alat.tahun, &pinjam_alat.jumlah, &pinjam_alat.tersedia)==7){
        if (pinjam_alat.id == id && pinjam_alat.tersedia >= jumlah_ingindipinjam){
            printf("alat ditemukan!\n");
                pinjam_alat.tersedia -= jumlah_ingindipinjam;
                 i=1; }
        fprintf(tempPinjam, "%u, %s, %s, %s, %u, %u, %u\n",
            pinjam_alat.id, pinjam_alat.nama, pinjam_alat.merek, pinjam_alat.model, pinjam_alat.tahun, pinjam_alat.jumlah, pinjam_alat.tersedia);
            }
        
        fclose(pinjam);
        fclose(tempPinjam);
        remove("dipinjam.txt");
        rename("tempPinjam.txt", "dipinjam.txt");

    if (i!=1)
    {
        printf("alat tidak ditemukan atau jumlah tersedia kurang!\n");
        return;
    }
    
    else if (i==1){
        Alat = fopen("Alat.txt", "r");
        
        if(Alat == NULL){
           Alat = fopen("Alat.txt", "w");
           fprintf(Alat, "%u, %s, %s, %s, %u, %u, %u\n",
            alat.id, alat.nama, alat.merek, alat.model, 
            alat.tahun, alat.jumlah, jumlah_ingindipinjam);
            fclose(Alat);
            return;}
   
            int a=0;
            tempAlat = fopen("tempAlat.txt", "w");
        while(fscanf(Alat, "%u, %49[^,], %49[^,], %49[^,], %u, %u, %u",
                &alat.id,alat.nama, alat.merek, alat.model, 
                &alat.tahun, &alat.jumlah, &alat.tersedia)==7){
                     if (alat.id == id){
                alat.tersedia += jumlah_ingindipinjam; a=1; }
                 fprintf(tempAlat, "%u, %s, %s, %s, %u, %u, %u\n",
            alat.id, alat.nama, alat.merek, alat.model,
            alat.tahun, alat.jumlah, alat.tersedia);
    }
    if(a==1){
    fclose(Alat);
    fclose(tempAlat);
    remove("Alat.txt");
    rename("tempAlat.txt", "Alat.txt");
    return;
    }
    else
    {
    fclose(Alat);
    Alat = fopen("Alat.txt", "a");
    fprintf(Alat, "%u, %s, %s, %s, %u, %u, %u\n",
            alat.id, alat.nama, alat.merek, alat.model, 
            alat.tahun, alat.jumlah, jumlah_ingindipinjam);
    fclose(Alat);
    fclose(tempAlat);
    remove("tempAlat.txt");
    return;
    }
    printf("data peminjaman telah disimpan ke lihatpinjam.txt.");
    return;
    }
}
    

