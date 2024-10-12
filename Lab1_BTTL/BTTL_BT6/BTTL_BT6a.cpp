#include <iostream>
#include <vector>

using namespace std;

/**
 * @brief Hàm tìm kiếm số lần xuất hiện của mảng A trong mảng B và vị trí bắt đầu của từng lần xuất hiện.
 * 
 * Hàm này duyệt qua mảng B, so sánh từng dãy con của B có cùng độ dài với mảng A. Nếu dãy con từ mảng B
 * khớp hoàn toàn với mảng A thì nó sẽ đếm số lần xuất hiện và lưu lại vị trí bắt đầu của lần xuất hiện đó.
 * 
 * @param A Mảng con cần tìm kiếm (mảng A)
 * @param B Mảng lớn chứa các phần tử để tìm mảng A (mảng B)
 */
void findSubarrays(const vector<int>& A, const vector<int>& B) {
    int count = 0;  // Biến đếm số lần xuất hiện của mảng A trong mảng B
    vector<int> positions;  // Vector lưu các chỉ số bắt đầu của mỗi lần xuất hiện của mảng A trong mảng B
    
    int n = A.size();  // Kích thước của mảng A
    int m = B.size();  // Kích thước của mảng B

    // Duyệt qua mảng B để kiểm tra từng dãy con có độ dài bằng độ dài của A
    for (int i = 0; i <= m - n; i++) {
        bool match = true;  // Biến để xác định có khớp mảng hay không
        
        // Kiểm tra từng phần tử của dãy con trong B so với mảng A
        for (int j = 0; j < n; j++) {
            if (B[i + j] != A[j]) {  // Nếu bất kỳ phần tử nào không khớp, dừng kiểm tra
                match = false;
                break;
            }
        }

        // Nếu tìm thấy sự khớp hoàn toàn, tăng biến đếm và lưu vị trí bắt đầu
        if (match) {
            count++;
            positions.push_back(i);  // Lưu vị trí bắt đầu tại chỉ số i
        }
    }

    // In ra số lần mảng A xuất hiện trong mảng B
    cout << "So lan mang A xuat hien trong B: " << count << '\n';

    // In ra danh sách các chỉ số bắt đầu của các lần xuất hiện
    cout << "Danh sach cac chi so bat dau: ";
    for (int pos : positions) {
        cout << pos << " ";  // In ra từng vị trí bắt đầu
    }
    cout << '\n';
}

int main() {
    int sizeA, sizeB;  // Kích thước của mảng A và B
    
    // Nhập kích thước của mảng A và B từ người dùng
    cout << "Nhap so phan tu cua mang A va B: ";
    cin >> sizeA >> sizeB;

    vector<int> A(sizeA), B(sizeB);  // Khởi tạo mảng A và B với kích thước đã nhập

    // Nhập các phần tử của mảng A từ người dùng
    cout << "Nhap mang A: ";
    for (int i = 0; i < sizeA; i++) {
        cin >> A[i];  // Lưu từng phần tử vào mảng A
    }

    // Nhập các phần tử của mảng B từ người dùng
    cout << "Nhap mang B: ";
    for (int i = 0; i < sizeB; i++) {
        cin >> B[i];  // Lưu từng phần tử vào mảng B
    }

    // Gọi hàm để tìm số lần mảng A xuất hiện trong mảng B và in ra kết quả
    findSubarrays(A, B);

    return 0;
}

