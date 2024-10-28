#include "ThiSinh.h"
#include <iostream>
#include <string>
using namespace std;

// Hàm khởi tạo mặc định
ThiSinh::ThiSinh() 
    : Ten(""), MSSV(23520000), iNgay(0), iThang(0), iNam(0), fToan(0.0), fVan(0.0), fAnh(0.0) {}

// Hàm khởi tạo với tham số
// Đầu vào: tên thí sinh, mã số sinh viên, ngày, tháng, năm sinh, và điểm của các môn
// Đầu ra: Khởi tạo một đối tượng ThiSinh với các thuộc tính được chỉ định
ThiSinh::ThiSinh(string name, int id, int dd, int mm, int yy, float Toan, float Van, float Anh) 
    : Ten(name), MSSV(id), iNgay(dd), iThang(mm), iNam(yy), fToan(Toan), fVan(Van), fAnh(Anh) {}

// Hàm khởi tạo sao chép
// Đầu vào: một đối tượng ThiSinh
// Đầu ra: Tạo một bản sao của đối tượng ThiSinh
ThiSinh::ThiSinh(const ThiSinh& ts) {
    Ten = ts.Ten;
    MSSV = ts.MSSV;
    iNgay = ts.iNgay;
    iThang = ts.iThang;
    iNam = ts.iNam;
    fToan = ts.fToan;
    fVan = ts.fVan;
    fAnh = ts.fAnh;
}

// Nhập thông tin thí sinh từ người dùng
// Đầu vào: không có
// Đầu ra: Thông tin thí sinh được lưu vào các thuộc tính của đối tượng
void ThiSinh::Nhap() {
    cout << "Nhap ho va ten: ";
    getline(cin, Ten);  // Nhập tên thí sinh
    cout << "Nhap MSSV: ";
    cin >> MSSV;        // Nhập mã số sinh viên
    cout << "Nhap ngay sinh (dd mm yy): ";
    cin >> iNgay >> iThang >> iNam;  // Nhập ngày, tháng, năm sinh
    cout << "Nhap diem Toan: "; cin >> fToan;  // Nhập điểm môn Toán
    cout << "Nhap diem Van: "; cin >> fVan;    // Nhập điểm môn Văn
    cout << "Nhap diem Anh: "; cin >> fAnh;     // Nhập điểm môn Anh
    cin.ignore();  // Xóa ký tự newline trong bộ đệm
}

// Xuất thông tin thí sinh ra màn hình
// Đầu vào: không có
// Đầu ra: Thông tin thí sinh được in ra màn hình
void ThiSinh::Xuat() {
    cout << "Ho va Ten: " << Ten << '\n';
    cout << "MSSV: " << MSSV << '\n';
    cout << "Ngay sinh: " << iNgay << "/" << iThang << "/" << iNam << '\n';
    cout << "Diem Toan: " << fToan << '\n';
    cout << "Diem Van: " << fVan << '\n';
    cout << "Diem Anh: " << fAnh << '\n';
    cout << "Tong diem: " << Tong() << '\n';  // In tổng điểm
}

// Tính tổng điểm của các môn
// Đầu vào: không có
// Đầu ra: Tổng điểm (float) của các môn Toán, Văn và Anh
float ThiSinh::Tong() { 
    return fToan + fVan + fAnh;  // Sửa lỗi: fVan -> fAnh
}
