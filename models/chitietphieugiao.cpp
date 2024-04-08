#include "chitietphieugiao.h"
#include <iostream>

ChiTietPhieuGiao::ChiTietPhieuGiao() {}

ChiTietPhieuGiao::ChiTietPhieuGiao(string _soPhieuGiao, string _maVatTu, int _soLuongGiao, double _donGiaGiao)
{
    soPhieuGiao = _soPhieuGiao;
    maVatTu = _maVatTu;
    soLuongGiao = _soLuongGiao;
    donGiaGiao = _donGiaGiao;
}