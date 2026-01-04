BÁO CÁO ĐỒ ÁN
HỆ THỐNG QUẢN LÝ NHẬP – XUẤT VẬT TƯ
1. Giới thiệu

Đề tài “Quản lý nhập – xuất vật tư” xây dựng một chương trình dạng console C++ nhằm hỗ trợ quản lý:

Danh mục vật tư và số lượng tồn kho

Danh sách nhân viên

Lập hóa đơn nhập/xuất và chi tiết hóa đơn

In hóa đơn và các chức năng thống kê doanh thu

Chương trình có giao diện console (vẽ khung, menu, điều hướng bằng phím mũi tên, F1/F2/F3, ESC), đồng thời hỗ trợ lưu và đọc dữ liệu từ file để tái sử dụng qua các lần chạy.

2. Yêu cầu bài toán

Hệ thống phải tổ chức 4 danh sách chính:

Vật tư: cây nhị phân tìm kiếm cân bằng theo mã vật tư (MAVT)

Nhân viên: danh sách tuyến tính dạng mảng con trỏ (tối đa 500 NV), sắp theo tên/họ

Hóa đơn: danh sách liên kết đơn theo từng nhân viên

Chi tiết hóa đơn: danh sách liên kết đơn (mã vật tư, số lượng, đơn giá, VAT)

Các chức năng nghiệp vụ:

(a) Nhập/cập nhật vật tư (thêm/xóa/sửa)

(b) In danh sách vật tư tồn kho theo tên tăng dần

(c) Nhập/cập nhật nhân viên (không rỗng, sắp theo tên/họ)

(d) In danh sách nhân viên theo tên/họ tăng dần

(e) Lập hóa đơn nhập/xuất và tự động cập nhật tồn kho

(f) In hóa đơn theo số hóa đơn

(g) Thống kê hóa đơn trong khoảng thời gian

(h) In 10 vật tư doanh thu cao nhất trong khoảng thời gian

(i) Thống kê doanh thu theo từng tháng của một năm

3. Thiết kế dữ liệu và cấu trúc lưu trữ
3.1. Danh sách Vật tư (cây nhị phân tìm kiếm cân bằng)

Trong code, vật tư được tổ chức trong lớp lopvattu với:

struct VatTu { MAVT, TENVT, DVT, SoLuongTon, height }

struct nodeVT { VatTu vt; nodeVT *left, *right; }

Con trỏ gốc treeVT dsvt

Ý tưởng triển khai nổi bật trong code:

Chương trình tạo sẵn một cây cân bằng gồm MAX_VatTu node bằng hàm taocaynhiphancanbang(start,end).

Mỗi node được gán sẵn mã VT0001 … theo midpoint để cây cân bằng.

Một vật tư “chưa tồn tại thực” được đánh dấu bằng TENVT == "".

Khi thêm vật tư, chương trình tìm node theo MAVT (Tim_kiem_theo_maVT) rồi ghi thông tin vào node đó.

➡️ Cách làm này giúp:

Tìm theo mã vật tư nhanh (O(log N))

Không cần thao tác xoay AVL phức tạp, vì cây đã cân bằng sẵn theo mã

3.2. Danh sách Nhân viên (mảng con trỏ)

Trong lớp nhanvien:

struct NhanVien { MANV, HO, TEN, PHAI, PTRHD dshd }

struct DSNV { int n; NhanVien* nodes[MAX_NhanVien]; }

Danh sách luôn được sắp theo:

TEN tăng dần

Nếu trùng TEN → HO tăng dần

Code thực hiện bằng hàm insert_order() (dịch mảng để chèn đúng vị trí).

3.3. Danh sách Hóa đơn (danh sách liên kết đơn)

struct HoaDon { SoHD, NgayLapHoaDon, Loai, trigia, PTRCTHD dscthd }

struct nodeHD { HoaDon hd; nodeHD* next }

Mỗi nhân viên có dshd trỏ đến danh sách hóa đơn do nhân viên đó lập.
Hóa đơn có Loai nhận N hoặc X.

Trong code có hỗ trợ:

Tạo node hóa đơn: create_node()

Chèn đầu danh sách: insert_begin()

Đảo danh sách khi đọc file: reverse() (vì lúc đọc chèn đầu)

3.4. Danh sách Chi tiết hóa đơn

struct CT_HoaDon { MAVT, soluong, DONGIA, VAT, tongtienthoethang }

struct nodeCTHD { CT_HoaDon cthd; nodeCTHD* next }

Có các hàm:

create_nodecthd(), insert_begincthd(), reverscthd() và hàm hiển thị chi tiết.

4. Thiết kế chức năng và luồng xử lý
4.1. Giao diện menu và điều khiển

