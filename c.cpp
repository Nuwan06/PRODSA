#include <iostream>
#include<fstream>
#include <sstream>
#include <string>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include <conio.h>
// #include "D:/mylib.h" // Đã comment vì không có file này
using namespace std;

const int MAX_NHANVIEN = 500; // số nhân viên tối đa
const int MAX_VATTU = 1000; // số vật tư tối đa
const int SO_MUC_MENU = 8; // số mục trong menu

// tọa độ menu
const int DONG_BAT_DAU_MENU = 9; // dòng bắt đầu menu
const int COT_BAT_DAU_MENU = 10; // cột bắt đầu menu

// Mã phím đặc biệt
const int Left = 75;
const int Right = 77;
const int Up = 72; // Extended code 
const int Down = 80;
const int F1 = 59;
const int F2 = 60;
const int F3 = 61;
const int ESC = 27;
const int A = 65;
const int D = 68;

string menuchinh[SO_MUC_MENU] = {
    "1. In danh sách vật tư theo mã số        ",
    "2. In danh sách vật tư theo tên          ", 
    "3. In danh sách nhân viên theo tên       ",
    "4. Lập hóa đơn      ",
    "5. Thống kê hóa đơn theo ngày tháng    ",
    "6. Thống kê Top 10 vật tư có giá cao nhất     ",
    "7. Thống kê doanh thu của từng tháng theo năm       ",
    "8. Kết thúc chương trình             "
};

string menuNhapVatTu[6] = {
    "1. Nhập mã vật tư(VD: VT0099):",
    "2. Nhập tên vật tư:",
    "3. Nhập đơn vị tính:",
    "4. Nhập số lượng tồn(0-9):",
    " Hủy ",
    " Xác nhận "
};

string menuXoaVatTu[3] = {
    "Nhập mã vật tư(VD: VT0099):",
    " Hủy ",
    " Xác nhận "
};

string menuSuaVatTu[5] = {
    "Nhập mã vật tư(VD: VT0099):",
    "                         ",
    "",
    " Hủy ",
    " Xác nhận "
};

string menuLapHoaDon[5] = {
    "1. Số hóa đơn:", 
    "2. Ngày lập hóa đơn:",
    "3. Loại hóa đơn:",
    " Hủy ", 
    " Xác nhận "
};

string menuChiTietHoaDon[6] = {
    "1. Nhập mã vật tư(VD: VT0099):",
    "2. Nhập số lượng:", 
    "3. Nhập đơn giá:",
    "4. Nhập VAT:",
    " Hủy ", 
    " Xác nhận "
};

string menuNhapHoaDon[5] = {
    "1. Mã hóa đơn:",
    "2. Ngày tháng năm:", 
    "3. Nhập loại:",
    " Hủy ", 
    " Xác nhận "
};

string menuNhapMaHoaDon[3] = {
    "1. Mã hóa đơn:",
    " Hủy ", 
    " Xác nhận "
};

string menuNgayThang[4] = {
    "1. Từ ngày:", 
    "2. Đến ngày:",  
    " Hủy ", 
    " Xác nhận "
};

string menuNam[3] = {
    "1. Nhập năm:",  
    " Hủy ", 
    " Xác nhận "
};

string menuXoaNhanVien[3] = {
    "1. Nhập mã nhân viên(VD: NV099):",
    " Hủy ", 
    " Xác nhận "
};

string menuSuaNhanVien[6] = { // Sửa từ 3 lên 6
    "1. Nhập mã nhân viên (VD: NV099):",
    "2. Sửa họ nhân viên:", 
    "3. sửa tên nhân viên:",
    "4. Sửa giới tính nhân viên (VD: Nam/Nữ):",
    " Hủy ",
    " Xác nhận "
};

// ========== CÁC HÀM CONSOLE ==========
void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void SetColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void SetBGColor(int color) {
    SetColor(color);
}

void Normal() {
    SetColor(15); // white 
    SetBGColor(0);// black
}

void HighLight() {
    SetColor(15);
    SetBGColor(1); // blue
}

// ========== CÁC HÀM VẼ KHUNG ==========
void VeKhungBaoQuanh() {
    SetColor(9);    //30 170
    gotoxy(7,3);
    cout<< "╔";    
    for(int i = 0; i <85; i++) {
        cout << "═";
    }
    cout << "╗";
    for(int i = 0; i < 25; i++) {
        gotoxy(7,i+3+1);
        cout << "║"; gotoxy(93,i+3+1);
         cout <<"║"; 
    }
    gotoxy(7,28);
    cout<<"╚";
    for(int i = 0; i <85; i++) {
        cout << "═";
    }
    cout << "╝";
}

void VeGhiChuMenu() {
    gotoxy(8, 7);
    for(int i = 0; i <85; i++) {
        cout << "═";
    }
    SetColor(15);
    SetBGColor(9);
    gotoxy(35,5);
    cout <<"     QUẢN LÝ VẬT TƯ     ";
    Normal();
    gotoxy(75,10);
    cout<<"⭡";
    gotoxy(71, 12);
    cout<<"⭠      ⭢";
    gotoxy(75, 14);
    cout<<"⭣";
    gotoxy(70,16); cout<<"Up: LÊN";
    gotoxy(70,17); cout<<"Down: XUỐNG";
    gotoxy(70,18); cout<<"Left: TRÁI";
    gotoxy(70,19); cout<<"Right: PHẢI";
    gotoxy(70,20); cout<<"Enter: ĐỂ CHỌN";
}

void VeKhungDanhSach() {
    VeKhungBaoQuanh();
    SetColor(9);
    gotoxy(15, 4); cout<<"║";
    gotoxy(38, 4); cout<<"║";
    gotoxy(61, 4);cout<<"║";
    Normal();
    gotoxy(8,4); cout<<" MãVT";
    gotoxy(17, 4); cout<<" Tên vật tư";
    gotoxy(40, 4);cout<<" Đơn vị tính";
    gotoxy(63, 4); cout<< " Số lượng tồn";
    SetColor(9);
    gotoxy(8, 5); 
    for(int i = 0; i <85; i++) {
        cout <<"═"; 
    }

    for(int i = 0 ; i < 22; i++) {
        gotoxy(15, 4+i+1); cout<<"║"; 
        gotoxy(38, 4+i+1); cout<<"║"; 
        gotoxy(61, 4+i+1);cout<<"║"; 
    }
    gotoxy(8, 26);
    for(int i = 0; i < 85; i++) {
        cout<<"═";
    }
    gotoxy(82, 2); 
    HighLight();
    cout<<" Trang: ";
    Normal();
}

void VeKhungChiTietHoaDon() {
    VeKhungBaoQuanh();
    SetColor(9);
    gotoxy(15, 4); cout<<"║";
    gotoxy(41, 4); cout<<"║";
    gotoxy(63, 4);cout<<"║";
    gotoxy(79, 4);cout<<"║";
    Normal();
    gotoxy(8,4); cout<<"Mã VT";
    gotoxy(17, 4); cout<<"Tên vật tư";
    gotoxy(44, 4); cout<<"Đơn giá VNĐ";
    gotoxy(65, 4);cout<<"Số lượng";
    gotoxy(81, 4); cout<< "VAT";
    SetColor(9);
    gotoxy(8, 5); 
    for(int i = 0; i <85; i++) {
        cout <<"═"; 
    }
    
    for(int i = 0 ; i < 22; i++) {
        gotoxy(15, 4+i+1); cout<<"║"; 
        gotoxy(41, 4+i+1); cout<<"║"; 
        gotoxy(63, 4+i+1); cout<<"║";
        gotoxy(79, 4+i+1); cout<<"║"; 
    }
    gotoxy(8, 26);
    for(int i = 0; i < 85; i++) {
        cout<<"═";
    }
    gotoxy(82, 2); 
    HighLight();
    cout<<" Trang: ";
    Normal();
}

void VeKhungThongKeHoaDon() {
    VeKhungBaoQuanh();
    SetColor(9);
    gotoxy(22, 4); cout<<"║";
    gotoxy(35, 4); cout<<"║";
    gotoxy(50, 4);cout<<"║";
    gotoxy(70, 4);cout<<"║";
    Normal();
    gotoxy(8,4); cout<<" Mã HĐ";
    gotoxy(24, 4); cout<<" Loại";
    gotoxy(37, 4);cout<<" Ngày tháng";
    gotoxy(52,4); cout<<" Tên nhân viên";
    gotoxy(72, 4); cout<< " Trị giá hóa đơn";
    SetColor(9);
    gotoxy(8, 5); 
    for(int i = 0; i <85; i++) {
        cout <<"═"; 
    }

    for(int i = 0 ; i < 22; i++) {
        gotoxy(22, 4+i+1); cout<<"║"; 
        gotoxy(35, 4+i+1); cout<<"║"; 
        gotoxy(50, 4+i+1);cout<<"║"; 
        gotoxy(70, 4+i+1);cout<<"║";
    }
    gotoxy(8, 26);
    for(int i = 0; i < 85; i++) {
        cout<<"═";
    }
    gotoxy(82, 2); 
    HighLight();
    cout<<" Trang: ";
    Normal();
}

void VeKhungTop10VatTu() {
   VeKhungBaoQuanh();
    SetColor(9);
    gotoxy(30, 4); cout<<"║"; gotoxy(60, 4); cout<<"║";
    Normal();
    gotoxy(12,4); cout<<" Mã vật tư";
    gotoxy(34, 4); cout<<"Tên vật tư";
    gotoxy(63, 4); cout<<" Tổng doanh thu của vật tư";
    SetColor(9);
    gotoxy(8, 5); 
    for(int i = 0; i <85; i++) {
        cout <<"═"; 
    }

    for(int i = 0 ; i < 22; i++) { 
        gotoxy(30, 4+i+1); cout<<"║"; 
        gotoxy(60, 4+i+1); cout<<"║"; 
    }
    gotoxy(8, 26);
    for(int i = 0; i < 85; i++) {
        cout<<"═";
    }
    gotoxy(82, 2); 
    HighLight();
    cout<<" Trang: ";
    Normal();
}

void VeKhungDoanhThuThang() {
   VeKhungBaoQuanh();
    SetColor(9);
    gotoxy(38, 4); cout<<"║";
    Normal();
    gotoxy(15,4); cout<<" Tháng ";
    gotoxy(45, 4); cout<<" Doanh thu";
    SetColor(9);
    gotoxy(8, 5); 
    for(int i = 0; i <85; i++) {
        cout <<"═"; 
    }

    for(int i = 0 ; i < 22; i++) { 
        gotoxy(38, 4+i+1); cout<<"║"; 
    }
    gotoxy(8, 26);
    for(int i = 0; i < 85; i++) {
        cout<<"═";
    }
    gotoxy(82, 2); 
    HighLight();
    cout<<" Trang: ";
    Normal();
}

void VeKhungDanhSachHoaDon() {
    VeKhungBaoQuanh(); // Sửa từ taokhung()
    SetColor(9);
    gotoxy(25, 4); cout<<"║";
    gotoxy(54, 4);cout<<"║";
    Normal();
    gotoxy(8,4); cout<<" Mã Hóa Đơn";
    gotoxy(27, 4); cout<<" Loại hóa đơn ";
    gotoxy(56, 4); cout<< " Ngày tháng lập hóa đơn ";
    SetColor(9);
    gotoxy(8, 5); 
    for(int i = 0; i <85; i++) {
        cout <<"═"; 
    }

    for(int i = 0 ; i < 22; i++) {
        gotoxy(25, 4+i+1); cout<<"║"; 
        gotoxy(54, 4+i+1); cout<<"║"; 
    }
    gotoxy(8, 26);
    for(int i = 0; i < 85; i++) {
        cout<<"═";
    }
    gotoxy(82, 2); 
    HighLight();
    cout<<" Trang: ";
    Normal();
}

void VeKhungDanhSachNhanVien() {
    VeKhungBaoQuanh();
    SetColor(9);
    gotoxy(15, 4); cout<<"║";
    gotoxy(38, 4); cout<<"║";
    gotoxy(61, 4);cout<<"║";
    Normal();
    gotoxy(8,4); cout<<" MãNV";
    gotoxy(17, 4);cout<<" Họ nhân viên";
    gotoxy(40, 4); cout<<" Tên nhân viên"; 
    gotoxy(63, 4); cout<< " Giới tính      ";
    SetColor(9);
    gotoxy(8, 5); 
    for(int i = 0; i <85; i++) {
        cout <<"═"; 
    }

    for(int i = 0 ; i < 22; i++) {
        gotoxy(15, 4+i+1); cout<<"║"; 
        gotoxy(38, 4+i+1); cout<<"║"; 
        gotoxy(61, 4+i+1);cout<<"║"; 
    }
    gotoxy(8, 26);
    for(int i = 0; i < 85; i++) {
        cout<<"═";
    }
    gotoxy(82, 2); 
    HighLight();
    cout<<" Trang: ";
    Normal();
}

// ========== CÁC HÀM TIÊU ĐỀ ==========
void VeTieuDeDanhSachVatTu() {
    HighLight();
    gotoxy(40,1); cout<<"   DANH SÁCH VẬT TƯ   ";
    Normal();
    gotoxy(9, 27); cout<<"F1: Thêm VT    F2: Xóa VT    F3: Chỉnh sửa VT    ⭡: Len    ⭣: Xuong    ESC: Để thoát";
}

void VeTieuDeChiTietHoaDon() {
    HighLight();
    gotoxy(40,1); cout<<"  CHI TIẾT HÓA ĐƠN  ";
    Normal();
    gotoxy(9, 27); cout<<"  ⭡: Len    ⭣: Xuong    ESC: Để thoát";
}

void VeTieuDeThongKeHoaDon() {
    HighLight();
    gotoxy(40,1); cout<<"  THỐNG KÊ HÓA ĐƠN  ";
    Normal();
    gotoxy(9, 27); cout<<"  ⭡: Len    ⭣: Xuong    ESC: Để thoát";
}

void VeTieuDeTop10VatTu() {
    HighLight();
    gotoxy(37,1); cout<<"  THỐNG KÊ TOP 10 VẬT TƯ CÓ DOANH THU CAO NHẤT   ";
    Normal();
    gotoxy(9, 27); cout<<"  ⭡: Len    ⭣: Xuong    ESC: Để thoát";
}

void VeTieuDeDoanhThuThang() {
    HighLight();
    gotoxy(40,1); cout<<"  BẢNG THỐNG KÊ DOANH THU NĂM:      ";
    Normal();
    gotoxy(9, 27); cout<<"  ⭡: Len    ⭣: Xuong    ESC: Để thoát";
}

void VeTieuDeDanhSachNhanVien() {
    HighLight();
    gotoxy(40,1); cout<<"   DANH SÁCH NHÂN VIÊN   ";
    Normal();
    gotoxy(9, 27); cout<<"F1: Thêm NV    F2: Xóa NV    F3: Chỉnh sửa NV    ⭡: Len    ⭣: Xuong    ESC: Để thoát";
}

void VeTieuDeDanhSachHoaDonCase4() {
    HighLight();
    gotoxy(40,1); cout<<"   DANH SÁCH HÓA ĐƠN   ";
    Normal();
    gotoxy(9, 27); cout<<"F1: Lập hóa đơn    F2: Xem chi tiết hóa đơn    ⭡: Len    ⭣: Xuong    ESC: Để thoát";
}

void VeTieuDeSapXepTheoTen() {
     HighLight();
    gotoxy(40,1); cout<<"   DANH SÁCH VẬT TƯ SẮP XẾP THEO TÊN   ";
    Normal();
    gotoxy(9, 27); cout<<"⭡: Len    ⭣: Xuong    ESC: Để thoát";
}

void XoaKhungNhap() {
    for(int i = 0 ;i < 14;i++) {
        gotoxy(17,7+i);
        for(int j = 0; j < 68;j++){
            cout<<" ";
        }
    }
}

