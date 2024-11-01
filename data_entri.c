#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAKS_ENTRI 100
#define MAKS_PANJANG 100

typedef struct
{
    char npm[MAKS_PANJANG];
    char nama[MAKS_PANJANG];
    char tempat_lahir[MAKS_PANJANG];
    char tanggal_lahir[MAKS_PANJANG];
    char prodi[MAKS_PANJANG];
} Mahasiswa;

Mahasiswa data_mahasiswa[MAKS_ENTRI];
int jumlah_entri = 0;

// Fungsi untuk menambah entri
void tambah_entri()
{
    if (jumlah_entri >= MAKS_ENTRI)
    {
        printf("Database penuh, tidak dapat menambah entri baru.\n");
        return;
    }

    Mahasiswa entri_baru;
    printf("Masukkan NPM: ");
    scanf("%s", entri_baru.npm);
    printf("Masukkan Nama: ");
    scanf(" %[^\n]s", entri_baru.nama); // Membaca string dengan spasi
    printf("Masukkan Tempat Lahir: ");
    scanf(" %[^\n]s", entri_baru.tempat_lahir);
    printf("Masukkan Tanggal Lahir (DD/MM/YYYY): ");
    scanf("%s", entri_baru.tanggal_lahir);
    printf("Masukkan Prodi: ");
    scanf(" %[^\n]s", entri_baru.prodi);

    data_mahasiswa[jumlah_entri++] = entri_baru;
    printf("Entri berhasil ditambahkan.\n");
}

// Fungsi untuk menampilkan semua entri
void tampilkan_entri()
{
    if (jumlah_entri == 0)
    {
        printf("Tidak ada entri untuk ditampilkan.\n");
        return;
    }

    for (int i = 0; i < jumlah_entri; i++)
    {
        printf("\nEntri %d:\n", i + 1);
        printf("NPM: %s\n", data_mahasiswa[i].npm);
        printf("Nama: %s\n", data_mahasiswa[i].nama);
        printf("Tempat Lahir: %s\n", data_mahasiswa[i].tempat_lahir);
        printf("Tanggal Lahir: %s\n", data_mahasiswa[i].tanggal_lahir);
        printf("Prodi: %s\n", data_mahasiswa[i].prodi);
    }
}

// Fungsi untuk menghapus entri berdasarkan NPM
void hapus_entri()
{
    char npm_dihapus[MAKS_PANJANG];
    printf("Masukkan NPM entri yang ingin dihapus: ");
    scanf("%s", npm_dihapus);

    int i, ditemukan = 0;
    for (i = 0; i < jumlah_entri; i++)
    {
        if (strcmp(data_mahasiswa[i].npm, npm_dihapus) == 0)
        {
            ditemukan = 1;
            break;
        }
    }

    if (!ditemukan)
    {
        printf("Entri dengan NPM %s tidak ditemukan.\n", npm_dihapus);
        return;
    }

    for (int j = i; j < jumlah_entri - 1; j++)
    {
        data_mahasiswa[j] = data_mahasiswa[j + 1];
    }
    jumlah_entri--;
    printf("Entri dengan NPM %s berhasil dihapus.\n", npm_dihapus);
}

// Fungsi utama
int main()
{
    int pilihan;

    do
    {
        printf("\nMenu:\n");
        printf("1. Tambah Entri\n");
        printf("2. Tampilkan Semua Entri\n");
        printf("3. Hapus Entri\n");
        printf("4. Keluar\n");
        printf("Pilih opsi (1-4): ");
        scanf("%d", &pilihan);

        switch (pilihan)
        {
        case 1:
            tambah_entri();
            break;
        case 2:
            tampilkan_entri();
            break;
        case 3:
            hapus_entri();
            break;
        case 4:
            printf("Keluar dari program.\n");
            break;
        default:
            printf("Opsi tidak valid.\n");
            break;
        }
    } while (pilihan != 4);

    return 0;
}
