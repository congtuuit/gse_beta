
#include <equip.h>
#include <ansi.h>

inherit WEAPON;

int get_family() { return 4; }
int is_thanbinh() { return 1; }
int is_thanbinh2() { return 1; }
int is_thanbinh_dia() { return 1; }

void create()
{
	set_name("Địa - Câu Tiễn");
	set_picid_1(7811);
	set_picid_2(7811);

	set_level(100);
	set_bind(6);
	set_value(20000);
	set_max_lasting(36099);
	set("ap+", 500);
	set("hp+", 120);
	set("!%+", 300);
	set("double", 200);
	set_item_color(10);

	setup();

	set_weapon_type(THROWING);
}

int get_weapon_level() { return 11; }

string get_desc()
{
	return "Trang bị \"Ám Khí\"";
}
