#include <bits/stdc++.h>
#include "../models/chitietphieugiao.h"
#include "../models/phieugiao.h"

class ChiTietPhieuGiaoFunction
{
public:
    void chucNangChiTietPG();
    vector<ChiTietPhieuGiao> docFile(const string &path);
    void themChiTietPG(vector<ChiTietPhieuGiao> &chiTietPhieuGiao, string path, string soPG);
    void hienThiChiTietPG(vector<ChiTietPhieuGiao> &chiTietPhieuGiao, string soPhieuGiao);
    void suaChiTietPG(vector<ChiTietPhieuGiao> &chiTietPhieuGiao, const string &filePath, string soPhieuGiao, string maVatTu);
    void xoaChiTietPG(vector<ChiTietPhieuGiao> &chiTietPhieuGiao, const string &codeToDelete, const string filePath);

    static bool comparePrice(const ChiTietPhieuGiao &a, const ChiTietPhieuGiao &b);
    void thongKeVatTuGiaCao(vector<ChiTietPhieuGiao> &chiTietPhieuGiao, int n);
    void thongKeTongTien(vector<ChiTietPhieuGiao> &chiTietPhieuGiao, string soPhieuGiao);

    static void nhapThoiGian(time_t &thoiGianBatDau, time_t &thoiGianKetThuc);
    static void thongKePhieuGiaoTrongKhoangThoiGian(vector<PhieuGiao> &dsPhieuGiao, vector<ChiTietPhieuGiao> &ctPG, time_t thoiGianBatDau, time_t thoiGianKetThuc);

    // Thống kê N vật tư bán nhiều nhất
    void thongKeVatTu(const vector<ChiTietPhieuGiao> &ctPG, int n);

    // Thống kê tổng tiền của tất cả các phiếu giao trong khoảng thời gian nhất định
    void thongKeTongTien(vector<PhieuGiao> &dsPhieuGiao, vector<ChiTietPhieuGiao> &ctPG, time_t thoiGianBatDau, time_t thoiGianKetThuc);

    // Sao lưu dữ liệu

    // Phục hồi dữ liệu
};