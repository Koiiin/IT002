#ifndef TAMGIAC_H
#define TAMGIAC_H

#include "Diem.h"

// Lớp TamGiac đại diện cho một tam giác trong không gian 2 chiều
class TamGiac {
private:
    Diem A, B, C; // Các đỉnh của tam giác

public:
    TamGiac(); // Constructor mặc định

    // Nhập tọa độ các đỉnh tam giác từ người dùng
    void Nhap();
    
    // Xuất tọa độ các đỉnh tam giác ra màn hình
    void Xuat() const;

    // Tịnh tiến tam giác theo vectơ (dx, dy)
    void TinhTien(float dx, float dy);
    
    // Phóng to tam giác theo tỉ lệ k
    void PhongTo(float k);
    
    // Thu nhỏ tam giác theo tỉ lệ k
    void ThuNho(float k);
    
    // Quay tam giác quanh gốc tọa độ theo góc goc (độ)
    void Quay(float goc);
};

#endif
