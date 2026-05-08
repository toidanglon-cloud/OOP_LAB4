#ifndef SOPHUC_H
#define SOPHUC_H
#include <iostream>

using namespace std;

class SoPhuc {
private:
    double thuc;
    double ao;

public:
    SoPhuc(double r = 0, double i = 0);

    friend SoPhuc operator+(const SoPhuc& a, const SoPhuc& b);
    friend SoPhuc operator-(const SoPhuc& a, const SoPhuc& b);
    friend SoPhuc operator*(const SoPhuc& a, const SoPhuc& b);
    friend SoPhuc operator/(const SoPhuc& a, const SoPhuc& b);

    friend bool operator==(const SoPhuc& a, const SoPhuc& b);
    friend bool operator!=(const SoPhuc& a, const SoPhuc& b);

    friend istream& operator>>(istream& in, SoPhuc& sp);
    friend ostream& operator<<(ostream& out, const SoPhuc& sp);
};

#endif