#include <iostream>
#include <windows.h>
#include "CTime.h"

using namespace std;

void anConTro() {
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO info;
    info.dwSize = 100;
    info.bVisible = FALSE;
    SetConsoleCursorInfo(consoleHandle, &info);
}

void inGocPhai(const CTime& t) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(hConsole, &csbi);

    int chieuRong = csbi.srWindow.Right - csbi.srWindow.Left + 1;

    COORD c;
    c.X = chieuRong - 8;
    c.Y = 0;

    SetConsoleCursorPosition(hConsole, c);
    cout << t;
}

int main() {
    CTime t;
    int giayThem;

    cin >> t;

    cout << "\nThoi gian hien tai: " << t << endl;

    cout << "Nhap so giay muon cong/tru: ";
    cin >> giayThem;

    cout << t << " + " << giayThem << "s = " << t + giayThem << endl;
    cout << t << " - " << giayThem << "s = " << t - giayThem << endl;

    cout << "\nTest ++t (Tien to): " << ++t << endl;
    cout << "Test --t (Tien to): " << --t << endl;

    cout << "\nNhan Enter de bat dau dong ho o goc tren ben phai...";
    cin.ignore();
    cin.get();

    system("cls");
    anConTro();

    while (true) {
        inGocPhai(t);
        t++;
        Sleep(1000);
    }

    return 0;
}