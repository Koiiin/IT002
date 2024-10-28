#include "Diem.h" // Bao gồm tệp tiêu đề của lớp Diem
#include <iostream>
using namespace std;

// Constructor mặc định
/**
 * @brief Constructor mặc định, khởi tạo tọa độ x và y bằng 0.
 */
Diem::Diem() : x(0), y(0) {}

// Constructor có tham số
/**
 * @brief Constructor khởi tạo tọa độ x và y với giá trị được cung cấp.
 * @param x_value Giá trị tọa độ x.
 * @param y_value Giá trị tọa độ y.
 */
Diem::Diem(float x_value, float y_value) : x(x_value), y(y_value) {}

// Hàm nhập tọa độ
/**
 * @brief Nhập tọa độ từ người dùng.
 * @details Hàm này yêu cầu người dùng nhập giá trị cho tọa độ x và y.
 */
void Diem::Nhap() {
    cout << "Nhap toa do: ";
    cin >> x >> y; // Nhập giá trị x và y từ người dùng
}

// Hàm xuất tọa độ
/**
 * @brief Xuất tọa độ ra màn hình.
 * @details Hàm này in ra tọa độ x và y của điểm theo định dạng "(x, y)".
 */
void Diem::Xuat() const {
    cout << "(" << x << "," << y << ")\n"; // Xuất tọa độ ra màn hình
}
