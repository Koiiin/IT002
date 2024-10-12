#include <bits/stdc++.h>
#include <vector>
#include <string>

using namespace std;

// Struct đại diện cho thông tin của một học sinh
struct HocSinh {
    string hoTen;    // Họ tên học sinh
    float diemToan;  // Điểm môn Toán
    float diemVan;   // Điểm môn Văn
    float diemNN;    // Điểm môn Ngoại ngữ
    float diemTB;    // Điểm trung bình
    string XepLoai;  // Xếp loại của học sinh
};

/**
 * @brief Kiểm tra tính hợp lệ của tên học sinh (không chứa số)
 * @param name Tên học sinh cần kiểm tra
 * @return true nếu tên hợp lệ, false nếu không hợp lệ
 */
bool checkName(const string& name) {
    if (name.length() < 1) return false;  // Tên không được rỗng
    for (char c : name) {
        if (isdigit(c)) return false;  // Tên không chứa ký tự số
    }
    return true;
}

/**
 * @brief Tính điểm trung bình của học sinh dựa trên các môn học
 * @param toan Điểm môn Toán
 * @param van Điểm môn Văn
 * @param ngoaingu Điểm môn Ngoại ngữ
 * @return Điểm trung bình của học sinh
 */
float TinhDTB(float toan, float van, float ngoaingu) {
    return (2 * toan + van + ngoaingu) / 4;  // Điểm Toán được nhân đôi
}

/**
 * @brief Kiểm tra tính hợp lệ của điểm (trong khoảng từ 0 đến 10)
 * @param x Điểm cần kiểm tra
 * @return true nếu điểm hợp lệ, false nếu không hợp lệ
 */
bool checkDiem(float x) {
    return (x >= 0 && x <= 10);  // Điểm hợp lệ trong khoảng 0-10
}

/**
 * @brief Nhập điểm Toán của học sinh
 * @param hs Thông tin của học sinh
 */
void NhapDiemToan(HocSinh &hs) {
    cout << "Nhap diem toan: ";
    while (1) {
        cin >> hs.diemToan;
        if (checkDiem(hs.diemToan)) break;
        else {
            cout << "Nhap lai diem toan\n";  // Thông báo nhập lại nếu điểm không hợp lệ
        }
    }
}

/**
 * @brief Nhập điểm Văn của học sinh
 * @param hs Thông tin của học sinh
 */
void NhapDiemVan(HocSinh &hs) {
    cout << "Nhap diem van: ";
    while (1) {
        cin >> hs.diemVan;
        if (checkDiem(hs.diemVan)) break;
        else {
            cout << "Nhap lai diem van\n";  // Thông báo nhập lại nếu điểm không hợp lệ
        }
    }
}

/**
 * @brief Nhập điểm Ngoại ngữ của học sinh
 * @param hs Thông tin của học sinh
 */
void NhapDiemNN(HocSinh &hs) {
    cout << "Nhap diem ngoai ngu: ";
    while (1) {
        cin >> hs.diemNN;
        if (checkDiem(hs.diemNN)) break;
        else {
            cout << "Nhap lai diem ngoai ngu\n";  // Thông báo nhập lại nếu điểm không hợp lệ
        }
    }
}

/**
 * @brief Nhập tên học sinh
 * @param hs Thông tin của học sinh
 */
void NhapTen(HocSinh &hs) {
    cout << "Nhap ho ten hoc sinh: ";
    while (1) {
        getline(cin, hs.hoTen);
        if (checkName(hs.hoTen)) {break;}  // Kiểm tra tính hợp lệ của tên
    }
}

/**
 * @brief Nhập thông tin của học sinh bao gồm: họ tên, điểm các môn và tính điểm trung bình, xếp loại
 * @param hs Thông tin của học sinh
 */
void NhapThongTin(HocSinh &hs) {
    NhapTen(hs);
    NhapDiemToan(hs);
    NhapDiemVan(hs);
    NhapDiemNN(hs);
    hs.diemTB = TinhDTB(hs.diemToan, hs.diemVan, hs.diemNN);  // Tính điểm trung bình

    // Xếp loại dựa trên điểm trung bình
    if (hs.diemTB < 5) {
        hs.XepLoai = "Yeu";
    } else if (hs.diemTB >= 5 && hs.diemTB < 6.5) {
        hs.XepLoai = "Trung Binh";
    } else if (hs.diemTB >= 6.5 && hs.diemTB <= 8) {
        hs.XepLoai = "Kha";
    } else if (hs.diemTB >= 8 && hs.diemTB < 9) {
        hs.XepLoai = "Gioi";
    } else {
        hs.XepLoai = "Xuat Sac";
    }
}

