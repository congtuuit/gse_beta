#include <item.h>
#include <ansi.h>
#include <effect.h>
#include <skill.h>
inherit ITEM;
inherit USABLE;

inherit "/inh/equip/equip";

#define RIDE_ID	28

// 函数：构造处理
void create()
{
        set_name( "Gấu Trắng" );
        set_picid_1(10);
        set_picid_2(10);
        set_value(500);
        set_hide(0);
        set_bind(1);
}

// 函数：nh9h获取描述
int get_item_value() {return 8 ;}
int get_item_value_2() {return 8 ;}
string get_desc() 
{ 
        return "Tề quốc chuyên thuộc kỵ sủng tiểu quai\nSử dụng điều kiện: sử dụng giả vi tề quốc tử dân hoặc dư tề quốc đạt đáo nhất định đích hữu hảo độ.\nCai đạo cụ sử dụng hậu bang định.\n";
}
string get_tail_desc()
{
	object item = this_object();
	string desc;

	if (item->get_lock_time() == 0)
	{
		desc = HIG "(Chưa kích hoạt)" NOR "[Thời gian sử dụng 31 ngày]\n ";
	}

	return desc;
}
// 函数：使用效果
int get_use_effect( object me ) { return __FILE__ ->get_use_effect_callout(me, this_object()); }

// 函数：使用效果(在线更新)
int get_use_effect_callout( object me, object item )
{
	int type;
	object who, npc;
	int i, size, x, y, z, p;	
	if (item->get_lock_time()==0) item->set_lock_time(time()+31*24*60*60);
	if (item->get_lock_time()<time())
	{
		send_user(me, "%c%s", '!', "Hết hạn sử dụng");
		return 0;		
	}	
	if (me->get_ride())
	{
		me->set_ride(0);
		me->add_to_scene(get_z(me), get_x(me), get_y(me), get_d(me));		
		return 0;
	}
	me->set_ride(RIDE_ID);
	me->add_to_scene(get_z(me), get_x(me), get_y(me), get_d(me));
	if (item->get_bind()==1)
	{
		item->set_bind(2);
		send_user( me, "%c%d%c", 0x31, getoid(item), 0 );
	}
        return 0;
}