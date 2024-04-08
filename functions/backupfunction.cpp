#include <bits/stdc++.h>
#include "../functions/backupfunction.h"
#include "../functions/vattufuction.h"
#include "../functions/phieugiaofunction.h"
#include "../functions/chitietphieugiaofunction.h"

using namespace std;

void BackUpFunction::chucNangSaoLuu()
{
    int chucNang;
    // Vat tu
    VatTuFunction vatTuFunction;
    vector<VatTu> vatTu;
    string pathVatTu = "E:/Visual_C++/Buoi7_13_03/Data/vattu.csv";
    vatTu = vatTuFunction.docFile(pathVatTu);

    // Phieu giao
    PhieuGiaoFunction phieuGiaoFunction;
    vector<PhieuGiao> phieuGiao;
    string pathPG = "E:/Visual_C++/Buoi7_13_03/Data/phieugiao.csv";
    phieuGiao = phieuGiaoFunction.docFile(pathPG);

    // Chi tiet phieu giao
    ChiTietPhieuGiaoFunction chiTietPhieuGiaoFunction;
    vector<ChiTietPhieuGiao> ctPG;
    string pathCtPG = "E:/Visual_C++/Buoi7_13_03/Data/chitietphieugiao.csv";
    ctPG = chiTietPhieuGiaoFunction.docFile(pathCtPG);

    while (true)
    {
        cout << "--------CHUC NANG SAO LUU DU LIEU----------" << endl;
        cout << "1. Sao luu du lieu vat tu." << endl;
        cout << "2. Sao luu du lieu phieu giao." << endl;
        cout << "3. Sao luu du lieu chi tiet phieu giao." << endl;
        cout << "4. Thoat chuc nang sao luu" << endl;
        cout << "Nhap chuc nang" << endl;
        cin >> chucNang;

        switch (chucNang)
        {
        case 1:
            backupDataVatTu(vatTu);
            break;

        case 2:
            backupDataPhieuGiao(phieuGiao);
            break;

        case 3:
            backupDataCtPG(ctPG);
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

// Chuc nang sao luu vat tu
void BackUpFunction::backupDataVatTu(vector<VatTu> &vatTu)
{
    auto now = std::chrono::system_clock::now();
    std::time_t currentTime = std::chrono::system_clock::to_time_t(now);

    std::ostringstream oss;
    oss << std::put_time(std::localtime(&currentTime), "%Y-%m-%d_%H-%M-%S") << ".csv";
    std::string backupFileName = "E:/Visual_C++/Buoi7_13_03/Backup/VatTu-" + oss.str();

    std::ofstream backupFile(backupFileName);
    if (!backupFile.is_open())
    {
        std::cerr << "Khong the mo file sao luu" << std::endl;
        return;
    }

    for (const auto &vattu : vatTu)
    {
        backupFile << vattu.maVatTu << "|" << vattu.tenVatTu << "|" << vattu.donViTinh << endl;
    }

    backupFile.close();
    std::cout << "Da sao luu du lieu vat tu vao " << backupFileName << std::endl;
}

// Chuc nang sao luu phieu giao
void BackUpFunction::backupDataPhieuGiao(vector<PhieuGiao> &phieuGiao)
{
    auto now = std::chrono::system_clock::now();
    std::time_t currentTime = std::chrono::system_clock::to_time_t(now);

    std::ostringstream oss;
    oss << std::put_time(std::localtime(&currentTime), "%Y-%m-%d_%H-%M-%S") << ".csv";
    std::string backupFileName = "E:/Visual_C++/Buoi7_13_03/Backup/PhieuGiao-" + oss.str();

    std::ofstream backupFile(backupFileName);
    if (!backupFile.is_open())
    {
        std::cerr << "Khong the mo file sao luu" << std::endl;
        return;
    }

    for (const auto &phieugiao : phieuGiao)
    {
        backupFile << phieugiao.soPhieuGiao << "|" << phieugiao.ngayGiao << "|" << phieugiao.noiGiao << "|" << phieugiao.maKhachHang << endl;
    }

    backupFile.close();
    std::cout << "Da sao luu du lieu phieu giao vao " << backupFileName << std::endl;
}

// Chuc nang sao luu chi tiet phieu giao
void BackUpFunction::backupDataCtPG(vector<ChiTietPhieuGiao> &chiTietPhieuGiao)
{
    auto now = std::chrono::system_clock::now();
    std::time_t currentTime = std::chrono::system_clock::to_time_t(now);

    std::ostringstream oss;
    oss << std::put_time(std::localtime(&currentTime), "%Y-%m-%d_%H-%M-%S") << ".csv";
    std::string backupFileName = "E:/Visual_C++/Buoi7_13_03/Backup/CtPG-" + oss.str();

    std::ofstream backupFile(backupFileName);
    if (!backupFile.is_open())
    {
        std::cerr << "Khong the mo file sao luu" << std::endl;
        return;
    }

    for (const auto &ctPg : chiTietPhieuGiao)
    {
        backupFile << ctPg.soPhieuGiao << "|" << ctPg.maVatTu << "|" << ctPg.soLuongGiao << "|" << ctPg.donGiaGiao << endl;
    }

    backupFile.close();
    std::cout << "Da sao luu du lieu chi tiet phieu giao vao " << backupFileName << std::endl;
}