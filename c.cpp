#include <bits/stdc++.h>
#include "D:/mylib.h"
using namespace std;
const int MAX_NhanVien = 500;
const int MAX_VatTu = 1000;
const int so_item = 8;
const int dong =9;
const int cot =10;
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

string thucdon[so_item] = {"1. In danh sách vật tư theo mã số        ",
			               "2. In danh sách vật tư theo tên          ", 
                           "3. In danh sách nhân viên theo tên       ",
                           "4. Lập hóa đơn      ",
                           "5. Thống kê hóa đơn theo ngày tháng    ",
                           "6. Thống kê Top 10 vật tư có giá cao nhất     ",
                           "7. Thống kê doanh thu của từng tháng theo năm       ",
						   "8. Kết thúc chương trình             "};
string nhapvt[6] = {"1. Nhập mã vật tư(VD: VT0099):","2. Nhập tên vật tư:", "3. Nhập đơn vị tính:","4. Nhập số lượng tồn(0-9):",
 " Hủy "," Xác nhận "};
string xoavt[3] = {"Nhập mã vật tư(VD: VT0099):"," Hủy "," Xác nhận "};
string suavt[5] = {"Nhập mã vật tư(VD: VT0099):", "", ""," Hủy "," Xác nhận "};
string laphoadon[5] = {"1. Số hóa đơn:", "2. Ngày lập hóa đơn:","3. Loại hóa đơn:"," Hủy "," Xác nhận "};
string chitiethoadon[6] = {"1. Nhập mã vật tư(VD: VT0099):","2. Nhập số lượng:", "3. Nhập đơn giá:","4. Nhập VAT:",
    " Hủy "," Xác nhận "};
string nhaphd[5] = {"1. Mã hóa đơn:","2. Ngày tháng năm:", "3. Nhập loại:",
 " Hủy "," Xác nhận "};
string nhapmahd[3] = {"1. Mã hóa đơn:"," Hủy "," Xác nhận "};
string ngaythang[4] = {"1. Từ ngày:", "2. Đến ngày:",  " Hủy ", " Xác nhận "};
string nam[3] = {"1. Nhập năm:",  " Hủy ", " Xác nhận "};
string xoanv[3] = {"1. Nhập mã nhân viên(VD: NV099):"," Hủy "," Xác nhận "};
string suanv[3] = {"1. Nhập mã nhân viên:",  " Hủy ", " Xác nhận "};

