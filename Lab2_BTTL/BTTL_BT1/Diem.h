// Diem.h
#ifndef DIEM_H
#define DIEM_H

class Diem {
private:
    int iHoanh; // Tọa độ hoành (x)
    int iTung;  // Tọa độ tung (y)

public:
    // Constructors
    // Constructor mặc định
    // Chức năng: Khởi tạo đối tượng Diem với tọa độ mặc định (0, 0).
    Diem();

    // Constructor với tham số
    // Đầu vào:
    // - Hoanh: tọa độ hoành (x)
    // - Tung: tọa độ tung (y)
    // Chức năng: Khởi tạo một đối tượng Diem với tọa độ được chỉ định.
    Diem(int Hoanh, int Tung);

    // Constructor sao chép
    // Đầu vào:
    // - x: đối tượng Diem để sao chép
    // Chức năng: Tạo một đối tượng Diem mới từ một đối tượng đã tồn tại.
    Diem(const Diem& x);

    // Phương thức
    // Xuất tọa độ điểm
    // Chức năng: In ra tọa độ của điểm.
    void Xuat() const;

    // Lấy tọa độ tung
    // Đầu ra: Tọa độ tung (int)
    int GetTungDo() const;

    // Lấy tọa độ hoành
    // Đầu ra: Tọa độ hoành (int)
    int GetHoanhDo() const;

    // Thiết lập tọa độ tung
    // Đầu vào:
    // - Tung: giá trị mới cho tọa độ tung
    // Chức năng: Cập nhật tọa độ tung của điểm.
    void SetTungDo(int Tung);

    // Thiết lập tọa độ hoành
    // Đầu vào:
    // - Hoanh: giá trị mới cho tọa độ hoành
    // Chức năng: Cập nhật tọa độ hoành của điểm.
    void SetHoanhDo(int Hoanh);

    // Phương thức tính tiền điểm
    // Đầu vào:
    // - dHoanh: độ dịch chuyển theo trục hoành
    // - dTung: độ dịch chuyển theo trục tung
    // Chức năng: Cập nhật tọa độ điểm bằng cách dịch chuyển nó theo các giá trị cho trước.
    void TinhTien(int dHoanh, int dTung);
};

#endif
