#include <stdio.h>

typedef struct  {
    char simpan[100], nama[50],model[50], merk[50];
    unsigned int tahun, jumlah,tersedia, id;
} data;





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
        sscanf(alat.simpan, "%d|", &alat.id);
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
        sscanf(alat.simpan, "%d|%[^|]|%[^|]|%[^|]|%d|%d|%d", &alat.id, alat.nama, alat.model, alat.merk, &alat.tahun, &alat.jumlah, &alat.tersedia);
        if(alat.id == idEdit){
            ditemukan = 1;
            printf("Masukkan nama alat baru: ");
            scanf(" %[^\n]", alat.nama);
            printf("Masukkan model alat baru: ");
            scanf(" %[^\n]", alat.model);
            printf("Masukkan merk alat baru: ");
            scanf(" %[^\n]", alat.merk);
            printf("Masukkan tahun alat baru: ");
            scanf("%d", &alat.tahun);
            printf("Masukkan jumlah alat baru: ");
            scanf("%d", &alat.jumlah);
            alat.tersedia = alat.jumlah; 
            fprintf(temp, "%d|%s|%s|%s|%d|%d|%d\n", alat.id, alat.nama, alat.model, alat.merk, alat.tahun, alat.jumlah, alat.tersedia);
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


    fprintf(file, "%d|%s|%s|%s|%d|%d|%d\n", alat.id, alat.nama, alat.model, alat.merk, alat.tahun, alat.jumlah, alat.tersedia);
    fclose(file);
}