/**
 * @brief Xuất thông tin của một học sinh
 * @param hs Thông tin của học sinh
 */
void XuatThongTin(const HocSinh& hs) {
    cout << "Ho ten: " << hs.hoTen << '\n';
    cout << "Diem toan: " << hs.diemToan << '\n';
    cout << "Diem van: " << hs.diemVan << '\n';
    cout << "Diem ngoai ngu: " << hs.diemNN << '\n';
    cout << "Diem trung binh: " << hs.diemTB << '\n';
    cout << "Xep loai: " << hs.XepLoai << '\n';
}

/**
 * @brief Tìm học sinh theo tên (không phân biệt chữ hoa, chữ thường)
 * @param danhSach Danh sách học sinh
 * @param tenTimKiem Tên học sinh cần tìm
 */
void timKiemTheoTen(const vector<HocSinh>& danhSach, const string& tenTimKiem) {
    bool timThay = false;
    for (const auto& hs : danhSach) {
        string hoTenLower = hs.hoTen;
        transform(hoTenLower.begin(), hoTenLower.end(), hoTenLower.begin(), ::tolower);
        string tenTimKiemLower = tenTimKiem;
        transform(tenTimKiemLower.begin(), tenTimKiemLower.end(), tenTimKiemLower.begin(), ::tolower);
        
        if (hoTenLower.find(tenTimKiemLower) != string::npos) {
            XuatThongTin(hs);
            timThay = true;
        }
    }
    if (!timThay) {
        cout << "Khong tim thay hoc sinh co ten \"" << tenTimKiem << "\".\n";
    }
}

/**
 * @brief Tìm học sinh có điểm trung bình cao nhất trong danh sách
 * @param danhSach Danh sách học sinh
 */
void timHocSinhDiemCaoNhat(const vector<HocSinh>& danhSach) {
    float diemCaoNhat = -1;
    HocSinh hsCaoNhat;
    for (const auto& hs : danhSach) {
        if (hs.diemTB > diemCaoNhat) {
            diemCaoNhat = hs.diemTB;
            hsCaoNhat = hs;
        }
    }

    cout <<"--------------------------------------------------------------------------\n";
    cout << "Hoc sinh co diem trung binh cao nhat:\n";

    for (const auto& hs : danhSach) {
        if (hs.diemTB == diemCaoNhat) {
            XuatThongTin(hs);
        }
    }

}

/**
 * @brief Tìm học sinh có điểm Toán thấp nhất trong danh sách
 * @param danhSach Danh sách học sinh
 */
void timHocSinhDiemToanThap(const vector<HocSinh>& danhSach) {
    float diemToanThapNhat = 11;  // Điểm tối đa là 10, khởi tạo với giá trị lớn hơn
    vector<HocSinh> hsDiemThap;
    for (const auto& hs : danhSach) {
        if (hs.diemToan < diemToanThapNhat) {
            diemToanThapNhat = hs.diemToan;
        }
    }

    for (const auto& hs : danhSach) {
        if (hs.diemToan == diemToanThapNhat) {
            hsDiemThap.push_back(hs);
        }
    }

    cout << "Hoc sinh co diem Toan thap nhat:\n";
    for (const auto& hs : hsDiemThap) {
        XuatThongTin(hs);
    }
}


int main() {
    int n;  // Số lượng học sinh
    cout << "Nhap so luong hoc sinh: ";
    cin >> n;

    vector<HocSinh> danhSachHocSinh(n);

    // Nhập thông tin cho từng học sinh
    for (int i = 0; i < n; i++) {
        cout << "Nhap thong tin cho hoc sinh " << i+1 << ":\n";
        NhapThongTin(danhSachHocSinh[i]);
    }
    cout <<"--------------------------------------------------------------------------\n";
    // Xuất thông tin của tất cả học sinh
    for (int i=0; i < n; i++) {
        XuatThongTin(danhSachHocSinh[i]);
    }

    // Tìm học sinh có điểm trung bình cao nhất
    timHocSinhDiemCaoNhat(danhSachHocSinh);
    cout <<"--------------------------------------------------------------------------\n";

    // Tìm học sinh theo tên
    string tenTimKiem;
    cout << "Nhap ten hoc sinh can tim: ";
    cin.ignore();  // Bỏ qua kí tự '\n' còn lại
    getline(cin, tenTimKiem);
    timKiemTheoTen(danhSachHocSinh, tenTimKiem);
    cout <<"--------------------------------------------------------------------------\n";
    // Tìm học sinh có điểm Toán thấp nhất
    timHocSinhDiemToanThap(danhSachHocSinh);

    return 0;
}
