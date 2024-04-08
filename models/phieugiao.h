#ifndef PHIEUGIAO_H
#define PHIEUGIAO_H
#include <string>
using namespace std;

class PhieuGiao
{
public:
    string soPhieuGiao;
    string ngayGiao;
    string noiGiao;
    string maKhachHang;

public:
    PhieuGiao();
    PhieuGiao(string _soPhieuGiao, string _ngayGiao, string _noiGiao, string _maKhachHang);
};

#endif