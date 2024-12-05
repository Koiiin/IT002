#ifndef KHACHSAN
#define KHACHSAN

#include <iostream>
using namespace std;

class KhachSan {
protected:
	int SoDem = 0;
	double PhiDV = 0;
	double PhiPV = 0;
public:
	KhachSan(int SoDem, double PhiDV, double PhiPV);
	virtual ~KhachSan();

	virtual double TinhDoanhThu() const = 0;

};

#endif // !KHACHSAN
