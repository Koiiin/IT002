#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <algorithm>

using namespace std;

// Kiểu dữ liệu biểu diễn ngày
struct Date {
    int day, month, year;
};

// Kiểu dữ liệu biểu diễn sổ tiết kiệm
struct SavingsAccount {
    string accountCode;        // Mã số sổ tiết kiệm
    string typeOfSavings;      // Loại sổ tiết kiệm (ngắn hạn, dài hạn)
    string customerName;       // Tên khách hàng
    int idNumber;              // Số CMND của khách hàng
    Date openingDate;          // Ngày mở sổ
    double depositAmount;      // Số tiền gửi
    double interestRate;       // Lãi suất (%)
    double interest;           // Tiền lãi
};

// Kiểm tra mã sổ hợp lệ (tối đa 5 ký tự và chỉ chứa ký tự số và chữ)
bool validateAccountCode(const string& code) {
    if (code.length() > 5) return false;   // Mã sổ phải có độ dài tối đa là 5 ký tự
    for (char c : code) {                   // Kiểm tra xem các ký tự có phải là chữ hoặc số không
        if (isspace(c) || !isalnum(c)) return false; // Mã sổ không được chứa khoảng trắng và chỉ chứa chữ cái và số
    }
    return true;
}

bool validateIDNumber(int id) {
    string idStr = to_string(id);  // Chuyển đổi số CMND thành chuỗi
    int length = idStr.length();

    // Kiểm tra độ dài CMND (9 hoặc 12 chữ số)
    if (length != 9 && length != 12) {
        return false;
    }

    // Kiểm tra xem CMND chỉ chứa chữ số
    for (char c : idStr) {
        if (!isdigit(c)) {
            return false;
        }
    }

    return true;
}


// Kiểm tra ngày hợp lệ (kiểm tra ngày, tháng, năm hợp lệ)
bool validateDate(Date date) {
    if (date.year < 0 || date.month < 1 || date.month > 12 || date.day < 1 || date.day > 31) return false;
    if (date.month == 2) {  // Kiểm tra tháng 2 có đúng ngày không
        bool leapYear = (date.year % 4 == 0 && date.year % 100 != 0) || (date.year % 400 == 0);
        return date.day <= (leapYear ? 29 : 28);
    }
    if (date.month == 4 || date.month == 6 || date.month == 9 || date.month == 11) {  // Kiểm tra các tháng có 30 ngày
        return date.day <= 30;
    }
    return true;
}

// Nhập ngày hợp lệ
Date inputDate() {
    Date date;
    do {
        cout << "Nhap ngay mo so (dd mm yyyy): ";
        cin >> date.day >> date.month >> date.year;
    } while (!validateDate(date));  // Lặp lại cho đến khi ngày nhập hợp lệ
    return date;
}

// Nhập thông tin sổ tiết kiệm
void inputSavingsAccount(SavingsAccount& account) {
    do {
        cout << "Nhap ma so (toi da 5 ky tu): ";
        cin >> account.accountCode;
    } while (!validateAccountCode(account.accountCode));  // Kiểm tra mã sổ hợp lệ

    cout << "Nhap loai tiet kiem (toi da 10 ky tu): ";
    cin.ignore();
    getline(cin, account.typeOfSavings);  // Nhập loại tiết kiệm

    cout << "Nhap ho ten khach hang: ";
    getline(cin, account.customerName);  // Nhập tên khách hàng

    do {
        cout << "Nhap so CMND (9 hoac 12 chu so): ";
        cin >> account.idNumber;
    } while (!validateIDNumber(account.idNumber));  // Kiểm tra CMND hợp lệ

    account.openingDate = inputDate();  // Nhập ngày mở sổ

    do {
        cout << "Nhap so tien gui: ";
        cin >> account.depositAmount;
    } while (account.depositAmount <= 0);  // Kiểm tra số tiền gửi phải lớn hơn 0

    account.interest = 0;  // Tiền lãi ban đầu là 0
}

// Xuất thông tin sổ tiết kiệm
void displaySavingsAccount(const SavingsAccount& account) {
    cout << "Ma so: " << account.accountCode << '\n';
    cout << "Loai tiet kiem: " << account.typeOfSavings << '\n';
    cout << "Ho ten khach hang: " << account.customerName << '\n';
    cout << "CMND: " << account.idNumber << '\n';
    cout << "Ngay mo so: " << account.openingDate.day << "/" << account.openingDate.month << "/" << account.openingDate.year << '\n';
    cout << "So tien gui: " << account.depositAmount << '\n';
    cout << "Lai suat: " << account.interestRate << "%" << '\n';
    cout << "Tien lai: " << account.interest << '\n';
}

