#ifndef SO_PHUC_H
#define SO_PHUC_H

#include <iostream>
using namespace std;

/**
 * Lop SoPhuc: Dinh nghia mot so phuc co phan thuc va phan ao.
 *
 * Thuoc tinh:
 *  - dThuc: Phan thuc cua so phuc.
 *  - dAo: Phan ao cua so phuc.
 *
 * Phuong thuc:
 *  - SoPhuc(): Khoi tao so phuc voi gia tri mac dinh.
 *  - SoPhuc(double Thuc, double Ao): Khoi tao so phuc voi phan thuc va phan ao cho truoc.
 *  - SoPhuc(double Tu): Khoi tao so phuc voi phan thuc bang Tu, phan ao bang 0.
 *
 * Toan tu:
 *  - Toan tu nhap/xuat (>>, <<): Cho phep nhap va xuat mot so phuc.
 *  - Toan tu +, -, *, /: Thuc hien phep toan cong, tru, nhan, chia giua hai so phuc.
 *  - Toan tu ==, !=: So sanh hai so phuc.
 */

class SoPhuc {
private:
    double dThuc; // Phan thuc cua so phuc
    double dAo;   // Phan ao cua so phuc

public:
    // Khoi tao mac dinh, gan phan thuc va phan ao bang 0
    SoPhuc();

    // Khoi tao so phuc voi gia tri phan thuc va phan ao cho truoc
    SoPhuc(double Thuc, double Ao);

    // Khoi tao so phuc voi gia tri phan thuc cho truoc, phan ao bang 0
    SoPhuc(double Tu);

    // Toan tu nhap so phuc tu input
    friend istream& operator >> (istream& is, SoPhuc& sp);

    // Toan tu xuat so phuc ra output
    friend ostream& operator << (ostream& os, const SoPhuc& sp);

    // Toan tu cong hai so phuc
    SoPhuc operator + (const SoPhuc& sp) const;

    // Toan tu cong giua so thuc va so phuc
    friend SoPhuc operator + (double x, SoPhuc& sp);

    // Toan tu tru hai so phuc
    SoPhuc operator - (const SoPhuc& sp) const;

    // Toan tu tru giua so thuc va so phuc
    friend SoPhuc operator - (double x, SoPhuc& sp);

    // Toan tu nhan hai so phuc
    SoPhuc operator * (const SoPhuc& sp) const;

    // Toan tu nhan giua so thuc va so phuc
    friend SoPhuc operator * (double x, SoPhuc& sp);

    // Toan tu chia hai so phuc
    SoPhuc operator / (const SoPhuc& sp) const;

    // Toan tu chia giua so thuc va so phuc
    friend SoPhuc operator / (double x, SoPhuc& sp);

    // Toan tu so sanh bang hai so phuc
    bool operator == (SoPhuc& sp) const;

    // Toan tu so sanh bang giua so thuc va so phuc
    friend bool operator == (double x, SoPhuc& sp);

    // Toan tu so sanh khac hai so phuc
    bool operator != (SoPhuc& sp) const;

    // Toan tu so sanh khac giua so thuc va so phuc
    friend bool operator != (double x, SoPhuc& sp);
};

#endif // !SO_PHUC_H
