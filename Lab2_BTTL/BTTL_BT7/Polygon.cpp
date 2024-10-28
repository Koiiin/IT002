#include "Polygon.h" // Nhúng tệp header của lớp Polygon
#include "Diem.h" // Nhúng tệp header của lớp Diem
#include <iostream>
#include <cmath>
using namespace std;

// Constructor mặc định cho lớp Polygon
Polygon::Polygon() : Point(nullptr), n(3) {}

// Phương thức nhập tọa độ cho các đỉnh của đa giác
void Polygon::Nhap() {
    cout << "Nhap so luong dinh cua da giac (n > 2): "; // Yêu cầu người dùng nhập số lượng đỉnh
    cin >> n; // Đọc số lượng đỉnh

    // Kiểm tra xem số lượng đỉnh có hợp lệ không
    if (n < 3) {
        cout << "So dinh khong the nho hon 3."; // Thông báo lỗi nếu số lượng đỉnh không hợp lệ
        return; // Thoát khỏi phương thức
    }

    Point = new Diem[n]; // Cấp phát bộ nhớ cho mảng các đỉnh
    for (int i = 0; i < n; ++i) { // Vòng lặp nhập tọa độ cho từng đỉnh
        cout << "Nhap toa do dinh thu " << i + 1 << ": "; // Thông báo yêu cầu nhập tọa độ
        cin >> Point[i].x >> Point[i].y; // Đọc tọa độ cho đỉnh thứ i
    }
}

// Phương thức tính diện tích của đa giác sử dụng công thức Shoelace
float Polygon::DienTich() {
    float area = 0.0; // Khởi tạo biến diện tích
    for (int i = 0; i < n; ++i) { // Vòng lặp tính diện tích
        int next = (i + 1) % n; // Chỉ số của đỉnh tiếp theo
        area += (Point[i].x * Point[next].y) - (Point[next].x * Point[i].y); // Cộng diện tích
    }

    return fabs(area) / 2.0; // Trả về diện tích tuyệt đối chia 2
}

// Destructor để giải phóng bộ nhớ khi đối tượng Polygon bị hủy
Polygon::~Polygon() { delete[] Point; }
