
#include <equip.h>
#include <ansi.h>
#include <level.h>

#define EQUIP_ATTR "sys/item/itemAttribute"

inherit WEAPON;

int get_family() { return 9; }
int is_thanbinh() { return 1; }
int is_thanbinh6() { return 1; }

int tu_chat() { return RAT_THAP; }
int equip_code() { return 7001; }

string get_next_equip() {
	return sprintf("/item/trangbi110/thankhi/%d", equip_code());
}

void create()
{
	set_name(HIR"Thủy Long Kiếm");
	//set_picid_1(6868);
	set_picid_1(7618);
	set_picid_2(6868);

	set_level(100);
	set_bind(1);
	set_value(20000);
	set_max_lasting(36099);
	set("cp+", 500);
	set("hp+", 100);
	set("double", 400);
	set("?%+", 200);
	set_item_color(5);
	set_hide(0);

	setup();

	set_weapon_color(0x4a49);
	set_weapon_type(SWORD);
}

int get_weapon_level() { return LEVEL_08; }

string get_desc()
{
	return "Trang bị \"Kiếm Pháp\"" + sprintf("\nTư chất: %s", EQUIP_ATTR->get_tuchat_desc(tu_chat()));
}

string get_tail_desc()
{
	return "[Đặc tính]Tăng sát thương pháp thuật 200-300 hoặc tăng hiệu quả trị liệu y thuật.\n"
		"Đồng thời có tỷ lệ nhất định thi triển Ma Kiếm\n"
		"khiến tấn công làm mục tiêu bị choáng trong 2 giây.";
}