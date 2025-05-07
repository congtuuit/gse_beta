#include <npc.h>
#include <item.h>
#include <ansi.h>
#include <task.h>
#include <music.h>
#include <equip.h>
inherit OFFICER;

// 函数：获取人物造型
int get_char_picid() { return 7909; }
int is_seller() { return 1; }
int is_self_look() { return 1; }
void do_welcome(string arg);
void do_accept(string arg);
void create()
{
	set_name("Thiếu Nhi");
	set_2("talk", ([
		"welcome":(: do_welcome:),
	]));
	setup();

}

void do_welcome(string arg)
{
	__FILE__->do_welcome2(this_object(), arg);
}
void do_welcome2(object npc, string arg)
{
	int flag, p, gender, rate, point, thieunhi_item, k, j;
	object player = this_player(), item, item1, item2;
	string* nTmp, cFile;
	flag = to_int(arg);
	switch (flag)
	{
	case 1:
		send_user(player, "%c%c%w%s", ':', 3, npc->get_char_picid(), npc->get_name() + ":\n" + "Điểm tích lũy của bạn là: "HIR"" + player->get_save_2("thieunhi.point") + "\n"
			ESC "Thoát ra\nCLOSE\n");
		break;
	case 2:
		point = player->get_save_2("thieunhi.point");
		rate = random(100);

		if (USER_INVENTORY_D->get_free_count(player) < 4)
		{
			notify("Hành trang không đủ 4 chỗ trống");
			return;
		}

		if (point > 9) {
			thieunhi_item = player->get_save_2("thieunhi.item");

			if (point >= 100) {

				item = new("item/test/tuilinhthachngaunhien/tuilinhthach3");
				item->set_no_give(1);
				item->set_amount(1);
				p = item->move2(player, -1);
				item->add_to_user(p);
				if (item) CHAT_D->sys_channel(0, "Bằng hữu " + player->get_name() + " đổi kẹo đường hồ lô Quốc Tế Thiếu Nhi đã may mắn nhận được " + item->get_name() + ", xin chúc mừng!");

				item1 = new("item/sell/2032");
				item1->set_no_give(1);
				k = item1->move2(player, -1);
				item1->add_to_user(k);
				if (item1) CHAT_D->sys_channel(0, "Bằng hữu " + player->get_name() + " đổi kẹo đường hồ lô Quốc Tế Thiếu Nhi đã may mắn nhận được " + item1->get_name() + ", xin chúc mừng!");

				item2 = new("item/sell/0034");
				item2->set_no_give(1);
				item2->set_amount(1);
				j = item2->move2(player, -1);
				item2->add_to_user(j);
				if (item2) CHAT_D->sys_channel(0, "Bằng hữu " + player->get_name() + " đổi kẹo đường hồ lô Quốc Tế Thiếu Nhi đã may mắn nhận được " + item2->get_name() + ", xin chúc mừng!");


				player->add_save_2("thieunhi.point", -100);
			}
			else if (point >= 50) {

				item = new("item/test/tuilinhthachngaunhien/tuilinhthach2");
				item->set_amount(1);
				item->set_no_give(1);
				p = item->move2(player, -1);
				item->add_to_user(p);
				if (item) CHAT_D->sys_channel(0, "Bằng hữu " + player->get_name() + " đổi kẹo đường hồ lô Quốc Tế Thiếu Nhi đã may mắn nhận được " + item->get_name() + ", xin chúc mừng!");

				item1 = new("item/sell/1032");
				item1->set_no_give(1);
				k = item1->move2(player, -1);
				item1->add_to_user(k);
				if (item1) CHAT_D->sys_channel(0, "Bằng hữu " + player->get_name() + " đổi kẹo đường hồ lô Quốc Tế Thiếu Nhi đã may mắn nhận được " + item1->get_name() + ", xin chúc mừng!");

				item2 = new("item/sell/0034");
				item2->set_no_give(1);
				item2->set_amount(1);
				j = item2->move2(player, -1);
				item2->add_to_user(j);
				if (item2) CHAT_D->sys_channel(0, "Bằng hữu " + player->get_name() + " đổi kẹo đường hồ lô Quốc Tế Thiếu Nhi đã may mắn nhận được " + item2->get_name() + ", xin chúc mừng!");

				player->add_save_2("thieunhi.point", -50);
			}
			else if (point >= 30) {

				item = new("item/test/tuilinhthachngaunhien/tuilinhthach1");
				item->set_amount(1);
				item->set_no_give(1);
				p = item->move2(player, -1);
				item->add_to_user(p);
				if (item) CHAT_D->sys_channel(0, "Bằng hữu " + player->get_name() + " đổi kẹo đường hồ lô Quốc Tế Thiếu Nhi đã may mắn nhận được " + item->get_name() + ", xin chúc mừng!");


				item1 = new("item/sell/0032");
				item1->set_no_give(1);
				k = item1->move2(player, -1);
				item1->add_to_user(k);
				if (item1) CHAT_D->sys_channel(0, "Bằng hữu " + player->get_name() + " đổi kẹo đường hồ lô Quốc Tế Thiếu Nhi đã may mắn nhận được " + item1->get_name() + ", xin chúc mừng!");

				player->add_save_2("thieunhi.point", -30);
			}
			else if (point >= 10) {
				//
				item = new("item/test2/block/TuiPhapBao");
				item->set_amount(2);
				item->set_no_give(1);
				p = item->move2(player, -1);
				item->add_to_user(p);
				if (item) CHAT_D->sys_channel(0, "Bằng hữu " + player->get_name() + " đổi kẹo đường hồ lô Quốc Tế Thiếu Nhi đã may mắn nhận được " + item->get_name() + ", xin chúc mừng!");


				item1 = new("item/test2/block/TuiQuaVoSong");
				item->set_amount(2);
				item1->set_no_give(1);
				k = item1->move2(player, -1);
				item1->add_to_user(k);
				if (item1) CHAT_D->sys_channel(0, "Bằng hữu " + player->get_name() + " đổi kẹo đường hồ lô Quốc Tế Thiếu Nhi đã may mắn nhận được " + item1->get_name() + ", xin chúc mừng!");


				//item2 = new("item/test2/block/AXPBlock");
				item2 = new("item/sell/0032");
				item2->set_amount(1);
				item2->set_no_give(1);
				j = item2->move2(player, -1);
				item2->add_to_user(j);

				if (item2) CHAT_D->sys_channel(0, "Bằng hữu " + player->get_name() + " đổi kẹo đường hồ lô Quốc Tế Thiếu Nhi đã may mắn nhận được " + item2->get_name() + ", xin chúc mừng!");

				player->add_save_2("thieunhi.point", -10);
			}
		}
		else {

			send_user(player, "%c%c%w%s", ':', 3, npc->get_char_picid(), npc->get_name() + ":\nBạn chưa tích lũy đủ điểm!\n"
				ESC "Thoát ra\nCLOSE\n");
			return;
		}

		break;

	case 3:

		if (TASK_LEGEND_D->check_task_item_amount(player, "Kẹo Đường Hồ Lô") < 5)
		{
			notify("Không đủ Kẹo");
			return;
		}
		if (USER_INVENTORY_D->get_free_count(player) < 4)
		{
			notify("Hành trang không đủ 4 chỗ trống");
			return;
		}

		TASK_LEGEND_D->check_task_item1(player, "Kẹo Đường Hồ Lô", 5);

		rate = random100();

		if (rate < 15) {
			item = new("item/test2/block/TuiPhapBao");
			item->set_no_give(1);
			p = item->move2(player, -1);
			item->add_to_user(p);
			notify("Bạn nhận được Túi pháp bảo.");
		}
		else if (rate < 30) {
			item = new("item/test2/block/TuiQuaVoSong");
			item->set_no_give(1);
			p = item->move2(player, -1);
			item->add_to_user(p);
			notify("Bạn nhận được Túi Quà Vô Song.");
		}
		else if (rate < 45) {
			item = new("item/test2/block/TuiPhapBao");
			item->set_no_give(1);
			p = item->move2(player, -1);
			item->add_to_user(p);
			notify("Bạn nhận được Túi pháp bảo.");

			//item = new("item/test2/block/AXPBlock");
			//item->set_no_give(1);
			//p = item->move2(player, -1);
			//item->add_to_user(p);
			//notify("Bạn nhận được Ân Xá Phù.");
		}
		// else if (rate < 60) {
		// 	item = new("/item/common/dacuonghoa");
		// 	item->set_no_give(1);
		// 	p = item->move2(player, -1);
		// 	item->add_to_user(p);
		// 	notify("Bạn nhận được Đá cường hóa");
		// }
		else if (rate < 75) {
			item = new("item/test2/TheGiamGia");
			item->set_no_give(1);
			p = item->move2(player, -1);
			item->add_to_user(p);
			notify("Bạn nhận được Thẻ Giảm Giá.");
		}
		else if (rate < 85) {
			item = new("item/sell/0032");
			item->set_no_give(1);
			p = item->move2(player, -1);
			item->add_to_user(p);
			notify("Bạn nhận được Bảo đề phù.");
		}
		else {
			player->add_exp(player->get_level()* 2000 + random(5000));
			notify("Bạn nhận được Kinh nghiệm.");
		}


		if (player->get_save_2("thieunhi.point") < 1) {
			player->set_save_2("thieunhi.point", 1);

		}
		else {
			player->add_save_2("thieunhi.point", 1);
		}

		send_user(player, "%c%c%w%s", ':', 3, npc->get_char_picid(), npc->get_name() + ":\nNghe nói Kẹo Hồ Lô rất ngon...!!\n"
			ESC "Thoát ra\nCLOSE\n");
		break;
	}
}
void do_look(object player)
{
	object npc = this_object();

	send_user(player, "%c%c%w%s", ':', 3, npc->get_char_picid(), sprintf("%s :\n" + "Ngươi có mang cho ta kẹo không?\n Hình như ngươi tích lũy được: "HIR"" + player->get_save_2("thieunhi.point") + ""NOR" điểm rồi!!!\n"
		ESC "Đổi điểm tích lũy lấy quà tặng\ntalk %x# welcome.2\n"
		//ESC "Kiểm tra điểm tích lũy \ntalk %x# welcome.1\n"
		ESC HIC "Quốc Tế Thiếu Nhi \ntalk %x# welcome.3\n"
		ESC "Rời khỏi\nCLOSE\n", npc->get_name(), getoid(npc), getoid(npc), getoid(npc)));
}
