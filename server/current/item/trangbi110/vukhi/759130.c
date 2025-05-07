
#include <equip.h>
#include <ansi.h>
#define EQUIP_ATTR "sys/item/itemAttribute"

inherit WEAPON;

int get_family() { return 3; }
int is_thanbinh() { return 1; }
int is_thanbinh5() { return 1; }

int get_pic_id() { return 6851; }

int tu_chat() { return RAT_THAP; }
int equip_code() { return 7001; }

string get_next_equip() {
	return sprintf("/item/trangbi110/thankhi/%d", equip_code());
}

void create()
{
	set_name(HIR"Hoả Long Côn");
	set_picid_1(get_pic_id());
	set_picid_2(get_pic_id());

	set_level(100);
	set_bind(1);
	set_value(20000);
	set_max_lasting(36099);
	set("ap+", 465);
	set("hp+", 100);
	set("double", 200);
	set("?%+", 200);
	set_item_color(5);
	setup();

	set_weapon_color(0x4a49);
	set_weapon_type(STICK);
}

int get_weapon_level() { return 11; }

string get_desc()
{
	return "Trang bị \"Bổng Pháp\"" + sprintf("\nTư chất: %s", EQUIP_ATTR->get_tuchat_desc(tu_chat()));
}

string get_tail_desc()
{
	return "[Đặc tính]Mỗi lần tấn công có 20% xác suất gây Choáng trong 3 giây.\n"
		"Đồng thời có tỷ lệ nhất định thi triển Hoả Long khiến tấn công\n"
		"làm phá vỡ 300 phòng thủ của mục tiêu trong 30 giây.";
}