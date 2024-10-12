#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// Định nghĩa cấu trúc ChuyenBay để lưu trữ thông tin về chuyến bay
struct ChuyenBay {
    string maChuyenBay;   // Mã chuyến bay
    string ngayBay;       // Ngày bay (dd/mm/yyyy)
    string gioBay;        // Giờ bay (HH:mm)
    string noiDi;         // Nơi đi
    string noiDen;        // Nơi đến
};

// Hàm kiểm tra tính hợp lệ của giờ bay
// Đầu vào: chuỗi 'gio' theo định dạng HH:mm
// Đầu ra: true nếu giờ hợp lệ, false nếu không hợp lệ
bool kiemTraGioHopLe(const string& gio) {
    // Kiểm tra độ dài chuỗi và dấu phân cách ':'
    if (gio.length() != 5 || gio[2] != ':') {
        return false;
    }

    // Lấy giá trị giờ và phút từ chuỗi
    int gioInt = stoi(gio.substr(0, 2));  // Lấy giờ
    int phutInt = stoi(gio.substr(3));    // Lấy phút

    // Kiểm tra giờ và phút có hợp lệ hay không (0 <= giờ <= 23, 0 <= phút <= 59)
    return (gioInt >= 0 && gioInt <= 23 && phutInt >= 0 && phutInt <= 59);
}

