#include "PhanSo.h"
#include <cmath>
#include <limits>

int PhanSo::timUCLN(int a, int b) {
    a = abs(a);
    b = abs(b);
    if (a == 0 || b == 0) return a + b;
    while (a != b) {
        if (a > b) a = a - b;
        else b = b - a;
    }
    return a;
}

void PhanSo::rutGon() {
    if (tu == 0) {
        mau = 1;
        return;
    }
    if (mau < 0) {
        tu = -tu;
        mau = -mau;
    }
    int ucln = timUCLN(tu, mau);
    tu = tu / ucln;
    mau = mau / ucln;
}

PhanSo::PhanSo(int t, int m) {
    tu = t;
    if (m == 0) {
        cout << "[Loi] Mau so khong the bang 0. Tu dong gan mau = 1." << endl;
        mau = 1;
    }
    else {
        mau = m;
    }
    rutGon();
}

PhanSo operator+(const PhanSo& a, const PhanSo& b) {
    PhanSo kq(a.tu * b.mau + b.tu * a.mau, a.mau * b.mau);
    return kq;
}

PhanSo operator-(const PhanSo& a, const PhanSo& b) {
    PhanSo kq(a.tu * b.mau - b.tu * a.mau, a.mau * b.mau);
    return kq;
}

PhanSo operator*(const PhanSo& a, const PhanSo& b) {
    PhanSo kq(a.tu * b.tu, a.mau * b.mau);
    return kq;
}

PhanSo operator/(const PhanSo& a, const PhanSo& b) {
    if (b.tu == 0) {
        cout << "[Loi] Khong the chia cho 0. Tra ve phan so 0/1." << endl;
        return PhanSo(0, 1);
    }
    PhanSo kq(a.tu * b.mau, a.mau * b.tu);
    return kq;
}

bool operator==(const PhanSo& a, const PhanSo& b) {
    return (a.tu == b.tu && a.mau == b.mau);
}

bool operator>(const PhanSo& a, const PhanSo& b) {
    return (a.tu * b.mau > b.tu * a.mau);
}

bool operator<(const PhanSo& a, const PhanSo& b) {
    return (a.tu * b.mau < b.tu * a.mau);
}

istream& operator>>(istream& in, PhanSo& ps) {
    cout << "  Nhap tu so: ";
    while (!(in >> ps.tu)) {
        cout << "  [Loi] Ban phai nhap SO. Vui long nhap lai tu so: ";
        in.clear();
        in.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "  Nhap mau so: ";
    while (!(in >> ps.mau) || ps.mau == 0) {
        if (in.fail()) {
            cout << "  [Loi] Ban phai nhap SO. Vui long nhap lai mau so: ";
            in.clear();
            in.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else {
            cout << "  [Loi] Mau so phai khac 0. Vui long nhap lai mau so: ";
        }
    }
    ps.rutGon();
    return in;
}

ostream& operator<<(ostream& out, const PhanSo& ps) {
    if (ps.tu == 0) {
        out << 0;
    }
    else if (ps.mau == 1) {
        out << ps.tu;
    }
    else {
        out << ps.tu << "/" << ps.mau;
    }
    return out;
}