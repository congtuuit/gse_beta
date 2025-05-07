
#include <equip.h>
#include <ansi.h>

inherit WEAPON;

int get_family() { return 1; }
int is_thanbinh() { return 1; }
int is_thanbinh1() { return 1; }
int is_thanbinh_dia() { return 1; }

void create()
{
	set_name("Địa - Trụ Thiên Quyền");
	set_picid_1(6833);
	set_picid_2(6833);

	set_level(100);
	set_bind(6);
	set_value(20000);
	set_max_lasting(36099);
	set("ap+", 530);
	set("hp+", 120);
	set("double", 200);
	set("!%+", 300);
	set_item_color(10);
	setup();

	set_weapon_type(UNARMED);
}

int get_weapon_level() { return 0; }

string get_desc()
{
	return "Trang bị \"Quyền Pháp\"";
}
