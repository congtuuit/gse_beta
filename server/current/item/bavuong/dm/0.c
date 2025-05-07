#include <ansi.h>
#include <equip.h>
#include <level.h>
#include <item.h>

inherit HEAD;
int is_suit() { return 1; }
int get_equip_serial() { return 1; }
int get_family() { return 4; }
int get_item_color() { return 5; }
string get_suit_name() { return "Huyết Long ĐM"; }
void create()
{
	set_name(HIR"Huyết Long - Môn Đầu Cân");
	set_picid_1(8714);
	set_picid_2(8714);

	set_level(105);
	set_value(15000);
	set_max_lasting(16099);
	set("ap+", 0);
	set("dp+", 118);
	set("cp+", 0);
	set("pp+", 123);
	set("sp+", 95);
	//set("hp+", 173);
	set("mp+", 0);
	set_item_color(5);
	set_bind(4);
	set_hide(0);
	setup();
}

string get_desc()
{
	return "Huyết Long - Môn Đầu Cân";
}

string get_suit_desc()
{
	return "Trang bị Huyết Long";
}

