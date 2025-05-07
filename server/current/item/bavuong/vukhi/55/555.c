
#include <equip.h>
#include <ansi.h>
#define EQUIP_ATTR "sys/item/itemAttribute"

inherit WEAPON;

int get_family() { return 3; }

int get_pic_id() { return 6851; }

int tu_chat() { return RAT_THAP; }
int isBaVuong() { return 1; }

void create()
{
	set_name("Bá Vương - Côn");
	set_picid_1(get_pic_id());
	set_picid_2(get_pic_id());

	set_level(55);
	set_bind(6);
	set_value(20000);
	set_max_lasting(36099);
	set("ap+", 340);
	set("hp+", 100);
	set("double", 200);
	set_item_color(4);
	setup();

	set_weapon_type(STICK);
}

int get_weapon_level() { return 5; }

string get_desc()
{
	return "Trang bị \"Bổng Pháp\"" + sprintf("\nTư chất: %s", EQUIP_ATTR->get_tuchat_desc(tu_chat()));
}
string get_tail_desc()
{
	return "";
}