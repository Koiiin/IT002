#include <iostream>
#include <vector>
using namespace std;

int main()
{
    // Khai báo biến để lưu kích thước của ma trận
    int matrixSize;
    cout << "Nhap kich thuoc ma tran: "; // Hướng dẫn nhập kích thước ma trận
    cin >> matrixSize;

    // Khởi tạo ma trận gốc với kích thước matrixSize x matrixSize
    vector<vector<int>> originalMatrix(matrixSize, vector<int>(matrixSize));

    // Nhập các phần tử của ma trận từ người dùng
    cout << "Nhap cac phan tu cua ma tran: \n";
    for (int row = 0; row < matrixSize; row++)
        for (int col = 0; col < matrixSize; col++)
            cin >> originalMatrix[row][col];

    int permutationCount = 0; // Đếm số lần hoán vị
    vector<vector<int>> permutedMatrix(matrixSize, vector<int>(matrixSize)); // Ma trận sau khi hoán vị
    vector<vector<int>> currentMatrix = originalMatrix; // Ma trận hiện tại, bắt đầu bằng ma trận gốc

    // Vòng lặp thực hiện hoán vị cho đến khi ma trận quay lại trạng thái ban đầu
    while (true)
    {
        permutationCount++; // Tăng số lần hoán vị

        // Hoán vị các phần tử theo quy tắc đã cho
        for (int row = 0; row < matrixSize; row++)
            for (int col = 0; col < matrixSize; col++)
                // Chuyển phần tử từ currentMatrix đến permutedMatrix theo quy tắc
                permutedMatrix[((2 * row + col) % matrixSize)][((row + col) % matrixSize)] = currentMatrix[row][col];

        // Cập nhật currentMatrix với permutedMatrix sau khi hoán vị
        currentMatrix = permutedMatrix;

        // Kiểm tra nếu ma trận hiện tại đã quay lại trạng thái ban đầu
        if (currentMatrix == originalMatrix)
            break; // Nếu quay lại, dừng vòng lặp
    }

    // In ra số lần hoán vị cần thiết để ma trận trở lại trạng thái ban đầu
    cout << "So lan hoan vi de ma tran ve trang thai ban dau: " << permutationCount << endl;

    return 0;
}
