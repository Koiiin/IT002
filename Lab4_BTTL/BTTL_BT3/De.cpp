#include "De.h"

De::De(int SL) : GiaSuc(SL) {}

De::~De() {}

string De::Keu() const {
    return "De: Mee Mee!";
}

void De::SinhCon() {
    for (int i = 0; i < SoLuong; ++i) {
        int soCon = rand() % 2;
        SoLuongCon += soCon;
    }
}

void De::ChoSua() {
    for (int i = 0; i < SoLuong; ++i) {
        int sua = rand() % 11;
        SoLuongSua += sua;
    }
}
