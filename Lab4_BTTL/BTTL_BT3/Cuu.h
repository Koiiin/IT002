#ifndef CUU_H
#define CUU_H

#include "GiaSuc.h"
#include <cstdlib>

class Cuu : public GiaSuc {
public:
    Cuu(int soLuong = 0);
    ~Cuu();

    string Keu() const override;
    void SinhCon() override;
    void ChoSua() override;
};

#endif
