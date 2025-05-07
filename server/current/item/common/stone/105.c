#include <item.h>
#include <ansi.h>
#include <equip.h>

inherit ITEM;
inherit "/inh/item/diamond";

int get_code() { return 105; }
int get_level() { return 1; }


string get_type() {
	return "stoneHP+";
}

int get_point() { return HOLE_D->get_value_by_code(get_code()); }

int confirm_sell_item() { return 1; }
int get_item_color() { return 4; }
int get_item_type() { return ITEM_TYPE_DIAMOND_HOLE; }
string get_diamond_type() { return "hole"; }
int is_specal_move() { return 1; }

void create()
{
	set_name(sprintf("%s", HOLE_D->get_stone_name_by_code(get_code())));
	set_real_name("Hole");
	set_picid_1(12094);
	set_picid_2(12094);
	set_save_2("mecung.point", 300);

	set_value(500);
	set_level(1);
}

string get_desc()
{
	return sprintf("Viên ngọc mang sức mạnh thần bí, có thể sử dụng để tăng sức mạnh cho trang bị\n"
		PPM"Thuộc tính %s: +%d", HOLE_D->get_stone_type_by_type(get_type()), HOLE_D->get_value_by_code(get_code()));
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
	int i, p, level, rate, pos, hole_number;
	string cmd = "";

	if (equip->is_equip() == 0 && equip->get_real_name() != "Hole")  return 0;

	if (equip->is_equip())
	{
		i = equip->get_equip_type();
		if (i != WEAPON_TYPE && i != ARMOR_TYPE && i != HEAD_TYPE && i != BOOTS_TYPE && i != WAIST_TYPE && i != NECK_TYPE)
			return 0;
	}

	if (!HOLE_D->valid_stone(get_code(), equip)) {
		return 0;
	}

	if (type == 1)
	{
		/*
		pos = 0,1,2;
		*/

		hole_number = ITEM_EQUIP_D->get_hole_amount(equip);

		if (hole_number < 1) {
			return 0;
		}

		for (i = 0; i < hole_number; i++) {
			cmd += sprintf(ESC"Khảm vào ô số %d\nmixhole %x# %x# %d\n", i + 1, getoid(equip), getoid(item), i);
		}

		send_user(me, "%c%c%s", ':', 3, sprintf("    Chọn vị trí khảm?\n%s"ESC"Rời khỏi\nCLOSE\n", cmd));
	}

	return 1;
}
