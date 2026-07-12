#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <time.h>

int menuDatabase();
int menuKasir();
void cetakStruk();
int main();
void tampilkanLoading();
void tampilkanLogin(char *usernameLolos);
void tampilkanWelcome(char *username);
void tampilkanAnggota();
void bunyiBeep();
void bunyiError();

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


void bunyiBeep() {
    Beep(1000, 250);
}

void bunyiError() {
    Beep(400, 600); 
}

void tampilkanLoading() {
    system("cls");
    printf("\n\n\n\n\n\n\n");
    printf("                  SELAMAT DATANG DI SISTEM KOPERASI DESA\n\n");
    
    for (int i = 0; i <= 100; i += 5) {
        printf("                                Loading : %d%%\n\n", i);
        
        printf("                  ==========================================\n"); 
        
        printf("                  |"); 
        int barWidth = i / 2.5; 
        for (int j = 0; j < 40; j++) {
            if (j < barWidth) printf("%c", 219); 
            else printf(" ");
        }
        printf("|\n"); 
        
        printf("                  =========================================="); 
        
        if(i % 20 == 0) Beep(1000, 20); 
        Sleep(70); 
        
        if(i < 100) {
            printf("\r\033[4A"); 
        } else {
            printf("\n");
        }
    }
    bunyiBeep(); 
    Sleep(500);
}

void tampilkanLogin(char *usernameLolos) {
    char password[50];
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    char timeStr[50];
    strftime(timeStr, sizeof(timeStr), "%a %b %d %H:%M:%S %Y", &tm);
    
    int loginSukses = 0;

    do {
        system("cls");
        printf("\n\n\n");
        printf("          ============================================================\n");
        printf("                                  MENU LOGIN                          \n");
        printf("          ============================================================\n");
        printf("                             SISTEM KOPERASI DESA                     \n");
        printf("          ============================================================\n\n\n");
        
        printf("                      USERNAME : ");
        scanf("%s", usernameLolos);
        while (getchar() != '\n'); 
        bunyiBeep();
        
        printf("                      PASSWORD : ");
        scanf("%s", password); 
        while (getchar() != '\n'); 
        
        if ((strcmp(usernameLolos, "Kenji") == 0 && strcmp(password, "672025046") == 0) ||
            (strcmp(usernameLolos, "Hans") == 0 && strcmp(password, "672025047") == 0) ||
            (strcmp(usernameLolos, "Theo") == 0 && strcmp(password, "672025093") == 0) ||
            (strcmp(usernameLolos, "Nathan") == 0 && strcmp(password, "672025101") == 0)) {
            
            bunyiBeep();
            loginSukses = 1; 
        } else {
            bunyiError();
            printf("\n                      [!] USERNAME ATAU PASSWORD SALAH! Silakan coba lagi.\n");
            Sleep(1500); 
        }

} while (loginSukses == 0);

    printf("\n\n");
    printf("          ============================================================\n");
    printf("           SISTEM KOPERASI DESA          %s\n", timeStr);
    printf("          ============================================================\n");
    
    Sleep(800);
}

void tampilkanWelcome(char *username) {
    system("cls");
    printf("\n\n\n\n\n\n\n\n\n\n");
    printf("                             Selamat datang, %s!\n", username);
    bunyiBeep();
    Sleep(1500);
}

void tampilkanAnggota() {
    system("cls");
    printf("\n\n");
    printf("      =====================================\n");
    printf("                Anggota Kelompok 1\n");
    printf("      =====================================\n");
    printf("      Nama    : Kenzie Sebastian Timothy\n");
    printf("      NIM     : 672025046\n");
    printf("      =====================================\n");
    printf("      Nama    : Elia Hans Hayudyo Purwanto\n");
    printf("      NIM     : 672025047\n");
    printf("      =====================================\n");
    printf("      Nama    : Teofilus Tri A M\n");
    printf("      NIM     : 672025093\n");
    printf("      =====================================\n");
    printf("      Nama    : Nathanael Affarel P\n");
    printf("      NIM     : 672025101\n");
    printf("      =====================================\n\n");
    printf("      Tekan Enter untuk kembali...");
    getchar();
    bunyiBeep();
}

