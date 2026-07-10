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
    char *endptr;
    *outputInteger = strtol(inputChar, &endptr, 10);
    if (*endptr != '\n' && *endptr != '\0') {
        printf("Input harus berupa angka!\n");
        return 0;
    }
    return 1;
}

    int tambahkeranjang(){
        int k = 0;
        char cari[5];
        int input, j;

        printf("\nMasukkan ID Produk: ");
        scanf(" %[^\n]", cari);

        for(int i = 0; i < length; i++){
            if(strcmp(cari,produk[i].id) == 0){
                printf("Masukkan Jumlah: ");
                scanf("%d", &j);
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
        printf("| Kode\t| Nama Produk                    | Harga Satuan\t\t| Jumlah \t| Total\t|\n");
        for(int i = 0; i < 10; i++){
            if(keranjang[0][i] != 0){
            printf("| %-5s | %-30s | Rp %d\t\t| %d\t| Rp %d\t|\n", produk[keranjang[0][i]].id, produk[keranjang[0][i]].nama, produk[keranjang[0][i]].harga, keranjang[1][i], produk[keranjang[0][i]].harga*keranjang[1][i]);
            };
        };
        printf("============================================================================================\n");
        printf("0 - Kembali\n1 - Konfirmasi Beli\nPilih : ");
        scanf("%d", &input);
        switch(input){
            case 0:
            menuKasir();
            break;

            case 1:
            printf("Yakin Beli? (1 - Ya / 0 - Tidak): ");
            scanf("%d", &input);
                switch(input){
                    case 0:
                    menuKasir();
                    break;

                    case 1:
                    for(int i = 0; i < 10; i++){
                        if(keranjang[0][i] != 0){
                            produk[keranjang[0][i]].kuan -= keranjang[1][i];
                            keranjang[0][i] = 0;
                            keranjang[1][i] = 0;
                        };
                    };

                    printf("Pembelian Berhasil! Tekan Enter untuk kembali...");
                        while (getchar() != '\n'); 
                        getchar();
                        menuKasir();
                    break;
                    
                    default:
                        printf("ERROR: Angka yang anda masukkan tidak sesuai. Tekan Enter untuk Coba lagi...");
                        while (getchar() != '\n'); 
                        getchar();
                        beli();
                        break;
                }
            break;

            default:
                printf("ERROR: Angka yang anda masukkan tidak sesuai. Tekan Enter untuk Coba lagi...");
                while (getchar() != '\n'); 
                getchar();
                beli();
                break;
        }
        return 0;
    }

    void tampilkategori(char x[10]){
        printf("====================================== KOPERASI DESA ======================================\n");
        printf("| Kode\t| Nama Produk                    | Kategori\t| Harga\t\t| Jumlah Stok \t|\n");
        for(int i = 0; i < length; i++){
            if(produk[i].id[0] != '\0' && strcmp(produk[i].kategori, x) == 0){
            printf("| %-5s | %-30s | %s\t| Rp %d\t| %d\t\t|\n", produk[i].id, produk[i].nama, produk[i].kategori, produk[i].harga, produk[i].kuan);
            };
        };
        printf("========================================================================================\n\n");
         printf("Tekan Enter untuk kembali ke menu...");
        while (getchar() != '\n'); 
        getchar();
    };

int tampilbarang(){
    int input;
    char cek[10];
    printf("\n1 - Lihat Semua\n");
    printf("2 - Lihat Berdasarkan Kategori\n");
    printf("0 - Kembali Ke Menu Utama\n");
    printf("Pilih (0-1) : ");
    scanf("%d", &input);

    
    switch(input){
        case 1:
            printf("====================================== KOPDES DESA ======================================\n");
            printf("| Kode\t| Nama Produk                    | Kategori\t| Harga\t\t| Jumlah Stok \t|\n");
            for(int i = 0; i < length; i++){
                if(produk[i].id[0] != '\0'){
                printf("| %-5s | %-30s | %s\t| Rp %d\t| %d\t\t|\n", produk[i].id, produk[i].nama, produk[i].kategori, produk[i].harga, produk[i].kuan);
                };
            };
            printf("========================================================================================\n");
            printf("Tekan Enter untuk kembali ke menu...");
            while (getchar() != '\n'); 
            getchar();
            system("cls");
            menuDatabase();
            break;

        case 2:
                printf("\n1 - Komoditas\n");
                printf("2 - Minuman\n");
                printf("3 - Snack\n");
                printf("0 - Kembali\n");
                printf("Pilih (0-3) : ");
                scanf("%d", &input);
                
                switch(input){
                    case 1:
                    strcpy(cek, "Komoditas");
                    tampilkategori(cek);
                    menuDatabase();
                    break;

                    case 2:
                    strcpy(cek, "Minuman");
                    tampilkategori(cek);
                    menuDatabase();
                    break;

                    case 3:
                    strcpy(cek, "Snack");
                    tampilkategori(cek);
                    menuDatabase();
                    break;

                    case 0:
                    menuDatabase();
                    break;

                    default:
                    printf("ERROR: Angka yang anda masukkan tidak sesuai. Tekan Enter untuk Coba lagi...");
                    while (getchar() != '\n'); 
                    getchar();
                    tampilbarang();
                    break;
                };
                break;

                case 0:
                    menuDatabase();
                    break;

                default:
                    printf("ERROR: Angka yang anda masukkan tidak sesuai. Tekan Enter untuk Coba lagi...");
                    while (getchar() != '\n'); 
                    getchar();
                    tampilbarang();
                    break;
        };
        return 0;
};

int tambahBarang(){
    char pilihanChar[10], hargaChar[50], stokChar[20], kode[10], nama[100], kategori[20];
    int pilihanInt = 0, hargaInt = 0, stokInt = 0, validasi = 0;
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

        for(int i = 0; i < length; i++){
            if(produk[i].id[0] == '\0'){
                strcpy(produk[i].id, kode);
                strcpy(produk[i].nama, nama);
                strcpy(produk[i].kategori, kategori);
                produk[i].harga = hargaInt;
                produk[i].kuan = stokInt;
                break;
            };
        };

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
    system("cls");
    printf("Selamat datang di menu kasir\n");
    int input;
    char cek[10];
    printf("1 - Tambahkan Keranjang\n");
    printf("2 - Lihat dan Konfirmasi Beli\n");
    printf("0 - Kembali Ke Menu Utama\n");
    printf("Pilih (0-1) : ");
    scanf("%d", &input);

    switch(input){
        case 1:
        tambahkeranjang();
        break;
        
        case 2:
        beli();
        break;

        case 0:
        main();
        break;

        default:
            printf("ERROR: Angka yang anda masukkan tidak sesuai. Tekan Enter untuk Coba lagi...");
            while (getchar() != '\n'); 
            getchar();
            menuKasir();
        break;
    };
};

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