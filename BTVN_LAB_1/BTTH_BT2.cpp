#include <iostream>
#include <vector>
#include <algorithm>
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
    return ps.mau != 0;
}

/**
 * Chuẩn hóa phân số để mẫu số dương
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
 * Nhập giá trị cho một phân số từ bàn phím và chuẩn hóa
 * Đầu vào: Phân số `ps` sẽ được nhập giá trị
 * Đầu ra: Phân số với tử số và mẫu số hợp lệ, với mẫu số khác 0 và được chuẩn hóa mẫu dương
 */
void NhapPhanSo(PhanSo &ps) {
    cout << "Nhap tu so: ";
    cin >> ps.tu;
    cout << "Nhap mau so: ";
    while (true) {
        cin >> ps.mau;
        if (checkMauSo(ps)) break;
        else cout << "Mau so khong the la 0. Nhap lai: ";
    }
    ChuanHoa(ps); // Chuẩn hóa mẫu số dương sau khi nhập
}

/**
 * So sánh hai phân số
 * Đầu vào: Phân số `a` và `b` cần so sánh
 * Đầu ra: `true` nếu `a` nhỏ hơn `b`, `false` nếu ngược lại
 * Phương pháp: So sánh bằng tích chéo của tử và mẫu
 */
bool SoSanhPhanSo(const PhanSo &a, const PhanSo &b) {
    return a.tu * b.mau < b.tu * a.mau;
}

int main() {
    int n, k;
    cout << "Nhap so luong phan so: ";
    cin >> n;
    cout << "Nhap gia tri k: ";
    cin >> k;

    vector<PhanSo> DanhSach(n); // Tạo danh sách phân số với n phần tử

    // Nhập từng phân số vào danh sách
    for (int i = 0; i < n; ++i) {
        cout << "Nhap phan so thu " << i + 1 << ":\n";
        NhapPhanSo(DanhSach[i]);
    }

    // Sắp xếp danh sách phân số theo thứ tự tăng dần
    sort(DanhSach.begin(), DanhSach.end(), SoSanhPhanSo);

    // Kiểm tra điều kiện của `k` trong khoảng hợp lệ
    if (k > 0 && k <= n) {
        PhanSo minK = DanhSach[k - 1];         // Phân số bé thứ k
        PhanSo maxK = DanhSach[n - k];         // Phân số lớn thứ k
        cout << "Phan so be thu " << k << ": " << minK.tu << "/" << minK.mau << '\n';
        cout << "Phan so lon thu " << k << ": " << maxK.tu << "/" << maxK.mau << '\n';
    } else {
        cout << "Khong ton tai phan so thu " << k << " trong danh sach.\n";
    }

    return 0;
}
