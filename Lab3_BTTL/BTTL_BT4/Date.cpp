#include "Date.h"
#include <iostream>
using namespace std;

/**
 * @class Date
 * @brief Lop bieu dien mot ngay trong nam, ho tro cac phep toan ngay thang co ban.
 */

 /**
  * @brief Khoi tao mot doi tuong Date voi gia tri mac dinh la 1/1/2024.
  * @details Thiet lap ngay, thang, va nam mac dinh.
  */
Date::Date() : iNgay(1), iThang(1), iNam(2024) {}

/**
 * @brief Khoi tao mot doi tuong Date voi cac gia tri ngay, thang, nam chi dinh.
 * @param YY Nam can thiet lap.
 * @param MM Thang can thiet lap.
 * @param DD Ngay can thiet lap.
 * @details Thiet lap gia tri ngay, thang, nam cho doi tuong.
 */
Date::Date(int YY, int MM, int DD) : iNgay(DD), iThang(MM), iNam(YY) {}

/**
 * @brief Thiet lap lai gia tri ngay tu mot tong so ngay ke tu dau nam hien tai.
 * @param DD Tong so ngay tinh tu ngay 1 thang 1 cua nam hien tai.
 * @details Ham nay se tinh toan va dat lai ngay, thang dua tren so ngay duoc cung cap.
 */
void Date::ResetDate(int DD) {
    int day = DD;
    int thang = 1;

    while (day <= 0 || day > 365 + ((iNam % 4 == 0 && iNam % 100 != 0) || iNam % 400 == 0)) {
        if (day <= 0) {
            iNam--;
            day += 365 + ((iNam % 4 == 0 && iNam % 100 != 0) || iNam % 400 == 0);
        }
        else {
            day -= 365 + ((iNam % 4 == 0 && iNam % 100 != 0) || iNam % 400 == 0);
            iNam++;
        }
    }

    while (day > 0) {
        switch (thang) {
        case 4: case 6: case 9: case 11:
            day -= 30;
            break;
        case 2:
            day -= 28 + ((iNam % 4 == 0 && iNam % 100 != 0) || iNam % 400 == 0);
            break;
        default:
            day -= 31;
            break;
        }

        if (day > 0) thang++;
    }

    iThang = thang;
    switch (iThang) {
    case 4: case 6: case 9: case 11:
        iNgay = 30 + day;
        break;
    case 2:
        iNgay = 28 + ((iNam % 4 == 0 && iNam % 100 != 0) || iNam % 400 == 0) + day;
        break;
    default:
        iNgay = 31 + day;
        break;
    }
}

/**
 * @brief Tinh tong so ngay ke tu dau nam den ngay hien tai.
 * @return Tong so ngay tu ngay 1/1 cua nam hien tai.
 * @details Ham nay tinh tong so ngay dua tren thang va ngay hien tai.
 */
int Date::TinhNgay() const {
    int SumDay = iNgay;
    for (int month = 1; month < iThang; ++month) {
        switch (month) {
        case 4: case 6: case 9: case 11:
            SumDay += 30;
            break;
        case 2:
            SumDay += 28 + ((iNam % 4 == 0 && iNam % 100 != 0) || iNam % 400 == 0);
            break;
        default:
            SumDay += 31;
            break;
        }
    }
    return SumDay;
}

/**
 * @brief Cong mot so ngay vao ngay hien tai.
 * @param DD So ngay can cong vao ngay hien tai.
 * @return Doi tuong Date moi voi ngay da duoc cong.
 * @details Ham tao ra mot doi tuong moi voi ngay duoc cong tu ngay hien tai.
 */
Date Date::operator+ (int DD) {
    int result = TinhNgay() + DD;
    Date dt;
    dt.ResetDate(result);
    return dt;
}

/**
 * @brief Tru mot so ngay tu ngay hien tai.
 * @param DD So ngay can tru tu ngay hien tai.
 * @return Doi tuong Date moi voi ngay da duoc tru.
 * @details Tra ve doi tuong moi sau khi tru mot so ngay nhat dinh.
 */
Date Date::operator- (int DD) {
    iNgay -= DD;
    while (iNgay <= 0) {
        iThang--;
        if (iThang < 1) {
            iThang = 12;
            iNam--;
        }
        switch (iThang) {
        case 4: case 6: case 9: case 11:
            iNgay += 30;
            break;
        case 2:
            iNgay += 28 + ((iNam % 4 == 0 && iNam % 100 != 0) || iNam % 400 == 0);
            break;
        default:
            iNgay += 31;
            break;
        }
    }
    return *this;
}

/**
 * @brief Tinh khoang cach giua hai ngay.
 * @param other Doi tuong Date khac de so sanh.
 * @return Khoang cach ngay giua hai doi tuong Date.
 * @details Ham tinh khoang cach (so ngay) giua ngay hien tai va ngay duoc cung cap.
 */
