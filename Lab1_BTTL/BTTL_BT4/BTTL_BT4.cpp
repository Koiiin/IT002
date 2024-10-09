#include <iostream>
#include <cmath>  

using namespace std;

// Hàm tính sin(x) theo chuỗi Taylor với độ chính xác cho trước
double calculateSin(double x, double accuracy = 0.00001) {
    double sin_x = 0;       // Kết quả của sin(x), khởi tạo bằng 0
    double term = x;        // Thành phần đầu tiên của chuỗi là x (tương ứng với n = 0)
    int n = 0;              // Biến đếm n, bắt đầu từ 0
    int sign = 1;           // Dấu của mỗi phần tử trong chuỗi, bắt đầu từ dương (+)

    // Vòng lặp chạy cho đến khi giá trị của phần tử trong chuỗi nhỏ hơn độ chính xác yêu cầu
    while (fabs(term) >= accuracy) {
        sin_x += sign * term;  // Cộng hoặc trừ phần tử hiện tại vào kết quả sin_x
        n++;                   // Tăng n lên để chuyển sang phần tử tiếp theo
        sign *= -1;            // Đổi dấu của phần tử tiếp theo (luân phiên giữa + và -)

        // Tính phần tử tiếp theo trong chuỗi Taylor
        // term = (x^(2n+1)) / (2n+1)!
        term = pow(x, 2 * n + 1) / tgamma(2 * n + 2);  // tgamma(k) trả về (k-1)!, do đó dùng tgamma(2n+2) để tính (2n+1)!
    }

    return sin_x;  // Trả về kết quả của sin(x) sau khi đạt được độ chính xác
}

int main() {
    double x;  // Biến lưu giá trị x cần tính sin
    cout << "Nhap gia tri x: ";  // Yêu cầu người dùng nhập giá trị x
    cin >> x;

    // Gọi hàm calculateSin để tính giá trị sin(x) với chuỗi Taylor
    double sin_x = calculateSin(x);
    
    // In ra kết quả tính toán của sin(x)
    cout << "Sin(" << x << ") = " << sin_x << '\n';

    return 0;
}
