#include <item.h>
#include <ansi.h>
#include <equip.h>

inherit ITEM;
inherit "/inh/item/diamond";

int is_diamond_2() { return 1; }

int confirm_sell_item() { return 1; }

int get_item_color() { return 3; }

string get_diamond_type() { return "forge"; }

string get_forge_index() { return "7"; }

int is_specal_move() { return 1; }

string item_str_name() {
	return "Vé Cường Hóa 7 Sao";
}

int level_type() {
	return 7;
}

void create()
{
	set_name(item_str_name());
	set_real_name("Đoạn Thạch");
	set_picid_1(3811);
	set_picid_2(3811);
	set_unit("块");
	set_value(500);
	set_level(1);
}

string get_desc()
{
	return sprintf("Có thể giúp trang bị đạt %d cấp cường hóa, tăng cường thuộc tính của trang bị.", level_type());
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
	int i, p, level, rate;
	if (equip->is_equip() == 0 && equip->get_real_name() != "Đoạn Thạch")  return 0;
	if (equip->is_equip())
	{
		i = equip->get_equip_type();
		if (i != WEAPON_TYPE && i != ARMOR_TYPE && i != HEAD_TYPE && i != BOOTS_TYPE && i != WAIST_TYPE && i != NECK_TYPE)
			return 0;
	}

	if (equip->get_real_name() == "Đoạn Thạch")
	{
		return 0;
	}

	forge = equip->get("forge");
	if (forge == 0) level = 0;
	else level = strlen(forge);

	if (level >= item->level_type()) {
		notify("Trang bị này có cấp độ cường hóa cao rồi.");
		return 1;
	}

	
	if (type == 1)
	{
		result = sprintf("Bạn muốn sử dụng vé cường hóa %d sao cho %s không?\n"
			ESC "Chấp nhận\ncuonghoa %x# %d\n"
			ESC "Hủy bỏ", item->level_type(),
			equip->get_name(), getoid(equip), item->level_type());
		send_user(me, "%c%c%w%s", ':', 3, 0, result);
		return 1;
	}
	return 1;
}