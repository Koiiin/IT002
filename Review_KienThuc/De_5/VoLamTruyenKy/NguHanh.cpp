#include "NguHanh.h"
#include <stdexcept>
using namespace std;

const unordered_map<string, string> NguHanh::MonPhai_NguHanh = {
    {"Thieu Lam", "Kim"}, {"Thien Vuong bang", "Kim"},
    {"Ngu Doc giao", "Moc"}, {"Duong Mon", "Moc"},
    {"Nga My", "Thuy"}, {"Thuy Yen mon", "Thuy"},
    {"Cai Bang", "Hoa"}, {"Thien Nhan giao", "Hoa"},
    {"Con Lon", "Tho"}, {"Vo Dang", "Tho"}
};

const unordered_map<string, string> NguHanh::Hanh_Sinh = {
    {"Hoa", "Tho"}, {"Tho", "Kim"},
    {"Kim", "Thuy"}, {"Thuy", "Moc"}, 
    {"Moc", "Hoa"}
};

const unordered_map<string, string> NguHanh::Hanh_Khac = {
    {"Moc", "Tho"}, {"Tho", "Thuy"},
    {"Thuy", "Hoa"}, {"Hoa", "Kim"}, 
    {"Kim", "Moc"}
};

string NguHanh::LayNguHanhTuMonPhai(const string& monPhai) {
    if (MonPhai_NguHanh.find(monPhai) != MonPhai_NguHanh.end()) {
        return MonPhai_NguHanh.at(monPhai);
    }
    throw invalid_argument("Mon phai khong hop le");
}


double NguHanh::TinhSatThuongTuongTac(const string& nguHanhA, const string& nguHanhB, double satThuongGoc) {
    if (Hanh_Sinh.at(nguHanhA) == nguHanhB) {
        return satThuongGoc * 1.1; 
    }
    else if (Hanh_Khac.at(nguHanhA) == nguHanhB) {
        return satThuongGoc * 1.2; 
    }
    else if (Hanh_Khac.at(nguHanhB) == nguHanhA) {
        return satThuongGoc * 0.8; 
    }
    return satThuongGoc; 
}
