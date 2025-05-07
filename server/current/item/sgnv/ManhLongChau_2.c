#include <ansi.h>
#include <item.h>
#include <public.h>
#include <task.h>

inherit ITEM;
inherit USABLE;

int get_item_value() { return 15; }
int get_item_value_2() { return 15; }
int get_item_color() { return 2; }

void create()
{
	set_name("Mảnh Ghép Long Châu (2)");
	set_picid_1(12021);
	set_picid_2(12021);
	set_value(300);
	set_save_2("diemnhiemvu.score", 300);
	set_no_sell(1);
	set_no_give(1);
}

string get_desc()
{
	return "[Có thể sử dụng] Vật phẩm quý hiếm, có thể tích lũy đổi Long Châu.\n(Nhấp chuột phải để sử dụng)";
}

int is_usable() { return 1; }

int get_use_effect(object me)
{
	return __FILE__->get_use_effect_callout(me, this_object());
}

int get_use_effect_callout(object me, object gift)
{
	int isExistItem, p;
	object item;

	isExistItem = TASK_LEGEND_D->check_task_item_amount(me, "Mảnh Ghép Long Châu (1)");

	if (!isExistItem) {
		notify("Bạn không đủ mảnh ghép");
		return 0;
	}

	if (USER_INVENTORY_D->get_free_count(me) < 2)
	{
		notify("Hành trang không đủ 2 chỗ trống");
		return 0;
	}

	item = new ("item/00/0001");
	if (USER_INVENTORY_D->can_carry(me, item) < 1)
	{
		notify("Hành trang không đủ 1 chỗ trống");
		return 0;
	}

	if (item && p = item->move(me, -1))
	{
		item->add_to_user(p);
		TASK_LEGEND_D->check_task_item1(me, "Mảnh Ghép Long Châu (1)", 1);
		send_user(me, "%c%s", ';', "Bạn nhận được "HIY + item->get_name());
		CHAT_D->sys_channel(0, sprintf(HIR "%s"HIY" thu thập đủ mảnh ghép và hợp thành nhận được "HIR"%s", me->get_name(), item->get_name()));
		log_file("longchau.txt", sprintf("%s %s (%d) hợp thành %s\n", short_time(), me->get_name(), me->get_number(), item->get_name()));
	}

	return 1;
}

