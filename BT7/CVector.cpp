#include "CVector.h"
#include <cmath>
#include <limits>

#define EPSILON 1e-9

CVector::CVector(int n) {
    chieu = (n > 0) ? n : 0;
    if (chieu > 0) {
        thanhPhan = new double[chieu];
        for (int i = 0; i < chieu; i++) {
            thanhPhan[i] = 0.0;
        }
    }
    else {
        thanhPhan = nullptr;
    }
}

CVector::CVector(const CVector& other) {
    chieu = other.chieu;
    if (chieu > 0) {
        thanhPhan = new double[chieu];
        for (int i = 0; i < chieu; i++) {
            thanhPhan[i] = other.thanhPhan[i];
        }
    }
    else {
        thanhPhan = nullptr;
    }
}

CVector::~CVector() {
    delete[] thanhPhan;
}

CVector& CVector::operator=(const CVector& other) {
    if (this != &other) {
        delete[] thanhPhan;
        chieu = other.chieu;
        if (chieu > 0) {
            thanhPhan = new double[chieu];
            for (int i = 0; i < chieu; i++) {
                thanhPhan[i] = other.thanhPhan[i];
            }
        }
        else {
            thanhPhan = nullptr;
        }
    }
    return *this;
}

CVector operator+(const CVector& a, const CVector& b) {
    if (a.chieu != b.chieu) {
        cout << "[Loi] Hai vector khong cung so chieu. Phep cong khong hop le!" << endl;
        return CVector(0);
    }
    CVector kq(a.chieu);
    for (int i = 0; i < a.chieu; i++) {
        kq.thanhPhan[i] = a.thanhPhan[i] + b.thanhPhan[i];
    }
    return kq;
}

CVector operator-(const CVector& a, const CVector& b) {
    if (a.chieu != b.chieu) {
        cout << "[Loi] Hai vector khong cung so chieu. Phep tru khong hop le!" << endl;
        return CVector(0);
    }
    CVector kq(a.chieu);
    for (int i = 0; i < a.chieu; i++) {
        kq.thanhPhan[i] = a.thanhPhan[i] - b.thanhPhan[i];
    }
    return kq;
}

double operator*(const CVector& a, const CVector& b) {
    if (a.chieu != b.chieu) {
        cout << "[Loi] Hai vector khong cung so chieu. Khong the tinh tich vo huong!" << endl;
        return 0.0;
    }
    double kq = 0;
    for (int i = 0; i < a.chieu; i++) {
        kq += a.thanhPhan[i] * b.thanhPhan[i];
    }
    return kq;
}

CVector operator*(const CVector& v, double k) {
    CVector kq(v.chieu);
    for (int i = 0; i < v.chieu; i++) {
        kq.thanhPhan[i] = v.thanhPhan[i] * k;
    }
    return kq;
}

CVector operator*(double k, const CVector& v) {
    return v * k;
}

bool operator==(const CVector& a, const CVector& b) {
    if (a.chieu != b.chieu) return false;
    for (int i = 0; i < a.chieu; i++) {
        if (abs(a.thanhPhan[i] - b.thanhPhan[i]) >= EPSILON) {
            return false;
        }
    }
    return true;
}

bool operator!=(const CVector& a, const CVector& b) {
    return !(a == b);
}

istream& operator>>(istream& in, CVector& v) {
    int n;
    cout << "  Nhap so chieu cua vector (n > 0): ";
    while (!(in >> n) || n <= 0) {
        cout << "  [Loi] So chieu phai la so nguyen duong. Nhap lai: ";
        in.clear();
        in.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    CVector tam(n);
    for (int i = 0; i < tam.chieu; i++) {
        cout << "  Nhap thanh phan thu " << i + 1 << ": ";
        while (!(in >> tam.thanhPhan[i])) {
            cout << "  [Loi] Ban phai nhap so. Nhap lai thanh phan thu " << i + 1 << ": ";
            in.clear();
            in.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    v = tam;
    return in;
}

ostream& operator<<(ostream& out, const CVector& v) {
    if (v.chieu == 0) {
        out << "(Vector rong)";
        return out;
    }
    out << "(";
    for (int i = 0; i < v.chieu; i++) {
        out << v.thanhPhan[i];
        if (i < v.chieu - 1) out << ", ";
    }
    out << ")";
    return out;
}

