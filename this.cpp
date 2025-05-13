#include <iostream>
using namespace std;

class buku
{
    string judul;

public:
    string setget(string judul)
    {
        this->judul = judul; // nilai parameter untuk member variabel
        return this->judul;
    }
};

int main()
{
    buku bukunya;
    cout << bukunya.setget("Matematika");
}