void VeKhungNhap() {
    for(int i = 0 ;i < 14;i++) {
        gotoxy(17,7+i);
        for(int j = 0; j < 68;j++){
            cout<<" ";
        }
    } 
    gotoxy(17,7);
    cout<<"╔";
    for(int i = 0; i < 68; i++){
        cout<<"═";
    }
    cout << "╗";
    gotoxy(18,9);
    for(int i = 0; i < 68; i++){
        cout<<"═";
    }
    for(int i = 0; i < 12; i++) {
        gotoxy(17,i+7+1);
        cout << "║"; gotoxy(86,i+7+1);
         cout <<"║"; 
    }
    gotoxy(18,18);
    for(int i = 0; i < 68; i++){
        cout<<"═";
    }
    gotoxy(17,20);
    cout<<"╚";
    for(int i = 0; i < 68; i++) {
        cout << "═";
    }
    cout << "╝";
}

int HienThiMenuChinh(string menuItems[SO_MUC_MENU]){
    Normal();
    system("cls");
    int viTriChon = 0;
    for (int i = 0; i < SO_MUC_MENU ; i++) {
        gotoxy(COT_BAT_DAU_MENU, DONG_BAT_DAU_MENU + i);
        cout << menuItems[i];
    }
    VeKhungBaoQuanh();
    VeGhiChuMenu();
    HighLight();
    gotoxy(COT_BAT_DAU_MENU, DONG_BAT_DAU_MENU + viTriChon);
    cout << menuItems[viTriChon];
    char kytu;
    do {
        kytu = getch();
        if (kytu == 0) kytu = getch();
        switch (kytu) {
            case Up:
                if (viTriChon > 0) {
                    Normal();
                    gotoxy(COT_BAT_DAU_MENU, DONG_BAT_DAU_MENU + viTriChon);
                    cout << menuItems[viTriChon];
                    viTriChon--;
                    HighLight();
                    gotoxy(COT_BAT_DAU_MENU, DONG_BAT_DAU_MENU + viTriChon);
                    cout << menuItems[viTriChon];
                }
                break;
            case Down:
                if (viTriChon < SO_MUC_MENU - 1) {
                    Normal();
                    gotoxy(COT_BAT_DAU_MENU, DONG_BAT_DAU_MENU + viTriChon);
                    cout << menuItems[viTriChon];
                    viTriChon++;
                    HighLight();
                    gotoxy(COT_BAT_DAU_MENU, DONG_BAT_DAU_MENU + viTriChon);
                    cout << menuItems[viTriChon];
                }
                break;
            case 13: // Enter
                return viTriChon + 1;
        }
    } while (1);
}

void VeKhungXacNhan() {
    for(int i = 0; i < 6; i++) {
        gotoxy(35,12+i);
        for (int j = 0; j < 35; j++) {
            cout<<" ";
        }
    }
    gotoxy(35,12); 
    cout<< "╔";    
    for(int i = 0; i <30; i++) {
        cout << "═";
    }
    cout << "╗";

    for(int i = 0; i < 4; i++) {
        gotoxy(35,i+12+1);
        cout << "║"; gotoxy(66,i+12+1);
         cout <<"║"; 
    }
    gotoxy(35,17);
    cout<<"╚";
    for(int i = 0; i <30; i++) {
        cout << "═";
    }
    cout << "╝"; 
}

void BaoLoi(string s1, string s2, string s3) {
    VeKhungXacNhan();
    gotoxy(37,14); cout<< s1;
    gotoxy(37,15); cout<< s2;
    gotoxy(37,16); cout<< s3;
    Sleep(1500);
    for(int i = 0; i < 6; i++) {
        gotoxy(35,12+i);
        for (int j = 0; j < 35; j++) {
            cout<<" ";
        }
    }
}

int XacNhanLuaChon() {
    VeKhungXacNhan();
    gotoxy(36,13); cout<<"Bạn có muốn xác nhận lựa chọn";
    gotoxy(36,14);
    for(int i = 0; i <30; i++) {
        cout << "═";
    }
    gotoxy(37,16); 
    string s = "  Hủy  "; 
    string s2 = "  Xác Nhận  ";
    cout<< s<<"        "; 
    HighLight(); 
    cout<< s2;
    Normal();
    int chon = 0; // Sửa từ 1 thành 0 (bắt đầu từ Hủy)
    do { 
        char luachon = getch();
        if (luachon == 0) luachon = getch();
        switch(luachon) {
            case Left:
                if (chon > 0) {
                    Normal();
                    gotoxy(37 + (chon == 1 ? 15 : 0), 16);
                    cout << (chon == 1 ? s2 : s);
                    chon--;
                    HighLight();
                    gotoxy(37 + (chon == 0 ? 0 : 15), 16);
                    cout << (chon == 0 ? s : s2);
                }
                break;
            case Right:
                if (chon < 1) {
                    Normal();
                    gotoxy(37 + (chon == 0 ? 0 : 15), 16);
                    cout << (chon == 0 ? s : s2);
                    chon++;
                    HighLight();
                    gotoxy(37 + (chon == 0 ? 0 : 15), 16);
                    cout << (chon == 0 ? s : s2);
                }
                break;
            case 13: // Enter
                return chon; // 0: Hủy, 1: Xác nhận
        }
    } while(true);
}

// ========== CLASS XỬ LÝ NHẬP LIỆU ==========
class XuLyNhapLieu {
public:
    struct Date {
        int day = 0;
        int month = 0;
        int year = 0;
    };
    
    static char toUpper(char c) {
        if (c >= 'a' && c <= 'z')
            return c - 32;
        return c;
    }

    static bool chuanHoaMAVT(string& input) {
        for (int i = 0; i < input.length(); i++)
            input[i] = toUpper(input[i]);

        if (input.length() < 2 || input[0] != 'V' || input[1] != 'T') {
            BaoLoi("Mã vật tư phải bắt đầu bằng","VT.","");
            return false;
        }

        string so = "";
        for (int i = 2; i < input.length(); i++) {
            if (input[i] >= '0' && input[i] <= '9')
                so += input[i];
            else {
                BaoLoi("Mã vật tư chỉ được chứa ","số sau VT.","");
                return false;
            }
        }

        if (so.length() == 0) {
            BaoLoi("Chưa nhập số cho mã vật tư.","","");
            return false;
        }

        int num = 0;
        for (int i = 0; i < so.length(); i++)
            num = num * 10 + (so[i] - '0');

        if (num < 1 || num > 9999) {
            BaoLoi("mã vật tư chỉ từ VT0001 ", "đến VT9999.","");
            return false;
        }

        string result = "VT";
        if (num < 10) result += "000";
        else if (num < 100) result += "00";
        else if (num < 1000) result += "0";
        result += to_string(num);

        input = result;
        return true;
    }

    static bool chuanHoaMaNV(string &maNV) {
        for (int i = 0; i < maNV.length(); i++) {
            if (maNV[i] >= 'a' && maNV[i] <= 'z')
                maNV[i] -= 32;
        }

        if (maNV.length() != 5) {
            BaoLoi("Loi: Ma nhan vien phai co"," dang NVxxx (VD: NV001)","");
            return false;
        }

        if (maNV[0] != 'N' || maNV[1] != 'V') {
            BaoLoi("Loi: Ma nhan vien phai ","bat dau bang NV","");
            return false;
        }

        for (int i = 2; i < 5; i++) {
            if (maNV[i] < '0' || maNV[i] > '9') {
                BaoLoi("Loi: 3 ky tu sau NV phai la so","","");
                return false;
            }
        }

        int so = (maNV[2] - '0') * 100 +
                 (maNV[3] - '0') * 10 +
                 (maNV[4] - '0');

        if (so == 0) {
            BaoLoi("Ma nhan vien khong duoc ","la NV000","");
            return false;
        }

        return true;
    }
    
    static bool chuanHoaTen(string& s) {
        if (s.length() == 0) {
            BaoLoi("Ten rong!", "", "");
            return false;
        }

        while (!s.empty() && s[0] == ' ')
            s.erase(0, 1);

        while (!s.empty() && s[s.length() - 1] == ' ')
            s.erase(s.length() - 1, 1);

        for (int i = 0; i + 1 < s.length(); i++) {
            if (s[i] == ' ' && s[i + 1] == ' ') {
                s.erase(i, 1);
                i--;
            }
        }

        for (int i = 0; i < s.length(); i++) {
            char c = s[i];
            if (!((c >= 'A' && c <= 'Z') ||
                  (c >= 'a' && c <= 'z') ||
                  c == ' ' ||
                  c == '\'' ||
                  c == '.' ||
                  (unsigned char)c >= 128)) {
                BaoLoi("Ten chua ky tu khong hop le!", "", "");
                return false;
            }
        }

        bool dauTu = true;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == ' ') {
                dauTu = true;
            } else if (dauTu) {
                if (s[i] >= 'a' && s[i] <= 'z') {
                    s[i] = s[i] - 32;
                }
                dauTu = false;
            } else {
                if (s[i] >= 'A' && s[i] <= 'Z') {
                    s[i] = s[i] + 32;
                }
            }
        }

        return true;
    }
    
    static bool kiemTraLoaiHoaDon(string& Loai) {
        char loai = Loai[0];
        if (loai >= 'a' && loai <= 'z') {
            loai -= 32;
        }
        Loai[0] = loai;

        return (Loai[0] == 'N' || Loai[0] == 'X');
    }
    
    static bool chuanHoaGioiTinh(string &phai) {
        while (phai.length() > 0 && phai[0] == ' ')
            phai.erase(0, 1);
        while (phai.length() > 0 && phai[phai.length() - 1] == ' ')
            phai.erase(phai.length() - 1, 1);

        for (int i = 0; i < phai.length(); i++) {
            if (phai[i] >= 'A' && phai[i] <= 'Z')
                phai[i] += 32;
        }

        if (phai == "nam") {
            phai = "Nam";
            return true;
        }

        if (phai == "nữ" || phai == "nu") {
            phai = "Nữ";
            return true;
        }

        BaoLoi("Giới tính chỉ được ","là Nam hoặc Nữ","");
        return false;
    }
    
    static int kiemTraSoNguyen() {
        int n;
        cin >> n;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            BaoLoi("Số lượng tồn không đúng định","dạng","");
            return -1;
        }
        if (n < 0 ) {  
            BaoLoi("lượng tồn không thể là số âm","","");
            return -1;
        } 
        return n;
    }
    
    static long long quyDoiNgay(int d, int m, int y) {
        return (long long)y * 10000 + m * 100 + d;
    }
};

// ========== CLASS QUẢN LÝ VẬT TƯ ==========
class QuanLyVatTu {
private:
    string fileVatTu;
    
    struct VatTu {
        string MAVT;
        string TENVT;
        string DVT;
        int SoLuongTon;
        int height;
    };
    
    struct nodeVT {
        VatTu vt;
        nodeVT *left, *right;
    };
    
    typedef nodeVT* treeVT;
    
public:
    treeVT dsVatTu = NULL;
    treeVT mangVatTu[MAX_VATTU];
    int index = 0;
    int soLuongVatTu = 0;
    VatTu vatTuTam = {"", "", "", -1};
    treeVT nodeTam = NULL;
    
    QuanLyVatTu(string fileVatTu) {
        this->fileVatTu = fileVatTu;
        KhoiTaoMangVatTu();
        dsVatTu = TaoCayNhiPhanCanBang(1, MAX_VATTU);
        CapNhatChieuCao(dsVatTu);
        MoFile();
    }
    
    void KhoiTaoMangVatTu() {
        for(int i = 0; i < MAX_VATTU; i++) {
            mangVatTu[i] = NULL;
        }
    }
    
    treeVT TaoCayNhiPhanCanBang(int start, int end) {
        if(start > end) {
            return nullptr;
        }
        int mid = (start + end)/2;
        treeVT root = new nodeVT;
        string ma = string(4 - to_string(mid).length(), '0') + to_string(mid);
        root->vt.MAVT = "VT" + ma;
        root->vt.TENVT = "";
        root->vt.DVT = "";
        root->vt.SoLuongTon = 0;  
        root->left = TaoCayNhiPhanCanBang(start, mid - 1);
        root->right = TaoCayNhiPhanCanBang(mid + 1, end);
        return root;
    }
    
    int CapNhatChieuCao(treeVT root) {
        if (root == nullptr) return -1;
        int height_left = CapNhatChieuCao(root->left);
        int height_right = CapNhatChieuCao(root->right);
        root->vt.height = 1 + max(height_left, height_right);
        return root->vt.height;
    }
    
    void DuyetCayVaoMangLNR(treeVT root) {
        if(root != NULL) { 
            DuyetCayVaoMangLNR(root->left);
            if(root->vt.TENVT != "") {
                mangVatTu[index++] = root;
            }
            DuyetCayVaoMangLNR(root->right); 
        } 
    }
    
    treeVT TimKiemTheoMaVT(treeVT root, string maVT) { 
        if (root == NULL || root->vt.MAVT == maVT) 
            return root;
        if (root->vt.MAVT < maVT) 
            return TimKiemTheoMaVT(root->right, maVT);
        return TimKiemTheoMaVT(root->left, maVT); 
    }
    
    treeVT TimKiemTheoMaVT1(treeVT root, string maVT) { 
        if (root == NULL || (root->vt.MAVT == maVT && root->vt.TENVT != "")) 
            return root;
        if (root->vt.MAVT < maVT) 
            return TimKiemTheoMaVT1(root->right, maVT);
        return TimKiemTheoMaVT1(root->left, maVT); 
    }
    
    void NhapVatTu(VatTu vatTu) {
        treeVT temp = TimKiemTheoMaVT(dsVatTu, vatTu.MAVT);
        if(temp != NULL) {
            temp->vt.MAVT = vatTu.MAVT;
            temp->vt.TENVT = vatTu.TENVT;
            temp->vt.DVT = vatTu.DVT;
            temp->vt.SoLuongTon = vatTu.SoLuongTon;
        }
    }
    
    int MenuNhap(string menu[], int viTriHienTai, int soLuong) {
        gotoxy(18, 19); cout<<"Enter: Để nhập.";
        
        if (viTriHienTai == soLuong) {
            viTriHienTai--;
        }
        
        int chon = viTriHienTai;
        gotoxy(18,10);
        int khoangCach = 0;
        for (int i = 0; i < soLuong-2; i++) {
            gotoxy(18,10+khoangCach); 
            cout<<menu[i]<<endl;
            khoangCach+=2;
        }
        gotoxy(60,19); 
        cout<<menu[soLuong-2]<<"          "<<menu[soLuong-1];
        
        HighLight();
        if(chon == 0) {
            gotoxy(18,10);
            cout << menu[chon];
        } else if(chon == soLuong - 2 || chon == soLuong - 1) {
            if(chon == soLuong-2) {
                gotoxy(60,19);
            } else {
                gotoxy(75, 19);
            }
            cout << menu[chon];
        } else { 
            gotoxy(18,10+chon*2);
            cout << menu[chon];
        }
        
        char kytu;
        do {
            kytu = getch();
            if (kytu == 0) kytu = getch();
            switch (kytu) {
                case Up:
                    if (chon > 0 && chon != soLuong - 1) {
                        Normal();
                        if(chon == soLuong - 2) {
                            gotoxy(60,19);
                        } else {
                            gotoxy(18,10+chon*2);
                        }
                        cout << menu[chon];
                        chon -= 1;
                        HighLight();
                        gotoxy(18,10+chon*2);
                        cout << menu[chon];
                    }
                    break;
                case Down:
                    if (chon < soLuong - 2) {
                        Normal();
                        gotoxy(18,10+chon*2);
                        cout << menu[chon];
                        chon += 1;
                        HighLight();
                        if(chon == soLuong - 2) {
                            gotoxy(60,19);
                        } else {
                            gotoxy(18,10+chon*2);
                        }
                        cout << menu[chon];
                    }
                    break;
                case Right:
                    if(chon == soLuong - 2) {
                        Normal();
                        gotoxy(60,19);
                        cout << menu[chon];
                        chon += 1;
                        HighLight();
                        gotoxy(75,19);
                        cout << menu[chon];
                    }
                    break;
                case Left:
                    if(chon == soLuong - 1) {
                        Normal();
                        gotoxy(75,19);
                        cout << menu[chon];
                        chon -= 1;
                        HighLight();
                        gotoxy(60,19);
                        cout << menu[chon];
                    }
                    break;
                case F1:
                    return 20;
                case F2:
                    return 21;
                case 13: // Enter
                    return chon + 1;
            }
        } while (1);
    }
    
    void XoaVatTu(treeVT temp) { 
        temp->vt.TENVT = "";
        temp->vt.DVT = "";
        temp->vt.SoLuongTon = 0;
    }
    
