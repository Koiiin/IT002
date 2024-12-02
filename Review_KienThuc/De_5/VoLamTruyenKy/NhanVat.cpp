#include "NhanVat.h"
using namespace std;

NhanVat::NhanVat(const string& name, const string& monPhai, int level) : Ten(name), MonPhai(monPhai), SinhVat(level, "") {
    Hanh = NguHanh::LayNguHanhTuMonPhai(monPhai);
}

string NhanVat::Get_Ten() const { return Ten; }
string NhanVat::Get_MonPhai() const { return MonPhai; }
string NhanVat::Get_Hanh() const { return Hanh; }
int NhanVat::Get_CapDo() const { return CapDo; }
double NhanVat::TinhSatThuong() const { return CapDo * 5; }

void NhanVat::HienThiThongTin() const {
    cout << "\n------------------------------------------------\n";
    cout << "Ten: " << Ten << endl;
    cout << "Mon Phai: " << Get_MonPhai() << endl;
    cout << "Ngu Hanh: " << Get_Hanh() << endl;
    cout << "Cap Do: " << Get_CapDo() << endl;
    cout << "Sat thuong goc: " << TinhSatThuong() << endl;
    cout << "\n------------------------------------------------\n";
}
