#include "vattu.h"
#include <iostream>

VatTu::VatTu(string _maVatTu, string _tenVatTu, string _donViTinh)
{
    maVatTu = _maVatTu;
    tenVatTu = _tenVatTu;
    donViTinh = _donViTinh;
}

VatTu::VatTu() {}

// Getter và Setter cho maVatTu
string VatTu::getMaVatTu()
{
    return maVatTu;
}

void VatTu::setMaVatTu(string _maVatTu)
{
    maVatTu = _maVatTu;
}

// Getter và Setter cho tenVatTu
string VatTu::getTenVatTu()
{
    return tenVatTu;
}

void VatTu::setTenVatTu(string _tenVatTu)
{
    tenVatTu = _tenVatTu;
}

// Getter và Setter cho donViTinh
string VatTu::getDonViTinh()
{
    return donViTinh;
}

void VatTu::setDonViTinh(string _donViTinh)
{
    donViTinh = _donViTinh;
}