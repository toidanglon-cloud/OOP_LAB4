#ifndef CVECTOR_H
#define CVECTOR_H
#include <iostream>

using namespace std;

class CVector {
private:
    int chieu;
    double* thanhPhan;

public:
    CVector(int n = 0);
    CVector(const CVector& other);
    ~CVector();
    CVector& operator=(const CVector& other);

    friend CVector operator+(const CVector& a, const CVector& b);
    friend CVector operator-(const CVector& a, const CVector& b);

    friend double operator*(const CVector& a, const CVector& b);
    friend CVector operator*(const CVector& v, double k);
    friend CVector operator*(double k, const CVector& v);

    friend bool operator==(const CVector& a, const CVector& b);
    friend bool operator!=(const CVector& a, const CVector& b);

    friend istream& operator>>(istream& in, CVector& v);
    friend ostream& operator<<(ostream& out, const CVector& v);
};

#endif