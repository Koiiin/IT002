#include <iostream>
#include <vector>
using namespace std;

struct PhanSo {
    int tu;  // Tử số của phân số
    int mau; // Mẫu số của phân số
};

/**
 * Kiểm tra mẫu số của phân số
 * Đầu vào: Phân số `ps` cần kiểm tra
 * Đầu ra: `true` nếu mẫu số khác 0, `false` nếu mẫu số bằng 0
 */
bool checkMauSo(PhanSo &ps) {
    if (ps.mau == 0) { return false; }
    return true;
}

/**
 * Chuẩn hóa phân số về dạng mẫu dương
 * Đầu vào: Phân số `ps` cần chuẩn hóa
 * Đầu ra: Phân số với mẫu số dương (nếu mẫu âm thì tử và mẫu đều đổi dấu)
 */
void ChuanHoa(PhanSo &ps) {
    if (ps.mau < 0) {
        ps.tu = -ps.tu;
        ps.mau = -ps.mau;
    }
}

/**
 * Nhập giá trị cho một phân số từ bàn phím
 * Đầu vào: Phân số `ps` sẽ được nhập giá trị
 * Đầu ra: Phân số có tử số và mẫu số hợp lệ, với mẫu số khác 0
 */
void NhapPhanSo(PhanSo &ps) {
    cout << "Nhap tu so: ";
    cin >> ps.tu;
    cout << "Nhap mau so: ";
    while (true) {
        cin >> ps.mau;
        if (checkMauSo(ps)) { 
            break; 
        } else { 
            cout << "Mau so khong the la 0\n"; 
            cout << "Nhap lai mau so: ";
        }
    }

    ChuanHoa(ps); // Đảm bảo mẫu số dương sau khi nhập
}

/**
 * Tìm và in ra phân số lớn nhất và nhỏ nhất từ danh sách phân số
 * Đầu vào: `ds` là danh sách các phân số, `n` là số lượng phân số trong danh sách
 * Đầu ra: In ra màn hình phân số có giá trị lớn nhất và nhỏ nhất
 * Phương pháp: So sánh các phân số bằng cách sử dụng tích chéo của tử và mẫu
 */
void MaxMin(const vector<PhanSo>& ds, int n) {
    // Khởi tạo phân số lớn nhất và nhỏ nhất là phân số đầu tiên
    PhanSo maxPS = ds[0];
    PhanSo minPS = ds[0];

    for (int i = 1; i < n; ++i) {
        // So sánh phân số hiện tại với maxPS
        if (ds[i].tu * maxPS.mau > maxPS.tu * ds[i].mau) {
            maxPS = ds[i];
        }
        // So sánh phân số hiện tại với minPS
        if (ds[i].tu * minPS.mau < minPS.tu * ds[i].mau) {
            minPS = ds[i];
        }
    }

    // In ra phân số có giá trị nhỏ nhất và lớn nhất
    cout << "Phan so co gia tri nho nhat: " << minPS.tu << "/" << minPS.mau << '\n';
    cout << "Phan so co gia tri lon nhat: " << maxPS.tu << "/" << maxPS.mau << '\n';
}

int main() {
    int n;
    cout << "Nhap so luong phan so: ";
    cin >> n;

    // Khởi tạo danh sách phân số với n phần tử
    vector<PhanSo> dsPhanSo(n);

    // Nhập từng phân số vào danh sách
    for (int i = 0; i < n; ++i) {
        cout << "-------------------------------\n";
        cout << "Nhap phan so thu " << i + 1 << ": \n";
        NhapPhanSo(dsPhanSo[i]);
    }

    // Tìm và hiển thị phân số lớn nhất, nhỏ nhất
    MaxMin(dsPhanSo, n);

    return 0;
}
