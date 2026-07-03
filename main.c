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

int validasiIsi(char inputChar[], int validasi){
    if(inputChar[0] == '\0'){
        validasi = 0;
        printf("Tidak boleh kosong!\n");
        return 0;
    }
    validasi = 1;
    return 1;
}

int validasiInteger(int *outputInteger, char inputChar[], int validasi){
    char *endptr;

    *outputInteger = strtol(inputChar, &endptr, 10);

    // Jika masih ada karakter selain newline atau null, input tidak valid
    if (*endptr != '\n' && *endptr != '\0') {
        validasi = 0;
        return 0;
    }
    validasi = 1;
    return 1;
}

int tambahBarang(){
    int validasi = 0;
    char pilihanChar[10], hargaChar[50], stokChar[20], kode[10], nama[100], kategori[20], pilihanChar[10];
    int pilihanInt, hargaInt, stokInt, pilihanInt;
    FILE *file;

    file = fopen("/data/barang.csv", "r");
    if (file == NULL) {
        printf("File tidak dapat ditemukan, kembali ke menu utama\n");
        return 0;
    } else {
        printf("File berhasil dibuka\n");
        fclose(file);
    }
    do {
        printf("Selamat datang di menu tambah barang\n");
        printf("Silahkan pilih : \n");
        printf("1. Tambah barang\n");
        printf("99. Kembali ke menu utama\n");
        printf("Pilihanmu : ");
        fgets(pilihanChar, sizeof(pilihanChar), stdin);
        pilihanInt = atoi(pilihanChar);
        switch (pilihanInt)
        {
            case 1:
                do {

                    system("cls");
                    printf("Silahkan input barang\n");
                    do {
                        printf("Masukkan kode barang (Contoh : T001): ");
                        fgets(kode, sizeof(kode), stdin);
                        if (validasiIsi(kode, validasi)){
                            break;
                        }
                    } while(validasi != 1);
                    do {
                        printf("Masukkan nama barang : ");
                        fgets(nama, sizeof(nama), stdin);
                        if (validasiIsi(nama, validasi)){
                            break;
                        }
                    } while (validasi != 1);
                    do {
                        printf("Masukkan kategori barang (Contoh : Beras 5 KG): ");
                        fgets(kategori, sizeof(kategori), stdin);
                        if (validasiIsi(kategori, validasi)){
                            break;
                        }
                    } while (validasi != 1);
                    do  {
                        printf("Masukkan harga barang (HANYA DALAM ANGKA SAJA) (Contoh : 10000): ");
                        fgets(hargaChar, sizeof(hargaChar), stdin);
                        if (validasiInteger(hargaChar, &hargaInt, validasi)){
                            break;
                        }
                    } while(validasi != 1);
                    do {
                        printf("Masukkan jumlah stok barang : ");
                        fgets(stokChar, sizeof(stokChar), stdin);
                        if (validasiInteger(stokChar, &stokInt, validasi)){
                            break;
                        }
                    } while (validasi != 1);
                    validasi = 0;
                    do
                    {
                        printf("Apakah input sudah valid?\n");
                        printf("1 - Ya\n");
                        printf("0 - Tidak, ulangi lagi\n");
                        print("Pilihanmu : ");
                        fgets(pilihanChar, sizeof(pilihanChar), stdin);
                        if(validasiInteger(pilihanChar, &pilihanInt, validasi)){
                            break;
                        }
                    } while (validasi != 1);
                    file = fopen("/data/barang.csv", "a");
                    if (file == NULL) {
                        printf("File tidak dapat dibuka, kembali ke menu utama\n");
                        return 0;
                    } else {
                        fprintf(file, "%s,%s,%s,%d,%d\n", kode, nama, kategori, hargaInt, stokInt);
                        fclose(file);
                        printf("Barang berhasil ditambahkan\n");
                    }
                    printf("Apakah mau menambah barang lagi?\n");
                    printf("1 - Ya\n");
                    printf("0 - Tidak, ulangi lagi\n");
                    print("Pilihanmu : ");
                } while (validasi != 1);

                break;
            case 99:
                printf("Kembali ke menu utama\n");
                break;
            default:
                printf("Pilihan Invalid\n");
                break;
        }
    } while (pilihanInt != 99);

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