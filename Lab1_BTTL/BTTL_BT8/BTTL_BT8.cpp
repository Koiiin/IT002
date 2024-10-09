#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <regex>

using namespace std;

// Cấu trúc biểu diễn sổ tiết kiệm
struct Savings {
    string account_code;    // Mã số tiết kiệm
    string type;            // Loại tiết kiệm
    string customer_name;   // Họ tên khách hàng
    string cmnd;            // Số CMND
    double deposit;         // Số tiền gửi
};

// Hàm kiểm tra mã số tiết kiệm hợp lệ (tối đa 5 ký tự, không chứa ký tự đặc biệt)
// Đầu vào: chuỗi `account_code` chứa mã số tiết kiệm cần kiểm tra
// Đầu ra: `true` nếu mã hợp lệ (chỉ bao gồm chữ cái và số, độ dài tối đa 5), `false` nếu không hợp lệ
bool validate_account_code(const string& account_code) {
    regex account_code_pattern("^[A-Za-z0-9]{1,5}$");
    return regex_match(account_code, account_code_pattern);
}

// Hàm kiểm tra số CMND hợp lệ (9 hoặc 12 chữ số)
// Đầu vào: chuỗi `cmnd` chứa số CMND cần kiểm tra
// Đầu ra: `true` nếu CMND hợp lệ (có đúng 9 hoặc 12 chữ số), `false` nếu không hợp lệ
bool validate_cmnd(const string& cmnd) {
    regex cmnd_pattern("^\\d{9}$|^\\d{12}$");
    return regex_match(cmnd, cmnd_pattern);
}

// Hàm nhập sổ tiết kiệm từ người dùng
// Đầu vào: không có
// Đầu ra: một đối tượng kiểu `Savings` chứa các thông tin nhập vào từ người dùng như mã số tiết kiệm, loại tiết kiệm, họ tên, CMND, và số tiền gửi
Savings input_savings() {
    Savings savings;
    string cmnd_input;

    // Nhập mã số tiết kiệm và kiểm tra độ hợp lệ
    do {
        cout << "Nhap ma so: ";
        getline(cin, savings.account_code);
        if (!validate_account_code(savings.account_code)) {
            cout << "Ma so khong hop le. Vui long nhap lai.\n";
        }
    } while (!validate_account_code(savings.account_code));

    // Nhập loại tiết kiệm
    cout << "Nhap loai tiet kiem: ";
    getline(cin, savings.type);

    // Nhập họ tên khách hàng
    cout << "Nhap ho ten khach hang: ";
    getline(cin, savings.customer_name);

    // Nhập số CMND và kiểm tra độ hợp lệ
    do {
        cout << "Nhap CMND: ";
        getline(cin, cmnd_input);
        if (!validate_cmnd(cmnd_input)) {
            cout << "CMND khong hop le. Vui long nhap lai.\n";
        }
    } while (!validate_cmnd(cmnd_input));
    savings.cmnd = cmnd_input;

    // Nhập số tiền gửi
    cout << "Nhap so tien gui: ";
    cin >> savings.deposit;

    // Xóa bộ đệm sau khi nhập số
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    return savings;
}

// Hàm hiển thị thông tin sổ tiết kiệm
// Đầu vào: một đối tượng kiểu `Savings` chứa các thông tin của sổ tiết kiệm
// Đầu ra: không có, chỉ in ra màn hình các thông tin của sổ tiết kiệm bao gồm mã số, loại, họ tên, CMND, và số tiền gửi
void display_savings(const Savings& savings) {
    cout << "Ma So: " << savings.account_code
         << ", Loai: " << savings.type
         << ", Ho Ten: " << savings.customer_name
         << ", CMND: " << savings.cmnd
         << ", So Tien Gui: " << savings.deposit << '\n';
}

int main() {
    vector<Savings> savings_list; // Danh sách sổ tiết kiệm
    int choice;

    do {
        // Hiển thị menu
        cout << "1. Nhap So Tiet Kiem\n";
        cout << "2. Hien Thi So Tiet Kiem\n";
        cout << "0. Thoat\n";
        cout << "Chon Chuc Nang: ";
        cin >> choice;

        // Xóa bộ đệm trước khi đọc tiếp bằng getline để tránh lỗi bỏ qua dòng
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        // Xử lý lựa chọn
        if (choice == 1) {
            Savings savings = input_savings();    // Gọi hàm nhập thông tin sổ tiết kiệm
            savings_list.push_back(savings);      // Thêm sổ tiết kiệm vào danh sách
        } else if (choice == 2) {
            for (const auto& savings : savings_list) {
                display_savings(savings);         // Hiển thị từng sổ tiết kiệm trong danh sách
            }
        }
    } while (choice != 0);   // Vòng lặp dừng khi người dùng chọn 0 (thoát)

    return 0;
}
