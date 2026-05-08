#include <iostream>
#include "PhanSo.h"

using namespace std;

int main() {
    PhanSo ps1, ps2;
    int soNguyen;

    cout << "Nhap phan so thu 1:" << endl;
    cin >> ps1;

    cout << "\nNhap phan so thu 2:" << endl;
    cin >> ps2;

    cout << "\n=> So lieu da nhap: \n   ps1 = " << ps1 << "\n   ps2 = " << ps2 << endl;

    cout << "Phep cong: " << ps1 + ps2 << endl;
    cout << "Phep tru : " << ps1 - ps2 << endl;
    cout << "Phep nhan: " << ps1 * ps2 << endl;

    cout << "Phep chia: ";
    if (ps2 == PhanSo(0, 1)) {
        cout << "[Loi] Khong the chia cho 0!" << endl;
    }
    else {
        cout << ps1 / ps2 << endl;
    }

    if (ps1 == ps2) cout << "ps1 bang ps2" << endl;
    if (ps1 > ps2)  cout << "ps1 lon hon ps2" << endl;
    if (ps1 < ps2)  cout << "ps1 nho hon ps2" << endl;

    cout << "Nhap mot so nguyen bat ky: ";
    cin >> soNguyen;

    cout << "ps1 + " << soNguyen << " = " << ps1 + soNguyen << endl;
    cout << soNguyen << " + ps1 = " << soNguyen + ps1 << endl;

    return 0;
}