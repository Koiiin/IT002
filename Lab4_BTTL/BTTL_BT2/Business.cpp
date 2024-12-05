#include "Business.h"
#include "KhachSan.h"
#include <iostream>
using namespace std;

Business::Business(int SoDem) : KhachSan(SoDem, 0, 0) {}

double Business::TinhDoanhThu() const { return SoDem * 300000; }