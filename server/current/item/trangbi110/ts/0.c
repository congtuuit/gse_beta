
#include <ansi.h>
#include <equip.h>
#include <level.h>
#include <item.h>

inherit HEAD;
int is_suit() { return 1; }
int get_equip_serial() { return 1; }
int get_family() { return 2; }
int get_item_color() { return 5; }
string get_suit_name() { return "Huyết Long TS"; }
void create()
{
	set_name(HIR"Huyết Long - Sơn Đầu Khôi");
	set_picid_1(6658);
	set_picid_2(6658);

	set_level(105);
	set_value(15000);
	set_max_lasting(16099);
	set("ap+", 0);
	set("dp+", 247);
	set("cp+", 0);
	set("pp+", 198);
	set("sp+", 0);
	set("hp+", 105);
	set("mp+", 100);
	set_item_color(5);
	set_bind(4);
	set_hide(0);
	setup();
}

string get_desc()
{
	return "Huyết Long - Sơn Đầu Khôi";
}

string get_suit_desc()
{
	return "Trang bị Huyết Long";
}