    void ChinhSuaVatTu(treeVT temp, VatTu vatTu) {
        temp->vt.TENVT = vatTu.TENVT;
        temp->vt.DVT = vatTu.DVT;
    }
    
    void GhiFile() {
        ofstream outputFile(fileVatTu);      
        if (outputFile.is_open()) {
            index = 0;
            DuyetCayVaoMangLNR(dsVatTu);
            for(int i = 0; i < 1000 && mangVatTu[i] != NULL; i++) {
                outputFile << mangVatTu[i]->vt.MAVT << ","
                          << mangVatTu[i]->vt.TENVT << ","
                          << mangVatTu[i]->vt.DVT << ","
                          << mangVatTu[i]->vt.SoLuongTon << endl;
            }
            BaoLoi("Ghi File Thành Công.","","");
        } else {
            BaoLoi("Không thể mở tệp để ghi.","","");  
        }
    }
    
    void MoFile() {
        ifstream inputFile(fileVatTu);
        if(inputFile.is_open()) {
            string line;
            int count = 0;
            while(getline(inputFile, line)) {
                stringstream ss(line);
                VatTu vatTu;
                getline(ss, vatTu.MAVT, ',');
                getline(ss, vatTu.TENVT, ',');
                getline(ss, vatTu.DVT, ',');
                ss >> vatTu.SoLuongTon;
                NhapVatTu(vatTu);
                count++;
            }
            string s = to_string(count) + " Vật Tư";
            BaoLoi("Mở File Thành Công", s, "");
        } else {
            BaoLoi("Không thể mở tệp doc.","","");
        }
    }
    
    void LietKeDanhSachVatTuTheoMaSo(int viTriBatDau, int viTriKetThuc) {
        index = 0;
        DuyetCayVaoMangLNR(dsVatTu);
        soLuongVatTu = index;
        int cot = 0;
        for(int i = viTriBatDau; i < viTriKetThuc && i < index; i++) {     
            gotoxy(8, 6+cot);
            cout << mangVatTu[i]->vt.MAVT; 
            gotoxy(16,6+cot);
            cout << mangVatTu[i]->vt.TENVT;
            gotoxy(39,6+cot);
            cout << mangVatTu[i]->vt.DVT;
            gotoxy(62,6+cot);
            cout << mangVatTu[i]->vt.SoLuongTon;
            cot++;
        }
        index = 0;
    }
    
    int partition(treeVT arr[], int l, int h) {
        string x = arr[h]->vt.TENVT;
        int i = (l - 1);
        for (int j = l; j <= h - 1; j++) {
            if (arr[j]->vt.TENVT <= x) {
                i++;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i + 1], arr[h]);
        return (i + 1);
    }
    
    void quickSort(treeVT arr[], int l, int h) {  
        if (l < h) { 
            int p = partition(arr, l, h);
            quickSort(arr, l, p - 1);
            quickSort(arr, p + 1, h);
        } 
    }
    
    void LietKeDanhSachVatTuTheoTen(int viTriBatDau, int viTriKetThuc) {
        DuyetCayVaoMangLNR(dsVatTu);
        quickSort(mangVatTu, 0, index - 1);
        soLuongVatTu = index;
        int cot = 0;
        for(int i = viTriBatDau; i < viTriKetThuc && i < index; i++) {     
            gotoxy(8, 6+cot);
            cout << mangVatTu[i]->vt.MAVT; 
            gotoxy(16,6+cot);
            cout << mangVatTu[i]->vt.TENVT;
            gotoxy(39,6+cot);
            cout << mangVatTu[i]->vt.DVT;
            gotoxy(62,6+cot);
            cout << mangVatTu[i]->vt.SoLuongTon;
            cot++;
        }
        index = 0;
    }
    
    bool KiemTraVatTu(string maVT, string loai, int soLuong) {
        nodeTam = TimKiemTheoMaVT1(dsVatTu, maVT);
        if(nodeTam != NULL) {
            if(nodeTam->vt.SoLuongTon < soLuong) {
                BaoLoi("Kho không đủ số lượng","","");
                return false;
            }
        } 
        return true;
    }
    
    void CapNhatSoLuongVatTu(string maVT, string loai, int soLuong) {
        nodeTam = TimKiemTheoMaVT(dsVatTu, maVT);
        if(nodeTam != NULL) {
            if(loai == "N") {
                nodeTam->vt.SoLuongTon += soLuong; 
            } else {
                nodeTam->vt.SoLuongTon -= soLuong;
            } 
        } 
    }
    
    void XoaCay(treeVT root) { 
        if(root != NULL) { 
            XoaCay(root->left);   
            XoaCay(root->right); 
            delete(root);
        } 
    }
    
    ~QuanLyVatTu() {
        XoaCay(dsVatTu);
    }
};

// ========== CLASS NHÂN VIÊN ==========
class NhanVien {
private:
    struct ChiTietHoaDon {
        string MAVT;
        int soluong;
        int DONGIA;
        int VAT;
        int tongtienthoethang = 0;
    };

    struct NodeCTHD {
        ChiTietHoaDon cthd;
        NodeCTHD* next;
    };
    typedef NodeCTHD* PTRCTHD;

    struct Date {
        int day, month, year;
    };

    struct HoaDon {
        string SoHD;
        Date NgayLapHoaDon;
        string Loai;
        int trigia = 0;
        PTRCTHD dscthd = NULL;
    };

    struct NodeHD {
        HoaDon hd;
        NodeHD* next;
    };
    typedef NodeHD* PTRHD;

    struct NhanVienStruct {
        string MANV;
        string HO;
        string TEN;
        string PHAI;
        PTRHD dshd = NULL; 
    };

    struct DSNhanVien {
        int n = -1;
        NhanVienStruct* nodes[MAX_NHANVIEN];
    };
    
    string fileNhanVien;
    string fileHoaDon;
    string fileChiTietHoaDon;
    
public:
    struct Date1 {
        int day, month, year;
    };
    
    struct ThongKeHoaDon {
        string maNV;
        PTRHD ptrhd;
    };
    
    struct Nam {
        int thang = 0;
        int doanhthuthang = 0;
    };
    
    struct TKCTHD {
        string tenvt;
        PTRCTHD cthd;
    };
    
    Nam nam[12];
    DSNhanVien dsNhanVien;
    NhanVienStruct nhanVienTam;
    int soLuongHoaDon = 0;
    int soLuongCTHD = 0;
    int dem3 = 0;
    int dem4 = 0;
    Date d1, d2;
    ThongKeHoaDon a1[1000];
    TKCTHD a2[5000];
    NhanVienStruct* nhanVienHienTai;
    ChiTietHoaDon a3[200];
    HoaDon hoaDon;
    PTRHD ptrHD;
    PTRHD ptrHDHienTai;
    HoaDon hoaDonMoiNhat;
    
    NhanVien(string fileNV, string fileHD, string fileCTHD) {
        fileNhanVien = fileNV;
        fileHoaDon = fileHD;
        fileChiTietHoaDon = fileCTHD;
        hoaDonMoiNhat.SoHD = "HD0000000000";
        MoFile();
    }

    void insert_order() {      
        int i = dsNhanVien.n - 1;
        NhanVienStruct* moi = dsNhanVien.nodes[dsNhanVien.n];

        while (i >= 0) {
            if (dsNhanVien.nodes[i]->TEN > moi->TEN ||
               (dsNhanVien.nodes[i]->TEN == moi->TEN &&
                dsNhanVien.nodes[i]->HO > moi->HO)) {
                dsNhanVien.nodes[i + 1] = dsNhanVien.nodes[i];
                i--;
            } else {
                break;
            }
        }  
        dsNhanVien.nodes[i + 1] = moi;
    }
    
    double TinhDoanhThuCT(const ChiTietHoaDon& ct) {  
        return ct.soluong * ct.DONGIA * (1 + ct.VAT / 100.0);
    }

    void NhapNhanVien(NhanVienStruct node, int f) {
        dsNhanVien.nodes[dsNhanVien.n] = new NhanVienStruct;
        dsNhanVien.nodes[dsNhanVien.n]->MANV = node.MANV;
        dsNhanVien.nodes[dsNhanVien.n]->HO = node.HO;
        dsNhanVien.nodes[dsNhanVien.n]->TEN = node.TEN;
        dsNhanVien.nodes[dsNhanVien.n]->PHAI = node.PHAI;
        dsNhanVien.nodes[dsNhanVien.n]->dshd = node.dshd;
        if(f) {
            insert_order();
        }
    }
    
    bool TimKiemTheoMaNV(NhanVienStruct nv) {
        for(int i = 0; i <= dsNhanVien.n; i++) {
            if(dsNhanVien.nodes[i]->MANV == nv.MANV)  {
                nhanVienHienTai = dsNhanVien.nodes[i];
                return true;
            }
        } 
        return false;
    }
    
    bool TimKiemTheoMaHoaDon(string maHD) {
        PTRHD temp = nhanVienHienTai->dshd;
        while(temp != NULL) {
            if(maHD == temp->hd.SoHD) {
                ptrHDHienTai = temp;
                return true;
            }
            temp = temp->next;
        }
        return false;
    }
    
    void InDSNVTheoTen(int viTriBatDau, int viTriKetThuc) {
        int cot = 0;
        for(int i = viTriBatDau; i < viTriKetThuc && i <= dsNhanVien.n; i++) {   
            if(dsNhanVien.nodes[i] == NULL) {
                gotoxy(8, 6+cot); 
                cout<<"NULL";
            } 
            gotoxy(8, 6+cot);
            cout << dsNhanVien.nodes[i]->MANV; 
            gotoxy(16,6+cot);
            cout << dsNhanVien.nodes[i]->HO;
            gotoxy(39,6+cot);
            cout << dsNhanVien.nodes[i]->TEN; 
            gotoxy(62,6+cot);
            cout << dsNhanVien.nodes[i]->PHAI;
            cot++;
        }
    }
    
    void GhiFileChiTietHoaDon(PTRCTHD t, string SoHD, ofstream &fileCT) {
        fileCT << SoHD << endl; 
        PTRCTHD temp = t;
        while (temp != NULL) {
            fileCT << temp->cthd.MAVT << "," 
                   << temp->cthd.soluong << "," 
                   << temp->cthd.DONGIA << "," 
                   << temp->cthd.VAT << endl;
            temp = temp->next;
        }
        fileCT << "." << endl;
    }

    void GhiFileHoaDon(PTRHD t, string MANV, ofstream &fileHD, ofstream &fileCT) {
        fileHD << MANV << endl;
        PTRHD temp = t;
        while (temp != NULL) {
            fileHD << temp->hd.SoHD << "," 
                   << temp->hd.Loai << "," 
                   << temp->hd.NgayLapHoaDon.day << "/" 
                   << temp->hd.NgayLapHoaDon.month << "/" 
                   << temp->hd.NgayLapHoaDon.year <<"."<< temp->hd.trigia<< endl;
            
            GhiFileChiTietHoaDon(temp->hd.dscthd, temp->hd.SoHD, fileCT);
            
            temp = temp->next;
        }
        fileHD << "." << endl;
    }

    void GhiFile() {
        ofstream f_nv(fileNhanVien);
        ofstream f_hd(fileHoaDon);
        ofstream f_ct(fileChiTietHoaDon);

        if (f_nv.is_open() && f_hd.is_open() && f_ct.is_open()) {
            for (int i = 0; i <= dsNhanVien.n; i++) {
                if (dsNhanVien.nodes[i] != NULL) {
                    f_nv << dsNhanVien.nodes[i]->MANV << "," 
                         << dsNhanVien.nodes[i]->HO << ","
                         << dsNhanVien.nodes[i]->TEN << "," 
                         << dsNhanVien.nodes[i]->PHAI << endl;

                    GhiFileHoaDon(dsNhanVien.nodes[i]->dshd, dsNhanVien.nodes[i]->MANV, f_hd, f_ct);
                }
            }

            f_nv.close();
            f_hd.close();
            f_ct.close();

            BaoLoi("Ghi File Thành Công.", "", "");
        } else {
            BaoLoi("Lỗi: Không thể mở các tệp để ghi.", "", "");
        }
    }
    
    void Reverse(PTRHD &start) {
        PTRHD ptr1, ptr2, ptr3; 
        
        if (start == NULL || start->next == NULL) {
            return; 
        }   
        ptr1 = start;
        ptr2 = ptr1->next;
        ptr3 = ptr2->next;
        ptr1->next = NULL;
        ptr2->next = ptr1;
        while (ptr3 != NULL) {
            ptr1 = ptr2;   
            ptr2 = ptr3; 
            ptr3 = ptr3->next; 
            ptr2->next = ptr1;          
        } 
        start = ptr2; 
    }
    
    void ReverseCTHD(PTRCTHD &start) {
        PTRCTHD ptr1, ptr2, ptr3; 
        
        if (start == NULL || start->next == NULL) {
            return; 
        }   
        ptr1 = start;
        ptr2 = ptr1->next;
        ptr3 = ptr2->next;
        ptr1->next = NULL;
        ptr2->next = ptr1;
        while (ptr3 != NULL) {
            ptr1 = ptr2;   
            ptr2 = ptr3; 
            ptr3 = ptr3->next; 
            ptr2->next = ptr1;          
        } 
        start = ptr2; 
    }
    
    void MoFileChiTietHoaDon(PTRCTHD &temp, ifstream &ct) {
        string sl, vat, dg;
        if(ct.is_open()) {
            string line;
            while(getline(ct, line)) {
                if(line[0] == 'H' && line[1] == 'D') {
                    continue;
                }
                if(line[0] == '.' || line == "") {
                    ReverseCTHD(temp);
                    return;
                }
                stringstream ss(line);
                ChiTietHoaDon cthd;
                getline(ss, cthd.MAVT, ',');
                getline(ss, sl, ',');
                getline(ss, dg, ',');
                getline(ss, vat);
                cthd.soluong = stoi(sl);
                cthd.VAT = stoi(vat);
                cthd.DONGIA = stoi(dg);
                InsertBeginCTHD(temp, cthd);
            }
        }
    }
    
    void MoFileHoaDon(PTRHD &temp, ifstream &h, ifstream &cthd) {
        string loai;
        string d, m, y, tg;
        if (h.is_open()) {
            string line;
            while (getline(h, line)) {
                if (line[0] == 'N' && line[1] == 'V') {
                    continue;
                }
                
                if (line[0] == '.' || line == "") {
                    Reverse(temp);
                    return;
                }

                stringstream ss(line);
                HoaDon hd;
                getline(ss, hd.SoHD, ',');
                getline(ss, hd.Loai, ',');
                getline(ss, d, '/');
                getline(ss, m, '/');
                getline(ss, y, '.');
                getline(ss, tg);
                
                hd.NgayLapHoaDon.day = stoi(d);
                hd.NgayLapHoaDon.month = stoi(m);
                hd.NgayLapHoaDon.year = stoi(y);
                hd.trigia = stoi(tg);
                hd.dscthd = NULL;

                if (hd.SoHD > hoaDonMoiNhat.SoHD) {
                    hoaDonMoiNhat.SoHD = hd.SoHD;
                }

                MoFileChiTietHoaDon(hd.dscthd, cthd);
                InsertBeginHD(temp, hd);
            }
        }
    }
    
    void SuaNhanVien(NhanVienStruct* &temp, NhanVienStruct nv) {
        temp->HO = nv.HO;
        temp->TEN = nv.TEN;
        temp->PHAI = nv.PHAI;
    }
    
    void XoaNhanVien(string maNV) {
        for(int i = 0; i <= dsNhanVien.n; i++) {
            if(dsNhanVien.nodes[i]->MANV == maNV) {
                PTRHD hd = dsNhanVien.nodes[i]->dshd;
                while(hd != NULL) {
                    PTRCTHD ct = hd->hd.dscthd;
                    while(ct != NULL) {
                        PTRCTHD tempCT = ct;
                        ct = ct->next;
                        delete tempCT;
                    }
                    PTRHD tempHD = hd;
                    hd = hd->next;
                    delete tempHD;
                }

                delete dsNhanVien.nodes[i];

                for(int j = i; j < dsNhanVien.n; j++) {
                    dsNhanVien.nodes[j] = dsNhanVien.nodes[j + 1];
                }

                dsNhanVien.nodes[dsNhanVien.n] = NULL;
                dsNhanVien.n--;
                return;
            }
        }
    }
    
