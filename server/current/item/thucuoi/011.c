#include <item.h>
#include <ansi.h>
#include <effect.h>
#include <skill.h>
inherit ITEM;
inherit USABLE;

inherit "/inh/equip/equip";
int get_item_color() { return 2; }
#define RIDE_ID	32

// 函数：构造处理
void create()
{
        set_name( "Rùa Xanh" );
        set_picid_1(10);
        set_picid_2(10);
        set_value(500);
        set_hide(0);
        set_bind(1);
		set_save_2("cqtq.score", 50);
}

// 函数：获取描述
int get_item_value() {return 8 ;}
int get_item_value_2() {return 8 ;}
string get_desc() 
{ 
	return sprintf("Thú Cưỡi Bổ Trợ\n"
		HIY"Ngoại Kháng: +150\n"
		HIY"Khí Huyết: +200\n"
		HIC"Giảm thương: +1%%\n\n"
		"Sau khi sử dụng sẽ phong ấn vào nhân vật.\n");
}


string get_tail_desc()
{
	object item = this_object();
	string desc;

	if (item->get_lock_time() == 0)
	{
		desc = HIG "(Chưa kích hoạt)" NOR "[Thời gian sử dụng 20 ngày]\n ";
	}

	return desc;
}

int get_use_effect(object me) { return __FILE__->get_use_effect_callout(me, this_object()); }

int get_use_effect_callout(object me, object item)
{
	int type;
	object who, npc;
	int i, size, x, y, z, p;
	if (item->get_lock_time() == 0) item->set_lock_time(time() + 20 * 24 * 60 * 60);
	if (item->get_lock_time() < time())
	{
		send_user(me, "%c%s", '!', "Hết hạn sử dụng");
		return 0;
	}

	if (item->get_bind() == 1)
	{
		item->set_bind(2);
		send_user(me, "%c%d%c", 0x31, getoid(item), 0);
	}

	if (me->get_ride())
	{
		me->set_ride(0);
		me->add_to_scene(get_z(me), get_x(me), get_y(me), get_d(me));
		return 0;
	}

	if (me->get_2("rided") == RIDE_ID) {
		me->set_ride(RIDE_ID);
		me->add_to_scene(get_z(me), get_x(me), get_y(me), get_d(me));
		return 0;
	}

	if (me->set_ride(RIDE_ID))
	{
		me->delete_2("thucuoi");
		me->set_2("thucuoi.dp", 150);
		me->set_2("thucuoi.hp", 200);

		USER_ENERGY_D->count_dp(me);
		USER_ENERGY_D->count_max_hp(me);

		me->set_2("thucuoi.anti_hurt", 1);
		USER_ENERGY_D->count_anti_hurt(me);

		me->add_to_scene(get_z(me), get_x(me), get_y(me), get_d(me));
		me->set_2("rided", RIDE_ID);

		return 0;
	}

	return 0;
}
