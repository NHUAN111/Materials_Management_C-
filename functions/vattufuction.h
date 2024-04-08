#include <bits/stdc++.h>
#include "../models/vattu.h"

class VatTuFunction
{
public:
    void chucNangVatTu();
    vector<VatTu> docFile(const string &path);
    void hienThiTatCaVatTu(vector<VatTu> &vatTu);
    void themVatTu(vector<VatTu> &vatTu, string path);
    void suaVatTu(vector<VatTu> &vatTu, const string &codeToUpdate, const string &filePath);
    void xoaVatTu(vector<VatTu> &vatTu, const string &codeToDelete, const string &filePath);
};
