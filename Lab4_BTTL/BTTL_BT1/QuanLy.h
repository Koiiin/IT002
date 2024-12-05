#ifndef QUANLY_H
#define QUANLY_H

#include "NhanVien.h"

class QuanLy : public NhanVien {
private:
    double TyLeThuong;
public:
    QuanLy();
    QuanLy(string ID, string Name, double Luong, double Rate);
    ~QuanLy();

    void Nhap() override;
    void Xuat() const override;
    double TienThuong() const override;
};

#endif // QUANLY_H
