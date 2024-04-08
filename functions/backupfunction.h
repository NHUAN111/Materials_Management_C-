#ifndef BACKUP_H
#define BACKUP_H

#include <bits/stdc++.h>
#include "../models/vattu.h"
#include "../models/phieugiao.h"
#include "../models/chitietphieugiao.h"
using namespace std;

class BackUpFunction
{
public:
    void chucNangSaoLuu();
    void backupDataVatTu(vector<VatTu> &vatTu);
    void backupDataPhieuGiao(vector<PhieuGiao> &phieuGiao);
    void backupDataCtPG(vector<ChiTietPhieuGiao> &chiTietPhieuGiao);
};

#endif