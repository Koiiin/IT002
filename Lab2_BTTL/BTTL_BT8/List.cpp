#include "List.h" // Nhúng tệp header của lớp List
#include <iostream>
#include <algorithm> // Để sử dụng hàm std::min
using namespace std;

List::List() : data(nullptr), size(0) {} // Khởi tạo danh sách với kích thước 0 và con trỏ data trỏ tới nullptr
List::~List() {
    delete[] data; // Giải phóng bộ nhớ khi đối tượng bị hủy
}

void List::Resize(unsigned int new_size) {
    double* new_data = new double[new_size]; // Tạo một mảng mới với kích thước mới
    for (unsigned int i = 0; i < min(size, new_size); ++i) { // Sao chép dữ liệu từ mảng cũ sang mảng mới
        new_data[i] = data[i];
    }
    delete[] data; // Giải phóng bộ nhớ của mảng cũ
    size = new_size; // Cập nhật kích thước
    data = new_data; // Cập nhật con trỏ data để trỏ tới mảng mới
}

void List::Add_List(double x) {
    Resize(size + 1); // Tăng kích thước danh sách
    data[size - 1] = x; // Thêm phần tử mới vào cuối danh sách
}

void List::Delete_First(double x) {
    for (unsigned int i = 0; i < size; ++i) { // Tìm kiếm phần tử đầu tiên có giá trị x
        if (data[i] == x) {
            for (unsigned int j = i; j < size - 1; ++j) { // Dời tất cả phần tử phía sau lên một vị trí
                data[j] = data[j + 1];
            }
            Resize(size - 1); // Giảm kích thước danh sách
            break; // Thoát khỏi vòng lặp
        }
    }
}

void List::Delete_All(double x) {
    unsigned int count = 0; // Biến đếm số phần tử không bằng x
    for (unsigned int i = 0; i < size; ++i) { // Duyệt qua tất cả phần tử
        if (data[i] != x) { // Nếu phần tử khác x
            data[count] = data[i]; // Sao chép phần tử vào vị trí count
            count++; // Tăng biến đếm
        }
    }
    Resize(count); // Giảm kích thước danh sách theo số phần tử không bằng x
}

void List::Replace(int index, double x) {
    if (index >= 0 && index < size) { // Kiểm tra chỉ số hợp lệ
        data[index] = x; // Thay thế phần tử tại index bằng x
    }
}

void List::Print_List() const {
    cout << "["; 
    for (unsigned int i = 0; i < size; ++i) { // In ra tất cả các phần tử trong danh sách
        cout << data[i];
        if (i != size - 1) { cout << ","; } // Thêm dấu phẩy giữa các phần tử
    }
    cout << "]";
}
