 DỰ ÁN 4: QUẢN LÝ NHẬP XUẤT VẬT TƯ
1. Giới thiệu
Dự án Quản lý nhập xuất vật tư mô phỏng hệ thống quản lý kho hàng trong doanh nghiệp.
Chương trình hỗ trợ quản lý vật tư, nhân viên, lập hóa đơn nhập – xuất, tự động cập nhật tồn kho và thống kê doanh thu theo thời gian.
2. Cấu trúc dữ liệu
🔹 Danh sách Vật tư.
Cấu trúc: Cây nhị phân tìm kiếm cân bằng (AVL)
Thông tin lưu trữ:
Mã vật tư (MAVT – C10)
Tên vật tư
Đơn vị tính (DVT)
Số lượng tồn
🔹 Danh sách Nhân viên
Cấu trúc: Danh sách tuyến tính – mảng con trỏ
Số lượng tối đa: 500 nhân viên
Thông tin lưu trữ:
Mã nhân viên (MANV)
Họ
Tên
Phái
Con trỏ dshd trỏ đến danh sách hóa đơn do nhân viên lập
Danh sách nhân viên luôn được sắp xếp tăng dần theo tên, nếu trùng tên thì tăng theo họ.
🔹 Danh sách Hóa đơn
Cấu trúc: Danh sách liên kết đơn
Thông tin lưu trữ:
Số hóa đơn (SoHD – C20)
Ngày lập hóa đơn
Loại hóa đơn:
N: Phiếu nhập
X: Phiếu xuất
Con trỏ dscthd trỏ đến danh sách chi tiết hóa đơn
🔹 Danh sách Chi tiết hóa đơn
Cấu trúc: Danh sách liên kết đơn
Thông tin lưu trữ:
Mã vật tư (MAVT)
Số lượng
Đơn giá
% VAT
3. Chức năng của chương trình
Cập nhật thông tin vật tư (thêm, xóa, hiệu chỉnh)
In danh sách vật tư tồn kho theo thứ tự tên tăng dần
Cập nhật và in danh sách nhân viên theo thứ tự quy định
Lập hóa đơn nhập / xuất và tự động cập nhật tồn kho
In hóa đơn theo số hóa đơn
Thống kê hóa đơn theo khoảng thời gian
Thống kê vật tư có doanh thu cao
Thống kê doanh thu theo từng tháng trong năm
4. Mô tả chi tiết một số chức năng
📄 Lập hóa đơn nhập / xuất
Nhập số hóa đơn, ngày lập và loại hóa đơn (N hoặc X)
Cho phép nhập nhiều vật tư cho một hóa đơn
Tự động cập nhật số lượng tồn:
Phiếu nhập → tăng tồn
Phiếu xuất → giảm tồn
Nếu số lượng xuất lớn hơn số lượng tồn → báo lỗi và hiển thị tồn kho hiện có
Chỉ cho phép xóa vật tư khi đang lập hóa đơn
Sau khi hóa đơn được ghi, không cho phép chỉnh sửa
🖨️ In hóa đơn
In hóa đơn theo số hóa đơn do người dùng nhập
Nội dung hiển thị:
Ngày lập hóa đơn
Họ tên nhân viên lập
Loại hóa đơn
Danh sách vật tư: tên vật tư, số lượng, đơn giá, trị giá
Tổng trị giá hóa đơn
📊 Thống kê hóa đơn theo khoảng thời gian
Nhập ngày bắt đầu và ngày kết thúc
In ra các hóa đơn được lập trong khoảng thời gian đó
Kết xuất:
Sao chép mã

BẢNG LIỆT KÊ CÁC HÓA ĐƠN TRONG KHOẢNG THỜI GIAN
Từ ngày: ##/##/####     Đến ngày: ##/##/####

Số HĐ | Ngày lập | Loại HĐ | Họ tên NV lập | Trị giá hóa đơn
5. Lưu trữ và kiểm tra dữ liệu
Chương trình cho phép lưu và đọc dữ liệu từ file
Kiểm tra các điều kiện nhập:
Không cho phép dữ liệu rỗng
Không cho trùng mã vật tư, mã nhân viên, số hóa đơn
Kiểm tra số lượng xuất không vượt tồn kho
Kiểm tra định dạng ngày hợp lệ
6. Phân công thực hiện
NGUYỄN NGỌC TOÀN:
Lập hóa đơn nhập và xuất
In hóa đơn
Thống kê hóa đơn theo khoảng thời gian
TRẦN THANH NHUẬN:
Cập nhật thông tin vật tư
In danh sách vật tư tồn kho
Thống kê 10 vật tư có doanh thu cao nhất
NGUYỄN THANH TÚ:
Cập nhật thông tin nhân viên
In danh sách nhân viên
Thống kê doanh thu theo từng tháng trong năm
7. Ngôn ngữ và công cụ
Ngôn ngữ lập trình: C / C++
Cấu trúc dữ liệu: AVL Tree, Linked List, Mảng con trỏ
Xử lý file: fstream
Xử lý chuỗi: stringstream
Chương trình chạy trên môi trường console8. TÀI LIỆU THAM KHẢO
[1] Tham khảo ngôn ngữ C++, cppreference.com.
Truy cập tại: https://en.cppreference.com/w/cpp
[2] Luồng tệp trong C++, cplusplus.com.
Truy cập tại: https://cplusplus.com/doc/tutorial/files/
[3] Luồng chuỗi trong C++, GeeksforGeeks.
Truy cập tại: https://www.geeksforgeeks.org/stringstream-c-applications/
[4] Tạo số ngẫu nhiên trong C++, GeeksforGeeks.
Truy cập tại: https://www.geeksforgeeks.org/generated-random-number-cpp/
[5] std::vector, cppreference.com.
Truy cập tại: https://en.cppreference.com/w/cpp/container/vector
[6] Tiện ích thời gian trong C++, cppreference.com.
Truy cập tại: https://en.cppreference.com/w/cpp/chrono/c/time
[7] Các thao tác nhập xuất trong C++ (iomanip), cppreference.com.
Truy cập tại: https://en.cppreference.com/w/cpp/io/manip
[8] Structs and Classes in C++, Programiz.
Truy cập tại: https://www.programiz.com/cpp-programming/structure
[9] Hàm system() trong C++, cplusplus.com.
Truy cập tại: https://cplusplus.com/reference/cstdlib/system/
[10] Hashing Data Structure, GeeksforGeeks.
Truy cập tại: https://www.geeksforgeeks.org/hashing-data-structure/
