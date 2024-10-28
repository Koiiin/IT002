#include "Diem.h"
#include <iostream>
using namespace std;

// Constructor mặc định
Diem::Diem() : x(0), y(0) {
    // Khởi tạo tọa độ (x, y) của điểm với giá trị mặc định (0, 0)
}

// Constructor có tham số
Diem::Diem(float x_val, float y_val) : x(x_val), y(y_val) {
    // Khởi tạo tọa độ (x, y) của điểm với giá trị được cung cấp
}

// Hàm nhập tọa độ
void Diem::Nhap() {
    cout << "Nhap toa do (x, y): "; // In thông báo yêu cầu nhập tọa độ
    cin >> x >> y;                // Nhập giá trị x và y từ người dùng
}

// Hàm xuất tọa độ
void Diem::Xuat() const {
    cout << "(" << x << ", " << y << ")"; // In ra tọa độ của điểm theo định dạng (x, y)
}
