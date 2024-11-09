#include <iostream>
#include "PhanSo.h"

using namespace std;

/**
 * @brief Chuong trinh chinh de thuc hien cac phep toan tren cac doi tuong phan so va so nguyen
 * 
 * Chuong trinh nhap vao hai phan so a va b va mot so nguyen n, sau do thuc hien va in ra man hinh 
 * ket qua cua cac phep toan giua hai phan so, giua phan so va so nguyen, va cac phep so sanh.
 * 
 * Input: 
 * - Phan so a, b (tu so va mau so cua moi phan so)
 * - So nguyen n
 * 
 * Output: 
 * - Cac ket qua cua phep toan giua hai phan so
 * - Cac ket qua cua phep toan giua phan so va so nguyen
 * - Ket qua so sanh giua phan so va so nguyen, giua hai phan so
 */

int main() {
    PhanSo a, b;    // Khai bao doi tuong phan so a va b
    double n;       // Khai bao bien so nguyen n kieu double de thuc hien phep toan voi phan so

    // Nhap vao phan so a tu ban phim
    cout << "Nhap phan so a (tu so va mau so): ";
    cin >> a;

    // Nhap vao phan so b tu ban phim
    cout << "Nhap phan so b (tu so va mau so): ";
    cin >> b;

    // Nhap vao so nguyen n tu ban phim
    cout << "Nhap so nguyen n: ";
    cin >> n;

    // Xuat thong tin phan so a, b va so nguyen n
    cout << "Phan so a: " << a << endl;
    cout << "Phan so b: " << b << endl;
    cout << "So nguyen n: " << n << endl;

    // Thuc hien cac phep toan giua hai phan so
    cout << "\n--- Phep toan giua hai phan so ---" << endl;
    cout << "a + b = " << a + b << endl;    // Phep cong giua a va b
    cout << "a - b = " << a - b << endl;    // Phep tru giua a va b
    cout << "a * b = " << a * b << endl;    // Phep nhan giua a va b
    cout << "a / b = " << a / b << endl;    // Phep chia giua a va b

    // Thuc hien cac phep toan giua phan so va so nguyen
    cout << "\n--- Phep toan giua phan so va so nguyen ---" << endl;
    cout << "a + n = " << a + n << endl;    // Phep cong giua phan so a va so nguyen n
    cout << "a - n = " << a - n << endl;    // Phep tru giua phan so a va so nguyen n
    cout << "a * n = " << a * n << endl;    // Phep nhan giua phan so a va so nguyen n
    cout << "a / n = " << a / n << endl;    // Phep chia giua phan so a va so nguyen n

    // Thuc hien cac phep so sanh giua phan so va so nguyen
    cout << "\n--- So sanh giua phan so va so nguyen ---" << endl;
    cout << "a == n: " << (a == n ? "true" : "false") << endl;   // So sanh bang giua a va n
    cout << "a != n: " << (a != n ? "true" : "false") << endl;   // So sanh khac nhau giua a va n
    cout << "a > n: " << (a > n ? "true" : "false") << endl;     // So sanh lon hon giua a va n
    cout << "a < n: " << (a < n ? "true" : "false") << endl;     // So sanh nho hon giua a va n
    cout << "a >= n: " << (a >= n ? "true" : "false") << endl;   // So sanh lon hon hoac bang giua a va n
    cout << "a <= n: " << (a <= n ? "true" : "false") << endl;   // So sanh nho hon hoac bang giua a va n

    // Thuc hien cac phep so sanh giua hai phan so
    cout << "\n--- So sanh giua hai phan so ---" << endl;
    cout << "a == b: " << (a == b ? "true" : "false") << endl;   // So sanh bang giua a va b
    cout << "a != b: " << (a != b ? "true" : "false") << endl;   // So sanh khac nhau giua a va b
    cout << "a < b: " << (a < b ? "true" : "false") << endl;     // So sanh nho hon giua a va b
    cout << "a > b: " << (a > b ? "true" : "false") << endl;     // So sanh lon hon giua a va b
    cout << "a <= b: " << (a <= b ? "true" : "false") << endl;   // So sanh nho hon hoac bang giua a va b
    cout << "a >= b: " << (a >= b ? "true" : "false") << endl;   // So sanh lon hon hoac bang giua a va b

    return 0;
}
