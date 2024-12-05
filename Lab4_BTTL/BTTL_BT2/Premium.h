#ifndef PREMIUM
#define PREMIUM

#include "KhachSan.h"
#include <iostream>
using namespace std;

class Premium : public KhachSan {
public:
	Premium(int SoDem, double PhiPV);

	double TinhDoanhThu() const override;
};

#endif // !PREMIUM

