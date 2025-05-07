
#include <ansi.h>
#include <task.h>

// 数组：标准提示信息 -- [随意]
mapping TipsTable = ([
    1    :  "Xin lỗi, bạn không có phần thưởng tương ứng.",
    1001 :  "Xin lỗi, bạn không nhận được phần thưởng Tân thủ vương!",
    1004 :  "Xin lỗi, bạn chưa từng tham gia rút thăm trúng thưởng trên client, nên không thể nhận phần thưởng tương ứng!",
    1005 :  "Xin lỗi, bạn chưa từng dùng mã thám bảo để kích hoạt tài khoản tương ứng với nhân vật hiện tại, nên không thể nhận phần thưởng!",
    1006 :  "Xin lỗi! Số tiền bạn nạp trong một lần chưa đủ 100 nguyên bảo, nên không thể nhận được phần thưởng Tử Sâm Đan!",
    1007 :  "Xin lỗi! Số tiền bạn nạp trong một lần chưa đủ 100 nguyên bảo, nên không thể nhận được phiếu đổi thưởng!",
    1008 :  "Bạn phải sử dụng mã kích hoạt vật phẩm từ Đại Thoại Chiến Quốc trên trang web để tham gia sự kiện nhận Gói Thú Cưng Vô Địch.",
    1009 :  "Tài khoản tương ứng với nhân vật này chưa được kích hoạt bằng Mã Duyên Phận! Vì vậy, bạn không thể nhận Thú Cưng Duyên Phận! Nếu muốn biết thêm chi tiết, vui lòng theo dõi thông báo chính thức hoặc truy cập www.zg.mop.com để tra cứu!",
    1010 :  "Tài khoản tương ứng với nhân vật này chưa được kích hoạt bằng Mã Duyên Phận! Vì vậy, bạn không thể nhận Thú Cưng Duyên Phận! Nếu muốn biết thêm chi tiết, vui lòng theo dõi thông báo chính thức hoặc truy cập www.zg.mop.com để tra cứu!",
    1011 :  "Xin lỗi, bạn không phải là người chơi trúng thưởng nên không thể nhận thú cưỡi!",
    1014 :  "Bạn chưa từng mua Thẻ Đổi Thưởng Vàng, làm sao có thể nhận thưởng bừa được?",
]);




// 函数：显示提示信息(地图)
void send_error_tips( object me ) 
{ 
        int id;
	id = me->get("phpnum");

        if( id==0 || !TipsTable[id] ) id = 1;
        send_user( me, "%c%s", ';', TipsTable[id] );
        me->delete("phpnum");
}
