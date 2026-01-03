ĐỒ ÁN QUẢN LÝ NHẬP XUẤT VẬT TƯ
1. Giới thiệu
Đây là chương trình Quản lý nhập – xuất vật tư được xây dựng nhằm hỗ trợ quản lý kho hàng, nhân viên và hóa đơn nhập/xuất.
Chương trình cho phép cập nhật vật tư, nhân viên, lập hóa đơn, thống kê doanh thu và báo cáo theo nhiều tiêu chí khác nhau.
2. Cấu trúc dữ liệu sử dụng
2.1. Danh sách Vật tư
Lưu trữ bằng cây nhị phân tìm kiếm cân bằng (AVL)
Thuộc tính:
MAVT (C10)
TENVT
DVT (Đơn vị tính)
Soluongton
2.2. Danh sách Nhân viên
Lưu bằng mảng con trỏ (tối đa 500 nhân viên)
Thuộc tính:
MANV
HO
TEN
PHAI
dshd (con trỏ đến danh sách hóa đơn của nhân viên)
Danh sách luôn tăng dần theo tên, nếu trùng tên thì tăng theo họ.
2.3. Danh sách Hóa đơn
Danh sách liên kết đơn
Thuộc tính:
SoHD (C20)
NgayLap
Loai (N – Nhập, X – Xuất)
dscthd (con trỏ đến danh sách chi tiết hóa đơn)
2.4. Danh sách Chi tiết hóa đơn
Danh sách liên kết đơn
Thuộc tính:
MAVT
Soluong
Dongia
%VAT
3. Các chức năng của chương trình
a. Quản lý vật tư
Thêm / xóa / hiệu chỉnh vật tư
Chỉ cho phép nhập số lượng tồn khi thêm vật tư mới
b. In danh sách vật tư tồn kho
In ra theo thứ tự tên vật tư tăng dần
Kết xuất:
Sao chép mã

Mã VT | Tên vật tư | Đơn vị tính | Số lượng tồn
c. Quản lý nhân viên
Thêm, cập nhật thông tin nhân viên
Không cho phép các trường mã, họ, tên, phái rỗng
Danh sách tăng dần theo tên, nếu trùng thì theo họ
d. In danh sách nhân viên
In theo thứ tự tăng dần tên → họ
Mỗi nhân viên một dòng
e. Lập hóa đơn nhập / xuất
Nhập: số hóa đơn, ngày lập, loại (N hoặc X)
Nhập các vật tư cho hóa đơn
Tự động cập nhật số lượng tồn:
Phiếu nhập → tăng tồn
Phiếu xuất → giảm tồn
Nếu xuất vượt tồn kho → báo lỗi và hiển thị số lượng hiện có
Chỉ được xóa vật tư khi đang lập hóa đơn
Khi hóa đơn đã ghi → không được chỉnh sửa
f. In hóa đơn
In theo số hóa đơn nhập vào
Kết xuất:
Sao chép mã

Ngày lập, Họ tên NV, Loại HĐ
Tên vật tư, Số lượng, Đơn giá, Trị giá
Tổng trị giá hóa đơn
g. Thống kê hóa đơn theo khoảng thời gian
Nhập: từ ngày – đến ngày
In ra các hóa đơn trong khoảng đó
Kết xuất:
Sao chép mã

Số HĐ | Ngày lập | Loại | Họ tên NV | Trị giá hóa đơn
h. In 10 vật tư có doanh thu cao nhất
Thống kê trong khoảng thời gian do người dùng nhập
i. Thống kê doanh thu theo tháng trong năm
Nhập năm cần thống kê
Kết xuất:
Sao chép mã

BẢNG THỐNG KÊ DOANH THU NĂM ####
Tháng | Doanh thu
4. Lưu trữ dữ liệu
Chương trình cho phép lưu và đọc dữ liệu từ file
Đảm bảo dữ liệu không bị mất khi thoát chương trình
5. Kiểm tra và ràng buộc dữ liệu
Kiểm tra dữ liệu rỗng
Kiểm tra trùng mã
Kiểm tra số lượng xuất không vượt tồn kho
Kiểm tra định dạng ngày tháng hợp lệ
6. Phân công công việc
Thành viên
Chức năng đảm nhận
Toàn
e, f, g
Nhuận
a, b, h
Tú
c, d, i
7. Ngôn ngữ & Môi trường
Ngôn ngữ: C / C++
Mô hình dữ liệu: Cây AVL, danh sách liên kết đơn, mảng con trỏ
Chạy trên môi trường console
