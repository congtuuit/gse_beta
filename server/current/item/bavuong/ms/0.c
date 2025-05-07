
#include <ansi.h>
#include <equip.h>
#include <level.h>
#include <item.h>

inherit HEAD;
int is_suit() { return 1; }
int get_equip_serial() { return 1; }
int get_family() { return 5; }
int get_item_color() { return 5; }
string get_suit_name() { return "Huyết Long MS"; }
void create()
{
	set_name(HIR"Huyết Long - Sơn Bì Mão");
	set_picid_1(6500);
	set_picid_2(6500);

	set_level(105);
	set_value(15000);
	set_max_lasting(16099);
	set("dp+", 188);
	set("cp+", 0);
	set("pp+", 253);
	set("sp+", 0);
	set("hp+", 195);
	set("mp+", 252);
	set_item_color(5);
	set_bind(4);
	set_hide(0);
	setup();
}

string get_desc()
{
	return "Huyết Long - Sơn Bì Mão";
}

string get_suit_desc()
{
	return "Trang bị Huyết Long";
}

