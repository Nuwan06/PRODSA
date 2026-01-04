# BÁO CÁO ĐỒ ÁN  
# HỆ THỐNG QUẢN LÝ NHẬP – XUẤT VẬT TƯ

---

## 1. Giới thiệu

Đề tài **“Quản lý nhập – xuất vật tư”** xây dựng một chương trình dạng **console C++** nhằm hỗ trợ quản lý:

- Danh mục vật tư và số lượng tồn kho  
- Danh sách nhân viên  
- Lập hóa đơn nhập / xuất và chi tiết hóa đơn  
- In hóa đơn và các chức năng thống kê doanh thu  

Chương trình có giao diện console *(vẽ khung, menu, điều hướng bằng phím mũi tên, F1/F2/F3, ESC)*, đồng thời hỗ trợ **lưu và đọc dữ liệu từ file** để tái sử dụng qua các lần chạy.

---

## 2. Yêu cầu bài toán

Hệ thống tổ chức **4 danh sách chính**:

- **Vật tư**: Cây nhị phân tìm kiếm cân bằng theo mã vật tư (`MAVT`)
- **Nhân viên**: Danh sách tuyến tính dạng mảng con trỏ (tối đa 500 NV), sắp theo tên/họ
- **Hóa đơn**: Danh sách liên kết đơn theo từng nhân viên
- **Chi tiết hóa đơn**: Danh sách liên kết đơn (`MAVT`, số lượng, đơn giá, VAT)

### Các chức năng nghiệp vụ
- (a) Nhập / cập nhật vật tư (thêm / xóa / sửa)
- (b) In danh sách vật tư tồn kho theo tên tăng dần
- (c) Nhập / cập nhật nhân viên (không rỗng, sắp theo tên/họ)
- (d) In danh sách nhân viên theo tên/họ tăng dần
- (e) Lập hóa đơn nhập / xuất và tự động cập nhật tồn kho
- (f) In hóa đơn theo số hóa đơn
- (g) Thống kê hóa đơn trong một khoảng thời gian
- (h) In 10 vật tư có doanh thu cao nhất trong khoảng thời gian
- (i) Thống kê doanh thu theo từng tháng của một năm

---

## 3. Thiết kế dữ liệu và cấu trúc lưu trữ

### 3.1. Danh sách Vật tư (Cây nhị phân tìm kiếm cân bằng)

Trong chương trình, vật tư được tổ chức trong lớp `lopvattu`:

