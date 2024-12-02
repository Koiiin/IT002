#pragma once
#include <iostream>
#include <string>
#include "NguHanh.h"
#include "SinhVat.h"
using namespace std;

class QuaiVat : public SinhVat
{
public:
	QuaiVat(const int level ,const string& hanh);
	virtual ~QuaiVat() = default;

	virtual double TinhSatThuong() const override = 0;
	virtual void HienThiThongTin() const override = 0;

	string Get_Hanh() const;
	int Get_CapDo() const;
};

