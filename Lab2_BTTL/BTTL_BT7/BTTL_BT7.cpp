#include "Diem.h"     // Nhúng tệp header của lớp Diem
#include "Polygon.h"  // Nhúng tệp header của lớp Polygon
#include <iostream>
#include <cmath>
using namespace std;

int main() {
    Polygon DaGiac; // Khởi tạo đối tượng DaGiac của lớp Polygon
    DaGiac.Nhap(); // Gọi phương thức Nhap để nhập tọa độ các đỉnh của đa giác
    cout << "Dien tich da giac: " << DaGiac.DienTich() << '\n'; // Tính và in ra diện tích đa giác
    return 0; // Trả về 0 để chỉ ra rằng chương trình đã chạy thành công
}
