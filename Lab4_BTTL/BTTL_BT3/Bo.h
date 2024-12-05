#ifndef BO
#define BO

#include <iostream>
#include <string>
#include <cstdlib>
#include "GiaSuc.h"
using namespace std;

class Bo : public GiaSuc {
public:
	Bo(int SL = 0);
	~Bo();

	string Keu() const override;
	void SinhCon() override;
	void ChoSua() override;
};

#endif // !BO

