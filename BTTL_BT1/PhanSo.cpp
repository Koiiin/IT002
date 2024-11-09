#include "PhanSo.h"
#include <iostream>
#include <cmath>
using namespace std;

/**
 * @brief Ham rut gon phan so bang cach chia ca tu va mau cho uoc chung lon nhat (UCLN)
 * @note Ham nay khong nhan tham so dau vao, chi thao tac tren du lieu thanh vien cua doi tuong hien tai
 */
void PhanSo::rutGon() {
    double ucln = gcd(iTu, iMau); // Tim UCLN cua tu va mau
    iTu /= ucln; // Chia tu cho UCLN de rut gon
    iMau /= ucln; // Chia mau cho UCLN de rut gon
    if (iMau < 0) { // Dam bao mau so luon duong
        iTu = -iTu;
        iMau = -iMau;
    }
}

/**
 * @brief Ham tim uoc chung lon nhat (GCD) cua hai so
 * @param a So thu nhat
 * @param b So thu hai
 * @return Gia tri GCD cua hai so a va b
 */
double PhanSo::gcd(double a, double b) {
    while (b != 0) {
        double temp = b;
        b = fmod(a, b); // Tim phan du khi chia a cho b
        a = temp;
    }
    return a;
}

/**
 * @brief Ham khoi tao mac dinh, tao phan so co tu so la 0 va mau so la 1
 */
PhanSo::PhanSo() : iTu(0), iMau(1) {}

/**
 * @brief Ham khoi tao phan so voi tu va mau cho truoc
 * @param Tu Tu so cua phan so
 * @param Mau Mau so cua phan so, khong duoc bang 0
 * @throws invalid_argument neu Mau bang 0
 */
PhanSo::PhanSo(double Tu, double Mau) : iTu(Tu), iMau(Mau) {
    if (iMau == 0) throw invalid_argument("Mau so phai khac 0");
    rutGon(); // Rut gon phan so ngay khi khoi tao
}

/**
 * @brief Ham khoi tao phan so voi tu so cu the va mau so mac dinh la 1
 * @param Tu Tu so cua phan so
 */
PhanSo::PhanSo(double Tu) : iTu(Tu), iMau(1) {}

/**
 * @brief Toan tu nhap >> cho phan so, nhap tu luong dau vao
 * @param is Luong nhap (istream)
 * @param ps Doi tuong phan so can nhap
 * @return Luong nhap sau khi xu ly
 */
istream& operator >> (istream& is, PhanSo& ps) {
    is >> ps.iTu >> ps.iMau;
    while (ps.iMau == 0) { // Kiem tra mau so, khong duoc bang 0
        cout << "Nhap lai mau so: ";
        is >> ps.iMau;
    }
    ps.rutGon(); // Rut gon phan so sau khi nhap
    return is;
}

/**
 * @brief Toan tu xuat << cho phan so, xuat ra luong dau ra
 * @param os Luong xuat (ostream)
 * @param ps Doi tuong phan so can xuat
 * @return Luong xuat sau khi xu ly
 */
ostream& operator << (ostream& os, const PhanSo& ps) {
    if (ps.iMau == 1) os << ps.iTu; // Neu mau la 1 thi chi xuat tu so
    else os << ps.iTu << "/" << ps.iMau; // Xuat phan so dang tu/mau
    return os;
}

/**
 * @brief Toan tu cong (+) hai phan so
 * @param a Phan so can cong voi doi tuong hien tai
 * @return Phan so ket qua sau khi cong
 */
PhanSo PhanSo::operator + (const PhanSo& a) const {
    PhanSo result(iTu * a.iMau + a.iTu * iMau, iMau * a.iMau); // Cong hai phan so
    result.rutGon(); // Rut gon ket qua
    return result;
}

/**
 * @brief Toan tu cong (+) giua so thuc va phan so
 * @param a So thuc can cong
 * @param b Phan so can cong
 * @return Phan so ket qua sau khi cong
 */
PhanSo operator + (double a, const PhanSo& b) {
    return PhanSo(a * b.iMau + b.iTu, b.iMau); // Chuyen a thanh phan so va cong voi b
}

