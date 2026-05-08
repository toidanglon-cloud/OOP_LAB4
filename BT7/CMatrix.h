#ifndef CMATRIX_H
#define CMATRIX_H
#include <iostream>
#include "CVector.h" 

using namespace std;

class CMatrix {
private:
    int dong;
    int cot;
    double** duLieu;

public:
    CMatrix(int d = 0, int c = 0);
    CMatrix(const CMatrix& other);
    ~CMatrix();
    CMatrix& operator=(const CMatrix& other);

    friend CMatrix operator+(const CMatrix& a, const CMatrix& b);
    friend CMatrix operator-(const CMatrix& a, const CMatrix& b);
    friend CMatrix operator*(const CMatrix& a, const CMatrix& b);

    friend CVector operator*(const CMatrix& m, const CVector& v);

    friend istream& operator>>(istream& in, CMatrix& m);
    friend ostream& operator<<(ostream& out, const CMatrix& m);
};

#endif