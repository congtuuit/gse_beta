
#include <equip.h>
#include <ansi.h>

inherit WEAPON;
#define EQUIP_ATTR "sys/item/itemAttribute"

int get_family() { return 4; }
int is_thanbinh() { return 1; }
int is_thanbinh2() { return 1; }

int tu_chat() { return RAT_THAP; }
int equip_code() { return 7001; }

string get_next_equip() {
	return sprintf("/item/trangbi110/thankhi/%d", equip_code());
}

void create()
{
	set_name(HIR"Độc Long Tiễn");
	set_picid_1(7810);//7811
	set_picid_2(7810);//7811

	set_level(100);
	set_bind(1);
	set_value(20000);
	set_max_lasting(36099);
	set("ap+", 450);
	set("hp+", 100);
	set("!%+", 300);
	set("double", 200);
	set_item_color(5);	//紫色

	set_hide(0);
	setup();

	//set_weapon_color(ORANGE);
	set_weapon_type(THROWING);
}

//int get_weapon_level() { return 100; }
int get_weapon_level() { return 10; }

string get_desc()
{
	return "Trang bị \"Ám Khí\"" + sprintf("\nTư chất: %s", EQUIP_ATTR->get_tuchat_desc(tu_chat()));
}

string get_tail_desc()
{
	return "[Đặc tính]Khi tấn công có thể làm mục tiêu trúng 300 sát thương Độc Tố trong 20 giây.\n"
		"Đồng thời có tỷ lệ nhất định thi triển Ma Khí khiến đòn tấn công\n"
		//"làm mù loà 6 giây hoặc làm phá vỡ 100 phòng thủ của mục tiêu.";
		"tăng thêm 2.5% sát thương bạo kích hoặc phá vỡ 100 phòng thủ của mục tiêu.";
}