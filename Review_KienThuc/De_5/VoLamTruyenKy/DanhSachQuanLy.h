#pragma once
#include <iostream>
#include "NhanVat.h"
#include "QuaiVat.h"
#include "NguHanh.h"
#include "SinhVat.h"
#include <vector>
using namespace std;

class DanhSachQuanLy
{
protected:
	vector<SinhVat*> DanhSach;
public:
	void Them(SinhVat* SV);
	SinhVat* SatThuong_Max();
	void SoSanh_SatThuong(SinhVat* A, SinhVat* B);
	void HienThiThongTin() const;
	vector<SinhVat*> GetDanhSach() const;
};

