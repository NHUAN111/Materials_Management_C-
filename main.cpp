#include <bits/stdc++.h>
#include "functions/vattufuction.h"
#include "models/vattu.h"

#include "functions/phieugiaofunction.h"
#include "models/phieugiao.h"

#include "functions/chitietphieugiaofunction.h"
#include "models/chitietphieugiao.h"

#include "functions/backupfunction.h"
#include "functions/restorefunction.h"

#include <iomanip>
#include <ctime>
#include <sstream>

using namespace std;

int main()
{
    int thuTuChucNang, nVatTuGiaCao, nVatTuBanNN;
    string soPG;

    // Vat tu
    VatTuFunction vatTuFunction;

    // Phieu giao
    PhieuGiaoFunction phieuGiaoFunction;
    string pathPhieuGiao = "E:/Visual_C++/Buoi7_13_03/Data/phieugiao.csv";
    vector<PhieuGiao> phieuGiao;
    phieuGiao = phieuGiaoFunction.docFile(pathPhieuGiao);

    // Chi tiet phieu giao
    ChiTietPhieuGiaoFunction chiTietPhieuGiaoFunction;
    const string pathChiTietPhieuGiao = "E:/Visual_C++/Buoi7_13_03/Data/chitietphieugiao.csv";
    vector<ChiTietPhieuGiao> chiTietPG;
    chiTietPG = chiTietPhieuGiaoFunction.docFile(pathChiTietPhieuGiao);

    // Sao luu
    BackUpFunction backUpFunction;

    // Khoi phuc du lieu
    RestoreFunction restoreFunction;

    while (true)
    {
        cout << "------------------MENU CHUC NANG-------------------" << endl;
        cout << "1. Quan ly vat tu" << endl;
        cout << "2. Quan ly phieu giao" << endl;
        cout << "3. Quan ly chi tiet phieu giao" << endl;
        cout << "4. Thong ke N vat tu gia cao nhat" << endl;
        cout << "5. Tong tien cua phieu giao" << endl;
        cout << "6. Thong ke so phieu giao, ngay giao, noi giao va tong tien " << endl;
        cout << "7. Thong ke N vat tu ban nhieu nhat" << endl;
        cout << "8. Thong ke doanh thu cua cong ty" << endl;
        cout << "9. Sao luu du lieu" << endl;
        cout << "10. Phuc hoi du lieu" << endl;
        cout << "Nhap chuc nang: ";
        cin >> thuTuChucNang;

        switch (thuTuChucNang)
        {
        case 1:
            vatTuFunction.chucNangVatTu();
            break;

        case 2:
            phieuGiaoFunction.chucNangPhieuGiao();
            break;

        case 3:
            chiTietPhieuGiaoFunction.chucNangChiTietPG();
            break;

        case 4:
            cout << "Nhap N vat tu can thong ke co gia cao nhat: " << endl;
            cin >> nVatTuGiaCao;
            chiTietPhieuGiaoFunction.thongKeVatTuGiaCao(chiTietPG, nVatTuGiaCao);
            break;

        case 5:
            cout << "Nhap so phieu giao: " << endl;
            cin >> soPG;
            chiTietPhieuGiaoFunction.thongKeTongTien(chiTietPG, soPG);
            break;

        case 6:
            time_t thoiGianBatDau, thoiGianKetThuc;
            chiTietPhieuGiaoFunction.nhapThoiGian(thoiGianBatDau, thoiGianKetThuc);
            chiTietPhieuGiaoFunction.thongKePhieuGiaoTrongKhoangThoiGian(phieuGiao, chiTietPG, thoiGianBatDau, thoiGianKetThuc);
            break;

        case 7:
            cout << "Nhap N vat tu can thong ke: " << endl;
            cin >> nVatTuBanNN;
            chiTietPhieuGiaoFunction.thongKeVatTu(chiTietPG, nVatTuBanNN);
            break;

        case 8:
            time_t tgBatDau, tgKetThuc;
            chiTietPhieuGiaoFunction.nhapThoiGian(tgBatDau, tgKetThuc);
            chiTietPhieuGiaoFunction.thongKeTongTien(phieuGiao, chiTietPG, tgBatDau, tgKetThuc);
            break;

        case 9:
            backUpFunction.chucNangSaoLuu();
            break;

        case 10:
            restoreFunction.chucNangKhoiPhuc();
            break;

        default:
            cout << "Nhap khong hop le chuc nang";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin.sync();
        }
    }
    return 0;
}