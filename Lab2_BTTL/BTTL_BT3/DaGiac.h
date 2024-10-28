#ifndef DAGIAC_H
#define DAGIAC_H

#include "Diem.h" // Bao gồm tệp định nghĩa lớp Diem
#include <iostream>
using namespace std;

class DaGiac {
private:
    int n;          // Số lượng đỉnh của đa giác
    Diem* Dinh;    // Con trỏ tới mảng các đỉnh

public:
    /**
     * @brief Constructor mặc định.
     * @details Khởi tạo một đối tượng DaGiac với số lượng đỉnh bằng 0 và không có mảng đỉnh.
     */
    DaGiac();                        

    /**
     * @brief Constructor với tham số.
     * @param soDinh Số lượng đỉnh của đa giác.
     * @details Khởi tạo mảng các đỉnh với số lượng đỉnh được chỉ định.
     */
    DaGiac(int soDinh);              

    /**
     * @brief Destructor.
     * @details Giải phóng bộ nhớ được cấp phát cho mảng các đỉnh.
     */
    ~DaGiac();                       

    /**
     * @brief Nhập thông tin đa giác.
     * @details Hàm này yêu cầu người dùng nhập số lượng đỉnh và tọa độ cho từng đỉnh của đa giác.
     */
    void Nhap();                    

    /**
     * @brief Xuất thông tin đa giác.
     * @details Hàm này in ra tọa độ của tất cả các đỉnh trong đa giác.
     */
    void Xuat() const;              

    /**
     * @brief Tịnh tiến đa giác.
     * @param dX Giá trị tịnh tiến theo trục x.
     * @param dY Giá trị tịnh tiến theo trục y.
     * @details Tăng giá trị x và y của từng đỉnh trong đa giác với các giá trị dX và dY.
     */
    void TinhTien(float dX, float dY); 

    /**
     * @brief Phóng to đa giác.
     * @param TiLe Tỉ lệ phóng to.
     * @details Nhân giá trị tọa độ của từng đỉnh với tỉ lệ TiLe để phóng to đa giác.
     */
    void PhongTo(float TiLe);       

    /**
     * @brief Thu nhỏ đa giác.
     * @param TiLe Tỉ lệ thu nhỏ.
     * @details Chia giá trị tọa độ của từng đỉnh với tỉ lệ TiLe để thu nhỏ đa giác.
     */
    void ThuNho(float TiLe);        

    /**
     * @brief Quay đa giác quanh gốc tọa độ.
     * @param goc Góc quay tính bằng độ.
     * @details Quay từng đỉnh của đa giác quanh gốc tọa độ theo góc goc.
     */
    void Quay(float goc);           
};

#endif // !DAGIAC_H
