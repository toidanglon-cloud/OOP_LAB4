#include "CMatrix.h"
#include <limits>

CMatrix::CMatrix(int d, int c) {
    dong = (d > 0) ? d : 0;
    cot = (c > 0) ? c : 0;

    if (dong > 0 && cot > 0) {
        duLieu = new double* [dong];
        for (int i = 0; i < dong; i++) {
            duLieu[i] = new double[cot];
            for (int j = 0; j < cot; j++) {
                duLieu[i][j] = 0.0;
            }
        }
    }
    else {
        duLieu = nullptr;
    }
}

CMatrix::CMatrix(const CMatrix& other) {
    dong = other.dong;
    cot = other.cot;

    if (dong > 0 && cot > 0) {
        duLieu = new double* [dong];
        for (int i = 0; i < dong; i++) {
            duLieu[i] = new double[cot];
            for (int j = 0; j < cot; j++) {
                duLieu[i][j] = other.duLieu[i][j];
            }
        }
    }
    else {
        duLieu = nullptr;
    }
}

CMatrix::~CMatrix() {
    if (duLieu != nullptr) {
        for (int i = 0; i < dong; i++) {
            delete[] duLieu[i];
        }
        delete[] duLieu;
    }
}

CMatrix& CMatrix::operator=(const CMatrix& other) {
    if (this != &other) {
        if (duLieu != nullptr) {
            for (int i = 0; i < dong; i++) {
                delete[] duLieu[i];
            }
            delete[] duLieu;
        }

        dong = other.dong;
        cot = other.cot;

        if (dong > 0 && cot > 0) {
            duLieu = new double* [dong];
            for (int i = 0; i < dong; i++) {
                duLieu[i] = new double[cot];
                for (int j = 0; j < cot; j++) {
                    duLieu[i][j] = other.duLieu[i][j];
                }
            }
        }
        else {
            duLieu = nullptr;
        }
    }
    return *this;
}

CMatrix operator+(const CMatrix& a, const CMatrix& b) {
    if (a.dong != b.dong || a.cot != b.cot) {
        cout << "[Loi] Hai ma tran khong cung kich thuoc. Khong the cong!" << endl;
        return CMatrix(0, 0);
    }
    CMatrix kq(a.dong, a.cot);
    for (int i = 0; i < a.dong; i++) {
        for (int j = 0; j < a.cot; j++) {
            kq.duLieu[i][j] = a.duLieu[i][j] + b.duLieu[i][j];
        }
    }
    return kq;
}

CMatrix operator-(const CMatrix& a, const CMatrix& b) {
    if (a.dong != b.dong || a.cot != b.cot) {
        cout << "[Loi] Hai ma tran khong cung kich thuoc. Khong the tru!" << endl;
        return CMatrix(0, 0);
    }
    CMatrix kq(a.dong, a.cot);
    for (int i = 0; i < a.dong; i++) {
        for (int j = 0; j < a.cot; j++) {
            kq.duLieu[i][j] = a.duLieu[i][j] - b.duLieu[i][j];
        }
    }
    return kq;
}

CMatrix operator*(const CMatrix& a, const CMatrix& b) {
    if (a.cot != b.dong) {
        cout << "[Loi] So cot ma tran 1 phai bang so dong ma tran 2. Khong the nhan!" << endl;
        return CMatrix(0, 0);
    }
    CMatrix kq(a.dong, b.cot);
    for (int i = 0; i < a.dong; i++) {
        for (int j = 0; j < b.cot; j++) {
            kq.duLieu[i][j] = 0.0;
            for (int k = 0; k < a.cot; k++) {
                kq.duLieu[i][j] += a.duLieu[i][k] * b.duLieu[k][j];
            }
        }
    }
    return kq;
}

CVector operator*(const CMatrix& m, const CVector& v) {
    if (m.cot != v.chieu) {
        cout << "[Loi] So cot cua ma tran phai bang so chieu cua vector. Khong the nhan!" << endl;
        return CVector(0);
    }
    CVector kq(m.dong);
    for (int i = 0; i < m.dong; i++) {
        kq.thanhPhan[i] = 0.0;
        for (int j = 0; j < m.cot; j++) {
            kq.thanhPhan[i] += m.duLieu[i][j] * v.thanhPhan[j];
        }
    }
    return kq;
}

istream& operator>>(istream& in, CMatrix& m) {
    int d, c;
    cout << "  Nhap so dong: ";
    while (!(in >> d) || d <= 0) {
        cout << "  [Loi] So dong phai lon hon 0. Nhap lai: ";
        in.clear();
        in.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cout << "  Nhap so cot: ";
    while (!(in >> c) || c <= 0) {
        cout << "  [Loi] So cot phai lon hon 0. Nhap lai: ";
        in.clear();
        in.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    CMatrix tam(d, c);
    for (int i = 0; i < tam.dong; i++) {
        for (int j = 0; j < tam.cot; j++) {
            cout << "  Nhap phan tu [" << i << "][" << j << "]: ";
            while (!(in >> tam.duLieu[i][j])) {
                cout << "  [Loi] Ban phai nhap so. Nhap lai [" << i << "][" << j << "]: ";
                in.clear();
                in.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }
    }
    m = tam;
    return in;
}

ostream& operator<<(ostream& out, const CMatrix& m) {
    if (m.dong == 0 || m.cot == 0) {
        out << "(Ma tran rong)";
        return out;
    }
    out << endl;
    for (int i = 0; i < m.dong; i++) {
        out << "  [ ";
        for (int j = 0; j < m.cot; j++) {
            out << m.duLieu[i][j];
            if (j < m.cot - 1) out << "\t";
        }
        out << " ]" << endl;
    }
    return out;
}