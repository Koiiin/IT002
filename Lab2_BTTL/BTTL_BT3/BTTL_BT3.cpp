#include "Diem.h"      
#include "DaGiac.h"    
#include <iostream>
using namespace std;

int main() {
    DaGiac p; // Khởi tạo một đối tượng đa giác

    // Nhập tọa độ các đỉnh của đa giác
    p.Nhap();

    // Xuất tọa độ của đa giác sau khi nhập
    cout << "Da giac sau khi nhap:\n";
    p.Xuat();

    // Nhập đơn vị tịnh tiến
    float dx, dy;
    cout << "Nhap don vi muon tinh tien (x, y): "; 
    cin >> dx >> dy;
    p.TinhTien(dx, dy); // Tịnh tiến đa giác
    cout << "\nDa giac sau khi tinh tien (" << dx << "," << dy <<"): \n";
    p.Xuat();

    // Nhập tỷ lệ phóng to
    float TL;
    cout << "Nhap ti le muon phong to: "; 
    cin >> TL;
    p.PhongTo(TL); // Phóng to đa giác
    cout << "\nDa giac sau khi phong to (ti le " << TL << "):\n";
    p.Xuat();

    // Nhập tỷ lệ thu nhỏ
    cout << "Nhap ti le muon thu nho: ";
    cin >> TL;
    p.ThuNho(TL); // Thu nhỏ đa giác
    cout << "\nDa giac sau khi thu nho (ti le " << TL << "):\n";
    p.Xuat();

    // Nhập góc quay
    float goc_quay;
    cout << "Nhap goc quay: "; 
    cin >> goc_quay;
    p.Quay(goc_quay); // Quay đa giác
    cout << "\nDa giac sau khi quay " << goc_quay << " do:\n";
    p.Xuat();

    return 0;
}
