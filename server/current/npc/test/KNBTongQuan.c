
// 自动生成：/make/npc/make0002
#include <ansi.h>
#include <equip.h>
#include <item.h>
#include <effect.h>
#include <city.h>
#include <public.h>
#include <task.h>
#include <npc.h>

#define DATA_KNB "data/KnbDatabase.dat"
#define DATA_GIFT "data/GiftDatabase.dat"
#define DATA_CARD_GIFT "data/CardGiftDatabase.dat"
#define LUCKYDRAW_GIFT "data/LuckyDrawGiftDatabase.dat"

#define YUANBAO "sys/sys/test_db"

inherit OFFICER;

// 函数：小贩识别
int get_char_picid() { return 5302; }
//int get_char_picid() { return 5502; }

void do_welcome(string arg);

// 函数：构造处理
void create()
{
	set_name(HIR"Kim Bảo Tổng Quản");
	set_real_name(HIY"Chiến Quốc KNB");
	set_2("talk", ([
		"welcome":(: do_welcome:),
	]));

	setup();
}

void do_look(object who)
{
	int id = getoid(this_object());
	send_user(who, "%c%c%w%s", ':', 3, get_char_picid(), sprintf(" %s :\n Ta là người quản lý Kim Bảo, ngươi cần gì ở ta?\n"
		//ESC HIY"Tôi muốn nhận Kim Bảo\ntalk %x# welcome.1\n"
		//ESC HIC"Nhập Gift Code nhận quà\ntalk %x# welcome.2\n"
		ESC HIC"Ta muốn nhận quà tích lũy (mốc nạp)\ntalk %x# welcome.3\n"
		ESC HIC"Nâng cấp Thiên Ma Chi Dực\ntalk %x# welcome.4\n"
		ESC HIY"Ta muốn chuyển Kim Nguyên Bảo qua người chơi khác\ntalk %x# welcome.5\n"
		//ESC "Nhận thưởng từ Vòng Quay\ntalk %x# welcome.6\n"
		ESC"Rời khỏi", get_name(), id, id, id, id,id, id));
}

