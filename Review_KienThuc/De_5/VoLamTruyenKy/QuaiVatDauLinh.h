#pragma once
#include "NguHanh.h"
#include "QuaiVat.h"
using namespace std;

class QuaiVatDauLinh : public QuaiVat
{
public:
	QuaiVatDauLinh(const int level, const string& Hanh);
	double TinhSatThuong() const override;
	void HienThiThongTin() const override;
};

