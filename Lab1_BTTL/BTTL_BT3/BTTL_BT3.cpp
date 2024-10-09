#include <iostream>  // Thư viện nhập xuất chuẩn
using namespace std;

// Hàm kiểm tra nếu mẫu số bằng 0
void checkDenominator(int mau) {
    if (mau == 0) {
        cout << "Mau khong the bang 0" << endl;
        exit(1);  // Kết thúc chương trình nếu mẫu số bằng 0
    }
}

// Hàm nhập phân số
// Tham chiếu (&) được sử dụng để thay đổi giá trị của tử và mẫu số truyền từ hàm main
void nhapPhanSo(int &tu, int &mau) {
    cout << "Nhap tu so: ";  // Yêu cầu người dùng nhập tử số
    cin >> tu;               // Nhập tử số từ người dùng
    cout << "Nhap mau so: "; // Yêu cầu người dùng nhập mẫu số
    cin >> mau;              // Nhập mẫu số từ người dùng
    checkDenominator(mau);   // Kiểm tra xem mẫu số có bằng 0 không
}

// Hàm tính tổng hai phân số
// Tổng của hai phân số: (tu1/mau1) + (tu2/mau2) = (tu1*mau2 + tu2*mau1) / (mau1*mau2)
void tongPhanSo(int tu1, int mau1, int tu2, int mau2, int &tu_ketqua, int &mau_ketqua) {
    tu_ketqua = (tu1 * mau2) + (tu2 * mau1);  // Tính tử số của tổng
    mau_ketqua = mau1 * mau2;                 // Tính mẫu số của tổng
}

// Hàm tính hiệu hai phân số
// Hiệu của hai phân số: (tu1/mau1) - (tu2/mau2) = (tu1*mau2 - tu2*mau1) / (mau1*mau2)
void hieuPhanSo(int tu1, int mau1, int tu2, int mau2, int &tu_ketqua, int &mau_ketqua) {
    tu_ketqua = (tu1 * mau2) - (tu2 * mau1);  // Tính tử số của hiệu
    mau_ketqua = mau1 * mau2;                 // Tính mẫu số của hiệu
}

// Hàm tính tích hai phân số
// Tích của hai phân số: (tu1/mau1) * (tu2/mau2) = (tu1*tu2) / (mau1*mau2)
void tichPhanSo(int tu1, int mau1, int tu2, int mau2, int &tu_ketqua, int &mau_ketqua) {
    tu_ketqua = tu1 * tu2;  // Tính tử số của tích
    mau_ketqua = mau1 * mau2;  // Tính mẫu số của tích
}

// Hàm tính thương hai phân số
// Thương của hai phân số: (tu1/mau1) / (tu2/mau2) = (tu1*mau2) / (mau1*tu2)
void thuongPhanSo(int tu1, int mau1, int tu2, int mau2, int &tu_ketqua, int &mau_ketqua) {
    tu_ketqua = tu1 * mau2;  // Tính tử số của thương
    mau_ketqua = mau1 * tu2;  // Tính mẫu số của thương
    checkDenominator(mau_ketqua);  // Kiểm tra nếu mẫu số của thương bằng 0
}

// Hàm xuất phân số
// In ra phân số dưới dạng "tử/mẫu"
void xuatPhanSo(int tu, int mau) {
    cout << tu << "/" << mau << '\n';  // In phân số theo định dạng "tu/mau"
}

int main() {
    int tu1, mau1, tu2, mau2;
    int tu_ketqua, mau_ketqua;

    // Nhập phân số thứ nhất từ người dùng
    cout << "Nhap Phan So Thu 1: \n";   // Yêu cầu nhập phân số thứ nhất
    nhapPhanSo(tu1, mau1);              // Gọi hàm nhập phân số thứ nhất

    // Nhập phân số thứ hai từ người dùng
    cout << "Nhap Phan So Thu 2: \n";   // Yêu cầu nhập phân số thứ hai
    nhapPhanSo(tu2, mau2);              // Gọi hàm nhập phân số thứ hai

    // Tính và in tổng hai phân số
    cout << "Tong 2 Phan So: \n";
    tongPhanSo(tu1, mau1, tu2, mau2, tu_ketqua, mau_ketqua);  // Gọi hàm tính tổng
    xuatPhanSo(tu_ketqua, mau_ketqua);  // Xuất kết quả tổng

    // Tính và in hiệu hai phân số
    cout << "Hieu 2 Phan So: \n";
    hieuPhanSo(tu1, mau1, tu2, mau2, tu_ketqua, mau_ketqua);  // Gọi hàm tính hiệu
    xuatPhanSo(tu_ketqua, mau_ketqua);  // Xuất kết quả hiệu

    // Tính và in tích hai phân số
    cout << "Tich 2 Phan So: \n";
    tichPhanSo(tu1, mau1, tu2, mau2, tu_ketqua, mau_ketqua);  // Gọi hàm tính tích
    xuatPhanSo(tu_ketqua, mau_ketqua);  // Xuất kết quả tích

    // Tính và in thương hai phân số
    cout << "Thuong 2 Phan So: \n";
    thuongPhanSo(tu1, mau1, tu2, mau2, tu_ketqua, mau_ketqua);  // Gọi hàm tính thương
    xuatPhanSo(tu_ketqua, mau_ketqua);  // Xuất kết quả thương

    return 0;  
}