// Hàm kiểm tra tính hợp lệ của ngày bay
// Đầu vào: chuỗi 'ngay' theo định dạng dd/mm/yyyy
// Đầu ra: true nếu ngày hợp lệ, false nếu không hợp lệ
bool kiemTraNgayHopLe(const string& ngay) {
    // Kiểm tra định dạng dd/mm/yyyy
    if (ngay.length() != 10 || ngay[2] != '/' || ngay[5] != '/') {
        return false;
    }

    // Trích xuất ngày, tháng, năm từ chuỗi
    int ngayInt = stoi(ngay.substr(0, 2));  // Ngày (dd)
    int thangInt = stoi(ngay.substr(3, 2)); // Tháng (mm)
    int namInt = stoi(ngay.substr(6, 4));   // Năm (yyyy)

    // Kiểm tra tháng hợp lệ (1 <= thang <= 12)
    if (thangInt < 1 || thangInt > 12) {
        return false;
    }

    // Mảng số ngày tối đa trong từng tháng
    int soNgayToiDaTrongThang[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    // Kiểm tra năm nhuận (tháng 2 có 29 ngày nếu năm nhuận)
    if ((namInt % 4 == 0 && namInt % 100 != 0) || (namInt % 400 == 0)) {
        soNgayToiDaTrongThang[1] = 29;  // Tháng 2 có 29 ngày nếu năm nhuận
    }

    // Kiểm tra ngày có hợp lệ trong tháng đã cho
    if (ngayInt < 1 || ngayInt > soNgayToiDaTrongThang[thangInt - 1]) {
        return false;
    }

    return true;
}

// Hàm kiểm tra tên địa danh có hợp lệ hay không (không chứa ký tự số hoặc ký tự đặc biệt)
// Đầu vào: chuỗi 'ten' là tên địa danh
// Đầu ra: true nếu tên địa danh hợp lệ, false nếu không hợp lệ
bool kiemTraTenDiaDanh(const string& ten) {
    // Kiểm tra nếu tên chứa ký tự không phải chữ cái hoặc dấu cách
    for (char c : ten) {
        if (!isalpha(c) && !isspace(c)) {
            return false;
        }
    }
    return true;
}

// Hàm nhập thông tin chuyến bay
// Đầu vào: tham chiếu đến đối tượng 'cb' (ChuyenBay)
// Đầu ra: không có, cập nhật đối tượng 'cb' với thông tin chuyến bay hợp lệ
void nhapChuyenBay(ChuyenBay &cb) {
    do {
        cout << "Nhap ma chuyen bay (toi da 5 ky tu): ";
        cin.ignore();
        getline(cin, cb.maChuyenBay);
    } while (cb.maChuyenBay.length() > 5 || !isalpha(cb.maChuyenBay[0]));  // Kiểm tra mã chuyến bay hợp lệ

    do {
        cout << "Nhap ngay bay (dd/mm/yyyy): ";
        getline(cin, cb.ngayBay);
    } while (!kiemTraNgayHopLe(cb.ngayBay));  // Kiểm tra ngày bay hợp lệ

    do {
        cout << "Nhap gio bay (HH:mm): ";
        getline(cin, cb.gioBay);
    } while (!kiemTraGioHopLe(cb.gioBay));  // Kiểm tra giờ bay hợp lệ

    do {
        cout << "Nhap noi di: ";
        getline(cin, cb.noiDi);
    } while (!kiemTraTenDiaDanh(cb.noiDi));  // Kiểm tra nơi đi hợp lệ

    do {
        cout << "Nhap noi den: ";
        getline(cin, cb.noiDen);
    } while (!kiemTraTenDiaDanh(cb.noiDen));  // Kiểm tra nơi đến hợp lệ

    cout <<"--------------------------------------\n";
}

// Hàm tìm kiếm chuyến bay trong danh sách
// Đầu vào: danh sách chuyến bay 'dsChuyenBay', mã chuyến bay 'maChuyenBay'
// Đầu ra: true nếu tìm thấy chuyến bay, false nếu không tìm thấy, chuyến bay tìm được được lưu trong 'ketQua'
bool timKiemChuyenBay(const vector<ChuyenBay> &dsChuyenBay, const string &code, int option, ChuyenBay &ketQua) {
    for (const ChuyenBay &cb : dsChuyenBay) {
        switch (option) {
            case 1: // Tìm kiếm theo mã chuyến bay
                if (cb.maChuyenBay == code) {
                    ketQua = cb;
                    return true;
                }
                break;
            case 2: // Tìm kiếm theo nơi đi
                if (cb.noiDi == code) {
                    ketQua = cb;
                    return true;
                }
                break;
            case 3: // Tìm kiếm theo nơi đến
                if (cb.noiDen == code) {
                    ketQua = cb;
                    return true;
                }
                break;
            default:
                return false;
        }
    }
    return false;
}

// Hàm so sánh hai chuyến bay theo ngày và giờ bay
// Đầu vào: hai chuyến bay 'cb1' và 'cb2'
// Đầu ra: true nếu 'cb1' trước 'cb2', false nếu ngược lại
bool soSanhChuyenBay(const ChuyenBay &cb1, const ChuyenBay &cb2) {
    return (cb1.ngayBay + cb1.gioBay) < (cb2.ngayBay + cb2.gioBay);
}

// Hàm đếm số lượng chuyến bay từ một nơi đi đến một nơi đến
// Đầu vào: danh sách chuyến bay 'dsChuyenBay', nơi đi 'noiDi', nơi đến 'noiDen'
// Đầu ra: số lượng chuyến bay từ 'noiDi' đến 'noiDen'
int demChuyenBay(const vector<ChuyenBay> &dsChuyenBay, const string &noiDi, const string &noiDen) {
    int dem = 0;
    for (const ChuyenBay &cb : dsChuyenBay) {
        if (cb.noiDi == noiDi && cb.noiDen == noiDen) {
            dem++;
        }
    }
    return dem;
}

// Hàm sắp xếp danh sách chuyến bay theo ngày và giờ
void sapXepChuyenBay(vector<ChuyenBay>& dsChuyenBay) {
    sort(dsChuyenBay.begin(), dsChuyenBay.end(), [](const ChuyenBay& cb1, const ChuyenBay& cb2) {
        // Kết hợp ngày và giờ thành một chuỗi duy nhất để so sánh
        string ngayGio1 = cb1.ngayBay + cb1.gioBay;
        string ngayGio2 = cb2.ngayBay + cb2.gioBay;
        return ngayGio1 < ngayGio2; // So sánh chuỗi ngày + giờ để sắp xếp từ sớm đến muộn
    });
}

// Hàm xuất thông tin chuyến bay
// Đầu vào: chuyến bay 'cb'
// Đầu ra: không có, chỉ hiển thị thông tin chuyến bay
void xuatChuyenBay(const ChuyenBay &cb) {
    cout << "Ma chuyen bay: " << cb.maChuyenBay << '\n';
    cout << "Ngay bay: " << cb.ngayBay << '\n';
    cout << "Gio bay: " << cb.gioBay << '\n';
    cout << "Noi di: " << cb.noiDi << '\n';
    cout << "Noi den: " << cb.noiDen << '\n';
}

// Hàm hiển thị danh sách chuyến bay khởi hành từ nơi cụ thể trong một ngày nhất định
void hienThiChuyenBayTheoNgayVaNoiDi(const vector<ChuyenBay>& dsChuyenBay) {
    string noiDi, ngayBay;
    
    // Nhập nơi đi và ngày bay
    cout << "Nhap noi di: ";
    cin.ignore(); // Đảm bảo loại bỏ ký tự newline còn lại trong bộ đệm
    getline(cin, noiDi);
    
    cout << "Nhap ngay bay (dd/mm/yyyy): ";
    getline(cin, ngayBay);
    
    // Tìm và hiển thị các chuyến bay thỏa mãn
    bool timThay = false;
    for (const ChuyenBay& cb : dsChuyenBay) {
        if (cb.noiDi == noiDi && cb.ngayBay == ngayBay) {
            xuatChuyenBay(cb);
            timThay = true;
        }
    }

    if (!timThay) {
        cout << "Khong tim thay chuyen bay khoi hanh tu " << noiDi << " vao ngay " << ngayBay << "!\n";
    }
}


int main() {
    vector<ChuyenBay> dsChuyenBay;
    int luaChon;

    do {
        cout << "===== Menu ======\n";
        cout << "1. Nhap danh sach chuyen bay\n";
        cout << "2. Hien thi danh sach chuyen bay\n";
        cout << "3. Tim kiem chuyen bay\n";
        cout << "4. Sap xep danh sach\n";
        cout << "5. Dem so luong chuyen bay\n";
        cout << "6. Hien thi danh sach chuyen bay tu noi va ngay co dinh\n";
        cout << "0. Thoat\n";
        cout << "Nhap lua chon: ";
        cin >> luaChon;

        switch (luaChon) {
            case 1: {
                // Nhập danh sách chuyến bay
                int n;
                cout << "Nhap so luong chuyen bay: ";
                cin >> n;
                for (int i = 0; i < n; ++i) {
                    ChuyenBay cb;
                    nhapChuyenBay(cb);
                    dsChuyenBay.push_back(cb);
                }
                break;
            }
            case 2: {
                // Hiển thị danh sách chuyến bay
                for (const ChuyenBay& cb : dsChuyenBay) {
                    xuatChuyenBay(cb);
                }
                break;
            }
            case 3: {
                // Tìm kiếm chuyến bay
                int option;
                cout << "Chon tieu chi tim kiem:\n";
                cout << "1. Ma chuyen bay\n";
                cout << "2. Noi di\n";
                cout << "3. Noi den\n";
                cout << "Nhap lua chon: ";
                cin >> option;

                string code;
                cout << "Nhap gia tri can tim: ";
                cin.ignore(); 
                getline(cin, code);

                ChuyenBay ketQua;
                if (timKiemChuyenBay(dsChuyenBay, code, option, ketQua)) {
                    xuatChuyenBay(ketQua);
                } else {
                    cout << "Khong tim thay chuyen bay!\n";
                }
                break;
            }
            case 4: {
                // Sắp xếp danh sách chuyến bay theo ngày và giờ
                sapXepChuyenBay(dsChuyenBay);
                cout << "Danh sach da duoc sap xep theo thu tu ngay va gio!\n";
                break;
            }
            case 5: {
                // Đếm số lượng chuyến bay
                string noiDi, noiDen;
                cout << "Nhap noi di: ";
                cin >> noiDi;
                cout << "Nhap noi den: ";
                cin >> noiDen;
                int soLuong = demChuyenBay(dsChuyenBay, noiDi, noiDen);
                cout << "So luong chuyen bay tu " << noiDi << " den " << noiDen << " la: " << soLuong << endl;
                break;
            }
            case 6: {
                // Hiển thị chuyến bay khởi hành từ nơi và ngày nhất định
                hienThiChuyenBayTheoNgayVaNoiDi(dsChuyenBay);
                break;
            }
            case 0:
                break;
        }
    } while (luaChon != 0);

    return 0;
}
