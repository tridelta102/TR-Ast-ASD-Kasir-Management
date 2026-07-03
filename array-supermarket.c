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
    
    int length = sizeof produk / sizeof produk[0];

    void tukar(struct item *ar, int x, int y){
        struct item tem = ar[x];
        ar[x] = ar[y];
        ar[y] = tem;
    };

    void sort(int x){
            //asc
        if(x == 0){
            for(int j = 0; j < length - 1; j++){
                for(int i = 0; i < length - 1 - j; i++){
                    if(produk[i].harga > produk[i+1].harga){
                       tukar(produk, i, i+1);
                    };
                };
            };
        };
    };


    void tampilkategori(char x[10]){
        printf("====================================== KOPERASI DESA ======================================\n");
        printf("| Kode\t| Nama Produk                    | Kategori\t| Harga\t\t| Jumlah Stok \t|\n");
        for(int i = 0; i < length; i++){
            if(produk[i].id[0] != '\0' && strcmp(produk[i].kategori, x) == 0){
            printf("| %-5s | %-30s | %s\t| Rp %d\t| %d\t\t|\n", produk[i].id, produk[i].nama, produk[i].kategori, produk[i].harga, produk[i].kuan);
            };
        };
        printf("========================================================================================\n\n");

    };

void menu(){
    int input;
    char cek[10];
    printf("\n1 - Lihat Semua\n");
    printf("2 - Lihat Berdasarkan Kategori\n");
    printf("0 - Keluar\n");
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
            menu();
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
                    menu();
                    break;

                    case 2:
                    strcpy(cek, "Minuman");
                    tampilkategori(cek);
                    menu();
                    break;

                    case 3:
                    strcpy(cek, "Snack");
                    tampilkategori(cek);
                    menu();
                    break;

                    case 0:
                    menu();
                    break;

                    default:
                    printf("ERROR: Angka yang anda masukkan tidak sesuai. Tekan Enter untuk Coba lagi...");
                    while (getchar() != '\n'); 
                    getchar();
                    menu();
                    break;
                };
                break;

                case 0:
                    exit(0);
                    break;

                default:
                    printf("ERROR: Angka yang anda masukkan tidak sesuai. Tekan Enter untuk Coba lagi...");
                    while (getchar() != '\n'); 
                    getchar();
                    menu();
                    break;
        };
};

int main(){
    system("cls");
    menu();
    return 0;
}

