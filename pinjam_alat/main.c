#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void menuUser();
void menuAdmin();
void pinjamAlat();
void kembalikanAlat();
void lihatPinjamanUser();
void hapusAlat();
void editAlat();
void tambahAlat();
void lihatAlat();

typedef  struct {
    unsigned int id;
    char nama[50];
    char merek[50];
    char model[50];
    unsigned int tahun;
    unsigned int jumlah;
    unsigned int tersedia;
}Alat; 

typedef struct  {
    char simpan[100], nama[50],model[50], merk[50];
    unsigned int tahun, jumlah,tersedia, id;
} data;



int main(int argc,char *argv[]){

    char username[50];
    char password[50];
    char role[10];
    
    FILE *fp = fopen("akun.txt", "r");
    int n=1;
    int i;
    while (fscanf(fp,"%s %s %s",username,password,role)==3)
    {   
        if (argc==3 &&(((strcmp(argv[1],username))==0  && (strcmp(argv[2],password))==0)))
        {  i=1; break; }    
        n++;
    }

    fclose(fp);
    if (n==3)
    { 
        printf("login gagal!\n");
        return 0; }

    else if (i==1)
    {
    printf("login berhasil sebagai %s!\n", argv[1]);

    if (strcmp(role,"admin")==0)
    { menuAdmin(); }
    else if (strcmp(role,"user")==0)
    { menuUser(); }
    }
    return 0;
}
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

void menuAdmin(){
    int pilih;
    do {
        printf("\n=== MENU ADMIN ===\n");
        printf("1. Lihat Alat\n");
        printf("2. Lihat Pinjaman\n");
        printf("3. Tambah Alat\n");
        printf("4. Edit Alat\n");
        printf("5. Hapus Alat\n");
        printf("0. Keluar\n");
        ulang:
        printf("Pilih menu: ");
        scanf("%d", &pilih);

        switch (pilih)
        {
        case 1:
            lihatAlat(); break;
        case 2:
            lihatPinjamanUser(); break;
        case 3:
            tambahAlat(); break;
        case 4:
            editAlat(); break;
        case 5:
            hapusAlat(); break;
        case 0:
            printf("Keluar dari menu admin.\n"); break;
        default:
            printf("Pilihan tidak valid.\n"); goto ulang;
        }
    } while (pilih != 0);
}

void lihatPinjamanUser(){
        FILE *file;
        Alat pinjam_alat;
        file = fopen("dipinjam.txt","r");
        if (file == NULL){
            printf("belum ada yang di pinjam ");
            return; 
        } 
        printf("============================================================\n");
        printf("Data Alat Laboraterium\n");
        printf("============================================================\n");
        printf("Id |Nama Alat      |Merek    |model       |tahun      |jumlah | DIPINJAM \n  ");
       printf("============================================================\n");
        while (fscanf(file,"%u %s %s %s %u %u %u\n", &pinjam_alat.id,pinjam_alat.nama, pinjam_alat.merek, pinjam_alat.model, &pinjam_alat.tahun, &pinjam_alat.jumlah,&pinjam_alat.tersedia) != EOF){
            printf("%-3d|%-15s|%-8s|%-11s|%-11d|%-6d|%-6d\n",pinjam_alat.id, pinjam_alat.nama, pinjam_alat.merek, pinjam_alat.model, pinjam_alat.tahun, pinjam_alat.jumlah, pinjam_alat.tersedia);
        }
        printf("============================================================\n");
        fclose(file);
    
    }

