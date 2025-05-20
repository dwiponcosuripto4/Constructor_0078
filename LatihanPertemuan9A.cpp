// Class Mahasiswa menyimpan informasi seperti nama, NIM, dan nilai.
// Atribut nilai bersifat privat dan tidak boleh diubah langsung oleh objek lain, kecuali oleh dosen yang mengajar.
// Oleh karena itu, class Dosen dideklarasikan sebagai friend class dari Mahasiswa,
// sehingga dosen dapat mengakses dan memberikan nilai menggunakan method seperti beriNilai(Mahasiswa* m, float nilai).

// Class Dosen menyimpan atribut pribadi seperti nama, NIDN, pangkat, dan gaji, dengan pangkat dosen hanya dapat diubah oleh Staff,
// sehingga class Staff harus dideklarasikan friend class oleh Dosen.
// Namun, berbeda dari akses gaji, pihak Universitas tidak dijadikan friend class secara langsung,
// melainkan hanya dapat mengakses informasi gaji dosen melalui sebuah fungsi friend yang dideklarasikan secara eksplisit di dalam class Dosen,
// tetapi dideklarasikan di luar class Universitas.

// Class Staff menyimpan informasi seperti ID staff, nama, dan gaji, dengan gaji bersifat privat.
// Staff memiliki kemampuan untuk mengubah pangkat dosen melalui pointer menggunakan method ubahPangkat(Dosen* d, string pangkatBaru).
// Sama seperti dosen, data gaji staff tidak bisa diakses langsung oleh class Universitas,
// tetapi disediakan melalui sebuah fungsi friend bernama lihatGajiStaff(Staff* s) yang diimplementasikan dalam class Universitas.

#include <iostream>
#include <string>
using namespace std;

class Dosen;
class Mahasiswa
{
private:
    string nama;
    int NIM;
    float nilai;

public:
    Mahasiswa(string nama, int NIM, float nilai) : nama(nama), NIM(NIM), nilai(nilai) {}

    // Friend function to allow Dosen class to access Mahasiswa's nilai
    friend void beriNilai(Mahasiswa *m, float nilai);
};

class Dosen
{
private:
    string nama;
    string NIDN;
    string pangkat;
    float gaji;

public:
    Dosen(string nama, string NIDN, string pangkat, float gaji)
        : nama(nama), NIDN(NIDN), pangkat(pangkat), gaji(gaji) {}

    // Friend function to give grade to Mahasiswa
    friend void beriNilai(Mahasiswa *m, float nilai);
};

class Staff
{
private:
    string nama;
    string IDStaff;
    float gaji;

public:
    Staff(string nama, string IDStaff, float gaji)
        : nama(nama), IDStaff(IDStaff), gaji(gaji) {}

    // Getter untuk nama
    string getNama() const
    {
        return nama;
    }

    // Friend function to access Staff salary
    friend float lihatGajiStaff(Staff *s);
};

// Function to assign grade to a student, can only be accessed by Dosen
void beriNilai(Mahasiswa *m, float nilai)
{
    m->nilai = nilai;
    cout << "Nilai untuk mahasiswa " << m->nama << " (NIM: " << m->NIM << ") telah diberikan: " << m->nilai << endl;
}

// Function to access Staff salary, can be accessed by Universitas class
float lihatGajiStaff(Staff *s)
{
    return s->gaji;
}

int main()
{
    // Membuat objek Mahasiswa
    Mahasiswa mhs1("Sri Dadi", 12345, 0);

    // Membuat objek Dosen
    Dosen dosen1("Dr. Ahmad", "NIDN123", "Profesor", 10000000);

    // Membuat objek Staff
    Staff staff1("Budi", "ID123", 5000000);

    // Dosen memberi nilai pada mahasiswa
    beriNilai(&mhs1, 90);

    cout << "Gaji Staff " << staff1.getNama() << ": " << lihatGajiStaff(&staff1) << endl;

    return 0;
}
