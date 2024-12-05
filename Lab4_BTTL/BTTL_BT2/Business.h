#ifndef BUSINESS
#define BUSINESS

#include <iostream>
#include "KhachSan.h"
using namespace std;

class Business : public KhachSan {
public:
	Business(int SoDem);

	double TinhDoanhThu() const override;
};

#endif // !BUSINESS

