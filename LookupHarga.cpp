#include <iostream>
#include <cmath>
#include <climits>
#include <string>
#include <vector>
#include <iomanip>

struct Barang
{
    std::string nama;
    std::string kategori;
    int harga;
};

// Helper method untuk lowercase string ASCII asal + 32
std::string toLowerCase(std::string s)
{
    for (char &c : s)
    {
        if (c >= 'A' && c <= 'Z')
        {
            c += 32;
        }
    }
    return s;
}

// Method tambah barang
void addBarang(std::vector<Barang> &dataBarang)
{
    Barang b;
    int hargaInput;
    std::string namaInput, kategoriInput;

    std::cout << "Nama barang: ";
    std::getline(std::cin, namaInput);
    std::cout << "Kategori   : ";
    std::getline(std::cin, kategoriInput);
    std::cout << "Harga      : ";
    std::cin >> hargaInput;
    std::cin.ignore();

    b.nama = namaInput;
    b.kategori = kategoriInput;
    b.harga = hargaInput;

    dataBarang.push_back(b);
}

// Method show semua daftar barang
void showAllBarang(const std::vector<Barang> dataBarang)
{
    std::cout << "=============================================\n";
    std::cout << std::left
              << std::setw(5) << "No"
              << std::setw(20) << "Nama Barang"
              << std::setw(15) << "Kategori"
              << std::setw(10) << "Harga"
              << "\n";
    std::cout << "=============================================\n";

    for (std::size_t i = 0; i < dataBarang.size(); i++)
    {
        std::cout << std::left
                  << std::setw(5) << i + 1
                  << std::setw(20) << dataBarang[i].nama
                  << std::setw(15) << dataBarang[i].kategori
                  << std::setw(10) << dataBarang[i].harga
                  << "\n";
    }
}

// Method cari barang berdasarkan nama
void findBarangNama(const std::vector<Barang> &dataBarang, std::string &findNama)
{
    std::string key = toLowerCase(findNama);
    bool find = false;

    std::cout << "=============================================\n";
    std::cout << std::left
              << std::setw(5) << "No"
              << std::setw(20) << "Nama Barang"
              << std::setw(15) << "Kategori"
              << std::setw(10) << "Harga"
              << "\n";
    std::cout << "=============================================\n";
    int nomor = 1;
    for (std::size_t i = 0; i < dataBarang.size(); i++)
    {
        std::string lowerNama = toLowerCase(dataBarang[i].nama);
        if (lowerNama.find(key) != std::string::npos)
        {
            std::cout << std::left
                      << std::setw(5) << nomor++
                      << std::setw(20) << dataBarang[i].nama
                      << std::setw(15) << dataBarang[i].kategori
                      << std::setw(10) << dataBarang[i].harga
                      << "\n";
            find = true;
        }
    }

    if (!find)
    {
        std::cout << "Barang tidak ditemukan!\n";
    }
}

// Method simpan semua harga barang sesuai kategori yang dicari
int getHargaByKategori(const std::vector<Barang> &dataBarang, std::string kategori, std::vector<int> &hargaKategori, std::vector<int> &indexKategori)
{
    hargaKategori.clear(); // bersihkan dulu
    indexKategori.clear(); // bersihkan dulu
    std::string key = toLowerCase(kategori);
    for (int i = 0; i < dataBarang.size(); i++)
    {
        if (toLowerCase(dataBarang[i].kategori) == key)
        {
            hargaKategori.push_back(dataBarang[i].harga);
            indexKategori.push_back(i); // buat nyimpan index asli structnya
        }
    }
    return hargaKategori.size();
}

// Method Insertion Sorting Ascending Parallel untuk sorting index yang dihasilkan method getHargaByKategori
void insertionSortParallel(std::vector<int> &arr, std::vector<int> &indexArr)
{
    for (int i = 1; i < arr.size(); i++)
    {
        int temp = arr[i];
        int tempIdx = indexArr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > temp)
        {
            arr[j + 1] = arr[j];
            indexArr[j + 1] = indexArr[j];
            j--;
        }
        arr[j + 1] = temp;
        indexArr[j + 1] = tempIdx;
    }
}

// Method Searching
int binarySearch(const std::vector<int> &arr, int target)
{
    int left = 0, right = arr.size() - 1;
    int closestIndex = -1; // index terdekat jika tidak ada match exact harga, -1 jika data tidak ditemukan
    int minDiff = INT_MAX; // untuk mencari selisih terkecil
    while (left <= right)
    {
        int mid = (left + right) / 2;
        int diff = std::abs(arr[mid] - target);
        if (diff < minDiff)
        { // mencari selisih terkecil
            minDiff = diff;
            closestIndex = mid;
        }
        if (arr[mid] == target)
        {
            return mid;
        }
        else if (arr[mid] < target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return closestIndex;
}

int main() {

    return 0;
}
