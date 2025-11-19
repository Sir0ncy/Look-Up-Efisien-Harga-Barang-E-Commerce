# Look Up Efisien Harga Barang E-Commerce

## Deskripsi dan Tujuan
Proyek ini merupakan implementasi algoritma **Insertion Sort** dan **Binary Search** dalam konteks pencarian harga barang pada sistem e-commerce sederhana.  
Program memungkinkan pengguna untuk menambahkan data barang, menampilkan daftar barang, serta mencari barang berdasarkan kategori dan harga tertentu.  
Jika harga yang dimasukkan pengguna tidak ditemukan, program akan menampilkan barang dengan harga terdekat dalam kategori tersebut.

Tujuan utama proyek ini adalah untuk:
- Menerapkan algoritma **Insertion Sort** dalam pengurutan harga barang per kategori.
- Menggunakan **Binary Search** untuk mencari harga barang dengan efisien.

---
## Functions
| Function | Use for |
|-----------|----------|
| `addBarang()` | Menambahkan data barang baru (nama, kategori, harga) ke dalam array `dataBarang`. |
| `toLowerCase()` | Helper untuk mengubah string menjadi huruf kecil (ASCII only). |
| `showAllBarang()` | Menampilkan seluruh data barang yang tersimpan di array. |
| `findBarangNama()` | Menampilkan seluruh data barang yang cocok atau mengandung keyword pencarian. |
| `getHargaByKategori()` | Mengambil seluruh daftar harga dari kategori tertentu dan menyimpannya ke dalam array `hargaKategori`. |
| `insertionSort()` | Mengurutkan array `hargaKategori` secara ascending menggunakan algoritma Insertion Sort. |
| `binarySearch()` | Mencari harga yang sesuai atau paling dekat dengan input pengguna menggunakan algoritma Binary Search. |

## Compile
```bash
g++ LookupHarga.cpp -o lookup

./lookup
```

## Struktur Data
Program menggunakan `struct Barang` untuk menyimpan data setiap barang dalam bentuk array.

```cpp
struct Barang {
    std::string nama;
    std::string kategori;
    int harga;
};
