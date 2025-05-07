
#include <equip.h>
#include <ansi.h>

inherit WEAPON;

int get_family() { return 3; }
int is_thanbinh() { return 1; }
int is_thanbinh4() { return 1; }
int is_thanbinh_dia() { return 1; }

void create()
{
	set_name("Địa - Thanh Long Kích");
	set_picid_1(6892);
	set_picid_2(6892);

	set_level(100);
	set_bind(6);
	set_value(20000);
	set_max_lasting(36099);
	set("ap+", 520);
	set("hp+", 120);
	set("!%+", 300);
	set("?%+", 200);
	set_item_color(10);
	setup();

	set_weapon_type(SPEAR);
}

int get_weapon_level() { return 12; }

string get_desc()
{
	return "Trang bị \"Thương Pháp\"";
}