int validasiIsi(char inputChar[]){
    if(inputChar[0] == '\0'){
        bunyiError();
        system("cls");
        printf("Tidak boleh kosong!\n");
        return 0;
    }
    return 1;
}

int validasiInteger(char inputChar[], int *outputInteger){
    if(strlen(inputChar) == 0) {
        bunyiError();
        system("cls");
        printf("Input tidak boleh kosong!\n");
    } else if (strspn(inputChar, "0123456789") != strlen(inputChar)){
        bunyiError();
        system("cls");
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
    int input, j, l, p = 0;

    //keranjang[0] menyimpan index (i)
    //keranjang[1] menyimpan jumlah

    printf("\nMasukkan ID Produk: ");
    scanf(" %4[^\n]", cari);
    bunyiBeep();

    for(int i = 0; i < length; i++){
        if(strcmp(cari,produk[i].id) == 0){

            printf("Masukkan Jumlah: ");
            scanf("%d", &j);
            while (getchar() != '\n'); 
            
            for(int x = 0; x <= z; x++){
                if(i == keranjang[0][x]){
                    l = keranjang[1][x] + j;
                    if(produk[i].kuan < l){
                        bunyiError();
                        printf("Stok tidak cukup.. Tekan Enter untuk Kembali...");
                        while (getchar() != '\n'); 
                        return 0; 
                    };
                    keranjang[0][x] = i;
                    keranjang[1][x] = l;
                    p++;
                    z++;
                    k++;
                    bunyiBeep();
                    printf("Produk berhasil ditambahkan!\n");
                    break;
                };
            }
            if(p == 0){
                if(produk[i].kuan >= j){
                    keranjang[0][z] = i;
                    keranjang[1][z] = j;
                    z++;
                    k++;
                    bunyiBeep();
                    printf("Produk berhasil dimasukkan ke keranjang!\n");
                    break;
                } else {
                    bunyiError();
                    printf("Stok tidak cukup.. Tekan Enter untuk Kembali...");
                    while (getchar() != '\n'); 
                    return 0; 
                };
            };
        };   
    };

    if(k == 0){
        bunyiError();
        printf("Item tidak ditemukan... Tekan Enter untuk Kembali...");
        while (getchar() != '\n'); 
        getchar();
        return 0; 
    };

    printf("Mau Memasukkan lagi? (1 - Ya / 0 - Tidak) : ");
    scanf("%d", &input);
    bunyiBeep();
    
    switch(input){
        case 0:
            return 0;
            break;
        case 1:
            tambahkeranjang();
            break;
        default:
            bunyiError();
            printf("Angka yang anda masukkan salah. Tekan Enter untuk kembali ke menu...");
            while (getchar() != '\n'); 
            getchar();
            return 0;
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
    bunyiBeep();

    switch(input){
        case 0:
            break;

        case 1:
            printf("Yakin Beli? (1 - Ya / 0 - Tidak): ");
            scanf("%d", &input);
            while (getchar() != '\n');
            bunyiBeep();
            
            if(input == 1){
                cetakStruk();
                for(int i = 0; i < 10; i++){
                    if(keranjang[0][i] != -1){
                        produk[keranjang[0][i]].kuan -= keranjang[1][i];
                        keranjang[0][i] = -1;
                        keranjang[1][i] = 0;
                    }
                }
                z = 0;
            }
            break;
            
        default:
            bunyiError();
            printf("Pilihan tidak sesuai. Tekan Enter untuk kembali...\n");
            getchar();
            break;
    }
    return 0;
} 

void cetakStruk(){
    FILE *fp = fopen("struk.txt", "w");
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    char timeStr[50];
    strftime(timeStr, sizeof(timeStr), "%a %b %d %H:%M:%S %Y", &tm);

    if(fp == NULL){
        bunyiError();
        printf("Gagal membuat file struk!\n");
        return;
    }

    int totalBelanja = 0;

    fprintf(fp, "================ STRUK BELANJA ===============\n");
    fprintf(fp, "%-5s %-25s %-5s %-10s\n", "Kode", "Nama", "Qty", "Total");
    fprintf(fp, "----------------------------------------------\n");

    for(int i = 0; i < z; i++){
        int idx = keranjang[0][i];

        if(idx != -1){
            int subtotal = produk[idx].harga * keranjang[1][i];

            fprintf(fp, "%-5s %-25s %-5d Rp %-8d\n",
                    produk[idx].id,
                    produk[idx].nama,
                    keranjang[1][i],
                    subtotal);

            totalBelanja += subtotal;
        }
    }

    fprintf(fp, "----------------------------------------------\n");
    fprintf(fp, "TOTAL BELANJA : Rp %d\n", totalBelanja);
    fprintf(fp, " %s\n", timeStr);

    fclose(fp);

    bunyiBeep();
    printf("\nPembelian Berhasil!\nStruk berhasil dibuat: struk.txt\n");
    printf("Tekan Enter untuk kembali...");
    getchar();
}

int menuKasir(){
    int input;
    do {
        system("cls");
        printf("\n\n");
        printf("      ||====================================================||\n");
        printf("      ||                   MENU KASIR                       ||\n");
        printf("      ||====================================================||\n");
        printf("      ||                                                    ||\n");
        printf("      ||    1. Tambahkan Keranjang                          ||\n");
        printf("      ||    2. Lihat dan Konfirmasi Beli                    ||\n");
        printf("      ||   99. Kembali Ke Menu Utama                        ||\n");
        printf("      ||                                                    ||\n");
        printf("      ||====================================================||\n");
        printf("      ||    Masukkan Pilihan : ");
        
        scanf("%d", &input);
        while (getchar() != '\n');
        bunyiBeep();

        switch(input){
            case 1:
                tambahkeranjang();
                break;
            case 2:
                beli();
                break;
            case 99:
                printf("      ||    Kembali ke menu utama . . .                     ||\n");
                Sleep(500);
                break;
            default:
                bunyiError();
                printf("      ||    ERROR: Pillihan tidak sesuai. Tekan Enter...    ||\n");
                getchar();
                break;
        }
    } while (input != 99); 
    
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
    bunyiBeep();
}


int tambahBarang(){
    char kode[10], nama[50], kategori[20], hargaChar[10], kuanChar[10], pilihanChar[10];
    int validasi = 0, hargaInt, kuanInt, pilihanInt, ditemukan = 0;
    do
    {   
        do
        {
            do
            {
                do
                {
                    printf("Masukkan Kode : ");
                    fgets(kode, sizeof(kode), stdin);
                    kode[strcspn(kode, "\n")] = '\0';
                } while (!validasiIsi(kode));

                validasi = 1;

                for (int i = 0; i < length; i++)
                {
                    if (strcmp(produk[i].id, kode) == 0)
                    {
                        bunyiError();
                        system("cls");
                        printf("Kode sudah dipakai, Gunakan kode lain.\n");
                        validasi = 0;
                        break;
                    }  
                }
            } while (validasi != 1);
            bunyiBeep();
            system("cls");
            do
            {
                printf("Masukkan Nama : ");
                fgets(nama, sizeof(nama), stdin);
                nama[strcspn(nama, "\n")] = '\0';
            } while (!validasiIsi(nama));
            bunyiBeep();
            system("cls");
            do
            {
                printf("Masukkan Kategori : ");
                fgets(kategori, sizeof(kategori), stdin);
                kategori[strcspn(kategori, "\n")] = '\0';
            } while (!validasiIsi(kategori));
            bunyiBeep();
            system("cls");
            do
            {
                printf("Masukkan Harga Barang : ");
                fgets(hargaChar, sizeof(hargaChar), stdin);
                hargaChar[strcspn(hargaChar, "\n")] = '\0';
            } while (!validasiInteger(hargaChar, &hargaInt));
            bunyiBeep();
            system("cls");
            do
            {
                printf("Masukkan Stok Barang : ");
                fgets(kuanChar, sizeof(kuanChar), stdin);
                kuanChar[strcspn(kuanChar, "\n")] = '\0';
            } while (!validasiInteger(kuanChar, &kuanInt));
            bunyiBeep();
            
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
            bunyiBeep();
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
                bunyiBeep();
                printf("Input sukses\n");
                break;
            }
        }
        if (!ditemukan){
            bunyiError();
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
                ditemukan = 0;
                bunyiBeep();
                system("cls");
                printf("Mengulang penginputan barang\n");
                break;
            case 0:
                validasi = 1;
                bunyiBeep();
                system("cls");
                printf("Kembali ke menu database\n");
                break;
            default:
                validasi = 0;
                bunyiError();
                system("cls");
                printf("Tidak ada pilihan seperti itu!\n");
                break;
            }
        } while (validasi != 1);
    } while (pilihanInt != 0);
    return 0;
}

