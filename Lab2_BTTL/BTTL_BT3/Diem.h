#ifndef DIEM_H
#define DIEM_H

#include <iostream>
using namespace std;

/**
 * @class Diem
 * @brief Lớp đại diện cho một điểm trong không gian 2 chiều với tọa độ x và y.
 */
class Diem {
private:

public:
    float x; // Tọa độ x của điểm
    float y; // Tọa độ y của điểm

    /**
     * @brief Constructor mặc định, khởi tạo tọa độ x và y bằng 0.
     */
    Diem();

    /**
     * @brief Constructor với tham số, khởi tạo tọa độ x và y bằng giá trị cung cấp.
     * @param x_value Giá trị tọa độ x.
     * @param y_value Giá trị tọa độ y.
     */
    Diem(float x_value, float y_value);

    /**
     * @brief Nhập tọa độ từ người dùng.
     * @details Hàm này yêu cầu người dùng nhập giá trị cho tọa độ x và y.
     */
    void Nhap();

    /**
     * @brief Xuất tọa độ ra màn hình.
     * @details Hàm này in ra tọa độ x và y của điểm theo định dạng "(x, y)".
     */
    void Xuat() const;
};

#endif // !DIEM_H
