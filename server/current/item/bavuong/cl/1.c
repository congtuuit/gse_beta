#include <ansi.h>
#include <equip.h>
#include <level.h>
#include <item.h>

inherit ARMOR;
int is_suit() { return 1; }
int get_equip_serial() { return 1; }
int get_family() { return 6; }
int get_item_color() { return 5; }
string get_suit_name() { return "Huyết Long CL"; }
void create()
{
	set_name(HIR"Huyết Long - Luân Vũ Y");
	set_picid_1(6125);
	set_picid_2(6125);

	set_level(105);
	set_value(15000);
	set_max_lasting(16099);
	set("ap+", 0);
	set("dp+", 246);
	set("cp+", 0);
	set("pp+", 375);
	set("sp+", 0);
	set("hp+", 205);
	set("mp+", 293);
	set_item_color(5);
	set_bind(4);
	set_hide(0);
	setup();
}

string get_desc()
{
	return "Huyết Long - Luân Vũ Y";
}

string get_suit_desc()
{
	return "Trang bị Huyết Long";
}

