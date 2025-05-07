
#include <equip.h>
#include <ansi.h>
#include <level.h>

inherit WEAPON;

int get_family() { return 9; }
int is_thanbinh() { return 1; }
int is_thanbinh6() { return 1; }
int is_thanbinh_thien() { return 1; }


void create()
{
	set_name("Thiên - Can Tương Kiếm");
	set_picid_1(6873);
	set_picid_2(6873);

	set_level(100);
	set_bind(6);
	set_value(20000);
	set_max_lasting(36099);
	set("cp+", 650);
	set("hp+", 200);
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

string get_tail_desc()
{
	return "[Đặc tính]Tăng sát thương pháp thuật 200-300 hoặc tăng hiệu quả trị liệu y thuật.\n"
		"Đồng thời có tỷ lệ nhất định thi triển Ma Kiếm\n"
		"khiến tấn công làm mục tiêu bị choáng trong 2 giây.";
}