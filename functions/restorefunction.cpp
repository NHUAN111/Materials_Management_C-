#include <bits/stdc++.h>
#include "../functions/restorefunction.h"
#include "../functions/vattufuction.h"
#include "../functions/phieugiaofunction.h"
#include "../functions/chitietphieugiaofunction.h"

using namespace std;

// Chuc nang khoi phuc du lieu
void RestoreFunction::chucNangKhoiPhuc()
{
    int chucNang;
    string fileName;
    vector<VatTu> vatTu;

    // Phieu giao
    vector<PhieuGiao> phieuGiao;

    // Chi tiet phieu giao
    vector<ChiTietPhieuGiao> ctPG;

    while (true)
    {
        cout << "--------CHUC NANG KHOI PHUC DU LIEU----------" << endl;
        cout << "1. Khoi phuc du lieu vat tu." << endl;
        cout << "2. Khoi phuc du lieu phieu giao." << endl;
        cout << "3. Khoi phuc du lieu chi tiet phieu giao." << endl;
        cout << "4. Thoat chuc nang khoi phuc du lieu" << endl;
        cout << "Nhap chuc nang" << endl;
        cin >> chucNang;

        switch (chucNang)
        {
        case 1:
            cout << "Nhap ten file du lieu de sao luu" << endl;
            cin >> fileName;
            restoreVatTu(vatTu, fileName);
            break;

        case 2:
            cout << "Nhap ten file du lieu de sao luu" << endl;
            cin >> fileName;
            restorePhieuGiao(phieuGiao, fileName);
            break;

        case 3:
            cout << "Nhap ten file du lieu de sao luu" << endl;
            cin >> fileName;
            restoreCtPG(ctPG, fileName);
            break;

        case 4:
            return;
            break;

        default:
            cout << "Nhap khong hop le chuc nang" << endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin.sync();
        }
    }
}

// Chuc nang khoi phuc du lieu vat tu
void RestoreFunction::restoreVatTu(vector<VatTu> &vatTu, string fileName)
{
    VatTuFunction vatTuFunction;
    vatTu = vatTuFunction.docFile("E:/Visual_C++/Buoi7_13_03/Backup/" + fileName);
    ofstream fileOutput("E:/Visual_C++/Buoi7_13_03/Data/vattu.csv");
    if (!fileOutput.is_open())
    {
        cout << "Khong the mo file de ghi" << endl;
        return;
    }

    for (const auto &vattu : vatTu)
    {
        fileOutput << vattu.maVatTu << "|" << vattu.tenVatTu << "|" << vattu.donViTinh << endl;
    }
    cout << "Khoi phuc thanh cong du lieu vat tu " << endl;
    fileOutput.close();
}

// Chuc nang khoi phuc du lieu phieu giao
void RestoreFunction::restorePhieuGiao(vector<PhieuGiao> &phieuGiao, string fileName)
{
    PhieuGiaoFunction phieuGiaoFunction;
    phieuGiao = phieuGiaoFunction.docFile("E:/Visual_C++/Buoi7_13_03/Backup/" + fileName);
    ofstream fileOutput("E:/Visual_C++/Buoi7_13_03/Data/phieugiao.csv");
    if (!fileOutput.is_open())
    {
        cout << "Khong the mo file de ghi" << endl;
        return;
    }

    for (const auto &phieugiao : phieuGiao)
    {
        fileOutput << phieugiao.soPhieuGiao << "|" << phieugiao.ngayGiao << "|" << phieugiao.noiGiao << "|" << phieugiao.maKhachHang << endl;
    }
    cout << "Khoi phuc thanh cong du lieu phieu giao " << endl;
    fileOutput.close();
}

// Chuc nang khoi phuc du lieu chi tiet phieu giao
void RestoreFunction::restoreCtPG(vector<ChiTietPhieuGiao> &chiTietPhieuGiao, string fileName)
{
    ChiTietPhieuGiaoFunction chiTietPhieuGiaoFunction;
    chiTietPhieuGiao = chiTietPhieuGiaoFunction.docFile("E:/Visual_C++/Buoi7_13_03/Backup/" + fileName);
    ofstream fileOutput("E:/Visual_C++/Buoi7_13_03/Data/chitietphieugiao.csv");
    if (!fileOutput.is_open())
    {
        cout << "Khong the mo file de ghi" << endl;
        return;
    }

    for (const auto &ctPg : chiTietPhieuGiao)
    {
        fileOutput << ctPg.soPhieuGiao << "|" << ctPg.maVatTu << "|" << ctPg.soLuongGiao << "|" << ctPg.donGiaGiao << endl;
    }
    cout << "Khoi phuc thanh cong du lieu chi tiet phieu giao" << endl;
    fileOutput.close();
}