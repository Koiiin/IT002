#include "GiaSuc.h"

GiaSuc::GiaSuc(int SL) : SoLuong(SL), SoLuongCon(0), SoLuongSua(0) {}
GiaSuc::~GiaSuc() = default;

int GiaSuc::Getter_SoLuong() const { return SoLuong; }
int GiaSuc::Getter_SoLuongCon() const { return SoLuongCon; }
double GiaSuc::Getter_Sua() const { return SoLuongSua; }
