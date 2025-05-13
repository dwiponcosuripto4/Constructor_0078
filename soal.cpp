#include <iostream>
using namespace std;

class persegiPanjang;
class bangunDatar
{

public:
    int panjang, lebar;
    void inputluas()
    {
        cout << "Masukkan panjang : ";
        cin >> panjang;
        cout << "Masukkan lebar : ";
        cin >> lebar;
    }

    int hitungLuas(int a, int b)
    {
        return a * b;
    }

    void inputkl()
    {
        cout << "Masukkan panjang : ";
        cin >> panjang;
        cout << "Masukkan lebar : ";
        cin >> lebar;
    }
    int hitungKeliling(int a, int b)
    {
        return a * b * a * b;
    }

    friend void setPanjang(bangunDatar &a);
    friend void setLebar(bangunDatar &b);
};

class persegiPanjang
{
private:
    int panjang, lebar;

public:
    friend int bangunDatar::hitungLuas(int a, int b);
    friend int bangunDatar::hitungKeliling(int a, int b);
};

int main()
{
    bangunDatar pp;
    pp.inputluas();
    cout << "Luas: " << pp.hitungLuas(pp.panjang, pp.lebar) << endl;

    pp.inputkl();
    cout << "Keliling: " << pp.hitungKeliling(pp.panjang, pp.lebar) << endl;

    return 0;
}
