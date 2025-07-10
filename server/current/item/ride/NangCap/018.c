#include <item.h>
#include <effect.h>
#include <skill.h>
inherit ITEM;
inherit USABLE;

inherit "/inh/equip/equip";

int get_item_color() { return 2; }

#define RIDE_ID	18 

// 函数：nh9h构造处理
void create()
{
		// TANG TOC DO DI CHUYEN
        set_name( "Hỏa Kì Lân" );
        set_picid_1(10);
        set_picid_2(10);
        set_value(500);
        set_hide(0);
        set_bind(0);
}

// 函数：nh9h获取描述
int get_item_value() {return 500 ;}
int get_item_value_2() {return 500 ;}
string get_desc() 
{ 
        return "Thần Thú VIP gia tăng 500 Công kích và 200 Thân thủ sau khi cưỡi. ";
}

// 函数：nh9h使用效果
int get_use_effect( object me ) { return __FILE__ ->get_use_effect_callout(me, this_object()); }

// 函数：nh9h使用效果(在线更新)
int get_use_effect_callout( object me, object item )
{
	int type;
	object who, npc;
	int i, size, x, y, z, p;	
	
	if (me->get_ride()) 
	{
		me->set_2("thucuoi.ap", 0);
		me->set_2("thucuoi.cp", 0);
	//	me->set_2("thucuoi.dp", 0);
	//	me->set_2("thucuoi.pp", 0);
		me->set_2("thucuoi.sp", 0);
		USER_ENERGY_D->count_ap(me);
		USER_ENERGY_D->count_cp(me);
	//	USER_ENERGY_D->count_dp(me);
	//	USER_ENERGY_D->count_pp(me);
		USER_ENERGY_D->count_sp(me);
			me->set_ride(0);
			me->add_to_scene(get_z(me), get_x(me), get_y(me), get_d(me));		
			return 0;
	}

	if (me->set_ride(18))
	{
		//me->set_walk_speed(3); // NEED DEBUG

		me->set_2("thucuoi.ap", 500);
		me->set_2("thucuoi.cp", 500);
	//	me->set_2("thucuoi.dp", 500);
	//	me->set_2("thucuoi.pp", 500);
		me->set_2("thucuoi.sp", 200);
		USER_ENERGY_D->count_ap(me);
		USER_ENERGY_D->count_cp(me);
	//	USER_ENERGY_D->count_dp(me);
	//	USER_ENERGY_D->count_pp(me);
		USER_ENERGY_D->count_sp(me);
			me->add_to_scene(get_z(me), get_x(me), get_y(me), get_d(me));		
			return 0;
	}
	me->set_ride(RIDE_ID);
	me->add_to_scene(get_z(me), get_x(me), get_y(me), get_d(me));
	if (item->get_bind()==1)
	{
		item->set_bind(0);
		send_user( me, "%c%d%c", 0x31, getoid(item), 0 );
	}
        return 0;
}