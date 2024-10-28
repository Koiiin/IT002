#include "Diem.h"
#include <iostream>
using namespace std;

int main() {
    // Khởi tạo các đối tượng Diem
    Diem A;                  // Gọi constructor mặc định, A được khởi tạo với tọa độ (0, 0)
    Diem B(3, 4);            // Gọi constructor với tham số, B được khởi tạo với tọa độ (3, 4)
    Diem C(B);               // Gọi constructor sao chép, C được khởi tạo bằng cách sao chép từ B

    // Xuất tọa độ của từng điểm
    cout << "Diem A: "; 
    A.Xuat();                // In ra tọa độ của điểm A
    cout << "Diem B: "; 
    B.Xuat();                // In ra tọa độ của điểm B
    cout << "Diem C (copy of B): "; 
    C.Xuat();                // In ra tọa độ của điểm C (sao chép từ B)

    // Sử dụng các getter và setter
    A.SetHoanhDo(10);        // Thiết lập tọa độ hoành của A thành 10
    A.SetTungDo(15);         // Thiết lập tọa độ tung của A thành 15
    cout << "Diem A sau khi set hoanh do va tung do: "; 
    A.Xuat();                // In ra tọa độ A sau khi thiết lập lại

    // Tính tiền điểm A
    A.TinhTien(5, -3);       // Dịch chuyển A theo hướng hoành 5 và tung -3
    cout << "Diem A sau khi tinh tien: "; 
    A.Xuat();                // In ra tọa độ A sau khi dịch chuyển

    return 0;                // Kết thúc chương trình
}
