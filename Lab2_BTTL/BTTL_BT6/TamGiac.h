#ifndef TAMGIAC_H
#define TAMGIAC_H

#include <iostream>
using namespace std;

class TamGiac {
private:
    float x1, y1; // Tọa độ đỉnh 1 của tam giác
    float x2, y2; // Tọa độ đỉnh 2 của tam giác
    float x3, y3; // Tọa độ đỉnh 3 của tam giác

public:
    // Phương thức để nhập tọa độ cho các đỉnh của tam giác
    void Nhap();

    // Phương thức để xuất tọa độ của tam giác
    void Xuat();

    // Phương thức để dịch chuyển tam giác
    void TinhTien(float goc, float d);
};

#endif // !TAMGIAC_H
