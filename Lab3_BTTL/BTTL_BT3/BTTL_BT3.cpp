#include <iostream>
#include "Time.h"
using namespace std;

/**
 * @brief Chuong trinh chinh de kiem thu cac phep toan va so sanh tren doi tuong ThoiGian.
 *
 * Chuong trinh nay se thuc hien nhap thoi gian tu nguoi dung, sau do thuc hien cac phep toan
 * cong tru giay, tang/giam thoi gian, so sanh giua hai doi tuong thoi gian, va hien thi ket qua.
 */
int main() {
    // Khoi tao doi tuong ThoiGian tg1 voi thoi gian mac dinh (0 gio, 0 phut, 0 giay)
    ThoiGian tg1;

    // Khoi tao doi tuong ThoiGian tg2 voi gia tri cu the (2 gio, 30 phut, 45 giay)
    ThoiGian tg2(2, 30, 45);

    // Khoi tao doi tuong ThoiGian tg3 voi gia tri bang doi tuong ThoiGian tg2
    ThoiGian tg3 = tg2;

    // Xuat thoi gian ban dau cua tg1, tg2 va tg3
    cout << "Thoi gian ban dau tg1: " << tg1 << endl;
    cout << "Thoi gian ban dau tg2: " << tg2 << endl;
    cout << "Thoi gian ban dau tg3: " << tg3 << endl;

    // Cong 1 gio (3600 giay) vao tg2 va xuat ket qua
    cout << "Sau khi cong 1 gio vao tg2: " << tg2 + 3600 << endl;

    // Tru 7200 giay vao tg2 va xuat ket qua
    cout << "Sau khi tru 7200 giay vao tg2: " << tg2 - 7200 << endl;

    // Nhap n (giay)
    int n;
    cout << "Nhap n giay: ";
    cin >> n;

    // Cong tg3 voi n va xuat ket qua
    cout << "Sau khi cong " << n << " giay vao tg3: " << tg3 + n << endl;

    // Tang tg1 len 1 giay va xuat ket qua
    tg1++;
    cout << "Tang 1 giay tg1: " << tg1 << endl;

    // Giam tg2 1 giay (truoc khi xuat) va xuat ket qua
    cout << "Giam 1 giay tg2: " << --tg2 << endl;

    // Nhap thoi gian tu nguoi dung cho tg1
    cout << "Nhap thoi gian cho tg1:" << endl;
    cin >> tg1;

    // Xuat thoi gian vua nhap cua tg1
    cout << "Thoi gian vua nhap: " << tg1 << endl;

    // Cong hai doi tuong tg1 va tg2, sau do xuat ket qua
    cout << "tg1 + tg2 = " << tg1 + tg2 << endl;

    // Tru tg2 cho tg1 va xuat ket qua
    cout << "tg2 - tg1 = " << tg2 - tg1 << endl;

    // So sanh hai doi tuong tg1 va tg2, xuat ket qua cho cac phep toan so sanh
    cout << "--- So sanh tg1 va tg2 ---\n";
    cout << "tg1 == tg2 : " << (tg1 == tg2 ? "true" : "false") << endl;
    cout << "tg1 != tg2 : " << (tg1 != tg2 ? "true" : "false") << endl;
    cout << "tg1 >= tg2 : " << (tg1 >= tg2 ? "true" : "false") << endl;
    cout << "tg1 <= tg2 : " << (tg1 <= tg2 ? "true" : "false") << endl;
    cout << "tg1 > tg2 : " << (tg1 > tg2 ? "true" : "false") << endl;
    cout << "tg1 < tg2 : " << (tg1 < tg2 ? "true" : "false") << endl;

    return 0;
}
