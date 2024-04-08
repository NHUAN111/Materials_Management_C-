#include <bits/stdc++.h>
#include "../functions/phieugiaofunction.h"
#include "../functions/chitietphieugiaofunction.h"
using namespace std;

PhieuGiao::PhieuGiao(std::string _soPhieuGiao, std::string _ngayGiao, std::string _noiGiao, std::string _maKhachHang)
    : soPhieuGiao(_soPhieuGiao), ngayGiao(_ngayGiao), noiGiao(_noiGiao), maKhachHang(_maKhachHang) {}

// Ham chuc nang cua phieu giao
void PhieuGiaoFunction::chucNangPhieuGiao()
{
    int chucNang;
    string codePhieuGiao;
    string pathPhieuGiao = "E:/Visual_C++/Buoi7_13_03/Data/phieugiao.csv";
    vector<PhieuGiao> phieuGiao;
    phieuGiao = docFile(pathPhieuGiao);
    while (true)
    {
        cout << "--------QUAN LY PHIEU GIAO----------" << endl;
        cout << "1. Hien thi phieu giao" << endl;
        cout << "2. Them phieu giao" << endl;
        cout << "3. Sua phieu giao" << endl;
        cout << "4. Xoa phieu giao" << endl;
        cout << "5. Thoat chuc nang phieu giao" << endl;
        cout << "Nhap chuc nang: ";
        cin >> chucNang;

        switch (chucNang)
        {
        case 1:
            hienThiTatCaPhieuGiao(phieuGiao);
            break;

        case 2:
            themPhieuGiao(phieuGiao, pathPhieuGiao);
            break;

        case 3:
            cout << "Nhap so phieu giao can sua: ";
            cin >> codePhieuGiao;
            suaPhieuGiao(phieuGiao, codePhieuGiao, pathPhieuGiao);
            break;

        case 4:
            cout << "Nhap so phieu giao can xoa: ";
            cin >> codePhieuGiao;
            xoaPhieuGiao(phieuGiao, codePhieuGiao, pathPhieuGiao);
            break;

        case 5:
            return;
            break;
        default:
            cout << "Nhap khong hop le chuc nang";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin.sync();
        }
    }
}

// Ham hien thi tat ca phieu giao trong file
void PhieuGiaoFunction::hienThiTatCaPhieuGiao(vector<PhieuGiao> &phieuGiao)
{
    // In tiêu đề
    cout << setw(20) << left << "SoPhieuGiao"
         << setw(20) << left << "NgayGiao"
         << setw(20) << left << "NoiGiao"
         << setw(20) << left << "MaKH"
         << endl;

    // In thông tin các vật tư
    for (const auto &phieugiao : phieuGiao)
    {
        cout << setw(20) << left << phieugiao.soPhieuGiao
             << setw(20) << left << phieugiao.ngayGiao
             << setw(20) << left << phieugiao.noiGiao
             << setw(20) << left << phieugiao.maKhachHang
             << endl;
    }
}

// Ham cat
vector<string> split(const string &input, char delimiter)
{
    vector<string> result;
    stringstream ss(input);
    string token;
    while (getline(ss, token, delimiter))
    {
        result.push_back(token);
    }
    return result;
}

// Ham doc file phieu giao
vector<PhieuGiao> PhieuGiaoFunction::docFile(const string &path)
{
    vector<PhieuGiao> phieuGiao;
    ifstream file(path);

    if (!file.is_open())
    {
        cout << "Không thể mở file " << path << endl;
        return phieuGiao;
    }

    string line;
    while (getline(file, line))
    {
        vector<string> data = split(line, '|');
        if (data.size() == 4)
        {
            string soPhieuGiao = data[0];
            string noiGiao = data[1];
            string ngayGiao = data[2];
            string maKhachHang = data[3];

            PhieuGiao phieugiao(soPhieuGiao, noiGiao, ngayGiao, maKhachHang);
            phieuGiao.push_back(phieugiao);
        }
    }

    file.close();
    return phieuGiao;
}

