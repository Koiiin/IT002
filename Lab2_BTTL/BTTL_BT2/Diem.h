#ifndef DIEM_H
#define DIEM_H

#include <iostream>
using namespace std;

// Lớp Diem đại diện cho một điểm trong không gian 2D với tọa độ (x, y)
class Diem {
public:
    float x; // Tọa độ x của điểm
    float y; // Tọa độ y của điểm

    // Constructor mặc định: Khởi tạo điểm với tọa độ (0, 0)
    Diem();

    // Constructor có tham số: Khởi tạo điểm với tọa độ (x_val, y_val)
    Diem(float x_val, float y_val);

    // Hàm nhập tọa độ điểm từ người dùng
    void Nhap();

    // Hàm xuất tọa độ điểm ra màn hình
    void Xuat() const;
};

#endif
