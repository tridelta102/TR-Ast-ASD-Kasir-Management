#include <stdio.h>
#include <stdlib.h>
#include <string.h>

    struct item{
        char id[5];
        char nama[30];
        char kategori[10];
        int harga;
        int kuan;
    };

    /* tambahi lagi/ganti dong produknya -teo*/
    /* Buat datanya mending di csv aja, biar bisa diedit, tambah atau hapus*/
    struct item produk[20] = {
        {"T001", "Beras 5 Kg", "Komoditas", 80000, 5},
        {"T002", "Telur 1 Lusin", "Komoditas", 20000, 8},
        {"T003", "Air Putih 1 Liter", "Minuman", 10000, 10},
        {"T004", "Tepung Terigu 1 Kg", "Komoditas", 12000, 10},
        {"T005", "Gula 1 Kg", "Komoditas", 20000, 10},
        {"T006", "Teh Botolan 300ml", "Minuman", 3000, 20},
        {"T007", "Roti Tawar", "Komoditas", 20000, 10},
        {"T008", "Minyak Sawit 1 Liter", "Komoditas", 14000, 15},
        {"T009", "Mi Instan", "Komoditas", 3000, 20},
        {"T010", "Kopi 200gr", "Komoditas", 20000, 15},
        {"T011", "Keripik Kentang", "Snack", 5000, 16},
        {"T012", "Garam", "Komoditas", 3000, 12},
        {"T013", "Masako", "Komoditas", 1000, 100}
    };

int validasiIsi(char inputChar[]){
    if(inputChar[0] == '\0'){
        printf("Tidak boleh kosong!\n");
        return 0;
    }
    return 1;
}

int validasiInteger(char inputChar[], int *outputInteger){
    char *endptr;
    *outputInteger = strtol(inputChar, &endptr, 10);
    if (*endptr != '\n' && *endptr != '\0') {
        printf("Input harus berupa angka!\n");
        return 0;
    }
    return 1;
}

int tambahBarang(){
    char pilihanChar[10], hargaChar[50], stokChar[20], kode[10], nama[100], kategori[20];
    int pilihanInt = 0, hargaInt = 0, stokInt = 0, validasi = 0;
    FILE *file;
    do  {
        do
        {   
            do
            {
                printf("Selamat datang di menu tambah barang\n");
                printf("Masukkan kode barang (maks 4 karakter): ");
                fgets(kode, sizeof(kode), stdin);
                kode[strcspn(kode, "\n")] = 0;
                if (!validasiIsi(kode)){
                    break;
                }
            } while (!validasiIsi(kode));
            do
            {
                printf("Masukkan nama barang (maks 30 karakter): ");
                fgets(nama, sizeof(nama), stdin);
                nama[strcspn(nama, "\n")] = 0;
                if(!validasiIsi(nama)){
                    break;
                }
            } while (!validasiIsi(nama));
            do
            {
                printf("Masukkan kategori barang (maks 10 karakter)\n");
                printf("Kategori yang tersedia: Komoditas, Minuman, Snack\n");
                printf(": ");
                fgets(kategori, sizeof(kategori), stdin);
                kategori[strcspn(kategori, "\n")] = 0;
                if(!validasiIsi(kategori)){
                    break;
                }
            } while (!validasiIsi(kategori));
            do  {
                printf("Masukkan harga barang: ");
                fgets(hargaChar, sizeof(hargaChar), stdin);
                hargaChar[strcspn(hargaChar, "\n")] = 0;
                if (!validasiInteger(hargaChar, &hargaInt)) {
                    printf("Input harga tidak valid. Silakan masukkan angka.\n");
                }
            } while (!validasiInteger(hargaChar, &hargaInt));
            do  {
                printf("Masukkan stok barang: ");
                fgets(stokChar, sizeof(stokChar), stdin);
                stokChar[strcspn(stokChar, "\n")] = 0;
                if (!validasiInteger(stokChar, &stokInt)) {
                    printf("Input stok tidak valid. Silakan masukkan angka.\n");
                }
            } while (!validasiInteger(stokChar, &stokInt));
            printf("Pastikan input data sudah benar\n");
            printf("Apakah anda ingin mengulang input data? (1. Ya / 0. Tidak) : ");
            fgets(pilihanChar, sizeof(pilihanChar), stdin);
            pilihanChar[strcspn(pilihanChar, "\n")] = 0;
            pilihanInt = atoi(pilihanChar);
            switch (pilihanInt)
            {
            case 1:
                printf("Mengulang penginputan data\n");
                break;
            case 0:
                system("cls");
                printf("Menginput data\n");
                break;            
            default:
                printf("Pilihan tidak valid!\n");
                break;
            }   
        } while (pilihanInt != 0);
        file = fopen("data/barang.csv", "a");
        fprintf(file, "%s,%s,%s,%d,%d\n", kode, nama, kategori, hargaInt, stokInt);
        fclose(file);
        printf("Data berhasil ditambahkan ke database\n");
        printf("Apakah anda ingin mengulang input data?\n");
        printf("1. Ya\n");
        printf("0. Tidak\n");
        printf("Pilihanmu : ");
        fgets(pilihanChar, sizeof(pilihanChar), stdin);
        pilihanChar[strcspn(pilihanChar, "\n")] = 0;
            switch (pilihanInt)
            {
            case 1:
                system("cls");
                break;
            case 0:
                system("cls");
                printf("Kembali ke menu utama\n");
                break;            
            default:
                printf("Pilihan tidak valid!\n");
                break;
            }
    } while (pilihanInt != 0);
}

