#ifndef KYSU_H
#define KYSU_H

#include "NhanVien.h"

class KySu : public NhanVien {
private:
    double SoGioLamThem;
public:
    KySu();
    KySu(string ID, string Name, double Luong, double Time);
    ~KySu();

    void Nhap() override;
    void Xuat() const override;
    double TienThuong() const override;
};

#endif // KYSU_H
