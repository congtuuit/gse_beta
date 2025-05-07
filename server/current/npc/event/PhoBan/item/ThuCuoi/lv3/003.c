#include <item.h>
#include <ansi.h>
#include <effect.h>
#include <skill.h>

inherit ITEM;
inherit USABLE;
inherit "/inh/equip/equip";

#define RIDE_ID	18 

int get_item_value() { return 500; }
int get_item_value_2() { return 500; }
int get_item_color() { return 3; }
int get_ride_id() { return RIDE_ID; }
int get_level() { return 3; }
int get_maxexp() { return 1000; }

void create()
{
        set_name( "Hỏa Kì Lân" );
        //set_picid_1(4984);
        set_picid_1(4983);
        //set_picid_2(4984);
        set_picid_2(4983);
		set_value(500);
		set_hide(0);
		set_bind(1);
		set_no_sell(1);
		set_no_give(1);
		set_no_drop(1);
}

string get_desc(object me)
{
	return sprintf(HIY"Hỏa Kì Lân Huyền Thoại\n"
		PPM"Ngoại công: +600\n"
		PPM"Nội công: +600\n"
		PPM"Ngoại kháng: +350\n"
		PPM"Nội kháng: +350\n"
		PPM"Thân thủ: +200\n"
		PPM"Khí huyết: +800\n"
		PPM"Bạo kích: +2%% \n"
		PPM"Tăng 5%% Ngoại công"

	);

}


int get_use_effect(object me)
{
	return __FILE__->get_use_effect_callout(me, this_object());
}

int get_use_effect_callout(object me, object item)
{
	object* obj, zombie, npc;
	int size, index, p, z, x, y, temp;

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
		me->set_2("thucuoi.ap", 600);
		me->set_2("thucuoi.cp", 600);
		me->set_2("thucuoi.dp", 350);
		me->set_2("thucuoi.pp", 350);
		me->set_2("thucuoi.sp", 200);
		me->set_2("thucuoi.hp", 800);
		me->set_2("thucuoi.do", 200);

		USER_ENERGY_D->count_ap(me);
		USER_ENERGY_D->count_cp(me);
		USER_ENERGY_D->count_dp(me);
		USER_ENERGY_D->count_pp(me);
		USER_ENERGY_D->count_sp(me);
		USER_ENERGY_D->count_max_hp(me);
		USER_ENERGY_D->count_hit_rate(me);


		/*if (me->get_2("jiguan.ap") > 0) {
			temp = me->get_2("jiguan.ap");
			me->delete_2("jiguan");
			USER_ENERGY_D->count_ap(me);
			me->set_2("jiguan.ap", 5 + temp);
		}
		else {
			me->set_2("jiguan.ap", 5);
		}

		USER_ENERGY_D->count_ap(me);*/

		me->add_to_scene(get_z(me), get_x(me), get_y(me), get_d(me));
		me->set_2("rided", RIDE_ID);
		return 0;
	}

	return 0;
}
