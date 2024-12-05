#include "Cuu.h"
using namespace std;

Cuu::Cuu(int SL) : GiaSuc(SL) {}
Cuu::~Cuu() = default;

string Cuu::Keu() const { return "Cuu: bebe bebe"; }

void Cuu::SinhCon() {
	for (int i = 0; i < SoLuong; ++i) {
		int soCon = rand() % 2;
		SoLuongCon += soCon;
	}
}

void Cuu::ChoSua() {
	for (int i = 0; i < SoLuong; ++i) {
		int sua = rand() % 6;
		SoLuongSua += sua;
	}
}