int hapusBarang(){
    char pilihanChar[10], kode[10];
    int pilihanInt, validasi = 0, index = -1, cobaLagi = 0;
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
            bunyiBeep();
            system("cls");
            for (int i = 0; i < length; i++)
            {
                if (strcmp(produk[i].id, kode) == 0){
                printf("============================= BARANG DITEMUKAN =====================================\n");
                printf("| Kode  | Nama Produk                    | Kategori | Harga     | Jumlah Stok  |\n");
                printf("| %-5s | %-30s | %-8s | Rp %-6d \t| %-12d |\n", produk[i].id, produk[i].nama, produk[i].kategori, produk[i].harga, produk[i].kuan);
                printf("====================================================================================\n");
                index = i;
                }
            }
            if(index == -1){
                    do {
                        printf("Barang tidak ditemukan\n");
                        do {
                            printf("Apakah ingin mencoba lagi?\n");
                            printf("1 Ya / 0 Tidak\n");
                            printf("Pilihanmu : ");
                            fgets(pilihanChar, sizeof(pilihanChar), stdin);
                            pilihanChar[strcspn(pilihanChar, "\n")] = '\0';
                            
                        } while (!validasiInteger(pilihanChar, &pilihanInt));
                        bunyiBeep();
                    switch (pilihanInt)
                    {
                    case 1:
                        system("cls");
                        printf("Mencoba lagi...\n");
                        cobaLagi = 1;
                        break;

                    case 0:
                        system("cls");
                        return 0;

                    default:
                        bunyiError();
                        system("cls");
                        printf("Tidak ada pilihan seperti itu!\n");
                    }

                } while (pilihanInt != 1 && pilihanInt != 0);

                if (cobaLagi)
                    continue;
                } 
            do {
                do
                {
                    printf("Apakah kamu ingin menghapus data ini?\n");
                    printf("1 Ya / 0 Tidak\n");
                    printf("Pilihanmu : ");
                    fgets(pilihanChar, sizeof(pilihanChar), stdin);
                    pilihanChar[strcspn(pilihanChar, "\n")] = '\0';
                } while (!validasiInteger(pilihanChar, &pilihanInt));
                switch (pilihanInt)
                {
                case 1:
                    bunyiBeep();
                    break;
                case 0:
                    bunyiBeep();
                    system("cls");
                    break;
                default:
                    bunyiError();
                    system("cls");
                    printf("Tidak ada pilihan seperti itu!\n");
                    break;
                }
            } while (pilihanInt != 1 && pilihanInt != 0);

        } while (pilihanInt != 1);
        system("cls");
        if (index != -1) {
            for(int i=index; i<length-1; i++) {
                produk[i] = produk[i+1];
            }
            produk[length-1].id[0] = '\0';
            bunyiBeep();
            printf("Barang berhasil di hapus!\n");
        }
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
                bunyiBeep();
                index = -1;
                system("cls");
                printf("Melakukan penghapusan barang lagi...\n");
                break;
            case 0:
                validasi = 1;
                bunyiBeep();
                system("cls");
                printf("Kembali ke menu database\n");
                break;
            default:
                validasi = 0;
                bunyiError();
                system("cls");
                printf("Tidak ada pilihan tersebut!\n");
                break;
            }
        } while (validasi != 1);
    } while (pilihanInt != 0);
    return 0;
}

