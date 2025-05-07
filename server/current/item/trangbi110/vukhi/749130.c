
#include <equip.h>
#include <ansi.h>

#define EQUIP_ATTR "sys/item/itemAttribute"

inherit WEAPON;

int get_family() { return 3; }
int is_thanbinh() { return 1; }
int is_thanbinh4() { return 1; }

int tu_chat() { return RAT_THAP; }
int equip_code() { return 7001; }

string get_next_equip() {
	return sprintf("/item/trangbi110/thankhi/%d", equip_code());
}

void create()
{
	set_name(HIR"Tà Long Kích");
	//set_picid_1(6890);
	set_picid_1(6893);
	set_picid_2(6893);

	set_level(100);
	set_bind(1);
	set_value(20000);
	set_max_lasting(36099);
	set("ap+", 470);
	set("hp+", 100);
	set("!%+", 300);
	set("?%+", 200);
	set_item_color(5);
	setup();

	set_weapon_color(0x4a49);
	set_weapon_type(SPEAR);
}

int get_weapon_level() { return 100; }

string get_desc()
{
	return "Trang bị \"Thương Pháp\"" + sprintf("\nTư chất: %s", EQUIP_ATTR->get_tuchat_desc(tu_chat()));
}

string get_tail_desc()
{
	return "[Đặc tính]Mỗi lần tấn công có 15% xác suất giảm 320 Phòng Thủ của mục tiêu.\n"
		"Đồng thời có tỷ lệ nhất định thi triển Thần Thương\n"
		" khiến tấn công làm mục tiêu choáng trong 3 giây.";
}