#include "TamGiac.h"
#include <cmath>
#include <iostream>
using namespace std;

// Constructor mặc định
TamGiac::TamGiac() {}

// Nhập tọa độ các đỉnh tam giác
void TamGiac::Nhap() {
    cout << "Nhap toa do dinh A:\n"; A.Nhap(); // Nhập tọa độ cho đỉnh A
    cout << "Nhap toa do dinh B:\n"; B.Nhap(); // Nhập tọa độ cho đỉnh B
    cout << "Nhap toa do dinh C:\n"; C.Nhap(); // Nhập tọa độ cho đỉnh C
}

// Xuất tọa độ các đỉnh tam giác
void TamGiac::Xuat() const {
    cout << "Dinh A: "; A.Xuat(); cout << endl; // Xuất tọa độ đỉnh A
    cout << "Dinh B: "; B.Xuat(); cout << endl; // Xuất tọa độ đỉnh B
    cout << "Dinh C: "; C.Xuat(); cout << endl; // Xuất tọa độ đỉnh C
}

// Tịnh tiến tam giác
void TamGiac::TinhTien(float dx, float dy) {
    // Thực hiện tịnh tiến cho từng đỉnh của tam giác
    A.x += dx; A.y += dy; // Tịnh tiến đỉnh A
    B.x += dx; B.y += dy; // Tịnh tiến đỉnh B
    C.x += dx; C.y += dy; // Tịnh tiến đỉnh C
}

// Phóng to tam giác
void TamGiac::PhongTo(float k) {
    // Phóng to từng đỉnh của tam giác theo tỉ lệ k
    A.x *= k; A.y *= k; // Phóng to đỉnh A
    B.x *= k; B.y *= k; // Phóng to đỉnh B
    C.x *= k; C.y *= k; // Phóng to đỉnh C
}

// Thu nhỏ tam giác
void TamGiac::ThuNho(float k) {
    // Kiểm tra nếu k bằng 0 thì không thể thu nhỏ
    if (k == 0) {
        cout << "Khong the thu nho tam giac ve 0." << endl;
        return; // Trả về nếu k = 0
    }
    // Thu nhỏ từng đỉnh của tam giác theo tỉ lệ k
    A.x /= k; A.y /= k; // Thu nhỏ đỉnh A
    B.x /= k; B.y /= k; // Thu nhỏ đỉnh B
    C.x /= k; C.y /= k; // Thu nhỏ đỉnh C
}

// Quay tam giác quanh gốc tọa độ
void TamGiac::Quay(float goc) {
    // Chuyển đổi góc từ độ sang radian
    float radian = goc * 3.14 / 180.0; 
    float cosTheta = cos(radian); // Tính cos của góc
    float sinTheta = sin(radian); // Tính sin của góc

    // Hàm lambda để quay một điểm
    auto quayDiem = [cosTheta, sinTheta](Diem& p) {
        // Tính tọa độ mới sau khi quay
        float x_new = p.x * cosTheta - p.y * sinTheta;
        float y_new = p.x * sinTheta + p.y * cosTheta;
        p.x = x_new; // Cập nhật tọa độ x
        p.y = y_new; // Cập nhật tọa độ y
    };

    // Quay từng đỉnh của tam giác
    quayDiem(A); // Quay đỉnh A
    quayDiem(B); // Quay đỉnh B
    quayDiem(C); // Quay đỉnh C
}
