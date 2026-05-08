#include <iostream>
#include <iomanip>
#include "CDate.h"

using namespace std;

int main() {
    CDate ngayGui, ngayRut;
    double soTienGui, laiSuatNam, tienLai;

    cout << "1. Nhap ngay gui tien:" << endl;
    cin >> ngayGui;

    do {
        cout << "\n2. Nhap ngay rut tien:" << endl;
        cin >> ngayRut;

        if (ngayRut < ngayGui) {
            cout << "  [Loi] Ngay rut tien phai xay ra SAU hoac BANG ngay gui! Vui long nhap lai.\n";
        }
    } while (ngayRut < ngayGui);

    cout << "\n3. Nhap so tien gui (VND): ";
    cin >> soTienGui;

    cout << "4. Nhap lai suat nam (%): ";
    cin >> laiSuatNam;

    int soNgayGui = ngayRut - ngayGui;

    tienLai = soTienGui * (laiSuatNam / 100.0) * (soNgayGui / 365.0);
    cout << "Ngay gui: " << ngayGui << endl;
    cout << "Ngay rut: " << ngayRut << endl;
    cout << "Khoang cach: " << soNgayGui << " ngay" << endl;

    cout << fixed << setprecision(0);
    cout << "So tien goc: " << soTienGui << " VND" << endl;
    cout << "Tien lai: " << tienLai << " VND" << endl;
    cout << "Tong nhan: " << soTienGui + tienLai << " VND" << endl;

    return 0;
}