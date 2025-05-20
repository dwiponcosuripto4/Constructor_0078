// Class Buku berisi informasi seperti judul, penulis, dan status peminjaman (bool dipinjam).
// Status ini bersifat privat dan tidak dapat diubah langsung oleh sembarang class. Hanya class Petugas yang dapat memproses status peminjaman atau pengembalian buku.
// Oleh karena itu, class Petugas harus dijadikan sebagai friend class dari Buku,
// sehingga dapat memodifikasi status peminjaman dengan method seperti prosesPinjam(Buku* b, Peminjam* p) dan prosesKembali(Buku* b).

// Class Peminjam menyimpan data pengguna seperti nama dan ID, serta jumlah buku yang sedang dipinjam (int totalPeminjaman).
// Atribut totalPeminjaman bersifat privat dan hanya dapat diubah oleh class Petugas yang memproses peminjaman atau pengembalian.
// Oleh karena itu, Petugas juga dijadikan friend class oleh Peminjam.

// Class Petugas bertanggung jawab terhadap operasional peminjaman dan pengembalian.
// Selain itu, ia memiliki atribut pribadi seperti nama, ID petugas, dan level akses (string levelAkses).
// Namun, hanya class Admin yang boleh mengubah level akses petugas berdasarkan performa. Karena itu, class Admin harus dijadikan friend class oleh Petugas.

// Class Admin hanya berhak melihat statistik data, termasuk jumlah buku yang sedang dipinjam oleh seorang peminjam,
// tetapi tidak memiliki akses penuh terhadap atribut private class lain.
// Untuk itu, informasi-informasi tersebut diberikan melalui friend function yang didefinisikan di dalam class Peminjam dan Buku,
// dengan kata lain, Admin hanya diizinkan mengakses data privat melalui fungsi friend yang disediakan secara terbatas.

#include <iostream>
#include <string>
using namespace std;

class Peminjam;
class Petugas;

class Buku
{
public:
    string judul;
    string penulis;
    bool dipinjam; // Status peminjaman buku

public:
    Buku(string j, string p) : judul(j), penulis(p), dipinjam(false) {}

    // Friend function to allow Petugas class to access and modify dipinjam
    friend void prosesPinjam(Buku *b, Peminjam *p);
    friend void prosesKembali(Buku *b);

    // Function to display book information
    void printInfo() const
    {
        cout << "Buku: " << judul << " oleh " << penulis << ", Status Peminjaman: " << (dipinjam ? "Dipinjam" : "Tersedia") << endl;
    }

    // Getter dan setter untuk dipinjam
    bool getDipinjam() const { return dipinjam; }
    void setDipinjam(bool status) { dipinjam = status; }
};

class Peminjam
{
private:
    string nama;
    int ID;
    int totalPeminjaman;

public:
    Peminjam(string n, int id) : nama(n), ID(id), totalPeminjaman(0) {}

    // Friend class Petugas to access totalPeminjaman and allow borrowing or returning books
    friend class Petugas;

    // Function to display borrower information
    void printInfo() const
    {
        cout << "Peminjam: " << nama << " (ID: " << ID << "), Total Peminjaman: " << totalPeminjaman << endl;
    }
};

class Petugas
{
private:
    string nama;
    int IDPetugas;
    string levelAkses; // Level akses petugas

public:
    Petugas(string n, int id, string level) : nama(n), IDPetugas(id), levelAkses(level) {}

    // Friend function to allow Admin to modify levelAkses
    friend class Admin;

    // Function to process borrowing a book
    void prosesPinjam(Buku *b, Peminjam *p)
    {
        if (!b->getDipinjam())
        {
            b->setDipinjam(true);
            p->totalPeminjaman++;
            cout << p->nama << " telah meminjam buku: " << b->judul << endl;
        }
        else
        {
            cout << "Buku sudah dipinjam." << endl;
        }
    }

    // Function to process returning a book
    void prosesKembali(Buku *b)
    {
        if (b->getDipinjam())
        {
            b->setDipinjam(false);
            cout << "Buku " << b->judul << " telah dikembalikan." << endl;
        }
        else
        {
            cout << "Buku tidak sedang dipinjam." << endl;
        }
    }

    // Function to display petugas information
    void printInfo() const
    {
        cout << "Petugas: " << nama << " (ID: " << IDPetugas << "), Level Akses: " << levelAkses << endl;
    }
};

class Admin
{
public:
    // Function to view book information (via friend access)
    void lihatBuku(Buku *b)
    {
        b->printInfo();
    }

    // Function to view borrower information (via friend access)
    void lihatPeminjam(Peminjam *p)
    {
        p->printInfo();
    }
};

int main()
{
    // Membuat objek Buku
    Buku b1("Pemrograman C++", "Budi Santoso");

    // Membuat objek Peminjam
    Peminjam p1("Sri Dadi", 101);

    // Membuat objek Petugas
    Petugas petugas1("Andi", 201, "Admin");

    // Membuat objek Admin
    Admin admin1;

    // Menampilkan informasi sebelum peminjaman
    b1.printInfo();
    p1.printInfo();

    // Petugas memproses peminjaman
    petugas1.prosesPinjam(&b1, &p1);

    // Menampilkan informasi setelah peminjaman
    b1.printInfo();
    p1.printInfo();

    // Admin melihat informasi
    admin1.lihatBuku(&b1);
    admin1.lihatPeminjam(&p1);

    // Petugas memproses pengembalian
    petugas1.prosesKembali(&b1);

    // Menampilkan informasi setelah pengembalian
    b1.printInfo();
    p1.printInfo();

    return 0;
}
