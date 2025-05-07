
#include <ansi.h>
#include <equip.h>
#include <level.h>
#include <item.h>

inherit NECK;
int is_suit() { return 1; }
int get_equip_serial() { return 1; }
int get_family() { return 2; }
int get_item_color() { return 5; }
string get_suit_name() { return "Huyết Long TS"; }
void create()
{
	set_name(HIR"Huyết Long - Sơn Hạng Liên");
	set_picid_1(8658);
	set_picid_2(8658);

	set_level(105);
	set_value(15000);
	set_max_lasting(16099);
	set("ap+", 100);
//	set("dp+", 125);
	set("cp+", 30);
	set("pp+", 120);
	set("sp+", 0);
	set("hp+", 200);
	set("mp+", 0);
	set_item_color(5);
	set_bind(4);
	set_hide(0);
	setup();
}

string get_desc()
{
	return "Huyết Long - Sơn Hạng Liên";
}

string get_suit_desc()
{
	return "Trang bị Huyết Long";
}

