#include "SoPhuc.h"
#include <iostream>
#include <math.h>
using namespace std;

/**
 * Ham main: Chuong trinh chinh de thuc hien cac phep toan voi so phuc
 *
 * Dau vao:
 *  - Nguoi dung nhap hai so phuc va mot so thuc.
 *
 * Dau ra:
 *  - Ket qua cua cac phep toan giua hai so phuc.
 *  - Ket qua cua cac phep toan giua so phuc va so thuc.
 *  - Ket qua so sanh giua hai so phuc va giua so phuc voi so thuc.
 */

int main() {
	// Khai bao hai doi tuong so phuc sp1 va sp2
	SoPhuc sp1, sp2;
	SoPhuc sp3(3, 4);
	SoPhuc sp4(5);

	// Nhap gia tri cho so phuc thu nhat
	cout << "Nhap so phuc thu 1: \n";
	cin >> sp1;

	// Nhap gia tri cho so phuc thu hai
	cout << "Nhap so phuc thu 2: \n";
	cin >> sp2;


	// Khai bao mot bien double n de luu gia tri so thuc
	double n;
	cout << "Nhap so nguyen n: ";
	cin >> n;

	// Hien thi cac so phuc vua nhap
	cout << "So phuc thu 1: " << sp1;
	cout << "So phuc thu 2: " << sp2;
	cout << "So phuc thu 3: " << sp3;
	cout << "So phuc thu 4: " << sp4;

	// Thuc hien cac phep toan cong, tru, nhan, chia giua hai so phuc
	cout << "\n--- Phep toan giua hai so phuc ---" << endl;
	cout << "sp1 + sp2 = " << sp1 + sp2 << endl;
	cout << "sp1 - sp2 = " << sp1 - sp2 << endl;
	cout << "sp1 * sp2 = " << sp1 * sp2 << endl;
	cout << "sp1 / sp2 = " << sp1 / sp2 << endl;

	// Thuc hien cac phep toan cong, tru, nhan, chia giua so phuc va so thuc
	cout << "\n--- Phep toan giua so phuc va so nguyen ---" << endl;
	cout << "sp1 + n = " << sp1 + n << endl;
	cout << "sp1 - n = " << sp1 - n << endl;
	cout << "sp1 * n = " << sp1 * n << endl;
	cout << "sp1 / n = " << sp1 / n << endl;
	cout << endl;
	cout << "n + sp2 = " << n + sp2 << endl;
	cout << "n - sp2 = " << n - sp2 << endl;
	cout << "n * sp2 = " << n * sp2 << endl;
	cout << "n / sp2 = " << n / sp2 << endl;

	// So sanh hai so phuc va hien thi ket qua
	cout << "\n--- So sanh giua hai so phuc ---" << endl;
	cout << "sp1 == sp2: " << (sp1 == sp2 ? "true" : "false") << endl;
	cout << "sp1 != sp2: " << (sp1 != sp2 ? "true" : "false") << endl;

	// So sanh so thuc va so phuc va hien thi ket qua
	cout << "\n--- So sanh giua so nguyen va so phuc ---" << endl;
	/*cout << "sp1 == n: " << (sp1 == n ? "true" : "false") << endl;
	cout << "sp1 != n: " << (sp1 != n ? "true" : "false") << endl;*/
	cout << "n == sp2: " << (n == sp2 ? "true" : "false") << endl;
	cout << "n != sp2: " << (n != sp2 ? "true" : "false") << endl;

	return 0;
}
