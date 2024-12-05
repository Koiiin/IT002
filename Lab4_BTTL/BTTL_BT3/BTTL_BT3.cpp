#include "Bo.h"
#include "Cuu.h"
#include "De.h"
#include <ctime>

int main() {
    srand(time(0));
    int soBo, soCuu, soDe;

    cout << "Nhap so luong Bo: ";
    cin >> soBo;
    cout << "Nhap so luong Cuu: ";
    cin >> soCuu;
    cout << "Nhap so luong De: ";
    cin >> soDe;

    Bo bo(soBo);
    Cuu cuu(soCuu);
    De de(soDe);

    cout << bo.Keu() << endl;
    cout << cuu.Keu() << endl;
    cout << de.Keu() << endl;

    bo.SinhCon();
    cuu.SinhCon();
    de.SinhCon();

    bo.ChoSua();
    cuu.ChoSua();
    de.ChoSua();

    cout << "\nThong ke:" << endl;
    cout << "Bo - Tong so con: " << bo.Getter_SoLuongCon() << ", Tong so sua: " << bo.Getter_Sua() << " lit" << endl;
    cout << "Cuu - Tong so con: " << cuu.Getter_SoLuongCon() << ", Tong so sua: " << cuu.Getter_Sua() << " lit" << endl;
    cout << "De - Tong so con: " << de.Getter_SoLuongCon() << ", Tong so sua: " << de.Getter_Sua() << " lit" << endl;

    return 0;
}
