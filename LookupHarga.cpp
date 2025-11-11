#include <iostream>
#include <cmath>
#include <climits>

void insertionSort(int harga[], int n) {
    for (int i = 1; i < n; i++) {
        int temp = harga[i];
        int j = i - 1;
        while (j >= 0 && harga[j] > temp) {
            harga[j + 1] = harga[j];
            j--;
        }
        harga[j + 1] = temp;
    }
}

int binarySearch(int harga[], int n, int target) {
    int left = 0, right = n - 1;
    int closestIndex = -1; // index terdekat jika tidak ada match exact harga, -1 jika data tidak ditemukan
    int minDiff = INT_MAX; // untuk mencari selisih terkecil
    while (left <= right) {
        int mid = (left + right) / 2;
        int diff = std::abs(harga[mid] - target);
        if (diff < minDiff) {
            minDiff = diff;
            closestIndex = mid;
        }
        if (harga[mid] == target) {
            return mid;
        } else if (harga[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return closestIndex;
}

int main() {
    int hargaBarang[] = {1600000, 600000, 3100000, 120000, 950000};
    int n = sizeof(hargaBarang) / sizeof(hargaBarang[0]);

    std::cout << "Data harga sebelum diurutkan:\n";
    for (int i = 0; i < n; i++) {
        std::cout << hargaBarang[i] << " ";
    }
    std::cout << "\n\n";

    insertionSort(hargaBarang, n);

    std::cout << "Data harga setelah diurutkan:\n";
    for (int i = 0; i < n; i++) {
        std::cout << hargaBarang[i] << " ";
    }
    std::cout << "\n\n";

    int targetHarga;
    std::cout << "Masukkan harga yang ingin dicari: ";
    std::cin >> targetHarga;

    int index = binarySearch(hargaBarang, n, targetHarga);

    if (index != -1) {
        std::cout << "Harga ditemukan atau terdekat: " << hargaBarang[index] << std::endl;
    } else {
        std::cout << "Data tidak ditemukan." << std::endl;
    }

    return 0;
}
