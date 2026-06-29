#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
        printf("2. Tambah database\n");
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