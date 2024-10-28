#include "TamGiac.h"
#include <iostream>
#include <cmath>
#define PI 3.14
using namespace std;

int main() {
    TamGiac P; // Tạo một đối tượng tam giác
    P.Nhap(); // Nhập tọa độ cho tam giác từ người dùng

    float goc, d; // Khai báo biến để lưu góc và độ dài dịch chuyển
    cout << "Nhap huong tinh tien: "; cin >> goc; // Nhập góc dịch chuyển
    cout << "Nhap do dai tinh tien: "; cin >> d;  // Nhập độ dài dịch chuyển

    P.TinhTien(goc, d); // Dịch chuyển tam giác theo góc và độ dài đã nhập
    P.Xuat(); // Xuất tọa độ của tam giác sau khi dịch chuyển

    return 0; // Kết thúc chương trình
}