    void MoFile() {
        ifstream inputFile(fileNhanVien);
        ifstream inputFileH(fileHoaDon);
        ifstream inputFileC(fileChiTietHoaDon);
        
        if(inputFile.is_open()) {
            string line;
            int count = 0;
            while(getline(inputFile, line)) {
                stringstream ss(line);
                NhanVienStruct node;
                getline(ss, node.MANV, ',');
                getline(ss, node.HO, ',');
                getline(ss, node.TEN, ',');
                getline(ss, node.PHAI);
                node.dshd = NULL;
                MoFileHoaDon(node.dshd, inputFileH, inputFileC);
                dsNhanVien.n++;
                NhapNhanVien(node, 0);
                count++;
            }
            string s = to_string(count) + " Nhân viên";
            BaoLoi("Mở File Thành Công", s, "");
        } else {
            BaoLoi("Không thể mở tệp doc.", "", "");
        }
    }
    
    PTRHD CreateNodeHD(HoaDon hd) {
        PTRHD temp = new NodeHD;
        if (temp == NULL) {
            cout << "Không đủ bộ nhớ" << endl; 
            return 0; 
        } else { 
            temp->hd.SoHD = hd.SoHD;
            temp->hd.Loai = hd.Loai;
            temp->hd.NgayLapHoaDon = hd.NgayLapHoaDon;
            temp->hd.dscthd = hd.dscthd;
            temp->hd.trigia = hd.trigia;
            temp->next = NULL;
            return temp;
        } 
    }
    
    void InsertBeginHD(PTRHD &dsHD, HoaDon hd) {
        PTRHD p; 
        PTRHD temp = CreateNodeHD(hd);
        if (dsHD == NULL) {
            dsHD = temp;
            dsHD->next = NULL;
        } else {
            p = dsHD;
            dsHD = temp;
            dsHD->next = p;
        } 
    }
    
    void DoHDVaoMang(PTRHD hd) {
        soLuongHoaDon = 0;
        PTRHD temp = hd;
        for(int i = 0; temp != NULL && i < 1000; i++) {
            soLuongHoaDon++;
            a1[i].ptrhd = temp;
            temp = temp->next;
        }
    }
    
    void DoCTHDVaoMang(PTRHD cthd) {
        soLuongCTHD = 0;
        PTRCTHD temp = cthd->hd.dscthd;
        for(int i = 0; temp != NULL && i < 500; i++) {
            soLuongCTHD++;
            a2[i].cthd = temp;
            temp = temp->next;
        }
    }
    
    void Display(PTRHD dsHD, int viTriBatDau, int viTriKetThuc) {
        DoHDVaoMang(dsHD);
        if (dsHD == NULL) { 
            cout << "Danh sách rỗng" << endl; 
            return; 
        }  
        int cot = 0;
        for(int i = viTriBatDau; i < viTriKetThuc && i < soLuongHoaDon; i++) {    
            gotoxy(8, 6+cot);
            cout << a1[i].ptrhd->hd.SoHD; 
            gotoxy(27,6+cot);
            cout << a1[i].ptrhd->hd.Loai;
            gotoxy(56,6+cot);
            cout << a1[i].ptrhd->hd.NgayLapHoaDon.day << "/" 
                 << a1[i].ptrhd->hd.NgayLapHoaDon.month << "/" 
                 << a1[i].ptrhd->hd.NgayLapHoaDon.year;
            cot++; 
        }
    }
void DisplayTKHoaDon(int viTriBatDau, int viTriKetThuc) {
    if (dem3 == 0) {
        gotoxy(40, 15); 
        cout << "KHÔNG CÓ HÓA ĐƠN NÀO TRONG KHOẢNG NÀY";
        return;
    }
    
    int dongHienTai = 0;
    for (int i = viTriBatDau; i < viTriKetThuc && i < dem3; i++) {
        gotoxy(8, 6 + dongHienTai);  
        cout << a1[i].ptrhd->hd.SoHD;
        gotoxy(24, 6 + dongHienTai); 
        cout << (a1[i].ptrhd->hd.Loai == "N" ? "NHẬP" : "XUẤT");
        gotoxy(37, 6 + dongHienTai); 
        cout << a1[i].ptrhd->hd.NgayLapHoaDon.day << "/" 
             << a1[i].ptrhd->hd.NgayLapHoaDon.month << "/" 
             << a1[i].ptrhd->hd.NgayLapHoaDon.year;
        
        nhanVienTam.MANV = a1[i].maNV;
        if (TimKiemTheoMaNV(nhanVienTam)) {
            gotoxy(52, 6 + dongHienTai); 
            cout << nhanVienHienTai->HO << " " << nhanVienHienTai->TEN;
        }
        
        gotoxy(72, 6 + dongHienTai); 
        cout << fixed << setprecision(0) << a1[i].ptrhd->hd.trigia << " VNĐ";
        dongHienTai++;
    }
}

void BubbleSort() {
    for(int i = 0; i < dem4; i++) {
        for(int j = i + 1; j < dem4; j++) {
            if(a2[i].cthd->cthd.tongtienthoethang < a2[j].cthd->cthd.tongtienthoethang) {
                swap(a2[i], a2[j]);
            }
        }
    }
}

void DisplayTop10(int viTriBatDau, int viTriKetThuc) {
    if (a2[0].cthd == NULL) { 
        cout << "Danh sách rỗng" << endl; 
        return; 
    }  
    BubbleSort();
    int cot = 0;
    for(int i = viTriBatDau; i < viTriKetThuc && i < dem4 && i < 10; i++) {    
        gotoxy(10, 6 + cot);
        cout << a2[i].cthd->cthd.MAVT; 
        gotoxy(32, 6 + cot); 
        cout << a2[i].tenvt;
        gotoxy(61, 6 + cot);
        cout << a2[i].cthd->cthd.tongtienthoethang << " VNĐ";
        cot++; 
    }
}

void DisplayDoanhThuThang(int viTriBatDau, int viTriKetThuc) {
    int cot = 0;
    for(int i = viTriBatDau; i < viTriKetThuc && i < 12; i++) {    
        gotoxy(8, 6 + cot);
        cout << nam[i].thang; 
        gotoxy(42, 6 + cot);
        cout << nam[i].doanhthuthang << " VNĐ";
        cot++; 
    }
}

PTRCTHD CreateNodeCTHD(ChiTietHoaDon cthd) {
    PTRCTHD temp = new NodeCTHD;
    if (temp == NULL) {
        cout << "Không đủ bộ nhớ" << endl; 
        return 0; 
    } else { 
        temp->cthd.MAVT = cthd.MAVT;
        temp->cthd.soluong = cthd.soluong;
        temp->cthd.DONGIA = cthd.DONGIA;
        temp->cthd.VAT = cthd.VAT;
        temp->next = NULL;
        return temp;
    } 
}

void InsertBeginCTHD(PTRCTHD &dsCTHD, ChiTietHoaDon cthd) {
    PTRCTHD p; 
    PTRCTHD temp = CreateNodeCTHD(cthd);
    if (dsCTHD == NULL) {
        dsCTHD = temp;
        dsCTHD->next = NULL;
    } else {
        p = dsCTHD;
        dsCTHD = temp;
        dsCTHD->next = p;
    } 
}

void DisplayCTHD(QuanLyVatTu &X, PTRHD cthd, int viTriBatDau, int viTriKetThuc) {
    if (cthd == NULL) { 
        cout << "Danh sách rỗng" << endl; 
        return; 
    } 
    DoCTHDVaoMang(cthd);
    int cot = 0;
    for(int i = viTriBatDau; i < viTriKetThuc && i < soLuongCTHD; i++) { 
        X.nodeTam = X.TimKiemTheoMaVT1(X.dsVatTu, a2[i].cthd->cthd.MAVT);  
        gotoxy(8, 6 + cot);
        cout << a2[i].cthd->cthd.MAVT; 
        gotoxy(16, 6 + cot); 
        cout << X.nodeTam->vt.TENVT;
        gotoxy(42, 6 + cot);
        cout << a2[i].cthd->cthd.DONGIA << " VNĐ";
        gotoxy(64, 6 + cot); 
        cout << a2[i].cthd->cthd.soluong;
        gotoxy(80, 6 + cot); 
        cout << a2[i].cthd->cthd.VAT << " %";
        cot++;
    }
}

void TaoSoHDVaNgayLapHD(HoaDon &hd, HoaDon hoaDonCu) {
    string thang;
    string songay = "";
    time_t now = time(0);
    tm* local_time = localtime(&now);
    hd.NgayLapHoaDon.year = local_time->tm_year + 1900;
    hd.NgayLapHoaDon.month = local_time->tm_mon + 1;
    hd.NgayLapHoaDon.day = local_time->tm_mday;
    
    if(hd.NgayLapHoaDon.month < 10) {
        thang = '0' + to_string(hd.NgayLapHoaDon.month);
    } else {
        thang = to_string(hd.NgayLapHoaDon.month);
    }
    
    string ngayHienTai = to_string(hd.NgayLapHoaDon.year) + thang; 
    int soThuTu = 0;
    
    string soHDCu = hoaDonCu.SoHD;
    string soCu = soHDCu.substr(soHDCu.length() - 4); 
    soThuTu = stoi(soCu);
    
    soThuTu++;
    
    for(int i = 2; i < 8; i++) {
        songay += hoaDonCu.SoHD[i];
    }
    
    if(ngayHienTai != songay) {
        soThuTu = 1;
    } 
    
    stringstream ss;
    ss << "HD" << hd.NgayLapHoaDon.year << thang 
       << setfill('0') << setw(4) << soThuTu; 
    hd.SoHD = ss.str();
}

void ThongKeHoaDon(Date d1, Date d2) {
    dem3 = 0;
    long long batDau = XuLyNhapLieu::quyDoiNgay(d1.day, d1.month, d1.year);
    long long ketThuc = XuLyNhapLieu::quyDoiNgay(d2.day, d2.month, d2.year);

    for (int i = 0; i <= dsNhanVien.n; i++) {
        PTRHD p = dsNhanVien.nodes[i]->dshd;
        while (p != NULL) {
            long long ngayLap = XuLyNhapLieu::quyDoiNgay(p->hd.NgayLapHoaDon.day, 
                                                       p->hd.NgayLapHoaDon.month, 
                                                       p->hd.NgayLapHoaDon.year);
            
            if (ngayLap >= batDau && ngayLap <= ketThuc) {
                if (dem3 < 1000) {
                    a1[dem3].maNV = dsNhanVien.nodes[i]->MANV;
                    a1[dem3].ptrhd = p;
                    dem3++;
                }
            }
            p = p->next;
        }
    } 
}

void TinhGiaTri(QuanLyVatTu &X) {
    dem4 = 0;
    
    for(int i = 0; i < 5000; i++) {
        a2[i].cthd = NULL;
        a2[i].tenvt = "";
    }
    
    for(int hdIndex = 0; hdIndex < dem3; hdIndex++) {
        PTRCTHD temp = a1[hdIndex].ptrhd->hd.dscthd;
        while(temp != NULL) {
            bool found = false;
            
            for(int vtIndex = 0; vtIndex < dem4; vtIndex++) {
                if(temp->cthd.MAVT == a2[vtIndex].cthd->cthd.MAVT) {
                    found = true;
                    double tien = temp->cthd.soluong * temp->cthd.DONGIA * (1 + temp->cthd.VAT/100.0);
                    a2[vtIndex].cthd->cthd.tongtienthoethang += (long long)tien;
                    break;
                }
            }
            
            if(!found) {
                X.nodeTam = X.TimKiemTheoMaVT1(X.dsVatTu, temp->cthd.MAVT);
                if(X.nodeTam != NULL) {
                    a2[dem4].tenvt = X.nodeTam->vt.TENVT;
                    
                    PTRCTHD newNode = new NodeCTHD;
                    newNode->cthd = temp->cthd;
                    
                    double tien = temp->cthd.soluong * temp->cthd.DONGIA * (1 + temp->cthd.VAT/100.0);
                    newNode->cthd.tongtienthoethang = (long long)tien;
                    newNode->next = NULL;
                    
                    a2[dem4].cthd = newNode;
                    dem4++;
                }
            }
            temp = temp->next;
        }
    }
}

void TimTheoNam(int namCanTim) {
    for(int i = 0; i < 12; i++) {
        nam[i].thang = i + 1;  
        nam[i].doanhthuthang = 0;
    }
    
    for(int i = 0; i <= dsNhanVien.n; i++) {
        if(dsNhanVien.nodes[i] == NULL) continue; 
        PTRHD temp = dsNhanVien.nodes[i]->dshd;
        while(temp != NULL) {
            if(temp->hd.NgayLapHoaDon.year == namCanTim) { 
                nam[temp->hd.NgayLapHoaDon.month - 1].thang = temp->hd.NgayLapHoaDon.month;
                nam[temp->hd.NgayLapHoaDon.month - 1].doanhthuthang += temp->hd.trigia;
            }
            temp = temp->next;
        }             
    }
}

~NhanVien() {
    for(int i = 0; i <= dsNhanVien.n; i++) {
        PTRHD temp = dsNhanVien.nodes[i]->dshd;
        while(temp != NULL) {
            PTRHD next = temp->next;
            delete temp;
            temp = next;
        }
        delete dsNhanVien.nodes[i];
    }
}
};

