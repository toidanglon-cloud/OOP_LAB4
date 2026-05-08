#include <iostream>
#include "SoPhuc.h"

using namespace std;

int main() {
    SoPhuc sp1, sp2;
    double soThuc;

    cout << "Nhap so phuc thu 1: " << endl;
    cin >> sp1;

    cout << "\nNhap so phuc thu 2:" << endl;
    cin >> sp2;

    cout << "\n=> So lieu da nhap: \n   sp1 = " << sp1 << "\n   sp2 = " << sp2 << endl;

    cout << "Phep cong (sp1 + sp2) = " << sp1 + sp2 << endl;
    cout << "Phep tru  (sp1 - sp2) = " << sp1 - sp2 << endl;
    cout << "Phep nhan (sp1 * sp2) = " << sp1 * sp2 << endl;

    cout << "Phep chia (sp1 / sp2) = ";
    if (sp2 != SoPhuc(0, 0)) {
        SoPhuc kqChia = sp1 / sp2;
        cout << kqChia << endl;
    }
    else {
        cout << "[Loi] Khong the chia vi mau so bang 0." << endl;
    }

    cout << "\nNhap mot so bat ky: ";
    cin >> soThuc;

    cout << "Lay sp1 cong " << soThuc << " (sp1 nam ben trai): " << sp1 + soThuc << endl;
    cout << "Lay " << soThuc << " cong sp1 (sp1 nam ben phai): " << soThuc + sp1 << endl;

    return 0;
}