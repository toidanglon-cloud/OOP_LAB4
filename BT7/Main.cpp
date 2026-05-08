#include <iostream>
#include "CMatrix.h"
#include "CVector.h"

using namespace std;

int main() {
    CMatrix mt1, mt2;
    CVector v1;

    cout << "NHAP MA TRAN 1" << endl;
    cin >> mt1;

    cout << "\nNHAP MA TRAN 2" << endl;
    cin >> mt2;

    cout << "\nNHAP VECTOR" << endl;
    cin >> v1;

    cout << "Ma tran 1:" << mt1 << endl;
    cout << "Ma tran 2:" << mt2 << endl;
    cout << "Vector: " << v1 << endl;

    cout << "Phep cong (mt1 + mt2):" << mt1 + mt2 << endl;
    cout << "Phep tru (mt1 - mt2):" << mt1 - mt2 << endl;
    cout << "Tich 2 ma tran (mt1 * mt2):" << mt1 * mt2 << endl;

    cout << "Tich ma tran 1 va vector (mt1 * v1) = " << mt1 * v1 << endl;


    return 0;
}