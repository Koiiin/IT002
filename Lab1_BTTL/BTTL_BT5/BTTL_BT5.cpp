#include <iostream>

using namespace std;

// Kiểm tra xem năm có phải là năm nhuận hay không
bool NamNhuan(int year) {
    if (year % 400 == 0) return true;
    if (year % 100 == 0) return false;
    if (year % 4 == 0) return true;
    return false;
}

// Số ngày trong mỗi tháng cho năm thường và năm nhuận
int daysInMonth(int month, int year) {
    int daysInMonths[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month == 2 && NamNhuan(year)) return 29;  // Tháng 2 có 29 ngày nếu là năm nhuận
    return daysInMonths[month - 1];  // Trả về số ngày của tháng đó
}

// Tìm ngày kế tiếp
void findNextDay(int& day, int& month, int& year) {
    if (day < daysInMonth(month, year)) {
        day++;
    } else {
        day = 1;  // Sang ngày 1 của tháng mới
        if (month < 12) {
            month++;  // Tăng tháng
        } else {
            month = 1;  // Sang tháng 1 của năm mới
            year++;
        }
    }
}

// Tìm ngày trước đó
void findPreviousDay(int& day, int& month, int& year) {
    if (day > 1) {
        day--;
    } else {
        if (month > 1) {
            month--;  // Lùi tháng
            day = daysInMonth(month, year);  // Lấy ngày cuối cùng của tháng trước
        } else {
            month = 12;  // Quay lại tháng 12 của năm trước
            year--;
            day = 31;  // Ngày cuối của tháng 12
        }
    }
}

// Tính xem ngày là ngày thứ bao nhiêu trong năm
int dayOfYear(int day, int month, int year) {
    int dayCount = 0;
    for (int m = 1; m < month; m++) {
        dayCount += daysInMonth(m, year);  // Cộng số ngày của các tháng trước đó
    }
    dayCount += day;  // Cộng thêm số ngày trong tháng hiện tại
    return dayCount;
}

int main() {
    int day, month, year;

    // Nhập ngày, tháng, năm từ người dùng
    cout << "Nhap ngay (dd mm yyyy): ";
    cin >> day >> month >> year;

    // Xuất ngày kế tiếp
    int nextDay = day, nextMonth = month, nextYear = year;
    findNextDay(nextDay, nextMonth, nextYear);
    cout << "Ngay ke tiep la: " << nextDay << "/" << nextMonth << "/" << nextYear << '\n';

    // Xuất ngày trước đó
    int prevDay = day, prevMonth = month, prevYear = year;
    findPreviousDay(prevDay, prevMonth, prevYear);
    cout << "Ngay truoc la: " << prevDay << "/" << prevMonth << "/" << prevYear << '\n';

    // Tính xem ngày đó là ngày thứ bao nhiêu trong năm
    int dayInYear = dayOfYear(day, month, year);
    cout << "Day la ngay thu " << dayInYear << " trong nam.\n";

    return 0;
}
