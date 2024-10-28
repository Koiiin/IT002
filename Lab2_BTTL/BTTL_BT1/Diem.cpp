#include "Diem.h"
#include <iostream>
using namespace std;

// Constructor mặc định
Diem::Diem() : iHoanh(0), iTung(0) {}

// Constructor với tham số
// Đầu vào: 
// - Hoanh: tọa độ hoành (x)
// - Tung: tọa độ tung (y)
// Chức năng: Khởi tạo một đối tượng Diem với tọa độ được chỉ định.
Diem::Diem(int Hoanh, int Tung) : iHoanh(Hoanh), iTung(Tung) {}

// Constructor sao chép
// Đầu vào: 
// - x: đối tượng Diem để sao chép
// Chức năng: Tạo một đối tượng Diem mới từ một đối tượng đã tồn tại.
Diem::Diem(const Diem& x) : iHoanh(x.iHoanh), iTung(x.iTung) {}

// Xuất tọa độ điểm
// Chức năng: In ra tọa độ của điểm.
// Đầu ra: Không có (void)
void Diem::Xuat() const {
    cout << "Hoanh do: " << iHoanh << ", Tung do: " << iTung << endl;
}

// Lấy tọa độ tung
// Đầu ra: Tọa độ tung (int)
int Diem::GetTungDo() const {
    return iTung;
}

// Lấy tọa độ hoành
// Đầu ra: Tọa độ hoành (int)
int Diem::GetHoanhDo() const {
    return iHoanh;
}

// Thiết lập tọa độ tung
// Đầu vào: 
// - Tung: giá trị mới cho tọa độ tung
// Chức năng: Cập nhật tọa độ tung của điểm.
void Diem::SetTungDo(int Tung) {
    iTung = Tung;
}

// Thiết lập tọa độ hoành
// Đầu vào: 
// - Hoanh: giá trị mới cho tọa độ hoành
// Chức năng: Cập nhật tọa độ hoành của điểm.
void Diem::SetHoanhDo(int Hoanh) {
    iHoanh = Hoanh;
}

// Phương thức tính tiền điểm
// Đầu vào: 
// - dHoanh: độ dịch chuyển theo trục hoành
// - dTung: độ dịch chuyển theo trục tung
// Chức năng: Cập nhật tọa độ điểm bằng cách dịch chuyển nó theo các giá trị cho trước.
void Diem::TinhTien(int dHoanh, int dTung) {
    iHoanh += dHoanh;
    iTung += dTung;
}