// ========== CÁC HÀM CASE ==========
void Case1(QuanLyVatTu &X) {
    char luaChon;
    int trangHienTai = 1;
    int viTriBatDau = 0;
    int viTriKetThuc = 20;
    system("cls");
    Normal();
    VeKhungDanhSach();
    VeTieuDeDanhSachVatTu();
    
    do {
        int cot = 0;
        for(int i = 0; i < 20; i++) {
            SetColor(9);
            gotoxy(15,6+cot);
            cout<<"║"; 
            gotoxy(38,6+cot);
            cout<<"║";
            gotoxy(61,6+cot);
            cout<<"║";
            gotoxy(8, 6+cot);
            Normal();
            cout << "       "; 
            gotoxy(16,6+cot);
            cout<<"                     ";
            gotoxy(39,6+cot);
            cout << "                 ";
            gotoxy(62,6+cot);
            cout<<"                             ";
            cot++;
        }
        
        X.LietKeDanhSachVatTuTheoMaSo(viTriBatDau, viTriKetThuc);
        HighLight();
        int tongTrang = 0;
        X.nodeTam = NULL;
        if(X.soLuongVatTu % 20 == 0) {
            tongTrang = X.soLuongVatTu/20;
        } else {
            tongTrang = X.soLuongVatTu/20 + 1;
        }
        gotoxy(90,2); 
        cout<<trangHienTai<<"/"<<tongTrang<<" ";
        Normal();
        
        luaChon = getch(); 
        if (luaChon == 0) 
            luaChon = getch(); 
            
        switch (luaChon) {
            case F1: {
                VeKhungNhap();
                gotoxy(40,8); 
                cout <<"THÊM MỚI VẬT TƯ";
                X.vatTuTam = {"", "", "", -1};
                bool flag = true;
                int temp = 0;
                
                do {
                    Normal();
                    int luaChonMenu = X.MenuNhap(menuNhapVatTu, temp, 6);
                    temp = luaChonMenu;
                    Normal();
                    
                    switch (luaChonMenu) {
                        case 1: 
                            gotoxy(49,10); 
                            cout<<"                          ";
                            gotoxy(49,10);
                            getline(cin, X.vatTuTam.MAVT);
                            if(!XuLyNhapLieu::chuanHoaMAVT(X.vatTuTam.MAVT)) {
                                temp = 0;
                                if(X.vatTuTam.SoLuongTon != -1) {
                                    gotoxy(45,16); 
                                    cout<< X.vatTuTam.SoLuongTon;
                                }
                                gotoxy(38,12); 
                                cout<< X.vatTuTam.TENVT;
                                gotoxy(39,14); 
                                cout<< X.vatTuTam.DVT;
                                break;
                            } 
                            gotoxy(49,10);
                            cout<<"                    ";
                            gotoxy(49,10);
                            cout<<X.vatTuTam.MAVT;
                            X.nodeTam = X.TimKiemTheoMaVT(X.dsVatTu, X.vatTuTam.MAVT);
                            if(X.nodeTam != NULL && X.nodeTam->vt.TENVT != "") {
                                BaoLoi("Mã VT đã có trong danh sách ", "hoặc không đúng định dạng","");
                                gotoxy(45,16); 
                                cout<< X.vatTuTam.SoLuongTon;
                                gotoxy(38,12); 
                                cout<< X.vatTuTam.TENVT;
                                gotoxy(39,14); 
                                cout<< X.vatTuTam.DVT;
                                temp = 0; 
                            }    
                            break;
                            
                        case 2:  
                            gotoxy(38,12); 
                            cout<<"                      ";
                            gotoxy(38,12);
                            getline(cin, X.vatTuTam.TENVT);
                            break;
                            
                        case 3:  
                            gotoxy(39,14); 
                            cout<<"                   ";
                            gotoxy(39,14);
                            getline(cin, X.vatTuTam.DVT);
                            break;
                            
                        case 4: 
                            gotoxy(45,16); 
                            cout<<"            ";
                            gotoxy(45,16);
                            X.vatTuTam.SoLuongTon = XuLyNhapLieu::kiemTraSoNguyen();
                            if (X.vatTuTam.SoLuongTon == -1) {
                                gotoxy(45,16); 
                                cout<< X.vatTuTam.SoLuongTon;
                                gotoxy(38,12); 
                                cout<< X.vatTuTam.TENVT;
                                gotoxy(39,14); 
                                cout<< X.vatTuTam.DVT;
                                temp = 3;  
                            } 
                            break;
                            
                        case 5: 
                            flag = false; 
                            break;
                            
                        case 6:
                            if(X.vatTuTam.MAVT == "") {
                                BaoLoi("Mã VT không được để trống", "","");
                                temp = 0; 
                                break;
                            }    
                            int t = XacNhanLuaChon();
                            if(t == 1) {
                                X.NhapVatTu(X.vatTuTam);  
                                flag = false;
                            } else {
                                Normal();
                                for(int i = 0; i < 6; i++) {
                                    gotoxy(35,12+i);
                                    for (int j = 0; j < 35; j++) {
                                        cout<<" ";
                                    }
                                }
                                gotoxy(48,12); 
                                cout<<X.vatTuTam.TENVT;
                                gotoxy(40,14);
                                cout<<X.vatTuTam.DVT;
                                if(X.vatTuTam.SoLuongTon != -1) {
                                    gotoxy(42,16);
                                    cout<<X.vatTuTam.SoLuongTon;
                                }
                                break; 
                            }
                    } 
                } while(flag);  
                XoaKhungNhap(); 
                break;
            }
                
            case F2: { 
                VeKhungNhap(); 
                gotoxy(40,8); 
                cout <<"XÓA VẬT TƯ";
                int temp = 0;
                bool flag = true;
                
                do {
                    int luaChonMenu = X.MenuNhap(menuXoaVatTu, temp, 3);
                    temp = luaChonMenu;
                    Normal();
                    
                    switch (luaChonMenu) {
                        case 1: {
                            gotoxy(47,10); 
                            cout<<"                   ";
                            gotoxy(47,10);
                            getline(cin, X.vatTuTam.MAVT);
                            if(!XuLyNhapLieu::chuanHoaMAVT(X.vatTuTam.MAVT)) {
                                temp = 0;
                                gotoxy(47,10); 
                                cout<<"                          ";
                                break;
                            }
                            gotoxy(47,10); 
                            cout<<X.vatTuTam.MAVT;
                            X.nodeTam = X.TimKiemTheoMaVT(X.dsVatTu, X.vatTuTam.MAVT);
                            if(X.nodeTam != NULL) {      
                                gotoxy(18,12); 
                                cout<<"Tên vật tư: "<< X.nodeTam->vt.TENVT;
                                gotoxy(18,14); 
                                cout<<"Đơn vị tính: "<<X.nodeTam->vt.DVT;
                                gotoxy(18,16); 
                                cout<<"Số lượng tồn: "<<X.nodeTam->vt.SoLuongTon;
                            } else {
                                BaoLoi("Không tìm thấy mã VT để xóa!", "","");
                                temp--;
                            } 
                            break;
                        }
                            
                        case 2: 
                            flag = false; 
                            break;
                            
                        case 3: 
                            if(X.vatTuTam.MAVT == "" || X.nodeTam == NULL) {
                                BaoLoi("Hãy nhập vật tư cần xóa","","");
                                temp = 0;
                                break;
                            }
                            int t = XacNhanLuaChon();
                            if(t == 1) {
                                X.XoaVatTu(X.nodeTam);  
                                flag = false;
                            } else {
                                Normal();
                                for(int i = 0; i < 6; i++) {
                                    gotoxy(35,12+i);
                                    for (int j = 0; j < 35; j++) {
                                        cout<<" ";
                                    }
                                }
                                if(X.vatTuTam.MAVT != "") {
                                    gotoxy(30,12); 
                                    cout<<"Tên vật tư: "<< X.nodeTam->vt.TENVT;
                                    gotoxy(31,14); 
                                    cout<<"Đơn vị tính: "<<X.nodeTam->vt.DVT;
                                    gotoxy(32,16); 
                                    cout<<"Số lượng tồn: "<<X.nodeTam->vt.SoLuongTon;
                                } else {
                                    break;
                                }
                                break; 
                            }
                    } 
                } while(flag); 
                XoaKhungNhap();
                break;
            }
                
            case F3: {
                VeKhungNhap();
                gotoxy(40,8); 
                cout <<"CHỈNH SỬA VẬT TƯ"; 
                int temp = 0;
                bool flag = true;
                bool l = true;
                int t = 3;
                string s[3] = {"Nhập mã vật tư(VD: VT0099):"," Hủy "," Xác nhận "};
                for(int i = 0; i < 3; i++) {
                    menuSuaVatTu[i] = s[i];
                }
                X.vatTuTam = {"", "", "", -1};
                
                do {
                    int luaChonMenu = X.MenuNhap(menuSuaVatTu, temp, t);
                    temp = luaChonMenu;
                    Normal();
                    
                    switch (luaChonMenu) {
                        case 1: {
                            if(l) {
                                gotoxy(47,10); 
                                cout<<"                   ";
                                gotoxy(47,10);
                                getline(cin, X.vatTuTam.MAVT);
                                if(!XuLyNhapLieu::chuanHoaMAVT(X.vatTuTam.MAVT)) {
                                    temp = 0;
                                    gotoxy(47,10); 
                                    cout<<"                          ";
                                    break;
                                }
                                gotoxy(47,10); 
                                cout<<X.vatTuTam.MAVT;
                                X.nodeTam = X.TimKiemTheoMaVT(X.dsVatTu, X.vatTuTam.MAVT);
                                if(X.nodeTam != NULL) { 
                                    string s[5] = {"Nhập mã vật tư(VD: VT0099):","Tên vật tư:", "Đơn vị tính:",
                                                   " Hủy "," Xác nhận "};  
                                    for(int i = 0; i < 5; i++) {
                                        menuSuaVatTu[i] = s[i];
                                    }   
                                    gotoxy(30,12); 
                                    cout<<X.nodeTam->vt.TENVT;
                                    gotoxy(31,14);
                                    cout<< X.nodeTam->vt.DVT;
                                    l = false; 
                                    t = 5;
                                } else {
                                    BaoLoi("Không tìm thấy mã VT để ","chỉnh sửa","");
                                    temp--;
                                }
                            }
                            break;
                        }
                            
                        case 2:  
                            if(t == 3) {
                                flag = false; 
                                break;
                            }
                            gotoxy(30,12); 
                            cout<<"                   ";
                            gotoxy(30,12);
                            getline(cin, X.vatTuTam.TENVT);
                            break;
                            
                        case 3:  
                            if(t == 3) {
                                BaoLoi("Hãy nhập vật tư cần chỉnh sửa","","");
                                temp = 0;
                                break; 
                            }
                            gotoxy(31,14); 
                            cout<<"                   ";
                            gotoxy(31,14);
                            getline(cin, X.vatTuTam.DVT);
                            break;
                            
                        case 4: 
                            flag = false; 
                            break;
                            
                        case 5: 
                            if(X.vatTuTam.MAVT == "" || X.nodeTam == NULL) {
                                BaoLoi("Hãy nhập vật tư cần chỉnh sửa","","");
                                temp = 0;
                                break;
                            } 
                            int t = XacNhanLuaChon();
                            if(t == 1) {
                                if(X.vatTuTam.TENVT == "") {
                                    X.vatTuTam.TENVT = X.nodeTam->vt.TENVT;
                                }
                                if(X.vatTuTam.DVT == "") {
                                    X.vatTuTam.DVT = X.nodeTam->vt.DVT;
                                }
                                X.ChinhSuaVatTu(X.nodeTam, X.vatTuTam);  
                                flag = false;
                            } else {
                                Normal();
                                for(int i = 0; i < 6; i++) {
                                    gotoxy(35,12+i);
                                    for (int j = 0; j < 35; j++) {
                                        cout<<" ";
                                    }
                                }
                                gotoxy(30,12); 
                                cout<<X.vatTuTam.TENVT;
                                gotoxy(31,14);
                                cout<<X.vatTuTam.DVT;
                                break; 
                            }
                    } 
                } while(flag);
                XoaKhungNhap(); 
                break;
            }

            case Up: {
                if(trangHienTai <= 1) {
                    BaoLoi("Đang là trang đầu tiên!","","");
                    break;
                } 
                viTriBatDau -= 20; 
                viTriKetThuc -= 20; 
                trangHienTai -= 1; 
                break;
            }
                
            case Down: {
                if(viTriKetThuc >= X.soLuongVatTu) {
                    BaoLoi("Đã là trang cuối cùng!","","");
                    break;
                }
                viTriBatDau += 20; 
                viTriKetThuc += 20; 
                trangHienTai += 1;
                break;
            }
                
            case ESC: { 
                X.GhiFile(); 
                return;
            }
        }
    } while (true);
}

void Case2(QuanLyVatTu &X) {
    char luaChon;
    int trangHienTai = 1;
    int viTriBatDau = 0;
    int viTriKetThuc = 20;
    
    system("cls");
    Normal();
    VeKhungDanhSach();
    VeTieuDeSapXepTheoTen();
    
    do {
        int cot = 0;
        for(int i = 0; i < 20; i++) {
            SetColor(9);
            gotoxy(15,6+cot);
            cout<<"║"; 
            gotoxy(38,6+cot);
            cout<<"║";
            gotoxy(61,6+cot);
            cout<<"║";
            gotoxy(8, 6+cot);
            Normal();
            cout << "       "; 
            gotoxy(17,6+cot);
            cout<<"                     ";
            gotoxy(40,6+cot);
            cout << "                 ";
            gotoxy(63,6+cot);
            cout<<"                             ";
            cot++;
        }

        X.LietKeDanhSachVatTuTheoTen(viTriBatDau, viTriKetThuc);
        HighLight();
        int tongTrang = 0;
        if(X.soLuongVatTu % 20 == 0) {
            tongTrang = X.soLuongVatTu/20;
        } else {
            tongTrang = X.soLuongVatTu/20 + 1;
        }
        gotoxy(90,2); 
        cout<<trangHienTai<<"/"<<tongTrang<<" ";
        Normal();
        
        luaChon = getch(); 
        if (luaChon == 0) 
            luaChon = getch(); 
            
        switch (luaChon) {
            case Up: {
                if(trangHienTai <= 1) {
                    BaoLoi("Đang là trang đầu tiên!","","");
                    break;
                } 
                viTriBatDau -= 20; 
                viTriKetThuc -= 20; 
                trangHienTai -= 1; 
                break;
            }
                
            case Down: {
                if(viTriKetThuc >= X.soLuongVatTu) {
                    BaoLoi("Đã là trang cuối cùng!","","");
                    break;
                }
                viTriBatDau += 20; 
                viTriKetThuc += 20; 
                trangHienTai += 1;
                break;
            }
                
            case ESC: { 
                return;
            }
        }
    } while (true);
}

