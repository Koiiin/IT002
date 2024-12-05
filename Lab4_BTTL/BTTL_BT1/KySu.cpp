#include "KySu.h"

KySu::KySu() : NhanVien(), SoGioLamThem(0) {}

KySu::KySu(string ID, string Name, double Luong, double Time)
    : NhanVien(ID, Name, Luong), SoGioLamThem(Time) {}

KySu::~KySu() {}

void KySu::Nhap() {
    NhanVien::Nhap();
    cout << "Nhap so gio lam them: ";
    cin >> SoGioLamThem;
}

void KySu::Xuat() const {
    NhanVien::Xuat();
    cout << "So gio lam them: " << SoGioLamThem << "\n";
    cout << "Tien thuong: " << fixed << setprecision(2) << TienThuong() << "\n";
}

double KySu::TienThuong() const {
    return SoGioLamThem * 100000;
}
