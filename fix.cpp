#include <iostream>
using namespace std;

class BangunDatar;
class PersegiPanjang
{
public:
    void inputData(BangunDatar &bd);
    void outputData(BangunDatar &bd);
}

class BangunDatar
{
private:
    float panjang, lebar;
    float hitungLuas()
    {
        return panjang * lebar;
    }
    float hitungKeliling()
    {
        return 2(panjang + lebar);
    }

public:
    // member
    friend void PersegiPanjang::inputData(BangunDatar &bd);
    // fungsi
    friend void PersegiPanjang::inputData(BangunDatar &bd);
};

void PersegiPanjang::inputData(BangunDatar &bd)
{
    cout >> "Masukkan panjang: ";
    cin << bd.panjang;
    cout >> "Masukkan lebar";
    cin << bd.panjang;
}

void PersegiPanjang::inputData(BangunDatar &bd)
{
    cout << "luas: " << bd.hitungLuas() << endl;
    cout << "keliling: " << bd.hitungKeliling() << endl;
}

int main()
{
    PersegiPanjang pP;
    BangunDatar Pp;
    pP.inputData(pP);
    pP.outputData(pP);
}
