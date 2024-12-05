#ifndef DELUXE
#define DELUXE

#include <iostream>
#include "KhachSan.h"
using namespace std;

class Deluxe : public KhachSan {
public:
	Deluxe(int SoDem, double PhiDV, double PhiPV);

	double TinhDoanhThu() const override;
};

#endif // !DELUXE