/**
 * @brief Toan tu tru (-) hai phan so
 * @param a Phan so can tru
 * @return Phan so ket qua sau khi tru
 */
PhanSo PhanSo::operator - (const PhanSo& a) const {
    PhanSo result(iTu * a.iMau - a.iTu * iMau, iMau * a.iMau); // Tru hai phan so
    result.rutGon(); // Rut gon ket qua
    return result;
}

/**
 * @brief Toan tu tru (-) giua so thuc va phan so
 * @param a So thuc can tru
 * @param b Phan so can tru
 * @return Phan so ket qua sau khi tru
 */
PhanSo operator- (double a, const PhanSo& b) {
    return PhanSo(a * b.iMau - b.iTu, b.iMau); // Chuyen a thanh phan so va tru b
}

/**
 * @brief Toan tu nhan (*) hai phan so
 * @param a Phan so can nhan
 * @return Phan so ket qua sau khi nhan
 */
PhanSo PhanSo::operator * (const PhanSo& a) const {
    PhanSo result(iTu * a.iTu, iMau * a.iMau); // Nhan hai phan so
    result.rutGon(); // Rut gon ket qua
    return result;
}

/**
 * @brief Toan tu nhan (*) giua so thuc va phan so
 * @param a So thuc can nhan
 * @param b Phan so can nhan
 * @return Phan so ket qua sau khi nhan
 */
PhanSo operator* (double a, const PhanSo& b) {
    return PhanSo(a * b.iTu, b.iMau); // Chuyen a thanh phan so va nhan voi b
}

/**
 * @brief Toan tu chia (/) hai phan so
 * @param a Phan so can chia
 * @return Phan so ket qua sau khi chia
 */
PhanSo PhanSo::operator / (const PhanSo& a) const {
    PhanSo result(iTu * a.iMau, iMau * a.iTu); // Chia hai phan so
    result.rutGon(); // Rut gon ket qua
    return result;
}

/**
 * @brief Toan tu chia (/) giua so thuc va phan so
 * @param a So thuc can chia
 * @param b Phan so can chia
 * @return Phan so ket qua sau khi chia
 */
PhanSo operator/ (double a, const PhanSo& b) {
    return PhanSo(a * b.iMau, b.iTu); // Chuyen a thanh phan so va chia b
}

/**
 * @brief Toan tu so sanh bang (==) hai phan so
 * @param a Phan so can so sanh
 * @return true neu hai phan so bang nhau, false neu khong
 */
bool PhanSo::operator == (const PhanSo& a) const { 
    return (iTu * a.iMau == iMau * a.iTu); 
}

/**
 * @brief Toan tu so sanh khac nhau (!=) hai phan so
 * @param a Phan so can so sanh
 * @return true neu hai phan so khac nhau, false neu bang nhau
 */
bool PhanSo::operator != (const PhanSo& a) const { 
    return !(*this == a); 
}

/**
 * @brief Toan tu lon hon hoac bang (>=) giua hai phan so
 * @param a Phan so can so sanh
 * @return true neu phan so hien tai lon hon hoac bang a, nguoc lai false
 */
bool PhanSo::operator >= (const PhanSo& a) const { 
    return (iTu * a.iMau >= iMau * a.iTu); 
}

/**
 * @brief Toan tu nho hon hoac bang (<=) giua hai phan so
 * @param a Phan so can so sanh
 * @return true neu phan so hien tai nho hon hoac bang a, nguoc lai false
 */
bool PhanSo::operator <= (const PhanSo& a) const { 
    return (iTu * a.iMau <= iMau * a.iTu); 
}

/**
 * @brief Toan tu lon hon (>) giua hai phan so
 * @param a Phan so can so sanh
 * @return true neu phan so hien tai lon hon a, nguoc lai false
 */
bool PhanSo::operator > (const PhanSo& a) const { 
    return (iTu * a.iMau > iMau * a.iTu); 
}

/**
 * @brief Toan tu nho hon (<) giua hai phan so
 * @param a Phan so can so sanh
 * @return true neu phan so hien tai nho hon a, nguoc lai false
 */
bool PhanSo::operator < (const PhanSo& a) const { 
    return (iTu * a.iMau < iMau * a.iTu); 
}


