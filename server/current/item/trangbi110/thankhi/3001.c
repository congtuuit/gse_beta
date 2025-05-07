
#include <equip.h>
#include <ansi.h>

inherit WEAPON;

int get_family() { return 2; }
int is_thanbinh() { return 1; }
int is_thanbinh3() { return 1; }
int is_thanbinh_dia() { return 1; }

void create()
{
	set_name("Địa - La Sát");
	set_picid_1(6811);
	set_picid_2(6811);

	set_level(100);
	set_bind(6);
	set_value(20000);
	set_max_lasting(36099);
	set("ap+", 500);
	set("hp+", 120);
	set("!%+", 300);
	set("?%+", 200);
	set_item_color(10);
	setup();
	
	set_weapon_type(BLADE);
}

int get_weapon_level() { return 100; }

string get_desc()
{
	return "Trang bị \"Đao Pháp\"";
}
