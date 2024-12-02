#pragma once
#include <string>
#include <iostream>
#include "NguHanh.h"
#include "QuaiVat.h"

class QuaiVatThongThuong : public QuaiVat
{
public:
	QuaiVatThongThuong(const int level, const string& Hanh);
	double TinhSatThuong() const override;
	void HienThiThongTin() const override;
};

