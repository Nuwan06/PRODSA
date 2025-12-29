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

string thucdon[so_item] = {"1. In danh sách vật tư theo mã số        ",
			               "2. In danh sách vật tư theo tên          ", 
                           "3. In danh sách nhân viên theo tên       ",
                           "4. Lập hóa đơn      ",
                           "5. Thpnh ke hoa don",
                           "6. thong ke tien",
                           "7. in nam",
						   "8. Kết thúc chương trình             "};
string nhapvt[6] = {"1. Nhập mã vật tư(VD: VT0099):","2. Nhập tên vật tư:", "3. Nhập đơn vị tính:","4. Nhập số lượng tồn(0-9):",
 " Hủy "," Xác nhận "};
string xoavt[3] = {"Nhập mã vật tư(VD: VT0099):"," Hủy "," Xác nhận "};
string suavt[5] = {"Nhập mã vật tư(VD: VT0099):", "", ""," Hủy "," Xác nhận "};
string laphoadon[5] = {"1. Số hóa đơn:", "2. Ngày lập hóa đơn:","3. Loại hóa đơn:"," Hủy "," Xác nhận "};
string chitiethoadon[6] = {"1. Nhập mã vật tư(VD: VT0099):","2. Nhập số lượng", "3. Nhập đơn giá:","4. Nhập VAT:",
    " Hủy "," Xác nhận "};
string ngaythang[4] = {"1. Từ ngày:", "2. Đến ngày:",  " Hủy ", " Xác nhận "};
string nam[3] = {"1. năm:",  " Hủy ", " Xác nhận "};

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
    gotoxy(8,4); cout<<" MãVT";
    gotoxy(15, 4); cout<<"║"; cout<<" Tên vật tư";
    gotoxy(38, 4); cout<<"║"; cout<<" Đơn vị tính";
    gotoxy(61, 4);cout<<"║"; cout<< " Số lượng tồn";
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
void taoghichumaso() {
    HighLight();
    gotoxy(40,1); cout<<"   DANH SÁCH VẬT TƯ   ";
    Normal();
    gotoxy(9, 27); cout<<"F1: Thêm VT    F2: Xóa VT    F3: Chỉnh sửa VT    ⭡: Len    ⭣: Xuong    ESC: Để thoát";
}

