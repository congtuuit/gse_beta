
#include <npc.h>
#include <city.h>
#include <ansi.h>

inherit SAVE_F;
inherit OFFICER;

void do_bonus(string arg);
int get_char_picid() { return 5302; }

void create()
{
	int i, size, * nTmp;
	set_name("Nhân Viên Ký Gửi KNB");

	set_2("talk", ([
		"bonus":(: do_bonus:),
	]));

	setup();
}

void do_look(object who)
{
	__FILE__->do_look_2(who, this_object());
}

void do_look_2(object who, object me)
{
	int id;
	id = getoid(me);
	send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(),
		me->get_name() + ":\n    Tôi đến từ tổng giám đốc của cửa hàng, ở đây để mọi người phải trả một xác minh công bằng, ER có thể yên tâm để đặt một số thẻ trong tay tôi, tôi sẽ đóng vai trò là một công chứng viên theo ủy thác!\n"
		+ sprintf(ESC"ĐIỀU KHOẢN KÝ GỬI\ntalk %x# bonus.1\n"
			ESC HIY"Ta muốn ký gửi\ntalk %x# bonus.10\n"
			ESC HIC"Ta muốn thu mua KNB\ntalk %x# bonus.20\n"
			ESC"Truy vấn KNB của tôi đã ký gửi\nconsign status\n"
			ESC"Rời khỏi.", id, id, id));
}


void do_bonus(string arg)
{
	__FILE__->do_bonus_2(this_player(), this_object(), arg);
}

void do_bonus_2(object me, object who, string arg)
{
	int id, flag;
	string result;
	flag = to_int(arg);
	id = getoid(who);
	switch (flag)
	{
	case 1:
		result = sprintf("%s：\n   Người gửi hàng phải trả trước một khoản phí ký gửi là 1.000 kho báu trong khi ký gửi thỏi. Sau khi bán thẻ điểm thành công, tôi có thể cung cấp cho bạn tám giờ, mười hai giờ hoặc 24 giờ dịch vụ ký gửi. Sau nhiều thời gian, thẻ điểm bạn đã được ký gửi đã được mua, tôi sẽ trả Yuanbao bạn đã vận chuyển. Dưới kệ, các phôi được xử lý để được xử lý vẫn còn hiệu lực và chúng có thể được yêu cầu một lần nữa!\n", who->get_name());
		result += ESC"Rời khỏi.";
		send_user(me, "%c%c%w%s", ':', 3, who->get_char_picid(), result);
		break;
	case 10:
		send_user(me, "%c%c%c", 0x92, 1, 0);
		send_user(me, "%c%c%c", 0x92, 1, 1);
		break;
	case 20:
		result = sprintf("%s：\n    Vui lòng chọn số lượng thẻ điểm bạn muốn mua.：\n", who->get_name());
		result += ESC "50 Kim\nconsign list 50\n";
		result += ESC "100 Kim\nconsign list 100\n";
		result += ESC "200 Kim\nconsign list 200\n";
		result += ESC"Rời khỏi.";
		send_user(me, "%c%c%w%s", ':', 3, who->get_char_picid(), result);
		break;

	case 111:
		//who->get_pay_money_buy_item(0);
		break;
	}
}

