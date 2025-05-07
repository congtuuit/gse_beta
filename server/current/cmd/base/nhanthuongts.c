#include <ansi.h>
#include <equip.h>
#include <item.h>
#include <effect.h>
#include <city.h>
#include <public.h>
#include <task.h>
#include <npc.h>

inherit ITEM;
inherit USABLE;

#define DATA_GIFT "data/GiftDatabase.dat"
#define YUANBAO "sys/sys/test_db"

// 函数：命令处理
int main(object me, string arg)
{
    object item;
    string* weapon, file;
    string cmd1, cmd2, cmd3, cmd4;
    int family, z, x, y, p, i, size;
	string* line, strAmount = "0", content = "", * data, user = "0";
    string nameRootObject, giftCode, path, amount, currentUser;
    string nameOfItem, result="";

	object who;

    int getOK = 0;
    int intAmount;

    if (sscanf(arg, "@ %s %s", giftCode, currentUser) == 2)
    {
		if (!(who = find_any_char(currentUser)))
		{
			notify("Không tìm thấy người này");
			return 1;
		}

		/*if (giftCode == "CQFREE") {

			if (me->get_save_2("ThuongTest") > 0) {
				send_user(me, "%c%c%w%s", ':', 3, 5302, sprintf(" %s :\n Ta nhớ không nhầm là ngươi đã nhận quà rồi!!\n"
					ESC"Thoát", "Chiến quốc tổng quản"));
				return;
			}

			item = new("/item/tuiquatanthu/giftOpenServer");
			if (item) {
				p = item->move2(me, -1);
				item->add_to_user(p);
			}

			send_user(me, "%c%c%w%s", ':', 3, 5302, sprintf(" %s :\n Ta đã trao phần thưởng cho ngươi rồi nhé!!\n"
				ESC"Thoát", "Chiến quốc tổng quản"));

			send_user(me, "%c%s", ';', sprintf("Bạn nhận được "HIR"%s", item->get_name()));
			me->set_save_2("ThuongTest", 1);

			return 1;
		}*/

		if (!file_exist(DATA_GIFT)) {
			ghi_file(DATA_GIFT, sprintf(""));
		}
		line = explode(read_file(DATA_GIFT), "\n");
		for (i = 0, size = sizeof(line); i < size; i++)
		{
			data = explode(line[i], " ");

			if (giftCode == data[0]) {
				path = data[1];
				getOK = 1;
				continue;
			}

			content += line[i] + "\n";
		}

		if (getOK == 0) {
			send_user(me, "%c%c%w%s", ':', 3, 6008, sprintf(" %s :\n Mã Code sai hoặc không tồn tại, vui lòng quay lại sau nhé!\n"
				ESC"Thoát", "Thần Tiên Gia Gia"));

			return;
		}

		item = new(sprintf("%s", path));

		if (item) {
			p = item->move2(me, -1);
			item->add_to_user(p);
		}

		rm(DATA_GIFT);
		write_file(DATA_GIFT, content);

		send_user(me, "%c%c%w%s", ':', 3, 6008, sprintf(" %s :\n Ta đã trao phần thưởng cho ngươi rồi nhé!!\n"
			ESC"Thoát", "Thần Tiên Gia Gia"));

		send_user(me, "%c%s", ';', sprintf("Bạn nhận được "HIR"%s", item->get_name()));
		//me->set_save_2("ThuongTest", 1);

		log_file("gm/GiftCode.dat", sprintf(" %s %s ( %d ) nhận %s\n", short_time(), who->get_id(), who->get_number(), item->get_name()));

        return 1;
    }
}