int editBarang(){
    char pilihanChar[10], kode[10], nama[50], kategori[20], hargaChar[10], kuanChar[10];
    int pilihanInt, hargaInt, kuanInt, validasi = 0, index = -1, cobaLagi = 0;
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
            bunyiBeep();
            system("cls");
            for (int i = 0; i < length; i++)
            {
                if (strcmp(produk[i].id, kode) == 0){
                printf("============================= BARANG DITEMUKAN =====================================\n");
                printf("| Kode  | Nama Produk                    | Kategori | Harga     | Jumlah Stok  |\n");
                printf("| %-5s | %-30s | %-8s | Rp %-6d \t| %-12d |\n", produk[i].id, produk[i].nama, produk[i].kategori, produk[i].harga, produk[i].kuan);
                printf("====================================================================================\n");
                index = i;
                }
            }
            if(index == -1){
                    do {
                        printf("Barang tidak ditemukan\n");
                        do {
                            printf("Apakah ingin mencoba lagi?\n");
                            printf("1 Ya / 0 Tidak\n");
                            printf("Pilihanmu : ");
                            fgets(pilihanChar, sizeof(pilihanChar), stdin);
                            pilihanChar[strcspn(pilihanChar, "\n")] = '\0';
                            
                        } while (!validasiInteger(pilihanChar, &pilihanInt));
                        bunyiBeep();
                    switch (pilihanInt)
                    {
                    case 1:
                        system("cls");
                        printf("Mencoba lagi...\n");
                        cobaLagi = 1;
                        break;

                    case 0:
                        system("cls");
                        return 0;

                    default:
                        bunyiError();
                        system("cls");
                        printf("Tidak ada pilihan seperti itu!\n");
                    }

                } while (pilihanInt != 1 && pilihanInt != 0);

                if (cobaLagi)
                    continue;
                } 
            do {
                do
                {
                    printf("Apakah kamu ingin mengedit data ini?\n");
                    printf("1 Ya / 0 Tidak\n");
                    printf("Pilihanmu : ");
                    fgets(pilihanChar, sizeof(pilihanChar), stdin);
                    pilihanChar[strcspn(pilihanChar, "\n")] = '\0';
                } while (!validasiInteger(pilihanChar, &pilihanInt));
                switch (pilihanInt)
                {
                case 1:
                    bunyiBeep();
                    break;
                case 0:
                    bunyiBeep();
                    system("cls");
                    break;
                default:
                    bunyiError();
                    system("cls");
                    printf("Tidak ada pilihan seperti itu!\n");
                    break;
                }
            } while (pilihanInt != 1 && pilihanInt != 0);

        } while (pilihanInt != 1);
        system("cls");
        do
        {
            printf("Silahkan isi pengeditan barang (Jika tidak ingin di edit, cukup isi \"-\")\n");
            do
            {
                printf("Edit nama : ");
                fgets(nama, sizeof(nama), stdin);
                nama[strcspn(nama, "\n")] = '\0';
            } while (!validasiIsi(nama));
            bunyiBeep();
            do
            {
                printf("Edit kategori : ");
                fgets(kategori, sizeof(kategori), stdin);
                kategori[strcspn(kategori, "\n")] = '\0';
            } while (!validasiIsi(kategori));
            bunyiBeep();
            do
            {
                printf("Edit harga : ");
                fgets(hargaChar, sizeof(hargaChar), stdin);
                hargaChar[strcspn(hargaChar, "\n")] = '\0';
                if (strcmp(hargaChar, "-") == 0)
                {
                    break;
                }    
            } while (!validasiInteger(hargaChar, &hargaInt));
            bunyiBeep();
            do
            {
                printf("Edit kuantitas : ");
                fgets(kuanChar, sizeof(kuanChar), stdin);
                kuanChar[strcspn(kuanChar, "\n")] = '\0';
                if (strcmp(kuanChar, "-") == 0)
                {
                    break;
                }
            } while (!validasiInteger(kuanChar, &kuanInt));
            bunyiBeep();

                printf("====================================== BARANG ======================================\n");
                printf("| Kode  | Nama Produk                    | Kategori | Harga     | Jumlah Stok  |\n");
                printf("| %-5s ", kode);
                
                if (strcmp(nama, "-") == 0){
                    printf("| %-30s ", "Tidak Berubah");
                } else {
                    printf("| %-30s ", nama);
                }
                if (strcmp(kategori, "-") == 0){
                    printf("| %-8s ", "Tidak Berubah");
                } else {
                    printf("| %-8s ", kategori);
                }
                if (strcmp(hargaChar, "-") == 0){
                    printf("| %-6s \t", "Tidak Berubah");
                } else {
                    printf("| Rp %-6d \t", hargaInt);
                }
                if (strcmp(kuanChar, "-") == 0){
                    printf("| %-12s ", "Tidak Berubah");
                } else {
                    printf("| %-12d |\n", kuanInt);
                }
                printf("====================================================================================\n");
            do {
                do
                {
                    printf("Apakah kamu ingin mengedit data ini?\n");
                    printf("1 Ya / 0 Tidak\n");
                    printf("Pilihanmu : ");
                    fgets(pilihanChar, sizeof(pilihanChar), stdin);
                    pilihanChar[strcspn(pilihanChar, "\n")] = '\0';
                } while (!validasiInteger(pilihanChar, &pilihanInt));
                switch (pilihanInt)
                {
                case 1:
                    bunyiBeep();
                    break;
                case 0:
                    bunyiBeep();
                    system("cls");
                    break;
                default:
                    bunyiError();
                    system("cls");
                    printf("Tidak ada pilihan seperti itu!\n");
                    break;
                }
            } while (pilihanInt != 1 && pilihanInt != 0);
            
        } while (pilihanInt != 1);
        if (strcmp(nama, "-") != 0) {
            strcpy(produk[index].nama, nama);
        }
        if (strcmp(kategori, "-") != 0){
            strcpy(produk[index].kategori, kategori);
        }
        if (strcmp(hargaChar, "-") != 0){
            produk[index].harga = hargaInt;
        }
        if (strcmp(kuanChar, "-") != 0){
            produk[index].kuan = kuanInt;
        }
        bunyiBeep();
        printf("Pengeditan barang berhasil!\n");
        do
        {
            do
            {
                printf("Apakah kamu ingin mengedit barang lagi?\n");
                printf("1 Ya / 0 Tidak\n");
                printf("Pilihanmu : ");
                fgets(pilihanChar, sizeof(pilihanChar), stdin);
                pilihanChar[strcspn(pilihanChar, "\n")] = '\0';
            } while (!validasiInteger(pilihanChar, &pilihanInt));
            
            switch (pilihanInt)
            {
            case 1:
                validasi = 1;
                index = -1;
                bunyiBeep();
                system("cls");
                printf("Melakukan pengeditan barang lagi...\n");
                break;
            case 0:
                validasi = 1;
                bunyiBeep();
                system("cls");
                printf("Kembali ke menu database\n");
                break;
            default:
                validasi = 0;
                bunyiError();
                system("cls");
                printf("Tidak ada pilihan tersebut!\n");
                break;
            }
        } while (validasi != 1);
    } while (pilihanInt != 0);
    return 0;
}

