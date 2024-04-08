#include <bits/stdc++.h>
#include "../models/phieugiao.h"

class PhieuGiaoFunction
{
public:
    void chucNangPhieuGiao();
    vector<PhieuGiao> docFile(const string &path);
    void hienThiTatCaPhieuGiao(vector<PhieuGiao> &phieuGiao);
    void themPhieuGiao(vector<PhieuGiao> &phieuGiao, string path);
    void suaPhieuGiao(vector<PhieuGiao> &phieuGiao, const string &codeToUpdate, const string &filePath);
    void xoaPhieuGiao(vector<PhieuGiao> &phieuGiao, const string &codeToDelete, const string &filePath);
};
