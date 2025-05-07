
#include <equip.h>
#include <ansi.h>

#define EQUIP_ATTR "sys/item/itemAttribute"

inherit WEAPON;

// 函数：适用门派
int get_family() { return 2; }
int is_thanbinh() { return 1; }
int is_thanbinh3() { return 1; }
// 函数：构造处理

int tu_chat() { return RAT_THAP; }
int equip_code() { return 7001; }

string get_next_equip() {
	return sprintf("/item/trangbi110/thankhi/%d", equip_code());
}

void create()
{
	set_name(HIR"Cuồng Long Đao");
	//set_picid_1(6811);
	set_picid_1(6811);
	set_picid_2(6811);

	set_level(100);
	set_bind(0);
	set_value(20000);
	set_max_lasting(36099);
	set("ap+", 450);
	set("hp+", 100);
	set("!%+", 300);
	set("?%+", 200);
	set_item_color(5);
	setup();

	set_weapon_color(0x4a49);
	set_weapon_type(BLADE);
}

int get_weapon_level() { return 11; }

string get_desc()
{
	return "Trang bị \"Đao Pháp\"" + sprintf("\nTư chất: %s", EQUIP_ATTR->get_tuchat_desc(tu_chat()));
}

string get_tail_desc()
{
	return "[Đặc tính]Mỗi lần tấn công có 30% xác suất tăng thêm 600 sát thương.\n"
		"Đồng thời có tỷ lệ nhất định thi triển Thiên Địa Càn Khôn\n"
		"khiến tấn công làm phá vỡ 500 phòng thủ của mục tiêu.";
}