#include "DaThuc.h"
#include <cmath>
#include <limits>

#define EPSILON 1e-9

void DaThuc::chuanHoa() {
    while (bac > 0 && abs(heSo[bac]) < EPSILON) {
        bac--;
    }
}

DaThuc::DaThuc(int b) {
    bac = (b > 0) ? b : 0;
    heSo = new double[bac + 1];
    for (int i = 0; i <= bac; i++) {
        heSo[i] = 0.0;
    }
}

DaThuc::DaThuc(const DaThuc& other) {
    bac = other.bac;
    heSo = new double[bac + 1];
    for (int i = 0; i <= bac; i++) {
        heSo[i] = other.heSo[i];
    }
}

DaThuc::~DaThuc() {
    delete[] heSo;
}

DaThuc& DaThuc::operator=(const DaThuc& other) {
    if (this != &other) {
        delete[] heSo;
        bac = other.bac;
        heSo = new double[bac + 1];
        for (int i = 0; i <= bac; i++) {
            heSo[i] = other.heSo[i];
        }
    }
    return *this;
}

DaThuc operator+(const DaThuc& a, const DaThuc& b) {
    int maxBac = (a.bac > b.bac) ? a.bac : b.bac;
    DaThuc kq(maxBac);
    for (int i = 0; i <= maxBac; i++) {
        double hsa = (i <= a.bac) ? a.heSo[i] : 0.0;
        double hsb = (i <= b.bac) ? b.heSo[i] : 0.0;
        kq.heSo[i] = hsa + hsb;
    }
    kq.chuanHoa();
    return kq;
}

DaThuc operator-(const DaThuc& a, const DaThuc& b) {
    int maxBac = (a.bac > b.bac) ? a.bac : b.bac;
    DaThuc kq(maxBac);
    for (int i = 0; i <= maxBac; i++) {
        double hsa = (i <= a.bac) ? a.heSo[i] : 0.0;
        double hsb = (i <= b.bac) ? b.heSo[i] : 0.0;
        kq.heSo[i] = hsa - hsb;
    }
    kq.chuanHoa();
    return kq;
}

DaThuc operator*(const DaThuc& a, const DaThuc& b) {
    DaThuc kq(a.bac + b.bac);
    for (int i = 0; i <= a.bac; i++) {
        for (int j = 0; j <= b.bac; j++) {
            kq.heSo[i + j] += a.heSo[i] * b.heSo[j];
        }
    }
    kq.chuanHoa();
    return kq;
}

istream& operator>>(istream& in, DaThuc& dt) {
    cout << "  Nhap bac cua da thuc: ";
    int b;
    while (!(in >> b) || b < 0) {
        cout << "  [Loi] Bac phai la so nguyen khong am. Nhap lai: ";
        in.clear();
        in.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    DaThuc tam(b);
    for (int i = tam.bac; i >= 0; i--) {
        cout << "  Nhap he so bac " << i << ": ";
        while (!(in >> tam.heSo[i])) {
            cout << "  [Loi] Vui long nhap so. Nhap lai he so bac " << i << ": ";
            in.clear();
            in.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    tam.chuanHoa();
    dt = tam;
    return in;
}

ostream& operator<<(ostream& out, const DaThuc& dt) {
    bool tatCaBang0 = true;
    for (int i = dt.bac; i >= 0; i--) {
        if (abs(dt.heSo[i]) >= EPSILON) {
            tatCaBang0 = false;

            if (i != dt.bac && dt.heSo[i] > 0) out << " + ";
            else if (dt.heSo[i] < 0) out << (i == dt.bac ? "-" : " - ");

            double hs = abs(dt.heSo[i]);
            if (hs != 1.0 || i == 0) out << hs;

            if (i > 0) {
                out << "x";
                if (i > 1) out << "^" << i;
            }
        }
    }
    if (tatCaBang0) out << "0";
    return out;
}