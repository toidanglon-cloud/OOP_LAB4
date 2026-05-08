#include "CTime.h"
#include <iomanip>
#include <limits>

void CTime::chuanHoa() {
    long tongGiay = h * 3600 + m * 60 + s;
    if (tongGiay < 0) {
        tongGiay = (tongGiay % 86400) + 86400;
    }
    tongGiay = tongGiay % 86400;

    h = tongGiay / 3600;
    tongGiay %= 3600;
    m = tongGiay / 60;
    s = tongGiay % 60;
}

CTime::CTime(int gio, int phut, int giay) {
    h = gio;
    m = phut;
    s = giay;
    chuanHoa();
}

CTime operator+(const CTime& t, int giay) {
    return CTime(t.h, t.m, t.s + giay);
}

CTime operator+(int giay, const CTime& t) {
    return CTime(t.h, t.m, t.s + giay);
}

CTime operator-(const CTime& t, int giay) {
    return CTime(t.h, t.m, t.s - giay);
}

CTime& CTime::operator++() {
    s++;
    chuanHoa();
    return *this;
}

CTime CTime::operator++(int) {
    CTime tam = *this;
    s++;
    chuanHoa();
    return tam;
}

CTime& CTime::operator--() {
    s--;
    chuanHoa();
    return *this;
}

CTime CTime::operator--(int) {
    CTime tam = *this;
    s--;
    chuanHoa();
    return tam;
}

istream& operator>>(istream& in, CTime& t) {
    cout << "  Nhap gio: ";
    while (!(in >> t.h)) {
        cout << "  [Loi] Nhap sai. Nhap lai gio: ";
        in.clear();
        in.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cout << "  Nhap phut: ";
    while (!(in >> t.m)) {
        cout << "  [Loi] Nhap sai. Nhap lai phut: ";
        in.clear();
        in.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cout << "  Nhap giay: ";
    while (!(in >> t.s)) {
        cout << "  [Loi] Nhap sai. Nhap lai giay: ";
        in.clear();
        in.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    t.chuanHoa();
    return in;
}

ostream& operator<<(ostream& out, const CTime& t) {
    out << setfill('0') << setw(2) << t.h << ":"
        << setfill('0') << setw(2) << t.m << ":"
        << setfill('0') << setw(2) << t.s;
    return out;
}