// Lấy ngày hiện tại
Date getCurrentDate() {
    time_t now = time(0);  // Lấy thời gian hiện tại
    tm* ltm = localtime(&now);  // Chuyển đổi thời gian hiện tại thành cấu trúc tm
    Date currentDate;
    currentDate.day = ltm->tm_mday;
    currentDate.month = 1 + ltm->tm_mon;
    currentDate.year = 1900 + ltm->tm_year;
    return currentDate;
}

// Tính số ngày giữa hai ngày
int calculateDaysBetween(Date start, Date end) {
    tm start_tm = {0, 0, 12, start.day, start.month - 1, start.year - 1900};  // Chuyển ngày bắt đầu thành tm
    tm end_tm = {0, 0, 12, end.day, end.month - 1, end.year - 1900};  // Chuyển ngày kết thúc thành tm

    time_t time1 = mktime(&start_tm);  // Chuyển đổi tm thành time_t
    time_t time2 = mktime(&end_tm);

    const int SECONDS_PER_DAY = 60 * 60 * 24;
    return difftime(time2, time1) / SECONDS_PER_DAY;  // Tính số ngày giữa hai thời điểm
}

// Cập nhật lãi suất
void updateInterestRate(SavingsAccount& account) {
    if (account.typeOfSavings == "ngan han") {
        cout << "Nhap lai suat ngan han (%/nam): ";
        cin >> account.interestRate;
    } else if (account.typeOfSavings == "dai han") {
        cout << "Nhap lai suat dai han (%/nam): ";
        cin >> account.interestRate;
    } else {
        cout << "Loai tiet kiem khong hop le!\n";
    }
}

// Tính tiền lãi
void calculateInterest(SavingsAccount& account) {
    Date currentDate = getCurrentDate();  // Lấy ngày hiện tại
    int daysDeposited = calculateDaysBetween(account.openingDate, currentDate);  // Tính số ngày đã gửi tiền

    if (daysDeposited <= 0) {
        cout << "Khong the tinh lai, ngay gui khong hop le.\n";
        return;
    }
    
    account.interest = account.depositAmount * (account.interestRate / 100) * (daysDeposited / 365.0);  // Tính lãi suất dựa trên số ngày đã gửi tiền
}

// Rút tiền
void withdrawMoney(SavingsAccount& account) {
    double amount;
    cout << "Nhap so tien muon rut: ";
    cin >> amount;

    if (amount > account.depositAmount) {
        cout << "So tien rut vuot qua so du!\n";  // Kiểm tra số tiền rút có vượt quá số dư không
    } else {
        account.depositAmount -= amount;  // Cập nhật lại số tiền gửi sau khi rút
        cout << "Rut tien thanh cong!\n";
    }
}

// Tìm kiếm sổ tiết kiệm theo CMND
void searchByID(const vector<SavingsAccount>& accounts, int id) {
    for (const auto& account : accounts) {
        if (account.idNumber == id) {  // Kiểm tra CMND
            displaySavingsAccount(account);  // Hiển thị thông tin sổ tiết kiệm nếu tìm thấy
        }
    }
}

// Tìm kiếm sổ tiết kiệm theo mã sổ
void searchByAccountCode(const vector<SavingsAccount>& accounts, const string& code) {
    for (const auto& account : accounts) {
        if (account.accountCode == code) {  // Kiểm tra mã sổ
            displaySavingsAccount(account);  // Hiển thị thông tin sổ tiết kiệm nếu tìm thấy
        }
    }
}

// Liệt kê các sổ tiết kiệm mở trong khoảng thời gian
void listAccountsByDate(const vector<SavingsAccount>& accounts, Date start, Date end) {
    for (const auto& account : accounts) {
        if (calculateDaysBetween(start, account.openingDate) >= 0 && calculateDaysBetween(account.openingDate, end) >= 0) {
            displaySavingsAccount(account);  // Hiển thị thông tin các sổ tiết kiệm nằm trong khoảng thời gian
        }
    }
}

// Sắp xếp sổ tiết kiệm theo số tiền gửi giảm dần
bool compareByDepositAmount(const SavingsAccount& a, const SavingsAccount& b) {
    return a.depositAmount > b.depositAmount;  // So sánh số tiền gửi, sổ có số tiền gửi lớn hơn sẽ đứng trước
}

