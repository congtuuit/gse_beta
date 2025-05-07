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
	set_name("Túi Qùa Donate 6");
	set_picid_1(4980);
	set_picid_2(4981);
	set_value(1000);
}

string get_desc(object me)
{
	return "[Có thể sử dụng] Phần quà nhận được từ mốc Donate.\n Sau khi sử dụng sẽ nhận được Mảnh Ghép Long Châu (2)\n Túi Ngọc 1-5 \n Túi Đoạn Thạch 11";
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

	if (USER_INVENTORY_D->count_empty_carry(who) < 3)
	{
		send_user(who, "%c%s", '!', "Hành trang của bạn không đủ 3 chỗ");
		return 0;
	}

	gift->remove_from_user();
	destruct(gift);

	item2 = new("/item/mocnap/item/ManhLongChau_2");
	l = item2->move(who, -1);
	item2->add_to_user(l);

	item3 = new("/item/mocnap/item/1_5");
	m = item3->move(who, -1);
	item3->add_to_user(m);

	item = new("/item/mocnap/item/tuidoanthach10");
	k = item->move(who, -1);
	item->add_to_user(k);

	log_file("sdmocnap.txt", sprintf("%s : %s (%d) %s sử dụng Tui diem 48000\n", short_time(time()), who->get_name(), who->get_number(), who->get_id()));
	return 0;
}