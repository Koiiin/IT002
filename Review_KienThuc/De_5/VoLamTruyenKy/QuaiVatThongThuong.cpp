#include "QuaiVatThongThuong.h"
using namespace std;

QuaiVatThongThuong::QuaiVatThongThuong(const int level, const string& h) : QuaiVat(level, h) {}

double QuaiVatThongThuong::TinhSatThuong() const {
	return CapDo * 3;
}

void QuaiVatThongThuong::HienThiThongTin() const {
	cout << "\n------------------------------------------------\n";
	cout << "Loai quai vat: Quai Vat Thong Thuong" << endl;
	cout << "Cap Do: " << Get_CapDo() << endl;
	cout << "Ngu Hanh: " << Get_Hanh() << endl;
	cout << "Sat Thuong: " << TinhSatThuong() << endl;
	cout << "\n------------------------------------------------\n";
}