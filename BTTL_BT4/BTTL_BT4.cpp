#include "Date.h"
#include <iostream>
using namespace std;

/**
 * @brief Chuong trinh minh hoa cach su dung lop Date de thuc hien cac phep tinh tren ngay thang nam.
 *
 * @details Chuong trinh tao ra 3 doi tuong Date: dt1, dt2, va dt3.
 * Ban dau, dt1 duoc khoi tao voi gia tri mac dinh (1/1/2024),
 * dt2 duoc khoi tao voi gia tri chi dinh (2005/12/22),
 * va dt3 se nhan gia tri tu nguoi dung.
 * Chuong trinh thuc hien cac chuc nang sau:
 * - In gia tri cua dt1 va dt2 luc khoi tao.
 * - Nhap vao so ngay can cong hoac tru, sau do thay doi gia tri cua dt1 va dt2 tuong ung.
 * - Tang dt1 len 1 ngay, giam dt2 xuong 1 ngay va in ra gia tri moi.
 * - So sanh dt1 va dt2 theo cac phep so sanh: ==, !=, >=, <=, >, < va in ket qua.
 * - Tinh khoang cach (so ngay) giua dt1 va dt2.
 *
 * @input Nhap vao so ngay can cong hoac tru, nhap ngay, thang, nam cho dt3.
 *
 * @output In ra gia tri cua cac doi tuong Date sau khi thuc hien cac phep toan
 * va ket qua cua cac phep so sanh, khoang cach giua dt1 va dt2.
 */

int main() {
    Date dt1;
    Date dt2(2005, 12, 22);
    Date dt3;

    cout << "Gia tri ban dau cua dt1: " << dt1 << endl;
    cout << "Gia tri ban dau cua dt2: " << dt2 << endl;
    cout << "Nhap ngay cho dt3 (ngay thang nam): \n";
    cin >> dt3;
    cout << "\nGia tri ban dau cua dt3: " << dt3 << endl;


    int day;
    cout << "\nNhap so ngay can cong hoac tru: ";
    cin >> day;

    dt1 = dt1 + day;
    cout << "\ndt1 sau khi cong " << day << " ngay: " << dt1 << endl;
    dt2 = dt2 - day;
    cout << "dt2 sau khi tru " << day << " ngay: " << dt2 << endl;

    ++dt1;
    cout << "\ndt1 sau khi tang 1 ngay: " << dt1 << endl;
    --dt2;
    cout << "dt2 sau khi giam 1 ngay: " << dt2 << endl;


    cout << "\nSo sanh dt1 va dt2:\n";
    cout << "dt1 == dt2: " << (dt1 == dt2 ? "true" : "false") << endl;
    cout << "dt1 != dt2: " << (dt1 != dt2 ? "true" : "false") << endl;
    cout << "dt1 >= dt2: " << (dt1 >= dt2 ? "true" : "false") << endl;
    cout << "dt1 <= dt2: " << (dt1 <= dt2 ? "true" : "false") << endl;
    cout << "dt1 > dt2: " << (dt1 > dt2 ? "true" : "false") << endl;
    cout << "dt1 < dt2: " << (dt1 < dt2 ? "true" : "false") << endl;

    int diff = dt2 - dt1;
    cout << "\nKhoang cach giua dt1 va dt2 (tinh bang ngay): " << diff << " ngay" << endl;

    return 0;
}
