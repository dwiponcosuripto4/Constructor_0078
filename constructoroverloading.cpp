#include <iostream>
#include <string>
using namespace std;

class mahasiswa
{
private:
    int nim;
    string nama;

public:
    mahasiswa();
    mahasiswa(int);
    mahasiswa(string);
    mahasiswa(int nim, string nama);
    void cetak();
};

mahasiswa::mahasiswa(/* args */)
{
}
mahasiswa::mahasiswa(int iNim)
{
    nim = iNim; // definisi hanya nim
}

mahasiswa::mahasiswa(string iNama)
{
    nama = iNama;
}
mahasiswa::mahasiswa(int iNim, string iNama)
{
    nim = iNim;
    nama = iNama;
}

void mahasiswa::cetak()
{
    cout << endl
         << "Nim = " << nim << endl;
    cout << endl
         << "Nama = " << nama << endl;
}