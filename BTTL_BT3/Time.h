#ifndef TIME_H
#define TIME_H

#include <iostream>
using namespace std;

/*
 * Lop ThoiGian mo ta thoi gian voi 3 thuoc tinh la gio, phut va giay.
 * Lop nay cung cap cac phuong thuc de tinh toan, cong, tru thoi gian va so sanh thoi gian.
 */
class ThoiGian {
private:
    int iGio;   // Thuoc tinh gio
    int iPhut;  // Thuoc tinh phut
    int iGiay;  // Thuoc tinh giay

public:
    // Ham khoi tao mac dinh, dat gia tri gio, phut, giay la 0.
    ThoiGian();

    // Ham khoi tao voi tham so: Gio (gio), Phut (phut), Giay (giay).
    ThoiGian(int Gio, int Phut, int Giay);

    // Ham tinh tong so giay tu gio, phut, giay hien tai. Tra ve tong so giay.
    int TinhGiay() const;

    // Ham cap nhat gio, phut, giay tu mot so giay cho truoc.
    void TinhLaiGio(int Giay);

    // Toan tu cong them so giay, tra ve doi tuong ThoiGian moi.
    ThoiGian operator+(int Giay);

    // Toan tu tru so giay, tra ve doi tuong ThoiGian moi.
    ThoiGian operator-(int Giay);

    // Toan tu cong hai doi tuong ThoiGian, tra ve doi tuong ThoiGian moi.
    ThoiGian operator+(const ThoiGian& a);

    // Toan tu tru hai doi tuong ThoiGian, tra ve doi tuong ThoiGian moi.
    ThoiGian operator-(const ThoiGian& a);

    // Toan tu tang truoc (tien to), tang thoi gian len 1 giay.
    ThoiGian& operator++();

    // Toan tu tang sau (hau to), tang thoi gian len 1 giay.
    ThoiGian operator++(int);

    // Toan tu giam truoc (tien to), giam thoi gian di 1 giay.
    ThoiGian& operator--();

    // Toan tu giam sau (hau to), giam thoi gian di 1 giay.
    ThoiGian operator--(int);

    // Toan tu so sanh bang, tra ve true neu hai thoi gian bang nhau.
    bool operator==(const ThoiGian& a) const;

    // Toan tu so sanh khac, tra ve true neu hai thoi gian khong bang nhau.
    bool operator!=(const ThoiGian& a) const;

    // Toan tu so sanh lon hon hoac bang, tra ve true neu thoi gian hien tai lon hon hoac bang a.
    bool operator>=(const ThoiGian& a) const;

    // Toan tu so sanh nho hon hoac bang, tra ve true neu thoi gian hien tai nho hon hoac bang a.
    bool operator<=(const ThoiGian& a) const;

    // Toan tu so sanh lon hon, tra ve true neu thoi gian hien tai lon hon a.
    bool operator>(const ThoiGian& a) const;

    // Toan tu so sanh nho hon, tra ve true neu thoi gian hien tai nho hon a.
    bool operator<(const ThoiGian& a) const;

    // Toan tu xuat thoi gian ra man hinh (dang "gio:phut:giay").
    friend ostream& operator<<(ostream& os, const ThoiGian& tg);

    // Toan tu nhap thoi gian tu ban phim.
    friend istream& operator>>(istream& is, ThoiGian& tg);
};

#endif // !TIME_H
