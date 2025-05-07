#include <item.h>
#include <ansi.h>
#include <equip.h>

inherit ITEM;
inherit COMBINED;

int confirm_sell_item() { return 1; }
int get_item_color() {return 2 ;}
int is_specal_move() { return 1; }

int get_item_value() { return 150; }
int get_item_value_2() {return 150;}

void create()
{
        set_name("Hồn Huyễn Thú");
        set_picid_1(12343);
        set_picid_2(12343);
        set_value(500);
		set_amount(1);
}

string get_desc() 
{
	return "Ẩn chứa sức mạnh thần bí\nNghe nói nếu thu thập đủ số lượng Hồn Huyễn Thú có thể luyện thành trứng Huyễn Thú.";
}

int move_item(object me, object item, object equip)
{
	return __FILE__->move_item_callout(me, item, equip, 1 );
}

int move_item2(object me, object item, object equip)
{
	return __FILE__->move_item_callout(me, item, equip, 2 );
}

int move_item_callout(object me, object item, object equip, int type)
{
	string result, forge;
	object item2;
	int i, p, level, rate, hole_number;

	if (!equip->is_superpet()) {
		return 0;
	}

	if (equip->get("itemLife") >= 100) {
		return 0;
	}

	item->add_amount(-1);

	if (equip->get("itemLife") + 5 >= 100) {
		equip->set("itemLife", 100);

		notify("Thọ mệnh đạt tối đa");
	}
	else {
		equip->add("itemLife", 5);
		notify("Thọ mệnh tăng thêm 5 điểm");
	}

	send_user(me, "%c%d%c", 0x31, getoid(equip), 0);

	return 1;
}