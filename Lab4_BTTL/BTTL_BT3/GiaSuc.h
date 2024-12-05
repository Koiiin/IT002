#ifndef GIASUC
#define GIASUC

#include <iostream>
#include <string>
using namespace std;

class GiaSuc {
protected:
	int SoLuong;
	int SoLuongCon;
	double SoLuongSua;
public:
	GiaSuc(int SL);
	virtual ~GiaSuc();

	virtual string Keu() const = 0;
	virtual void SinhCon() = 0;
	virtual void ChoSua() = 0;

	int Getter_SoLuong() const;
	int Getter_SoLuongCon() const;
	double Getter_Sua() const;
};

#endif // !GIASUC
