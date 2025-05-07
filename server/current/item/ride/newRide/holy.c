#include <item.h>
#include <ansi.h>
#include <effect.h>
#include <skill.h>

inherit ITEM;
inherit USABLE;
inherit "/inh/equip/equip";

#define RIDE_ID	27 

int get_item_value() { return 2550; }
int get_item_value_2() { return 2550; }
int get_item_color() { return 2; }

void create()
{
        set_name( "Hồ Ly Lệnh (Giới Hạn)" );
        set_picid_1(4984);
        set_picid_2(4984);
		set_value(500);
		set_hide(0);
		set_bind(1);
		setup();
}

string get_desc(object me)
{
	return "Triệu hồi thú cưỡi Hồ Ly - Thú cưỡi sự kiện";
}

int get_use_effect(object me)
{
	return __FILE__->get_use_effect_callout(me, this_object());
}

int get_use_effect_callout(object me, object item)
{
	object* obj, zombie, npc;
	int size, index, p, z, x, y;

	if (item->get_bind() == 1)
	{
		item->set_bind(2);
		send_user(me, "%c%d%c", 0x31, getoid(item), 0);
	}

	if (item->get_lock_time() == 0)
	{
		item->set_lock_time(time() + 14 * 24 * 60 * 60);
		send_user(me, "%c%d%c", 0x31, getoid(item), 0);
	}

	if (item->get_lock_time() < time())
	{
		send_user(me, "%c%s", '!', "Trang bị đã quá hạn.");
		return;
	}

	if (me->get_ride())
	{
		me->set_ride(0);
		me->add_to_scene(get_z(me), get_x(me), get_y(me), get_d(me));
		return 0;
	}

	me->set_ride(RIDE_ID);
	me->add_to_scene(get_z(me), get_x(me), get_y(me), get_d(me));

	item->set_no_drop(1);
	item->set_no_get(1);
	item->set_no_give(1);

	return 0;
}

string get_tail_desc()
{
	object item = this_object();
	string desc;

	if (item->get_lock_time() == 0)
	{
		desc = HIG "(Chưa kích hoạt)" NOR "[Thời gian sử dụng 14 ngày]\n ";
	}

	return desc;
}