void Case3(QuanLyVatTu& X, NhanVien &Y) {
    string nhapNV[6] = {"1. Nhập mã nhân viên(VD: NV099):","2. Nhập họ nhân viên:", "3. Nhập tên nhân viên:",
        "4. Nhập giới tính nhân viên (VD: Nam/Nữ):"," Hủy "," Xác nhận "};
    char luaChon;
    int trangHienTai = 1;
    int viTriBatDau = 0;
    int viTriKetThuc = 20;
    
    system("cls");
    Normal();
    VeKhungDanhSachNhanVien();
    VeTieuDeDanhSachNhanVien();
    
    do {
        int cot = 0;
        for(int i = 0; i < 20; i++) {
            SetColor(9);
            gotoxy(15,6+cot);
            cout<<"║"; 
            gotoxy(38,6+cot);
            cout<<"║";
            gotoxy(61,6+cot);
            cout<<"║";
            gotoxy(8, 6+cot);
            Normal();
            cout << "       "; 
            gotoxy(16,6+cot);
            cout<<"                      ";
            gotoxy(39,6+cot);
            cout << "                      ";
            gotoxy(62,6+cot);
            cout<<"                             ";
            cot++;
        }
        
        Y.InDSNVTheoTen(viTriBatDau, viTriKetThuc);
        int tongTrang = 0;
        if(Y.dsNhanVien.n % 20 == 0) {
            tongTrang = Y.dsNhanVien.n/20;
        } else {
            tongTrang = Y.dsNhanVien.n/20 + 1;
        }
        HighLight();
        gotoxy(90,2); 
        cout<<trangHienTai<<"/"<<tongTrang<<" ";
        Normal();
        
        luaChon = getch(); 
        if (luaChon == 0) 
            luaChon = getch(); 
            
        switch (luaChon) {
            case F1: {
                VeKhungNhap();
                gotoxy(40,8); 
                cout <<"THÊM MỚI NHÂN VIÊN";
                Y.nhanVienTam = {"","","",""};
                bool flag = true;
                int temp = 0;
                
                do {
                    Normal();
                    int luaChonMenu = X.MenuNhap(nhapNV, temp, 6);
                    temp = luaChonMenu;
                    Normal();
                    
                    switch (luaChonMenu) {
                        case 1: {
                            gotoxy(51,10); 
                            cout<<"                   ";
                            gotoxy(51,10);
                            getline(cin, Y.nhanVienTam.MANV);
                            if(!XuLyNhapLieu::chuanHoaMaNV(Y.nhanVienTam.MANV)) {
                                temp = 0;
                                gotoxy(49,10); 
                                cout<<"                          ";
                            } 
                            gotoxy(51,10); 
                            cout<< Y.nhanVienTam.MANV;
                            if(Y.TimKiemTheoMaNV(Y.nhanVienTam)) {
                                BaoLoi("Mã NV bị trùng", "hoặc lớn hơn 100","");
                                temp = 0;
                            } 
                            break;
                        }
                            
                        case 2:  
                            gotoxy(40,12); 
                            cout<<"                   ";
                            gotoxy(40,12);
                            getline(cin, Y.nhanVienTam.HO);
                            if(!XuLyNhapLieu::chuanHoaTen(Y.nhanVienTam.HO)) {
                                temp = 1;
                                gotoxy(40,12); 
                                cout<< Y.nhanVienTam.HO;
                                gotoxy(41,14);
                                cout<<Y.nhanVienTam.TEN;
                                gotoxy(60,16); 
                                cout<<Y.nhanVienTam.PHAI;
                            } 
                            gotoxy(40,12); 
                            cout<< Y.nhanVienTam.HO;
                            break;
                            
                        case 3:  
                            gotoxy(41,14); 
                            cout<<"                   ";
                            gotoxy(41,14);
                            getline(cin, Y.nhanVienTam.TEN);
                            if(!XuLyNhapLieu::chuanHoaTen(Y.nhanVienTam.TEN)) {
                                temp = 1;
                                gotoxy(40,12); 
                                cout<< Y.nhanVienTam.HO;
                                gotoxy(41,14);
                                cout<<Y.nhanVienTam.TEN;
                                gotoxy(60,16); 
                                cout<<Y.nhanVienTam.PHAI;
                            } 
                            gotoxy(41,14);
                            cout<<Y.nhanVienTam.TEN;
                            break;
                            
                        case 4: 
                            gotoxy(60,16); 
                            cout<<"            ";
                            gotoxy(60,16);
                            getline(cin, Y.nhanVienTam.PHAI);
                            if(!XuLyNhapLieu::chuanHoaGioiTinh(Y.nhanVienTam.PHAI)) {
                                temp = 3;
                                gotoxy(40,12); 
                                cout<< Y.nhanVienTam.HO;
                                gotoxy(41,14);
                                cout<<Y.nhanVienTam.TEN;
                            } 
                            gotoxy(60,16); 
                            cout<<Y.nhanVienTam.PHAI;
                            break;
                            
                        case 5: 
                            flag = false; 
                            break;
                            
                        case 6: 
                            if(Y.nhanVienTam.MANV == "") {
                                BaoLoi("Mã NV không được", "để trống","");
                                temp = 0; 
                                break;
                            }
                            int t = XacNhanLuaChon();
                            if(t == 1) {
                                Y.dsNhanVien.n++;
                                Y.NhapNhanVien(Y.nhanVienTam, 1);  
                                flag = false;
                            } else {
                                Normal();
                                for(int i = 0; i < 6; i++) {
                                    gotoxy(35,12+i);
                                    for (int j = 0; j < 35; j++) {
                                        cout<<" ";
                                    }
                                }
                                gotoxy(40,12); 
                                cout<< Y.nhanVienTam.HO;
                                gotoxy(41,14);
                                cout<<Y.nhanVienTam.TEN;
                                gotoxy(60,16);
                                cout<< Y.nhanVienTam.PHAI;
                                break; 
                            }
                    } 
                } while(flag); 
                break;
            }
                
            case F2: {
                VeKhungNhap(); 
                gotoxy(40,8); 
                cout <<"XÓA NHÂN VIÊN";
                int temp = 0;
                bool flag = true;
                
                do {
                    int luaChonMenu = X.MenuNhap(menuXoaNhanVien, temp, 3);
                    temp = luaChonMenu;
                    Normal();
                    
                    switch (luaChonMenu) {
                        case 1: {
                            gotoxy(51,10); 
                            cout<<"                   ";
                            gotoxy(51,10);
                            getline(cin, Y.nhanVienTam.MANV);
                            if(!XuLyNhapLieu::chuanHoaMaNV(Y.nhanVienTam.MANV)) {
                                temp = 0;
                                gotoxy(49,10); 
                                cout<<"                          ";
                            } 
                            gotoxy(51,10); 
                            cout<< Y.nhanVienTam.MANV;
                            if(Y.TimKiemTheoMaNV(Y.nhanVienTam)) {      
                                gotoxy(18,12); 
                                cout<<"2. Họ và tên nhân viên: "<<Y.nhanVienHienTai->HO<<" "<<Y.nhanVienHienTai->TEN;
                                gotoxy(18,14); 
                                cout<<"3. Giới tính nhân viên: "<< Y.nhanVienHienTai->PHAI;
                            } else {
                                BaoLoi("Không tìm thấy mã NV để xóa!", "","");
                                temp = 0;
                            } 
                            break;
                        }
                            
                        case 2: 
                            flag = false; 
                            break;
                            
                        case 3: 
                            if(Y.nhanVienTam.MANV == "" || !Y.TimKiemTheoMaNV(Y.nhanVienTam)) {
                                BaoLoi("Hãy nhập nhân viên cần xóa","","");
                                temp = 0;
                                break;
                            }
                            int t = XacNhanLuaChon();
                            if(t == 1) {
                                Y.XoaNhanVien(Y.nhanVienTam.MANV);
                                flag = false;
                            } else {
                                Normal();
                                for(int i = 0; i < 6; i++) {
                                    gotoxy(35,12+i);
                                    for (int j = 0; j < 35; j++) {
                                        cout<<" ";
                                    }
                                }
                                if(Y.nhanVienTam.MANV != "") {
                                    gotoxy(18,12); 
                                    cout<<"2. Họ và tên nhân viên: "<<Y.nhanVienHienTai->HO<<" "<<Y.nhanVienHienTai->TEN;
                                    gotoxy(18,14); 
                                    cout<<"3. Giới tính nhân viên: "<< Y.nhanVienHienTai->PHAI;
                                } 
                            } 
                            break;
                    } 
                } while(flag); 
                break;
            }
                
            case F3: {
                VeKhungNhap();
                gotoxy(40,8); 
                cout <<"CHỈNH SỬA NHÂN VIÊN"; 
                int temp = 0;
                bool flag = true;
                bool l = true;
                int t = 3;
                string s[3] = {"1. Nhập mã nhân viên (VD: NV099):"," Hủy "," Xác nhận "};
                for(int i = 0; i < 3; i++) {
                    menuSuaNhanVien[i] = s[i];
                }
                Y.nhanVienTam = {"", "", "", ""};
                
                do {
                    int luaChonMenu = X.MenuNhap(menuSuaNhanVien, temp, t);
                    temp = luaChonMenu;
                    Normal();
                    
                    switch (luaChonMenu) {
                        case 1: {
                            if(l) {
                                gotoxy(52,10); 
                                cout<<"                   ";
                                gotoxy(52,10);
                                getline(cin, Y.nhanVienTam.MANV);
                                if(!XuLyNhapLieu::chuanHoaMaNV(Y.nhanVienTam.MANV)) {
                                    temp = 0;
                                    BaoLoi("Mã nhân viên không", "hợp lệ","");
                                    break;
                                } 
                                gotoxy(52,10);
                                cout<<Y.nhanVienTam.MANV;
                                if(Y.TimKiemTheoMaNV(Y.nhanVienTam)) {
                                    string s[6] = {"1. Nhập mã nhân viên (VD: NV099):","2. Sửa họ nhân viên:", "3. sửa tên nhân viên:",
                                                   "4. Sửa giới tính nhân viên (VD: Nam/Nữ):", " Hủy "," Xác nhận "};  
                                    for(int i = 0; i < 6; i++) {
                                        menuSuaNhanVien[i] = s[i];
                                    }   
                                    gotoxy(39,12); 
                                    cout<< Y.nhanVienHienTai->HO;
                                    gotoxy(40,14);
                                    cout<< Y.nhanVienHienTai->TEN;
                                    gotoxy(59, 16); 
                                    cout << Y.nhanVienHienTai->PHAI;
                                    l = false; 
                                    t = 6;
                                } else {
                                    BaoLoi("Không tìm thấy mã NV để ","chỉnh sửa","");
                                    temp--;
                                }
                            }
                            break;
                        }
                            
                        case 2:  
                            if(t == 3) {
                                flag = false; 
                                break;
                            }
                            gotoxy(39,12); 
                            cout<<"                   ";
                            gotoxy(39,12);
                            getline(cin, Y.nhanVienTam.HO);
                            if(!XuLyNhapLieu::chuanHoaTen(Y.nhanVienTam.HO)) {
                                temp = 1;
                                gotoxy(40,12); 
                                cout<< Y.nhanVienTam.HO;
                                gotoxy(41,14);
                                cout<<Y.nhanVienTam.TEN;
                                gotoxy(60,16); 
                                cout<<Y.nhanVienTam.PHAI;
                            } 
                            gotoxy(39,12); 
                            cout<<Y.nhanVienTam.HO;
                            break;
                            
                        case 3:  
                            if(t == 3) {
                                BaoLoi("Hãy nhập nhân viên cần chỉnh sửa","","");
                                temp = 0;
                                break; 
                            }
                            gotoxy(40,14); 
                            cout<<"                   ";
                            gotoxy(40,14);
                            getline(cin, Y.nhanVienTam.TEN); 
                            if(!XuLyNhapLieu::chuanHoaTen(Y.nhanVienTam.TEN)) {
                                temp = 1;
                                gotoxy(40,12); 
                                cout<< Y.nhanVienTam.HO;
                                gotoxy(41,14);
                                cout<<Y.nhanVienTam.TEN;
                                gotoxy(60,16); 
                                cout<<Y.nhanVienTam.PHAI;
                            } 
                            gotoxy(40,14);
                            cout<<"             ";
                            gotoxy(40,14);
                            cout<<Y.nhanVienTam.TEN;
                            break;
                            
                        case 4:  
                            gotoxy(59,16); 
                            cout<<"                   ";
                            gotoxy(59,16);
                            getline(cin, Y.nhanVienTam.PHAI);
                            if(!XuLyNhapLieu::chuanHoaGioiTinh(Y.nhanVienTam.PHAI)) {
                                temp = 3;
                                gotoxy(40,12); 
                                cout<< Y.nhanVienTam.HO;
                                gotoxy(41,14);
                                cout<<Y.nhanVienTam.TEN;
                            } 
                            gotoxy(59,16); 
                            cout<<Y.nhanVienTam.PHAI;
                            break;
                            
                        case 5: 
                            flag = false; 
                            break;
                            
                        case 6: {
                            int t = XacNhanLuaChon();
                            if(t == 1) {
                                if(Y.nhanVienTam.HO == "") {
                                    Y.nhanVienTam.HO = Y.nhanVienHienTai->HO;
                                }
                                if(Y.nhanVienTam.TEN == "") {
                                    Y.nhanVienTam.TEN = Y.nhanVienHienTai->TEN;
                                }
                                if(Y.nhanVienTam.PHAI == "") {
                                    Y.nhanVienTam.PHAI = Y.nhanVienHienTai->PHAI;
                                }
                                Y.SuaNhanVien(Y.nhanVienHienTai, Y.nhanVienTam);
                                flag = false;
                            } else {
                                Normal();
                                for(int i = 0; i < 6; i++) {
                                    gotoxy(35,12+i);
                                    for (int j = 0; j < 35; j++) {
                                        cout<<" ";
                                    }
                                }
                                if(Y.nhanVienTam.HO == "") {
                                    gotoxy(40,12);  
                                    cout<< Y.nhanVienHienTai->HO;
                                } else {
                                    gotoxy(40,12); 
                                    cout<<Y.nhanVienTam.HO;
                                }
                                if(Y.nhanVienTam.TEN == "") {
                                    gotoxy(41,14);  
                                    cout<< Y.nhanVienHienTai->TEN;
                                } else {
                                    gotoxy(41,14); 
                                    cout<<Y.nhanVienTam.TEN;
                                }
                                if(Y.nhanVienTam.PHAI == "") {
                                    gotoxy(60,16);  
                                    cout<< Y.nhanVienHienTai->PHAI;
                                } else {
                                    gotoxy(60,16); 
                                    cout<<Y.nhanVienTam.PHAI;
                                }
                                break; 
                            }
                        }
                    }
                } while(flag); 
                break;
            }

            case Up: {
                if(trangHienTai <= 1) {
                    BaoLoi("Đang là trang đầu tiên!","","");
                    break;
                } 
                viTriBatDau -= 20; 
                viTriKetThuc -= 20; 
                trangHienTai -= 1; 
                break;
            }
                
            case Down: {
                if(viTriKetThuc >= Y.dsNhanVien.n) {
                    BaoLoi("Đã là trang cuối cùng!","","");
                    break;
                }
                viTriBatDau += 20; 
                viTriKetThuc += 20; 
                trangHienTai += 1;
                break;
            }
                
            case ESC: { 
                Y.GhiFile(); 
                return;
            }
        }
    } while (true);
}	

bool NhapMaNV(QuanLyVatTu &X, NhanVien &Y) {
    VeKhungNhap(); 
    gotoxy(35,8); 
    cout <<" NHẬP NHÂN VIÊN CẦN LẬP HÓA ĐƠN ";
    int temp = 0;
    
    do {
        int luaChonMenu = X.MenuNhap(menuXoaNhanVien, temp, 3);
        temp = luaChonMenu;
        Normal();
        
        switch (luaChonMenu) {
            case 1: {
                gotoxy(51,10); 
                cout<<"                   ";
                gotoxy(51,10);
                getline(cin, Y.nhanVienTam.MANV);
                if(!XuLyNhapLieu::chuanHoaMaNV(Y.nhanVienTam.MANV)) {
                    temp = 0;
                    gotoxy(49,10); 
                    cout<<"                          ";
                } 
                gotoxy(51,10); 
                cout<< Y.nhanVienTam.MANV;
                if(Y.TimKiemTheoMaNV(Y.nhanVienTam)) {      
                    gotoxy(18,12); 
                    cout<<"2. Họ và tên nhân viên: "<<Y.nhanVienHienTai->HO<<" "<<Y.nhanVienHienTai->TEN;
                    gotoxy(18,14); 
                    cout<<"3. Giới tính nhân viên: "<< Y.nhanVienHienTai->PHAI;
                } else {
                    BaoLoi("Không tìm thấy mã NV để lập!", "hóa đơn","");
                    temp = 0;
                }
                break;
            }
                
            case 2: 
                return false;
                
            case 3: 
                if(Y.nhanVienTam.MANV == "" || !Y.TimKiemTheoMaNV(Y.nhanVienTam)) {
                    BaoLoi("Hãy nhập NV cần lập hóa đơn","","");
                    temp = 0;
                    break;
                }
                int t = XacNhanLuaChon();
                if(t == 1) {
                    return true;
                } else {
                    Normal();
                    for(int i = 0; i < 6; i++) {
                        gotoxy(35,12+i);
                        for (int j = 0; j < 35; j++) {
                            cout<<" ";
                        }
                    }
                    if(Y.nhanVienTam.MANV != "") {
                        gotoxy(18,12); 
                        cout<<"2. Họ và tên nhân viên: ";
                        cout<<Y.nhanVienHienTai->HO<<" "<<Y.nhanVienHienTai->TEN;
                        gotoxy(18,14); 
                        cout<<"3. Giới tính nhân viên: ";
                        cout<< Y.nhanVienHienTai->PHAI;
                    } 
                } 
                break;
        } 
    } while(1);
}

// ========== CÁC HÀM BỔ SUNG CÒN THIẾU ==========

void VeKhungDanhSachNhanVienCase3() {
    VeKhungBaoQuanh();
    SetColor(9);
    gotoxy(15, 4); cout<<"║";
    gotoxy(38, 4); cout<<"║";
    gotoxy(61, 4);cout<<"║";
    Normal();
    gotoxy(8,4); cout<<" MãNV";
    gotoxy(17, 4);cout<<" Họ nhân viên";
    gotoxy(40, 4); cout<<" Tên nhân viên"; 
    gotoxy(63, 4); cout<< " Giới tính      ";
    SetColor(9);
    gotoxy(8, 5); 
    for(int i = 0; i <85; i++) {
        cout <<"═"; 
    }

    for(int i = 0 ; i < 22; i++) {
        gotoxy(15, 4+i+1); cout<<"║"; 
        gotoxy(38, 4+i+1); cout<<"║"; 
        gotoxy(61, 4+i+1);cout<<"║"; 
    }
    gotoxy(8, 26);
    for(int i = 0; i < 85; i++) {
        cout<<"═";
    }
    gotoxy(82, 2); 
    HighLight();
    cout<<" Trang: ";
    Normal();
}

void VeKhungDanhSachHoaDonCase4() {
    VeKhungBaoQuanh();
    SetColor(9);
    gotoxy(25, 4); cout<<"║";
    gotoxy(54, 4);cout<<"║";
    Normal();
    gotoxy(8,4); cout<<" Mã Hóa Đơn";
    gotoxy(27, 4); cout<<" Loại hóa đơn ";
    gotoxy(56, 4); cout<< " Ngày tháng lập hóa đơn ";
    SetColor(9);
    gotoxy(8, 5); 
    for(int i = 0; i <85; i++) {
        cout <<"═"; 
    }

    for(int i = 0 ; i < 22; i++) {
        gotoxy(25, 4+i+1); cout<<"║"; 
        gotoxy(54, 4+i+1); cout<<"║"; 
    }
    gotoxy(8, 26);
    for(int i = 0; i < 85; i++) {
        cout<<"═";
    }
    gotoxy(82, 2); 
    HighLight();
    cout<<" Trang: ";
    Normal();
}

