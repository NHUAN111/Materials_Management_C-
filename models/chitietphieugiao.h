#ifndef CHITIETPHIEUGIAO_H
#define CHITIETPHIEUGIAO_H
#include <string>
using namespace std;

class ChiTietPhieuGiao
{
public:
    string soPhieuGiao;
    string maVatTu;
    int soLuongGiao;
    double donGiaGiao;

public:
    ChiTietPhieuGiao();
    ChiTietPhieuGiao(string _soPhieuGiao,
                     string _maVatTu,
                     int _soLuongGiao,
                     double _donGiaGiao);
};

#endif