void Normal () {
	SetColor(15); // white 
	SetBGColor(0);// black
}
void HighLight () {
	SetColor(15);
	SetBGColor(1); // blue
}
void taokhung() {
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

void taoghichumenu() {
    gotoxy(8, 7);
    for(int i = 0; i <85; i++) {
        cout << "═";
    }
       SetColor(15);
    SetBGColor(9);
    gotoxy(35,5);
    cout <<"     QUẢN LÝ VẬT TƯ     ";;
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
void taokhungdanhsach() {
    taokhung();
    SetColor(9);
    gotoxy(15, 4); cout<<"║";
    gotoxy(38, 4); cout<<"║";
    gotoxy(61, 4);cout<<"║";
    Normal();
    gotoxy(8,4); cout<<" MãVT";gotoxy(17, 4); cout<<" Tên vật tư";
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
void taokhungdanhsach2() {
    taokhung();
    SetColor(9);
    gotoxy(15, 4); cout<<"║";
    gotoxy(41, 4); cout<<"║";
    gotoxy(63, 4);cout<<"║";
    gotoxy(79, 4);cout<<"║";
    Normal();
    gotoxy(8,4); cout<<"Mã VT";gotoxy(17, 4); cout<<"Tên vật tư";
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
void taokhungdanhsach3() {
    taokhung();
    SetColor(9);
    gotoxy(22, 4); cout<<"║";
    gotoxy(35, 4); cout<<"║";
    gotoxy(50, 4);cout<<"║";
    gotoxy(70, 4);cout<<"║";
    Normal();
    gotoxy(8,4); cout<<" Mã HĐ";gotoxy(24, 4); cout<<" Loại";
    gotoxy(37, 4);cout<<" Ngày tháng"; gotoxy(52,4); cout<<" Tên nhân viên";
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
void taokhungdanhsach4() {
    taokhung();
    SetColor(9);
    gotoxy(30, 4); cout<<"║"; gotoxy(60, 4); cout<<"║";
    Normal();
    gotoxy(12,4); cout<<" Mã vật tư";gotoxy(34, 4); cout<<"Tên vật tư";gotoxy(63, 4); cout<<" Tổng doanh thu của vật tư";
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
void taokhungdanhsach5() {
    taokhung();
    SetColor(9);
    gotoxy(38, 4); cout<<"║";
    Normal();
    gotoxy(15,4); cout<<" Tháng ";gotoxy(45, 4); cout<<" Doanh thu";
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
void taokhungdanhsachhoadon() {
    taokhung();
    SetColor(9);
    gotoxy(25, 4); cout<<"║";
    gotoxy(54, 4);cout<<"║";
    Normal();
    gotoxy(8,4); cout<<" Mã Hóa Đơn";gotoxy(27, 4); cout<<" Loại hóa đơn ";
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
void taoghichumaso() {
    HighLight();
    gotoxy(40,1); cout<<"   DANH SÁCH VẬT TƯ   ";
    Normal();
    gotoxy(9, 27); cout<<"F1: Thêm VT    F2: Xóa VT    F3: Chỉnh sửa VT    ⭡: Len    ⭣: Xuong    ESC: Để thoát";
}
void taoghichumaso2() {
    HighLight();
    gotoxy(40,1); cout<<"  CHI TIẾT HÓA ĐƠN  ";
    Normal();
    gotoxy(9, 27); cout<<"  ⭡: Len    ⭣: Xuong    ESC: Để thoát";
}
void taoghichumaso3() {
    HighLight();
    gotoxy(40,1); cout<<"  THỐNG KÊ HÓA ĐƠN  ";
    Normal();
    gotoxy(9, 27); cout<<"  ⭡: Len    ⭣: Xuong    ESC: Để thoát";
}
void taoghichumaso4() {
    HighLight();
    gotoxy(37,1); cout<<"  THỐNG KÊ TOP 10 VẬT TƯ CÓ DOANH THU CAO NHÁT   ";
    Normal();
    gotoxy(9, 27); cout<<"  ⭡: Len    ⭣: Xuong    ESC: Để thoát";
}
void taoghichumaso5() {
    HighLight();
    gotoxy(40,1); cout<<"  BẢNG THỐNG KÊ DOANH THU NĂM:      ";
    Normal();
    gotoxy(9, 27); cout<<"  ⭡: Len    ⭣: Xuong    ESC: Để thoát";
}
void taoghichumaso1() {
    SetColor(9);
    gotoxy(15, 4); cout<<"║";
    gotoxy(38, 4); cout<<"║";
    gotoxy(61, 4);cout<<"║";
    Normal();
    gotoxy(8,4); cout<<" MãNV";  gotoxy(17, 4);cout<<" Họ nhân viên";gotoxy(40, 4); cout<<" tên nhân viên"; 
    gotoxy(63, 4); cout<< " Giới tính      ";
    HighLight();
    gotoxy(40,1); cout<<"   DANH SÁCH NHÂN VIÊN   ";
    Normal();
    gotoxy(9, 27); cout<<"F1: Thêm NV    F2: Xóa NV    F3: Chỉnh sửa NV    ⭡: Len    ⭣: Xuong    ESC: Để thoát";
}
void taoghichumasocase4() {
    HighLight();
    gotoxy(40,1); cout<<"   DANH SÁCH HÓA ĐƠN   ";
    Normal();
    gotoxy(9, 27); cout<<"F1: Lập hóa đơn    F2: Xem chi tiết hóa đơn    ⭡: Len    ⭣: Xuong    ESC: Để thoát";
}
void ghichucase2() {
     HighLight();
    gotoxy(40,1); cout<<"   DANH SÁCH VẬT TƯ SẮP XẾP THEO TÊN   ";
    Normal();
    gotoxy(9, 27); cout<<"⭡: Len    ⭣: Xuong    ESC: Để thoát";
}
void huykhungnhap() {
    for(int i = 0 ;i < 14;i++) {
        gotoxy(17,7+i);
        for(int j = 0; j < 68;j++){
            cout<<" ";
        }
    }
}
void khungnhap() {
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
int MenuDong(string td[so_item]){
  Normal(); system("cls");
  int chon =0;
  int i; 
  for ( i=0; i< so_item ; i++)
  { gotoxy(cot, dong +i);
    cout << td[i];
  }
  taokhung();
  taoghichumenu();
  HighLight();
  gotoxy(cot,dong+chon);
  cout << td[chon];
  char kytu;
do {
  kytu = getch();
  if (kytu==0) kytu = getch();
  switch (kytu) {
    case Up :if (chon > 0)
  			  {
  		        Normal(); 
              	gotoxy(cot,dong+chon);
              	cout << td[chon];
              	chon --;
              	HighLight();
              	gotoxy(cot,dong+chon);
              	cout << td[chon];
  				
  			  }
  			  break;
  	case Down :if (chon <so_item-1)
  			  {
  		        Normal();
              	gotoxy(cot,dong+chon);
              	cout << td[chon];
              	chon ++;
              	HighLight();
              	gotoxy(cot,dong+chon);
              	cout << td[chon];
  				
  			  }
  			  break;
  	case Enter : return chon+1;
  }  // end switch
  } while (1);
}
void khungxacnhan() {
    for(int i = 0; i < 6; i++) {
        gotoxy(35,12+i);
        for (int j = 0; j < 35; j++) {
            cout<<" ";
        }
    }gotoxy(35,12); 
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
void BaoLoi (string s1, string s2, string s3){
    khungxacnhan();
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

int xacnhanluachon() {
    khungxacnhan();
     gotoxy(36,13); cout<<"Bạn có muốn xác nhận lựa chọn";
    gotoxy(36,14);
    for(int i = 0; i <30; i++) {
        cout << "═";
    }
    gotoxy(37,16); string s = "  Hủy  "; string s2 = "  Xác Nhận  ";
    cout<< s<<"        "; HighLight(); cout<< s2;
    Normal();
    int chon = 1;
   do{ char luachon = getch();
    if (luachon==0) luachon = getch();
    switch(luachon) {
        case Left :if (chon > 0)
  			  {
  		        Normal(); 
              	gotoxy(52,16);
              	cout << s2;
              	chon --;
              	HighLight();
              	gotoxy(37,16);
              	cout << s;
  				
  			  }
  			  break;
  	case Right :if (chon < 2)
  			  {
  		        Normal();
              	gotoxy(37,16);
              	cout << s;
              	chon ++;
              	HighLight();
              	gotoxy(52,16);
              	cout << s2;
  				
  			  }
  			  break;
  	case Enter : if(chon == 0) {
        return 0;
    } else {
       return 1;
    }

    }
}while(true);

    }
class XuLyNhapLieu {
public:
struct Date{
    int day = 0;
    int month = 0;
    int year = 0;
};
    // chuyen ky tu thuong -> hoa
    static char toUpper(char c) {
        if (c >= 'a' && c <= 'z')
            return c - 32;
        return c;
    }

    // chuan hoa ma vat tu VTxxxx
 static bool chuanHoaMAVT(string& input) {
        // chuyen sang chu hoa
        for (int i = 0; i < input.length(); i++)
            input[i] = toUpper(input[i]);

        // kiem tra VT
        if (input.length() < 2 || input[0] != 'V' || input[1] != 'T') {
            BaoLoi("Mã vật tư phải bắt đầu bằng","VT.","");
            return false;
        }

        // lay phan so
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

        // tao lai dang VTxxxx
        string result = "VT";
        if (num < 10) result += "000";
        else if (num < 100) result += "00";
        else if (num < 1000) result += "0";
        result += to_string(num);

        input = result;
        return true;
    }

   static bool chuanHoaMaNV(string &maNV) {
    // 1. Chuẩn hóa sang chữ HOA
    for (int i = 0; i < maNV.length(); i++) {
        if (maNV[i] >= 'a' && maNV[i] <= 'z')
            maNV[i] -= 32;
    }

    // 2. Phải đúng 5 ký tự
    if (maNV.length() != 5) {
        BaoLoi("Loi: Ma nhan vien phai co"," dang NVxxx (VD: NV001)","");
        return false;
    }

    // 3. Hai ký tự đầu phải là NV
    if (maNV[0] != 'N' || maNV[1] != 'V') {
        BaoLoi("Loi: Ma nhan vien phai ","bat dau bang NV","");
        return false;
    }

    // 4. Ba ký tự sau phải là số
    for (int i = 2; i < 5; i++) {
        if (maNV[i] < '0' || maNV[i] > '9') {
            BaoLoi("Loi: 3 ky tu sau NV phai la so","","");
            return false;
        }
    
    }

    // 5. Không cho NV000
    int so = (maNV[2] - '0') * 100 +
             (maNV[3] - '0') * 10 +
             (maNV[4] - '0');

    if (so == 0) {
        BaoLoi("Ma nhan vien khong duoc ","la NV000","");
        return false;
    }

    return true; // hợp lệ
}
   static bool chuanHoaTen(string& s) {
    if (s.length() == 0) {
        BaoLoi("Ten rong!", "", "");
        return false;
    }

    // 1. Xóa khoảng trắng đầu
    while (!s.empty() && s[0] == ' ')
        s.erase(0, 1);

    // 2. Xóa khoảng trắng cuối
    while (!s.empty() && s[s.length() - 1] == ' ')
        s.erase(s.length() - 1, 1);

    // 3. Xóa khoảng trắng thừa ở giữa
    for (int i = 0; i + 1 < s.length(); i++) {
        if (s[i] == ' ' && s[i + 1] == ' ') {
            s.erase(i, 1);
            i--;
        }
    }

    // 4. Chỉ kiểm tra ký tự cơ bản (không kiểm tra tiếng Việt phức tạp)
    for (int i = 0; i < s.length(); i++) {
        char c = s[i];
        // Cho phép: chữ cái, khoảng trắng, dấu nháy đơn (cho tên như O'Connor)
        if (!((c >= 'A' && c <= 'Z') ||
              (c >= 'a' && c <= 'z') ||
              c == ' ' ||
              c == '\'' ||
              c == '.' || // cho phép chấm
              (unsigned char)c >= 128)) { // cho phép ký tự UTF-8 (tiếng Việt)
            BaoLoi("Ten chua ky tu khong hop le!", "", "");
            return false;
        }
    }

    // 5. Chuyển đổi về dạng chuẩn: viết hoa chữ cái đầu mỗi từ
    bool dauTu = true;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == ' ') {
            dauTu = true;
        } else if (dauTu) {
            // Chỉ viết hoa nếu là chữ cái tiếng Anh không dấu
            if (s[i] >= 'a' && s[i] <= 'z') {
                s[i] = s[i] - 32;
            }
            dauTu = false;
        } else {
            // Chỉ viết thường nếu là chữ cái tiếng Anh không dấu
            if (s[i] >= 'A' && s[i] <= 'Z') {
                s[i] = s[i] + 32;
            }
        }
    }

    return true;
}
    // kiem tra loai hoa don N / X
    static bool kiemTraLoaiHoaDon(string& Loai) {
        char loai = Loai[0];
        if (loai >= 'a' && loai <= 'z'){
            loai -= 32;}
            Loai[0] = loai;

        return (Loai[0] == 'N' || Loai[0] == 'X');
    }
    static bool chuanHoaGioiTinh(string &phai) {
    // 1. Bỏ khoảng trắng đầu/cuối (nếu có)
    while (phai.length() > 0 && phai[0] == ' ')
        phai.erase(0, 1);
    while (phai.length() > 0 && phai[phai.length() - 1] == ' ')
        phai.erase(phai.length() - 1, 1);

    // 2. Chuẩn hóa hết về chữ thường
    for (int i = 0; i < phai.length(); i++) {
        if (phai[i] >= 'A' && phai[i] <= 'Z')
            phai[i] += 32;
    }

    // 3. Kiểm tra hợp lệ
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
    static int ktrasonguyen() {
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
        } return n;
    }
    static string bangChuCaiTV() {
        return "aăâbcdđeêghiklmnoôơpqrstuưvxy";
    }

    static int viTriChu(string c) {
        if (c.length() == 0) return 100;

        char ch = c[0];
        if (ch >= 'A' && ch <= 'Z')
            ch += 32;

        string bang = bangChuCaiTV();
        for (int i = 0; i < bang.length(); i++) {
            if (bang[i] == ch)
                return i;
        }
        return 100; 
    }

    static int soSanhChuoiTV(string a, string b) {
        int na = a.length();
        int nb = b.length();
        int n = (na < nb) ? na : nb;

        for (int i = 0; i < n; i++) {
            string ca = "";
            string cb = "";
            ca += a[i];
            cb += b[i];

            int va = viTriChu(ca);
            int vb = viTriChu(cb);

            if (va < vb) return -1;
            if (va > vb) return 1;
        }

        if (na < nb) return -1;
        if (na > nb) return 1;
        return 0;
    }
    static long long quyDoiNgay(int d, int m, int y) {
    return (long long)y * 10000 + m * 100 + d;
}
};


class lopvattu {
    private:
    string filevattu;

struct VatTu{
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
treeVT dsvt = NULL;
int arr[MAX_VatTu];
treeVT a[MAX_VatTu]; 
int index = 0;
int kt = 0;
VatTu vattu = {"", "", "", -1};
treeVT temptree = NULL;

void Taomanga(treeVT a[]) {
    for(int i = 0; i < MAX_VatTu; i++) {
        a[i] = NULL;
    }
}

lopvattu(string Filevattu) {
    filevattu = Filevattu;
    Taomanga(a);
    dsvt = taocaynhiphancanbang(1, MAX_VatTu);
    Cap_nhat_do_cao(dsvt);
    mofile();
   }
void nvvattu(string vattu, string loai, int soluong) {
    temptree = NULL;
    temptree = Tim_kiem_theo_maVT(dsvt, vattu);
    if(temptree!=NULL) {
    if(loai == "N") {
        temptree->vt.SoLuongTon += soluong; 
    } else {
        
            temptree->vt.SoLuongTon-=soluong;
       
    } 
} 
}
bool ktravatu(string vattu, string loai, int soluong) {
    temptree = NULL;
    temptree = Tim_kiem_theo_maVT(dsvt, vattu);
    if(temptree!=NULL) {
        if(temptree->vt.SoLuongTon < soluong) {
            BaoLoi("Kho không đủ số lượng","","");
            return false;
        }
    } return true;
}

int Cap_nhat_do_cao(treeVT root) {
    if (root == nullptr) return -1;
    int height_left = Cap_nhat_do_cao(root->left);
    int height_right = Cap_nhat_do_cao(root->right);
    root->vt.height =  1 + max(height_left, height_right);
    return root->vt.height;
}

 treeVT taocaynhiphancanbang(int start, int end)  {
        int mid = (start + end)/2;
            if(start > end) {
                return nullptr;
           }
                treeVT root = new nodeVT;
                string ma = string(4 - to_string(mid).length(), '0') + to_string(mid);
                root -> vt.MAVT = "VT" + ma;
                root->vt.TENVT = "";
                root->vt.DVT = "";
                root->vt.SoLuongTon = 0;  
                root->left = taocaynhiphancanbang(start, mid -1);
                root->right = taocaynhiphancanbang(mid + 1, end);
                return root;
            }

void Duyet_cay_vao_Manng_LNR(treeVT root) {
 if(root!=NULL){ 
  Duyet_cay_vao_Manng_LNR(root->left);
  if(root->vt.TENVT != "") {
   a[index++] = root;}
  Duyet_cay_vao_Manng_LNR(root->right); 
 } 
} 

treeVT Tim_kiem_theo_maVT(treeVT root, string mavt){ 
    if (root == NULL || root->vt.MAVT == mavt) 
        return root;
    if (root->vt.MAVT < mavt) 
        return Tim_kiem_theo_maVT(root->right, mavt);
        return Tim_kiem_theo_maVT(root->left, mavt); 
 
}
treeVT Tim_kiem_theo_maVT1(treeVT root, string mavt){ 
    if (root == NULL || (root->vt.MAVT == mavt&&root->vt.TENVT!="")) 
        return root;
    if (root->vt.MAVT < mavt) 
        return Tim_kiem_theo_maVT1(root->right, mavt);
        return Tim_kiem_theo_maVT1(root->left, mavt); 
 
}

void nhapVT(VatTu vattu) {
    treeVT temp = Tim_kiem_theo_maVT(dsvt, vattu.MAVT);
       if(temp != NULL) {
            temp->vt.MAVT = vattu.MAVT;
             temp ->vt.TENVT = vattu.TENVT;
        temp ->vt.DVT = vattu.DVT;
        temp ->vt.SoLuongTon = vattu.SoLuongTon;
        } }
            


int menunhapVT(string s[], int temp, int n) {
    gotoxy(18, 19); cout<<"Enter: Để nhập.";

    if (temp == n) {
        temp --;
    }
  int chon = temp;
    gotoxy(18,10);
    int a=0;
    for (int i = 0; i < n-2;i++) {
        gotoxy(18,10+a); cout<<s[i]<<endl;
        a+=2;
    }
        gotoxy(60,19); cout<<s[n-2]<<"          "<<s[n-1];
  HighLight();
  if(chon == 0) {
    gotoxy(18,10);
  cout << s[chon];
  } else if(chon == n - 2||chon == n-1) {
    if(chon == n-2) {
    	gotoxy(60,19);
    } else {
        gotoxy(75, 19);
    }
              	cout << s[chon];} 
    else { gotoxy(18,10+chon*2);
  cout << s[chon];}
  char kytu;
do {
  kytu = getch();
  if (kytu==0) kytu = getch();
  switch (kytu) {

    case Up :if (chon >0&&chon!=n-1)
  			  {
  		        Normal(); 
                if(chon == n-2) {
                    gotoxy(60,19);

                } else {
              	gotoxy(18,10+chon*2);}
              	cout << s[chon];
              	chon -=1;
              	HighLight();
              	gotoxy(18,10+chon*2);
              	cout << s[chon];
  			  }
  			  break;
  	case Down :if (chon <n-2)
  			  {
  		        Normal();
              	gotoxy(18,10+chon*2);
              	cout << s[chon];
              	chon +=1;
              	HighLight();
                if(chon == n - 2) {
                    gotoxy(60,19);

                } else {
              	gotoxy(18,10+chon*2);}
              	cout << s[chon];
  				
  			  }
  			  break;
    case Right : if(chon == n - 2) {
        Normal();
              	gotoxy(60,19);
              	cout << s[chon];
              	chon +=1;
              	HighLight();
              	gotoxy(75,19);
              	cout << s[chon];


    } break;
    case Left : if(chon == n - 1) {
          Normal();
              	gotoxy(75,19);
              	cout << s[chon];
              	chon -=1;
              	HighLight();
              	gotoxy(60,19);
              	cout << s[chon];
    } break;
    case F1 : return 20;
    case F2 : return 21;
  	case Enter : 
    return  chon +1;
  }  // end switch
  } while (1);
}
   


void XoaVT(treeVT temp) { 
        temp->vt.TENVT = "";
        temp ->vt.DVT = "";
        temp->vt.SoLuongTon = 0;
}

void ChinhsuaVT(treeVT temp, VatTu vattu) {
        temp ->vt.TENVT = vattu.TENVT;
        temp ->vt.DVT = vattu.DVT;}
void ghifile(){
     ofstream outputFile(filevattu);      
        if (outputFile.is_open()) {
            index = 0;
            Duyet_cay_vao_Manng_LNR(dsvt);
            for(int i = 0; i < 1000&& a[i] != NULL; i++) {
                outputFile << a[i] ->vt.MAVT<<","<<a[i]->vt.TENVT<<","<<a[i]->vt.DVT<<","<<a[i]->vt.SoLuongTon<<endl;
            }
            BaoLoi("Ghi File Thành Công.","","");

    } else {
            BaoLoi("Không thể mở tệp để ghi.","","");  
        }
    }
    
void mofile() {
    ifstream inputfile(filevattu);
    if(inputfile.is_open()) {
        string line;
        int count = 0;
        while(getline(inputfile, line)) {
            stringstream ss(line);
            VatTu vattu;
            getline(ss, vattu.MAVT, ',');
            getline(ss, vattu.TENVT, ',');
            getline(ss, vattu.DVT, ',');
            ss >> vattu.SoLuongTon;
            nhapVT(vattu);
            count++;
        }
        string s = to_string(count)+ " Vật Tư";
        BaoLoi("Mở File Thành Công",s,"");
    } else {
            BaoLoi ("Không thể mở tệp doc.","","");
      }

}

void liet_ke_danh_sach_VT_theo_MaSo(int v,int n) {
    index = 0;
    Duyet_cay_vao_Manng_LNR(dsvt);
    kt = index;
    int cot = 0;
    for(int i = v; i <  n && i< index; i++) {     
        gotoxy(8, 6+cot);
            cout << a[i] ->vt.MAVT; gotoxy(16,6+cot);cout<<a[i]->vt.TENVT;
         gotoxy(39,6+cot);cout<<a[i]->vt.DVT;gotoxy(62,6+cot);cout<<a[i]->vt.SoLuongTon;
         cot++;
}
index = 0;
 }

int partition (treeVT arr[], int l, int h){ //thuật toán partition chốt h 
string x = arr[h]->vt.TENVT;    // x chính là chốt 
int i = (l - 1);  // i lấy vị trí nhỏ hơn l 
for (int j = l; j <= h- 1; j++) {//duyệt từ l đến h-1  
if (arr[j]->vt.TENVT <= x){ //nếu arr[j] bé hơn hoặc bằng chốt 
i++;    // tăng i lên một đoen vị 
swap(arr[i], arr[j]);  // đổi chỗ arr[i] cho arr[j] 
} 
} 
swap(arr[i + 1], arr[h]);  //đổi chỗ cho arr[i+1] và arr[h] 
return (i + 1); //đây là vị trí của chốt 
} 

void quickSort(treeVT arr[], int l, int h){  
if (l < h){ 
int p = partition(arr, l, h); // tìm vị trí của chốt 
quickSort(arr, l, p - 1);//trị nửa bên trái 
quickSort(arr, p + 1, h);//trị nửa bên phải 
} 
}

void Liet_ke_danh_sach_VT_theo_Ten(int v, int n) {
    Duyet_cay_vao_Manng_LNR(dsvt);
    quickSort(a, 0, index - 1);
    kt = index;
    int cot = 0;
 for(int i = v; i <  n && i< index; i++) {     
        gotoxy(8, 6+cot);
            cout << a[i] ->vt.MAVT; gotoxy(16,6+cot);cout<<a[i]->vt.TENVT;
         gotoxy(39,6+cot);cout<<a[i]->vt.DVT;gotoxy(62,6+cot);cout<<a[i]->vt.SoLuongTon;
         cot++;
}
index = 0;
}


void Clear_Tree(treeVT root){ 
if(root!=NULL){ 
Clear_Tree(root->left);   
Clear_Tree(root->right); 
delete(root);
} 
}
~lopvattu() {
    Clear_Tree(dsvt);
}
};

void Case1(lopvattu &X) {
    char Luachon;
    int d = 1;
    int n = 20;
    int v = 0;
    system("cls");
    Normal();
    taokhungdanhsach();
    taoghichumaso();
    do
  {
    int cot = 0;
    for(int i = 0; i <  20; i++) {
        SetColor(9);
        gotoxy(15,6+cot);cout<<"║"; 
        gotoxy(38,6+cot);cout<<"║";gotoxy(61,6+cot);cout<<"║";
       gotoxy(8, 6+cot);
       Normal();
         cout << "       "; gotoxy(16,6+cot);cout<<"                     ";
         gotoxy(39,6+cot);cout << "                 ";gotoxy(62,6+cot);
         cout<<"                             ";
         cot++;
}
     X.liet_ke_danh_sach_VT_theo_MaSo(v,n);
     HighLight();
     int m = 0; 
     X.temptree = NULL;
     if(X.kt %20 == 0) {
         m = X.kt/20;

     } else {
        m = X.kt/20 + 1;
     }
     gotoxy(90,2); cout<<d<<"/"<<m<<" ";
     Normal();
    Luachon = getch(); 
    if (Luachon == 0) 
    Luachon = getch(); 
    switch (Luachon){
    case F1:{ khungnhap();
        gotoxy(40,8); cout <<"THÊM MỚI VẬT TƯ";
    X.vattu = {"", "", "", -1};
    bool flag = true;
    int temp = 0;
    do{
        Normal();
        int luachon = X.menunhapVT(nhapvt,temp, 6);
        temp = luachon;
        Normal();
        switch (luachon) {
            case 1: gotoxy(49,10); cout<<"                          ";gotoxy(49,10);
            getline(cin, X.vattu.MAVT);
            if(!XuLyNhapLieu::chuanHoaMAVT(X.vattu.MAVT)) {
                temp = 0;
                if(X.vattu.SoLuongTon != -1) {
                gotoxy(45,16); cout<< X.vattu.SoLuongTon;}
            gotoxy(38,12); cout<< X.vattu.TENVT;
            gotoxy(39,14); cout<< X.vattu.DVT;
                break;
            } gotoxy(49,10);cout<<"                    ";
            gotoxy(49,10);cout<<X.vattu.MAVT;
            X.temptree  = X.Tim_kiem_theo_maVT(X.dsvt, X.vattu.MAVT);
       if(X.temptree != NULL && X.temptree->vt.TENVT!="") {
            BaoLoi("Mã VT đã có trong danh sách ", "hoặc không đúng định dạng","");
            gotoxy(45,16); cout<< X.vattu.SoLuongTon;
            gotoxy(38,12); cout<< X.vattu.TENVT;
            gotoxy(39,14); cout<< X.vattu.DVT;

        temp = 0; 
    }    
            break;
            case 2:  gotoxy(38,12); cout<<"                      ";gotoxy(38,12);
             getline(cin, X.vattu.TENVT);break;
            case 3:  gotoxy(39,14); cout<<"                   ";gotoxy(39,14);
            getline(cin, X.vattu.DVT);break;
            case 4: gotoxy(45,16); cout<<"            ";gotoxy(45,16);
            X.vattu.SoLuongTon = XuLyNhapLieu::ktrasonguyen();
            if (X.vattu.SoLuongTon == -1) {
            gotoxy(45,16); cout<< X.vattu.SoLuongTon;
            gotoxy(38,12); cout<< X.vattu.TENVT;
            gotoxy(39,14); cout<< X.vattu.DVT;
            temp = 3;  
        } break;
            case 5: flag = false; break;
            case 6:
       if(X.vattu.MAVT == "") {
            BaoLoi("Mã VT không được để trống", "","");
        temp = 0; break;
    }    
        int t = xacnhanluachon();
            if(t == 1) {
                X.nhapVT(X.vattu);  flag = false;
            } else {
                Normal();
                for(int i = 0; i < 6; i++) {
        gotoxy(35,12+i);
        for (int j = 0; j < 35; j++) {
            cout<<" ";
        }
    }
    gotoxy(48,12); cout<<X.vattu.TENVT;
    gotoxy(40,14);cout<<X.vattu.DVT;
    if(X.vattu.SoLuongTon != -1) {
    gotoxy(42,16);cout<<X.vattu.SoLuongTon;}break; 
            }
    } 
    } while(flag); huykhungnhap(); break;}
    case F2: {khungnhap(); 
        gotoxy(40,8); cout <<"XÓA VẬT TƯ";
    int temp = 0;
    bool flag = true;
    do{
    int luachon = X.menunhapVT(xoavt, temp, 3);
    temp = luachon;
        Normal();
    switch (luachon) {
                case 1: {gotoxy(47,10); cout<<"                   ";gotoxy(47,10);
            getline(cin, X.vattu.MAVT);
            if(!XuLyNhapLieu::chuanHoaMAVT(X.vattu.MAVT)) {
                temp = 0;
                gotoxy(47,10); cout<<"                          ";
                break;
            }
            gotoxy(47,10); cout<<X.vattu.DVT;
    X.temptree = X.Tim_kiem_theo_maVT(X.dsvt, X.vattu.MAVT);
    if(X.temptree != NULL) {      
        gotoxy(18,12); cout<<"Tên vật tư: "<< X.temptree->vt.TENVT;
        gotoxy(18,14); cout<<"Đơn vị tính: "<<X.temptree->vt.DVT;
        gotoxy(18,16); cout<<"Số lượng tồn: "<<X.temptree->vt.SoLuongTon;
    }else {
        BaoLoi("Không tìm thấy mã VT để xóa!", "","");
        temp--;
    } }break;
            case 2: flag = false; break;
            case 3: if(X.vattu.MAVT == ""||X.temptree == NULL) {
                BaoLoi("Hãy nhập vật tư cần xóa","","");
                temp = 0;
                break;
            }
            int t = xacnhanluachon();
            if(t == 1) {
                X.XoaVT(X.temptree);  flag = false;
            } else {
                Normal();
                for(int i = 0; i < 6; i++) {
        gotoxy(35,12+i);
        for (int j = 0; j < 35; j++) {
            cout<<" ";
        }
    }
    if(X.vattu.MAVT != "") {
        gotoxy(30,12); cout<<"Tên vật tư: "<< X.temptree->vt.TENVT;
        gotoxy(31,14); cout<<"Đơn vị tính: "<<X.temptree->vt.DVT;
        gotoxy(32,16); cout<<"Số lượng tồn: "<<X.temptree->vt.SoLuongTon;
    } else {
        break;
    }
        break; 
            }
    } 
    } while(flag); huykhungnhap();break;}
    case F3: {khungnhap();
        gotoxy(40,8); cout <<"CHỈNH SỬA VẬT TƯ"; 
    int temp = 0;
    bool flag = true;
    bool l = true;
    int  t= 3;
    string s[3] = {"Nhập mã vật tư(VD: VT0099):"," Hủy "," Xác nhận "};
    for(int i = 0; i < 3; i++) {
        suavt[i] = s[i];
    }
    X.vattu = {"", "", "", -1};
    do{
    int luachon = X.menunhapVT(suavt, temp, t);
    temp = luachon;
        Normal();
        switch (luachon) {
            case 1: {if(l) {{gotoxy(47,10); cout<<"                   ";gotoxy(47,10);
            getline(cin, X.vattu.MAVT);
            if(!XuLyNhapLieu::chuanHoaMAVT(X.vattu.MAVT)) {
                temp = 0;
                gotoxy(47,10); cout<<"                          ";
                break;
            }
            gotoxy(47,10); cout<<X.vattu.DVT;
    X.temptree = X.Tim_kiem_theo_maVT(X.dsvt, X.vattu.MAVT);
    if(X.temptree != NULL) { 
        string s[5] = {"Nhập mã vật tư(VD: VT0099):","Tên vật tư:", "Đơn vị tính:",
 " Hủy "," Xác nhận "};  
 for(int i = 0; i < 5; i++) {
        suavt[i] = s[i];
    }   
        gotoxy(30,12); cout<<X.temptree->vt.TENVT;
        gotoxy(31,14);cout<< X.temptree->vt.DVT;
        l = false; t = 5;
    }else {
        BaoLoi("Không tìm thấy mã VT để ","chỉnh sửa","");
        temp--;

    } } }break;}
           case 2:  if(t == 3) {
             flag = false; break;}
            gotoxy(30,12); cout<<"                   ";gotoxy(30,12);
            getline(cin, X.vattu.TENVT);break;
            case 3:  if(t==3)
            { BaoLoi("Hãy nhập vật tư cần chỉnh sửa","","");
            temp = 0;
             break; }
            gotoxy(31,14); cout<<"                   ";gotoxy(31,14);
            getline(cin, X.vattu.DVT);break;
            case 4: flag = false; break;
            case 5: if(X.vattu.MAVT == ""||X.temptree == NULL) {
                BaoLoi("Hãy nhập vật tư cần xóa","","");
                temp = 0;
                break;
            } int t = xacnhanluachon();
            if(t == 1) {
                if(X.vattu.TENVT=="")
                {
                    X.vattu.TENVT=X.temptree->vt.TENVT;
                }
                if(X.vattu.DVT=="")
                {
                    X.vattu.DVT=X.temptree->vt.DVT;
                }
                X.ChinhsuaVT(X.temptree, X.vattu);  flag = false;
            } else {
                Normal();
                for(int i = 0; i < 6; i++) {
        gotoxy(35,12+i);
        for (int j = 0; j < 35; j++) {
            cout<<" ";
        }
    }
    gotoxy(30,12); cout<<X.vattu.TENVT;
    gotoxy(31,14);cout<<X.vattu.DVT;
    break; 
            }
    } 
    } while(flag);huykhungnhap(); break;}

    case Up: {if(d<=1) {
        BaoLoi("Đang là trang đầu tiên!","","");
         break;} 
        v-=20; n-=20; d-=1; break;}
    case Down:{if(n >= X.kt) {
        BaoLoi("Đã là trang cuối cùng!","","");
        break;}
        v+=20; n+=20; d+=1;break;}
    case ESC : { X.ghifile(); return;}
  }}while (true);
}

void Case2(lopvattu &X) {
    char Luachon;
    int d = 1;
    int n = 20;
    int v = 0;
      system("cls");
    Normal();
    taokhungdanhsach();
    taoghichumaso();
    do
  {
    int cot = 0;
    for(int i = 0; i <  20; i++) {
        SetColor(9);
        gotoxy(15,6+cot);cout<<"║"; 
        gotoxy(38,6+cot);cout<<"║";gotoxy(61,6+cot);cout<<"║";
       gotoxy(8, 6+cot);
       Normal();
            cout << "       "; gotoxy(17,6+cot);cout<<"                     ";
         gotoxy(40,6+cot);cout << "                 ";gotoxy(63,6+cot);
         cout<<"                             ";
         cot++;
    }

     X.Liet_ke_danh_sach_VT_theo_Ten(v,n);
     HighLight();
     int m = 0; 
     if(X.kt %20 == 0) {
         m = X.kt/20;

     } else {
        m = X.kt/20 + 1;
     }
     gotoxy(90,2); cout<<d<<"/"<<m<<" ";
     Normal();
    Luachon = getch(); 
    if (Luachon == 0) 
    Luachon = getch(); 
    switch (Luachon){
   
    case Up: {if(d<=1) {BaoLoi("Đang là trang đầu tiên!","","");
        break;} 
        v-=20; n-=20; d-=1; break;}
    case Down:{if(n >= X.kt) {
        BaoLoi("Đã là trang cuối cùng!","","");break;}
        v+=20; n+=20; d+=1;break;}
    case ESC : { return;}
  }}while (true);
}

class nhanvien {
    private:
struct CT_HoaDon {
    string MAVT;
    int soluong;
    int DONGIA;
    int VAT;
    int tongtienthoethang = 0;
};

struct nodeCTHD{
    CT_HoaDon cthd;
    nodeCTHD* next;
};
typedef nodeCTHD* PTRCTHD;
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

struct nodeHD {
    HoaDon hd;
    nodeHD* next;
};
typedef nodeHD* PTRHD;

struct NhanVien {
    string MANV;
    string HO;
    string TEN;
    string PHAI;
    PTRHD dshd = NULL; 
};

struct DSNV {
    int n = -1;
    NhanVien* nodes[MAX_NhanVien];
};
string filenhanvien;
string filehoadon;
string filechitiethoadon;
    public:
    struct Date1 {
	int day, month, year;
};
    struct thongkehoadon{
        string maNV;
        PTRHD ptrhd;
    };
    struct nam{
        int thang = 0;
        int doanhthuthang = 0;
    };
    struct  tkcthd{
        string tenvt;
        PTRCTHD cthd;
    };
    nam Nam[12];
    DSNV dsnv;
    NhanVien tnv;
    int a =0;
    int b = 0;
    int dem = 0; int dem2 = 0; int dem3 = 0; int dem4 = 0;
    Date d1, d2;
    thongkehoadon a1[1000];
    tkcthd a2[5000];
    NhanVien* Temp;
    CT_HoaDon a3[200];
    HoaDon Hd;
    PTRHD PTR;
    PTRHD PTRhd;
    HoaDon mamoinhat;
    nhanvien(string Filenhanvien, string Filehoadon, string Filechitiethoadon) {
        filenhanvien = Filenhanvien;
        filehoadon = Filehoadon;
        filechitiethoadon = Filechitiethoadon;
        mamoinhat.SoHD = "HD0000000000";
        mofile();
    }

    void insert_order() 
      {      
        int i = dsnv.n - 1;                 // bắt đầu từ phần tử trước phần tử mới
        NhanVien* moi = dsnv.nodes[dsnv.n]; // nhân viên vừa thêm

        // Dịch mảng sang phải cho tới khi tìm đúng vị trí
          while (i >= 0) {
          // So sánh theo TÊN trước
            if (dsnv.nodes[i]->TEN > moi->TEN ||
               (dsnv.nodes[i]->TEN == moi->TEN &&
                dsnv.nodes[i]->HO > moi->HO)) {

                dsnv.nodes[i + 1] = dsnv.nodes[i];
                i--;
              } 
			else 
			{
            break;
            }
         }  

       dsnv.nodes[i + 1] = moi;
}
    double tinhDoanhThuCT(const CT_HoaDon& ct) 
    {  
    return ct.soluong * ct.DONGIA * (1 + ct.VAT / 100.0);
    }

    void nhapNV(NhanVien Node, int f) {
        
        dsnv.nodes[dsnv.n] = new NhanVien;
        dsnv.nodes[dsnv.n]->MANV = Node.MANV;
        dsnv.nodes[dsnv.n]->HO = Node.HO;
        dsnv.nodes[dsnv.n]->TEN = Node.TEN;
        dsnv.nodes[dsnv.n]->PHAI = Node.PHAI;
        dsnv.nodes[dsnv.n]->dshd = Node.dshd;
        if(f) {
        insert_order();
        }
    }
    bool timkiemtheomanhanvien(NhanVien nv) {
        for(int i = 0; i < dsnv.n; i++) {
            if(dsnv.nodes[i]->MANV == nv.MANV)  {
                Temp = dsnv.nodes[i];
                return 1;
            }

        } return 0;

    }
    bool timmkiemthomahoadon(string mahd) {
        PTRHD temp = Temp->dshd;
        while(temp!=NULL) {
            if(mahd == temp->hd.SoHD) {
                PTRhd = temp;
                return 1;
            }
            temp = temp->next;
        }
        return 0;

    }
    void indsnvtheoten(int v, int n) {
        int cot = 0;
        for(int i = v; i < n&& i <= dsnv.n; i++) {   
            if(dsnv.nodes[i] == NULL) {
                gotoxy(8, 6+cot); cout<<"NULL";

            } 
        gotoxy(8, 6+cot);
            cout << dsnv.nodes[i]->MANV; gotoxy(16,6+cot);cout<<dsnv.nodes[i]->HO;gotoxy(39,6+cot);
            cout<< dsnv.nodes[i]->TEN; gotoxy(62,6+cot);cout<<dsnv.nodes[i]->PHAI;
         cot++;
        }
    }
// 1. Hàm ghi chi tiết hóa đơn (Đã tối ưu: Nhận biến file từ bên ngoài)
void ghifilechitiethoadon(PTRCTHD t, string SoHD, ofstream &fileCT) {
    // Ghi header để hàm đọc nhận diện và bỏ qua (khớp với logic mofile)
    // Code đọc của bạn: if(line[0] == 'H'&&line[1]=='D') continue;
    fileCT << SoHD << endl; 
    PTRCTHD temp = t;
    while (temp != NULL) {
        fileCT << temp->cthd.MAVT << "," 
               << temp->cthd.soluong << "," 
               << temp->cthd.DONGIA << "," 
               << temp->cthd.VAT << endl;
        temp = temp->next;
    }
    // Ghi dấu kết thúc danh sách
    fileCT << "." << endl;
}

// 2. Hàm ghi danh sách hóa đơn (Đã tối ưu)
void ghifilehoadon(PTRHD t, string MANV, ofstream &fileHD, ofstream &fileCT) {
    // Ghi header để hàm đọc nhận diện (khớp với logic mofile)
    // Code đọc của bạn: if(line[0] == 'N'&&line[1]=='V') continue;
    // Thêm chữ "NV" vào trước để đảm bảo hàm đọc luôn skip dòng này dù MANV là gì
    fileHD  << MANV << endl;
    PTRHD temp = t;
    while (temp != NULL) {
        // Ghi thông tin hóa đơn
        fileHD << temp->hd.SoHD << "," 
               << temp->hd.Loai << "," 
               << temp->hd.NgayLapHoaDon.day << "/" 
               << temp->hd.NgayLapHoaDon.month << "/" 
               << temp->hd.NgayLapHoaDon.year <<"."<< temp->hd.trigia<< endl;
        
        // Gọi hàm ghi chi tiết cho hóa đơn này (truyền fileCT vào)
        ghifilechitiethoadon(temp->hd.dscthd, temp->hd.SoHD, fileCT);
        
        temp = temp->next;
    }
    // Ghi dấu kết thúc danh sách hóa đơn của nhân viên này
    fileHD << "." << endl;
}

// 3. Hàm chính (Quản lý mở/đóng file)
void ghifile() {
    // Mở cả 3 file ở chế độ ghi mới (trunc) để xóa dữ liệu cũ
    ofstream f_nv(filenhanvien);
    ofstream f_hd(filehoadon);
    ofstream f_ct(filechitiethoadon);

    // Kiểm tra xem cả 3 file có mở được không
    if (f_nv.is_open() && f_hd.is_open() && f_ct.is_open()) {
        
        for (int i = 0; i <= dsnv.n; i++) {
            // Kiểm tra node có tồn tại không để tránh lỗi NULL pointer
            if (dsnv.nodes[i] != NULL) {
                // 1. Ghi nhân viên
                f_nv << dsnv.nodes[i]->MANV << "," 
                     << dsnv.nodes[i]->HO << ","
                     << dsnv.nodes[i]->TEN << "," 
                     << dsnv.nodes[i]->PHAI << endl;

                // 2. Ghi danh sách hóa đơn của nhân viên đó
                // Truyền f_hd và f_ct vào để hàm con dùng tiếp, không cần mở lại
                ghifilehoadon(dsnv.nodes[i]->dshd, dsnv.nodes[i]->MANV, f_hd, f_ct);
            }
        }

        // Đóng file sau khi hoàn tất
        f_nv.close();
        f_hd.close();
        f_ct.close();

        BaoLoi("Ghi File Thành Công.", "", "");
    } else {
        BaoLoi("Lỗi: Không thể mở các tệp để ghi.", "", "");
    }
}
    void reverse(PTRHD &start){//đảo ngược danh sách 
     PTRHD ptr1, ptr2, ptr3; 
    
     if (start == NULL || start->next == NULL){//nếu danh sách chỏ có một node 
          return; 
     }   
     ptr1 = start; //ptr1 trỏ đến node đầu tiên 
     ptr2 = ptr1->next;// ptr2 trỏ đến node tiếp theo 
     ptr3 = ptr2->next;// ptr3 trỏ đến node tiếp theo 
     ptr1->next = NULL;//ngắt liên kết của ptr1 
     ptr2->next = ptr1;//ptr1 trở thành node kế tiếp của ptr2 
     while (ptr3 != NULL){//lặp nếu ptr3 không rỗng 
          ptr1 = ptr2;   
ptr2 = ptr3; 
          ptr3 = ptr3->next; 
          ptr2->next = ptr1;          
     } 
     start = ptr2; 
}
void reverscthd(PTRCTHD &start){//đảo ngược danh sách 
     PTRCTHD ptr1, ptr2, ptr3; 
    
     if (start == NULL||start->next == NULL){//nếu danh sách chỏ có một node 
          return; 
     }   
     ptr1 = start; //ptr1 trỏ đến node đầu tiên 
     ptr2 = ptr1->next;// ptr2 trỏ đến node tiếp theo 
     ptr3 = ptr2->next;// ptr3 trỏ đến node tiếp theo 
     ptr1->next = NULL;//ngắt liên kết của ptr1 
     ptr2->next = ptr1;//ptr1 trở thành node kế tiếp của ptr2 
     while (ptr3 != NULL){//lặp nếu ptr3 không rỗng 
          ptr1 = ptr2;   
ptr2 = ptr3; 
          ptr3 = ptr3->next; 
          ptr2->next = ptr1;          
     } 
     start = ptr2; 
}
void mofilechitiethoadon(PTRCTHD &temp, ifstream &ct) {
    string sl ,vat,dg;
    if(ct.is_open()) {
        string line;
        while(getline(ct, line)){
            if(line[0] == 'H'&&line[1]=='D') {
                continue;
            }
            if(line[0] == '.'||line=="") {
                reverscthd(temp);
                return;}
            stringstream ss(line);
            CT_HoaDon cthd;
            getline(ss, cthd.MAVT,',');
            getline(ss, sl, ',');
            getline(ss,dg, ',');
            getline(ss, vat);
            cthd.soluong = stoi(sl);
            cthd.VAT = stoi(vat);
            cthd.DONGIA = stoi(dg);
            insert_begincthd(temp, cthd);
        }
    }

}
void mofilehoadon(PTRHD &temp, ifstream &h, ifstream &cthd) {
    string loai;
    string d, m, y, tg;
    if (h.is_open()) {
        string line;
        while (getline(h, line)) {
            // Bỏ qua dòng chứa Mã nhân viên
            if (line[0] == 'N' && line[1] == 'V') {
                continue;
            }
            
            // Gặp dấu chấm là hết danh sách hóa đơn của 1 nhân viên
            if (line[0] == '.' || line == "") {
                reverse(temp);
                // XÓA ĐOẠN CODE CŨ Ở ĐÂY (đoạn so sánh soma, soma1)
                // Vì nó kiểm tra sai vị trí node sau khi đảo ngược
                return;
            }

            // Xử lý đọc dòng hóa đơn
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

            // --- SỬA Ở ĐÂY: Cập nhật mã mới nhất ngay khi đọc ---
            // So sánh nguyên chuỗi string sẽ chính xác cả Năm/Tháng/Số
            if (hd.SoHD > mamoinhat.SoHD) {
                mamoinhat.SoHD = hd.SoHD;
            }
            // ----------------------------------------------------

            mofilechitiethoadon(hd.dscthd, cthd);
            insert_begin(temp, hd);
        }
    }
}
 void suaNhanVien(NhanVien* &temp, NhanVien nv) {
                temp->HO = nv.HO;
                temp->TEN = nv.TEN;
                temp->PHAI= nv.PHAI;
            }
//hamf xóa nhân viên
void xoaNhanVien(string maNV) {
        for(int i = 0; i <= dsnv.n; i++) {
            if(dsnv.nodes[i]->MANV == maNV) {

                // Xóa danh sách hóa đơn
                PTRHD hd = dsnv.nodes[i]->dshd;
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

                // Xóa nhân viên
                delete dsnv.nodes[i];

                // Dồn mảng DSNV
                for(int j = i; j < dsnv.n; j++) {
                    dsnv.nodes[j] = dsnv.nodes[j + 1];
                }

                dsnv.nodes[dsnv.n] = NULL;
                dsnv.n--;
            }
        }
    }
void mofile(){
    ifstream inputfile(filenhanvien);
    ifstream inputfileh(filehoadon);
    ifstream inputfilec(filechitiethoadon);
    if(inputfile.is_open()) {
        string line;
        int count = 0;
        while(getline(inputfile, line)) {
            stringstream ss(line);
            NhanVien node;
            getline(ss, node.MANV, ',');
            getline(ss, node.HO, ',');
            getline(ss, node.TEN, ',');
            getline(ss, node.PHAI);
            node.dshd = NULL;
            mofilehoadon(node.dshd, inputfileh, inputfilec);
            dsnv.n++;
            nhapNV(node, 0);
            count++;
        }
        string s = to_string(count)+ " Nhân viên";
        BaoLoi("Mở File Thành Công",s,"");
    } else {
            BaoLoi ("Không thể mở tệp doc.","","");
      }
}

PTRHD create_node(HoaDon Hd){//tạo node rời rạc có giá trị value 
     PTRHD temp = new nodeHD; //cấp phát không gian nhớ cho temp 
     if (temp == NULL){ //nếu không đủ gian nhớ để cấp phát 
          cout<<"Không đủ bộ nhớ"<<endl; 
         return 0; 
     } 
     else { 
          temp->hd.SoHD = Hd.SoHD;
          temp->hd.Loai = Hd.Loai;
          temp ->hd.NgayLapHoaDon = Hd.NgayLapHoaDon;
          temp->hd.dscthd = Hd.dscthd;
          temp->hd.trigia = Hd.trigia;
          temp->next = NULL; //thiết lập thành phần liên kết     
          return temp;//trả lại con trỏ node 
     } 
} 
 void insert_begin(PTRHD &Dshd, HoaDon Hd){
    PTRHD p; 
     PTRHD temp = create_node(Hd);
     if (Dshd == NULL){//nếu danh sách liên kết đơn rỗng 
          Dshd = temp;//start chính là temp; 
          Dshd->next = NULL; //thiết lập thành phần liên kết cho start          
     }  
     else { //trường hợp danh sách liên kết không rỗng 
          p = Dshd; //con trỏ p trỏ đến start 
          Dshd = temp;//start trỏ đến temp 
          Dshd->next = p;//thiết lập lại liên kết cho start 
     } 
}
void dohdvaomang(PTRHD hd) {
    a = 0;
    PTRHD temp = hd;
    for(int i = 0; temp!=NULL && i < 1000; i++) {
        a++;
        a1[i].ptrhd = temp;
        temp = temp->next;
    }

}
void  docthdvaomang(PTRHD cthd) {
    b = 0;
      PTRCTHD temp = cthd->hd.dscthd;
    for(int i = 0; temp != NULL && i <500; i++) {
        b++;
        a2[i].cthd = temp;
        temp = temp->next;
    }


}
void display(PTRHD Dshd, int v, int n){//duyệt danh sách 
        dohdvaomang(Dshd);
     if (Dshd == NULL){ 
          cout<<"Danh sách rỗng"<<endl; 
          return; 
     }  
      int cot = 0;
        for(int i = v; i < n&&i<a; i++) {    
        gotoxy(8, 6+cot);
            cout << a1[i].ptrhd->hd.SoHD; gotoxy(27,6+cot);cout<<a1[i].ptrhd->hd.Loai;gotoxy(56,6+cot);
            cout<< a1[i].ptrhd->hd.NgayLapHoaDon.day<<"/"<<a1[i].ptrhd->hd.NgayLapHoaDon.month<<"/"<<a1[i].ptrhd->hd.NgayLapHoaDon.year;
         cot++; 
    }
}
void displaytkhd(int v, int n) {
    if (dem3 == 0) {
        gotoxy(40, 15); cout << "KHÔNG CÓ HÓA ĐƠN NÀO TRONG KHOẢNG NÀY";
        return;
    }
    
    int dongHienTai = 0;
    for (int i = v; i < n && i < dem3; i++) {
        gotoxy(8, 6 + dongHienTai);  cout << a1[i].ptrhd->hd.SoHD;
        gotoxy(24, 6 + dongHienTai); cout << (a1[i].ptrhd->hd.Loai == "N" ? "NHẬP" : "XUẤT");
        gotoxy(37, 6 + dongHienTai); cout << a1[i].ptrhd->hd.NgayLapHoaDon.day << "/" 
                                         << a1[i].ptrhd->hd.NgayLapHoaDon.month << "/" 
                                         << a1[i].ptrhd->hd.NgayLapHoaDon.year;
        
        // Tìm tên nhân viên dựa trên mã đã lưu trong mảng a1
        tnv.MANV = a1[i].maNV;
        if (timkiemtheomanhanvien(tnv)) {
            gotoxy(52, 6 + dongHienTai); cout << Temp->HO << " " << Temp->TEN;
        }
        
        gotoxy(72, 6 + dongHienTai); cout << fixed << setprecision(0) << a1[i].ptrhd->hd.trigia << " VNĐ";
        dongHienTai++;
    }
}
void bbsort() {
    for(int i = 0; i < dem4; i++) {
        for(int j = i+1; j < dem4; j++) {
            if(a2[i].cthd->cthd.tongtienthoethang < a2[j].cthd->cthd.tongtienthoethang) {
                swap(a2[i], a2[j]);
            }
        }
    }
}
void displayt( int v, int n){//duyệt danh sách 
     if (a2[0].cthd == NULL){ 
          cout<<"Danh sách rỗng"<<endl; 
          return; 
     }  
     bbsort();
      int cot = 0;
        for(int i = v; i < n&&i<dem4&&i<10; i++) {    
        gotoxy(10, 6+cot);
            cout << a2[i].cthd->cthd.MAVT; gotoxy(32, 6 + cot); cout<< a2[i].tenvt;
            gotoxy(61, 6+cot);cout<<a2[i].cthd->cthd.tongtienthoethang<<" VNĐ";
         cot++; 
    }
}
void displayn( int v, int n){//duyệt danh sách 
          int cot = 0;
        for(int i = v; i < n&&i<12; i++) {    
        gotoxy(8, 6+cot);
            cout << Nam[i].thang; gotoxy(42,6+cot);cout<< Nam[i].doanhthuthang<<" VNĐ";
         cot++; 
    }
}
PTRCTHD create_nodecthd(CT_HoaDon Cthd){//tạo node rời rạc có giá trị value 
     PTRCTHD temp = new nodeCTHD; //cấp phát không gian nhớ cho temp 
     if (temp == NULL){ //nếu không đủ gian nhớ để cấp phát 
          cout<<"Không đủ bộ nhớ"<<endl; 
         return 0; 
     } 
     else { 
          temp->cthd.MAVT = Cthd.MAVT;
          temp->cthd.soluong = Cthd.soluong;
          temp ->cthd.DONGIA = Cthd.DONGIA;
          temp ->cthd.VAT = Cthd.VAT;
          temp->next = NULL; //thiết lập thành phần liên kết     
          return temp;//trả lại con trỏ node 
     } 
} 
 void insert_begincthd(PTRCTHD &cthd, CT_HoaDon Hd){
    PTRCTHD p; 
     PTRCTHD temp = create_nodecthd(Hd);
     if (cthd == NULL){//nếu danh sách liên kết đơn rỗng 
          cthd = temp;//start chính là temp; 
          cthd->next = NULL; //thiết lập thành phần liên kết cho start          
     }  
     else { //trường hợp danh sách liên kết không rỗng 
          p = cthd; //con trỏ p trỏ đến start 
          cthd = temp;//start trỏ đến temp 
          cthd->next = p;//thiết lập lại liên kết cho start 
     } 
}   
void displaycthd(lopvattu &X, PTRHD Cthd, int v, int n){//duyệt danh sách 
    if (Cthd == NULL){ 
          cout<<"Danh sách rỗng"<<endl; 
          return; 
     } 
        docthdvaomang(Cthd);
      int cot = 0;
        for(int i = v; i < n && i < b; i++) { 
            X.temptree = X.Tim_kiem_theo_maVT(X.dsvt, a2[i].cthd->cthd.MAVT);  
        gotoxy(8, 6+cot);
            cout << a2[i].cthd->cthd.MAVT; gotoxy(16,6+cot); cout<<X.temptree->vt.TENVT;gotoxy(42,6+cot);
            cout<< a2[i].cthd->cthd.DONGIA<<" VNĐ";gotoxy(64,6+cot); cout<<a2[i].cthd->cthd.soluong;
            gotoxy(80, 6+cot); cout<< a2[i].cthd->cthd.VAT<<" %";
         cot++;
    }
} 
void taotaosohdngaylaphd(HoaDon &hd, HoaDon t) {
    int temp;
    string thang;
    string songay = "";
    time_t now = time(0);
        tm* local_time = localtime(&now);
        hd.NgayLapHoaDon.year = local_time->tm_year + 1900;
        hd.NgayLapHoaDon.month = local_time->tm_mon + 1;//hd2025120001
        hd.NgayLapHoaDon.day = local_time->tm_mday;
        if(hd.NgayLapHoaDon.month/10 != 1) {
        thang = '0' + to_string(hd.NgayLapHoaDon.month);
    }
        string ngayhientai = to_string(hd.NgayLapHoaDon.year) + thang; 
    int soThuTu = 0;
    // Kiểm tra xem nhân viên này đã có hóa đơn nào chưa
    
        // Giả sử Temp.dshd đang trỏ tới hóa đơn mới nhất (đã sort hoặc insert head)
        string soHDCu = t.SoHD;
        // Cắt chuỗi lấy 4 số cuối: HD202512[0001]
        string soCu = soHDCu.substr(soHDCu.length() - 4); 
        soThuTu = stoi(soCu);
    
    soThuTu++; // Tăng lên 1
    
    // Format lại chuỗi (ví dụ: HD2025120001)
    for(int i = 2; i<8; i++) {
        songay += t.SoHD[i];
    }
    if(ngayhientai != songay) {
        soThuTu = 1;
        
    } 
    stringstream ss;
        ss << "HD" << hd.NgayLapHoaDon.year << thang 
       << setfill('0') << setw(4) << soThuTu; 
    hd.SoHD = ss.str();
}

void thongKeHoaDon(Date d1, Date d2) {
    dem3 = 0; // Biến đếm số lượng hóa đơn thỏa điều kiện
    long long batDau = XuLyNhapLieu::quyDoiNgay(d1.day, d1.month, d1.year);
    long long ketThuc = XuLyNhapLieu::quyDoiNgay(d2.day, d2.month, d2.year);

    for (int i = 0; i <= dsnv.n; i++) {
        PTRHD p = dsnv.nodes[i]->dshd;
        while (p != NULL) {
            long long ngayLap = XuLyNhapLieu::quyDoiNgay(p->hd.NgayLapHoaDon.day, 
                                                       p->hd.NgayLapHoaDon.month, 
                                                       p->hd.NgayLapHoaDon.year);
            
            // So sánh đơn giản bằng số nguyên
            if (ngayLap >= batDau && ngayLap <= ketThuc) {
                if (dem3 < 1000) { // Tránh tràn mảng a1
                    a1[dem3].maNV = dsnv.nodes[i]->MANV; // Lưu mã NV để biết ai lập
                    a1[dem3].ptrhd = p;
                    dem3++;
                }
            }
            p = p->next;
        }
    } 
}

void tinhgiatine(lopvattu &X) {
    dem4 = 0;
    
    // Reset mảng a2
    for(int i = 0; i < 5000; i++) {
        a2[i].cthd = NULL;
        a2[i].tenvt = "";
    }
    
    // Duyệt qua tất cả hóa đơn trong khoảng thời gian
    for(int hdIndex = 0; hdIndex < dem3; hdIndex++) {
        PTRCTHD temp = a1[hdIndex].ptrhd->hd.dscthd;
        while(temp != NULL) {
            bool found = false;
            
            // Kiểm tra xem vật tư đã có trong mảng a2 chưa
            for(int vtIndex = 0; vtIndex < dem4; vtIndex++) {
                if(temp->cthd.MAVT == a2[vtIndex].cthd->cthd.MAVT) {
                    found = true;
                    // Tính tổng tiền: số lượng * đơn giá * (1 + VAT/100)
                    double tien = temp->cthd.soluong * temp->cthd.DONGIA * (1 + temp->cthd.VAT/100.0);
                    a2[vtIndex].cthd->cthd.tongtienthoethang += (long long)tien;
                    break;
                }
            }
            
            // Nếu chưa có, thêm mới
            if(!found) {
                X.temptree = X.Tim_kiem_theo_maVT(X.dsvt, temp->cthd.MAVT);
                if(X.temptree != NULL) {
                    a2[dem4].tenvt = X.temptree->vt.TENVT;
                    
                    // Tạo node mới để lưu thông tin
                    PTRCTHD newNode = new nodeCTHD;
                    newNode->cthd = temp->cthd;
                    
                    // Tính tổng tiền cho vật tư này
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
void timnam() {
     for(int i = 0; i < 12; i++) {
        Nam[i].thang = i + 1;  
        Nam[i].doanhthuthang = 0;
    }
    for(int i = 0; i <= dsnv.n; i++) {
        if(dsnv.nodes[i] == NULL) continue; 
        PTRHD temp = dsnv.nodes[i]->dshd;
        while(temp != NULL) {
            if(temp->hd.NgayLapHoaDon.year == d1.year) { 
                Nam[temp->hd.NgayLapHoaDon.month - 1].thang = temp->hd.NgayLapHoaDon.month;
                Nam[temp->hd.NgayLapHoaDon.month - 1].doanhthuthang += temp->hd.trigia;
            }
        temp = temp->next;
    }             
}
}

~nhanvien() {
    for(int i = 0; i < dsnv.n; i++) {
        // Cần xóa dshd của mỗi nhân viên
        PTRHD temp = dsnv.nodes[i]->dshd;
        while(temp != NULL) {
            PTRHD next = temp->next;
            // Cần xóa dscthd trong mỗi hóa đơn
            delete temp;
            temp = next;
        }
        delete dsnv.nodes[i];
    }
}
};

   
void Case3(lopvattu& X, nhanvien &Y) {
    string nhapnv[6] = {"1. Nhập mã nhân viên(VD: NV099):","2. Nhập họ nhân viên:", "3. Nhập tên nhân viên:",
        "4. Nhập giới tính nhân viên (VD: Nam/Nữ):"," Hủy "," Xác nhận "};
    char Luachon;
    int d = 1;
    int n = 20;
    int v = 0;
     system("cls");
    Normal();
    taokhungdanhsach();
    taoghichumaso1();
    do
  {
     int cot = 0;
    for(int i = 0; i <  20; i++) {
        SetColor(9);
        gotoxy(15,6+cot);cout<<"║"; 
        gotoxy(38,6+cot);cout<<"║";gotoxy(61,6+cot);cout<<"║";
       gotoxy(8, 6+cot);
       Normal();
            cout << "       "; gotoxy(16,6+cot);cout<<"                      ";
         gotoxy(39,6+cot);cout << "                      ";gotoxy(62,6+cot);
         cout<<"                             ";
         cot++;
    }
     Y.indsnvtheoten(v,n);
     int m = 0; 
     if(Y.dsnv.n %20 == 0) {
         m = Y.dsnv.n/20;

     } else {
        m = Y.dsnv.n/20 + 1;
     }
     HighLight();
     gotoxy(90,2); cout<<d<<"/"<<m<<" ";
     Normal();
    Luachon = getch(); 
    if (Luachon == 0) 
    Luachon = getch(); 
    switch (Luachon){
    case F1:{ khungnhap();
    gotoxy(40,8); cout <<"THÊM MỚI NHÂN VIÊN";
    Y.tnv = {"","","",""};
    bool flag = true;
    int temp = 0;
    do{
        Normal();
        int luachon = X.menunhapVT(nhapnv,temp, 6);
        temp = luachon;
        Normal();
        switch (luachon) {
            case 1: {gotoxy(51,10); cout<<"                   ";gotoxy(51,10);
            getline(cin, Y.tnv.MANV);
             if(!XuLyNhapLieu::chuanHoaMaNV(Y.tnv.MANV)) {
                temp = 0;
                gotoxy(49,10); cout<<"                          ";
            } gotoxy(51,10); cout<< Y.tnv.MANV;
            if(Y.timkiemtheomanhanvien(Y.tnv) == 1) {
            BaoLoi("Mã NV bị trùng", "hoặc lớn hơn 100","");
        temp = 0;} break;
        }
            case 2:  gotoxy(40,12); cout<<"                   ";gotoxy(40,12);
            getline(cin, Y.tnv.HO);
            if(!XuLyNhapLieu::chuanHoaTen(Y.tnv.HO)) {
                temp = 1;
                gotoxy(40,12); cout<< Y.tnv.HO;
    gotoxy(41,14);cout<<Y.tnv.TEN;
        gotoxy(60,16); cout<<Y.tnv.PHAI;
            } gotoxy(40,12); cout<< Y.tnv.HO;
            break;
            case 3:  gotoxy(41,14); cout<<"                   ";gotoxy(41,14);
            getline(cin, Y.tnv.TEN);
             if(!XuLyNhapLieu::chuanHoaTen(Y.tnv.TEN)) {
                temp = 1;
                gotoxy(40,12); cout<< Y.tnv.HO;
    gotoxy(41,14);cout<<Y.tnv.TEN;
        gotoxy(60,16); cout<<Y.tnv.PHAI;
            } gotoxy(41,14);cout<<Y.tnv.TEN;
            break;
            case 4: gotoxy(60,16); cout<<"            ";gotoxy(60,16);
            getline(cin, Y.tnv.PHAI);
            if(!XuLyNhapLieu::chuanHoaGioiTinh(Y.tnv.PHAI))  {
                temp = 3;
                gotoxy(40,12); cout<< Y.tnv.HO;
    gotoxy(41,14);cout<<Y.tnv.TEN;
            } gotoxy(60,16); cout<<Y.tnv.PHAI;
            break;
            case 5: flag = false; break;
            case 6: if(Y.tnv.MANV == "") {
            BaoLoi("Mã NV khong duoc", "de trong","");
        temp = 0; break;}
            int t = xacnhanluachon();
            if(t == 1) {
                Y.dsnv.n++;
                Y.nhapNV(Y.tnv,1);  flag = false;
            } else {
                Normal();
                for(int i = 0; i < 6; i++) {
        gotoxy(35,12+i);
        for (int j = 0; j < 35; j++) {
            cout<<" ";
        }
    }
    gotoxy(40,12); cout<< Y.tnv.HO;
    gotoxy(41,14);cout<<Y.tnv.TEN;
    gotoxy(60,16);cout<< Y.tnv.PHAI;break; 
            }
    } 
    } while(flag); break;}
    case F2:{
    khungnhap(); 
    gotoxy(40,8); cout <<"XÓA NHÂN VIÊN";
    int temp = 0;
    bool flag = true;
    do{
    int luachon = X.menunhapVT(xoanv, temp, 3);
    temp = luachon;
        Normal();
    switch (luachon) {
                case 1: {gotoxy(51,10); cout<<"                   ";gotoxy(51,10);
            getline(cin, Y.tnv.MANV);
            if(!XuLyNhapLieu::chuanHoaMaNV(Y.tnv.MANV)) {
                temp = 0;
                gotoxy(49,10); cout<<"                          ";
            } gotoxy(51,10); cout<< Y.tnv.MANV;
    if(Y.timkiemtheomanhanvien(Y.tnv)) {      
        gotoxy(18,12); cout<<"2. Họ và tên nhân viên: "<<Y.Temp->HO<<" "<<Y.Temp->TEN;
        gotoxy(18,14); cout<<"3. Giới tính nhân viên: "<< Y.Temp->PHAI;
    }else {
        BaoLoi("Không tìm thấy mã NV để xóa!", "","");
        temp = 0;
    } }break;
            case 2: flag = false; break;
            case 3: if(Y.tnv.MANV == ""|| !Y.timkiemtheomanhanvien(Y.tnv)) {
                BaoLoi("Hãy nhập vật tư cần xóa","","");
                temp = 0;
                break;
            }
            int t = xacnhanluachon();
            if(t == 1) {
                Y.xoaNhanVien(Y.tnv.MANV);
                flag = false;
            } else {
                Normal();
                for(int i = 0; i < 6; i++) {
        gotoxy(35,12+i);
        for (int j = 0; j < 35; j++) {
            cout<<" ";
        }
    }
    if(Y.tnv.MANV!= "") {
        gotoxy(18,12); cout<<"2. Họ và tên nhân viên: "<<Y.Temp->HO<<" "<<Y.Temp->TEN;
        gotoxy(18,14); cout<<"3. Giới tính nhân viên: "<< Y.Temp->PHAI;
    } 
            } break;
    } 
    
} while(flag); break;
} 

    
    case F3: {khungnhap();
        gotoxy(40,8); cout <<"CHỈNH SỬA NHÂN VIÊN"; 
    int temp = 0;
    bool flag = true;
    bool l = true;
    int  t= 3;
    string s[3] = {"1. Nhập mã nhân viên (VD: NV099):"," Hủy "," Xác nhận "};
    for(int i = 0; i < 3; i++) {
        suavt[i] = s[i];
    }
    Y.tnv = {"", "", "", ""};
    do{
    int luachon = X.menunhapVT(suavt, temp, t);
    temp = luachon;
        Normal();
        switch (luachon) {
            case 1: {if(l) {{gotoxy(52,10); cout<<"                   ";gotoxy(52,10);
            getline(cin, Y.tnv.MANV);
           if(!XuLyNhapLieu::chuanHoaMaNV(Y.tnv.MANV)) {
                temp = 0;
                 BaoLoi("Mã nhân viên không", "hợp lệ","");
                 break;
            } gotoxy(52,10);cout<<Y.tnv.MANV;
            if(Y.timkiemtheomanhanvien(Y.tnv)) {
        string s[6] = {"1. Nhập mã nhân viên (VD: NV099):","2. Sửa họ nhân viên:", "3. sửa tên nhân viên:",
        "4. Sửa giới tính nhân viên (VD: Nam/Nữ):", " Hủy "," Xác nhận "};  
 for(int i = 0; i < 6; i++) {
        suavt[i] = s[i];
    }   
        gotoxy(39,12); cout<< Y.Temp->HO;
        gotoxy(40,14);cout<< Y.Temp->TEN;
        gotoxy(59, 16); cout << Y.Temp->PHAI;
        l = false; t = 6;
    }else {
        BaoLoi("Không tìm thấy mã NV để ","chỉnh sửa","");
        temp--;

    } } }break;}
           case 2:  if(t == 3) {
             flag = false; break;}
            gotoxy(39,12); cout<<"                   ";gotoxy(39,12);
            getline(cin, Y.tnv.HO);
             if(!XuLyNhapLieu::chuanHoaTen(Y.tnv.HO)) {
                temp = 1;
                gotoxy(40,12); cout<< Y.tnv.HO;
    gotoxy(41,14);cout<<Y.tnv.TEN;
        gotoxy(60,16); cout<<Y.tnv.PHAI;
            } gotoxy(39,12); cout<<Y.tnv.HO;
            break;
            case 3:  if(t==3)
            { BaoLoi("Hãy nhập nhân viên cần chỉnh sửa","","");
            temp = 0;
             break; }
            gotoxy(40,14); cout<<"                   ";gotoxy(40,14);
            getline(cin, Y.tnv.TEN); 
            if(!XuLyNhapLieu::chuanHoaTen(Y.tnv.TEN)) {
                temp = 1;
                gotoxy(40,12); cout<< Y.tnv.HO;
    gotoxy(41,14);cout<<Y.tnv.TEN;
        gotoxy(60,16); cout<<Y.tnv.PHAI;
            } gotoxy(40,14);cout<<"             ";;gotoxy(40,14);cout<<Y.tnv.TEN;
            break;
            case 4:  gotoxy(59,16); cout<<"                   ";gotoxy(59,16);
            getline(cin, Y.tnv.PHAI);
            if(!XuLyNhapLieu::chuanHoaGioiTinh(Y.tnv.PHAI))  {
                temp = 3;
                gotoxy(40,12); cout<< Y.tnv.HO;
    gotoxy(41,14);cout<<Y.tnv.TEN;
            } gotoxy(59,16); cout<<Y.tnv.PHAI;
            break;
            case 5: flag = false; break;
            case 6: {int t = xacnhanluachon();
            if(t == 1) {
                if(Y.tnv.HO=="")
                {
                    Y.tnv.HO=Y.Temp->HO;
                }
                if(Y.tnv.TEN=="")
                {
                    Y.tnv.TEN=Y.Temp->TEN;
                }
                if(Y.tnv.PHAI=="")
                {
                    Y.tnv.PHAI=Y.Temp->PHAI;
                }
                flag = false;
                Y.suaNhanVien(Y.Temp, Y.tnv);
                  flag = false;
            } else {
                Normal();
                for(int i = 0; i < 6; i++) {
        gotoxy(35,12+i);
        for (int j = 0; j < 35; j++) {
            cout<<" ";
        }
    }
    if(Y.tnv.HO=="")
                {
                 gotoxy(40,12);  cout<< Y.Temp->HO;
                } else {
                    gotoxy(40,12); cout<<Y.tnv.HO;

                }
                if(Y.tnv.TEN=="")
                {
                    gotoxy(41,14);  cout<< Y.Temp->TEN;
                } else {
                    gotoxy(41,14); cout<<Y.tnv.TEN;}
                if(Y.tnv.PHAI=="")
                {
                    gotoxy(60,16);  cout<< Y.Temp->PHAI;
                } else {
                    gotoxy(60,16); cout<<Y.tnv.PHAI;
                }
    break; 
            }
            }
        }
    }while(flag); break;}


    case Up: {if(d<=1) {BaoLoi("Đang là trang đầu tiên!","","");
        break;} 
        v-=20; n-=20; d-=1; break;}
    case Down:{if(n >= Y.dsnv.n) {
        BaoLoi("Đã là trang cuối cùng!","","");break;}
        v+=20; n+=20; d+=1;break;}
    case ESC : { Y.ghifile(); return;}
  }}while (true);
}	

bool nhapmaNV(lopvattu &X, nhanvien &Y) {
    khungnhap(); 
        gotoxy(35,8); cout <<" NHẬP NHÂN VIÊN CẦN LẬP HÓA ĐƠN ";
    int temp = 0;
    bool flag = true;
    do{
    int luachon = X.menunhapVT(xoanv, temp, 3);
    temp = luachon;
        Normal();
    switch (luachon) {
                case 1: {gotoxy(51,10); cout<<"                   ";gotoxy(51,10);
            getline(cin, Y.tnv.MANV);
             if(!XuLyNhapLieu::chuanHoaMaNV(Y.tnv.MANV)) {
                temp = 0;
                gotoxy(49,10); cout<<"                          ";
            } gotoxy(51,10); cout<< Y.tnv.MANV;
             if(Y.timkiemtheomanhanvien(Y.tnv)) {      
        gotoxy(18,12); cout<<"2. Họ và tên nhân viên: "<<Y.Temp->HO<<" "<<Y.Temp->TEN;
        gotoxy(18,14); cout<<"3. Giới tính nhân viên: "<< Y.Temp->PHAI;
    }else {
        BaoLoi("Không tìm thấy mã NV để lập!", "hóa đơn","");
        temp=0;
    }break;  }
            case 2: return 0;
            case 3: if(Y.tnv.MANV == ""|| !Y.timkiemtheomanhanvien(Y.tnv)) {
                BaoLoi("Hãy NV cần lập hóa đơn","","");
                temp = 0;
                break;
            }
            int t = xacnhanluachon();
            if(t == 1) {
                return 1;
            } else {
                Normal();
                for(int i = 0; i < 6; i++) {
        gotoxy(35,12+i);
        for (int j = 0; j < 35; j++) {
            cout<<" ";
        }
    }
    if(Y.tnv.MANV!= "") {
        gotoxy(18,12); cout<<"2. Họ và tên nhân viên: ";cout<<Y.Temp->HO<<" "<<Y.Temp->TEN;
        gotoxy(18,14); cout<<"3. Giới tính nhân viên: ";cout<< Y.Temp->PHAI;
    } 
            } break;
    } 
    
} while(1);
}

void nhapchitiethoadon(lopvattu &X, nhanvien &Y){
    for(int i = 0; i < 200; i++) {
        Y.a3[i].DONGIA = 0;
        Y.a3[i].MAVT = "         ";
        Y.a3[i].soluong = 0;
        Y.a3[i].VAT = 0;
    }
     khungnhap();
     int dem = 0;
     int trigia = 0;
     gotoxy(40, 8); cout <<"NHẬP VẬT TƯ CHO HÓA ĐƠN";
    bool flag = true;
    int temp = 0;
    do{
        X.temptree = NULL;
         gotoxy(18, 17); cout<<"F1: Lui trang     F2: Qua trang";
        gotoxy(70,8); cout<<"Số vật tư: "<<"    "; gotoxy(81,8);cout<<dem + 1;
        Normal();
        int luachon = X.menunhapVT(chitiethoadon,temp, 6);
        temp = luachon;
        Normal();
        switch (luachon) {
            case 1: gotoxy(49,10); cout<<"                   ";gotoxy(49,10);
            getline(cin, Y.a3[dem].MAVT);
            if(!XuLyNhapLieu::chuanHoaMAVT(Y.a3[dem].MAVT)) {
                temp = 0;
                gotoxy(36,12); cout<< Y.a3[dem].soluong;
                gotoxy(35,14);cout<< Y.a3[dem].DONGIA;
                gotoxy(31,16); cout<<Y.a3[dem].VAT;
                break;
            } gotoxy(49,10); cout<< Y.a3[dem].MAVT;
            X.temptree  = X.Tim_kiem_theo_maVT1(X.dsvt, Y.a3[dem].MAVT);
       if(X.temptree == NULL) {
            BaoLoi("Mã VT không đúng định dạng", "hoặc không có trong kho","");
            gotoxy(36,12); cout<< Y.a3[dem].soluong;
                 gotoxy(35,14);cout<< Y.a3[dem].DONGIA;
                gotoxy(31,16); cout<<Y.a3[dem].VAT;

        temp = 0; 
    }    gotoxy(60, 10); cout<<"                ";
    gotoxy(60, 10); cout<<X.temptree->vt.TENVT;
            break;
            case 2:  gotoxy(36,12); cout<<"                   ";gotoxy(36,12);
            Y.a3[dem].soluong = XuLyNhapLieu::ktrasonguyen();
            if (Y.a3[dem].soluong == -1) {
             gotoxy(36,12); cout<< Y.a3[dem].soluong;
                 gotoxy(35,14);cout<< Y.a3[dem].DONGIA;
                gotoxy(31,16); cout<<Y.a3[dem].VAT;
            temp = 1;  
        } break;
            case 3:  gotoxy(35,14); cout<<"                   ";gotoxy(35,14);
            Y.a3[dem].DONGIA = XuLyNhapLieu::ktrasonguyen();
            if (Y.a3[dem].DONGIA == -1) {
             gotoxy(36,12); cout<< Y.a3[dem].soluong;
                 gotoxy(35,14);cout<< Y.a3[dem].DONGIA;
                gotoxy(31,16); cout<<Y.a3[dem].VAT;
            temp = 2;  
        } break;
            case 4: gotoxy(31,16); cout<<"            ";gotoxy(31,16);
            Y.a3[dem].VAT = XuLyNhapLieu::ktrasonguyen();
            if (Y.a3[dem].VAT == -1) {
             gotoxy(36,12); cout<< Y.a3[dem].soluong;
                 gotoxy(35,14);cout<< Y.a3[dem].DONGIA;
                gotoxy(31,16); cout<<Y.a3[dem].VAT;
            temp = 1;  
        } break;
            case 20: if(dem > 0) {
            dem--; 
            gotoxy(49,10); cout << Y.a3[dem].MAVT;
            gotoxy(36,12); cout<< Y.a3[dem].soluong;
            gotoxy(35,14);cout<< Y.a3[dem].DONGIA;
            gotoxy(31,16); cout<<Y.a3[dem].VAT; temp = 0; break;} temp = 0;break;
            case 21: dem++;
            gotoxy(49,10); cout << Y.a3[dem].MAVT;
            gotoxy(36,12); cout<< Y.a3[dem].soluong;
            gotoxy(35,14);cout<< Y.a3[dem].DONGIA;
            gotoxy(31,16); cout<<Y.a3[dem].VAT; temp = 0; break;
            case 5: flag = false; break;
            case 6: int t = xacnhanluachon();
            if(t == 1) {
                // TRƯỚC KHI LƯU HÓA ĐƠN
bool du_hang = true;
for (int i = 0; i < dem; i++) { // dem là số lượng vật tư trong hóa đơn tạm
    if (!X.ktravatu(Y.a3[i].MAVT, "X", Y.a3[i].soluong)) {
        du_hang = false;
        break;
    }
}

if (du_hang) {
    // Nếu đủ hàng cho toàn bộ hóa đơn mới tiến hành trừ kho
    for (int i = 0; i < dem; i++) {
        Y.insert_begin(Y.Temp->dshd, Y.Hd);
        X.nvvattu(Y.a3[i].MAVT, "X", Y.a3[i].soluong); // Trừ kho
        Y.insert_begincthd(Y.PTR->hd.dscthd, Y.a3[i]); // Lưu vào DS liên kết
        Y.mamoinhat.SoHD = Y.Hd.SoHD;
    }
    BaoLoi("Lập hóa đơn thành công!", "", "");
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
    gotoxy(36,12); cout<< Y.a3[dem].soluong;
    gotoxy(35,14);cout<< Y.a3[dem].DONGIA;
    gotoxy(31,16); cout<<Y.a3[dem].VAT;
            } break;
    } 
    } while(flag);}

    void intkhd(nhanvien&Y) {
        char Luachon;
    int d = 1;  
    int n = 20;
    int v = 0;
    do
  {
        system("cls");
        gotoxy(5, 1); cout << "Từ ngày: "<<Y.d1.day<<"/" <<Y.d1.month<<"/"<< Y.d1.year;
            gotoxy(5, 2); cout << "Đến ngày: "<<Y.d2.day<<"/" <<Y.d2.month<<"/"<< Y.d2.year;
    Normal();
    taokhungdanhsach3();
    taoghichumaso3();
     Y.displaytkhd(v,n);
     int m = 0; 
    if(Y.dem3 %20 == 0) {
         m = Y.dem3/20;

     } else {
        m = Y.dem3/20 + 1;
     }
     HighLight();
     gotoxy(90,2); cout<<d<<"/"<<m<<" ";
     Normal();
    Luachon = getch(); 
    if (Luachon == 0) 
    Luachon = getch(); 
    switch (Luachon){
    case Up: {if(d<=1) {BaoLoi("Đang là trang đầu tiên!","","");
        break;} 
        v-=20; n-=20; d-=1; break;}
    case Down:{if(n >= Y.dem3) {
        BaoLoi("Đã là trang cuối cùng!","","");break;}
        v+=20; n+=20; d+=1;break;}
    case ESC : { return;}
  }}while (true);


    }
    void indt(nhanvien&Y) {
        char Luachon;
    int d = 1;  
    int n = 20;
    int v = 0;
    do
  {
        system("cls");
        gotoxy(5, 1); cout << "Từ ngày: "<<Y.d1.day<<"/" <<Y.d1.month<<"/"<< Y.d1.year;
            gotoxy(5, 2); cout << "Đến ngày: "<<Y.d2.day<<"/" <<Y.d2.month<<"/"<< Y.d2.year;
    Normal();
    taokhungdanhsach4();
    taoghichumaso4();
     Y.displayt(v,n);
     HighLight();
     gotoxy(90,2); cout<<d<<"/"<<"1"<<" ";
     Normal();
    Luachon = getch(); 
    if (Luachon == 0) 
    Luachon = getch(); 
    switch (Luachon){
    case Up: {if(d<=1) {BaoLoi("Đang là trang đầu tiên!","","");
        break;} 
        v-=20; n-=20; d-=1; break;}
    case Down:{if(n >= Y.dem4) {
        BaoLoi("Đã là trang cuối cùng!","","");break;}
        v+=20; n+=20; d+=1;break;}
    case ESC : { return;}
  }}while (true);


    }
    void inn(nhanvien&Y) {
        char Luachon;
    int d = 1;  
    int n = 20;
    int v = 0;
    do
  {
        system("cls");
    Normal();
    taokhungdanhsach5();
    taoghichumaso5();
    HighLight();
    gotoxy(71, 1); cout << Y.d1.year;
    Normal();
     Y.displayn(v,n);
     int m = 1; 
     HighLight();
     gotoxy(90,2); cout<<d<<"/"<<m<<" ";
     Normal();
    Luachon = getch(); 
    if (Luachon == 0) 
    Luachon = getch(); 
    switch (Luachon){
    case Up: {if(d<=1) {BaoLoi("Đang là trang đầu tiên!","","");
        break;} 
        v-=20; n-=20; d-=1; break;}
    case Down:{if(n >= 12) {
        BaoLoi("Đã là trang cuối cùng!","","");break;}
        v+=20; n+=20; d+=1;break;}
    case ESC : { return;}
  }}while (true);


    }
    void inchitiethoadon(lopvattu &X, nhanvien &Y, string m) {
        char Luachon;
    int d = 1;  
    int n = 20;
    int v = 0;
    do
  {
    system("cls");
    gotoxy(5, 0); cout<< "Mã hóa đơn: "<<m;
    gotoxy(5, 1); cout<<"Loại hóa đơn: "<<Y.PTRhd->hd.Loai;
    gotoxy(5, 2); cout<<"Ngày lập hóa đơn "<<Y.PTRhd->hd.NgayLapHoaDon.day<<"/"<<Y.PTRhd->hd.NgayLapHoaDon.month
            <<"/"<<Y.PTRhd->hd.NgayLapHoaDon.year;
    gotoxy(60,27); cout<<"TỔNG TRỊ GIÁ HÓA ĐƠN: "<<Y.PTRhd->hd.trigia;
    Normal();
    taokhungdanhsach2();
    taoghichumaso2();
     Y.displaycthd(X, Y.PTRhd, v, n);
     int m = 0; 
    if(Y.b %20 == 0) {
         m = Y.b/20;

     } else {
        m = Y.b/20 + 1;
     }
     HighLight();
     gotoxy(90,2); cout<<d<<"/"<<m<<" ";
     Normal();
    Luachon = getch(); 
    if (Luachon == 0) 
    Luachon = getch(); 
    switch (Luachon){
    case Up: {if(d<=1) {BaoLoi("Đang là trang đầu tiên!","","");
        break;} 
        v-=20; n-=20; d-=1; break;}
    case Down:{if(n >= Y.b) {
        BaoLoi("Đã là trang cuối cùng!","","");break;}
        v+=20; n+=20; d+=1;break;}
    case ESC : { return;}
  }}while (true);


    }

void Case4(lopvattu &X, nhanvien &Y) {
    if(nhapmaNV(X,Y)) {
    char Luachon;
    int d = 1;
    int n = 20;
    int v = 0;
    do
  {
    system("cls");
    Normal();
    gotoxy(5, 1); cout<<"Tên nhân viên: "<<Y.Temp->HO<<" "<<Y.Temp->TEN;
       taokhungdanhsachhoadon();
    taoghichumasocase4();
     Y.display(Y.Temp->dshd, v, n);
    int m = 0; 
     if(Y.a %20 == 0) {
         m = Y.a/20;

     } else {
        m = Y.a/20 + 1;
     }
     HighLight();
     gotoxy(90,2); cout<<d<<"/"<<m<<" ";
     Normal();
    Luachon = getch(); 
    if (Luachon == 0) 
    Luachon = getch(); 
    switch (Luachon){
    case F1:{ khungnhap();
        gotoxy(40,8); cout <<"LẬP HÓA ĐƠN";
    Y.taotaosohdngaylaphd(Y.Hd, Y.mamoinhat);
    bool flag = true;
    int temp = 2;
    gotoxy(33,10); cout<<Y.Hd.SoHD;
    gotoxy(37,12); cout<<Y.Hd.NgayLapHoaDon.day<<"/"<<Y.Hd.NgayLapHoaDon.month
            <<"/"<<Y.Hd.NgayLapHoaDon.year;
    do {
        Normal();
        int luachon = X.menunhapVT(nhaphd,temp, 5);
        temp = luachon;
        Normal();
        switch (luachon) {
            case 1: break;
            case 2: break;
            case 3:  gotoxy(32,14); cout<<"                   ";gotoxy(32,14);
            getline(cin, Y.Hd.Loai);
            if(!XuLyNhapLieu::kiemTraLoaiHoaDon(Y.Hd.Loai)) {
                temp = 2;
                BaoLoi("Sai định dạng","","");
                gotoxy(37,12); cout<<Y.Hd.NgayLapHoaDon.day<<"/"<<Y.Hd.NgayLapHoaDon.month
            <<"/"<<Y.Hd.NgayLapHoaDon.year;
            gotoxy(32,14); cout<<Y.Hd.Loai;
            } gotoxy(32,14);cout<<Y.Hd.Loai;break;
            case 4: flag = false; break;
            case 5: int t = xacnhanluachon();
            if(t == 1) {
                //Y.insert_begin(Y.Temp->dshd, Y.Hd);
                nhapchitiethoadon(X,Y);
                //Y.mamoinhat.SoHD = Y.Hd.SoHD;
                flag = false;
            } else {
                Normal();
                for(int i = 0; i < 6; i++) {
        gotoxy(35,12+i);
        for (int j = 0; j < 35; j++) {
            cout<<" ";
        }
    }
    gotoxy(37,12); cout<<Y.Hd.NgayLapHoaDon.day<<"/"<<Y.Hd.NgayLapHoaDon.month
            <<"/"<<Y.Hd.NgayLapHoaDon.year;break; 
            }
    } 
}while(flag); break;}
    case F2: {khungnhap(); 
        gotoxy(40,8); cout <<"NHẬP MÃ HÓA ĐƠN";
    int temp = 0;
    string mahd;
    bool flag = true;
    do{
    int luachon = X.menunhapVT(nhapmahd, temp, 3);
    temp = luachon;
        Normal();
    switch (luachon) {
                case 1: {gotoxy(33,10); cout<<"                   ";gotoxy(33,10);
            getline(cin, mahd);
    if(Y.timmkiemthomahoadon(mahd)) {      
        gotoxy(18,12); cout<<"2. Loại: "<<Y.PTRhd->hd.Loai;
        gotoxy(18,14); cout<<"3. Ngày lập hóa đơn: "<<Y.PTRhd->hd.NgayLapHoaDon.day<<"/"<<Y.PTRhd->hd.NgayLapHoaDon.month
            <<"/"<<Y.PTRhd->hd.NgayLapHoaDon.year;
    }else {
        BaoLoi("Không tìm thấy mã HD!", "","");
        temp--;
    } }break;
            case 2: flag = false; break;
            case 3: if(Y.tnv.MANV == ""|| !Y.timmkiemthomahoadon(mahd)) {
                BaoLoi("Hãy nhập hóa đơn cần xem","","");
                temp = 0;
                break;
            }
            int t = xacnhanluachon();
            if(t == 1) {
                inchitiethoadon(X, Y, mahd);flag= false;
            } else {
                Normal();
                for(int i = 0; i < 6; i++) {
        gotoxy(35,12+i);
        for (int j = 0; j < 35; j++) {
            cout<<" ";
        }
    }
    if(mahd!= "") {
        gotoxy(18,12); cout<<"2. Loại: "<<Y.PTRhd->hd.Loai;
        gotoxy(18,14); cout<<"3. Ngày lập hóa đơn: "<<Y.PTRhd->hd.NgayLapHoaDon.day<<"/"<<Y.PTRhd->hd.NgayLapHoaDon.month
            <<"/"<<Y.PTRhd->hd.NgayLapHoaDon.year;
    } 
            } break;
    } 
    } while(flag); break;}

    case Up: {if(d<=1) {BaoLoi("Đang là trang đầu tiên!","","");
        break;} 
        v-=20; n-=20; d-=1; break;}
    case Down:{if(n >= Y.a) {
        BaoLoi("Đã là trang cuối cùng!","","");break;}
        v+=20; n+=20; d+=1;break;}
    case ESC : { Y.ghifile(); return;}
    }
}while (true);}
}
int xulyngaythang(nhanvien& Y) {
   int n = XuLyNhapLieu::ktrasonguyen();
            if (n == -1) {
            gotoxy(30,10); cout<< Y.d1.day;
            gotoxy(33,10); cout<< Y.d1.month;
            gotoxy(36,10); cout<< Y.d1.year;
            gotoxy(30,12); cout<< Y.d2.day;
            gotoxy(33, 12); cout << Y.d2.month;
            gotoxy(36, 12); cout<< Y.d2.year;}
            return n;
}
void nhapngaythang(lopvattu& X, nhanvien &Y) {
    khungnhap();
    gotoxy(40,8); cout <<"NHẬP NGÀY THÁNG";
    bool flag = true;
    int temp = 0;
    XuLyNhapLieu::Date d;
    gotoxy(30,10); cout<<"0 /0 /0    ";
    gotoxy(31,12); cout<<"0 /0 /0    ";
    do{
        Normal();
        int luachon = X.menunhapVT(ngaythang,temp, 4);
        temp = luachon;
        Normal();
        switch (luachon) {
            case 1: gotoxy(30,10); cout<<"0 /0 /0              ";
             Nhaplaid11:
             gotoxy(30,10); Y.d1.day = xulyngaythang(Y);
            if(Y.d1.day == -1|| Y.d1.day > 31) {
                goto Nhaplaid11;
            } 
            
            Nhaplaid12:
            gotoxy(33, 10); Y.d1.month =  xulyngaythang(Y);
            if (Y.d1.month == -1 || Y.d1.month > 12) {
                goto Nhaplaid12;
            } 
            Nhaplaid13:
            gotoxy(36, 10);Y.d1.year = xulyngaythang(Y);
            if(Y.d1.year == -1) {
                goto Nhaplaid13;
            }
            break;
            case 2: gotoxy(31,12); cout<<"0 /0 /0            ";
             Nhaplaid21:
             gotoxy(31,12); Y.d2.day = xulyngaythang(Y);
            if(Y.d2.day == -1 || Y.d2.day > 31) {
                goto Nhaplaid21;
            } 
            
            Nhaplaid22:
            gotoxy(34, 12); Y.d2.month =  xulyngaythang(Y);
            if (Y.d2.month == -1 || Y.d2.month > 12) {
                goto Nhaplaid22;
            } 
            Nhaplaid23:
            gotoxy(37, 12);Y.d2.year = xulyngaythang(Y);
            if(Y.d2.year == -1) {
                goto Nhaplaid23;
            }
            break;
            case 3: flag = false; break;
            case 4: int t = xacnhanluachon();
            if(t == 1) {
                Y.thongKeHoaDon(Y.d1, Y.d2);
                intkhd(Y);  flag = false;
            } else {
                Normal();
                for(int i = 0; i < 6; i++) {
        gotoxy(35,12+i);
        for (int j = 0; j < 35; j++) {
            cout<<" ";
        }
    }
    gotoxy(40,12); cout<< Y.d2.day; cout<<Y.d2.month; cout<< Y.d2.year;break; 
            }
    } 
  }while (flag);
}

void nhapngaythang1(lopvattu& X, nhanvien &Y) { 
    khungnhap();
    gotoxy(40,8); cout <<"NHẬP NGÀY THÁNG";
    bool flag = true;
    int temp = 0;
    gotoxy(30,10); cout<<"0 /0 /0    ";
    gotoxy(31,12); cout<<"0 /0 /0    ";
    do{
        Normal();
        int luachon = X.menunhapVT(ngaythang,temp, 4);
        temp = luachon;
        Normal();
        switch (luachon) {
            case 1: gotoxy(30,10); cout<<"0 /0 /0              ";
             Nhaplaid11:
             gotoxy(30,10); Y.d1.day = xulyngaythang(Y);
            if(Y.d1.day == -1|| Y.d1.day > 31) {
                goto Nhaplaid11;
            } 
            
            Nhaplaid12:
            gotoxy(33, 10); Y.d1.month =  xulyngaythang(Y);
            if (Y.d1.month == -1 || Y.d1.month > 12) {
                goto Nhaplaid12;
            } 
            Nhaplaid13:
            gotoxy(36, 10);Y.d1.year = xulyngaythang(Y);
            if(Y.d1.year == -1) {
                goto Nhaplaid13;
            }
            break;
            case 2: gotoxy(31,12); cout<<"0 /0 /0            ";
             Nhaplaid21:
             gotoxy(31,12); Y.d2.day = xulyngaythang(Y);
            if(Y.d2.day == -1 || Y.d2.day > 31) {
                goto Nhaplaid21;
            } 
            
            Nhaplaid22:
            gotoxy(34, 12); Y.d2.month =  xulyngaythang(Y);
            if (Y.d2.month == -1 || Y.d2.month > 12) {
                goto Nhaplaid22;
            } 
            Nhaplaid23:
            gotoxy(37, 12);Y.d2.year = xulyngaythang(Y);
            if(Y.d2.year == -1) {
                goto Nhaplaid23;
            }
            break;
            case 3: flag = false; break;
            case 4: int t = xacnhanluachon();
            if(t == 1) {
                Y.thongKeHoaDon(Y.d1, Y.d2);
                Y.tinhgiatine(X);
                indt(Y);  flag = false;
            } else {
                Normal();
                for(int i = 0; i < 6; i++) {
        gotoxy(35,12+i);
        for (int j = 0; j < 35; j++) {
            cout<<" ";
        }
    }
    gotoxy(40,12); cout<< Y.d2.day; cout<<Y.d2.month; cout<< Y.d2.year;;break; 
            }
    } 
  }while (flag);
}

void nhapngaythangnam(lopvattu& X, nhanvien &Y) { 
    khungnhap();
    gotoxy(40,8); cout <<"THÊM MỚI NHÂN VIÊN";
    bool flag = true;
    int temp = 0;
    do{
        Normal();
        int luachon = X.menunhapVT(nam, temp, 3);
        temp = luachon;
        Normal();
        switch (luachon) {
            case 1: gotoxy(31,10); cout<<"                   ";gotoxy(31,10);
            Y.d1.year = XuLyNhapLieu::ktrasonguyen();
            if(Y.d1.year == -1) {
                temp = 0;
            } break;
            case 2: flag = false; break;
            case 3: if(1) {
                Y.timnam();
                 int t = xacnhanluachon();
            if(t == 1) {
             inn(Y);  flag = false;
            } else {
                Normal();
                for(int i = 0; i < 6; i++) {
        gotoxy(35,12+i);
        for (int j = 0; j < 35; j++) {
            cout<<" ";
        }
    }
        }
    } 

        } 
  }while (flag);
}




int main() {
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
    XuLyNhapLieu Z;
    lopvattu X("DanhSachVatTu.txt");
    nhanvien Y("DanhSachNhanVien.txt", "Danhsachhoadon.txt","Danhsachcautruchoadon.txt");
    int Luachon = 0;
    do
  {
    Luachon = MenuDong (thucdon); Normal();
    //system ("cls");
    switch (Luachon ){
    case 1: Case1(X);break;
    case 2: Case2(X); break;
    case 3: Case3(X,Y); break;
    case 4: Case4(X,Y); break;
    case 5: nhapngaythang(X, Y); break;
    case 6: nhapngaythang1(X, Y); break;
    case 7: nhapngaythangnam(X,Y); break;
    case so_item : { Y.ghifile(); return 0;
   }
  } 
}while (true);
  return 0;
  }
  

   