void VeKhungThongKeHoaDonCase5() {
    VeKhungBaoQuanh();
    SetColor(9);
    gotoxy(22, 4); cout<<"║";
    gotoxy(35, 4); cout<<"║";
    gotoxy(50, 4);cout<<"║";
    gotoxy(70, 4);cout<<"║";
    Normal();
    gotoxy(8,4); cout<<" Mã HĐ";
    gotoxy(24, 4); cout<<" Loại";
    gotoxy(37, 4);cout<<" Ngày tháng";
    gotoxy(52,4); cout<<" Tên nhân viên";
    gotoxy(72, 4); cout<< " Trị giá hóa đơn";
    SetColor(9);
    gotoxy(8, 5); 
    for(int i = 0; i <85; i++) {
        cout <<"═"; 
    }

    for(int i = 0 ; i < 22; i++) {
        gotoxy(22, 4+i+1); cout<<"║"; 
        gotoxy(35, 4+i+1); cout<<"║"; 
        gotoxy(50, 4+i+1);cout<<"║"; 
        gotoxy(70, 4+i+1);cout<<"║";
    }
    gotoxy(8, 26);
    for(int i = 0; i < 85; i++) {
        cout<<"═";
    }
    gotoxy(82, 2); 
    HighLight();
    cout<<" Trang: ";
    Normal();
}

void VeKhungTop10VatTuCase6() {
   VeKhungBaoQuanh();
    SetColor(9);
    gotoxy(30, 4); cout<<"║"; gotoxy(60, 4); cout<<"║";
    Normal();
    gotoxy(12,4); cout<<" Mã vật tư";
    gotoxy(34, 4); cout<<"Tên vật tư";
    gotoxy(63, 4); cout<<" Tổng doanh thu của vật tư";
    SetColor(9);
    gotoxy(8, 5); 
    for(int i = 0; i <85; i++) {
        cout <<"═"; 
    }

    for(int i = 0 ; i < 22; i++) { 
        gotoxy(30, 4+i+1); cout<<"║"; 
        gotoxy(60, 4+i+1); cout<<"║"; 
    }
    gotoxy(8, 26);
    for(int i = 0; i < 85; i++) {
        cout<<"═";
    }
    gotoxy(82, 2); 
    HighLight();
    cout<<" Trang: ";
    Normal();
}

void VeKhungDoanhThuThangCase7() {
   VeKhungBaoQuanh();
    SetColor(9);
    gotoxy(38, 4); cout<<"║";
    Normal();
    gotoxy(15,4); cout<<" Tháng ";
    gotoxy(45, 4); cout<<" Doanh thu";
    SetColor(9);
    gotoxy(8, 5); 
    for(int i = 0; i <85; i++) {
        cout <<"═"; 
    }

    for(int i = 0 ; i < 22; i++) { 
        gotoxy(38, 4+i+1); cout<<"║"; 
    }
    gotoxy(8, 26);
    for(int i = 0; i < 85; i++) {
        cout<<"═";
    }
    gotoxy(82, 2); 
    HighLight();
    cout<<" Trang: ";
    Normal();
}

// ========== HÀM NHẬP CHI TIẾT HÓA ĐƠN ==========
void NhapChiTietHoaDon(QuanLyVatTu &X, NhanVien &Y) {
    for(int i = 0; i < 200; i++) {
        Y.a3[i].DONGIA = 0;
        Y.a3[i].MAVT = "";
        Y.a3[i].soluong = 0;
        Y.a3[i].VAT = 0;
    }
    
    VeKhungNhap();
    int dem = 0;
    int trigia = 0;
    gotoxy(40, 8); 
    cout <<"NHẬP VẬT TƯ CHO HÓA ĐƠN";
    bool flag = true;
    int temp = 0;
    
    do {
        X.nodeTam = NULL;
        gotoxy(18, 17); 
        cout<<"F1: Lui trang     F2: Qua trang";
        gotoxy(70,8); 
        cout<<"Số vật tư: "<<"    "; 
        gotoxy(81,8);
        cout<<dem + 1;
        Normal();
        
        int luachon = X.MenuNhap(menuChiTietHoaDon, temp, 6);
        temp = luachon;
        Normal();
        
        switch (luachon) {
            case 1: 
                gotoxy(49,10); 
                cout<<"                   ";
                gotoxy(49,10);
                getline(cin, Y.a3[dem].MAVT);
                if(!XuLyNhapLieu::chuanHoaMAVT(Y.a3[dem].MAVT)) {
                    temp = 0;
                    gotoxy(36,12); 
                    cout<< Y.a3[dem].soluong;
                    gotoxy(35,14);
                    cout<< Y.a3[dem].DONGIA;
                    gotoxy(31,16); 
                    cout<<Y.a3[dem].VAT;
                    break;
                } 
                gotoxy(49,10); 
                cout<< Y.a3[dem].MAVT;
                X.nodeTam = X.TimKiemTheoMaVT1(X.dsVatTu, Y.a3[dem].MAVT);
                if(X.nodeTam == NULL) {
                    BaoLoi("Mã VT không đúng định dạng", "hoặc không có trong kho","");
                    gotoxy(36,12); 
                    cout<< Y.a3[dem].soluong;
                    gotoxy(35,14);
                    cout<< Y.a3[dem].DONGIA;
                    gotoxy(31,16); 
                    cout<<Y.a3[dem].VAT;
                    temp = 0; 
                }    
                gotoxy(60, 10); 
                cout<<"                ";
                gotoxy(60, 10); 
                if(X.nodeTam != NULL) {
                    cout<<X.nodeTam->vt.TENVT;
                }
                break;
                
            case 2:  
                gotoxy(36,12); 
                cout<<"                   ";
                gotoxy(36,12);
                Y.a3[dem].soluong = XuLyNhapLieu::kiemTraSoNguyen();
                if (Y.a3[dem].soluong == -1) {
                    gotoxy(36,12); 
                    cout<< Y.a3[dem].soluong;
                    gotoxy(35,14);
                    cout<< Y.a3[dem].DONGIA;
                    gotoxy(31,16); 
                    cout<<Y.a3[dem].VAT;
                    temp = 1;  
                } 
                break;
                
            case 3:  
                gotoxy(35,14); 
                cout<<"                   ";
                gotoxy(35,14);
                Y.a3[dem].DONGIA = XuLyNhapLieu::kiemTraSoNguyen();
                if (Y.a3[dem].DONGIA == -1) {
                    gotoxy(36,12); 
                    cout<< Y.a3[dem].soluong;
                    gotoxy(35,14);
                    cout<< Y.a3[dem].DONGIA;
                    gotoxy(31,16); 
                    cout<<Y.a3[dem].VAT;
                    temp = 2;  
                } 
                break;
                
            case 4: 
                gotoxy(31,16); 
                cout<<"            ";
                gotoxy(31,16);
                Y.a3[dem].VAT = XuLyNhapLieu::kiemTraSoNguyen();
                if (Y.a3[dem].VAT == -1) {
                    gotoxy(36,12); 
                    cout<< Y.a3[dem].soluong;
                    gotoxy(35,14);
                    cout<< Y.a3[dem].DONGIA;
                    gotoxy(31,16); 
                    cout<<Y.a3[dem].VAT;
                    temp = 3;  
                } 
                break;
                
            case 20: // F1
                if(dem > 0) {
                    dem--; 
                    gotoxy(49,10); 
                    cout << Y.a3[dem].MAVT;
                    gotoxy(36,12); 
                    cout<< Y.a3[dem].soluong;
                    gotoxy(35,14);
                    cout<< Y.a3[dem].DONGIA;
                    gotoxy(31,16); 
                    cout<<Y.a3[dem].VAT; 
                    temp = 0; 
                } 
                break;
                
            case 21: // F2
                dem++;
                gotoxy(49,10); 
                cout << Y.a3[dem].MAVT;
                gotoxy(36,12); 
                cout<< Y.a3[dem].soluong;
                gotoxy(35,14);
                cout<< Y.a3[dem].DONGIA;
                gotoxy(31,16); 
                cout<<Y.a3[dem].VAT; 
                temp = 0; 
                break;
                
            case 5: 
                flag = false; 
                break;
                
            case 6: {
                int t = XacNhanLuaChon();
                if(t == 1) {
                    // Kiểm tra đủ hàng trước khi lưu
                    bool duHang = true;
                    for (int i = 0; i <= dem; i++) {
                        if (!X.KiemTraVatTu(Y.a3[i].MAVT, "X", Y.a3[i].soluong)) {
                            duHang = false;
                            break;
                        }
                    }

                    if (duHang) {
                        // Cập nhật kho
                        for (int i = 0; i <= dem; i++) {
                            X.CapNhatSoLuongVatTu(Y.a3[i].MAVT, "X", Y.a3[i].soluong);
                            Y.InsertBeginCTHD(Y.hoaDon.dscthd, Y.a3[i]);
                        }
                        
                        // Tính trị giá hóa đơn
                        Y.hoaDon.trigia = 0;
                        for (int i = 0; i <= dem; i++) {
                            Y.hoaDon.trigia += Y.a3[i].soluong * Y.a3[i].DONGIA * (1 + Y.a3[i].VAT/100.0);
                        }
                        
                        // Thêm hóa đơn vào nhân viên
                        Y.InsertBeginHD(Y.nhanVienHienTai->dshd, Y.hoaDon);
                        Y.hoaDonMoiNhat.SoHD = Y.hoaDon.SoHD;
                        
                        BaoLoi("Lập hóa đơn thành công!", "", "");
                        flag = false;
                    } else {
                        BaoLoi("Hủy hóa đơn do không đủ hàng trong kho!", "", "");
                    }  
                } else {
                    Normal();
                    for(int i = 0; i < 6; i++) {
                        gotoxy(35,12+i);
                        for (int j = 0; j < 35; j++) {
                            cout<<" ";
                        }
                    }
                    gotoxy(36,12); 
                    cout<< Y.a3[dem].soluong;
                    gotoxy(35,14);
                    cout<< Y.a3[dem].DONGIA;
                    gotoxy(31,16); 
                    cout<<Y.a3[dem].VAT;
                } 
                break;
            }
        } 
    } while(flag);
    XoaKhungNhap();
}

// ========== HÀM CASE 4 - LẬP HÓA ĐƠN ==========
void Case4(QuanLyVatTu &X, NhanVien &Y) {
    if(NhapMaNV(X, Y)) {
        char luaChon;
        int trangHienTai = 1;
        int viTriBatDau = 0;
        int viTriKetThuc = 20;
        
        do {
            system("cls");
            Normal();
            gotoxy(5, 1); 
            cout<<"Tên nhân viên: "<<Y.nhanVienHienTai->HO<<" "<<Y.nhanVienHienTai->TEN;
            VeKhungDanhSachHoaDonCase4();
            VeTieuDeDanhSachHoaDonCase4();
            
            Y.Display(Y.nhanVienHienTai->dshd, viTriBatDau, viTriKetThuc);
            int tongTrang = 0;
            if(Y.soLuongHoaDon % 20 == 0) {
                tongTrang = Y.soLuongHoaDon/20;
            } else {
                tongTrang = Y.soLuongHoaDon/20 + 1;
            }
            HighLight();
            gotoxy(90,2); 
            cout<<trangHienTai<<"/"<<tongTrang<<" ";
            Normal();
            
            luaChon = getch(); 
            if (luaChon == 0) 
                luaChon = getch(); 
                
            switch (luaChon) {
                case F1: {
                    VeKhungNhap();
                    gotoxy(40,8); 
                    cout <<"LẬP HÓA ĐƠN";
                    Y.TaoSoHDVaNgayLapHD(Y.hoaDon, Y.hoaDonMoiNhat);
                    bool flag = true;
                    int temp = 2;
                    gotoxy(33,10); 
                    cout<<Y.hoaDon.SoHD;
                    gotoxy(37,12); 
                    cout<<Y.hoaDon.NgayLapHoaDon.day<<"/"<<Y.hoaDon.NgayLapHoaDon.month
                        <<"/"<<Y.hoaDon.NgayLapHoaDon.year;
                        
                    do {
                        Normal();
                        int luachon = X.MenuNhap(menuLapHoaDon, temp, 5);
                        temp = luachon;
                        Normal();
                        
                        switch (luachon) {
                            case 1: 
                                break;
                            case 2: 
                                break;
                            case 3:  
                                gotoxy(32,14); 
                                cout<<"                   ";
                                gotoxy(32,14);
                                getline(cin, Y.hoaDon.Loai);
                                if(!XuLyNhapLieu::kiemTraLoaiHoaDon(Y.hoaDon.Loai)) {
                                    temp = 2;
                                    BaoLoi("Sai định dạng","","");
                                    gotoxy(37,12); 
                                    cout<<Y.hoaDon.NgayLapHoaDon.day<<"/"<<Y.hoaDon.NgayLapHoaDon.month
                                        <<"/"<<Y.hoaDon.NgayLapHoaDon.year;
                                    gotoxy(32,14); 
                                    cout<<Y.hoaDon.Loai;
                                } 
                                gotoxy(32,14);
                                cout<<Y.hoaDon.Loai;
                                break;
                            case 4: 
                                flag = false; 
                                break;
                            case 5: {
                                int t = XacNhanLuaChon();
                                if(t == 1) {
                                    NhapChiTietHoaDon(X, Y);
                                    flag = false;
                                } else {
                                    Normal();
                                    for(int i = 0; i < 6; i++) {
                                        gotoxy(35,12+i);
                                        for (int j = 0; j < 35; j++) {
                                            cout<<" ";
                                        }
                                    }
                                    gotoxy(37,12); 
                                    cout<<Y.hoaDon.NgayLapHoaDon.day<<"/"<<Y.hoaDon.NgayLapHoaDon.month
                                        <<"/"<<Y.hoaDon.NgayLapHoaDon.year;
                                }
                                break; 
                            }
                        } 
                    } while(flag); 
                    XoaKhungNhap();
                    break;
                }
                    
                case F2: {
                    VeKhungNhap(); 
                    gotoxy(40,8); 
                    cout <<"NHẬP MÃ HÓA ĐƠN";
                    int temp = 0;
                    string maHD;
                    bool flag = true;
                    
                    do {
                        int luachon = X.MenuNhap(menuNhapMaHoaDon, temp, 3);
                        temp = luachon;
                        Normal();
                        
                        switch (luachon) {
                            case 1: {
                                gotoxy(33,10); 
                                cout<<"                   ";
                                gotoxy(33,10);
                                getline(cin, maHD);
                                if(Y.TimKiemTheoMaHoaDon(maHD)) {      
                                    gotoxy(18,12); 
                                    cout<<"2. Loại: "<<Y.ptrHDHienTai->hd.Loai;
                                    gotoxy(18,14); 
                                    cout<<"3. Ngày lập hóa đơn: "<<Y.ptrHDHienTai->hd.NgayLapHoaDon.day<<"/"
                                        <<Y.ptrHDHienTai->hd.NgayLapHoaDon.month<<"/"
                                        <<Y.ptrHDHienTai->hd.NgayLapHoaDon.year;
                                } else {
                                    BaoLoi("Không tìm thấy mã HD!", "","");
                                    temp--;
                                } 
                                break;
                            }
                                
                            case 2: 
                                flag = false; 
                                break;
                                
                            case 3: 
                                if(Y.nhanVienTam.MANV == "" || !Y.TimKiemTheoMaHoaDon(maHD)) {
                                    BaoLoi("Hãy nhập hóa đơn cần xem","","");
                                    temp = 0;
                                    break;
                                }
                                int t = XacNhanLuaChon();
                                if(t == 1) {
                                    // Hiển thị chi tiết hóa đơn
                                    system("cls");
                                    gotoxy(5, 0); 
                                    cout<< "Mã hóa đơn: "<<maHD;
                                    gotoxy(5, 1); 
                                    cout<<"Loại hóa đơn: "<<Y.ptrHDHienTai->hd.Loai;
                                    gotoxy(5, 2); 
                                    cout<<"Ngày lập hóa đơn "<<Y.ptrHDHienTai->hd.NgayLapHoaDon.day<<"/"
                                        <<Y.ptrHDHienTai->hd.NgayLapHoaDon.month
                                        <<"/"<<Y.ptrHDHienTai->hd.NgayLapHoaDon.year;
                                    gotoxy(60,27); 
                                    cout<<"TỔNG TRỊ GIÁ HÓA ĐƠN: "<<Y.ptrHDHienTai->hd.trigia;
                                    
                                    char luaChonCT;
                                    int trangCT = 1;
                                    int viTriBatDauCT = 0;
                                    int viTriKetThucCT = 20;
                                    
                                    do {
                                        Normal();
                                        VeKhungChiTietHoaDon();
                                        VeTieuDeChiTietHoaDon();
                                        Y.DisplayCTHD(X, Y.ptrHDHienTai, viTriBatDauCT, viTriKetThucCT);
                                        
                                        int tongTrangCT = 0;
                                        if(Y.soLuongCTHD % 20 == 0) {
                                            tongTrangCT = Y.soLuongCTHD/20;
                                        } else {
                                            tongTrangCT = Y.soLuongCTHD/20 + 1;
                                        }
                                        HighLight();
                                        gotoxy(90,2); 
                                        cout<<trangCT<<"/"<<tongTrangCT<<" ";
                                        Normal();
                                        
                                        luaChonCT = getch();
                                        if (luaChonCT == 0) luaChonCT = getch();
                                        
                                        switch(luaChonCT) {
                                            case Up:
                                                if(trangCT > 1) {
                                                    viTriBatDauCT -= 20;
                                                    viTriKetThucCT -= 20;
                                                    trangCT--;
                                                }
                                                break;
                                            case Down:
                                                if(viTriKetThucCT < Y.soLuongCTHD) {
                                                    viTriBatDauCT += 20;
                                                    viTriKetThucCT += 20;
                                                    trangCT++;
                                                }
                                                break;
                                            case ESC:
                                                flag = false;
                                                break;
                                        }
                                    } while(luaChonCT != ESC);
                                    
                                    flag = false;
                                } else {
                                    Normal();
                                    for(int i = 0; i < 6; i++) {
                                        gotoxy(35,12+i);
                                        for (int j = 0; j < 35; j++) {
                                            cout<<" ";
                                        }
                                    }
                                    if(maHD != "") {
                                        gotoxy(18,12); 
                                        cout<<"2. Loại: "<<Y.ptrHDHienTai->hd.Loai;
                                        gotoxy(18,14); 
                                        cout<<"3. Ngày lập hóa đơn: "<<Y.ptrHDHienTai->hd.NgayLapHoaDon.day<<"/"
                                            <<Y.ptrHDHienTai->hd.NgayLapHoaDon.month<<"/"
                                            <<Y.ptrHDHienTai->hd.NgayLapHoaDon.year;
                                    } 
                                } 
                                break;
                        } 
                    } while(flag); 
                    XoaKhungNhap();
                    break;
                }

                case Up: {
                    if(trangHienTai <= 1) {
                        BaoLoi("Đang là trang đầu tiên!","","");
                        break;
                    } 
                    viTriBatDau -= 20; 
                    viTriKetThuc -= 20; 
                    trangHienTai -= 1; 
                    break;
                }
                    
                case Down: {
                    if(viTriKetThuc >= Y.soLuongHoaDon) {
                        BaoLoi("Đã là trang cuối cùng!","","");
                        break;
                    }
                    viTriBatDau += 20; 
                    viTriKetThuc += 20; 
                    trangHienTai += 1;
                    break;
                }
                    
                case ESC: { 
                    Y.GhiFile(); 
                    return;
                }
            }
        } while (true);
    }
}

