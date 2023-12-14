#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void garis() {
    printf("\n===============================================");
}

struct member {
    char nama[20];
    char kode[4];
    int poin;
};

void menu() {
    garis();
    printf("\n===== M E N U  M E M B E R  D W I J A Y A =====");
    garis();
    printf("\n 1. Input");
    printf("\n 2. Insert");
    printf("\n 3. Update");
    printf("\n 4. Delete");
    printf("\n 5. List Data");
    printf("\n 6. Selesai");
}

int main() {
    int pil = 0;
    int index = 0;
    struct member mc[100];
    int ins;
    char s_ins[20];
    char edit[20];
    int note = -1;
    int del;
    char hapus[20];

    while (pil != 6) {
        menu();
        printf("\n Masukan pilihanmu : ");
        scanf("%d", &pil);

        switch (pil) {
            case 1:
                printf("\nInput data member ke %d", index + 1);
                printf("\nMasukan Nama = "); fflush(stdin);
                gets(mc[index].nama);
                printf("Masukan Kode = "); gets(mc[index].kode);
                printf("Masukan Poin = "); scanf("%d", &mc[index].poin);
                index++;
                break;
            case 2:
                printf("\nMasukan data ke berapa yang ingin disisipkan? maks record %d", index);
                fflush(stdin);
                gets(s_ins);
                ins = atoi(s_ins);
                if (ins > index) {
                    printf("Melebihi maximal data!");
                } else {
                    for (int i = index - 1; i >= ins; i--) {
                        strcpy(mc[i + 1].nama, mc[i].nama);
                        strcpy(mc[i + 1].kode, mc[i].kode);
                        mc[i + 1].poin = mc[i].poin;
                    }
                    printf("\nInput Data Member Baru pada posisi %d", ins);
                    printf("\nMasukan Nama = "); fflush(stdin);
                    gets(mc[ins].nama);
                    printf("Masukan Kode = "); gets(mc[ins].kode);
                    printf("Masukan Poin = "); scanf("%d", &mc[ins].poin);
                    index++;
                }
                break;
            case 3:
                printf("\nMasukan nama yang akan diubah = ");
                fflush(stdin);
                gets(edit);
                note = -1;
                for (int i = 0; i < index; i++) {
                    if (strcmp(edit, mc[i].nama) == 0) {
                        note = i;
                        break;
                    }
                }
                if (note != -1) {
                    printf("\nEdit Data Member ke-%d", note + 1);
                    printf("\nMasukan Nama = "); fflush(stdin);
                    gets(mc[note].nama);
                    printf("Masukan Kode = "); gets(mc[note].kode);
                    printf("Masukan Poin = "); scanf("%d", &mc[note].poin);
                } else {
                    printf("\nData tidak ditemukan!");
                }
                break;
            case 4:
                printf("\nData ke berapa yang ingin dihapus? = ");
                scanf("%d", &del);
                del--;
                if (del >= index || del < 0) {
                    printf("Data tidak ditemukan!");
                } else {
                    printf("\nData rekaman sebelum dihapus:");
                    printf("\nNama = %s", mc[del].nama);
                    printf("\nKode = %s", mc[del].kode);
                    printf("\nPoin = %d", mc[del].poin);
                    printf("\nApakah Anda yakin akan menghapus data ini (y/t)? ");
                    fflush(stdin);
                    gets(hapus);
                    if (hapus[0] == 'y' || hapus[0] == 'Y') {
                        for (int i = del; i < index - 1; i++) {
                            strcpy(mc[i].nama, mc[i + 1].nama);
                            strcpy(mc[i].kode, mc[i + 1].kode);
                            mc[i].poin = mc[i + 1].poin;
                        }
                        index--;
                        printf("\nData telah dihapus.");
                    } else {
                        printf("\nPenghapusan data dibatalkan.");
                    }
                }
        break;

                break;
            case 5:
                for (int i = 0; i < index; i++) {
                    printf("\nData Member Ke-%d", i + 1);
                    garis();
                    printf("\nNama Member : %s", mc[i].nama);
                    printf("\nKode Member : %s", mc[i].kode);
                    printf("\nPoin : %d\n", mc[i].poin);
                }
                break;
        }
    }
    return 0;
}

