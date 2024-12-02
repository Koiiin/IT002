#include "SinhVat.h"
using namespace std;

SinhVat::SinhVat(int level, const string& h) : CapDo(level), Hanh(h) {}

string SinhVat::Get_Hanh() const { return Hanh; }