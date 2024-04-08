#ifndef RESTORE_H
#define RESTORE_H

#include <bits/stdc++.h>
#include "../models/vattu.h"
#include "../models/phieugiao.h"
#include "../models/chitietphieugiao.h"
using namespace std;

class RestoreFunction
{
public:
    void chucNangKhoiPhuc();
    void restoreVatTu(vector<VatTu> &vatTu, string fileName);
    void restorePhieuGiao(vector<PhieuGiao> &phieuGiao, string fileName);
    void restoreCtPG(vector<ChiTietPhieuGiao> &chiTietPhieuGiao, string fileName);
};

#endif