int tampilBarangSementara (){
    system("cls");
    printf("Menampilkan barang-barang\n");
    printf("================================ BARANG ========================================\n");
    printf("| Kode  | Nama Produk                    | Kategori | Harga     | Jumlah Stok  |\n");
    for (int i = 0; i < length; i++)
    {
        if(produk[i].id[0] != '\0'){
            printf("| %-5s | %-30s | %-8s | Rp %-6d \t| %-12d |\n", produk[i].id, produk[i].nama, produk[i].kategori, produk[i].harga, produk[i].kuan);
        }
    }
    printf("====================================================================================\n");
    printf("Tekan Enter untuk kembali...");
    getchar();
    bunyiBeep();
    return 0;
}

int menuDatabase(){
    int pilihanInt;
    char pilihanChar[10];
    
    do
    {
        system("cls");
        printf("\n\n");
        printf("      ||====================================================||\n");
        printf("      ||                 MENU DATABASE                      ||\n");
        printf("      ||====================================================||\n");
        printf("      ||                                                    ||\n");
        printf("      ||    1. Tambah barang                                ||\n");
        printf("      ||    2. Hapus barang                                 ||\n");
        printf("      ||    3. Edit barang                                  ||\n");
        printf("      ||    4. Tampilkan barang                             ||\n");
        printf("      ||   99. Kembali ke menu utama                        ||\n");
        printf("      ||                                                    ||\n");
        printf("      ||====================================================||\n");
        printf("      ||    Pilihanmu : ");
        
        fgets(pilihanChar, sizeof(pilihanChar), stdin);
        pilihanInt = atoi(pilihanChar);
        bunyiBeep();

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
            editBarang();
            break;
        case 4:
            system("cls");
            tampilBarangSementara();
            break;
        case 99:
            printf("      ||    Kembali ke menu utama . . .                     ||\n");
            Sleep(500);
            break;
        default:
            bunyiError();
            printf("      ||    Pilihan Invalid. Tekan Enter...                 ||\n");
            getchar();
            break;
        }
    } while (pilihanInt != 99);
    return 0;
}

