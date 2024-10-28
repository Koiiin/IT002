#include "Diem.h"       // Bao gồm tệp định nghĩa lớp Diem
#include "DaGiac.h"     // Bao gồm tệp định nghĩa lớp DaGiac
#include <iostream>
#include <cmath>
using namespace std;

// Constructor mặc định
DaGiac::DaGiac() : n(0), Dinh(nullptr) {} 

// Constructor có tham số
DaGiac::DaGiac(int soDinh) : n(soDinh) { 
    Dinh = new Diem[n]; // Khởi tạo mảng các đỉnh
}

// Destructor
DaGiac::~DaGiac() { 
    delete[] Dinh; // Giải phóng bộ nhớ
}

// Hàm nhập thông tin đa giác
void DaGiac::Nhap() {
    cout << "Nhap so dinh cua da giac: "; 
    cin >> n; // Nhập số lượng đỉnh
    Dinh = new Diem[n]; // Cấp phát bộ nhớ cho các đỉnh

    // Nhập tọa độ từng đỉnh
    for (int i = 0; i < n; ++i) {
        cout << "Nhap toa do dinh thu " << i + 1 << ": \n"; 
        Dinh[i].Nhap();
    }
}

// Hàm xuất tọa độ các đỉnh
void DaGiac::Xuat() const { 
    for (int i = 0; i < n; ++i) {
        cout << "Dinh thu " << i + 1 << ": ";
        Dinh[i].Xuat(); // Xuất tọa độ của đỉnh thứ i
        cout << '\n';
    }
}

// Hàm tịnh tiến đa giác
void DaGiac::TinhTien(float dX, float dY) { 
    for (int i = 0; i < n; ++i) {
        Dinh[i].x += dX; // Cập nhật tọa độ x
        Dinh[i].y += dY; // Cập nhật tọa độ y
    }
}

// Hàm phóng to đa giác
void DaGiac::PhongTo(float Tile) { 
    for (int i = 0; i < n; ++i) {
        Dinh[i].x *= Tile; // Cập nhật tọa độ x
        Dinh[i].y *= Tile; // Cập nhật tọa độ y
    }
}

// Hàm thu nhỏ đa giác
void DaGiac::ThuNho(float Tile) { 
    for (int i = 0; i < n; ++i) {
        Dinh[i].x /= Tile; // Cập nhật tọa độ x
        Dinh[i].y /= Tile; // Cập nhật tọa độ y
    }
}

// Hàm quay đa giác
void DaGiac::Quay(float goc) { 
    float radian = goc * 3.14 / 180; // Chuyển đổi góc từ độ sang radian
    float cosTheta = cos(radian);
    float sinTheta = sin(radian);

    // Tính tọa độ mới cho từng đỉnh sau khi quay
    for (int i = 0; i < n; ++i) {
        float x_new = Dinh[i].x * cosTheta - Dinh[i].y * sinTheta; // Tính tọa độ x mới
        float y_new = Dinh[i].x * sinTheta + Dinh[i].y * cosTheta; // Tính tọa độ y mới
        Dinh[i].x = x_new; // Cập nhật tọa độ x
        Dinh[i].y = y_new; // Cập nhật tọa độ y
    }
}
