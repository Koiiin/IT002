#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <regex>
#include <cmath>
#include <chrono>
#include <sstream>

using namespace std;

// Cấu trúc biểu diễn sổ tiết kiệm
struct Savings {
    string account_code;    // Mã số tiết kiệm
    string type;            // Loại tiết kiệm
    string customer_name;   // Họ tên khách hàng
    string cmnd;            // Số CMND
    string time;            // Ngày mở sổ
    double deposit;         // Số tiền gửi
    double lai;             // Lãi suất
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

bool validate_money(const int& money) {
    if (money <= 0) return false;
    return true;
}

bool validate_time(const string& ngay) {
    // Kiểm tra định dạng dd/mm/yyyy
    if (ngay.length() != 10 || ngay[2] != '/' || ngay[5] != '/') {
        return false;
    }

    // Trích xuất ngày, tháng, năm từ chuỗi
    int ngayInt = stoi(ngay.substr(0, 2));  // Ngày (dd)
    int thangInt = stoi(ngay.substr(3, 2)); // Tháng (mm)
    int namInt = stoi(ngay.substr(6, 4));   // Năm (yyyy)

    // Kiểm tra tháng hợp lệ (1 <= thang <= 12)
    if (thangInt < 1 || thangInt > 12) {
        return false;
    }

    // Mảng số ngày tối đa trong từng tháng
    int soNgayToiDaTrongThang[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    // Kiểm tra năm nhuận (tháng 2 có 29 ngày nếu năm nhuận)
    if ((namInt % 4 == 0 && namInt % 100 != 0) || (namInt % 400 == 0)) {
        soNgayToiDaTrongThang[1] = 29;  // Tháng 2 có 29 ngày nếu năm nhuận
    }

    // Kiểm tra ngày có hợp lệ trong tháng đã cho
    if (ngayInt < 1 || ngayInt > soNgayToiDaTrongThang[thangInt - 1]) {
        return false;
    }

    return true;
}

// Hàm tính số tháng giữa hai ngày (ngày mở sổ và ngày hiện tại)
int calculate_time(const string& start_date, const string& end_date) {
    int start_day = stoi(start_date.substr(0, 2));
    int start_month = stoi(start_date.substr(3, 2));
    int start_year = stoi(start_date.substr(6, 4));

    int end_day = stoi(end_date.substr(0, 2));
    int end_month = stoi(end_date.substr(3, 2));
    int end_year = stoi(end_date.substr(6, 4));

    int months = (end_year - start_year) * 12 + (end_month - start_month);
    if (end_day < start_day) months--;  // Nếu ngày kết thúc nhỏ hơn ngày bắt đầu, trừ đi 1 tháng

    return months;
}

// Hàm tính tiền lãi dựa trên thời gian gửi và lãi suất
double calculate_money(const Savings& savings, const string& current_date, double interest_rate_short, double interest_rate_long) {
    int months = calculate_time(savings.time, current_date);

    if (months < 0) {
        cout << "Loi: Ngay nhap vao khong hop le.\n";
        return 0;
    }

    double interest_rate = 0.0;
    if (months <= 6) {
        interest_rate = interest_rate_short;
    } else {
        interest_rate = interest_rate_long;
    }

    // Tính tiền lãi
    double interest = (savings.deposit * interest_rate * months) / 12;
    return interest;
}


// Hàm rút tiền
void withdraw_money(Savings& savings, const string& current_date, double early_withdraw_rate) {
    double withdraw_amount;
    cout << "Nhap so tien muon rut: ";
    cin >> withdraw_amount;

    if (withdraw_amount > savings.deposit) {
        cout << "So tien rut vuot qua so du!\n";
        return;
    }

    int days = calculate_time(savings.time, current_date);
    if (days < 180) {
        cout << "Rut truoc han! Tinh lai suat thap hon.\n";
        savings.deposit -= withdraw_amount;
        cout << "So du con lai: " << savings.deposit << '\n';
    } else {
        savings.deposit -= withdraw_amount;
        cout << "So du con lai: " << savings.deposit << '\n';
    }
}


// Hàm nhập sổ tiết kiệm từ người dùng
// Đầu vào: không có
// Đầu ra: một đối tượng kiểu `Savings` chứa các thông tin nhập vào từ người dùng như mã số tiết kiệm, loại tiết kiệm, họ tên, CMND, và số tiền gửi
Savings input_savings() {
    Savings savings;
    string cmnd_input;
    string time_input;
    double money_input;

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

    // Nhập ngày mở sổ
    do {
        cout << "Nhap ngay mo so (dd/mm/yyyy): ";
        getline(cin, time_input);
        if (!validate_time(time_input)) {
            cout << "Ngay mo khong hop le. Vui long nhap lai.\n";
        }
    } while (!validate_time(time_input));

    // Nhập số tiền gửi
    do {
        cout << "Nhap so tien gui: ";
        cin >> money_input;
        if (!validate_money(money_input)) {
            cout << "So tien khong hop le. Vui long nhap lai.\n";
        }
    } while (!validate_money(money_input));
    savings.deposit = money_input;

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

    string current_date;

    // Nhập ngày hiện tại
    do {
        cout << "Nhap ngay hien tai (dd/mm/yyyy): ";
        getline(cin, current_date);
        if (!validate_time(current_date)) {
            cout << "Ngay hien tai khong hop le. Vui long nhap lai.\n";
        }
    } while (!validate_time(current_date));

    double interest_rate_short = 0.05; // Lãi suất ngắn hạn
    double interest_rate_long = 0.07;  // Lãi suất dài hạn
    double early_withdraw_rate = 0.005; // Lãi suất rút trước hạn


    do {
        // Hiển thị menu
        cout << "1. Nhap So Tiet Kiem\n";
        cout << "2. Hien Thi So Tiet Kiem\n";
        cout << "3. Tinh tien lai\n";
        cout << "4. Rut tien\n";
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
        } else if (choice == 3) {
            for (const auto& savings : savings_list) {
                double interest = calculate_money(savings, current_date, interest_rate_short, interest_rate_long);
                cout << "Ma so: " << savings.account_code << " - Tien lai tinh duoc: " << interest <<'\n';
            }
        } else if (choice == 4) {
            for (auto& savings : savings_list) {
                withdraw_money(savings, current_date, early_withdraw_rate);
            }
        } else if (choice == 0) {
            break;
        }
    } while (choice != 0);   // Vòng lặp dừng khi người dùng chọn 0 (thoát)

    return 0;
}
