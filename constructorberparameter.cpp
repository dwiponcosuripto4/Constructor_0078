#include <iostream>
using namespace std;

class mahasiswa
{
public:
    mahasiswa(int nim, string nama);
};

mahasiswa::mahasiswa(int nim, string nama)
{
    cout << "construktor dengan parameter terpanggil" << endl;
    cout << "NIM: " << nim << endl;
    cout << "Nama: " << nama << endl;
}
