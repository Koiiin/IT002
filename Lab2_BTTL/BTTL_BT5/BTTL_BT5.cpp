#include "Diem.h"
#include <iostream>
using namespace std;

int main() {
    Diem A; // Tạo một đối tượng điểm A
    A.Nhap(); // Nhập tọa độ cho điểm A

    int n; // Biến lưu số lần chỉ thị
    cout << "Nhap so lan chi thi: "; 
    cin >> n; // Nhập số lần chỉ thị từ người dùng
    
    // Vòng lặp thực hiện các chỉ thị cho điểm A
    while (n != 0) {
        int choice; // Biến để lưu lựa chọn của người dùng
        cout << "Nhap chi thi: "; 
        cin >> choice; // Nhập chỉ thị từ người dùng

        // Nếu lựa chọn là 1, nhân tọa độ điểm với 2 và xuất ra
        if (choice == 1) {
            A.Set(2); // Nhân tọa độ điểm với 2
            A.Xuat(); // Xuất tọa độ sau khi nhân

        // Nếu lựa chọn là 2, nhân tọa độ điểm với 0 (đặt điểm về (0,0)) và xuất ra
        } else if (choice == 2) {
            A.Set(0); // Nhân tọa độ điểm với 0
            A.Xuat(); // Xuất tọa độ sau khi đặt về (0, 0)

        // Nếu lựa chọn là 3, dịch chuyển điểm theo một hướng và khoảng cách cụ thể
        } else if (choice == 3) {
            int k; // Biến để lưu trục dịch chuyển
            float d; // Biến để lưu khoảng cách dịch chuyển
            cout << "Nhap huong tinh tien: "; 
            cin >> k; // Nhập trục (0 cho x, 1 cho y)
            cout << "Nhap do tinh tien: "; 
            cin >> d; // Nhập khoảng cách
            A.TinhTien(k, d); // Dịch chuyển điểm A
            A.Xuat(); // Xuất tọa độ sau khi dịch chuyển
        }

        n--; // Giảm số lần chỉ thị còn lại
    }

    return 0; // Kết thúc chương trình
}