void lihatAlat(){ 
    FILE *file;
    file = fopen("alat.txt", "r");
    Alat alat;

    if (file == NULL){
        printf("File alat.txt tidak dapat ditemukan");
        return;
    }
    printf("\n=== DAFTAR ALAT LABORATURIUM YANG TERSEDIA ===\n");
    printf("ID      | NAMA        | MEREK    | MODEL   | TAHUN PRODUKSI   | JUMLAH UNIT   | TERSEDIA   \n");

    while(fscanf(file, "%u %s %s %s %u %u %u",
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
        
    Alat = fopen("alat.txt", "r");
        if(Alat == NULL){
            printf("Gagal membuka file!\n");
            return;}

    tempAlat = fopen("tempalat.txt", "w");
        if(tempAlat == NULL){
            printf("Gagal membuka file!\n");
            return;}
    int i=0;
    while(fscanf(Alat, "%u %s %s %s %u %u %u",
        &alat.id, alat.nama, alat.merek, alat.model, &alat.tahun, &alat.jumlah, &alat.tersedia)==7){
        if (alat.id == id && alat.tersedia >= jumlah_ingindipinjam){
            printf("alat ditemukan!\n");
                alat.tersedia -= jumlah_ingindipinjam;
                pinjam_alat=alat;
                 i=1; }
        fprintf(tempAlat, "%u %s %s %s %u %u %u\n",
            alat.id, alat.nama, alat.merek, alat.model, alat.tahun, alat.jumlah, alat.tersedia);
            }
        
        fclose(Alat);
        fclose(tempAlat);
        remove("alat.txt");
        rename("tempalat.txt", "alat.txt");

    if (i!=1)
    {
        printf("alat tidak ditemukan atau jumlah tersedia kurang!\n");
        return;
    }
    
    else if (i==1){
        pinjam = fopen("dipinjam.txt", "r");
        
        
        if((pinjam == NULL) || (fgetc(pinjam)==EOF)){
           pinjam = fopen("dipinjam.txt", "w");
           fprintf(pinjam, "%u %s %s %s %u %u %u\n",
            pinjam_alat.id, pinjam_alat.nama, pinjam_alat.merek, pinjam_alat.model, 
            pinjam_alat.tahun, pinjam_alat.jumlah, jumlah_ingindipinjam);
            fclose(pinjam);
            return;}
   
            int a=0;
            tempPinjam = fopen("tempPinjam.txt", "w");
        while(fscanf(pinjam, "%u %s %s %s %u %u %u",
                &pinjam_alat.id, pinjam_alat.nama, pinjam_alat.merek, pinjam_alat.model, 
                &pinjam_alat.tahun, &pinjam_alat.jumlah, &pinjam_alat.tersedia)==7){
                     if (pinjam_alat.id == id){
                pinjam_alat.tersedia += jumlah_ingindipinjam; a=1; }
                 fprintf(tempPinjam, "%u %s %s %s %u %u %u\n",
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
    fprintf(pinjam, "%u %s %s %s %u %u %u\n",
            pinjam_alat.id, pinjam_alat.nama, pinjam_alat.merek, pinjam_alat.model, 
            pinjam_alat.tahun, pinjam_alat.jumlah, jumlah_ingindipinjam);
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
    unsigned int jumlah_ingindikembalikan;
    lihatAlat();

    printf("Masukkan id alat yang ingin dikembalikan: ");
    scanf("%u", &id);

    printf("Jumlah alat yang ingin dikembalikan: ");
    scanf("%u", &jumlah_ingindikembalikan);

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
    while(fscanf(pinjam, "%u %s %s %s %u %u %u",
        &pinjam_alat.id, pinjam_alat.nama, pinjam_alat.merek, pinjam_alat.model, &pinjam_alat.tahun, &pinjam_alat.jumlah, &pinjam_alat.tersedia)==7){
        if (pinjam_alat.id == id && pinjam_alat.tersedia >= jumlah_ingindikembalikan){
            printf("alat ditemukan!\n");
                pinjam_alat.tersedia -= jumlah_ingindikembalikan;
                 i=1; }
        fprintf(tempPinjam, "%u %s %s %s %u %u %u\n",
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
        Alat = fopen("alat.txt", "r");
        
        if((Alat == NULL) ){
           Alat = fopen("alat.txt", "w");
           fprintf(Alat, "%u %s %s %s %u %u %u\n",
            alat.id, alat.nama, alat.merek, alat.model, 
            alat.tahun, alat.jumlah, jumlah_ingindikembalikan);
            fclose(Alat);
            return;}
   
            int a=0;
            tempAlat = fopen("tempalat.txt", "w");
        while(fscanf(Alat, "%u %s %s %s %u %u %u",
                &alat.id,alat.nama, alat.merek, alat.model, 
                &alat.tahun, &alat.jumlah, &alat.tersedia)==7){
                     if (alat.id == id){
                alat.tersedia += jumlah_ingindikembalikan; a=1; }
                 fprintf(tempAlat, "%u %s %s %s %u %u %u\n",
            alat.id, alat.nama, alat.merek, alat.model,
            alat.tahun, alat.jumlah, alat.tersedia);
    }
    if(a==1){
    fclose(Alat);
    fclose(tempAlat);
    remove("alat.txt");
    rename("tempalat.txt", "alat.txt");
    return;
    }
    else
    {
    fclose(Alat);
    Alat = fopen("alat.txt", "a");
    fprintf(Alat, "%u %s %s %s %u %u %u\n",
            alat.id, alat.nama, alat.merek, alat.model, 
            alat.tahun, alat.jumlah, jumlah_ingindikembalikan);
    fclose(Alat);
    fclose(tempAlat);
    remove("tempalat.txt");
    return;
    }
    printf("data peminjaman telah disimpan ke lihatpinjam.txt.");
    return;
    }
}

void hapusAlat(){
    FILE *temp, *file;
    
    data alat;

    file = fopen("alat.txt", "r");
    temp = fopen("temp.txt", "w");

    if (file == NULL || temp == NULL) {
        printf("Gagal membuka file alat.txt\n");
        return;
    }

    int idHapus;
    printf("Masukkan ID alat yang mau anda hapus: ");
    scanf("%d",&idHapus);

    int ditemukan = 0;
    
    while (fgets(alat.simpan, sizeof(alat.simpan), file) != NULL){
        sscanf(alat.simpan, "%u|", &alat.id);
        if(alat.id != idHapus){
            fputs(alat.simpan, temp);
        } else {
            ditemukan = 1;
        }
    }
    fclose(file);
    fclose(temp);
    remove("alat.txt");
    rename("temp.txt", "alat.txt");

    if(ditemukan){
        printf("Alat dengan id %d sudah dihapus.\n", idHapus);
    } else {
        printf("Alat dengan id %d tidak ada di dalam daftar.\n", idHapus);
    }

}

void editAlat(){
    FILE *temp, *file;
    file = fopen("alat.txt", "r");
    temp = fopen("temp.txt", "w");

    if (file == NULL || temp == NULL) {
        printf("Gagal membuka file alat.txt\n");
        return;
    }

    int idEdit;
    printf("Masukkan id yang mau anda edit: ");
    scanf("%d",&idEdit);

    data alat;
    int ditemukan = 0;

    while (fgets(alat.simpan, sizeof(alat.simpan), file) != NULL) {
        sscanf(alat.simpan, "%u|%[^|]|%[^|]|%[^|]|%u|%u|%u", &alat.id, alat.nama, alat.merk, alat.model, &alat.tahun, &alat.jumlah, &alat.tersedia);
        if(alat.id == idEdit){
            ditemukan = 1;
            printf("Masukkan nama alat baru: ");
            scanf(" %[^\n]", alat.nama);
            printf("Masukkan model alat baru: ");
            scanf(" %[^\n]", alat.merk);
            printf("Masukkan merk alat baru: ");
            scanf(" %[^\n]", alat.model);
            printf("Masukkan tahun alat baru: ");
            scanf("%d", &alat.tahun);
            printf("Masukkan jumlah alat baru: ");
            scanf("%d", &alat.jumlah);
            alat.tersedia = alat.jumlah; 
            fprintf(temp, "%u|%s|%s|%s|%u|%u|%u\n", alat.id, alat.nama, alat.merk, alat.model, alat.tahun, alat.jumlah, alat.tersedia);
        } else {
            fputs(alat.simpan, temp);
        }
    }

        fclose(file);
        fclose(temp);
        remove("alat.txt");
        rename("temp.txt", "alat.txt");

        if(ditemukan){
            printf("Alat dengan id %d sudah diupdate.\n", idEdit);
        } else {
            printf("Alat dengan id %d tidak ada di dalam daftar.\n", idEdit);
        }
}

void tambahAlat(){
    FILE *file;
    data alat;

    file = fopen("alat.txt", "a");
    if(file == NULL) {
        printf("Gagal membuka file alat.txt\n");
        return;
    }

    printf("======= Masukkan data alat barunya woi! =======");
    printf("Masukkan id alat baru : ");
    scanf("%d",&alat.id);
    printf("Masukkan nama alat baru yang mau ditambahkan : ");
    scanf(" %[^\n]", alat.nama);
    printf("Masukkan model alat baru yang mau ditambahkan : ");
    scanf(" %[^\n]", alat.model);
    printf("Masukkan merk alat baru yang mau ditambahkan : ");
    scanf(" %[^\n]", alat.merk);
    printf("Masukkan tahun alat baru yang mau ditambahkan : ");
    scanf("%d", &alat.tahun);
    printf("Masukkan jumlah alat baru yang mau ditambahkan : ");
    scanf("%d", &alat.jumlah);
    alat.tersedia = alat.jumlah;


    fprintf(file, "%u|%s|%s|%s|%u|%u|%u\n", alat.id, alat.nama, alat.merk, alat.model, alat.tahun, alat.jumlah, alat.tersedia);
    fclose(file);
}
