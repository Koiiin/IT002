#include <iostream>
#include "List.h"
#include <algorithm>
using namespace std;

int main() {
    List list; // Tạo một đối tượng danh sách
    int choice; // Biến để lưu lựa chọn của người dùng

    while (true) { // Vòng lặp vô hạn
        cin >> choice; // Đọc lựa chọn từ người dùng

        if (choice == -1) break; // Thoát vòng lặp nếu người dùng nhập -1

        if (choice == 0) { // Thêm phần tử
            double x;
            cin >> x; // Đọc giá trị x từ người dùng
            list.Add_List(x); // Thêm giá trị vào danh sách
        }
        else if (choice == 1) { // Xóa phần tử đầu tiên
            double x;
            cin >> x; // Đọc giá trị x từ người dùng
            list.Delete_First(x); // Xóa phần tử đầu tiên có giá trị x
        }
        else if (choice == 2) { // Xóa tất cả phần tử
            double x;
            cin >> x; // Đọc giá trị x từ người dùng
            list.Delete_All(x); // Xóa tất cả phần tử có giá trị x
        }
        else if (choice == 3) { // Thay thế phần tử tại chỉ số x
            int x;
            double y;
            cin >> x >> y; // Đọc chỉ số x và giá trị y từ người dùng
            list.Replace(x, y); // Thay thế phần tử tại chỉ số x bằng y
        }
    }

    list.Print_List(); // In danh sách sau khi thực hiện các thao tác

    return 0; // Kết thúc chương trình
}
