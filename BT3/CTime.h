#ifndef CTIME_H
#define CTIME_H
#include <iostream>

using namespace std;

class CTime {
private:
    int h;
    int m;
    int s;

    void chuanHoa();

public:
    CTime(int gio = 0, int phut = 0, int giay = 0);

    friend CTime operator+(const CTime& t, int giay);
    friend CTime operator+(int giay, const CTime& t);
    friend CTime operator-(const CTime& t, int giay);

    CTime& operator++();
    CTime operator++(int);
    CTime& operator--();
    CTime operator--(int);

    friend istream& operator>>(istream& in, CTime& t);
    friend ostream& operator<<(ostream& out, const CTime& t);
};

#endif