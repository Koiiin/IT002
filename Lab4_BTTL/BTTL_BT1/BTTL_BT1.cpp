#include "QuanLy.h"
#include "KySu.h"

int main() {
    QuanLy ql;
    KySu ks;

    cout << "Nhap thong tin Quan Ly:\n";
    ql.Nhap();

    cout << "\nNhap thong tin Ky Su:\n";
    ks.Nhap();

    cout << "\nThong tin Quan Ly:\n";
    ql.Xuat();

    cout << "\nThong tin Ky Su:\n";
    ks.Xuat();

    return 0;
}
