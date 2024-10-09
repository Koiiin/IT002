#include <iostream>  // Thư viện chuẩn cho nhập/xuất
using namespace std;

// Hàm nhập phân số
// Nhập tử số và mẫu số từ người dùng
// & sử dụng để truyền tham chiếu, tức là thay đổi trực tiếp giá trị của biến bên ngoài
void nhapPhanSo(int &tu, int &mau) {
    cout << "Nhap tu so: ";   // Yêu cầu người dùng nhập tử số
    cin >> tu;                // Nhận giá trị tử số từ người dùng
    cout << "Nhap mau so: ";  // Yêu cầu người dùng nhập mẫu số
    cin >> mau;               // Nhận giá trị mẫu số từ người dùng
    if (mau == 0) {
        cout << "Mau khong the bang 0" << '\n';
        cout << "Nhap lai phan so: \n";
        nhapPhanSo(tu, mau);
    }    // Kiểm tra mẫu số, đảm bảo không bằng 0
}

// Hàm so sánh hai phân số
// Trả về true nếu phân số 1 lớn hơn hoặc bằng phân số 2
// Trả về false nếu phân số 2 lớn hơn phân số 1
bool soSanhPhanSo(int tu1, int mau1, int tu2, int mau2) {
    // So sánh phân số bằng cách nhân chéo (cross-multiply)
    // Nếu tu1 * mau2 >= tu2 * mau1, phân số thứ nhất lớn hơn hoặc bằng phân số thứ hai
    if (tu1 * mau2 >= tu2 * mau1) {
        return true;  // Phân số thứ nhất lớn hơn hoặc bằng
    } else {
        return false; // Phân số thứ hai lớn hơn
    }
}

// Hàm xuất phân số
// Hiển thị phân số dưới dạng tử số / mẫu số
void xuatPhanSo(int tu, int mau) {
    cout << tu << "/" << mau << endl;  // In phân số theo định dạng "tu/mau"
}

int main() {
    // Khai báo các biến cho tử số và mẫu số của hai phân số
    int tu1, mau1, tu2, mau2;

    // Nhập phân số thứ nhất từ người dùng
    cout << "Nhap Phan So Thu 1: \n";  // Yêu cầu nhập phân số 1
    nhapPhanSo(tu1, mau1);             // Gọi hàm nhapPhanSo để nhập phân số 1

    // Nhập phân số thứ hai từ người dùng
    cout << "Nhap Phan So Thu 2: \n";  // Yêu cầu nhập phân số 2
    nhapPhanSo(tu2, mau2);             // Gọi hàm nhapPhanSo để nhập phân số 2

    // In phân số lớn nhất
    cout << "Phan So Lon Nhat: ";      // In thông báo phân số lớn nhất

    // So sánh hai phân số và in ra phân số lớn hơn
    if (soSanhPhanSo(tu1, mau1, tu2, mau2)) {
        xuatPhanSo(tu1, mau1);  // Nếu phân số 1 lớn hơn hoặc bằng, in phân số 1
    } else {
        xuatPhanSo(tu2, mau2);  // Nếu phân số 2 lớn hơn, in phân số 2
    }

    return 0;  // Kết thúc chương trình
}
