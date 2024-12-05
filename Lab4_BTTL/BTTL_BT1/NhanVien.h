#ifndef NHANVIEN_H
#define NHANVIEN_H

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class NhanVien {
protected:
    string NhanVien_ID;
    string TenNhanVien; 
    double LuongCoBan;
public:
    NhanVien();
    NhanVien(string ID, string Name, double Luong);
    virtual ~NhanVien(); 

    virtual void Nhap();
    virtual void Xuat() const;
    virtual double TienThuong() const = 0; 
};

#endif // NHANVIEN_H
