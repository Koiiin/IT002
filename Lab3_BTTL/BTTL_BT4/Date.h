#ifndef DATE_H
#define DATE_H

#include <iostream>
using namespace std;

class Date {
private:
	int iNgay;   // Ngay
	int iThang;  // Thang
	int iNam;    // Nam
public:
	/**
	 * Constructor mac dinh
	 * Khoi tao doi tuong `Date` voi cac gia tri mac dinh cho ngay, thang, va nam.
	 */
	Date();

	/**
	 * Constructor co tham so
	 * @param YY: Nam can khoi tao
	 * @param MM: Thang can khoi tao
	 * @param DD: Ngay can khoi tao
	 * Khoi tao doi tuong `Date` voi gia tri nam, thang, va ngay cu the.
	 */
	Date(int YY, int MM, int DD);

	/**
	 * TinhNgay
	 * @return: Tong so ngay tinh tu mot moc thoi gian nhat dinh (co the la 01/01/0001).
	 * Chuc nang: Tinh va tra ve so ngay tich luy cua doi tuong `Date`.
	 */
	int TinhNgay() const;

	/**
	 * ResetDate
	 * @param DD: Ngay moi can thiet lap.
	 * Chuc nang: Dat lai ngay cua doi tuong `Date` thanh gia tri ngay moi duoc chi dinh.
	 */
	void ResetDate(int DD);

	/**
	 * Operator +
	 * @param DD: So ngay muon cong them.
	 * @return: Doi tuong `Date` moi voi so ngay da duoc cong them.
	 * Chuc nang: Cong them so ngay vao doi tuong `Date` hien tai va tra ve mot doi tuong moi.
	 */
	Date operator + (int DD);

	/**
	 * Operator -
	 * @param DD: So ngay muon tru.
	 * @return: Doi tuong `Date` moi voi so ngay da duoc tru.
	 * Chuc nang: Tru so ngay khoi doi tuong `Date` hien tai va tra ve mot doi tuong moi.
	 */
	Date operator - (int DD);

	/**
	 * Operator -
	 * @param NgayThangNam: Doi tuong `Date` can so sanh.
	 * @return: Hieu so ngay giua hai doi tuong `Date`.
	 * Chuc nang: Tinh va tra ve so ngay chen lech giua hai doi tuong `Date`.
	 */
	int operator - (const Date& NgayThangNam) const;

	/**
	 * Operator ++
	 * @return: Tham chieu den doi tuong `Date` sau khi tang them mot ngay.
	 * Chuc nang: Tang ngay cua doi tuong `Date` len 1.
	 */
	Date& operator ++();

	/**
	 * Operator --
	 * @return: Tham chieu den doi tuong `Date` sau khi giam di mot ngay.
	 * Chuc nang: Giam ngay cua doi tuong `Date` di 1.
	 */
	Date& operator --();

	/**
	 * Operator ==
	 * @param NgayThangNam: Doi tuong `Date` can so sanh.
	 * @return: `true` neu hai doi tuong `Date` bang nhau, `false` neu khong.
	 * Chuc nang: Kiem tra xem hai doi tuong `Date` co bang nhau khong.
	 */
	bool operator == (const Date& NgayThangNam);

	/**
	 * Operator !=
	 * @param NgayThangNam: Doi tuong `Date` can so sanh.
	 * @return: `true` neu hai doi tuong `Date` khac nhau, `false` neu khong.
	 * Chuc nang: Kiem tra xem hai doi tuong `Date` co khac nhau khong.
	 */
	bool operator != (const Date& NgayThangNam);

	/**
	 * Operator >=
	 * @param NgayThangNam: Doi tuong `Date` can so sanh.
	 * @return: `true` neu doi tuong `Date` hien tai lon hon hoac bang doi tuong kia, `false` neu khong.
	 * Chuc nang: Kiem tra xem doi tuong `Date` hien tai co lon hon hoac bang doi tuong kia khong.
	 */
	bool operator >= (const Date& NgayThangNam);

	/**
	 * Operator <=
	 * @param NgayThangNam: Doi tuong `Date` can so sanh.
	 * @return: `true` neu doi tuong `Date` hien tai nho hon hoac bang doi tuong kia, `false` neu khong.
	 * Chuc nang: Kiem tra xem doi tuong `Date` hien tai co nho hon hoac bang doi tuong kia khong.
	 */
	bool operator <= (const Date& NgayThangNam);

	/**
	 * Operator >
	 * @param NgayThangNam: Doi tuong `Date` can so sanh.
	 * @return: `true` neu doi tuong `Date` hien tai lon hon doi tuong kia, `false` neu khong.
	 * Chuc nang: Kiem tra xem doi tuong `Date` hien tai co lon hon doi tuong kia khong.
	 */
	bool operator > (const Date& NgayThangNam);

	/**
	 * Operator <
	 * @param NgayThangNam: Doi tuong `Date` can so sanh.
	 * @return: `true` neu doi tuong `Date` hien tai nho hon doi tuong kia, `false` neu khong.
	 * Chuc nang: Kiem tra xem doi tuong `Date` hien tai co nho hon doi tuong kia khong.
	 */
	bool operator < (const Date& NgayThangNam);

	/**
	 * Operator >>
	 * @param is: Doi tuong `istream` de nhap du lieu.
	 * @param date: Doi tuong `Date` can nhap du lieu vao.
	 * @return: Doi tuong `istream` sau khi nhap.
	 * Chuc nang: Nhap thong tin ngay, thang, nam cho doi tuong `Date`.
	 */
	friend istream& operator >> (istream& is, Date& date);

	/**
	 * Operator <<
	 * @param os: Doi tuong `ostream` de xuat du lieu.
	 * @param date: Doi tuong `Date` can xuat du lieu.
	 * @return: Doi tuong `ostream` sau khi xuat.
	 * Chuc nang: Xuat thong tin ngay, thang, nam cua doi tuong `Date`.
	 */
	friend ostream& operator << (ostream& os, const Date& date);
};

#endif // !DATE_H
