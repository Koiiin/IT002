#include "Time.h"
#include <iostream>
using namespace std;

// Ham khoi tao mac dinh, dat gia tri iGio, iPhut, iGiay la 0
ThoiGian::ThoiGian() : iGio(0), iPhut(0), iGiay(0) {}

// Ham khoi tao voi cac tham so Gio, Phut, Giay
// Dau vao: Gio, Phut, Giay - gia tri khoi tao cua gio, phut, giay
ThoiGian::ThoiGian(int Gio, int Phut, int Giay) : iGio(Gio), iPhut(Phut), iGiay(Giay) {}

// Ham tinh tong so giay tu gio, phut va giay hien tai
// Dau ra: Tong so giay tinh tu gia tri hien tai
int ThoiGian::TinhGiay() const {
    return iGio * 3600 + iPhut * 60 + iGiay;
}

// Ham cap nhat gia tri gio, phut, giay tu so giay cho truoc
// Dau vao: Giay - so giay can cap nhat
void ThoiGian::TinhLaiGio(int Giay) {
    iGio = Giay / 3600;
    Giay %= 3600;
    iPhut = Giay / 60;
    iGiay = Giay % 60;

    while (iGio >= 24) {
        iGio -= 24;
    }
}

// Toan tu + de cong thoi gian hien tai voi so giay cho truoc
// Dau vao: Giay - so giay can cong
// Dau ra: Doi tuong ThoiGian moi sau khi cong
ThoiGian ThoiGian::operator+(int Giay) {
    int totalSeconds = TinhGiay() + Giay;
    ThoiGian tg;
    tg.TinhLaiGio(totalSeconds);
    return tg;
}

// Toan tu - de tru thoi gian hien tai voi so giay cho truoc
// Dau vao: Giay - so giay can tru
// Dau ra: Doi tuong ThoiGian moi sau khi tru
ThoiGian ThoiGian::operator-(int Giay) {
    int totalSeconds = TinhGiay() - Giay;
    ThoiGian tg;
    tg.TinhLaiGio(totalSeconds);
    return tg;
}

// Toan tu + de cong hai doi tuong ThoiGian
// Dau vao: a - doi tuong ThoiGian can cong
// Dau ra: Doi tuong ThoiGian moi sau khi cong
ThoiGian ThoiGian::operator+(const ThoiGian& a) {
    return *this + a.TinhGiay();
}

// Toan tu - de tru hai doi tuong ThoiGian
// Dau vao: a - doi tuong ThoiGian can tru
// Dau ra: Doi tuong ThoiGian moi sau khi tru
// Neu thoi gian ket qua am, them 86400 giay (24h) de dam bao thoi gian duong
ThoiGian ThoiGian::operator-(const ThoiGian& a) {
    int totalSeconds1 = TinhGiay();
    int totalSeconds2 = a.TinhGiay();
    int resultSeconds = totalSeconds1 - totalSeconds2;

    if (resultSeconds < 0) {
        resultSeconds += 86400;
    }

    ThoiGian result;
    result.TinhLaiGio(resultSeconds);
    return result;
}

// Toan tu tang truoc ++: tang thoi gian len 1 giay
// Dau ra: Doi tuong ThoiGian sau khi tang
ThoiGian& ThoiGian::operator++() {
    *this = *this + 1;
    return *this;
}

// Toan tu tang sau ++: tang thoi gian len 1 giay
// Dau ra: Doi tuong ThoiGian truoc khi tang
ThoiGian ThoiGian::operator++(int) {
    ThoiGian temp = *this;
    *this = *this + 1;
    return temp;
}

// Toan tu giam truoc --: giam thoi gian di 1 giay
// Dau ra: Doi tuong ThoiGian sau khi giam
ThoiGian& ThoiGian::operator--() {
    iGiay -= 1;
    if (iGiay < 0) { 
        iGiay += 60; 
        iPhut -= 1;
        if (iPhut < 0) {
            iPhut += 60;
            iGio -= 1;
            if (iGio < 0) {
                iGio += 24;
            }
        }
    }
    return *this;
}

// Toan tu giam sau --: giam thoi gian di 1 giay
// Dau ra: Doi tuong ThoiGian truoc khi giam
ThoiGian ThoiGian::operator--(int) {
    ThoiGian temp = *this;
    *this = *this - 1;
    return temp;
}

// Toan tu == de kiem tra hai doi tuong ThoiGian bang nhau
// Dau vao: a - doi tuong ThoiGian can so sanh
// Dau ra: true neu hai doi tuong bang nhau, nguoc lai false
bool ThoiGian::operator==(const ThoiGian& a) const {
    return TinhGiay() == a.TinhGiay();
}

// Toan tu != de kiem tra hai doi tuong ThoiGian khong bang nhau
bool ThoiGian::operator!=(const ThoiGian& a) const {
    return TinhGiay() != a.TinhGiay();
}

// Toan tu >= de kiem tra doi tuong ThoiGian hien tai lon hon hoac bang doi tuong a
bool ThoiGian::operator>=(const ThoiGian& a) const {
    return TinhGiay() >= a.TinhGiay();
}

// Toan tu <= de kiem tra doi tuong ThoiGian hien tai nho hon hoac bang doi tuong a
bool ThoiGian::operator<=(const ThoiGian& a) const {
    return TinhGiay() <= a.TinhGiay();
}

// Toan tu > de kiem tra doi tuong ThoiGian hien tai lon hon doi tuong a
bool ThoiGian::operator>(const ThoiGian& a) const {
    return TinhGiay() > a.TinhGiay();
}

// Toan tu < de kiem tra doi tuong ThoiGian hien tai nho hon doi tuong a
bool ThoiGian::operator<(const ThoiGian& a) const {
    return TinhGiay() < a.TinhGiay();
}

// Toan tu << de xuat thoi gian ra man hinh theo dinh dang "gio:phut:giay"
// Dau vao: tg - doi tuong ThoiGian can xuat
ostream& operator<<(ostream& os, const ThoiGian& tg) {
    os << tg.iGio << ":" << tg.iPhut << ":" << tg.iGiay;
    return os;
}

// Toan tu >> de nhap thoi gian tu ban phim
// Dau ra: tg - doi tuong ThoiGian sau khi nhap
istream& operator>>(istream& is, ThoiGian& tg) {
    while (1) {
        cout << "Nhap gio: ";
        is >> tg.iGio;
        if (tg.iGio >= 0 && tg.iGio <= 23) { break; }
        else
        {
            cout << "Gio khong hop le. Hay nhap lai.\n";
        }
    }

    while (1) {
        cout << "Nhap phut: ";
        is >> tg.iPhut;
        if (tg.iPhut >= 0 && tg.iPhut <= 59) { break; }
        else
        {
            cout << "Phut khong hop le. Hay nhap lai.\n";
        }
    }
    
    while (1) {
        cout << "Nhap giay: ";
        is >> tg.iGiay;
        if (tg.iGiay >= 0 && tg.iGiay <= 59) { break; }
        else
        {
            cout << "Giay khong hop le. Hay nhap lai.\n";
        }
    }
    return is;
}
