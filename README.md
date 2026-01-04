# BÁO CÁO ĐỒ ÁN  
## HỆ THỐNG QUẢN LÝ NHẬP – XUẤT VẬT TƯ

---

## 1. Giới thiệu

Đề tài **Quản lý nhập – xuất vật tư** xây dựng một chương trình dạng **console C++** nhằm hỗ trợ quản lý:

- Danh mục vật tư và số lượng tồn kho  
- Danh sách nhân viên  
- Lập hóa đơn nhập / xuất và chi tiết hóa đơn  
- In hóa đơn và các chức năng thống kê doanh thu  

Chương trình có giao diện console *(vẽ khung, menu, điều hướng bằng phím mũi tên, F1/F2/F3, ESC)*, đồng thời hỗ trợ **lưu và đọc dữ liệu từ file** để tái sử dụng qua các lần chạy.

---

## 2. Yêu cầu bài toán

Hệ thống tổ chức **4 danh sách chính**:

- **Vật tư**: Cây nhị phân tìm kiếm cân bằng theo mã vật tư (`MAVT`)
- **Nhân viên**: Danh sách tuyến tính dạng mảng con trỏ (tối đa 500 nhân viên)
- **Hóa đơn**: Danh sách liên kết đơn theo từng nhân viên
- **Chi tiết hóa đơn**: Danh sách liên kết đơn (mã vật tư, số lượng, đơn giá, VAT)

### Các chức năng nghiệp vụ

- (a) Nhập / cập nhật vật tư (thêm / xóa / sửa)  
- (b) In danh sách vật tư tồn kho theo tên tăng dần  
- (c) Nhập / cập nhật nhân viên (không rỗng)  
- (d) In danh sách nhân viên theo tên / họ tăng dần  
- (e) Lập hóa đơn nhập / xuất và tự động cập nhật tồn kho  
- (f) In hóa đơn theo số hóa đơn  
- (g) Thống kê hóa đơn trong một khoảng thời gian  
- (h) In 10 vật tư có doanh thu cao nhất trong khoảng thời gian  
- (i) Thống kê doanh thu theo từng tháng của một năm  

---

## 3. Thiết kế dữ liệu và cấu trúc lưu trữ

### 3.1. Danh sách Vật tư (Cây nhị phân tìm kiếm cân bằng)

Vật tư được tổ chức trong lớp `lopvattu` với cấu trúc dữ liệu:

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
Con trỏ gốc của cây: treeVT dsvt

Ý tưởng triển khai:

Tạo sẵn cây cân bằng gồm MAX_VatTu node

Gán mã vật tư dạng VT0001...

Vật tư chưa tồn tại được đánh dấu TENVT == ""

Khi thêm vật tư, tìm node theo mã và ghi thông tin

Ưu điểm:

Tìm kiếm nhanh theo mã vật tư O(log N)

Không cần xoay AVL phức tạp

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
Danh sách nhân viên luôn được sắp:

Theo tên tăng dần

Nếu trùng tên thì họ tăng dần

Thực hiện bằng hàm insert_order()

3.3. Danh sách Hóa đơn (Danh sách liên kết đơn)
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

Loai:

N: Phiếu nhập

X: Phiếu xuất

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
Kiểm tra định dạng mã vật tư VTxxxx

In danh sách theo mã hoặc theo tên

4.3. Nhập & in nhân viên
Không cho phép dữ liệu rỗng

Luôn duy trì thứ tự danh sách

4.4. Lập hóa đơn nhập / xuất
Nhập số hóa đơn, ngày lập, loại

Tự động cập nhật số lượng tồn kho

Thiếu hàng → báo lỗi và hiển thị số lượng tồn hiện có

4.5. In hóa đơn
In chi tiết từng vật tư trong hóa đơn

Tính và in tổng trị giá hóa đơn

4.6. Thống kê hóa đơn theo khoảng thời gian
Nhập từ ngày – đến ngày

Lọc và in danh sách hóa đơn theo dạng bảng

4.7. Top 10 vật tư có doanh thu cao nhất
Gom doanh thu theo mã vật tư

Sắp xếp giảm dần và in 10 vật tư cao nhất

4.8. Thống kê doanh thu theo năm
Nhập năm cần thống kê

Cộng doanh thu theo từng tháng

5. Lưu và đọc file dữ liệu
5.1. Ghi file
Ghi danh sách nhân viên

Ghi danh sách hóa đơn

Ghi chi tiết hóa đơn

Sử dụng ký hiệu . để kết thúc mỗi danh sách

5.2. Đọc file
Đọc danh sách nhân viên

Đọc hóa đơn theo từng nhân viên

Đọc chi tiết hóa đơn theo số hóa đơn

6. Cài đặt và chạy chương trình
6.1. Yêu cầu hệ thống
Trình biên dịch C++ (g++, clang++, Visual Studio)

Hệ điều hành Windows (khuyến nghị)

6.2. Biên dịch
bash
Sao chép mã
g++ d.cpp -o ql_vattu
6.3. Chạy chương trình
bash
Sao chép mã
./ql_vattu
Nếu lỗi thiếu mylib.h, gotoxy, SetColor…
Hãy đặt mylib.h đúng đường dẫn hoặc sửa include thành "mylib.h".

7. Thành viên tham gia & Phân công công việc
🔹 Nguyễn Ngọc Toàn – Quản lý Hóa đơn & Thống kê
Lập hóa đơn nhập / xuất

In hóa đơn

Thống kê hóa đơn theo thời gian

🔹 Trần Thanh Nhuận – Quản lý Vật tư
Nhập và cập nhật vật tư

In danh sách vật tư tồn kho

Top 10 vật tư doanh thu cao nhất

🔹 Nguyễn Thanh Tú – Quản lý Nhân viên & Doanh thu
Nhập và in danh sách nhân viên

Thống kê doanh thu theo năm

8. Kết luận – Hướng phát triển
Chương trình đáp ứng đầy đủ yêu cầu quản lý vật tư, nhân viên, hóa đơn và thống kê.

Hướng phát triển:

Chuẩn hóa cách tính trị giá hóa đơn

Cải thiện thuật toán so sánh ngày tháng

Chuẩn hóa định dạng file dữ liệu

TÀI LIỆU THAM KHẢO
[1] https://en.cppreference.com/w/
[2] https://cplusplus.com/doc/tutorial/files/
[3] https://www.geeksforgeeks.org/binary-search-tree-data-structure/
[4] https://www.geeksforgeeks.org/data-structures/linked-list/
[5] https://www.geeksforgeeks.org/array-of-pointers-in-c/