int main() {
    char username[50];
    int pilihanInt = 0;
    char pilihanChar[10];
    
    tampilkanLoading();

    tampilkanLogin(username);

    tampilkanWelcome(username);

    for(int i = 0; i < 10; i++){
        keranjang[0][i] = -1;
        keranjang[1][i] = 0;
    };

    do
    {
        system("cls");
        printf("\n\n");
        printf("      ||====================================================||\n");
        printf("      ||             SISTEM KOPERASI DESA                   ||\n");
        printf("      ||====================================================||\n");
        printf("      ||                                                    ||\n");
        printf("      ||    1. Masuk Menu Kasir                             ||\n");
        printf("      ||    2. Masuk Menu Database                          ||\n");
        printf("      ||    3. Anggota Kelompok                             ||\n");
        printf("      ||   99. Keluar                                       ||\n");
        printf("      ||                                                    ||\n");
        printf("      ||====================================================||\n");
        printf("      ||    Pilihan anda : ");
        
        fgets(pilihanChar, sizeof(pilihanChar), stdin);
        pilihanInt = atoi(pilihanChar);
        bunyiBeep();

        switch (pilihanInt)
        {
        case 1:
            menuKasir();
            break;
        case 2:
            menuDatabase();
            break;
        case 3:
            tampilkanAnggota();
            break;
        case 99:
            printf("      ||====================================================||\n");
            printf("      ||    Keluar dari program...                          ||\n");
            Sleep(1000);
            exit(0);
            break;
        default:
            bunyiError();
            printf("      ||    Pilihan Invalid. Tekan Enter...                 ||\n");
            getchar();
            break;
        }  
    } while (pilihanInt != 99);
    
    return 0;
}