#ifndef CDATE_H
#define CDATE_H
#include <iostream>

using namespace std;

class CDate {
private:
    int ngay;
    int thang;
    int nam;

    bool laNamNhuan(int y) const;
    int soNgayTrongThang(int m, int y) const;
    void chuanHoa();
    int tinhKhoangCachNgay() const;

public:
    CDate(int d = 1, int m = 1, int y = 1);

    friend CDate operator+(const CDate& d, int n);
    friend CDate operator+(int n, const CDate& d);
    friend CDate operator-(const CDate& d, int n);

    friend int operator-(const CDate& a, const CDate& b);
    friend bool operator<(const CDate& a, const CDate& b);

    CDate& operator++();
    CDate operator++(int);
    CDate& operator--();
    CDate operator--(int);

    friend istream& operator>>(istream& in, CDate& d);
    friend ostream& operator<<(ostream& out, const CDate& d);
};

#endif