void taoghichumaso1() {
    gotoxy(8,4); cout<<" MãNV";
    gotoxy(15, 4); cout<<"║"; cout<<" Họ nhân viên";
    gotoxy(38, 4); cout<<"║"; cout<<" tên nhân viên";
    gotoxy(61, 4);cout<<"║"; cout<< " Giới tính";
    HighLight();
    gotoxy(40,1); cout<<"   DANH SÁCH NHÂN VIÊN   ";
    Normal();
    gotoxy(9, 27); cout<<"F1: Thêm NV    ⭡: Len    ⭣: Xuong    ESC: Để thoát";
}
void ghichucase2() {
     HighLight();
    gotoxy(40,1); cout<<"   DANH SÁCH VẬT TƯ SẮP XẾP THEO TÊN   ";
    Normal();
    gotoxy(9, 27); cout<<"⭡: Len    ⭣: Xuong    ESC: Để thoát";
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
            BaoLoi("Ma vat tu phai bat dau bang","VT.","");
            return false;
        }

        // lay phan so
        string so = "";
        for (int i = 2; i < input.length(); i++) {
            if (input[i] >= '0' && input[i] <= '9')
                so += input[i];
            else {
                cout << "Ma vat tu chi duoc chua so sau VT.\n";
                return false;
            }
        }

        if (so.length() == 0) {
            cout << "Chua nhap so cho ma vat tu.\n";
            return false;
        }

        int num = 0;
        for (int i = 0; i < so.length(); i++)
            num = num * 10 + (so[i] - '0');

        if (num < 0 || num > 9999) {
            BaoLoi("Ma vat tu chi tu VT0000 den", "VT9999.","");
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

    // chuan hoa ten (viet hoa chu cai dau moi tu)
    static string chuanHoaTen(string s) {
        // xoa khoang trang dau
        while (s.length() > 0 && s[0] == ' ')
            s.erase(0, 1);

        // xoa khoang trang cuoi
        while (s.length() > 0 && s[s.length() - 1] == ' ')
            s.erase(s.length() - 1, 1);

        // xoa khoang trang thua giua
        for (int i = 0; i < s.length() - 1; i++) {
            if (s[i] == ' ' && s[i + 1] == ' ') {
                s.erase(i, 1);
                i--;
            }
        }

        bool dauTu = true;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == ' ')
                dauTu = true;
            else {
                if (dauTu) {
                    if (s[i] >= 'a' && s[i] <= 'z')
                        s[i] -= 32;
                    dauTu = false;
                }
                else {
                    if (s[i] >= 'A' && s[i] <= 'Z')
                        s[i] += 32;
                }
            }
        }
        return s;
    }

    // kiem tra nam nhuan
    static bool laNamNhuan(int nam) {
        if (nam % 400 == 0) return true;
        if (nam % 100 == 0) return false;
        if (nam % 4 == 0) return true;
        return false;
    }

    // kiem tra ngay hop le
    static bool kiemTraNgayHopLe(Date d) {
        if (d.year < 1900 || d.year > 2100) return false;
        if (d.month < 1 || d.month > 12) return false;
        if (d.day < 1) return false;

        int soNgay = 0;
        if (d.month == 1 || d.month == 3 || d.month == 5 ||
            d.month == 7 || d.month == 8 || d.month == 10 || d.month == 12)
            soNgay = 31;
        else if (d.month == 4 || d.month == 6 ||
            d.month == 9 || d.month == 11)
            soNgay = 30;
        else {
            if (laNamNhuan(d.year)) soNgay = 29;
            else soNgay = 28;
        }

        return d.day <= soNgay;
    }

    // kiem tra loai hoa don N / X
    static bool kiemTraLoaiHoaDon(char loai) {
        if (loai >= 'a' && loai <= 'z')
            loai -= 32;

        return (loai == 'N' || loai == 'X');
    }
    static int ktrasonguyen() {
        int n;
       cin >> n;
            if (cin.fail()) {
            BaoLoi("Số lượng tồn không đúng định","dạng","");
            return -1;
            cin.clear();
        }
        if (n < 0 ) {  
            BaoLoi("lượng tồn không thể là số âm","","");
            return -1;
        } return n;
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

void Liet_ke_danh_sach_VT_theo_Ten() {
    Duyet_cay_vao_Manng_LNR(dsvt);
    quickSort(a, 0, index - 1);
    for(int i = 0; i < index && a[i] != NULL; i++) {     
            cout << a[i] ->vt.MAVT<<","<<a[i]->vt.TENVT<<","<<a[i]->vt.DVT<<","<<a[i]->vt.SoLuongTon<<endl;
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
    do
  {
    system("cls");
    Normal();
    taokhungdanhsach();
    taoghichumaso();
     X.liet_ke_danh_sach_VT_theo_MaSo(v,n);
     int m = X.kt/20 > 0 ? X.kt/20 : 1;
     HighLight();
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
                //gotoxy(49,10); cout<<"                                   ";
                break;
            }
            break;
            case 2:  gotoxy(38,12); cout<<"                      ";gotoxy(38,12);
             getline(cin, X.vattu.TENVT);break;
            case 3:  gotoxy(39,14); cout<<"                   ";gotoxy(39,14);
            getline(cin, X.vattu.DVT);break;
            case 4: gotoxy(45,16); cout<<"            ";gotoxy(45,16);
            X.vattu.SoLuongTon = XuLyNhapLieu::ktrasonguyen();
            if (X.vattu.SoLuongTon == -1) {
            temp = 3;
            break;  
        } break;
            case 5: flag = false; break;
            case 6: X.temptree  = X.Tim_kiem_theo_maVT(X.dsvt, X.vattu.MAVT);
       if(X.temptree == NULL) {
            BaoLoi("Mã VT không đúng định dạng", "hoặc lớn hơn 1000","");
        temp = 0; break;}    int t = xacnhanluachon();
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
    } while(flag); break;}
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
    } while(flag); break;}
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
    } while(flag); break;}

    case Up: {if(d<=1) {BaoLoi("Đang là trang đầu tiên!","","");
        break;} 
        v-=20; n-=20; d-=1; break;}
    case Down:{if(n >= X.kt) {
        BaoLoi("Đã là trang cuối cùng!","","");break;}
        v+=20; n+=20; d+=1;break;}
    case ESC : { X.ghifile(); return;}
  }}while (true);
}