Chương trình có menu lựa chọn (điều khiển bằng phím mũi tên và Enter).
Trong code có các thành phần:

Vẽ khung, ghi chú hướng dẫn phím

Phân trang khi in danh sách (Up/Down để chuyển trang)

4.2. Nhập vật tư (a) và in vật tư (b)

Nhập vật tư: kiểm tra định dạng mã vật tư VTxxxx (chuẩn hóa in hoa và padding số)

In danh sách vật tư:

In theo mã: duyệt LNR để lấy node có TENVT != ""

In theo tên: code có màn hình riêng “DS VẬT TƯ SẮP XẾP THEO TÊN” (có chức năng sắp theo tên)

4.3. Nhập nhân viên (c) và in nhân viên (d)

Thêm nhân viên vào DSNV, kiểm tra rỗng

Duy trì thứ tự bằng insert_order()

In nhân viên theo danh sách đã sắp

4.4. Lập hóa đơn nhập/xuất (e)

Luồng nghiệp vụ đúng yêu cầu:

Nhập thông tin hóa đơn: số HĐ/ngày/loại

Nhập danh sách vật tư (MAVT, số lượng, đơn giá, VAT)

Theo loại hóa đơn:

Nếu N: tăng tồn kho

Nếu X: giảm tồn kho

Nếu không đủ tồn → báo lỗi và hiển thị tồn hiện có

Trong code có hỗ trợ sinh số hóa đơn theo thời gian và tăng tự động:

Hàm taotaosohdngaylaphd() tạo SoHD theo dạng HD<year><month><####>

4.5. In hóa đơn (f)

Tìm hóa đơn theo số hóa đơn trong danh sách hóa đơn của nhân viên

In các dòng chi tiết: tên vật tư/ số lượng/ đơn giá/ VAT/ trị giá

Tính tổng trị giá hóa đơn

4.6. Thống kê hóa đơn theo khoảng thời gian (g)

Nhập từ ngày – đến ngày

Lọc các hóa đơn thuộc khoảng thời gian

In danh sách dạng bảng: số HĐ, ngày, loại, NV lập, trị giá

Trong code, dữ liệu thống kê được đưa vào mảng trung gian:

a1[] lưu con trỏ hóa đơn và thông tin NV để dễ phân trang/hiển thị.

4.7. Top 10 vật tư doanh thu cao nhất (h)

Dựa trên các hóa đơn trong khoảng thời gian

Cộng gộp doanh thu theo mã vật tư

Sắp xếp giảm dần và in top 10

Trong code có hướng xử lý cộng gộp qua tinhgiatine():

Duyệt các hóa đơn đã lọc, gom doanh thu theo MAVT

4.8. Thống kê doanh thu theo tháng của 1 năm (i)

Nhập năm thống kê

Duyệt toàn bộ hóa đơn của tất cả nhân viên

Cộng doanh thu theo tháng

Trong code có 2 hướng:

thongKeDoanhThuTheoNam(namThongKe) tính theo CT_HoaDon (có VAT)

timnam() cộng theo hd.trigia (cần thống nhất lại cách tính “trị giá” để tránh lệch)

5. Lưu và đọc file dữ liệu

Chương trình có cơ chế đọc/ghi:

File nhân viên

File hóa đơn

File chi tiết hóa đơn

5.1. Ghi file

Trong code có hàm ghifile():

Mở 3 file output (trunc)

Ghi từng nhân viên: MANV,HO,TEN,PHAI

Ghi hóa đơn theo nhân viên (kèm dấu kết thúc .)

Ghi chi tiết hóa đơn theo từng SoHD (kèm dấu kết thúc .)

5.2. Đọc file

Trong code có mofile():

Đọc nhân viên → với mỗi nhân viên gọi mofilehoadon() để đọc danh sách hóa đơn

Mỗi hóa đơn lại gọi mofilechitiethoadon() để đọc chi tiết

Cách dùng ký hiệu:

Dòng . để kết thúc danh sách

Một số dòng header được bỏ qua trong lúc đọc (theo điều kiện ký tự đầu dòng)

6. Cài đặt và chạy chương trình
6.1. Yêu cầu hệ thống

C++ compiler (g++, clang++, Visual Studio)

Windows (khuyến nghị vì dùng conio.h, getch(), system("cls") và thư viện console)

6.2. Biên dịch

Ví dụ (MinGW g++):

g++ d.cpp -o ql_vattu

6.3. Chạy
./ql_vattu


Nếu lỗi thiếu mylib.h / gotoxy / SetColor…:
Hãy đặt mylib.h đúng đường dẫn hoặc sửa include thành "mylib.h".
