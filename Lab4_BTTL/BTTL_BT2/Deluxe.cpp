#include "Deluxe.h"
#include "KhachSan.h"
#include <iostream>
using namespace std;

Deluxe::Deluxe(int SoDem, double PhiDV, double PhiPV) : KhachSan(SoDem, PhiDV, PhiPV) {}

double Deluxe::TinhDoanhThu() const { return SoDem * 750000 + PhiDV + PhiPV; }
