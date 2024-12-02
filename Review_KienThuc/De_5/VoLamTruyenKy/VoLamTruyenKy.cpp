#include <iostream>
#include "DanhSachQuanLy.h"
#include "NguHanh.h"
#include "NhanVat.h"
#include "QuaiVat.h"
#include "QuaiVatDauLinh.h"
#include "QuaiVatThongThuong.h"
using namespace std;

int main() {
    DanhSachQuanLy ds;
    ds.Them(new NhanVat("VHK", "Thieu Lam", 20));
    ds.Them(new QuaiVatDauLinh(10, "Hoa"));
    ds.Them(new QuaiVatThongThuong(8, "Moc"));

    SinhVat* maxSatThuong = ds.SatThuong_Max();
    if (maxSatThuong) {
        cout << "Sinh vat co sat thuong cao nhat:\n";
        maxSatThuong->HienThiThongTin();
    }

    vector<SinhVat*> danhSach = ds.GetDanhSach();
    if (danhSach.size() >= 2) {
        ds.SoSanh_SatThuong(danhSach[0], danhSach[1]);
    }
    else {
        cout << "Khong du sinh vat de so sanh.\n";
    }

    cout << "\nTat ca sinh vat trong danh sach:\n";
    ds.HienThiThongTin();

    return 0;
}
