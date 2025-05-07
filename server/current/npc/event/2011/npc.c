#include <npc.h>
#include <ansi.h>
#include <public.h>

inherit OFFICER;

int get_char_picid() { return 8200; }
void do_welcome(string arg);
int is_seller() { return 1; }
int is_self_look() { return 1; }

int is_exist(object player, string itemName);
void remove_item(object player, string itemName, int amount);
void move_item_to_user(object who, int amount_s, string name);

void create()
{
    set_name("Sứ giả sự kiện");
    set_real_name("Lão Phu Tử");
    set_2("talk", ([
        "welcome":(: do_welcome:),
    ]));

    setup();
}

void do_welcome(string arg)
{
	__FILE__->do_welcome2(this_object(), arg);
}

void do_look(object who)
{
	object me = this_object();
	string result;

	result = sprintf(me->get_name() + ": Nhanh tay thu thập các vật phẩm sự kiện để đổi thưởng\nQuy tắc:\nChữ 'Tôn' - 'Trọng': Nhận được từ mỗi 10 lượt nhiệm vụ sư môn.\nChữ 'Sư': Nhận được từ mỗi 10 lượt nhiệm vụ Sư Gia. Hoặc có thể mua tại Bảo Khố.\nChữ 'Đạo': Vật phẩm rơi từ quái bạn tiêu diệt xuất hiện tại các bản đồ\n**Hoạt động BOSS phản đồ diễn ra từ 8h-22h cũng có các phần thưởng.\n\n");
	result += sprintf(ESC HIC"Nhận phần thưởng Tôn - Trọng - Đạo.\ntalk %x# welcome.1\n", getoid(me));
	result += sprintf(ESC HIY"Nhận phần thưởng Tôn Sư Trọng Đạo.\ntalk %x# welcome.2\n", getoid(me));
	result += sprintf(ESC "Quay lại sau.");
	send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), result);
}

void do_welcome2(object me, string arg)
{
	int i, flag, size, x, y, z, p, tid, map_grade, iTime, member;
	string result, file_item, ton = "Tôn", su = "Sư", trong = "Trọng", dao = "Đạo";
	object who = this_player();
	who->set_time("time", 0);
	flag = to_int(arg);

	switch (flag)
	{
	case 1:
		if (is_exist(who, ton) < 1|| is_exist(who, trong) < 1|| is_exist(who, dao) < 1) {
			result = sprintf(me->get_name() + ": Vật phẩm không đủ, hãy thu thập đủ rồi hãy quay lại đây nhé.\n");
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), result);
		}
		else {
			file_item = "item/event/2011/qua1";
			remove_item(who,ton,1);
			remove_item(who,trong,1);
			remove_item(who,dao,1);
			move_item_to_user(who, 1, file_item);
		}
		
		break;
	case 2:

		if (is_exist(who, ton) < 2 || is_exist(who, trong) < 2 || is_exist(who, dao) < 3|| is_exist(who, su) < 2) {
			result = sprintf(me->get_name() + ": Vật phẩm không đủ, cần ít nhất 3 vật phẩm mỗi loại. Hãy thu thập đủ rồi hãy quay lại đây nhé.\n");
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), result);
		}
		else {
			file_item = "item/event/2011/qua2";

			remove_item(who, ton, 2);
			remove_item(who, trong, 2);
			remove_item(who, dao, 3);
			remove_item(who, su, 2);
			move_item_to_user(who, 1, file_item);
		}

		break;
	}

}


void move_item_to_user(object who, int amount_s, string name)
{
	int p, total, amount;
	object item;
	string name_s;

	item = new(name);

	if (item)
	{
		name_s = item->get_name();
		if (item->get_max_combined() > 1)
		{
			total = amount_s;
			amount = USER_INVENTORY_D->carry_combined_item(who, item, total);
			if (amount > 0 && item->set_amount(amount))
			{
				if (p = item->move(who, -1))
				{
					item->add_to_user(p);
				}
			}
			else
			{
				item->add_amount(-total);
			}
		}
		else
		{
			if (p = item->move(who, -1))
			{
				item->add_to_user(p);
			}
		}

		USER_D->user_channel("Chúc mừng "HIY + who->get_name() + NOR" nhận được " + item->get_name() + ".\n");
	}
}

int is_exist(object player, string itemName) {
	int amount;
	amount = TASK_LEGEND_D->check_task_item_amount(player, itemName);

	if (amount > 1) {
		return amount;
	}
	else {
		return 0;
	}
}

void remove_item(object player, string itemName, int amount) {
	TASK_LEGEND_D->check_task_item1(player, itemName, amount);
}