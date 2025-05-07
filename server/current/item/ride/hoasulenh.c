#include <item.h>
#include <ansi.h>
#include <effect.h>
#include <skill.h>

inherit ITEM;
inherit USABLE;
inherit "/inh/equip/equip";

#define RIDE_ID	18 
//#define RIDE_ID	1

int get_item_value() { return 10000; }
int get_item_value_2() { return 10000; }
int get_item_color() { return 2; }

void create()
{
        set_name( "Hỏa Sư Lệnh" );
        set_picid_1(4984);
        //set_picid_1(4983);
        set_picid_2(4984);
        //set_picid_2(4983);
		set_value(500);
		set_hide(0);
		set_bind(1);
		set_no_sell(1);

		//set_head_color(0x001);
		setup();

}

string get_desc(object me)
{
	return sprintf("Thú cưỡi sự kiện\n"
		PPM"Ngoại công: +400\n"
		PPM"Nội công: +400\n"
		PPM"Ngoại kháng: +300\n"
		PPM"Nội kháng: +300\n"
		PPM"Bạo kích: +2%%"
	);

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
		item->set_lock_time(time() + 30 * 24 * 60 * 60);
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

	if (me->set_ride(RIDE_ID))
	{
		me->set_2("thucuoi.ap", 400);
		me->set_2("thucuoi.cp", 400);
		me->set_2("thucuoi.dp", 300);
		me->set_2("thucuoi.pp", 300);
		me->set_2("thucuoi.sp", 0);
		me->set_2("thucuoi.hp", 0);
		me->set_2("thucuoi.do", 200);

		USER_ENERGY_D->count_ap(me);
		USER_ENERGY_D->count_cp(me);
		USER_ENERGY_D->count_dp(me);
		USER_ENERGY_D->count_pp(me);
		USER_ENERGY_D->count_sp(me);
		USER_ENERGY_D->count_max_hp(me);
		USER_ENERGY_D->count_hit_rate(me);

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
		desc = HIG "(Chưa kích hoạt)" NOR "[Thời gian sử dụng 30 ngày]\n ";
	}

	return desc;
}