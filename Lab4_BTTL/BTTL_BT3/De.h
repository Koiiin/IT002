#ifndef DE
#define DE

#include <iostream>
#include "GiaSuc.h"
#include <cstdlib>

class De : public GiaSuc {
public:
	De(int SL);
	~De();

	string Keu() const override;
	void SinhCon() override;
	void ChoSua() override;
};

#endif // !CUU
