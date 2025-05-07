#include <ansi.h>
#include <equip.h>
#include <level.h>
#include <item.h>

inherit NECK;
int is_suit() { return 1; }
int get_equip_serial() { return 1; }
int get_family() { return 6; }
int get_item_color() { return 5; }
string get_suit_name() { return "Huyết Long CL"; }
void create()
{
	set_name(HIR"Huyết Long - Luân Hạng Liên");
	set_picid_1(8614);
	set_picid_2(8614);

	set_level(105);
	set_value(15000);
	set_max_lasting(16099);
	//set("ap+", 295);
	set("dp+", 125);
	set("cp+", 250);
	set("pp+", 274);
	set("sp+", 0);
	set("hp+", 212);
	set("mp+", 210);
	set_item_color(5);
	set_bind(4);
	set_hide(0);
	setup();
}

string get_desc()
{
	return "Huyết Long - Luân Hạng Liên";
}

string get_suit_desc()
{
	return "Trang bị Huyết Long";
}

