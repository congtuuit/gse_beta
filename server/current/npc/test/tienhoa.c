#include <item.h>
#include <npc.h>
#include <cmd.h>
#include <task.h>
#include <ansi.h>
#include <effect.h>
#include <music.h>

#include <time.h>
#include <city.h>
#include <public.h>
#include <equip.h>
#include <time.h>
inherit OFFICER;

int get_char_picid() { return 6010; }
int is_seller() { return 1; }
int is_self_look() { return 1; }
void do_welcome(string arg);
void do_accept(string arg);
void create()
{
	set_name("Tiên Hoa");
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
	int flag, p, gender, rate, point, thieunhi_item, k, j, amount;
	object player = this_player(), item, item1, item2;
	string* nTmp, cFile;
	int iTime;
	mixed* mixTime;
	iTime = time();
	mixTime = localtime(iTime);

	flag = to_int(arg);
	npc->to_front_eachother(player);

	switch (flag)
	{
	case 1:

		
		if ((mixTime[TIME_MON] + 1) > 8 || ((mixTime[TIME_MON] + 1) == 8 && mixTime[TIME_MDAY] > 30)) {
			send_user(player, "%c%c%w%s", ':', 3, npc->get_char_picid(), sprintf("%s :\n" + "Sự kiện đã kết thúc.\n"
				ESC "Rời khỏi\nCLOSE\n", npc->get_name(), getoid(npc)));
			return;
		}

		if (
			TASK_LEGEND_D->check_task_item_amount(player, "Dã Cúc") < 5 ||
			TASK_LEGEND_D->check_task_item_amount(player, "Cây mẫu đơn") < 5 ||
			TASK_LEGEND_D->check_task_item_amount(player, "Hoa Kèn") < 5 ||
			TASK_LEGEND_D->check_task_item_amount(player, "Cây lan") < 5
			)
		{
			notify("Vật phẩm không đủ");
			return;
		}

		if (USER_INVENTORY_D->get_free_count(player) < 1)
		{
			notify("Hành trang không đủ 1 chỗ trống");
			return;
		}

		item = new ("/item/test2/tuihoa");
		if (item) {

			if (USER_INVENTORY_D->can_carry(player, item) < 1)
			{
				notify("Hành trang không đủ 1 chỗ trống");
				destruct(item);
				return;
			}

			if (item->get_max_combined() > 1)
			{
				amount = USER_INVENTORY_D->carry_combined_item(player, item, 1);
				if (amount > 0 && item->set_amount(amount))
				{
					if (p = item->move(player, -1))
					{
						item->add_to_user(p);
					}
				}
				else    item->add_amount(-1);
			}
			else
			{
				if (p = item->move(player, -1))
				{
					item->add_to_user(p);
				}
			}


			TASK_LEGEND_D->check_task_item1(player, "Dã Cúc", 5);
			TASK_LEGEND_D->check_task_item1(player, "Cây mẫu đơn", 5);
			TASK_LEGEND_D->check_task_item1(player, "Hoa Kèn", 5);
			TASK_LEGEND_D->check_task_item1(player, "Cây lan", 5);

			send_user(player, "%c%c%w%s", ':', 3, npc->get_char_picid(), npc->get_name() + ":\nChúc ngươi may mắn...!!\n"
				ESC "Thoát ra\nCLOSE\n");
		}
		
		break;

	case 2:

		if ((mixTime[TIME_MON] + 1) > 8 || ((mixTime[TIME_MON] + 1) == 8 && mixTime[TIME_MDAY] > 30)) {
			send_user(player, "%c%c%w%s", ':', 3, npc->get_char_picid(), sprintf("%s :\n" + "Sự kiện đã kết thúc.\n"
				ESC "Rời khỏi\nCLOSE\n", npc->get_name(), getoid(npc)));
			return;
		}

		if (
			TASK_LEGEND_D->check_task_item_amount(player, "Dã Cúc") < 5 ||
			TASK_LEGEND_D->check_task_item_amount(player, "Cây mẫu đơn") < 5 ||
			TASK_LEGEND_D->check_task_item_amount(player, "Hoa Kèn") < 5 ||
			TASK_LEGEND_D->check_task_item_amount(player, "Cây lan") < 5 ||
			TASK_LEGEND_D->check_task_item_amount(player, "Giấy Gói Hoa") < 1
			)
		{
			notify("Vật phẩm không đủ");
			return;
		}

		if (USER_INVENTORY_D->get_free_count(player) < 1)
		{
			notify("Hành trang không đủ 1 chỗ trống");
			return;
		}

		item = new ("/item/test2/tuihoa2");
		if (item) {

			if (USER_INVENTORY_D->can_carry(player, item) < 1)
			{
				notify("Hành trang không đủ 1 chỗ trống");
				destruct(item);
				return;
			}

			if (item->get_max_combined() > 1)
			{
				amount = USER_INVENTORY_D->carry_combined_item(player, item, 1);
				if (amount > 0 && item->set_amount(amount))
				{
					if (p = item->move(player, -1))
					{
						item->add_to_user(p);
					}
				}
				else    item->add_amount(-1);
			}
			else
			{
				if (p = item->move(player, -1))
				{
					item->add_to_user(p);
				}
			}

			TASK_LEGEND_D->check_task_item1(player, "Dã Cúc", 5);
			TASK_LEGEND_D->check_task_item1(player, "Cây mẫu đơn", 5);
			TASK_LEGEND_D->check_task_item1(player, "Hoa Kèn", 5);
			TASK_LEGEND_D->check_task_item1(player, "Cây lan", 5);
			TASK_LEGEND_D->check_task_item1(player, "Giấy Gói Hoa", 1);

			send_user(player, "%c%c%w%s", ':', 3, npc->get_char_picid(), npc->get_name() + ":\nNhanh tay thu thập hoa và về đổi thưởng nha...!!\n"
				ESC "Thoát ra\nCLOSE\n");
		}
		
		break;
	}
}
void do_look(object player)
{
	object npc = this_object();

	send_user(player, "%c%c%w%s", ':', 3, npc->get_char_picid(), sprintf("%s :\n" + "Sự kiện diễn ra từ "+ HIR"7/8 đến 23h59 30/8 "+NOR". Nhanh tay thu thập hoa và về đổi thưởng nha!!!\n"
		ESC HIC "Đổi túi hoa (Sơ) \ntalk %x# welcome.1\n"
		ESC HIY "Đổi túi hoa (Cao) \ntalk %x# welcome.2\n"
		ESC "Rời khỏi\nCLOSE\n", npc->get_name(), getoid(npc), getoid(npc), getoid(npc)));
}
