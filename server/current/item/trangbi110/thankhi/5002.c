
#include <equip.h>
#include <ansi.h>

inherit WEAPON;

int get_family() { return 3; }
int is_thanbinh() { return 1; }
int is_thanbinh4() { return 1; }
int is_thanbinh_thien() { return 1; }

void create()
{
	set_name("Thiên - Phương Thiên Họa Kích");
	set_picid_1(6894);
	set_picid_2(6894);

	set_level(100);
	set_bind(6);
	set_value(20000);
	set_max_lasting(36099);
	set("ap+", 620);
	set("hp+", 200);
	set("!%+", 300);
	set("?%+", 200);
	set_item_color(10);
	setup();

	set_weapon_type(SPEAR);
}

int get_weapon_level() { return 14; }

string get_desc()
{
	return "Trang bị \"Thương Pháp\"";
}

string get_tail_desc()
{
	return "[Đặc tính]Mỗi lần tấn công có 15% xác suất giảm 320 Phòng Thủ của mục tiêu.\n"
		"Đồng thời có tỷ lệ nhất định thi triển Thần Thương\n"
		" khiến tấn công làm mục tiêu choáng trong 3 giây.";
}