#ifndef NHANVAT_H
#define NHANVAT_H

#include <string>
#include "NguHanh.h"
#include "SinhVat.h"
using namespace std;

class NhanVat : public SinhVat {
private:
    string Ten;
    string MonPhai;

public:
    NhanVat(const string& ten, const string& monPhai, int capDo);

    string Get_Ten() const;
    string Get_MonPhai() const;
    string Get_Hanh() const;
    int Get_CapDo() const;
    double TinhSatThuong() const override;

    void HienThiThongTin() const override;
};

#endif