```cpp
struct VatTu { MAVT, TENVT, DVT, SoLuongTon, height };
struct nodeVT { VatTu vt; nodeVT *left, *right; };
Con trỏ gốc: treeVT dsvt

Ý tưởng triển khai:

Tạo sẵn cây cân bằng gồm MAX_VatTu node bằng hàm taocaynhiphancanbang(start, end)

Gán sẵn mã VT0001 ... theo midpoint

Vật tư chưa tồn tại được đánh dấu TENVT == ""

Khi thêm vật tư, tìm node theo mã (Tim_kiem_theo_maVT) và ghi thông tin

➡️ Ưu điểm:

Tìm kiếm nhanh theo mã vật tư O(log N)

Không cần xoay AVL vì cây đã cân bằng sẵn

3.2. Danh sách Nhân viên (Mảng con trỏ)
cpp
Sao chép mã
struct NhanVien { MANV, HO, TEN, PHAI, PTRHD dshd };
struct DSNV { int n; NhanVien* nodes[MAX_NhanVien]; };
Danh sách luôn sắp:

Tên tăng dần

Nếu trùng tên → Họ tăng dần

Thực hiện bằng hàm insert_order()

3.3. Danh sách Hóa đơn (Danh sách liên kết đơn)
cpp
Sao chép mã
struct HoaDon { SoHD, NgayLapHoaDon, Loai, trigia, PTRCTHD dscthd };
struct nodeHD { HoaDon hd; nodeHD* next };
Mỗi nhân viên có dshd trỏ đến danh sách hóa đơn

Loai:

N – Phiếu nhập

X – Phiếu xuất

Các hàm chính:

create_node()

insert_begin()

reverse() (đảo danh sách khi đọc file)

3.4. Danh sách Chi tiết hóa đơn
cpp
Sao chép mã
struct CT_HoaDon { MAVT, soluong, DONGIA, VAT, tongtienthoethang };
struct nodeCTHD { CT_HoaDon cthd; nodeCTHD* next };
Các hàm xử lý:

create_nodecthd()

insert_begincthd()

reverscthd()

4. Thiết kế chức năng và luồng xử lý
4.1. Giao diện menu
Menu điều khiển bằng phím mũi tên + Enter

Có vẽ khung, hướng dẫn phím

Phân trang khi in danh sách (Up / Down)

4.2. Nhập và in vật tư (a, b)
Kiểm tra định dạng mã VTxxxx

In danh sách:

Theo mã: duyệt LNR

Theo tên: màn hình riêng “DS VẬT TƯ SẮP XẾP THEO TÊN”

4.3. Nhập và in nhân viên (c, d)
Kiểm tra dữ liệu không rỗng

Duy trì thứ tự bằng insert_order()

In danh sách theo thứ tự đã sắp

4.4. Lập hóa đơn nhập / xuất (e)
Nhập: số HĐ, ngày lập, loại

Nhập danh sách vật tư

Tự động cập nhật tồn kho:

N → tăng tồn

X → giảm tồn (thiếu hàng → báo lỗi)

Sinh số HĐ tự động:

cpp
Sao chép mã
taotaosohdngaylaphd(); // HD<year><month><####>
4.5. In hóa đơn (f)
Tìm theo số hóa đơn

In chi tiết + tổng trị giá

4.6. Thống kê hóa đơn theo thời gian (g)
Nhập từ ngày – đến ngày

Lọc hóa đơn và in dạng bảng

Dùng mảng trung gian a1[] để phân trang

4.7. Top 10 vật tư doanh thu cao nhất (h)
Gom doanh thu theo mã vật tư

Sắp xếp giảm dần

In 10 vật tư cao nhất

4.8. Thống kê doanh thu theo năm (i)
Nhập năm

Cộng doanh thu theo từng tháng

5. Lưu và đọc file dữ liệu
5.1. Ghi file
Hàm ghifile()

Ghi:

Nhân viên

Hóa đơn

Chi tiết hóa đơn

Dùng ký hiệu . để kết thúc danh sách

5.2. Đọc file
Hàm mofile()

Gọi lần lượt:

mofilehoadon()

mofilechitiethoadon()

6. Cài đặt và chạy chương trình
6.1. Yêu cầu hệ thống
Trình biên dịch C++ (g++, clang++, Visual Studio)

Windows (khuyến nghị)

6.2. Biên dịch
bash
Sao chép mã
g++ d.cpp -o ql_vattu
6.3. Chạy
bash
Sao chép mã
./ql_vattu
Nếu lỗi thiếu mylib.h, gotoxy, SetColor…
Hãy đặt mylib.h đúng đường dẫn hoặc sửa include thành "mylib.h".

7. Thành viên tham gia & Phân công công việc
🔹 Nguyễn Ngọc Toàn – Quản lý Hóa đơn & Thống kê
Phụ trách:

Lập hóa đơn nhập / xuất

In hóa đơn

Thống kê hóa đơn theo thời gian

🔹 Trần Thanh Nhuận – Quản lý Vật tư
Phụ trách:

Nhập / cập nhật vật tư

In danh sách vật tư tồn kho

Top 10 vật tư doanh thu cao nhất

🔹 Nguyễn Thanh Tú – Quản lý Nhân viên & Doanh thu
Phụ trách:

Nhập / in nhân viên

Thống kê doanh thu theo năm

8. Kết luận – Hướng phát triển
Chương trình đáp ứng đầy đủ yêu cầu quản lý vật tư, nhân viên, hóa đơn và thống kê.

Hướng phát triển:

Chuẩn hóa cách tính trị giá hóa đơn

Cải thiện so sánh ngày tháng

Chuẩn hóa định dạng file dữ liệu

TÀI LIỆU THAM KHẢO
[1] C++ Language Reference, cppreference.com
https://en.cppreference.com/w/

[2] File Streams in C++, cplusplus.com
https://cplusplus.com/doc/tutorial/files/

[3] Binary Search Tree, GeeksforGeeks
https://www.geeksforgeeks.org/binary-search-tree-data-structure/

[4] Linked List Data Structure, GeeksforGeeks
https://www.geeksforgeeks.org/data-structures/linked-list/

[5] Array of Pointers in C++, GeeksforGeeks
https://www.geeksforgeeks.org/array-of-pointers-in-c/
