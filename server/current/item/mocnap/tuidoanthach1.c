#include <ansi.h>
#include <equip.h>
#include <effect.h>
inherit ITEM;
inherit USABLE;

int get_item_color() { return 2; }
int get_item_value() { return 100; }
int get_item_value_2() { return 100; }

void create()
{
	set_name("Túi Qùa Đoạn Thạch 1");
	set_picid_1(4980);
	set_picid_2(4981);
	set_value(1000);
	set_save_2("cqtq.score", 15);

}

string get_desc(object me)
{
	return "[Có thể sử dụng] Nhận được x1 Sơ Cấp Đoạn Thạch, 1x Trung Cấp Đoạn Thạch, 1x Cao Cấp Đoạn Thạch.\n";
}

int get_use_effect(object me)
{
	return __FILE__->get_use_effect_callout(me, this_object());
}

int get_use_effect_callout(object who, object gift)
{
	int gender, family, type, i, k, l, m;
	object item, item1, item2, item3;
	string cTmp, cFile, cFile1, cFile2, cFile3, p;

	if (USER_INVENTORY_D->get_free_count(who) < 3)
	{
		notify("Hành trang không đủ 3 chỗ trống");
		return 0;
	}

	if (sizeof_inventory(who, 3, MAX_CARRY) >= MAX_CARRY)
	{
		send_user(who, "%c%s", '!', "Hành trang của bạn không đủ 3 chỗ");
		return 0;
	}

	if (USER_INVENTORY_D->count_empty_carry(who) < 3)
	{
		send_user(who, "%c%s", '!', "Hành trang của bạn không đủ 3 chỗ");
		return 0;
	}

	gift->remove_from_user();
	destruct(gift);

	item2 = new("/item/mocnap/item/0032");
	l = item2->move(who, -1);
	item2->add_to_user(l);

	item3 = new("/item/mocnap/item/1032");
	m = item3->move(who, -1);
	item3->add_to_user(m);

	item1 = new("/item/mocnap/item/2032");
	k = item1->move(who, -1);
	item1->add_to_user(k);

	log_file("sdmocnap.txt", sprintf("%s : %s (%d) %s sử dụng Tui doan thach 1\n", short_time(time()), who->get_name(), who->get_number(), who->get_id()));
	return 0;
}