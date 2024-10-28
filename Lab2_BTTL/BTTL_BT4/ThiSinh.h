#ifndef THISINH_H
#define THISINH_H

#include <iostream>
#include <string>
using namespace std;

// Lớp ThiSinh đại diện cho một thí sinh với các thuộc tính và phương thức liên quan.
class ThiSinh {
private:
    string Ten;     // Tên thí sinh
    int MSSV;       // Mã số sinh viên
    int iNgay;      // Ngày sinh
    int iThang;     // Tháng sinh
    int iNam;       // Năm sinh
    float fToan;    // Điểm môn Toán
    float fVan;     // Điểm môn Văn
    float fAnh;     // Điểm môn Anh

public:
    // Hàm khởi tạo mặc định
    ThiSinh();

    // Hàm khởi tạo với tham số
    // Đầu vào: tên, mã số sinh viên, ngày, tháng, năm sinh, và điểm của các môn
    // Đầu ra: Khởi tạo một đối tượng ThiSinh với các thuộc tính được chỉ định
    ThiSinh(string ten, int id, int dd, int mm, int yy, float Toan, float Van, float Anh);

    // Hàm khởi tạo sao chép
    // Đầu vào: một đối tượng ThiSinh
    // Đầu ra: Tạo một bản sao của đối tượng ThiSinh
    ThiSinh(const ThiSinh& ts);

    // Nhập thông tin thí sinh từ người dùng
    // Đầu vào: không có
    // Đầu ra: Thông tin thí sinh được lưu vào các thuộc tính của đối tượng
    void Nhap();

    // Xuất thông tin thí sinh ra màn hình
    // Đầu vào: không có
    // Đầu ra: Thông tin thí sinh được in ra màn hình
    void Xuat();

    // Tính tổng điểm của các môn
    // Đầu vào: không có
    // Đầu ra: Tổng điểm (float) của các môn Toán, Văn và Anh
    float Tong();
};

#endif // !THISINH_H
