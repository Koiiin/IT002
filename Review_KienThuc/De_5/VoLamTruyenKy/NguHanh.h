#ifndef NGUHANH_H
#define NGUHANH_H

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class NguHanh {
public:
    static const unordered_map<string, string> MonPhai_NguHanh;
    static const unordered_map<string, string> Hanh_Sinh;
    static const unordered_map<string, string> Hanh_Khac;

    static string LayNguHanhTuMonPhai(const std::string& monPhai);

    static double TinhSatThuongTuongTac(const std::string& nguHanhA, const std::string& nguHanhB, double satThuongGoc);
};

#endif
