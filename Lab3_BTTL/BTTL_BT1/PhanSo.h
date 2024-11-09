#ifndef PHANSO_H
#define PHANSO_H

#include <iostream>
using namespace std;

/**
 * @class PhanSo
 * @brief Lớp đại diện cho phân số với tử và mẫu số, hỗ trợ các phép toán số học và so sánh phân số.
 */
class PhanSo {
private:
    double iTu;  ///< Tử số của phân số
    double iMau; ///< Mẫu số của phân số

    /**
     * @brief Hàm rút gọn phân số bằng cách chia cả tử và mẫu cho UCLN của chúng.
     * @note Hàm này không có đầu vào, chỉ thao tác trên dữ liệu thành viên của đối tượng.
     */
    void rutGon();

    /**
     * @brief Hàm tìm ước chung lớn nhất (GCD) của hai số.
     * @param a Số thứ nhất
     * @param b Số thứ hai
     * @return Ước chung lớn nhất của a và b
     */
    double gcd(double a, double b);

public:
    /**
     * @brief Hàm tạo mặc định, khởi tạo phân số với tử số là 0 và mẫu số là 1.
     */
    PhanSo();

    /**
     * @brief Hàm tạo phân số với tử và mẫu cụ thể.
     * @param Tu Tử số của phân số
     * @param Mau Mẫu số của phân số
     */
    PhanSo(double Tu, double Mau);

    /**
     * @brief Hàm tạo phân số với tử số cụ thể và mẫu số mặc định là 1.
     * @param Tu Tử số của phân số
     */
    PhanSo(double Tu);

    // Toán tử nhập và xuất
    /**
     * @brief Toán tử nhập >> để nhập phân số từ luồng.
     * @param is Luồng nhập
     * @param ps Đối tượng phân số cần nhập
     * @return Luồng nhập sau khi xử lý
     */
    friend istream& operator >> (istream& is, PhanSo& ps);

    /**
     * @brief Toán tử xuất << để xuất phân số ra luồng.
     * @param os Luồng xuất
     * @param ps Đối tượng phân số cần xuất
     * @return Luồng xuất sau khi xử lý
     */
    friend ostream& operator << (ostream& os, const PhanSo& ps);

    // Các toán tử số học
    PhanSo operator + (const PhanSo& a) const; ///< Cộng hai phân số
    friend PhanSo operator + (double a, const PhanSo& b); ///< Cộng phân số với số thực

    PhanSo operator - (const PhanSo& a) const; ///< Trừ hai phân số
    friend PhanSo operator - (double a, const PhanSo& b); ///< Trừ phân số với số thực

    PhanSo operator * (const PhanSo& a) const; ///< Nhân hai phân số
    friend PhanSo operator * (double a, const PhanSo& b); ///< Nhân phân số với số thực

    PhanSo operator / (const PhanSo& a) const; ///< Chia hai phân số
    friend PhanSo operator / (double a, const PhanSo& b); ///< Chia phân số với số thực

    // Các toán tử so sánh
    bool operator == (const PhanSo& a) const; ///< So sánh bằng hai phân số
    friend bool operator == (double a, const PhanSo& b); ///< So sánh bằng phân số và số thực

    bool operator != (const PhanSo& a) const; ///< So sánh khác nhau giữa hai phân số
    friend bool operator != (double a, const PhanSo& b); ///< So sánh khác nhau giữa phân số và số thực

    bool operator >= (const PhanSo& a) const; ///< So sánh lớn hơn hoặc bằng giữa hai phân số
    friend bool operator >= (double a, const PhanSo& b); ///< So sánh lớn hơn hoặc bằng giữa phân số và số thực

    bool operator <= (const PhanSo& a) const; ///< So sánh nhỏ hơn hoặc bằng giữa hai phân số
    friend bool operator <= (double a, const PhanSo& b); ///< So sánh nhỏ hơn hoặc bằng giữa phân số và số thực

    bool operator > (const PhanSo& a) const; ///< So sánh lớn hơn giữa hai phân số
    friend bool operator > (double a, const PhanSo& b); ///< So sánh lớn hơn giữa phân số và số thực

    bool operator < (const PhanSo& a) const; ///< So sánh nhỏ hơn giữa hai phân số
    friend bool operator < (double a, const PhanSo& b); ///< So sánh nhỏ hơn giữa phân số và số thực
};

#endif // !PHANSO_H
