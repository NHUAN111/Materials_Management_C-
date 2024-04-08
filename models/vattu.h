#ifndef VATTU_H
#define VATTU_H
#include <string>
using namespace std;

class VatTu
{
public:
    string maVatTu;
    string tenVatTu;
    string donViTinh;

public:
    VatTu(string _maVatTu, string _tenVatTu, string _donViTinh);

    VatTu();

    // Getter và Setter cho maVatTu
    string getMaVatTu();
    void setMaVatTu(string _maVatTu);

    // Getter và Setter cho tenVatTu
    string getTenVatTu();
    void setTenVatTu(string _tenVatTu);

    // Getter và Setter cho donViTinh
    string getDonViTinh();
    void setDonViTinh(string _donViTinh);
};

#endif