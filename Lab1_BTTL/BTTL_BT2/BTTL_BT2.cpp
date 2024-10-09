#include <iostream>
using namespace std;

class PhanSo {
private:
	int tu_so;
	int mau_so;
public:
	// Constructor
	PhanSo(int tu = 0, int mau = 1) {
		if (mau == 0) { 
			cout << "Mau khong the bang 0";
			exit(1);
		}
		tu_so = tu;
		mau_so = mau;
	}

	// Set/Get 
	void SetTuSo(int tu) { tu_so = tu; }
	void SetMauSo(int mau) { 
		if (mau == 0) {
			cout <<"Mau khong the bang 0";
			exit(1);
		}
		mau_so = mau; 
	}

	int GetTuSo() { return tu_so; }
	int GetMauSo() { return mau_so; }

	// Nhập Phân Số
	void NhapPhanSo() {
		int tu, mau;
		cout <<"Nhap tu so: ";
		cin >> tu;
		cout <<"Nhap mau so: ";
		cin >> mau;
		SetTuSo(tu);
		SetMauSo(mau);
	}

	// Tìm Phân Số Lớn Nhất
	bool CheckSoLon(PhanSo* ps) {
		if ((tu_so * ps->mau_so) >= (ps->tu_so * mau_so)) return true;
		else return false;
	}

	// Xuất Phân Số
	void XuatPhanSo() {
		cout << tu_so << "/" << mau_so;
	}
};

int main() {
	PhanSo ps1, ps2;
	cout <<"Nhap Phan So Thu 1: \n";
	ps1.NhapPhanSo();
	cout <<"Nhap Phan So Thu 2: \n";
	ps2.NhapPhanSo();
	cout <<"Phan So Lon Nhat: \n";
	if (ps1.CheckSoLon(&ps2)) {
		ps1.XuatPhanSo();
	} else {
		ps2.XuatPhanSo();
	}

	return 0;
}