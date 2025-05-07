#include <effect.h>
#include <equip.h>
#include <ansi.h>
inherit ITEM;

int get_item_value() { return 500; }
int get_item_value_2() { return 500; }
int get_item_number() { return 30; }
int get_item_color() { return 2; }

int is_repair() { return 1; }


void create()
{
    set_name("Tinh Thạch");
    set_picid_1(4108);
    set_picid_2(4108);
    set_value(500);
}

string get_desc()
{
    return "Loại đá đặc biệt dùng để rèn lại trang bị, thời gian dát vàng hiệu lực trong 15 ngày";
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
	string result;
	int i, rate;

	if (!equip->is_equip()) return 0;

	if (equip->is_equip())
	{
		i = equip->get_equip_type();
		if (i != WEAPON_TYPE && i != ARMOR_TYPE && i != HEAD_TYPE && i != BOOTS_TYPE && i != WAIST_TYPE && i != NECK_TYPE)
			return 0;
	}

	rate = 20;

	if (me->get_vip()) {
		rate += 5;
	}
	
	if (type == 1)
	{
		result = sprintf("Tỉ lệ thành công %d%%. Bạn có chắc chắn muốn dát vàng trang bị " + HIR"%s" + NOR" không?\n"
			ESC "%c\n" ESC "\nmove ! %x# %d\n"
			,rate, equip->get_name(), 1, getoid(item), get_d(equip));
		send_user(me, "%c%c%s", 0x59, 1, result);
		return 1;
	}

	if (random(100) <= rate) {
		equip->set("gold_time", time() + 15 * 24 * 3600);

		equip->set("goldAP+", 300);
		equip->set("goldCP+", 300);
		equip->set("goldDP+", 100);
		equip->set("goldPP+", 100);

		send_user(me, "%c%d%c", 0x31, getoid(equip), 0);
		tell_user(me, ECHO"Tinh luyện thành công!");

		result = sprintf(HIY "Chúc mừng người chơi %s dát vàng thành công trang bị %s!", me->get_name(), equip->get_name());
		USER_D->user_channel(result);
	}
	else {
		tell_user(me, ECHO"Tinh luyện thất bại!");
	}
	

	result = sprintf("Vật phẩm biến mất %s,%d,%s,%s @%s %s %s %d %s %d_%d_%d", me->get_name(), me->get_number(), get_ip_name(me), me->get_id(), "", item->get_name(), "/sys/item/item"->get_pawn_save_string(item), 1, item->get_user_id(), get_z(me), get_x(me), get_y(me));
	"/sys/user/cmd"->log_item(result);
	item->remove_from_user();
	destruct(item);
	return 1;
}
