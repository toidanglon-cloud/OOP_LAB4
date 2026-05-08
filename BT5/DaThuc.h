#ifndef DATHUC_H
#define DATHUC_H
#include <iostream>

using namespace std;

class DaThuc {
private:
    int bac;
    double* heSo;
    void chuanHoa();

public:
    DaThuc(int b = 0);
    DaThuc(const DaThuc& other);
    ~DaThuc();
    DaThuc& operator=(const DaThuc& other);

    friend DaThuc operator+(const DaThuc& a, const DaThuc& b);
    friend DaThuc operator-(const DaThuc& a, const DaThuc& b);
    friend DaThuc operator*(const DaThuc& a, const DaThuc& b);

    friend istream& operator>>(istream& in, DaThuc& dt);
    friend ostream& operator<<(ostream& out, const DaThuc& dt);
};

#endif