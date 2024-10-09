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
// Trả về false nếu phân số 2 lớn hơn phân số 1}

// Hàm xuất phân số
// Hiển thị phân số dưới dạng tử số / mẫu số
void xuatPhanSo(int tu, int mau) {
    if (mau == 1) {
        cout << tu << '\n';  // Nếu mẫu số là 1, chỉ cần in tử
    } else {
        cout << tu << "/" << mau << '\n';  // In phân số theo định dạng "tu/mau"
    }
}

int gcd(int tu, int mau) {
    if (mau == 0) return tu;
    return gcd(mau, tu % mau);
}

void rutPhanSo(int tu, int mau) {
    int ucln = gcd(tu, mau);
    tu /= ucln;
    mau /= ucln;
    xuatPhanSo(tu, mau);
}

int main() {
    // Khai báo các biến cho tử số và mẫu số của hai phân số
    int tu_so, mau_so;

    // Nhập phân số thứ nhất từ người dùng
    cout << "Nhap Phan So Thu 1: \n";  // Yêu cầu nhập phân số 
    nhapPhanSo(tu_so, mau_so);             // Gọi hàm nhapPhanSo để nhập phân số 1

    cout << "Rut gon phan so: ";
    rutPhanSo(tu_so, mau_so);
    

    return 0;  // Kết thúc chương trình
}
