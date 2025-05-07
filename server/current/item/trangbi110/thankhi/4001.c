
#include <equip.h>
#include <ansi.h>
#include <level.h>

inherit WEAPON;

int get_family() { return 9; }
int is_thanbinh() { return 1; }
int is_thanbinh6() { return 1; }
int is_thanbinh_dia() { return 1; }


void create()
{
	set_name("Địa - Can Tương Kiếm");
	set_picid_1(6870);
	set_picid_2(6870);

	set_level(100);
	set_bind(6);
	set_value(20000);
	set_max_lasting(36099);
	set("cp+", 550);
	set("hp+", 120);
	set("double", 400);
	set("?%+", 200);
	set_item_color(10);
	setup();

	set_weapon_type(SWORD);
}

int get_weapon_level() { return LEVEL_08; }

string get_desc()
{
	return "Trang bị \"Kiếm Pháp\"";
}
