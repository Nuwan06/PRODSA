## 3. Thiết kế dữ liệu và cấu trúc lưu trữ
### 3.1. Danh sách Vật tư ...
Trong chương trình, vật tư được tổ chức...
hoặc tệ hơn là:

css
Sao chép mã
## 3. Thiết kế dữ liệu và cấu trúc lưu trữ ### 3.1. Danh sách Vật tư ...
→ GitHub coi đó là chữ thường, không render heading.

✅ Giải pháp
Mình làm lại TOÀN BỘ README từ đầu đến cuối, đảm bảo:

✔️ Mỗi # / ## / ### đứng đúng chuẩn

✔️ Có dòng trống bắt buộc

✔️ Copy–paste vào README.md → render đẹp 100%

✔️ Không bị “đẹp nửa đầu, xấu nửa sau” nữa

Dưới đây là FULL README ĐÃ SỬA LỖI ĐỊNH DẠNG
👉 Copy NGUYÊN KHỐI, đừng thiếu dòng nào.

md
Sao chép mã
# BÁO CÁO ĐỒ ÁN  
## HỆ THỐNG QUẢN LÝ NHẬP – XUẤT VẬT TƯ

---

## 1. Giới thiệu

Đề tài **Quản lý nhập – xuất vật tư** xây dựng một chương trình dạng **console C++** nhằm hỗ trợ quản lý:

- Danh mục vật tư và số lượng tồn kho  
- Danh sách nhân viên  
- Lập hóa đơn nhập / xuất và chi tiết hóa đơn  
- In hóa đơn và các chức năng thống kê doanh thu  

Chương trình có giao diện console *(vẽ khung, menu, điều hướng bằng phím mũi tên, F1/F2/F3, ESC)* và hỗ trợ **lưu – đọc dữ liệu từ file**.

---

## 2. Yêu cầu bài toán

Hệ thống tổ chức **4 danh sách chính**:

- **Vật tư**: Cây nhị phân tìm kiếm cân bằng theo mã vật tư (`MAVT`)
- **Nhân viên**: Danh sách tuyến tính dạng mảng con trỏ (tối đa 500 nhân viên)
- **Hóa đơn**: Danh sách liên kết đơn theo từng nhân viên
- **Chi tiết hóa đơn**: Danh sách liên kết đơn (mã VT, số lượng, đơn giá, VAT)

### Các chức năng nghiệp vụ

- (a) Nhập / cập nhật vật tư  
- (b) In danh sách vật tư tồn kho theo tên tăng dần  
- (c) Nhập / cập nhật nhân viên  
- (d) In danh sách nhân viên theo tên / họ tăng dần  
- (e) Lập hóa đơn nhập / xuất và cập nhật tồn kho  
- (f) In hóa đơn  
- (g) Thống kê hóa đơn theo thời gian  
- (h) Top 10 vật tư doanh thu cao nhất  
- (i) Thống kê doanh thu theo năm  

---

## 3. Thiết kế dữ liệu và cấu trúc lưu trữ

### 3.1. Danh sách Vật tư (Cây nhị phân tìm kiếm cân bằng)

Trong chương trình, vật tư được tổ chức trong lớp `lopvattu`:

```cpp
struct VatTu {
    char MAVT[10];
    char TENVT[30];
    char DVT[10];
    int SoLuongTon;
    int height;
};

struct nodeVT {
    VatTu vt;
    nodeVT *left, *right;
};
Con trỏ gốc: treeVT dsvt

Ý tưởng triển khai:

Tạo sẵn cây cân bằng với MAX_VatTu node

Mã vật tư gán sẵn dạng VT0001...

Vật tư chưa tồn tại có TENVT == ""

Khi thêm vật tư → tìm node theo mã rồi ghi thông tin

Ưu điểm:

Tìm kiếm nhanh O(log N)

Không cần xoay AVL

3.2. Danh sách Nhân viên (Mảng con trỏ)
cpp
Sao chép mã
struct NhanVien {
    int MANV;
    char HO[20];
    char TEN[20];
    char PHAI[5];
    PTRHD dshd;
};

struct DSNV {
    int n;
    NhanVien* nodes[MAX_NHANVIEN];
};
Danh sách luôn sắp:

Tên tăng dần

Trùng tên → họ tăng dần

Thực hiện bằng insert_order()

3.3. Danh sách Hóa đơn
cpp
Sao chép mã
struct HoaDon {
    char SoHD[20];
    Date NgayLapHoaDon;
    char Loai;
    float trigia;
    PTRCTHD dscthd;
};

struct nodeHD {
    HoaDon hd;
    nodeHD* next;
};
Mỗi nhân viên có danh sách hóa đơn riêng

Loai: N (nhập) hoặc X (xuất)

3.4. Danh sách Chi tiết hóa đơn
cpp
Sao chép mã
struct CT_HoaDon {
    char MAVT[10];
    int soluong;
    float DONGIA;
    float VAT;
};
4. Thiết kế chức năng và luồng xử lý
4.1. Giao diện menu
Điều khiển bằng phím mũi tên + Enter

Có phân trang khi in danh sách

4.2. Nhập & in vật tư
Kiểm tra định dạng VTxxxx

In theo mã hoặc theo tên

4.3. Nhập & in nhân viên
Không cho phép dữ liệu rỗng

Luôn duy trì thứ tự

4.4. Lập hóa đơn nhập / xuất
Nhập số HĐ, ngày, loại

Tự động cập nhật tồn kho

Thiếu hàng → báo lỗi

4.5. In hóa đơn
In chi tiết + tổng trị giá

4.6. Thống kê hóa đơn theo thời gian
Lọc theo khoảng ngày

In dạng bảng

4.7. Top 10 vật tư doanh thu cao nhất
Gom doanh thu

Sắp xếp giảm dần

4.8. Thống kê doanh thu theo năm
Cộng doanh thu theo từng tháng

5. Lưu và đọc file dữ liệu
5.1. Ghi file
Ghi nhân viên, hóa đơn, chi tiết hóa đơn

Ký hiệu . kết thúc danh sách

5.2. Đọc file
Đọc theo thứ tự: NV → HĐ → CTHĐ

6. Cài đặt và chạy chương trình
6.1. Yêu cầu
C++ compiler

Windows (khuyến nghị)

6.2. Biên dịch
bash
Sao chép mã
g++ d.cpp -o ql_vattu
6.3. Chạy
bash
Sao chép mã
./ql_vattu
7. Thành viên tham gia & Phân công
🔹 Nguyễn Ngọc Toàn
Lập hóa đơn

In hóa đơn

Thống kê theo thời gian

🔹 Trần Thanh Nhuận
Quản lý vật tư

In tồn kho

Top 10 vật tư

🔹 Nguyễn Thanh Tú
Quản lý nhân viên

Thống kê doanh thu năm

8. Kết luận – Hướng phát triển
Chuẩn hóa tính trị giá hóa đơn

Cải thiện so sánh ngày

Chuẩn hóa định dạng file

TÀI LIỆU THAM KHẢO
[1] https://en.cppreference.com/w/
[2] https://cplusplus.com/doc/tutorial/files/
[3] https://www.geeksforgeeks.org/binary-search-tree-data-structure/
[4] https://www.geeksforgeeks.org/data-structures/linked-list/
