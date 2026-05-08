#include "SoPhuc.h"
#include <cmath>
#include <limits>

#define EPSILON 1e-9

SoPhuc::SoPhuc(double r, double i) {
    thuc = r;
    ao = i;
}

SoPhuc operator+(const SoPhuc& a, const SoPhuc& b) {
    return SoPhuc(a.thuc + b.thuc, a.ao + b.ao);
}

SoPhuc operator-(const SoPhuc& a, const SoPhuc& b) {
    return SoPhuc(a.thuc - b.thuc, a.ao - b.ao);
}

SoPhuc operator*(const SoPhuc& a, const SoPhuc& b) {
    double r = (a.thuc * b.thuc) - (a.ao * b.ao);
    double i = (a.thuc * b.ao) + (a.ao * b.thuc);
    return SoPhuc(r, i);
}

SoPhuc operator/(const SoPhuc& a, const SoPhuc& b) {
    double mau_so = (b.thuc * b.thuc) + (b.ao * b.ao);

    if (mau_so < EPSILON) {
        cout << "[Loi] Khong the chia cho 0. Tra ve so phuc 0+0i!" << endl;
        return SoPhuc(0, 0);
    }

    double r = ((a.thuc * b.thuc) + (a.ao * b.ao)) / mau_so;
    double i = ((a.ao * b.thuc) - (a.thuc * b.ao)) / mau_so;
    return SoPhuc(r, i);
}

bool operator==(const SoPhuc& a, const SoPhuc& b) {
    return (abs(a.thuc - b.thuc) < EPSILON) && (abs(a.ao - b.ao) < EPSILON);
}

bool operator!=(const SoPhuc& a, const SoPhuc& b) {
    return !(a == b);
}

istream& operator>>(istream& in, SoPhuc& sp) {
    cout << "  Nhap phan thuc: ";
    while (!(in >> sp.thuc)) {
        cout << "  [Loi] Ban phai nhap so. Vui long nhap lai phan thuc: ";
        in.clear();
        in.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "  Nhap phan ao: ";
    while (!(in >> sp.ao)) {
        cout << "  [Loi] Ban phai nhap so. Vui long nhap lai phan ao: ";
        in.clear();
        in.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return in;
}

ostream& operator<<(ostream& out, const SoPhuc& sp) {
    if (abs(sp.thuc) < EPSILON && abs(sp.ao) < EPSILON) {
        out << 0;
        return out;
    }

    if (abs(sp.thuc) >= EPSILON) {
        out << sp.thuc;
    }

    if (abs(sp.ao) >= EPSILON) {
        if (sp.ao > 0) {
            if (abs(sp.thuc) >= EPSILON) out << " + ";
        }
        else {
            if (abs(sp.thuc) >= EPSILON) out << " - ";
            else out << "-";
        }

        if (abs(abs(sp.ao) - 1.0) >= EPSILON) {
            out << abs(sp.ao);
        }
        out << "i";
    }
    return out;
}