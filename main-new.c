#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int menuDatabase();
int menuKasir();
int main();

    struct item{
        char id[5];
        char nama[30];
        char kategori[10];
        int harga;
        int kuan;
    };

    struct item produk[100] = {
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

    int length = sizeof produk / sizeof produk[0];

    int keranjang[2][10];
    int z = 0;

int validasiIsi(char inputChar[]){
    if(inputChar[0] == '\0'){
        printf("Tidak boleh kosong!\n");
        return 0;
    }
    return 1;
}

int validasiInteger(char inputChar[], int *outputInteger){
    if(strlen(inputChar) == 0) {
        printf("Input tidak boleh kosong!\n");
        } else if (strspn(inputChar, "0123456789") != strlen(inputChar)){
    printf("Input hanya berupa angka saja.\n");
    } else {
        *outputInteger = atoi(inputChar);
        return 1;
    }
    return 0;
}

    int tambahkeranjang(){
        int k = 0;
        char cari[5];
        int input, j;

        printf("\nMasukkan ID Produk: ");
        scanf(" %4[^\n]", cari);

        for(int i = 0; i < length; i++){
            if(strcmp(cari,produk[i].id) == 0){
                printf("Masukkan Jumlah: ");
                scanf("%d", &j);
                while (getchar() != '\n'); 
                if(produk[i].kuan >= j){
                    keranjang[0][z] = i;
                    keranjang[1][z] = j;
                z++;
                k++;
                printf("Produk berhasil dimasukkan ke keranjang!\n");
                break;
                } else {
                printf("Stok tidak cukup.. Tekan Enter untuk Kembali...");
                while (getchar() != '\n'); 
                getchar();
                menuKasir();
                };
            };   
        };

            if(k == 0){
                printf("Item tidak ditemukan... Tekan Enter untuk Kembali...");
                while (getchar() != '\n'); 
                getchar();
                menuKasir();
            };

        printf("Mau Memasukkan lagi? (1 - Ya / 0 - Tidak) : ");
        scanf("%d", &input);
        switch(input){
            case 0:
            menuKasir();
            break;
            case 1:
            tambahkeranjang();
            break;
            default:
            printf("Angka yang anda masukkan salah. Tekan Enter untuk kembali ke menu...");
            while (getchar() != '\n'); 
            getchar();
            menuKasir();
            break;
        };

        return 0;
    };

int beli(){
    int input;
    printf("====================================== KERANJANG ANDA ======================================\n");
    printf("| %-5s | %-30s | %-15s | %-7s | %-12s |\n", "Kode", "Nama Produk", "Harga Satuan", "Jumlah", "Total");
    printf("--------------------------------------------------------------------------------------------\n");
    
    for(int i = 0; i < 10; i++){
        if(keranjang[0][i] != -1){
            int idx = keranjang[0][i];
            printf("| %-5s | %-30s | Rp %-12d | %-7d | Rp %-9d |\n", 
                   produk[idx].id, produk[idx].nama, produk[idx].harga, keranjang[1][i], produk[idx].harga * keranjang[1][i]);
        }
    }
    printf("============================================================================================\n");
    printf("0 - Kembali\n1 - Konfirmasi Beli\nPilih : ");
    scanf("%d", &input);
    while (getchar() != '\n');

    switch(input){
        case 0:
            break;

        case 1:
            printf("Yakin Beli? (1 - Ya / 0 - Tidak): ");
            scanf("%d", &input);
            while (getchar() != '\n');
            
            if(input == 1){
                for(int i = 0; i < 10; i++){
                    if(keranjang[0][i] != -1){
                        produk[keranjang[0][i]].kuan -= keranjang[1][i];
                        keranjang[0][i] = -1;
                        keranjang[1][i] = 0;
                    }
                }
                z = 0;
                printf("Pembelian Berhasil! Tekan Enter untuk kembali...");
                getchar();
            }
            break;
            
        default:
            printf("Pilihan tidak sesuai. Tekan Enter untuk kembali...\n");
            getchar();
            break;
    }
    return 0;
}   

 void tampilkategori(char x[10]){
    printf("====================================== KOPERASI DESA ======================================\n");
    printf("| Kode  | Nama Produk                    | Kategori | Harga     | Jumlah Stok  |\n");
    for(int i = 0; i < length; i++){
        if(produk[i].id[0] != '\0' && strcmp(produk[i].kategori, x) == 0){
            printf("| %-5s | %-30s | %-8s | Rp %-6d | %-12d |\n", produk[i].id, produk[i].nama, produk[i].kategori, produk[i].harga, produk[i].kuan);
        }
    }
    printf("========================================================================================\n\n");
    printf("Tekan Enter untuk kembali...");
    getchar();
}

int tampilbarang(){
    int input;
    char cek[10];
    printf("\n1 - Lihat Semua\n");
    printf("2 - Lihat Berdasarkan Kategori\n");
    printf("0 - Kembali Ke Menu Utama\n");
    printf("Pilih (0-2) : ");
    scanf("%d", &input);
    while (getchar() != '\n');

    switch(input){
        case 1:
            printf("====================================== KOPDES DESA ======================================\n");
            printf("| Kode  | Nama Produk                    | Kategori \t| Harga     | Jumlah Stok  |\n");
            for(int i = 0; i < length; i++){
                if(produk[i].id[0] != '\0'){
                    printf("| %-5s | %-30s | %-8s | Rp %-6d \t| %-12d |\n", produk[i].id, produk[i].nama, produk[i].kategori, produk[i].harga, produk[i].kuan);
                }
            }
            printf("========================================================================================\n");
            printf("Tekan Enter untuk kembali...");
            getchar();
            system("cls");
            break;

        case 2:
            printf("\n1 - Komoditas\n");
            printf("2 - Minuman\n");
            printf("3 - Snack\n");
            printf("0 - Kembali\n");
            printf("Pilih (0-3) : ");
            scanf("%d", &input);
            while (getchar() != '\n');
            
            switch(input){
                case 1: tampilkategori("Komoditas"); break;
                case 2: tampilkategori("Minuman"); break;
                case 3: tampilkategori("Snack"); break;
                default: break;
            }
            system("cls");
            break;

        default:
            break;
    }
    return 0; 
}

/* Fungsi Database */
int tambahBarang(){
    char kode[10], nama[50], kategori[20], hargaChar[10], kuanChar[10], pilihanChar[10];
    int validasi = 0, hargaInt, kuanInt, pilihanInt, ditemukan = 0;
    do
    {   
        do
        {
            do
            {
                printf("Masukkan Kode : ");
                fgets(kode, sizeof(kode), stdin);
                kode[strcspn(kode, "\n")] = '\0';
                if(!validasiIsi(kode)){
                    break;
                }
            } while (!validasiIsi(kode));
            do
            {
                printf("Masukkan Nama : ");
                fgets(nama, sizeof(nama), stdin);
                nama[strcspn(nama, "\n")] = '\0';
                if(!validasiIsi(nama)){
                    break;
                }
            } while (!validasiIsi(nama));
            do
            {
                printf("Masukkan Kategori : ");
                fgets(kategori, sizeof(kategori), stdin);
                kategori[strcspn(kategori, "\n")] = '\0';
                if (!validasiIsi(kategori)){
                    break;
                }
            } while (!validasiIsi(kategori));
            do
            {
                printf("Masukkan Harga Barang : ");
                fgets(hargaChar, sizeof(hargaChar), stdin);
                hargaChar[strcspn(hargaChar, "\n")] = '\0';
            } while (!validasiInteger(hargaChar, &hargaInt));
            do
            {
                printf("Masukkan Stok Barang : ");
                fgets(kuanChar, sizeof(kuanChar), stdin);
                kuanChar[strcspn(kuanChar, "\n")] = '\0';
            } while (!validasiInteger(kuanChar, &kuanInt));
            system("cls");
            printf("Silahkan Cek ulang data yang anda isi :\n");
            printf("====================================== BARANG ======================================\n");
            printf("| Kode  | Nama Produk                    | Kategori | Harga     | Jumlah Stok  |\n");
            printf("| %-5s | %-30s | %-8s | Rp %-6d \t| %-12d |\n", kode, nama, kategori, hargaInt, kuanInt);
            printf("====================================================================================\n");
            do
            {
                printf("Apakah kamu ingin melanjutkan?\n");
                printf("1 Ya / 0 Tidak\n");
                printf("Pilihanmu : ");
                fgets(pilihanChar, sizeof(pilihanChar), stdin);
                pilihanChar[strcspn(pilihanChar, "\n")] = '\0';
            } while (!validasiInteger(pilihanChar, &pilihanInt));
            system("cls");
        } while (pilihanInt != 1); 

        for (int i = 0; i < length; i++)
        {
            if (produk[i].id[0] == '\0'){
                strcpy(produk[i].id, kode);
                strcpy(produk[i].nama, nama);
                strcpy(produk[i].kategori, kategori);
                produk[i].harga = hargaInt;
                produk[i].kuan = kuanInt;
                ditemukan = 1;
                printf("Input sukses\n");
                break;
            }
        }
        if (!ditemukan){
            system("cls");
            printf("Penyimpanan sudah penuh, kembali ke menu utama\n");
            return 0;
        }
        do
        {
            do
            {
                printf("Apakah kamu ingin menginput barang lagi?\n");
                printf("1 Ya / 0 Tidak\n");
                printf("Pilihanmu : ");
                fgets(pilihanChar, sizeof(pilihanChar), stdin);
                pilihanChar[strcspn(pilihanChar, "\n")] = '\0';
            } while (!validasiInteger(pilihanChar, &pilihanInt));
            switch (pilihanInt)
            {
            case 1:
                validasi = 1;
                system("cls");
                printf("Mengulang penginputan barang\n");
                break;
            case 0:
                validasi = 1;
                system("cls");
                printf("Kembali ke menu database\n");
                break;
            default:
                validasi = 0;
                printf("Tidak ada pilihan seperti itu!\n");
                break;
            }
        } while (validasi != 1);
    } while (pilihanInt != 0);
    
}

int hapusBarang(){
    char pilihanChar[10], kode[10];
    int pilihanInt, validasi = 0, ditemukan = 0, index = -1;
    do
    {   
        do
        {
            printf("Menu penghapusan barang\n");
            do
            {
                printf("Silahkan cari kode barang (Contoh: T001) : ");
                fgets(kode, sizeof(kode), stdin);
                kode[strcspn(kode, "\n")] = '\0';
            } while (!validasiIsi(kode));
            for (int i = 0; i < length; i++)
            {
                if (strcmp(produk[i].id, kode) == 0){
                printf("============================= BARANG DITEMUKAN =====================================\n");
                printf("| Kode  | Nama Produk                    | Kategori | Harga     | Jumlah Stok  |\n");
                printf("| %-5s | %-30s | %-8s | Rp %-6d \t| %-12d |\n", produk[i].id, produk[i].nama, produk[i].kategori, produk[i].harga, produk[i].kuan);
                printf("====================================================================================\n");
                ditemukan = 1;
                index = i;
                }
            }
            do
            {
                printf("Apakah kamu ingin menghapus data ini?\n");
                printf("1 Ya / 0 Tidak\n");
                printf("Pilihanmu : ");
                fgets(pilihanChar, sizeof(pilihanChar), stdin);
                pilihanChar[strcspn(pilihanChar, "\n")] = '\0';
            } while (!validasiInteger(pilihanChar, &pilihanInt));
        } while (pilihanInt != 1);
        for(int i=index; i<length-1; i++) {
            produk[i] = produk[i+1];
        }
        length--;
        printf("Barang berhasil di hapus!\n");
        validasi = 0;
        do
        {
            do
            {
                printf("Apakah kamu ingin menghapus barang lagi?\n");
                printf("1 Ya / 0 Tidak\n");
                printf("Pilihanmu : ");
                fgets(pilihanChar, sizeof(pilihanChar), stdin);
                pilihanChar[strcspn(pilihanChar, "\n")] = '\0';
            } while (!validasiInteger(pilihanChar, &pilihanInt));
            switch (pilihanInt)
            {
            case 1:
                validasi = 1;
                system("cls");
                printf("Melakukan penghapusan barang lagi...\n");
                break;
            case 0:
                validasi = 1;
                system("cls");
                printf("Kembali ke menu database\n");
                break;
            default:
                validasi = 0;
                system("cls");
                printf("Tidak ada pilihan tersebut!\n");
                break;
            }
        } while (validasi != 1);
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
        case 2:
            system("cls");
            hapusBarang();
            break;
        case 3:
            system("cls");
            tampilbarang();
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
    int input;
    do {
        system("cls");
        printf("Selamat datang di menu kasir\n");
        printf("1 - Tambahkan Keranjang\n");
        printf("2 - Lihat dan Konfirmasi Beli\n");
        printf("99 - Kembali Ke Menu Utama\n");
        printf("Pilih : ");
        scanf("%d", &input);
        while (getchar() != '\n');

        switch(input){
            case 1:
                tambahkeranjang();
                break;
            
            case 2:
                beli();
                break;

            case 99:
                printf("Kembali ke menu utama . . . \n");
                break;

            default:
                printf("ERROR: Angka tidak sesuai. Tekan Enter untuk Coba lagi...");
                getchar();
                break;
        }
    } while (input != 99); 
    
    return 0;
}

int main() {
    int pilihanInt = 0;
    int validasi = 0;
    char pilihanChar[10];
    system("cls");

    for(int i = 0; i < 10; i++){
        keranjang[0][i] = -1;
        keranjang[1][i] = 0;
    };

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
        case 1:
            system("cls");
            menuKasir();
            break;
        case 2:
            system("cls");
            menuDatabase();
            break;
        case 99:
            system("cls");
            printf("Keluar dari program, tekan enter untuk melanjutkan \n");
            getchar();
            exit(0);
            break;
        default:
            system("cls");
            printf("Pilihan Invalid\n");
            break;
        }  
    } while (pilihanInt != 99);
    
}