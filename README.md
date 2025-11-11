# Look Up Efisien Harga Barang E-Commerce

## Deskripsi dan Tujuan
Proyek ini merupakan implementasi algoritma **Insertion Sort** dan **Binary Search** dalam konteks pencarian harga barang pada sistem e-commerce sederhana.  
Program memungkinkan pengguna untuk menambahkan data barang, menampilkan daftar barang, serta mencari barang berdasarkan kategori dan harga tertentu.  
Jika harga yang dimasukkan pengguna tidak ditemukan, program akan menampilkan barang dengan harga terdekat dalam kategori tersebut.

Tujuan utama proyek ini adalah untuk:
- Menerapkan algoritma **Insertion Sort** dalam pengurutan harga barang per kategori.
- Menggunakan **Binary Search** untuk mencari harga barang dengan efisien.

---
## Compile
```bash
g++ lookupharga.cpp -o lookup

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
