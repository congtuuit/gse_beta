
#include <equip.h>
#include <ansi.h>

#define EQUIP_ATTR "sys/item/itemAttribute"

inherit WEAPON;

int get_family() { return 1; }
int is_thanbinh() { return 1; }
int is_thanbinh1() { return 1; }

int tu_chat() { return RAT_THAP; }
int equip_code() { return 7001; }

string get_next_equip() {
	return sprintf("/item/trangbi110/thankhi/%d", equip_code());
}

void create()
{
	set_name(HIR"Trụ Thiên Quyền Thủ");
	set_picid_1(6827);
	set_picid_2(6827);

	set_level(100);
	set_bind(1);
	set_value(20000);
	set_max_lasting(36099);
	set("ap+", 480);
	set("hp+", 100);
	set("double", 200);
	set("!%+", 300);
	set_item_color(5);
	setup();

	set_weapon_color(0x4a49);
	set_weapon_type(UNARMED);
}

int get_weapon_level() { return 0; }

string get_desc()
{
	return "Trang bị \"Quyền Pháp\"" + sprintf("\nTư chất: %s", EQUIP_ATTR->get_tuchat_desc(tu_chat()));
}

string get_tail_desc()
{
	return "[Đặc tính]Khi bị tấn công có xác xuất 10% tạo ra Linh giáp hộ thể.\n"
		"Đồng thời có tỷ lệ nhất định thi triển Cuồng Tâm khiến tấn công\n"
		"làm choáng 3 giây hoặc làm phá vỡ 300 phòng thủ của mục tiêu.";
}