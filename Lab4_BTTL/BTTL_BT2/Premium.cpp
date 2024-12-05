#include "Premium.h"
#include "KhachSan.h"
#include <iostream>
using namespace std;

Premium::Premium(int SoDem, double PhiDV) : KhachSan(SoDem, PhiDV, 0) {}

double Premium::TinhDoanhThu() const { return SoDem * 500000 + PhiDV; }