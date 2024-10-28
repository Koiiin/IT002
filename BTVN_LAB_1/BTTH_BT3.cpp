#include <iostream>
#include <vector>
using namespace std;

struct PhanSo {
    int tu, mau; // Tử số và mẫu số của phân số
};

/**
 * Hàm tính tích của hai phân số mà không rút gọn
 * @param ps1 Phân số thứ nhất
 * @param ps2 Phân số thứ hai
 * @return Phân số là tích của hai phân số đầu vào (không rút gọn)
 */
PhanSo TichPhanSo(const PhanSo& ps1, const PhanSo& ps2) {
    PhanSo kq;
    kq.tu = ps1.tu * ps2.tu;    // Tử số kết quả là tích của tử số hai phân số đầu vào
    kq.mau = ps1.mau * ps2.mau; // Mẫu số kết quả là tích của mẫu số hai phân số đầu vào
    return kq;
}

/**
 * Hàm kiểm tra nếu tích các phân số trong tập con bằng phân số đích
 * @param tapCon Tập con các phân số được chọn
 * @param phanSoDich Phân số đích cần so sánh
 * @return true nếu tích của các phân số trong tập con bằng phân số đích, ngược lại là false
 */
bool KiemTraTich(const vector<PhanSo>& tapCon, const PhanSo& phanSoDich) {
    PhanSo tich = {1, 1}; // Khởi tạo phân số tích là 1/1
    for (const auto& ps : tapCon) {
        tich = TichPhanSo(tich, ps); // Tính tích của tất cả các phân số trong tập con
    }
    // So sánh tử và mẫu của tích với tử và mẫu của phân số đích
    return tich.tu == phanSoDich.tu && tich.mau == phanSoDich.mau;
}

/**
 * Hàm tìm tập hợp con của danh sách phân số có tích bằng phân số đích và có số lượng phần tử ít nhất
 * @param danhSach Danh sách các phân số đầu vào
 * @param phanSoDich Phân số đích cần đạt được thông qua tích
 * 
 * In ra tập hợp con thỏa mãn có số lượng phần tử ít nhất hoặc thông báo không tìm thấy tập hợp nào thỏa mãn
 */
void TimTapHopCon(const vector<PhanSo>& danhSach, const PhanSo& phanSoDich) {
    int n = danhSach.size();  // Số lượng phân số trong danh sách
    vector<PhanSo> ketQua;    // Tập hợp con thỏa mãn kết quả
    int minSize = n + 1;      // Khởi tạo kích thước tối thiểu là lớn hơn số phân số

    // Duyệt qua tất cả các tổ hợp con của danh sách phân số
    for (int i = 1; i < (1 << n); ++i) {
        vector<PhanSo> tapCon;
        for (int j = 0; j < n; ++j) {
            // Kiểm tra xem phân số tại vị trí j có trong tập con được biểu diễn bởi bitmask i không
            if (i & (1 << j)) {
                tapCon.push_back(danhSach[j]); // Thêm phân số vào tập con nếu bit j của i được bật
            }
        }
        // Kiểm tra nếu tích của các phân số trong tập con bằng phân số đích và kích thước tập con nhỏ nhất
        if (KiemTraTich(tapCon, phanSoDich) && tapCon.size() < minSize) {
            ketQua = tapCon;
            minSize = tapCon.size(); // Cập nhật kích thước tối thiểu
        }
    }

    // In ra kết quả
    if (!ketQua.empty()) {
        cout << "Tap hop con thoa man co so luong it nhat:\n";
        for (const auto& ps : ketQua) {
            cout << ps.tu << "/" << ps.mau << " ";
        }
        cout << endl;
    } else {
        cout << "Khong co tap hop con thoa man\n";
    }
}

int main() {
    int n;
    cout << "Nhap so luong phan so: ";
    cin >> n;

    vector<PhanSo> danhSach(n); // Khởi tạo danh sách phân số
    for (int i = 0; i < n; ++i) {
        cout << "Nhap tu so va mau so cua phan so thu " << i + 1 << ": ";
        cin >> danhSach[i].tu >> danhSach[i].mau; // Nhập tử số và mẫu số của từng phân số
    }

    PhanSo phanSoDich;
    cout << "Nhap tu so va mau so cua phan so dich: ";
    cin >> phanSoDich.tu >> phanSoDich.mau; // Nhập tử số và mẫu số của phân số đích

    // Tìm tập hợp con thỏa mãn điều kiện và in ra
    TimTapHopCon(danhSach, phanSoDich);

    return 0;
}
