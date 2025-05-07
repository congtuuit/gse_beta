
#include <equip.h>
#include <ansi.h>

inherit WEAPON;

int get_family() { return 4; }
int is_thanbinh() { return 1; }
int is_thanbinh2() { return 1; }
int is_thanbinh_thien() { return 1; }

void create()
{
	set_name("Thiên - Câu Tiễn");
	set_picid_1(7812);
	set_picid_2(7812);

	set_level(100);
	set_bind(6);
	set_value(20000);
	set_max_lasting(36099);
	set("ap+", 600);
	set("hp+", 200);
	set("!%+", 300);
	set("double", 200);
	set_item_color(10);

	setup();
	set_weapon_type(THROWING);
}

int get_weapon_level() { return 12; }

string get_desc()
{
	return "Trang bị \"Ám Khí\"";
}

string get_tail_desc()
{
	return "[Đặc tính] Khi tấn công có thể làm mục tiêu trúng 300 sát thương Độc Tố trong 20 giây.\n"
		"Đồng thời có tỷ lệ nhất định thi triển Ma Khí khiến đòn tấn công\n"
		//"làm mù loà 6 giây hoặc làm phá vỡ 100 phòng thủ của mục tiêu.";
		"tăng thêm 2.5% sát thương bạo kích hoặc phá vỡ 100 phòng thủ của mục tiêu.";
}