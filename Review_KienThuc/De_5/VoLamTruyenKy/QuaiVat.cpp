#include "NguHanh.h"
#include "QuaiVat.h"
using namespace std;

QuaiVat::QuaiVat(const int level, const string& h) : SinhVat(level, h) {}



string QuaiVat::Get_Hanh() const { return Hanh; }
int QuaiVat::Get_CapDo() const { return CapDo; }