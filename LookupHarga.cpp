#include <iostream>
#include <cmath>
#include <climits>
#include <string>

struct Barang {
    std::string nama;
    std::string kategori;
    int harga;
};

// Helper method untuk lowercase string ASCII asal + 32
std::string toLowerCase(std::string s) {
    for (char &c : s) {
        if (c >= 'A' && c <= 'Z') {
            c += 32;
        }
    }
    return s;
}

// Method tambah barang
void addBarang(Barang barang[], int &jumlahBarang, std::string nama, std::string kategori, int harga) {
    barang[jumlahBarang].nama = nama;
    barang[jumlahBarang].kategori = kategori;
    barang[jumlahBarang].harga = harga;
    jumlahBarang++;
}

// Method show semua daftar barang
void showAllBarang(Barang barang[], int n) {
    for (int i = 0; i < n; i++) {
        std::cout << "===========================================\n";
        std::cout << "Nama barang: " << barang[i].nama << std::endl;
        std::cout << "Kategori: " << barang[i].kategori << std::endl;
        std::cout << "Harga: Rp. " << barang[i].harga << std::endl;
    }
}

// Method cari barang berdasarkan nama
void findBarangNama(Barang barang[], int n, std::string findNama) {
    std::string key = toLowerCase(findNama);
    bool find = false;

    for (int i = 0; i < n; i++) {
        std::string namaBarangLower = toLowerCase(barang[i].nama);

        if (namaBarangLower.find(key) != std::string::npos) {
            std::cout << "===========================================\n";
            std::cout << "Nama barang: " << barang[i].nama << std::endl;
            std::cout << "Kategori: " << barang[i].kategori << std::endl;
            std::cout << "Harga: Rp. " << barang[i].harga << std::endl;
            find = true;
        }
    }

    if (!find) {
        std::cout << "Barang tidak ditemukan!\n";
    }
}

// Method simpan semua harga barang sesuai kategori yang dicari
int getHargaByKategori(Barang barang[], int &jumlahBarang, std::string kategori, int hargaKategori[], int indexKategori[]) {
    int count = 0;

    std::string key = toLowerCase(kategori);
    for (int i = 0; i < jumlahBarang; i++) {
        std::string kategoriLower = toLowerCase(barang[i].kategori);

        if (kategoriLower.compare(key) == 0) {
            hargaKategori[count] = barang[i].harga;
            indexKategori[count] = i; // simpan index struct
            count++;
        }
    }
    return count;
}

// Method Insertion Sorting Ascending
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int temp = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > temp) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}

// Method Searching
int binarySearch(int arr[], int n, int target) {
    int left = 0, right = n - 1;
    int closestIndex = -1; // index terdekat jika tidak ada match exact harga, -1 jika data tidak ditemukan
    int minDiff = INT_MAX; // untuk mencari selisih terkecil
    while (left <= right) {
        int mid = (left + right) / 2;
        int diff = std::abs(arr[mid] - target);
        if (diff < minDiff) { // mencari selisih terkecil
            minDiff = diff;
            closestIndex = mid;
        }
        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return closestIndex;
}

int main() {
    int n;
    int jumlahBarang = 0;

    std::cout << "Masukkan maksimum barang: ";
    while (!(std::cin >> n) || n <= 0) {
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        std::cout << "Masukkan angka yang valid: ";
    }

    Barang dataBarang[n];
    int hargaKategori[n];
    int indexKategori[n];

    int pilih = 0;

    while (true) {
        std::cout << "\nMenu:\n";
        std::cout << "1. Tambah data Barang\n";
        std::cout << "2. Tampilkan semua data Barang\n";
        std::cout << "3. Cari barang berdasarkan nama\n";
        std::cout << "4. Cari harga berdasarkan kategori\n";
        std::cout << "5. Keluar\n";
        std::cout << "Pilih: ";

        while (!(std::cin >> pilih)) {
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            std::cout << "Masukkan angka yang valid: ";
        }

        std::cin.ignore();

        if (pilih == 1) {
            if (jumlahBarang >= n) {
                std::cout << "Kapasitas penuh\n";
                continue;
            }
            std::string nama, kategori;
            int harga;

            std::cout << "Nama barang: ";
            std::getline(std::cin, nama);

            std::cout << "Kategori: ";
            std::getline(std::cin, kategori);

            std::cout << "Harga: ";
            while (!(std::cin >> harga) || harga < 0) {
                std::cin.clear();
                std::cin.ignore(1000, '\n');
                std::cout << "Masukkan harga valid: ";
            }
            std::cin.ignore();

            addBarang(dataBarang, jumlahBarang, nama, kategori, harga);
        }

        else if (pilih == 2) {
            if (jumlahBarang == 0) {
                std::cout << "Belum ada data\n";
                continue;
            }
            showAllBarang(dataBarang, jumlahBarang);
        }

        else if (pilih == 3) {
            if (jumlahBarang == 0) {
                std::cout << "Belum ada data\n";
                continue;
            }
            std::string nama;
            std::cout << "Masukkan nama barang: ";
            std::getline(std::cin, nama);
            findBarangNama(dataBarang, jumlahBarang, nama);
        }

        else if (pilih == 4) {
            if (jumlahBarang == 0) {
                std::cout << "Belum ada data\n";
                continue;
            }
            std::string kategori;
            std::cout << "Masukkan kategori: ";
            std::getline(std::cin, kategori);

            int jumlah = getHargaByKategori(dataBarang, jumlahBarang, kategori, hargaKategori, indexKategori);

            if (jumlah == 0) {
                std::cout << "Tidak ada data kategori tersebut\n";
                continue;
            }

            insertionSort(hargaKategori, jumlah);

            int target;
            std::cout << "Masukkan harga yang dicari: ";
            while (!(std::cin >> target) || target < 0) {
                std::cin.clear();
                std::cin.ignore(1000, '\n');
                std::cout << "Harga tidak valid: ";
            }
            std::cin.ignore();

            int idx = binarySearch(hargaKategori, jumlah, target);
            std::cout << "Hasil: Rp " << hargaKategori[idx] << "\n";
        }

        else if (pilih == 5) {
            break;
        }

        else {
            std::cout << "Menu tidak valid\n";
        }
    }

    return 0;
}
