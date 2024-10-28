#ifndef LIST_H
#define LIST_H

#include <iostream>
using namespace std;

class List {
private:
	double* data;	   // pointer quản lý mảng động
	unsigned int size; // Số lượng phần tử trong list

	void Resize(unsigned int new_size);  // Hàm resize mảng động

public:
	List();					  // Constructor khởi tạo list rỗng
	~List();                  // Destructor để giải phóng bộ nhớ
	void Add_List(double x);  // Thêm phần tử vào cuối list
	void Delete_First(double x);    // Xóa phần tử đầu tiên có giá trị x
	void Delete_All(double x);		// Xóa tất cả phần tử có giá trị x
	void Replace(int index, double x);   // Thay phần tử ở vị trí index bằng y
	void Print_List() const;	    // In list theo định dạng [a,b,c,...]
};

#endif // !LIST_H
