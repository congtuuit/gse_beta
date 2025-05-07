
#include <equip.h>
#include <ansi.h>

inherit WEAPON;

int get_family() { return 3; }
int is_thanbinh() { return 1; }
int is_thanbinh5() { return 1; }
int is_thanbinh_dia() { return 1; }

int get_pic_id() { return 6852; }

void create()
{
	set_name("Địa - Hoả Vân Côn");
	set_picid_1(get_pic_id());
	set_picid_2(get_pic_id());

	set_level(100);
	set_bind(6);
	set_value(20000);
	set_max_lasting(36099);
	set("ap+", 515);
	set("hp+", 120);
	set("double", 200);
	set("?%+", 200);
	set_item_color(10);
	setup();
	set_weapon_type(STICK);
}

int get_weapon_level() { return 12; }

string get_desc()
{
	return "Trang bị \"Bổng Pháp\"";
}
