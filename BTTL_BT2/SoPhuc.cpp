#include "SoPhuc.h"
#include <iostream>
#include <math.h>
using namespace std;

/**
 * Ham khoi tao mac dinh cho so phuc, gan phan thuc va phan ao bang 0.
 */
SoPhuc::SoPhuc() : dThuc(0), dAo(0) {}

/**
 * Ham khoi tao so phuc voi gia tri phan thuc va phan ao cho truoc.
 * @param Thuc Gia tri phan thuc
 * @param Ao Gia tri phan ao
 */
SoPhuc::SoPhuc(double Thuc, double Ao) : dThuc(Thuc), dAo(Ao) {}

/**
 * Ham khoi tao so phuc voi gia tri phan thuc cho truoc, phan ao mac dinh bang 0.
 * @param Thuc Gia tri phan thuc
 */
SoPhuc::SoPhuc(double Thuc) : dThuc(Thuc), dAo(0) {}

/**
 * Toan tu nhap so phuc tu input.
 * @param is Stream nhap
 * @param sp So phuc can nhap
 * @return Stream nhap
 */
istream& operator >> (istream& is, SoPhuc& sp) {
    cout << "Nhap phan thuc: "; is >> sp.dThuc;
    cout << "Nhap phan ao: "; is >> sp.dAo;
    return is;
}

/**
 * Toan tu xuat so phuc ra output.
 * @param os Stream xuat
 * @param sp So phuc can xuat
 * @return Stream xuat
 */
ostream& operator << (ostream& os, const SoPhuc& sp) {
    os << sp.dThuc << " + " << sp.dAo << "i\n";
    return os;
}

/**
 * Toan tu cong hai so phuc.
 * @param sp So phuc can cong
 * @return Ket qua cong
 */
SoPhuc SoPhuc::operator+(const SoPhuc& sp) const {
    return SoPhuc(dThuc + sp.dThuc, dAo + sp.dAo);
}

/**
 * Toan tu cong giua so thuc va so phuc.
 * @param x So thuc
 * @param sp So phuc
 * @return Ket qua cong
 */
SoPhuc operator+(double x, SoPhuc& sp) {
    return SoPhuc(x + sp.dThuc, sp.dAo);
}

/**
 * Toan tu tru hai so phuc.
 * @param sp So phuc can tru
 * @return Ket qua tru
 */
SoPhuc SoPhuc::operator-(const SoPhuc& sp) const {
    return SoPhuc(dThuc - sp.dThuc, dAo - sp.dAo);
}

/**
 * Toan tu tru giua so thuc va so phuc.
 * @param x So thuc
 * @param sp So phuc
 * @return Ket qua tru
 */
SoPhuc operator-(double x, SoPhuc& sp) {
    return SoPhuc(x - sp.dThuc, -sp.dAo);
}

/**
 * Toan tu nhan hai so phuc.
 * @param sp So phuc can nhan
 * @return Ket qua nhan
 */
SoPhuc SoPhuc::operator*(const SoPhuc& sp) const {
    return SoPhuc(dThuc * sp.dThuc - dAo * sp.dAo, dThuc * sp.dAo + dAo * sp.dThuc);
}

/**
 * Toan tu nhan giua so thuc va so phuc.
 * @param x So thuc
 * @param sp So phuc
 * @return Ket qua nhan
 */
SoPhuc operator*(double x, SoPhuc& sp) {
    return SoPhuc(x * sp.dThuc, x * sp.dAo);
}

/**
 * Toan tu chia hai so phuc.
 * @param sp So phuc chia
 * @return Ket qua chia
 */
SoPhuc SoPhuc::operator/(const SoPhuc& sp) const {
    double MauChung = pow(sp.dThuc, 2) + pow(sp.dAo, 2);
    return SoPhuc((dThuc * sp.dThuc + dAo * sp.dAo) / MauChung, (dAo * sp.dThuc - dThuc * sp.dAo) / MauChung);
}

/**
 * Toan tu chia giua so thuc va so phuc.
 * @param x So thuc
 * @param sp So phuc
 * @return Ket qua chia
 */
SoPhuc operator/(double x, SoPhuc& sp) {
    double MauChung = pow(sp.dThuc, 2) + pow(sp.dAo, 2);
    return SoPhuc((x * sp.dThuc + sp.dAo) / MauChung, (-x * sp.dAo) / MauChung);
}

/**
 * Toan tu so sanh bang hai so phuc.
 * @param sp So phuc can so sanh
 * @return True neu hai so phuc bang nhau, nguoc lai False
 */
bool SoPhuc::operator==(SoPhuc& sp) const {
    return (dThuc == sp.dThuc && dAo == sp.dAo);
}

/**
 * Toan tu so sanh bang giua so thuc va so phuc.
 * @param x So thuc
 * @param sp So phuc
 * @return True neu so thuc bang so phuc, nguoc lai False
 */
bool operator==(double x, SoPhuc& sp) {
    return (x == sp.dThuc && sp.dAo == 0);
}

/**
 * Toan tu so sanh khac hai so phuc.
 * @param sp So phuc can so sanh
 * @return True neu hai so phuc khac nhau, nguoc lai False
 */
bool SoPhuc::operator!=(SoPhuc& sp) const {
    return !(*this == sp);
}

/**
 * Toan tu so sanh khac giua so thuc va so phuc.
 * @param x So thuc
 * @param sp So phuc
 * @return True neu so thuc khac so phuc, nguoc lai False
 */
bool operator!=(double x, SoPhuc& sp) {
    return (x != sp.dThuc || sp.dAo != 0);
}
