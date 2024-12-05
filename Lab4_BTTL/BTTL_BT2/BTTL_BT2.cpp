#include "KhachSan.h"
#include "Deluxe.h"
#include "Premium.h"
#include "Business.h"
#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

int main() {
    vector<KhachSan*> danhSachPhong;
    int choice;

    cout << "Nhap danh sach cac phong (0 de ket thuc):\n";
    while (true) {
        cout << "1. Phong Deluxe\n";
        cout << "2. Phong Premium\n";
        cout << "3. Phong Business\n";
        cout << "Nhap loai phong: ";
        cin >> choice;

        if (choice == 0) break;

        int soDem;
        double phiDV = 0, phiPV = 0;

        cout << "Nhap so dem: ";
        cin >> soDem;

        if (choice == 1) {
            cout << "Nhap phi dich vu: ";
            cin >> phiDV;
            cout << "Nhap phi phuc vu: ";
            cin >> phiPV;
            danhSachPhong.push_back(new Deluxe(soDem, phiDV, phiPV));
        }
        else if (choice == 2) {
            cout << "Nhap phi dich vu: ";
            cin >> phiDV;
            danhSachPhong.push_back(new Premium(soDem, phiDV));
        }
        else if (choice == 3) {
            danhSachPhong.push_back(new Business(soDem));
        }
        else {
            cout << "Lua chon khong hop le.\n";
        }
    }

    double doanhThuDeluxe = 0, doanhThuPremium = 0, doanhThuBusiness = 0;
    for (KhachSan* phong : danhSachPhong) {
        Deluxe* dlx = dynamic_cast<Deluxe*>(phong);
        Premium* prm = dynamic_cast<Premium*>(phong);
        Business* bns = dynamic_cast<Business*>(phong);

        if (dlx) doanhThuDeluxe += dlx->TinhDoanhThu();
        else if (prm) doanhThuPremium += prm->TinhDoanhThu();
        else if (bns) doanhThuBusiness += bns->TinhDoanhThu();
    }

    cout << fixed << setprecision(2);
    cout << "Doanh thu Deluxe: " << doanhThuDeluxe << " VND\n";
    cout << "Doanh thu Premium: " << doanhThuPremium << " VND\n";
    cout << "Doanh thu Business: " << doanhThuBusiness << " VND\n";

    if (doanhThuDeluxe >= doanhThuPremium && doanhThuDeluxe >= doanhThuBusiness)
        cout << "Loai phong Deluxe co doanh thu cao nhat.\n";
    else if (doanhThuPremium >= doanhThuDeluxe && doanhThuPremium >= doanhThuBusiness)
        cout << "Loai phong Premium co doanh thu cao nhat.\n";
    else
        cout << "Loai phong Business co doanh thu cao nhat.\n";

    return 0;
}
