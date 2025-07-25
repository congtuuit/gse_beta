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
	set_name("Túi Qùa Donate 4");
	set_picid_1(4980);
	set_picid_2(4981);
	set_value(1000);
}

string get_desc(object me)
{
	return "[Có thể sử dụng] Phần quà nhận được từ mốc Donate.\n Sau khi sử dụng nhận được "HIY"x1 Cánh Thiên Ma";
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

	if (USER_INVENTORY_D->count_empty_carry(who) < 1)
	{
		send_user(who, "%c%s", '!', "Hành trang của bạn không đủ 1 chỗ");
		return 0;
	}

	gift->remove_from_user();
	destruct(gift);

	item = new("/item/ppvacanh/canhtrangden/canhtrangden");
	k = item->move(who, -1);
	item->add_to_user(k);

	log_file("sdmocnap.txt", sprintf("%s : %s (%d) %s sử dụng Tui diem 24000\n", short_time(time()), who->get_name(), who->get_number(), who->get_id()));
	return 0;
}