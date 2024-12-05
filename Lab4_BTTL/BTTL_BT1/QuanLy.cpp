#include "QuanLy.h"

QuanLy::QuanLy() : NhanVien(), TyLeThuong(0) {}

QuanLy::QuanLy(string ID, string Name, double Luong, double Rate)
    : NhanVien(ID, Name, Luong), TyLeThuong(Rate) {}

QuanLy::~QuanLy() {}

void QuanLy::Nhap() {
    NhanVien::Nhap();
    cout << "Nhap ty le thuong: ";
    cin >> TyLeThuong;
}

void QuanLy::Xuat() const {
    NhanVien::Xuat();
    cout << "Ty le thuong: " << TyLeThuong << "%\n";
    cout << "Tien thuong: " << fixed << setprecision(2) << TienThuong() << "\n";
}

double QuanLy::TienThuong() const {
    return LuongCoBan * TyLeThuong / 100;
}
