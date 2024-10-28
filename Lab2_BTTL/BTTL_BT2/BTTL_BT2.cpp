#include "TamGiac.h"
#include "Diem.h"
#include <iostream>
#include <cmath>

int main() {
    TamGiac t;                // Tạo đối tượng TamGiac
    t.Nhap();                 // Nhập thông tin cho tam giác từ người dùng

    // Xuất thông tin tam giác sau khi nhập
    cout << "Tam giac sau khi nhap:\n";
    t.Xuat();                 // In ra thông tin của tam giác

    // Tính tiền cho tam giác
    t.TinhTien(2, 3);         // Dịch chuyển tam giác theo vector (2, 3)
    cout << "\nTam giac sau khi tinh tien (2, 3):\n";
    t.Xuat();                 // In ra thông tin của tam giác sau khi dịch chuyển

    // Phóng to tam giác
    cout << "Mhap ti le phong to: ";
    float TiLe_PT;
    cin >> TiLe_PT;           // Nhập tỷ lệ phóng to từ người dùng
    t.PhongTo(TiLe_PT);       // Phóng to tam giác theo tỷ lệ đã nhập
    cout << "\nTam giac sau khi phong to (ti le " << TiLe_PT << "):\n";
    t.Xuat();                 // In ra thông tin của tam giác sau khi phóng to

    // Thu nhỏ tam giác
    cout << "Nhap ti le thu nho: ";
    float TiLe_TN;
    cin >> TiLe_TN;           // Nhập tỷ lệ thu nhỏ từ người dùng
    t.ThuNho(TiLe_TN);        // Thu nhỏ tam giác theo tỷ lệ đã nhập
    cout << "\nTam giac sau khi thu nho (tỉ lệ " << TiLe_TN << "):\n";
    t.Xuat();                 // In ra thông tin của tam giác sau khi thu nhỏ

    // Quay tam giác
    float goc_quay;
    cout << "Nhap goc quay: "; 
    cin >> goc_quay;          // Nhập góc quay từ người dùng
    t.Quay(goc_quay);         // Quay tam giác theo góc đã nhập
    cout << "\nTam giac sau khi quay: \n";
    t.Xuat();                 // In ra thông tin của tam giác sau khi quay

    return 0;                 // Kết thúc chương trình
}