void do_welcome(string arg)
{
	object me = this_object();
	__FILE__->do_welcome2(me, arg);
}
void do_welcome2(object me, string arg)
{
	int flag, id, gender, userId, intAmount = 0, intUser, checked, p;
	int i, size;
	object who, item;
	string* line, strAmount = "0", content = "", * data, user="0";
	string item_name;
	string result;
	int item_number;

	who = this_player();
	id = getoid(me);
	flag = to_int(arg);
	who->set_time("talk", 0);
	userId = who->get_number();

	switch (flag)
	{
		case 1:
			return;
			line = explode(read_file(DATA_KNB), "\n");
			for (i = 0, size = sizeof(line); i < size; i++)
			{
				data = explode(line[i], " ");

				if (userId == to_int(data[0])) {
					strAmount = data[1];
					user = data[0];
					continue;
				}

				content += line[i] + "\n";
			}

			if (user == "0") {
				send_user(who, "%c%c%w%s", ':', 3, get_char_picid(), sprintf(" %s :\n Ngươi không có trong danh sách chuyển đổi KNB, vui lòng quay lại sau nhé!\n"
				ESC"Thoát", get_name()));

				return ;
			}

			//intUser = to_int(user);

			if (!(who = find_any_char(user)))
			{
				notify("Không tìm thấy người này");
				return;
			}

			intAmount = to_int(strAmount);

			if (intAmount > 0)
			{
				YUANBAO->add_yuanbao(who, (intAmount * 10));
				notify("Bạn đã nhận được "+ HIR "%d "+ HIY"Kim Nguyên Bảo", intAmount);
				tell_user(who, sprintf(HIY"Bạn đã nhận được %d Kim Nguyên Bảo", intAmount));
			}

			rm(DATA_KNB);
			write_file(DATA_KNB, content);

			send_user(who, "%c%c%w%s", ':', 3, get_char_picid(), sprintf(" %s :\n Ta đã đưa %d KNB cho ngươi rồi nhé!\n"
			ESC"Thoát", get_name(), intAmount));
			
			break;

		case 2:
			send_user(who, "%c%c%d%s", '?', 16, 15, "Nhập mã code để nhận thưởng：\n" ESC"nhanthuongts @ %s " + who->get_number() + "\n");
			break;
		case 3:

			if (USER_INVENTORY_D->get_free_count(who) < 2)
			{
				notify("Hành trang không đủ 2 chỗ trống");
				return 0;
			}

			line = explode(read_file(DATA_CARD_GIFT), "\n");
			for (i = 0, size = sizeof(line); i < size; i++)
			{
				data = explode(line[i], " ");

				if (userId == to_int(data[0]) && checked != 1) {
					checked = 1;
					strAmount = data[1];
					user = data[0];
					continue;
				}

				content += line[i] + "\n";
			}

			if (user == "0") {
				send_user(who, "%c%c%w%s", ':', 3, get_char_picid(), sprintf(" %s :\n Bạn chưa có phần thưởng nào để nhận, vui lòng quay lại sau nhé!\n"
					ESC"Thoát", get_name()));

				return;
			}

			//intUser = to_int(user);

			if (!(who = find_any_char(user)))
			{
				notify("Không tìm thấy người này");
				return;
			}

			//giao item
			if (strAmount == "0") {
				notify("Vật phẩm này không tồn tại");
				return;
			}

			item = new(strAmount);
			p = item->move(who, -1);
			item->add_to_user(p);

			rm(DATA_CARD_GIFT);
			write_file(DATA_CARD_GIFT, content);

			send_user(who, "%c%c%w%s", ':', 3, get_char_picid(), sprintf(" %s :\n Chúc mừng bạn đã nhận được %s!\n"
				ESC"Thoát", get_name(), item->get_name()));
			break;

		case 4:
			if (USER_INVENTORY_D->get_free_count(who) < 2)
			{
				notify("Hành trang không đủ 2 chỗ trống");
				return 0;
			}

			item_name = "Thiên Ma Chi Dực";
			item_number = TASK_LEGEND_D->check_task_item_amount(who, item_name);

			if (item_number < 3) {
				notify("Bạn không đủ 3 Thiên Ma Chi Dực");
				return 0;
			}

			TASK_LEGEND_D->check_task_item1(who, item_name, 3);

			item = new ("/item/ppvacanh/canhtrangden/canhtrangden_1");
			i = item->move(who, -1);
			item->add_to_user(i);

			result = HIY + sprintf("Chúc mừng %s ( %d ) đã nhận được "HIR"%s.", who->get_name(), who->get_number(), item->get_name());
			CHAT_D->sys_channel(0, result);
			send_user(who, "%c%s", ';', "Chúc mừng bạn đã nhận được "HIY"" + item->get_name());

			log_file("gm/gm3.dat", sprintf(" %s %s ( %d ) nhận được item Thien Ma + 1 %d ( %d %d )\n", short_time(), who->get_id(), who->get_number(), get_z(who), get_x(who), get_y(who)));


			break;
		case 5:
			send_user(who, "%c%c%d%s", '?', 16, 7, "Bạn muốn chuyển Kim Bảo    cho số ID nào? Xin hãy nhập vào : \n" ESC "chuyenknb - %s\n");
			break;

		case 6:
			return;
			if (USER_INVENTORY_D->get_free_count(who) < 2)
			{
				notify("Hành trang không đủ 2 chỗ trống");
				return 0;
			}

			line = explode(read_file(LUCKYDRAW_GIFT), "\n");
			for (i = 0, size = sizeof(line); i < size; i++)
			{
				data = explode(line[i], " ");

				if (userId == to_int(data[0]) && checked != 1) {
					checked = 1;
					strAmount = data[1];
					user = data[0];
					continue;
				}

				content += line[i] + "\n";
			}

			if (user == "0") {
				send_user(who, "%c%c%w%s", ':', 3, get_char_picid(), sprintf(" %s :\n Bạn chưa có phần thưởng nào để nhận, vui lòng quay lại sau nhé!\n"
					ESC"Thoát", get_name()));

				return;
			}

			if (!(who = find_any_char(user)))
			{
				notify("Không tìm thấy người này");
				return;
			}

			if (strAmount == "0") {
				notify("Vật phẩm này không tồn tại");
				return;
			}

			item = new(strAmount);
			p = item->move(who, -1);
			item->add_to_user(p);

			rm(LUCKYDRAW_GIFT);
			write_file(LUCKYDRAW_GIFT, content);

			send_user(who, "%c%c%w%s", ':', 3, get_char_picid(), sprintf(" %s :\n Chúc mừng bạn đã nhận được %s!\n"
				ESC"Thoát", get_name(), item->get_name()));
			break;

	}
}