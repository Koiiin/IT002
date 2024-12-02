#include "QuaiVatDauLinh.h"
using namespace std;

QuaiVatDauLinh::QuaiVatDauLinh(const int level, const string& h) : QuaiVat(level, h) {}

double QuaiVatDauLinh::TinhSatThuong() const { return CapDo * 7; }

void QuaiVatDauLinh::HienThiThongTin() const {
	cout << "\n------------------------------------------------\n";
	cout << "Loai quai vat: Quai Vat Dau Linh" << endl;
	cout << "Cap Do: " << Get_CapDo() << endl;
	cout << "Ngu Hanh: " << Get_Hanh() << endl;
	cout << "Sat Thuong " << TinhSatThuong() << endl;
	cout << "\n------------------------------------------------\n";
}