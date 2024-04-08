#include <bits/stdc++.h>
#include <algorithm>
#include "../functions/chitietphieugiaofunction.h"
#include <iomanip>
#include <ctime>
#include <sstream>

using namespace std;
ChiTietPhieuGiao::ChiTietPhieuGiao(std::string _soPhieuGiao, std::string _maVatTu, int _soLuongGiao, double _donGiaGiao)
    : soPhieuGiao(_soPhieuGiao), maVatTu(_maVatTu), soLuongGiao(_soLuongGiao), donGiaGiao(_donGiaGiao) {}

// Ham chinh quan ly chuc nang cua phieu giao
void ChiTietPhieuGiaoFunction::chucNangChiTietPG()
{
    int chucNang;
    string pathChiTietPhieuGiao = "E:/Visual_C++/Buoi7_13_03/Data/chitietphieugiao.csv";
    vector<ChiTietPhieuGiao> chiTietPG;
    chiTietPG = docFile(pathChiTietPhieuGiao);
    string soPG, maVatTu;
    while (true)
    {
        cout << "--------QUAN LY CHI TIET PHIEU GIAO----------" << endl;
        cout << "1. Hien thi chi tiet phieu giao" << endl;
        cout << "2. Sua chi tiet phieu giao" << endl;
        cout << "3. Thoat chuc nang chi tiet phieu giao" << endl;
        cout << "Nhap chuc nang: ";
        cin >> chucNang;

        switch (chucNang)
        {
        case 1:
            cout << "Nhap ma phieu giao: ";
            cin >> soPG;
            hienThiChiTietPG(chiTietPG, soPG);
            break;

        case 2:
            cout << "Nhap ma phieu giao: ";
            cin >> soPG;
            suaChiTietPG(chiTietPG, pathChiTietPhieuGiao, soPG, maVatTu);
            break;

        case 3:
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

// Ham them chi tiet phieu giao duoc goi ben phieu giao khi nguoi dung nhap phieu giao
void ChiTietPhieuGiaoFunction::themChiTietPG(vector<ChiTietPhieuGiao> &chiTietPhieuGiao, string path, string soPG)
{
    ofstream fileOutput(path, ios::app); // Open file to append

    if (!fileOutput.is_open())
    {
        cout << "\nFailed to open this file" << endl;
        return;
    }

    string maVatTu;
    int soLuongGiao;
    double donGiaGiao;

    cout << "Nhap ma vat tu: ";
    cin >> maVatTu;
    cout << "Nhap so luong giao: ";
    cin >> soLuongGiao;
    cout << "Nhap don gia giao: ";
    cin >> donGiaGiao;

    fileOutput << soPG << "|" << maVatTu << "|" << soLuongGiao << "|" << donGiaGiao << '\n';

    ChiTietPhieuGiao ctPG = ChiTietPhieuGiao(soPG, maVatTu, soLuongGiao, donGiaGiao);

    fileOutput.close();

    chiTietPhieuGiao.push_back(ctPG);
}

// Ham cat
vector<string> spli(const string &input, char delimiter)
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

// Ham doc file cua chi tiet phieu giao
vector<ChiTietPhieuGiao> ChiTietPhieuGiaoFunction::docFile(const string &path)
{
    vector<ChiTietPhieuGiao> chiTietPG;
    ifstream file(path);

    if (!file.is_open())
    {
        cout << "Không thể mở file " << path << endl;
        return chiTietPG;
    }

    string line;
    while (getline(file, line))
    {
        vector<string> data = spli(line, '|');
        if (data.size() == 4)
        {
            string soPhieuGiao = data[0];
            string maVatTu = data[1];
            int soLuongGiao = stoi(data[2]);
            double donGiaGiao = stoi(data[3]);

            ChiTietPhieuGiao ctphieugiao(soPhieuGiao, maVatTu, soLuongGiao, donGiaGiao);
            chiTietPG.push_back(ctphieugiao);
        }
    }

    file.close();
    return chiTietPG;
}

// Hien thi tat ca cac phieu giao theo so phieu giao duoc nhap
void ChiTietPhieuGiaoFunction::hienThiChiTietPG(vector<ChiTietPhieuGiao> &chiTietPhieuGiao, string soPhieuGiao)
{
    cout << setw(20) << left << "SoPhieuGiao"
         << setw(20) << left << "MaVatTu"
         << setw(20) << left << "SoLuongGiao"
         << setw(20) << left << "DonGia"
         << endl;
    bool find = false;
    for (const auto &ctPG : chiTietPhieuGiao)
    {
        if (ctPG.soPhieuGiao == soPhieuGiao)
        {
            cout << setw(20) << left << ctPG.soPhieuGiao
                 << setw(20) << left << ctPG.maVatTu
                 << setw(20) << left << ctPG.soLuongGiao
                 << setw(20) << left << ctPG.donGiaGiao
                 << endl;
            find = true;
        }
    }
    if (!find)
    {
        cout << "Khong tim thay phieu giao " << soPhieuGiao << endl;
    }
}

// Sua chi tiet phieu giao
// Cho phep sua cac phieu giao muon sua, neu thoat nhap 'q'
void ChiTietPhieuGiaoFunction::suaChiTietPG(vector<ChiTietPhieuGiao> &chiTietPhieuGiao, const string &filePath, string soPhieuGiao, string maVatTu)
{
    cout << setw(20) << left << "SoPhieuGiao"
         << setw(20) << left << "MaVatTu"
         << setw(20) << left << "SoLuongGiao"
         << setw(20) << left << "DonGia"
         << endl;
    bool find = false;
    for (const auto &ctPG : chiTietPhieuGiao)
    {
        if (ctPG.soPhieuGiao == soPhieuGiao)
        {
            cout << setw(20) << left << ctPG.soPhieuGiao
                 << setw(20) << left << ctPG.maVatTu
                 << setw(20) << left << ctPG.soLuongGiao
                 << setw(20) << left << ctPG.donGiaGiao
                 << endl;
            find = true;
        }
    }
    if (!find)
    {
        cout << "Khong tim thay phieu giao " << soPhieuGiao << endl;
    }

    bool tiepTucSua = true;

    while (tiepTucSua)
    {
        cout << "Nhap ma vat tu can sua hoac nhap 'q' de thoat: ";
        cin >> maVatTu;

        if (maVatTu == "q")
        {
            tiepTucSua = false;
            continue;
        }

        bool daSua = false;
        for (auto &ctPG : chiTietPhieuGiao)
        {
            if (maVatTu == ctPG.maVatTu && ctPG.soPhieuGiao == soPhieuGiao)
            {
                cout << "Nhap so luong giao moi: ";
                cin >> ctPG.soLuongGiao;
                cout << "Nhap don gia giao moi: ";
                cin >> ctPG.donGiaGiao;
                daSua = true;
            }
        }

        if (!daSua)
        {
            cout << "Khong tim thay ma vat tu trong chi tiet phieu giao." << endl;
        }

        // Ghi lại thông tin sau khi sửa vào file
        ofstream fileOutput(filePath);
        if (!fileOutput.is_open())
        {
            cout << "Khong the mo file de ghi" << endl;
            return;
        }

        for (const auto &ctPg : chiTietPhieuGiao)
        {
            fileOutput << ctPg.soPhieuGiao << "|" << ctPg.maVatTu << "|" << ctPg.soLuongGiao << "|" << ctPg.donGiaGiao << endl;
        }
        fileOutput.close();
    }
}

// Xoa chi tiet phieu giao duoc goi ben phieu giao khi dung chuc nang xoa phieu giao
// Xoa hang loat phieu giao khi nguoi dung nhap phieu giao
void ChiTietPhieuGiaoFunction::xoaChiTietPG(vector<ChiTietPhieuGiao> &chiTietPhieuGiao, const string &codeToDelete, const string filePath)
{
    auto it = chiTietPhieuGiao.begin();
    while (it != chiTietPhieuGiao.end())
    {
        std::string str = it->soPhieuGiao;
        str.erase(std::remove_if(str.begin(), str.end(), [](unsigned char x)
                                 { return std::isspace(x); }),
                  str.end());
        if (str == codeToDelete)
        {
            it = chiTietPhieuGiao.erase(it);
            cout << "Da xoa cac chi tiet phieu giao " << codeToDelete << endl;
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

        for (const auto &ctPg : chiTietPhieuGiao)
        {
            fileOutput << ctPg.soPhieuGiao << "|" << ctPg.maVatTu << "|" << ctPg.soLuongGiao << "|" << ctPg.donGiaGiao << endl;
        }
        fileOutput.close();
    }
}

// Hàm so sánh giá của hai vật phẩm
bool ChiTietPhieuGiaoFunction::comparePrice(const ChiTietPhieuGiao &a, const ChiTietPhieuGiao &b)
{
    return a.donGiaGiao > b.donGiaGiao;
}

// Hàm thống kê N vật phẩm có giá cao nhất
void ChiTietPhieuGiaoFunction::thongKeVatTuGiaCao(vector<ChiTietPhieuGiao> &chiTietPhieuGiao, int n)
{
    sort(chiTietPhieuGiao.begin(), chiTietPhieuGiao.end(), comparePrice);

    cout << "N vat tu co gia cao nhat:\n";
    for (int i = 0; i < n && i < chiTietPhieuGiao.size(); ++i)
    {
        cout << chiTietPhieuGiao[i].maVatTu << ": " << chiTietPhieuGiao[i].donGiaGiao << endl;
    }
}

// Ham thong ke tong tien cua tung PG
void ChiTietPhieuGiaoFunction::thongKeTongTien(vector<ChiTietPhieuGiao> &chiTietPhieuGiao, string soPhieuGiao)
{
    double tongTien = 0;
    bool found = false;
    cout << "----------------------CHI TIET PHIEU GIAO----------------------" << endl
         << setw(20) << left << "SoPhieuGiao"
         << setw(20) << left << "MaVatTu"
         << setw(20) << left << "SoLuongGiao"
         << setw(20) << left << "DonGia"
         << endl;
    for (auto &ctPG : chiTietPhieuGiao)
    {
        if (soPhieuGiao == ctPG.soPhieuGiao)
        {
            cout << setw(20) << left << ctPG.soPhieuGiao
                 << setw(20) << left << ctPG.maVatTu
                 << setw(20) << left << ctPG.soLuongGiao
                 << setw(20) << left << ctPG.donGiaGiao
                 << endl;
            tongTien += ctPG.donGiaGiao * ctPG.soLuongGiao;
            found = true;
        }
    }
    cout << "Tong tien cua phieu giao " << soPhieuGiao << ": " << tongTien << endl;

    if (!found)
    {
        cout << "Khong tim thay so phieu giao " << soPhieuGiao << " trong chi tiet phieu giao." << endl;
    }
}

// Ham nhap thoi gian de tinh toan
void ChiTietPhieuGiaoFunction::nhapThoiGian(time_t &thoiGianBatDau, time_t &thoiGianKetThuc)
{
    cout << "Nhap thoi gian bat dau (yyyy-MM-dd): ";
    string strBatDau;
    getline(cin, strBatDau);
    struct tm tmBatDau = {};
    istringstream ssBatDau(strBatDau);
    ssBatDau >> get_time(&tmBatDau, "%Y-%m-%d");
    thoiGianBatDau = mktime(&tmBatDau);

    // Xóa bộ nhớ đệm của luồng nhập
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Nhap thoi gian ket thuc (yyyy-MM-dd): ";
    string strKetThuc;
    getline(cin, strKetThuc);
    struct tm tmKetThuc = {};
    istringstream ssKetThuc(strKetThuc);
    ssKetThuc >> get_time(&tmKetThuc, "%Y-%m-%d");
    thoiGianKetThuc = mktime(&tmKetThuc);
}

// Ham thong ke phieu giao trong mot khoang thoi gian nhat dinh
// Se hien thi gom cac thong tin nhu phieu giao, ngay giao, noi giao va tong don
void ChiTietPhieuGiaoFunction::thongKePhieuGiaoTrongKhoangThoiGian(vector<PhieuGiao> &dsPhieuGiao, vector<ChiTietPhieuGiao> &ctPG, time_t thoiGianBatDau, time_t thoiGianKetThuc)
{
    cout << "----------------------CHI TIET PHIEU GIAO----------------------" << endl
         << setw(20) << left << "SoPhieuGiao"
         << setw(20) << left << "NgayGiao"
         << setw(20) << left << "NoiGiao"
         << setw(20) << left << "TongDon"
         << endl;
    bool found = false;
    for (const auto &phieu : dsPhieuGiao)
    {
        struct tm tmNgayGiao = {};
        istringstream ssNgayGiao(phieu.ngayGiao);
        ssNgayGiao >> get_time(&tmNgayGiao, "%Y-%m-%d");
        time_t thoiGianNgayGiao = mktime(&tmNgayGiao);
        if (thoiGianNgayGiao >= thoiGianBatDau && thoiGianNgayGiao <= thoiGianKetThuc)
        {
            double tongTienPhieuPG = 0.0;
            found = true;
            for (const auto &ctpg : ctPG)
            {
                if (ctpg.soPhieuGiao == phieu.soPhieuGiao)
                {
                    tongTienPhieuPG += ctpg.donGiaGiao * ctpg.soLuongGiao;
                }
            }
            cout << setw(20) << left << phieu.soPhieuGiao
                 << setw(20) << left << phieu.ngayGiao
                 << setw(20) << left << phieu.noiGiao
                 << setw(20) << left << tongTienPhieuPG
                 << endl;
        }
    }
    if (!found)
    {
        cout << "Khong co phieu giao nao trong khoang thoi gian tren !" << endl;
    }
}

// Ham thong ke N vat tu ban nhieu nhat
void ChiTietPhieuGiaoFunction::thongKeVatTu(const vector<ChiTietPhieuGiao> &ctPG, int n)
{
    unordered_map<string, int> freqMap;
    for (const ChiTietPhieuGiao &item : ctPG)
    {
        string tenVatTu = item.maVatTu;
        freqMap[tenVatTu]++;
    }

    // Chuyển dữ liệu từ map sang vector<pair> để sắp xếp
    vector<pair<string, int>> freqVec(freqMap.begin(), freqMap.end());

    // Sắp xếp các cặp theo thứ tự giảm dần của số lần xuất hiện
    sort(freqVec.begin(), freqVec.end(), [](const auto &a, const auto &b)
         { return a.second > b.second; });

    // Lấy N vật tư đầu tiên sau khi đã sắp xếp
    vector<pair<string, int>> topNVatTu;
    for (int i = 0; i < n && i < freqVec.size(); ++i)
    {
        topNVatTu.push_back(freqVec[i]);
    }

    cout << "----------TOP VAT TU BAN NHIEU----------" << endl
         << setw(20) << left << "MaVatTu"
         << setw(20) << left << "DaBan"
         << endl;

    for (const auto &vatTu : topNVatTu)
    {
        cout << setw(20) << left << vatTu.first
             << setw(20) << left << vatTu.second
             << endl;
    }
}

// Ham thong ke doanh so trong khoang thoi gian nhat dinh
void ChiTietPhieuGiaoFunction::thongKeTongTien(vector<PhieuGiao> &dsPhieuGiao, vector<ChiTietPhieuGiao> &ctPG, time_t thoiGianBatDau, time_t thoiGianKetThuc)
{
    double tongTienTatCaPG = 0.0;
    bool found = false;
    for (const auto &phieu : dsPhieuGiao)
    {
        struct tm tmNgayGiao = {};
        istringstream ssNgayGiao(phieu.ngayGiao);
        ssNgayGiao >> get_time(&tmNgayGiao, "%Y-%m-%d");
        time_t thoiGianNgayGiao = mktime(&tmNgayGiao);

        if (thoiGianNgayGiao >= thoiGianBatDau && thoiGianNgayGiao <= thoiGianKetThuc)
        {
            double tongTienPhieuPG = 0.0;
            found = true;
            for (const auto &ctpg : ctPG)
            {
                if (ctpg.soPhieuGiao == phieu.soPhieuGiao)
                {
                    tongTienPhieuPG += ctpg.donGiaGiao * ctpg.soLuongGiao;
                }
            }

            tongTienTatCaPG += tongTienPhieuPG;
        }
    }

    if (!found)
    {
        cout << "Khong co phieu giao nao trong khoang thoi gian tren !" << endl;
    }

    cout << setw(20) << left << "TONG DOANH THU: " << tongTienTatCaPG << endl;
}
