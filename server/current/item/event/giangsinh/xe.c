#include <item.h>
#include <effect.h>
#include <skill.h>
#include <ansi.h>

inherit ITEM;
inherit USABLE;

inherit "/inh/equip/equip";

#define RIDE_ID	17
int get_item_value() { return 8; }
int get_item_value_2() { return 8; }
int get_item_color() { return 2; }
// 函数：nh9h构造处理
void create()
{
	set_name("Xe Giáng Sinh");
	set_picid_1(10);
	set_picid_2(10);
	set_value(500);
	set_hide(0);
	set_bind(1);

	set("time_item", 1);
}

// 函数：nh9h获取描述
string get_desc()
{
	return "Xe giáng sinh đẹp lung linh trong mùa Noel. Quà tặng từ ADMIN";
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

// 函数：nh9h使用效果
int get_use_effect(object me) { return __FILE__->get_use_effect_callout(me, this_object()); }

// 函数：nh9h使用效果(在线更新)
int get_use_effect_callout(object me, object item)
{
	int type;
	object who, npc;
	int i, size, x, y, z, p;

	if (item->get_lock_time() == 0)
	{
		item->set_lock_time(time() + 14 * 24 * 60 * 60);
		send_user(me, "%c%d%c", 0x31, getoid(item), 0);
	}

	if (me->get_ride())
	{
		me->set_ride(0);
		me->add_to_scene(get_z(me), get_x(me), get_y(me), get_d(me));
		return 0;
	}
	me->set_ride(RIDE_ID);
	me->add_to_scene(get_z(me), get_x(me), get_y(me), get_d(me));
	if (item->get_bind() == 1)
	{
		item->set_bind(2);
		send_user(me, "%c%d%c", 0x31, getoid(item), 0);
	}
	return 0;
}
