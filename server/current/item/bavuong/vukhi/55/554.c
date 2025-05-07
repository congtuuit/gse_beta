
#include <equip.h>
#include <ansi.h>

inherit WEAPON;
#define EQUIP_ATTR "sys/item/itemAttribute"

int get_family() { return 4; }

//int is_thanbinh() { return 1; }
//int is_thanbinh2() { return 1; }

int tu_chat() { return RAT_THAP; }
int isBaVuong() { return 1; }

void create()
{
	set_name("Bá Vương - Tiễn");
	set_picid_1(7810);//7811
	set_picid_2(7810);//7811

	set_level(55);
	set_bind(6);
	set_value(20000);
	set_max_lasting(36099);

	set("ap+", 250);
	set("!%+", 300);
	set_poison(3000);
	//set("@%", 100);
	set("double", 200);
	set_item_color(4);


	set_hide(0);
	setup();

	set_weapon_type(THROWING);
}

//int get_weapon_level() { return 100; }
int get_weapon_level() { return 5; }

string get_desc()
{
	return "Trang bị \"Ám Khí\"" + sprintf("\nTư chất: %s", EQUIP_ATTR->get_tuchat_desc(tu_chat()));
}

string get_tail_desc()
{
	return "";
}