int Date::operator- (const Date& other) const {
    auto totalDays = [](int year, int month, int day) {
        int days = day;

        for (int m = 1; m < month; ++m) {
            switch (m) {
            case 4: case 6: case 9: case 11:
                days += 30;
                break;
            case 2:
                days += 28 + (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
                break;
            default:
                days += 31;
                break;
            }
        }

        days += 365 * (year - 1) + (year - 1) / 4 - (year - 1) / 100 + (year - 1) / 400;
        return days;
        };

    int days1 = totalDays(iNam, iThang, iNgay);
    int days2 = totalDays(other.iNam, other.iThang, other.iNgay);

    return abs(days1 - days2);
}

/**
 * @brief Tinh ngay tiep theo.
 * @return Tham chieu den doi tuong Date sau khi tang ngay.
 */
Date& Date::operator++() {
    *this = *this + 1;
    return *this;
}

/**
 * @brief Tinh ngay truoc do.
 * @return Tham chieu den doi tuong Date sau khi giam ngay.
 */
Date& Date::operator--() {
    iNgay -= 1;
    while (iNgay <= 0) {
        iThang--;
        if (iThang < 1) {
            iThang = 12;
            iNam--;
        }
        switch (iThang)
        {
        case 4:
        case 6:
        case 9:
        case 11:
            iNgay += 30;
            break;
        case 2:
            iNgay += 28 + ((iNam % 4 == 0 && iNam % 100 != 0) || iNam % 400 == 0);
            break;
        default:
            iNgay += 31;
            break;
        }
    }
    return *this;
}

/**
 * @brief Kiem tra hai doi tuong Date co bang nhau khong.
 * @param NgayThangNam Doi tuong Date de so sanh.
 * @return true neu hai ngay bang nhau, false neu nguoc lai.
 */
bool Date::operator== (const Date& NgayThangNam) {
    if (iNam == NgayThangNam.iNam) { return TinhNgay() == NgayThangNam.TinhNgay(); }
    else { return false; }
}

/**
 * @brief Kiem tra hai doi tuong Date co khong bang nhau khong.
 * @param NgayThangNam Doi tuong Date de so sanh.
 * @return true neu hai ngay khong bang nhau, false neu nguoc lai.
 */
bool Date::operator!= (const Date& NgayThangNam) {
    if (iNam != NgayThangNam.iNam) { return true; }
    else { return TinhNgay() != NgayThangNam.TinhNgay(); }
}

/**
 * @brief Kiem tra ngay hien tai lon hon hoac bang ngay khac.
 * @param NgayThangNam Doi tuong Date de so sanh.
 * @return true neu lon hon hoac bang, false neu nguoc lai.
 */
bool Date::operator>= (const Date& NgayThangNam) {
    if (iNam < NgayThangNam.iNam) { return false; }
    else { return TinhNgay() >= NgayThangNam.TinhNgay(); }
}

/**
 * @brief Kiem tra ngay hien tai nho hon hoac bang ngay khac.
 * @param NgayThangNam Doi tuong Date de so sanh.
 * @return true neu nho hon hoac bang, false neu nguoc lai.
 */
bool Date::operator<= (const Date& NgayThangNam) {
    if (iNam > NgayThangNam.iNam) { return false; }
    else { return TinhNgay() <= NgayThangNam.TinhNgay(); }
}


/**
 * @brief Kiem tra ngay hien tai lon hon ngay khac.
 * @param NgayThangNam Doi tuong Date de so sanh.
 * @return true neu lon hon, false neu nguoc lai.
 */
bool Date::operator> (const Date& NgayThangNam) {
    if (iNam < NgayThangNam.iNam) {
        return false;
    }
    else if (iNam > NgayThangNam.iNam)
    {
        return true;
    }
    else
    {
        return TinhNgay() >= NgayThangNam.TinhNgay();
    }
}

/**
 * @brief Kiem tra ngay hien tai nho hon ngay khac.
 * @param NgayThangNam Doi tuong Date de so sanh.
 * @return true neu nho hon, false neu nguoc lai.
 */
bool Date::operator< (const Date& NgayThangNam) {
    if (iNam > NgayThangNam.iNam) {
        return false;
    }
    else if (iNam < NgayThangNam.iNam)
    {
        return true;
    }
    else
    {
        return TinhNgay() < NgayThangNam.TinhNgay();
    }
}

/**
 * @brief Xuat thong tin ngay/thang/nam cua doi tuong Date.
 * @param os Doi tuong ostream de xuat du lieu.
 * @param dt Doi tuong Date can xuat.
 * @return ostream voi thong tin ngay/thang/nam da duoc in ra.
 */
ostream& operator<<(ostream& os, const Date& dt) {
    os << dt.iNgay << '/' << dt.iThang << '/' << dt.iNam;
    return os;
}


/**
 * @brief Nhap thong tin ngay/thang/nam cua doi tuong Date.
 * @param is Doi tuong istream de nhap du lieu.
 * @param dt Doi tuong Date can nhap.
 * @return istream voi thong tin ngay/thang/nam da duoc nhap vao.
 */
istream& operator>>(istream& is, Date& dt) {
    while (1) {
        cout << "Nhap ngay: DD MM YYYY: ";
        bool valid = true;
        is >> dt.iNgay >> dt.iThang >> dt.iNam;

        if (dt.iThang <= 0 || dt.iThang > 12 || dt.iNam <= 0) { valid = false; }
        else
        {
            switch (dt.iThang)
            {
            case 4:
            case 6:
            case 9:
            case 11:
                if (dt.iNgay <= 0 || dt.iNgay > 30) { valid = false; }
                break;
            case 2:
                if ((dt.iNam % 4 == 0 && dt.iNam % 100 != 0) || dt.iNam % 400 == 0) {
                    if (dt.iNgay <= 0 || dt.iNgay > 29) { valid = false; }
                }
                else
                {
                    if (dt.iNgay <= 0 || dt.iNgay > 28) { valid = false; }
                }
                break;
            default:
                if (dt.iNgay <= 0 || dt.iNgay > 31) { valid = false; }
                break;
            }
        }

        if (!valid) { cout << "Du lieu khong hop le. Hay nhap lai.\n"; }
        else { break; }
        
    }
    return is;
}