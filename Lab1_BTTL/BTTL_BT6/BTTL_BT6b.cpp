#include <bits/stdc++.h>
#include <vector>
#include <string>

using namespace std;

struct HocSinh {
    string hoTen;
    float diemToan;
    float diemVan;
    float diemNN;
    float diemTB;
    string XepLoai;
};

bool checkName(const string& name) {
    if (name.length() < 1) return false;
    for (char c : name) {
        if (isdigit(c)) return false;
    }
    return true;
}


float TinhDTB(float toan, float van, float ngoaingu) { return (2*toan + van + ngoaingu) / 4 ;}

bool checkDiem(float x) {
    if (x >= 0 && x <= 10) return true;
    else return false;
}

void NhapDiemToan(HocSinh &hs) {
    cout << "Nhap diem toan: ";
    
    while (1) {
        cin >> hs.diemToan;
        if (checkDiem(hs.diemToan)) break;
        else {
            cout << "Nhap lai diem toan\n";
        }
    }
}

void NhapDiemVan(HocSinh &hs) {
    cout << "Nhap diem van: ";
    while (1) {
        cin >> hs.diemVan;
        if (checkDiem(hs.diemVan)) break;
        else {
            cout << "Nhap lai diem van\n";
        }
    }
}

void NhapDiemNN(HocSinh &hs) {
    cout << "Nhap diem ngoai ngu: ";
    while (1) {
        cin >> hs.diemNN;
        if (checkDiem(hs.diemNN)) break;
        else {
            cout << "Nhap lai diem ngoai ngu\n";
        }
    }
}

void NhapTen(HocSinh &hs) {
    cout << "Nhap ho ten hoc sinh: ";
    
    while (1) {
        getline(cin, hs.hoTen);
        if (checkName(hs.hoTen)) { break; }
    }
}

void NhapThongTin (HocSinh &hs) {
    
    NhapTen(hs);
    NhapDiemToan(hs);
    NhapDiemVan(hs);
    NhapDiemNN(hs);
    hs.diemTB = TinhDTB(hs.diemToan, hs.diemVan, hs.diemNN);

    if (hs.diemTB < 5) {
        hs.XepLoai = "Yeu";
    } else if (hs.diemTB >= 5 && hs.diemTB < 6.5) {
        hs.XepLoai = "Trung Binh";
    } else if (hs.diemTB >= 6.5 && hs.diemTB <= 8) {
        hs.XepLoai = "Kha";
    } else if (hs.diemTB >= 8 && hs.diemTB < 9) {
        hs.XepLoai = "Gioi";
    } else { hs.XepLoai = "Xuat Sac";}
}


void XuatThongTin (const HocSinh& hs) {
    cout << "Ho ten: " << hs.hoTen << '\n';
    cout << "Diem toan: " << hs.diemToan << '\n';
    cout << "Diem van: " << hs.diemVan << '\n';
    cout << "Diem ngoai ngu: " << hs.diemNN << '\n';
    cout << "Diem trung binh: " << hs.diemTB << '\n';
    cout << "Xep loai: " << hs.XepLoai << '\n';
}

// Hàm tìm kiếm học sinh theo tên (không phân biệt chữ hoa chữ thường)
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



// Hàm tìm kiếm học sinh có điểm trung bình cao nhất
void timHocSinhDiemCaoNhat(const vector<HocSinh>& danhSach) {
    float diemCaoNhat = -1;
    HocSinh hsCaoNhat;
    for (const auto& hs : danhSach) {
        if (hs.diemTB > diemCaoNhat) {
            diemCaoNhat = hs.diemTB;
            hsCaoNhat = hs;
        }
    }
    cout << "Hoc sinh co diem trung binh cao nhat:\n";
    XuatThongTin(hsCaoNhat);
}

// Hàm xuất danh sách học sinh có điểm toán thấp nhất
void timHocSinhDiemToanThap(const vector<HocSinh>& danhSach) {
    float diemToanThapNhat = 11;  // Điểm Toán tối đa là 10
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
    for (const auto& hs : danhSachHocSinh) {
        XuatThongTin(hs);
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