void Case2(lopvattu &X) {
    char Luachon;
    int d = 1;
    int n = 20;
    int v = 0;
    do
  {
    system("cls");
    Normal();
    taokhungdanhsach();
    taoghichumaso();
     X.liet_ke_danh_sach_VT_theo_MaSo(v,n);
     int m = X.kt/20 > 0 ? X.kt/20 : 1;
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
        long long doanhthuthang  =0;
    };
    nam Nam[12];
    DSNV dsnv;
    NhanVien tnv;
    int a =0;
    int b = 0;
    int dem = 0; int dem2 = 0; int dem3 = 0; int dem4 = 0;
    Date d1, d2;
    thongkehoadon a1[1000];
    PTRCTHD a2[5000];
    NhanVien Temp;
    CT_HoaDon a3[200];
    HoaDon Hd;
    PTRHD PTR;
    PTRCTHD PTRCT;
    nhanvien(string Filenhanvien, string Filehoadon, string Filechitiethoadon) {
        filenhanvien = Filenhanvien;
        filehoadon = Filehoadon;
        filechitiethoadon = Filechitiethoadon;
        mofile();
    }

        void insert_order(int n, NhanVien* node[]) {
             for(int i = 0; i < dsnv.n; i++) {
                if(dsnv.nodes[dsnv.n]->TEN[0] < dsnv.nodes[i]->TEN[0]) {
                    swap(dsnv.nodes[dsnv.n], dsnv.nodes[i]);
                    return;
                } else if (dsnv.nodes[dsnv.n]->TEN[0] == dsnv.nodes[i]->TEN[0]){
                    if(dsnv.nodes[dsnv.n]->HO[0] < dsnv.nodes[i]->HO[0]) {
                        swap(dsnv.nodes[dsnv.n] , dsnv.nodes[i]);
                        return;
                    }

                }
            }

        }

    void nhapNV(NhanVien Node, int f) {
        
        dsnv.nodes[dsnv.n] = new NhanVien;
        dsnv.nodes[dsnv.n]->MANV = Node.MANV;
        dsnv.nodes[dsnv.n]->HO = Node.HO;
        dsnv.nodes[dsnv.n]->TEN = Node.TEN;
        dsnv.nodes[dsnv.n]->PHAI = Node.PHAI;
        dsnv.nodes[dsnv.n]->dshd = Node.dshd;
        if(f) {
        insert_order(dsnv.n, dsnv.nodes);
        }
    }
    bool timkiemtheomanhanvien(NhanVien nv) {
        for(int i = 0; i < dsnv.n; i++) {
            if(dsnv.nodes[i]->MANV == nv.MANV)  {
                Temp.HO =  dsnv.nodes[i]->HO;
                Temp.TEN = dsnv.nodes[i]->TEN;
                Temp.PHAI = dsnv.nodes[i]->PHAI;
                Temp.dshd = dsnv.nodes[i]->dshd;
                return 1;

            }

        } return 0;

    }
    bool timmkiemthomahoadon(string mahd) {
        PTRHD temp = Temp.dshd;
        while(temp!=NULL) {
            if(mahd == temp->hd.SoHD) {
                PTRCT = temp->hd.dscthd;
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
               << temp->hd.NgayLapHoaDon.year << endl;
        
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
void mofilechitiethoadon(HoaDon &hd, PTRCTHD &temp, ifstream &ct) {
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
            hd.trigia+= cthd.DONGIA;
            insert_begincthd(temp, cthd);
        }
    }

}
void mofilehoadon(PTRHD &temp, ifstream &h, ifstream &cthd) {
    string loai;
    string d,m,y;
    if(h.is_open()) {
        string line;
        while(getline(h, line)){
            if(line[0] == 'N'&&line[1]=='V') {
                continue;
            }
            if(line[0] == '.'|| line == "") {
                reverse(temp);
                return;
            }
            stringstream ss(line);
            HoaDon hd;
            getline(ss, hd.SoHD,',');
            getline(ss, hd.Loai, ',');  
            getline(ss, d, '/');
            getline(ss, m, '/');
            getline(ss, y);
            hd.NgayLapHoaDon.day = stoi(d);
            hd.NgayLapHoaDon.month = stoi(m);
            hd.NgayLapHoaDon.year = stoi(y);
            hd.dscthd = NULL;
            mofilechitiethoadon(hd, hd.dscthd, cthd);
            insert_begin(temp, hd);
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
     cout<<"Hoàn thành thêm node vào đầu"<<endl; 
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
void  docthdvaomang(PTRCTHD cthd) {
    b = 0;
      PTRCTHD temp = cthd;
    for(int i = 0; temp != NULL && i <500; i++) {
        b++;
        a2[i] = temp;
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
            cout << a1[i].ptrhd->hd.SoHD; gotoxy(16,6+cot);cout<<a1[i].ptrhd->hd.Loai;gotoxy(39,6+cot);
            cout<< a1[i].ptrhd->hd.NgayLapHoaDon.day<<"/"<<a1[i].ptrhd->hd.NgayLapHoaDon.month<<"/"<<a1[i].ptrhd->hd.NgayLapHoaDon.year;
         cot++; 
    }
}
void displaytkhd( int v, int n){//duyệt danh sách 
     if (a1[0].ptrhd == NULL){ 
          cout<<"Danh sách rỗng"<<endl; 
          return; 
     }  
      int cot = 0;
        for(int i = v; i < n && i < dem3; i++) {    
        gotoxy(8, 6+cot);
            cout << a1[i].ptrhd->hd.SoHD; gotoxy(16,6+cot);cout<<a1[i].ptrhd->hd.Loai;gotoxy(39,6+cot);
            cout<< a1[i].ptrhd->hd.NgayLapHoaDon.day<<"/"<<a1[i].ptrhd->hd.NgayLapHoaDon.month<<"/"<<
            a1[i].ptrhd->hd.NgayLapHoaDon.year; gotoxy(50, 6+cot); cout<<a1[i].maNV;gotoxy(60, 6+cot);
             cout<< a1[i].ptrhd->hd.trigia;
         cot++; 
    }
}

void displayt( int v, int n){//duyệt danh sách 
     if (a2[0] == NULL){ 
          cout<<"Danh sách rỗng"<<endl; 
          return; 
     }  
      int cot = 0;
        for(int i = v; i < n&&i<dem4; i++) {    
        gotoxy(8, 6+cot);
            cout << a2[i]->cthd.MAVT; gotoxy(16,6+cot);cout<<a2[i]->cthd.tongtienthoethang;
         cot++; 
    }
}
void displayn( int v, int n){//duyệt danh sách 
          int cot = 0;
        for(int i = v; i < n&&i<12; i++) {    
        gotoxy(8, 6+cot);
            cout << Nam[i].thang; gotoxy(16,6+cot);cout<< Nam[i].doanhthuthang;
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
     cout<<"Hoàn thành thêm node vào đầu"<<endl; 
}   
void displaycthd(PTRCTHD Cthd, int v, int n){//duyệt danh sách 
    if (Cthd == NULL){ 
          cout<<"Danh sách rỗng"<<endl; 
          return; 
     } 
        docthdvaomang(Cthd);
      int cot = 0;
        for(int i = v; i < n && i < b; i++) {    
        gotoxy(8, 6+cot);
            cout << a2[i]->cthd.MAVT; gotoxy(16,6+cot);cout<<a2[i]->cthd.soluong;gotoxy(39,6+cot);
            cout<< a2[i]->cthd.DONGIA;gotoxy(62,6+cot); cout<<a2[i]->cthd.VAT<<"%";
         cot++;
    }
} 
void taotaosohdngaylaphd(HoaDon &hd) {
    int temp;
    time_t now = time(0);
        tm* local_time = localtime(&now);
        hd.NgayLapHoaDon.year = local_time->tm_year + 1900;
        hd.NgayLapHoaDon.month = local_time->tm_mon + 1;//hd2025120001
        hd.NgayLapHoaDon.day = local_time->tm_mday;
    int soThuTu = 0;
    // Kiểm tra xem nhân viên này đã có hóa đơn nào chưa
    if (Temp.dshd != NULL) {
        // Giả sử Temp.dshd đang trỏ tới hóa đơn mới nhất (đã sort hoặc insert head)
        string soHDCu = Temp.dshd->hd.SoHD; 
        // Cắt chuỗi lấy 4 số cuối: HD202512[0001]
        string soCu = soHDCu.substr(soHDCu.length() - 4); 
        soThuTu = stoi(soCu);
    }
    
    soThuTu++; // Tăng lên 1
    
    // Format lại chuỗi (ví dụ: HD2025120001)
    stringstream ss;
    ss << "HD" << hd.NgayLapHoaDon.year << hd.NgayLapHoaDon.month 
       << setfill('0') << setw(4) << soThuTu; 
    hd.SoHD = ss.str();

}
bool timngaythang(Date d1,Date d2) {
    dem3 = 0;
    for(int i = 0; i <= dsnv.n; i++) {
        PTRHD temp = dsnv.nodes[i]->dshd;
         while(temp != NULL) {
            if(temp->hd.NgayLapHoaDon.day <= d2.day && temp->hd.NgayLapHoaDon.month <= d2.month && 
                temp->hd.NgayLapHoaDon.year <= d2.year) {
                    a1[dem3].maNV = dsnv.nodes[i]->HO+dsnv.nodes[i]->TEN;
                    while(temp != NULL) {
                        if(temp->hd.NgayLapHoaDon.day < d1.day && temp->hd.NgayLapHoaDon.month < d1.month && 
                temp->hd.NgayLapHoaDon.year < d1.year) {
                        break;}
                        a1[dem3].ptrhd = temp;
                        dem3++;
                        temp = temp->next;
                }   
                break;
                }
                temp = temp->next;
            }
    } 
    if(dem3!=0) return 1;
         return 0;
}
void tinhgiatine() {
    bool flag;
    dem4 = 0;
    for(int i = 0; i < dem3; i++) {
        PTRCTHD temp = a1[i].ptrhd->hd.dscthd;
        while(temp != NULL) {
            for(int i =0; i < dem4 ; i++) {
                if(temp->cthd.MAVT == a2[i]->cthd.MAVT) {
                    flag = true;
                    a2[i]->cthd.tongtienthoethang += temp->cthd.DONGIA;
                }
            }
            if(!flag) {
                a2[dem4] = temp; 
                a2[dem4]->cthd.tongtienthoethang = temp->cthd.DONGIA;
                dem4++;
            }
            flag = false;
            temp = temp->next;
        }
    }
}

void timnam() {
    for(int i = 0; i <= dsnv.n; i++) {
        PTRHD temp = dsnv.nodes[i]->dshd;
         while(temp != NULL) {
            if(temp->hd.NgayLapHoaDon.year == d1.year) { 
                Nam[temp->hd.NgayLapHoaDon.month - 1].thang = temp->hd.NgayLapHoaDon.month;
                Nam[temp->hd.NgayLapHoaDon.month - 1].doanhthuthang+= temp->hd.trigia;
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
        "Nhập giới tính nhân viên (VD: Nam/Nữ):"," Hủy "," Xác nhận "};
    char Luachon;
    int d = 1;
    int n = 20;
    int v = 0;
    do
  {
    system("cls");
    Normal();
    taokhungdanhsach();
    taoghichumaso1();
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
            case 1: gotoxy(51,10); cout<<"                   ";gotoxy(51,10);
            getline(cin, Y.tnv.MANV);break;
            case 2:  gotoxy(40,12); cout<<"                   ";gotoxy(40,12);
            getline(cin, Y.tnv.HO);break;
            case 3:  gotoxy(41,14); cout<<"                   ";gotoxy(41,14);
            getline(cin, Y.tnv.TEN);break;
            case 4: gotoxy(53,16); cout<<"            ";gotoxy(53,16);
            getline(cin, Y.tnv.PHAI);
            break;
            case 5: flag = false; break;
            case 6: if(Y.timkiemtheomanhanvien(Y.tnv) == 1) {
            BaoLoi("Mã NV bị trùng", "hoặc lớn hơn 100","");
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
    gotoxy(53,16);cout<< Y.tnv.PHAI;break; 
            }
    } 
    } while(flag); break;}

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
        gotoxy(40,8); cout <<"XÓA VẬT TƯ";
    int temp = 0;
    bool flag = true;
    do{
    int luachon = X.menunhapVT(xoavt, temp, 3);
    temp = luachon;
        Normal();
    switch (luachon) {
                case 1: {gotoxy(47,10); cout<<"                   ";gotoxy(47,10);
            getline(cin, Y.Temp.MANV);
    if(Y.timkiemtheomanhanvien(Y.Temp)) {      
        gotoxy(18,12); cout<<"Tên vật tư: "<<Y.Temp.HO<<" "<<Y.Temp.TEN;
        gotoxy(18,14); cout<<"Đơn vị tính: "<< Y.Temp.PHAI;
    }else {
        BaoLoi("Không tìm thấy mã VT để xóa!", "","");
        temp--;
    } }break;
            case 2: return 0;
            case 3: if(Y.Temp.MANV == ""|| !Y.timkiemtheomanhanvien(Y.Temp)) {
                BaoLoi("Hãy nhập vật tư cần xóa","","");
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
    if(X.vattu.MAVT != "") {
        gotoxy(18,12); cout<<"Tên vật tư: "<<Y.Temp.HO<<" "<<Y.Temp.TEN;
        gotoxy(18,14); cout<<"Đơn vị tính: "<< Y.Temp.PHAI;
    } 
            } break;
    } 
    
} while(1);
}

void nhapchitiethoadon(lopvattu &X, nhanvien &Y){
     khungnhap();
     int dem = 0;
     gotoxy(40,8); cout <<"THÊM MỚI VẬT TƯ";
    X.vattu = {"", "", "", -1};
    bool flag = true;
    int temp = 0;
    do{
        Normal();
        int luachon = X.menunhapVT(chitiethoadon,temp, 6);
        dem++;
        temp = luachon;
        Normal();
        switch (luachon) {
            case 1: gotoxy(49,10); cout<<"                   ";gotoxy(49,10);
            getline(cin, Y.a3[dem].MAVT);break;
            case 2:  gotoxy(38,12); cout<<"                   ";gotoxy(38,12);
            cin>> Y.a3[dem].soluong;break;
            case 3:  gotoxy(39,14); cout<<"                   ";gotoxy(39,14);
            cin>> X.vattu.DVT;break;
            case 4: gotoxy(45,16); cout<<"            ";gotoxy(45,16);
            cin >> X.vattu.SoLuongTon;
            break;
            case 20: dem--; 
            gotoxy(49,10); cout << Y.a3[dem].MAVT;
            gotoxy(38,12); cout<< Y.a3[dem].soluong;
            gotoxy(39,14);cout<< Y.a3[dem].DONGIA;
            gotoxy(45,16); cout<<Y.a3[dem].VAT; temp = 0; break;
            case 21: dem++;
            gotoxy(49,10); cout << Y.a3[dem].MAVT;
            gotoxy(38,12); cout<< Y.a3[dem].soluong;
            gotoxy(39,14);cout<< Y.a3[dem].DONGIA;
            gotoxy(45,16); cout<<Y.a3[dem].VAT; temp = 0; break;
            case 5: flag = false; break;
            case 6: int t = xacnhanluachon();
            if(t == 1) {
                for(int i = dem; i >= 0; i--) {
                    Y.insert_begincthd(Y.Temp.dshd->hd.dscthd, Y.a3[i]);
                }  flag = false;
            } else {
                Normal();
                for(int i = 0; i < 6; i++) {
        gotoxy(35,12+i);
        for (int j = 0; j < 35; j++) {
            cout<<" ";
        }
    }
    gotoxy(38,12); cout<< Y.a3[dem].soluong;
    gotoxy(39,14);cout<< Y.a3[dem].DONGIA;
    gotoxy(45,16); cout<<Y.a3[dem].VAT;
            } break;
    } 
    } while(flag);}

    void in(nhanvien&Y, string s) {
        char Luachon;
    int d = 1;
    int n = 20;
    int v = 0;
    do
  {
        system("cls");
    Normal();
    taokhungdanhsach();
    taoghichumaso();
    if(s== "incthd") {
     Y.displaycthd(Y.PTRCT, v, n);
    } else if(s == "intkhd") {
        Y.displaytkhd(v, n);
    } else if(s =="int") {
        Y.displayt(v, n);
    } else if(s =="inn") {
        Y.displayn(v, n);
    }
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
    void inchitiethoadon(nhanvien &Y) {
    if(nhapmaNV) {
    in(Y, "incthd");
} 
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
    taokhungdanhsach();
    taoghichumaso();
     Y.display(Y.Temp.dshd, v, n);
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
        gotoxy(40,8); cout <<"THÊM MỚI VẬT TƯ";
    X.vattu = {"", "", "", -1};
    Y.taotaosohdngaylaphd(Y.Hd);
    bool flag = true;
    int temp = 2;
        Normal();
        int luachon = X.menunhapVT(nhapvt,temp, 6);
          gotoxy(49,10); cout<<Y.Hd.SoHD;
         gotoxy(38,12); cout<<Y.Hd.NgayLapHoaDon.day<<"/"<<Y.Hd.NgayLapHoaDon.month
            <<"/"<<Y.Hd.NgayLapHoaDon.year;
        temp = luachon;
        Normal();
        switch (luachon) {
            case 1: break;
            case 2: break;
            case 3:  gotoxy(39,14); cout<<"                   ";gotoxy(39,14);
            getline(cin, Y.Hd.Loai);break;
            case 5: flag = false; break;
            case 6: int t = xacnhanluachon();
            if(t == 1) {
                Y.insert_begin(Y.Temp.dshd, Y.Hd);  flag = false;
                nhapchitiethoadon(X,Y);
            } else {
                Normal();
                for(int i = 0; i < 6; i++) {
        gotoxy(35,12+i);
        for (int j = 0; j < 35; j++) {
            cout<<" ";
        }
    }
    gotoxy(38,12); cout<<Y.Hd.NgayLapHoaDon.day<<"/"<<Y.Hd.NgayLapHoaDon.month
            <<"/"<<Y.Hd.NgayLapHoaDon.year;break; 
            }
    } 
     while(flag); break;}
    case F2: {khungnhap(); 
        gotoxy(40,8); cout <<"XÓA VẬT TƯ";
    int temp = 0;
    string mahd;
    bool flag = true;
    do{
    int luachon = X.menunhapVT(xoavt, temp, 3);
    temp = luachon;
        Normal();
    switch (luachon) {
                case 1: {gotoxy(47,10); cout<<"                   ";gotoxy(47,10);
            getline(cin, mahd);
    if(Y.timmkiemthomahoadon(mahd)) {      
        gotoxy(18,12); cout<<"Tên vật tư: "<<Y.PTRCT->cthd.soluong;
        gotoxy(18,14); cout<<"Đơn vị tính: "<< Y.PTRCT->cthd.DONGIA;
        gotoxy(18, 16); cout<<"Vat: " << Y.PTRCT->cthd.VAT; 
    }else {
        BaoLoi("Không tìm thấy mã VT để xóa!", "","");
        temp--;
    } }break;
            case 2: flag = false;
            case 3: if(Y.Temp.MANV == ""|| !Y.timmkiemthomahoadon(mahd)) {
                BaoLoi("Hãy nhập vật tư cần xóa","","");
                temp = 0;
                break;
            }
            int t = xacnhanluachon();
            if(t == 1) {
                inchitiethoadon(Y);
            } else {
                Normal();
                for(int i = 0; i < 6; i++) {
        gotoxy(35,12+i);
        for (int j = 0; j < 35; j++) {
            cout<<" ";
        }
    }
    if(X.vattu.MAVT != "") {
        gotoxy(18,12); cout<<"Tên vật tư: "<<Y.Temp.HO<<" "<<Y.Temp.TEN;
        gotoxy(18,14); cout<<"Đơn vị tính: "<< Y.Temp.PHAI;
    } 
            } break;
    } 
    
} while(flag); break;}
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
    } while(flag); break;}

    case Up: {if(d<=1) {BaoLoi("Đang là trang đầu tiên!","","");
        break;} 
        v-=20; n-=20; d-=1; break;}
    case Down:{if(n >= Y.a) {
        BaoLoi("Đã là trang cuối cùng!","","");break;}
        v+=20; n+=20; d+=1;break;}
    case ESC : { Y.ghifile(); return;}
  }}while (true);
} 
}

void nhapngaythang(lopvattu& X, nhanvien &Y) {
    khungnhap();
    gotoxy(40,8); cout <<"THÊM MỚI NHÂN VIÊN";
    bool flag = true;
    int temp = 0;
    do{
        Normal();
        int luachon = X.menunhapVT(ngaythang,temp, 4);
        temp = luachon;
        Normal();
        switch (luachon) {
            case 1: gotoxy(51,10); cout<<"                   ";gotoxy(51,10);
            cin>> Y.d1.day; cin>>Y.d1.month; cin>> Y.d1.year; break;
            case 2:  gotoxy(40,12); cout<<"                   ";gotoxy(40,12);
            cin>> Y.d2.day; cin>>Y.d2.month; cin>> Y.d2.year; break;
            case 3: flag = false; break;
            case 4: if(Y.timngaythang(Y.d1, Y.d2)) {
                 int t = xacnhanluachon();
            if(t == 1) {
                in(Y, "intkhd");  flag = false;
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

            } 
    

  }while (flag);
}

void nhapngaythang1(lopvattu& X, nhanvien &Y) { 
    khungnhap();
    gotoxy(40,8); cout <<"THÊM MỚI NHÂN VIÊN";
    bool flag = true;
    int temp = 0;
    do{
        Normal();
        int luachon = X.menunhapVT(ngaythang,temp, 4);
        temp = luachon;
        Normal();
        switch (luachon) {
            case 1: gotoxy(51,10); cout<<"                   ";gotoxy(51,10);
            cin>> Y.d1.day; cin>>Y.d1.month; cin>> Y.d1.year; break;
            case 2:  gotoxy(40,12); cout<<"                   ";gotoxy(40,12);
            cin>> Y.d2.day; cin>>Y.d2.month; cin>> Y.d2.year; break;
            case 3: flag = false; break;
            case 4: if(Y.timngaythang(Y.d1, Y.d2)) {
                Y.tinhgiatine();
                 int t = xacnhanluachon();
            if(t == 1) {

                in(Y, "int");  flag = false;
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
            case 1: gotoxy(51,10); cout<<"                   ";gotoxy(51,10);
            cin>> Y.d1.year; break;
            case 3: flag = false; break;
            case 4: if(1) {
                Y.timnam();
                 int t = xacnhanluachon();
            if(t == 1) {
             in(Y,"inn");  flag = false;
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
  

   


