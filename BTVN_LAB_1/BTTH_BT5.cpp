#include <bits/stdc++.h>
using namespace std;

// Cấu trúc để lưu thông tin hình chữ nhật
struct Rectangle
{
    int x; // Tọa độ x của góc trên bên trái
    int y; // Tọa độ y của góc trên bên trái
    int width; // Chiều rộng của hình chữ nhật
    int height; // Chiều cao của hình chữ nhật
};

int rows, cols; // Số hàng và số cột của ma trận

// Hàm so sánh hai hình chữ nhật để sắp xếp
bool compare(const Rectangle &a, const Rectangle &b)
{
    if (a.y != b.y) return a.y < b.y; // Sắp xếp theo tọa độ y
    return a.x < b.x; // Nếu y bằng nhau, sắp xếp theo tọa độ x
}

// Hàm kiểm tra xem hình chữ nhật có thể được vẽ trong ma trận hay không
bool canPlaceRectangle(const vector<vector<int>> &matrix, int x, int y, int width, int height)
{
    // Kiểm tra các hàng trên và dưới của hình chữ nhật
    for (int i = y - 1; i <= y + height; i++)
    {
        if (i >= 0 && i < rows) {
            if (x - 1 >= 0 && matrix[i][x - 1] == 1) return false; // Kiểm tra bên trái
            if (x + width < cols && matrix[i][x + width] == 1) return false; // Kiểm tra bên phải
        }
    }
    // Kiểm tra các cột bên trái và bên phải của hình chữ nhật
    for (int j = x - 1; j <= x + width; j++)
    {
        if (j >= 0 && j < cols) {
            if (y - 1 >= 0 && matrix[y - 1][j] == 1) return false; // Kiểm tra phía trên
            if (y + height < rows && matrix[y + height][j] == 1) return false; // Kiểm tra phía dưới
        }
    }
    return true; // Có thể vẽ hình chữ nhật
}

int main()
{
    cin >> rows >> cols; // Nhập số hàng và số cột
    vector<vector<int>> matrix(rows, vector<int>(cols)); // Khởi tạo ma trận
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++) cin >> matrix[i][j]; // Nhập các phần tử của ma trận

    vector<Rectangle> rectangles; // Danh sách lưu trữ các hình chữ nhật
    vector<vector<bool>> visited(rows, vector<bool>(cols, false)); // Ma trận đánh dấu đã duyệt

    // Duyệt qua ma trận để tìm các hình chữ nhật
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++) 
            if (matrix[i][j] == 1 && !visited[i][j]) // Tìm vị trí chưa được đánh dấu
            {
                int startX = j, startY = i, width = 0; // Khởi tạo tọa độ và chiều rộng
                while (startX + width < cols && matrix[startY][startX + width] == 1) width++; // Tính chiều rộng

                int height = 0; // Khởi tạo chiều cao
                bool valid = true; // Biến kiểm tra tính hợp lệ
                while (startY + height < rows && valid)
                {
                    for (int k = 0; k < width; k++) 
                        if (matrix[startY + height][startX + k] != 1)
                        {
                            valid = false; break; // Kiểm tra chiều cao
                        }
                    if (valid) height++; // Tăng chiều cao nếu hợp lệ
                }
                // Nếu chiều rộng và chiều cao lớn hơn hoặc bằng 2 và có thể vẽ hình chữ nhật
                if (width >= 2 && height >= 2 && canPlaceRectangle(matrix, startX, startY, width, height)) 
                    rectangles.push_back({startX, startY, width, height}); // Lưu hình chữ nhật vào danh sách

                // Đánh dấu các vị trí đã duyệt
                for (int p = 0; p < height; p++)
                    for (int q = 0; q < width; q++) visited[startY + p][startX + q] = true;
            }

    // Sắp xếp và in ra các hình chữ nhật đã tìm thấy
    sort(rectangles.begin(), rectangles.end(), compare);
    for (const auto &rect : rectangles)
        cout << "[" << rect.x << "," << rect.y << "," << rect.width << "," << rect.height << "]" << '\n';

    return 0;
}
