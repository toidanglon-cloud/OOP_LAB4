#ifndef PHANSO_H
#define PHANSO_H
#include <iostream>

using namespace std;

class PhanSo {
private:
    int tu;
    int mau;

    int timUCLN(int a, int b);
    void rutGon();

public:
    PhanSo(int t = 0, int m = 1);

    friend PhanSo operator+(const PhanSo& a, const PhanSo& b);
    friend PhanSo operator-(const PhanSo& a, const PhanSo& b);
    friend PhanSo operator*(const PhanSo& a, const PhanSo& b);
    friend PhanSo operator/(const PhanSo& a, const PhanSo& b);

    friend bool operator==(const PhanSo& a, const PhanSo& b);
    friend bool operator>(const PhanSo& a, const PhanSo& b);
    friend bool operator<(const PhanSo& a, const PhanSo& b);

    friend istream& operator>>(istream& in, PhanSo& ps);
    friend ostream& operator<<(ostream& out, const PhanSo& ps);
};

#endif