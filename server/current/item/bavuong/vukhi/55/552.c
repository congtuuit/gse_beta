
#include <equip.h>
#include <ansi.h>

#define EQUIP_ATTR "sys/item/itemAttribute"

inherit WEAPON;

// 函数：适用门派
int get_family() { return 2; }

//int is_thanbinh() { return 1; }
//int is_thanbinh3() { return 1; }
//// 函数：构造处理
//
int tu_chat() { return RAT_THAP; }
//int equip_code() { return 7001; }
int isBaVuong() { return 1; }

void create()
{
	set_name("Bá Vương - Đao");
	set_picid_1(6811);
	set_picid_2(6811);

	set_level(55);
	set_bind(6);
	set_value(20000);
	set_max_lasting(36099);
	set("ap+", 310);
	set("hp+", 50);
	set("!%+", 100);
	set_item_color(4);
	setup();

	set_weapon_type(BLADE);
}

int get_weapon_level() { return 5; }

string get_desc()
{
	return "Trang bị \"Đao Pháp\"" + sprintf("\nTư chất: %s", EQUIP_ATTR->get_tuchat_desc(tu_chat()));
}
string get_tail_desc()
{
	return "";
}
