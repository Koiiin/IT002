#pragma once
#include "NguHanh.h"
#include <iostream>
#include <string>
using namespace std;
class SinhVat
{
protected:
	int CapDo;
	string Hanh;
public:
	SinhVat(const int level, const string& Hanh);
	virtual ~SinhVat() = default;

	virtual double TinhSatThuong() const = 0;
	virtual void HienThiThongTin() const = 0;
	string Get_Hanh() const;
};

