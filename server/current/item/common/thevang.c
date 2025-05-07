#include <item.h>
#include <ansi.h>
#include <equip.h>

inherit ITEM;
inherit "/inh/item/diamond";
#define EQUIP "sys/item/equip"


int get_level() { return 1; };
int get_max_hole() { return 3; }
int confirm_sell_item() { return 1; }
int get_item_color() { return 1; }
int is_add_hole() { return 1; }
int is_specal_move() { return 1; }


void create()
{
	set_name("Bột Hoàng Kim");
	set_picid_1(6825);
	set_picid_2(6825);
	set_unit("块");
	set_value(500);
	set_level(1);
}

string get_desc()
{
	return "Có thể dùng để biến trang bị thành hoàng kim";
}

int move_item(object me, object item, object equip)
{
	return __FILE__->move_item_callout(me, item, equip, 1);
}

int move_item2(object me, object item, object equip)
{
	return __FILE__->move_item_callout(me, item, equip, 2);
}

int move_item_callout(object me, object item, object equip, int type)
{
	string result, forge;
	object item2;
	int i, p, level, rate, hole_number;

	if (equip->is_equip())
	{
		i = equip->get_equip_type();
		if (i != WEAPON_TYPE && i != ARMOR_TYPE && i != HEAD_TYPE && i != BOOTS_TYPE && i != WAIST_TYPE && i != NECK_TYPE) {
			return 0;
		}
	}

	if (type == 1)
	{
		equip->set_item_color(2);
		send_user(me, "%c%d%c", 0x31, getoid(equip), 0);
		tell_user(me, ECHO"Bạn đã biến %s thành hoàng kim。", equip->get_name());

		item->remove_from_user();
		destruct(item);
	}

	return 1;
}