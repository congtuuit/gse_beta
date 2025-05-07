#include <ansi.h>
#include <equip.h>
#include <level.h>
#include <item.h>

inherit NECK;
int is_suit() { return 1; }
int get_equip_serial() { return 1; }
int get_family() { return 7; }
int get_item_color() { return 5; }
string get_suit_name() { return "Huyết Long VMC"; }
void create()
{
	set_name(HIR"Huyết Long - Cốc Hạng Liên");
	set_picid_1(8663);
	set_picid_2(8663);

	set_level(105);
	set_value(15000);
	set_max_lasting(16099);
	set("ap+", 0);
	set("dp+", 125);
	set("cp+", 250);
	set("pp+", 225);
	set("sp+", 0);
	set("hp+", 257);
	set("mp+", 275);
	set_item_color(5);
	set_bind(4);
	set_hide(0);
	setup();
}

string get_desc()
{
	return "Huyết Long - Cốc Hạng Liên";
}

string get_suit_desc()
{
	return "Trang bị Huyết Long";
}

