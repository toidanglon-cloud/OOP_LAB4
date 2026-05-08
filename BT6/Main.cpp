#include <iostream>
#include "CVector.h"

using namespace std;

int main() {
    CVector v1, v2;
    double heSo;

    cout << "NHAP VECTOR 1" << endl;
    cin >> v1;

    cout << "\nNHAP VECTOR 2" << endl;
    cin >> v2;

   
    cout << "Vector 1: " << v1 << endl;
    cout << "Vector 2: " << v2 << endl;

    cout << "Phep cong (v1 + v2) = " << v1 + v2 << endl;
    cout << "Phep tru  (v1 - v2) = " << v1 - v2 << endl;
    cout << "Tich vo huong (v1 * v2) = " << v1 * v2 << endl;

    cout << "Nhap mot so thuc k de nhan: ";
    cin >> heSo;
    cout << "v1 * " << heSo << " = " << v1 * heSo << endl;
    cout << heSo << " * v2 = " << heSo * v2 << endl;

    if (v1 == v2) cout << "v1 va v2 GIONG NHAU hoan toan." << endl;
    else cout << "v1 va v2 KHAC NHAU." << endl;


    return 0;
}