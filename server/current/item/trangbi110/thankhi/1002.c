
#include <equip.h>
#include <ansi.h>

inherit WEAPON;

int get_family() { return 1; }
int is_thanbinh() { return 1; }
int is_thanbinh1() { return 1; }
int is_thanbinh_thien() { return 1; }

void create()
{
	set_name("Thiên - Trụ Thiên Quyền");
	set_picid_1(6834);
	set_picid_2(6834);

	set_level(100);
	set_bind(6);
	set_value(20000);
	set_max_lasting(36099);
	set("ap+", 630);
	set("hp+", 200);
	set("double", 200);
	set("!%+", 300);
	set_item_color(10);

	setup();

	set_weapon_type(UNARMED);
}

int get_weapon_level() { return 0; }

string get_desc()
{
	return "Trang bị \"Quyền Pháp\"";
}

string get_tail_desc()
{
	return "[Đặc tính]Khi bị tấn công có xác xuất 10% tạo ra Linh giáp hộ thể.\n"
		"Đồng thời có tỷ lệ nhất định thi triển Cuồng Tâm khiến tấn công\n"
		"làm choáng 3 giây hoặc làm phá vỡ 300 phòng thủ của mục tiêu.";
}