#include "ThiSinh.h"
#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;  // Số lượng thí sinh
    cout << "Nhap so luong thi sinh: ";
    cin >> n;  // Nhập số lượng thí sinh
    cin.ignore();  // Xóa ký tự newline trong bộ đệm

    // Cấp phát bộ nhớ cho mảng động chứa thông tin thí sinh
    ThiSinh* ds = new ThiSinh[n];

    // Nhập thông tin cho từng thí sinh
    for (int i = 0; i < n; i++) {
        cout << "Nhap thong tin thi sinh thu " << i + 1 << ": " << '\n';
        ds[i].Nhap();  // Gọi hàm Nhap() để nhập thông tin thí sinh
    }

    // Xuất danh sách thí sinh có tổng điểm > 15
    cout << "\nDanh sach thi sinh co tong diem > 15: " << '\n';
    for (int i = 0; i < n; i++) {
        if (ds[i].Tong() > 15) {  // Kiểm tra tổng điểm
            ds[i].Xuat();  // Xuất thông tin thí sinh nếu tổng điểm > 15
        }
    }

    // Tìm thí sinh có tổng điểm cao nhất
    int idxMax = 0;  // Biến lưu chỉ số thí sinh có tổng điểm cao nhất
    for (int i = 1; i < n; i++) {
        if (ds[i].Tong() > ds[idxMax].Tong()) {  // So sánh tổng điểm
            idxMax = i;  // Cập nhật chỉ số nếu tìm thấy thí sinh có tổng điểm cao hơn
        }
    }

    // Xuất thông tin thí sinh có tổng điểm cao nhất
    cout << "\nThi sinh co tong diem cao nhat: " << '\n';
    ds[idxMax].Xuat();  // Xuất thông tin thí sinh có tổng điểm cao nhất
    cout << "Thong tin thi sinh co diem cao nhat: \n";
    ds[idxMax].Xuat();  // Xuất lại thông tin thí sinh có tổng điểm cao nhất

    delete[] ds;  // Giải phóng bộ nhớ đã cấp phát
    return 0;  // Kết thúc chương trình
}
