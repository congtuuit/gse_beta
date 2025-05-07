#include <item.h>
#include <ansi.h>
#include <effect.h>
#include <skill.h>
inherit ITEM;
inherit USABLE;
inherit "/inh/equip/equip";

#define RIDE_ID	33

int get_item_value() { return 500; }
int get_item_value_2() { return 500; }
int get_item_color() { return 2; }
int get_ride_id() { return RIDE_ID; }
int get_level() { return 2; }
int get_maxexp() { return 500; }

void create()
{
        set_name( "Thuỷ Long Quy (Cấp 2)" );
		set_picid_1(10);
		set_picid_2(10);
		set_value(500);
		set_hide(0);
		set_bind(1);
		set_no_sell(1);
		set_no_give(1);
		set_no_drop(1);
}


string get_desc(object me)
{
	return sprintf("Thú Cưỡi Huyền Thoại Cấp 2\n(Được tiến hóa từ Thuỷ Long Quy - Cấp 1)\n"
		HIY"Ngoại Công: +150\n"
		HIY"Nội Công: +150\n"
		HIY"Ngoại kháng: +300\n"
		HIY"Nội kháng: +200\n"
		HIY"Khí huyết: +150\n"
		HIC"Nội Công: +2%%\n"
		HIC"Giảm thương: +6%%\n\n"

		HIR"Cấp tiếp theo \n "
		HIG"Ngoại Công: +200\n"
		HIG"Nội Công: +200\n"
		HIG"Ngoại kháng: +450\n"
		HIG"Nội kháng: +300\n"
		HIG"Khí huyết: +200\n"
		HIC"Nội Công: +3%%\n"
		HIC"Giảm thương: +11%%"
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
		me->set_2("thucuoi.ap", 150);
		me->set_2("thucuoi.cp", 150);
		me->set_2("thucuoi.dp", 300);
		me->set_2("thucuoi.pp", 200);
		me->set_2("thucuoi.sp", 0);
		me->set_2("thucuoi.hp", 150);
		me->set_2("thucuoi.do", 0);

		USER_ENERGY_D->count_ap(me);
		USER_ENERGY_D->count_cp(me);
		USER_ENERGY_D->count_dp(me);
		USER_ENERGY_D->count_pp(me);
		USER_ENERGY_D->count_sp(me);
		USER_ENERGY_D->count_max_hp(me);
		USER_ENERGY_D->count_hit_rate(me);

		me->set_2("thucuoi.cp%", 2);
		USER_ENERGY_D->count_ap(me);

		me->set_2("thucuoi.anti_hurt", 6);
		USER_ENERGY_D->count_anti_hurt(me);

		me->add_to_scene(get_z(me), get_x(me), get_y(me), get_d(me));
		me->set_2("rided", RIDE_ID);
		return 0;
	}

	return 0;
}
