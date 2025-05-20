#include <iostream>
using namespace std;

class barang
{
private:
    string namaBarang;
    int kodeBarang;

public:
    barang(string namaBarang, int kodeBarang);
    void cetak();
};

barang::barang(string namaBarang, int kodeBarang)
{
    cout << "constructor terpanggil" << endl;
    cout << "Nama Barang: " << namaBarang << endl;
    cout << "Kode Barang: " << kodeBarang << endl;
}

void barang::cetak()
{
    cout << endl
         << "Nama Barang: Laptop" << namaBarang << endl;
    cout << "Kode Barang: 078" << kodeBarang << endl;
}

int main()
{
    barang b("Laptop", 12345);
    b.cetak();
    return 0;
}
