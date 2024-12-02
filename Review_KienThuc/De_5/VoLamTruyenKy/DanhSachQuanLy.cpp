#include "DanhSachQuanLy.h"
using namespace std;

void DanhSachQuanLy::Them(SinhVat* SV) { DanhSach.push_back(SV); }

SinhVat* DanhSachQuanLy::SatThuong_Max() {
    if (DanhSach.empty()) {
        cout << "Danh sach trong, khong co sinh vat nao.\n";
        return nullptr;
    }

    SinhVat* maxSinhVat = DanhSach[0];
    for (SinhVat* sv : DanhSach) {
        if (sv->TinhSatThuong() > maxSinhVat->TinhSatThuong()) {
            maxSinhVat = sv;
        }
    }
    return maxSinhVat;
}

void DanhSachQuanLy::SoSanh_SatThuong(SinhVat* A, SinhVat* B) {
	double SatThuong_AB = NguHanh::TinhSatThuongTuongTac(A->Get_Hanh(), B->Get_Hanh(), A->TinhSatThuong());
	double SatThuong_BA = NguHanh::TinhSatThuongTuongTac(B->Get_Hanh(), A->Get_Hanh(), B->TinhSatThuong());

	cout << "A gay sat thuong len B: " << SatThuong_AB << endl;
	cout << "B gay sat thuong len A: " << SatThuong_BA << endl;
}

vector<SinhVat*> DanhSachQuanLy::GetDanhSach() const {
    return DanhSach;
}

void DanhSachQuanLy::HienThiThongTin() const {
    for (const SinhVat* sv : DanhSach) {
        sv->HienThiThongTin();
        cout << "----------------------\n";
    }
}