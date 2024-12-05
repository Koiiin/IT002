#include "Bo.h"
#include "GiaSuc.h"
#include <cstdlib>
using namespace	std;

Bo::Bo(int SL) : GiaSuc(SL) {}
Bo::~Bo() = default;

string Bo::Keu() const { return "Bo: Umbooooo Moo Moo"; }

void Bo::SinhCon() {
	for (int i = 0; i < SoLuong; ++i) {
		int soCon = rand() % 2; 
		SoLuongCon += soCon;
	}
}

void Bo::ChoSua() {
	for (int i = 0; i < SoLuong; ++i) {
		int sua = rand() % 21; 
		SoLuongSua += sua;
	}
}