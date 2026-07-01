#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int barangTambahAtauHapus(){

}

int menuDatabase(){
    int pilihanInt;
    char pilihanChar[10];
    int validasi = 0;
    do
    {
        do
        {
            printf("Selamat datang di menu database\n");
            printf("Silahkan pilih : \n");
            printf("1. Tambah/Hapus barang\n");
            printf("2. Tampilkan barang\n");
            printf("99. Kembali ke menu utama\n");
            printf("Pilihanmu : ");
            fgets(pilihanChar, sizeof(pilihanChar), stdin);
            pilihanChar[strcspn(pilihanChar, "\n")] = '\0';
                if (pilihanChar[0] == '\0')
                {
                    system("cls");
                    printf("Pilihan tidak boleh kosong!\n");
                } else if(strspn(pilihanChar, "0123456789") != strlen(pilihanChar)){
                    system("cls");
                    printf("Pilihan harus dalam bentuk angka!\n");
                } else {
                    validasi = 1;
                }
        } while (validasi != 1);
        pilihanInt = atoi(pilihanChar);
        validasi = 0;
        switch (pilihanInt)
        {
        case 1:
            system("cls");
            printf("%d\n", pilihanInt);
            printf("Ahihihi\n");
            break;
        case 99:
            system("cls");
            printf("%d\n", pilihanInt);
            printf("Kembali ke menu utama . . . \n");
            break;
        
        default:
            system("cls");
            printf("%d\n", pilihanInt);
            printf("Belum ada mas\n");
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
        do
        {
        printf("Selamat datang di sistem supermarket!\n");
        printf("Silahkan pilih yang ingin anda lakukan:\n");
        printf("1. Masuk menu kasir\n");
        printf("2. Cek database\n");
        printf("99. Keluar\n");
            printf("Pilihan anda : ");
            fgets(pilihanChar, sizeof(pilihanChar), stdin);
            pilihanChar[strcspn(pilihanChar, "\n")] = '\0';
            if (pilihanChar[0] == '\0')
            {
                system("cls");
                printf("Pilihan tidak boleh kosong!\n");
            } else if(strspn(pilihanChar, "0123456789") != strlen(pilihanChar)){
                system("cls");
                printf("Pilihan harus dalam bentuk angka!\n");
            } else {
                validasi = 1;
            }
        } while (validasi != 1);
        validasi = 0;
        pilihanInt = atoi(pilihanChar);
        switch (pilihanInt)
        {
        case 2:
            system("cls");
            menuDatabase();
            break;
        case 99:
            system("cls");
            printf("Exiting, goodbye!\n");
            getchar();
            break;
        default:
            system("cls");
            printf("Mohon maaf, pilihan tersebut tidak ada.\n");
            break;
        }
        
    } while (pilihanInt != 99);
    
}