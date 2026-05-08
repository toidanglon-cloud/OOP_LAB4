#include "CDate.h"
#include <iomanip>
#include <limits>
#include <cmath>

bool CDate::laNamNhuan(int y) const {
    return (y % 400 == 0) || (y % 4 == 0 && y % 100 != 0);
}

int CDate::soNgayTrongThang(int m, int y) const {
    switch (m) {
    case 4: case 6: case 9: case 11:
        return 30;
    case 2:
        return laNamNhuan(y) ? 29 : 28;
    default:
        return 31;
    }
}

void CDate::chuanHoa() {
    while (thang > 12) {
        nam++;
        thang -= 12;
    }
    while (thang <= 0) {
        nam--;
        thang += 12;
    }

    while (ngay > soNgayTrongThang(thang, nam)) {
        ngay -= soNgayTrongThang(thang, nam);
        thang++;
        if (thang > 12) {
            thang = 1;
            nam++;
        }
    }

    while (ngay <= 0) {
        thang--;
        if (thang <= 0) {
            thang = 12;
            nam--;
        }
        ngay += soNgayTrongThang(thang, nam);
    }
}

int CDate::tinhKhoangCachNgay() const {
    int days = ngay;
    for (int i = 1; i < thang; i++) {
        days += soNgayTrongThang(i, nam);
    }
    int y = nam - 1;
    days += y * 365 + y / 4 - y / 100 + y / 400;
    return days;
}

CDate::CDate(int d, int m, int y) {
    ngay = d;
    thang = m;
    nam = y;
    if (nam <= 0) nam = 1;
    chuanHoa();
}

CDate operator+(const CDate& d, int n) {
    CDate kq = d;
    kq.ngay += n;
    kq.chuanHoa();
    return kq;
}

CDate operator+(int n, const CDate& d) {
    return d + n;
}

CDate operator-(const CDate& d, int n) {
    CDate kq = d;
    kq.ngay -= n;
    kq.chuanHoa();
    return kq;
}

int operator-(const CDate& a, const CDate& b) {
    return abs(a.tinhKhoangCachNgay() - b.tinhKhoangCachNgay());
}

CDate& CDate::operator++() {
    ngay++;
    chuanHoa();
    return *this;
}

CDate CDate::operator++(int) {
    CDate tam = *this;
    ngay++;
    chuanHoa();
    return tam;
}

CDate& CDate::operator--() {
    ngay--;
    chuanHoa();
    return *this;
}

CDate CDate::operator--(int) {
    CDate tam = *this;
    ngay--;
    chuanHoa();
    return tam;
}

istream& operator>>(istream& in, CDate& d) {
    bool hopLe = false;
    while (!hopLe) {
        cout << "  Nhap nam (nam > 0): ";
        while (!(in >> d.nam) || d.nam <= 0) {
            cout << "  [Loi] Nam phai la so nguyen duong. Nhap lai nam: ";
            in.clear();
            in.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        cout << "  Nhap thang (1-12): ";
        while (!(in >> d.thang) || d.thang < 1 || d.thang > 12) {
            cout << "  [Loi] Thang khong hop le. Nhap lai thang: ";
            in.clear();
            in.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        cout << "  Nhap ngay: ";
        while (!(in >> d.ngay)) {
            cout << "  [Loi] Ban phai nhap so. Nhap lai ngay: ";
            in.clear();
            in.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        int ngayToiDa = d.soNgayTrongThang(d.thang, d.nam);
        if (d.ngay < 1 || d.ngay > ngayToiDa) {
            cout << "  [Loi] Thang " << d.thang << "/" << d.nam
                << " chi co " << ngayToiDa << " ngay! Vui long nhap lai tu dau.\n\n";
        }
        else {
            hopLe = true;
        }
    }
    return in;
}

ostream& operator<<(ostream& out, const CDate& d) {
    out << setfill('0') << setw(2) << d.ngay << "/"
        << setfill('0') << setw(2) << d.thang << "/"
        << setfill('0') << setw(4) << d.nam;
    return out;
}
bool operator<(const CDate& a, const CDate& b) {
    return a.tinhKhoangCachNgay() < b.tinhKhoangCachNgay();
}