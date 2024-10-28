#include "TamGiac.h"
#include <iostream>
#include <cmath> // Thư viện để sử dụng hàm toán học như cos và sin
#define PI 3.14 // Định nghĩa hằng số PI
using namespace std;

// Phương thức để nhập tọa độ cho 3 đỉnh của tam giác
void TamGiac::Nhap() {
    cout << "Nhap toa do 3 diem cua tam giac: ";
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3; // Nhập tọa độ của 3 đỉnh
}

// Phương thức để xuất tọa độ của tam giác
void TamGiac::Xuat() {
    cout << "Toa do 3 diem cua tam giac sau khi tinh tien: \n";
    cout << "Diem thu nhat: (" << x1 << "," << y1 << ")\n"; // Xuất tọa độ đỉnh 1
    cout << "Diem thu hai: (" << x2 << "," << y2 << ")\n";  // Xuất tọa độ đỉnh 2
    cout << "Diem thu ba: (" << x3 << "," << y3 << ")\n";   // Xuất tọa độ đỉnh 3
}

// Phương thức để dịch chuyển tam giác
void TamGiac::TinhTien(float goc, float d) {
    float radian = goc * PI / 180; // Chuyển đổi góc từ độ sang radian
    float dx = d * cos(radian);    // Tính biến dịch chuyển theo trục x
    float dy = d * sin(radian);     // Tính biến dịch chuyển theo trục y

    // Cập nhật tọa độ của các đỉnh sau khi dịch chuyển
    x1 += dx;
    y1 += dy;
    x2 += dx;
    y2 += dy;
    x3 += dx;
    y3 += dy;
}
