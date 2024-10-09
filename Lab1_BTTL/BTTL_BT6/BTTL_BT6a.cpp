#include <iostream>
#include <vector>

using namespace std;

// Hàm tìm kiếm số lần xuất hiện của A trong B
void findSubarrays(const vector<int>& A, const vector<int>& B) {
    int count = 0;  // Đếm số lần xuất hiện
    vector<int> positions;  // Lưu các chỉ số bắt đầu của những lần xuất hiện
    
    int n = A.size();  // Kích thước của mảng A
    int m = B.size();  // Kích thước của mảng B

    // Duyệt qua mảng B và kiểm tra các dãy con có độ dài bằng độ dài của A
    for (int i = 0; i <= m - n; i++) {
        bool match = true;
        
        // Kiểm tra dãy con từ B[i] đến B[i+n-1] có giống A không
        for (int j = 0; j < n; j++) {
            if (B[i + j] != A[j]) {
                match = false;
                break;
            }
        }

        // Nếu tìm thấy sự khớp, tăng đếm và lưu vị trí bắt đầu
        if (match) {
            count++;
            positions.push_back(i);
        }
    }

    // In ra số lần mảng A xuất hiện trong B
    cout << "So lan mang A xuat hien trong B: " << count << endl;

    // In ra các chỉ số bắt đầu của các lần xuất hiện
    cout << "Danh sach cac chi so bat dau: ";
    for (int pos : positions) {
        cout << pos << " ";
    }
    cout << '\n';
}

int main() {
    int sizeA, sizeB;
    
    // Nhập kích thước của mảng A và B
    cout << "Nhap so phan tu cua mang A va B: ";
    cin >> sizeA >> sizeB;

    vector<int> A(sizeA), B(sizeB);

    // Nhập mảng A
    cout << "Nhap mang A: ";
    for (int i = 0; i < sizeA; i++) {
        cin >> A[i];
    }

    // Nhập mảng B
    cout << "Nhap mang B: ";
    for (int i = 0; i < sizeB; i++) {
        cin >> B[i];
    }

    // Gọi hàm để tìm số lần xuất hiện và các chỉ số bắt đầu
    findSubarrays(A, B);

    return 0;
}