int menuDatabase(){
    int pilihanInt;
    char pilihanChar[10];
    int validasi = 0;
    do
    {
        printf("Selamat datang di menu database\n");
        printf("Silahkan pilih : \n");
        printf("1. Tambah barang\n");
        printf("2. Hapus barang\n");
        printf("3. Tampilkan barang\n");
        printf("99. Kembali ke menu utama\n");
        printf("Pilihanmu : ");
        fgets(pilihanChar, sizeof(pilihanChar), stdin);
        pilihanInt = atoi(pilihanChar);
        switch (pilihanInt)
        {
        case 1:
            system("cls");
            tambahBarang();
            break;
        case 99:
            system("cls");
            printf("Kembali ke menu utama . . . \n");
            break;
        default:
            system("cls");
            printf("Pilihan Invalid\n");
            break;
        }
        } while (pilihanInt != 99);
}

int menuKasir(){
    printf("Selamat datang di menu kasir\n");
    printf("");
}
int main() {
    int pilihanInt = 0;
    int validasi = 0;
    char pilihanChar[10];
    system("cls");
    FILE *file;

    file = fopen("data/barang.csv", "r");
    if (file == NULL) {
        printf("File tidak dapat dibuka, kembali ke menu utama\n");
        exit(1);
    }
    fclose(file);
    fopen("data/barang.csv", "a");
    fseek(file, 0, SEEK_END);
    long size = ftell(file);
    if (size == 0){
        fprintf(file, "Kode,Nama,Kategori,Harga,Stok\n");
        for (int i = 0; i < 13; i++) {
            fprintf(file, "%s,%s,%s,%d,%d\n", produk[i].id, produk[i].nama, produk[i].kategori, produk[i].harga, produk[i].kuan);
        }
    }   
    fclose(file);
    do
    {
        printf("Selamat datang di sistem supermarket!\n");
        printf("Silahkan pilih yang ingin anda lakukan:\n");
        printf("1. Masuk menu kasir\n");
        printf("2. Cek database\n");
        printf("99. Keluar\n");
        printf("Pilihan anda : ");
        fgets(pilihanChar, sizeof(pilihanChar), stdin);
        pilihanInt = atoi(pilihanChar);
        switch (pilihanInt)
        {
        case 2:
            system("cls");
            menuDatabase();
            break;
        case 99:
            system("cls");
            printf("Keluar dari program, tekan enter untuk melanjutkan \n");
            getchar();
            break;
        default:
            system("cls");
            printf("Pilihan Invalid\n");
            break;
        }  
    } while (pilihanInt != 99);
    
}