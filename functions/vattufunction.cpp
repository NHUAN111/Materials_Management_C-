#include <bits/stdc++.h>
#include "vattufuction.h"

using namespace std;

// Định nghĩa constructor của lớp VatTu
VatTu::VatTu(std::string _maVatTu, std::string _tenVatTu, std::string _donViTinh)
    : maVatTu(_maVatTu), tenVatTu(_tenVatTu), donViTinh(_donViTinh) {}

// Ham toan bo chuc nang vat tu
void VatTuFunction::chucNangVatTu()
{
    int chucNang;
    string pathVatTu = "E:/Visual_C++/Buoi7_13_03/Data/vattu.csv";
    string codeVatTu;
    vector<VatTu> vatTu;
    vatTu = docFile(pathVatTu);
    while (true)
    {
        cout << "--------QUAN LY VAT TU----------" << endl;
        cout << "1. Hien thi vat tu" << endl;
        cout << "2. Them vat tu" << endl;
        cout << "3. Sua vat tu" << endl;
        cout << "4. Xoa vat tu" << endl;
        cout << "5. Thoat chuc nang vat tu" << endl;
        cout << "Nhap chuc nang: ";
        cin >> chucNang;

        switch (chucNang)
        {
        case 1:
            hienThiTatCaVatTu(vatTu);
            break;

        case 2:
            themVatTu(vatTu, pathVatTu);
            break;

        case 3:
            cout << "Nhap ma van tu can sua: ";
            cin >> codeVatTu;
            suaVatTu(vatTu, codeVatTu, pathVatTu);
            break;

        case 4:
            cout << "Nhap ma van tu can xoa: ";
            cin >> codeVatTu;
            xoaVatTu(vatTu, codeVatTu, pathVatTu);
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

// Ham cat
vector<string> splits(const string &input, char delimiter)
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

// Ham doc file vat tu
vector<VatTu> VatTuFunction::docFile(const string &path)
{
    vector<VatTu> vatTu;
    ifstream file(path);

    if (!file.is_open())
    {
        cout << "Không thể mở file " << path << endl;
        return vatTu;
    }

    string line;
    while (getline(file, line))
    {
        vector<string> data = splits(line, '|');
        if (data.size() == 3)
        {
            string maVatTu = data[0];
            string tenVatTu = data[1];
            string donViTinh = data[2];

            VatTu vattu(maVatTu, tenVatTu, donViTinh);
            vatTu.push_back(vattu);
        }
    }

    file.close();
    return vatTu;
}

// Ham hien thi tat ca du lieu trong file vat tu
void VatTuFunction::hienThiTatCaVatTu(vector<VatTu> &VatTu)
{
    // In tiêu đề
    cout << setw(10) << left << "MaVatTu"
         << setw(20) << left << "TenVatTu"
         << setw(10) << left << "DonViTinh" << endl;

    // In thông tin các vật tư
    for (const auto &vattu : VatTu)
    {
        cout << setw(10) << left << vattu.maVatTu
             << setw(20) << left << vattu.tenVatTu
             << setw(10) << left << vattu.donViTinh << endl;
    }
}

// Ham them vat tu
void VatTuFunction::themVatTu(vector<VatTu> &vatTu, string path)
{
    ofstream fileOutput(path, ios::app); // Mở file để ghi vào cuối file

    if (!fileOutput.is_open())
    {
        cout << "\nFailed to open this file" << endl;
        return;
    }

    string maVatTu, tenVatTu, donViTinh;
    cout << "Nhap ma vat tu: ";
    cin >> maVatTu;
    cout << "Nhap ten vat tu: ";
    cin >> tenVatTu;
    cout << "Nhap don vi tinh: ";
    cin >> donViTinh;

    fileOutput << maVatTu << "|" << tenVatTu << "|" << donViTinh << '\n';

    VatTu vattu = VatTu(maVatTu, tenVatTu, donViTinh);

    fileOutput.close();

    vatTu.push_back(vattu);

    cout << "Vat tu da duoc tao moi" << endl;
}

// Ham sua vat tu
void VatTuFunction::suaVatTu(vector<VatTu> &vatTu, const string &codeToUpdate, const string &filePath)
{
    bool found = false;

    for (auto &vattu : vatTu)
    {
        std::string str = vattu.maVatTu;
        str.erase(std::remove_if(str.begin(), str.end(), [](unsigned char x)
                                 { return std::isspace(x); }),
                  str.end());
        if (str == codeToUpdate)
        {
            found = true;

            // Yêu cầu người dùng nhập các thông tin mới
            cout << "Nhap thong tin moi cho ma vat tu " << codeToUpdate << endl;
            cout << "Nhap ma vat tu: ";
            cin >> vattu.maVatTu;
            cout << "Nhap ten vat tu: ";
            cin >> vattu.tenVatTu;
            cout << "Nhap don vi tinh: ";
            cin >> vattu.donViTinh;
            cout << "Vat tu da duoc cap nhat." << endl;
            break;
        }
    }

    if (!found)
    {
        cout << "Khong tim thay vat tu " << codeToUpdate << endl;
        return;
    }

    ofstream fileOutput(filePath);
    if (!fileOutput.is_open())
    {
        cout << "Khong the mo file de ghi" << endl;
        return;
    }

    for (const auto &vattu : vatTu)
    {
        fileOutput << vattu.maVatTu << "|" << vattu.tenVatTu << "|" << vattu.donViTinh << endl;
    }
    fileOutput.close();
}

// Ham xoa vat tu theo ten
void VatTuFunction::xoaVatTu(vector<VatTu> &vatTu, const string &codeToDelete, const string &filePath)
{
    auto it = vatTu.begin();
    while (it != vatTu.end())
    {
        std::string str = it->maVatTu;
        str.erase(std::remove_if(str.begin(), str.end(), [](unsigned char x)
                                 { return std::isspace(x); }),
                  str.end());
        if (str == codeToDelete)
        {
            it = vatTu.erase(it);
            cout << "Da xoa vat tu " << codeToDelete << endl;
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

        for (const auto &vattu : vatTu)
        {
            fileOutput << vattu.maVatTu << "|" << vattu.tenVatTu << "|" << vattu.donViTinh << endl;
            fileOutput.close();
        }
    }
}
