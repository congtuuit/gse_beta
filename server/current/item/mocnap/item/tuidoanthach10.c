#include <ansi.h>
#include <equip.h>
#include <effect.h>
inherit ITEM;
inherit USABLE;

int get_item_color() { return 2; }
int get_item_value() { return 3000; }
int get_item_value_2() { return 3000; }

void create()
{
	set_name("Túi Đoạn Thạch (11)");
	set_picid_1(7107);
	set_picid_2(7107);
	set_value(1000);
}

string get_desc(object me)
{
	return "[Có thể sử dụng] Sau khi sử dụng nhận ngẫu nhiên 11 viên đoạn thạch Sơ - Trung - Cao\n";
}

int get_use_effect(object me)
{
	return __FILE__->get_use_effect_callout(me, this_object());
}

int get_use_effect_callout(object who, object gift)
{
	int gender, family, type, i, k, l, m, index;
	object item, item1, item2, item3;
	string cTmp, cFile, cFile1, cFile2, cFile3, p;

	if (USER_INVENTORY_D->count_empty_carry(who) < 11)
	{
		send_user(who, "%c%s", '!', "Hành trang của bạn không đủ 11 chỗ");
		return 0;
	}
	
	/*if (USER_INVENTORY_D->can_carry(who, obj) < 1)
	{
		send_user(who, "%c%s", '!', "Hành trang của bạn không đủ 11 chỗ");
		return 0;
	}*/

	gift->remove_from_user();
	destruct(gift);

	for (i = 0; i < 11; i++) {
		item2 = new(sprintf("item/sell/%d032", 0 + random(3)));
		l = item2->move(who, -1);
		item2->add_to_user(l);
	}

	/*item3 = new("/item/mocnap/item/1032");
	m = item3->move(who, -1);
	item3->add_to_user(m);

	item1 = new("/item/mocnap/item/2032");
	k = item1->move(who, -1);
	item1->add_to_user(k);*/

	log_file("tui_doan_thach.txt", sprintf("%s : %s (%d) %s sử dụng Túi Đoạn Thạch (11)\n", short_time(time()), who->get_name(), who->get_number(), who->get_id()));
	return 0;
}