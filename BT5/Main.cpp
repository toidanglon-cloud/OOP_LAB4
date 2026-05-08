#include <iostream>
#include "DaThuc.h"

using namespace std;

int main() {
    DaThuc dt1, dt2;

    cout << "NHAP DA THUC 1 "<<endl ;
    cin >> dt1;

    cout << "\nNHAP DA THUC 2" ;
    cin >> dt2;
  
    cout << "Da thuc 1: " << dt1 << endl;
    cout << "Da thuc 2: " << dt2 << endl;

    cout << "\nPhep cong: " << dt1 + dt2 << endl;
    cout << "Phep tru : " << dt1 - dt2 << endl;
    cout << "Phep nhan: " << dt1 * dt2 << endl;

    return 0;
}