// ========== HÀM XỬ LÝ NGÀY THÁNG ==========
int XuLyNgayThang(NhanVien& Y) {
    int n = XuLyNhapLieu::kiemTraSoNguyen();
    if (n == -1) {
        gotoxy(30,10); 
        cout<< Y.d1.day;
        gotoxy(33,10); 
        cout<< Y.d1.month;
        gotoxy(36,10); 
        cout<< Y.d1.year;
        gotoxy(30,12); 
        cout<< Y.d2.day;
        gotoxy(33, 12); 
        cout << Y.d2.month;
        gotoxy(36, 12); 
        cout<< Y.d2.year;
    }
    return n;
}

// ========== CASE 5 - THỐNG KÊ HÓA ĐƠN ==========
void Case5(QuanLyVatTu& X, NhanVien &Y) {
    VeKhungNhap();
    gotoxy(40,8); 
    cout <<"NHẬP NGÀY THÁNG";
    bool flag = true;
    int temp = 0;
    gotoxy(30,10); 
    cout<<"0 /0 /0    ";
    gotoxy(31,12); 
    cout<<"0 /0 /0    ";
    
    do {
        Normal();
        int luachon = X.MenuNhap(menuNgayThang, temp, 4);
        temp = luachon;
        Normal();
        
        switch (luachon) {
            case 1: 
                gotoxy(30,10); 
                cout<<"0 /0 /0              ";
                NhapLaiNgay11:
                gotoxy(30,10); 
                Y.d1.day = XuLyNgayThang(Y);
                if(Y.d1.day == -1 || Y.d1.day > 31) {
                    goto NhapLaiNgay11;
                } 
                
                NhapLaiThang12:
                gotoxy(33, 10); 
                Y.d1.month = XuLyNgayThang(Y);
                if (Y.d1.month == -1 || Y.d1.month > 12) {
                    goto NhapLaiThang12;
                } 
                
                NhapLaiNam13:
                gotoxy(36, 10);
                Y.d1.year = XuLyNgayThang(Y);
                if(Y.d1.year == -1) {
                    goto NhapLaiNam13;
                }
                break;
                
            case 2: 
                gotoxy(31,12); 
                cout<<"0 /0 /0            ";
                NhapLaiNgay21:
                gotoxy(31,12); 
                Y.d2.day = XuLyNgayThang(Y);
                if(Y.d2.day == -1 || Y.d2.day > 31) {
                    goto NhapLaiNgay21;
                } 
                
                NhapLaiThang22:
                gotoxy(34, 12); 
                Y.d2.month = XuLyNgayThang(Y);
                if (Y.d2.month == -1 || Y.d2.month > 12) {
                    goto NhapLaiThang22;
                } 
                
                NhapLaiNam23:
                gotoxy(37, 12);
                Y.d2.year = XuLyNgayThang(Y);
                if(Y.d2.year == -1) {
                    goto NhapLaiNam23;
                }
                break;
                
            case 3: 
                flag = false; 
                break;
                
            case 4: {
                int t = XacNhanLuaChon();
                if(t == 1) {
                    Y.ThongKeHoaDon(Y.d1, Y.d2);
                    
                    // Hiển thị kết quả thống kê
                    char luaChonTK;
                    int trangTK = 1;
                    int viTriBatDauTK = 0;
                    int viTriKetThucTK = 20;
                    
                    do {
                        system("cls");
                        gotoxy(5, 1); 
                        cout << "Từ ngày: "<<Y.d1.day<<"/" <<Y.d1.month<<"/"<< Y.d1.year;
                        gotoxy(5, 2); 
                        cout << "Đến ngày: "<<Y.d2.day<<"/" <<Y.d2.month<<"/"<< Y.d2.year;
                        
                        Normal();
                        VeKhungThongKeHoaDonCase5();
                        VeTieuDeThongKeHoaDon();
                        
                        Y.DisplayTKHoaDon(viTriBatDauTK, viTriKetThucTK);
                        
                        int tongTrangTK = 0;
                        if(Y.dem3 % 20 == 0) {
                            tongTrangTK = Y.dem3/20;
                        } else {
                            tongTrangTK = Y.dem3/20 + 1;
                        }
                        HighLight();
                        gotoxy(90,2); 
                        cout<<trangTK<<"/"<<tongTrangTK<<" ";
                        Normal();
                        
                        luaChonTK = getch();
                        if (luaChonTK == 0) luaChonTK = getch();
                        
                        switch(luaChonTK) {
                            case Up:
                                if(trangTK > 1) {
                                    viTriBatDauTK -= 20;
                                    viTriKetThucTK -= 20;
                                    trangTK--;
                                }
                                break;
                            case Down:
                                if(viTriKetThucTK < Y.dem3) {
                                    viTriBatDauTK += 20;
                                    viTriKetThucTK += 20;
                                    trangTK++;
                                }
                                break;
                            case ESC:
                                flag = false;
                                return;
                        }
                    } while(true);
                    
                    flag = false;
                } else {
                    Normal();
                    for(int i = 0; i < 6; i++) {
                        gotoxy(35,12+i);
                        for (int j = 0; j < 35; j++) {
                            cout<<" ";
                        }
                    }
                    gotoxy(40,12); 
                    cout<< Y.d2.day; 
                    cout<<Y.d2.month; 
                    cout<< Y.d2.year;
                } 
                break;
            }
        } 
    } while (flag);
    XoaKhungNhap();
}

// ========== CASE 6 - TOP 10 VẬT TƯ ==========
void Case6(QuanLyVatTu& X, NhanVien &Y) {
    VeKhungNhap();
    gotoxy(40,8); 
    cout <<"NHẬP NGÀY THÁNG";
    bool flag = true;
    int temp = 0;
    gotoxy(30,10); 
    cout<<"0 /0 /0    ";
    gotoxy(31,12); 
    cout<<"0 /0 /0    ";
    
    do {
        Normal();
        int luachon = X.MenuNhap(menuNgayThang, temp, 4);
        temp = luachon;
        Normal();
        
        switch (luachon) {
            case 1: 
                gotoxy(30,10); 
                cout<<"0 /0 /0              ";
                NhapLaiNgay11_6:
                gotoxy(30,10); 
                Y.d1.day = XuLyNgayThang(Y);
                if(Y.d1.day == -1 || Y.d1.day > 31) {
                    goto NhapLaiNgay11_6;
                } 
                
                NhapLaiThang12_6:
                gotoxy(33, 10); 
                Y.d1.month = XuLyNgayThang(Y);
                if (Y.d1.month == -1 || Y.d1.month > 12) {
                    goto NhapLaiThang12_6;
                } 
                
                NhapLaiNam13_6:
                gotoxy(36, 10);
                Y.d1.year = XuLyNgayThang(Y);
                if(Y.d1.year == -1) {
                    goto NhapLaiNam13_6;
                }
                break;
                
            case 2: 
                gotoxy(31,12); 
                cout<<"0 /0 /0            ";
                NhapLaiNgay21_6:
                gotoxy(31,12); 
                Y.d2.day = XuLyNgayThang(Y);
                if(Y.d2.day == -1 || Y.d2.day > 31) {
                    goto NhapLaiNgay21_6;
                } 
                
                NhapLaiThang22_6:
                gotoxy(34, 12); 
                Y.d2.month = XuLyNgayThang(Y);
                if (Y.d2.month == -1 || Y.d2.month > 12) {
                    goto NhapLaiThang22_6;
                } 
                
                NhapLaiNam23_6:
                gotoxy(37, 12);
                Y.d2.year = XuLyNgayThang(Y);
                if(Y.d2.year == -1) {
                    goto NhapLaiNam23_6;
                }
                break;
                
            case 3: 
                flag = false; 
                break;
                
            case 4: {
                int t = XacNhanLuaChon();
                if(t == 1) {
                    Y.ThongKeHoaDon(Y.d1, Y.d2);
                    Y.TinhGiaTri(X);
                    
                    // Hiển thị Top 10
                    char luaChonTop;
                    int trangTop = 1;
                    int viTriBatDauTop = 0;
                    int viTriKetThucTop = 10;
                    
                    do {
                        system("cls");
                        gotoxy(5, 1); 
                        cout << "Từ ngày: "<<Y.d1.day<<"/" <<Y.d1.month<<"/"<< Y.d1.year;
                        gotoxy(5, 2); 
                        cout << "Đến ngày: "<<Y.d2.day<<"/" <<Y.d2.month<<"/"<< Y.d2.year;
                        
                        Normal();
                        VeKhungTop10VatTuCase6();
                        VeTieuDeTop10VatTu();
                        
                        Y.DisplayTop10(viTriBatDauTop, viTriKetThucTop);
                        
                        HighLight();
                        gotoxy(90,2); 
                        cout<<trangTop<<"/"<<"1"<<" ";
                        Normal();
                        
                        luaChonTop = getch();
                        if (luaChonTop == 0) luaChonTop = getch();
                        
                        switch(luaChonTop) {
                            case ESC:
                                flag = false;
                                return;
                        }
                    } while(true);
                    
                    flag = false;
                } else {
                    Normal();
                    for(int i = 0; i < 6; i++) {
                        gotoxy(35,12+i);
                        for (int j = 0; j < 35; j++) {
                            cout<<" ";
                        }
                    }
                    gotoxy(40,12); 
                    cout<< Y.d2.day; 
                    cout<<Y.d2.month; 
                    cout<< Y.d2.year;
                } 
                break;
            }
        } 
    } while (flag);
    XoaKhungNhap();
}

// ========== CASE 7 - DOANH THU THEO THÁNG ==========
void Case7(QuanLyVatTu& X, NhanVien &Y) {
    VeKhungNhap();
    gotoxy(40,8); 
    cout <<"THỐNG KÊ DOANH THU THEO NĂM";
    bool flag = true;
    int temp = 0;
    
    do {
        Normal();
        int luachon = X.MenuNhap(menuNam, temp, 3);
        temp = luachon;
        Normal();
        
        switch (luachon) {
            case 1: 
                gotoxy(31,10); 
                cout<<"                   ";
                gotoxy(31,10);
                Y.d1.year = XuLyNhapLieu::kiemTraSoNguyen();
                if(Y.d1.year == -1) {
                    temp = 0;
                } 
                break;
                
            case 2: 
                flag = false; 
                break;
                
            case 3: {
                Y.TimTheoNam(Y.d1.year);
                int t = XacNhanLuaChon();
                if(t == 1) {
                    // Hiển thị doanh thu theo tháng
                    char luaChonDT;
                    int trangDT = 1;
                    int viTriBatDauDT = 0;
                    int viTriKetThucDT = 12;
                    
                    do {
                        system("cls");
                        Normal();
                        VeKhungDoanhThuThangCase7();
                        VeTieuDeDoanhThuThang();
                        
                        HighLight();
                        gotoxy(71, 1); 
                        cout << Y.d1.year;
                        Normal();
                        
                        Y.DisplayDoanhThuThang(viTriBatDauDT, viTriKetThucDT);
                        
                        HighLight();
                        gotoxy(90,2); 
                        cout<<trangDT<<"/"<<"1"<<" ";
                        Normal();
                        
                        luaChonDT = getch();
                        if (luaChonDT == 0) luaChonDT = getch();
                        
                        switch(luaChonDT) {
                            case Up:
                                if(trangDT > 1) {
                                    viTriBatDauDT -= 12;
                                    viTriKetThucDT -= 12;
                                    trangDT--;
                                }
                                break;
                            case Down:
                                if(viTriKetThucDT < 12) {
                                    viTriBatDauDT += 12;
                                    viTriKetThucDT += 12;
                                    trangDT++;
                                }
                                break;
                            case ESC:
                                flag = false;
                                return;
                        }
                    } while(true);
                    
                    flag = false;
                } else {
                    Normal();
                    for(int i = 0; i < 6; i++) {
                        gotoxy(35,12+i);
                        for (int j = 0; j < 35; j++) {
                            cout<<" ";
                        }
                    }
                } 
                break;
            }
        } 
    } while (flag);
    XoaKhungNhap();
}

// ========== HÀM MAIN ĐẦY ĐỦ ==========
int main() {
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
    
    QuanLyVatTu quanLyVT("DanhSachVatTu.txt");
    NhanVien nhanVien("DanhSachNhanVien.txt", "Danhsachhoadon.txt", "Danhsachcautruchoadon.txt");
    
    int luaChon = 0;
    do {
        luaChon = HienThiMenuChinh(menuchinh, SO_MUC_MENU);
        Normal();
        
        switch (luaChon) {
            case 1: 
                Case1(quanLyVT);
                break;
            case 2: 
                Case2(quanLyVT);
                break;
            case 3: 
                Case3(quanLyVT, nhanVien);
                break;
            case 4: 
                Case4(quanLyVT, nhanVien);
                break;
            case 5: 
                Case5(quanLyVT, nhanVien);
                break;
            case 6: 
                Case6(quanLyVT, nhanVien);
                break;
            case 7: 
                Case7(quanLyVT, nhanVien);
                break;
            case 8: {
                nhanVien.GhiFile();
                quanLyVT.GhiFile();
                cout << "\n\n\t\t\tThoát chương trình!" << endl;
                cout << "\t\t\tCảm ơn bạn đã sử dụng phần mềm!" << endl;
                Sleep(2000);
                return 0;
            }
        }
    } while (true);
    
    return 0;
}
    
    

