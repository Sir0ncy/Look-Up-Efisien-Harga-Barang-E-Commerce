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
    

    return 0;
}