// Ham them phieu giao
// Khi them phieu giao thi nguoi dung co the them chi tiet phieu giao tuy vao so luong
void PhieuGiaoFunction::themPhieuGiao(vector<PhieuGiao> &phieuGiao, string path)
{
    ChiTietPhieuGiaoFunction ct;
    vector<ChiTietPhieuGiao> ctPG;
    ctPG = ct.docFile("E:/Visual_C++/Buoi7_13_03/Data/chitietphieugiao.csv");
    int soChiTietPhieuGiao;
    ofstream fileOutput(path, ios::app); // Open file to append

    if (!fileOutput.is_open())
    {
        cout << "\nFailed to open this file" << endl;
        return;
    }

    string maPhieuGiao, ngayGiao, noiGiao, maKhachHang;
    cout << "Nhap ma phieu giao: ";
    cin >> maPhieuGiao;
    cout << "Nhap ngay giao: ";
    cin >> ngayGiao;
    cout << "Nhap noi giao: ";
    cin >> noiGiao;
    cout << "Nhap ma khach hang: ";
    cin >> maKhachHang;

    fileOutput << maPhieuGiao << "|" << ngayGiao << "|" << noiGiao << "|" << maKhachHang << '\n';

    PhieuGiao phieugiao = PhieuGiao(maPhieuGiao, ngayGiao, noiGiao, maKhachHang);

    cout << "Nhap so truong du lieu cho phieu giao: ";
    cin >> soChiTietPhieuGiao;
    for (int i = 1; i <= soChiTietPhieuGiao; i++)
    {
        cout << "Nhap thong tin cho chi tiet phieu giao " << i << endl;
        ct.themChiTietPG(ctPG, "E:/Visual_C++/Buoi7_13_03/Data/chitietphieugiao.csv", maPhieuGiao); // Call the function to add details
    }

    fileOutput.close();

    phieuGiao.push_back(phieugiao);

    cout << "Phieu giao va chi tiet phieu giao da duoc tao moi" << endl;
}

// Ham sua phieu giao
void PhieuGiaoFunction::suaPhieuGiao(vector<PhieuGiao> &phieuGiao, const string &codeToUpdate, const string &filePath)
{
    bool found = false;

    for (auto &phieugiao : phieuGiao)
    {
        std::string str = phieugiao.soPhieuGiao;
        str.erase(std::remove_if(str.begin(), str.end(), [](unsigned char x)
                                 { return std::isspace(x); }),
                  str.end());
        if (str == codeToUpdate)
        {
            found = true;

            // Yêu cầu người dùng nhập các thông tin mới
            cout << "Nhap thong tin moi cho phieu giao " << codeToUpdate << endl;
            cout << "Nhap ngay giao: ";
            cin >> phieugiao.ngayGiao;
            cout << "Nhap noi giao: ";
            cin >> phieugiao.noiGiao;
            cout << "Nhap ma khach hang: ";
            cin >> phieugiao.maKhachHang;
            cout << "Phieu giao " << codeToUpdate << " da duoc cap nhat." << endl;
            break;
        }
    }

    if (!found)
    {
        cout << "Khong tim thay so phieu giao " << codeToUpdate << endl;
        return;
    }

    ofstream fileOutput(filePath);
    if (!fileOutput.is_open())
    {
        cout << "Khong the mo file de ghi" << endl;
        return;
    }

    for (const auto &phieugiao : phieuGiao)
    {
        fileOutput << phieugiao.soPhieuGiao << "|" << phieugiao.ngayGiao << "|" << phieugiao.noiGiao << "|" << phieugiao.maKhachHang << endl;
    }
    fileOutput.close();
}

// Ham xoa phieu giao
// Khi xoa phieu giao thanh cong, thi toan bo chi tiet phieu giao cung bi xoa
void PhieuGiaoFunction::xoaPhieuGiao(vector<PhieuGiao> &phieuGiao, const string &codeToDelete, const string &filePath)
{
    auto it = phieuGiao.begin();
    while (it != phieuGiao.end())
    {
        std::string str = it->soPhieuGiao;
        str.erase(std::remove_if(str.begin(), str.end(), [](unsigned char x)
                                 { return std::isspace(x); }),
                  str.end());
        if (str == codeToDelete)
        {
            it = phieuGiao.erase(it);
            cout << "Da xoa phieu giao " << codeToDelete << endl;
        }
        else
        {
            ++it;
        }
    }

    if (!filePath.empty())
    {
        ofstream fileOutput(filePath);
        if (!fileOutput.is_open())
        {
            cout << "Khong the mo file de ghi" << endl;
            return;
        }

        for (const auto &phieugiao : phieuGiao)
        {
            fileOutput << phieugiao.soPhieuGiao << "|" << phieugiao.ngayGiao << "|" << phieugiao.noiGiao << "|" << phieugiao.maKhachHang << endl;
        }
        fileOutput.close();
    }
    ChiTietPhieuGiaoFunction chiTietPhieuGiaoFunction;
    string pathChiTietPhieuGiao = "E:/Visual_C++/Buoi7_13_03/Data/chitietphieugiao.csv";
    vector<ChiTietPhieuGiao> chiTietPG;
    chiTietPG = chiTietPhieuGiaoFunction.docFile(pathChiTietPhieuGiao);
    chiTietPhieuGiaoFunction.xoaChiTietPG(chiTietPG, codeToDelete, pathChiTietPhieuGiao);
}