// Sắp xếp danh sách sổ tiết kiệm theo số tiền gửi
void sortAccountsByDepositAmount(vector<SavingsAccount>& accounts) {
    sort(accounts.begin(), accounts.end(), compareByDepositAmount);  // Sử dụng hàm sort để sắp xếp
    cout << "Da sap xep theo so tien gui.\n";  // Thông báo đã sắp xếp
}

// Sắp xếp sổ tiết kiệm theo ngày mở sổ tăng dần
bool compareByOpeningDate(const SavingsAccount& a, const SavingsAccount& b) {
    return calculateDaysBetween(a.openingDate, b.openingDate) < 0;  // So sánh ngày mở sổ, sổ mở trước sẽ đứng trước
}

// Sắp xếp danh sách sổ tiết kiệm theo ngày mở sổ
void sortAccountsByOpeningDate(vector<SavingsAccount>& accounts) {
    sort(accounts.begin(), accounts.end(), compareByOpeningDate);  // Sử dụng hàm sort để sắp xếp
    cout << "Da sap xep theo ngay mo so.\n";  // Thông báo đã sắp xếp
}

int main() {
    vector<SavingsAccount> accounts;  // Danh sách các sổ tiết kiệm
    int choice;

    do {
        cout << "1. Nhap so tiet kiem\n";
        cout << "2. Xuat danh sach so tiet kiem\n";
        cout << "3. Cap nhat lai suat\n";
        cout << "4. Tinh tien lai\n";
        cout << "5. Rut tien\n";
        cout << "6. Tim kiem theo CMND\n";
        cout << "7. Tim kiem theo ma so\n";
        cout << "8. Liet ke theo thoi gian\n";
        cout << "9. Sap xep theo so tien gui\n";
        cout << "10. Sap xep theo ngay mo so\n";
        cout << "0. Thoat\n";
        cout << "Lua chon: ";
        cin >> choice;  // Nhập lựa chọn từ người dùng

        switch (choice) {
            case 1: {
                SavingsAccount account;
                inputSavingsAccount(account);  // Nhập thông tin sổ tiết kiệm
                accounts.push_back(account);  // Thêm sổ tiết kiệm vào danh sách
                break;
            }
            case 2: {
                for (const auto& account : accounts) {
                    displaySavingsAccount(account);  // Hiển thị thông tin tất cả các sổ tiết kiệm
                }
                break;
            }
            case 3: {
                for (auto& account : accounts) {
                    updateInterestRate(account);  // Cập nhật lãi suất cho từng sổ tiết kiệm
                }
                break;
            }
            case 4: {
                for (auto& account : accounts) {
                    calculateInterest(account);  // Tính tiền lãi cho từng sổ tiết kiệm
                    displaySavingsAccount(account);  // Hiển thị thông tin sổ sau khi tính lãi
                }
                break;
            }
            case 5: {
                string code;
                cout << "Nhap ma so can rut tien: ";
                cin >> code;
                for (auto& account : accounts) {
                    if (account.accountCode == code) {
                        withdrawMoney(account);  // Thực hiện rút tiền nếu mã sổ khớp
                    }
                }
                break;
            }
            case 6: {
                int id;
                cout << "Nhap so CMND can tim: ";
                cin >> id;
                searchByID(accounts, id);  // Tìm kiếm sổ tiết kiệm theo CMND
                break;
            }
            case 7: {
                string code;
                cout << "Nhap ma so can tim: ";
                cin >> code;
                searchByAccountCode(accounts, code);  // Tìm kiếm sổ tiết kiệm theo mã sổ
                break;
            }
            case 8: {
                Date start, end;
                cout << "Nhap thoi gian bat dau (dd mm yyyy): ";
                cin >> start.day >> start.month >> start.year;
                cout << "Nhap thoi gian ket thuc (dd mm yyyy): ";
                cin >> end.day >> end.month >> end.year;
                listAccountsByDate(accounts, start, end);  // Liệt kê sổ tiết kiệm trong khoảng thời gian
                break;
            }
            case 9: {
                sortAccountsByDepositAmount(accounts);  // Sắp xếp các sổ tiết kiệm theo số tiền gửi giảm dần
                break;
            }
            case 10: {
                sortAccountsByOpeningDate(accounts);  // Sắp xếp các sổ tiết kiệm theo ngày mở sổ tăng dần
                break;
            }
            case 0:
                cout << "Thoat chuong trinh.\n";  // Thoát khỏi chương trình
                break;
            default:
                cout << "Lua chon khong hop le!\n";  // Lựa chọn không hợp lệ
                break;
        }
    } while (choice != 0);  // Lặp lại cho đến khi người dùng chọn thoát

    return 0;
}

