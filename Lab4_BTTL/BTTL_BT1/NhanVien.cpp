#include "NhanVien.h"

NhanVien::NhanVien() : NhanVien_ID(""), TenNhanVien(""), LuongCoBan(0) {}
NhanVien::NhanVien(string ID, string Name, double Luong)
    : NhanVien_ID(ID), TenNhanVien(Name), LuongCoBan(Luong) {}

NhanVien::~NhanVien() {}

void NhanVien::Nhap() {
    cout << "Nhap ma nhan vien: ";
    cin >> NhanVien_ID;
    cin.ignore();
    cout << "Nhap ten nhan vien: ";
    getline(cin, TenNhanVien);
    cout << "Nhap luong co ban: ";
    cin >> LuongCoBan;
}

void NhanVien::Xuat() const {
    cout << "Ma nhan vien: " << NhanVien_ID << "\n";
    cout << "Ten nhan vien: " << TenNhanVien << "\n";
    cout << "Luong co ban: " << fixed << setprecision(2) << LuongCoBan << "\n";
}
