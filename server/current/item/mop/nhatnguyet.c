#include <ansi.h>
#include <effect.h>
#include <skill.h>
#include <time.h>
#include <equip.h>

inherit TALISMAN;
int get_talisman_type() { return 1; }

int get_item_value() {return 300 ;}
int get_item_value_2() {return 300 ;}
int get_item_number() {return 10001101 ;}
int get_item_color() {return 3 ;}

int is_sub_item() {return 1;}

// 函数：构造处理
void create()
{
		set_name("Nhật Nguyệt Tinh Thần");
		set_picid_1(9006);//未Chấp nhận。
		set_picid_2(9006);
		set_unit("个");

		set_value(50);
		set_no_give(1);
		set_no_sell(1);
		set_max_lasting(35099);

		set("time_item", 1);

		set("cp%", 2);
		set("cp", 200);
		set("pp", 200);
		set("dp", 100);

		setup();
}   

// 函数：获取描述
string get_desc() 
{
	return "";
}

string get_short()
{
	return "[Pháp bảo] Nội công +2%, Nội công +200, Nội kháng +200, Ngoại kháng +100 . Thời gian sử dụng 14 ngày, phong ấn sau khi sử dụng.";
}

void start_loop_perform(object me)
{
	CHAR_CHAR_D->init_loop_perform(me);
	send_user( get_scene_object_2(me, USER_TYPE), "%c%d%w%c%c%c", 0x6f, getoid(me), 9009, 1,UNDER_FOOT, PF_LOOP );
	me->add_to_scene(get_z(me), get_x(me), get_y(me), get_d(me));

}
void stop_loop_perform(object me)
{
	CHAR_CHAR_D->init_loop_perform(me);
	send_user( get_scene_object_2(me, USER_TYPE), "%c%d%w%c%c%c", 0x6f, getoid(me), 9009, 1, UNDER_FOOT, PF_STOP );
	me->add_to_scene(get_z(me), get_x(me), get_y(me), get_d(me));
}


// 函数：Sử dụng效果
int get_equip_effect( object me )
{
	return __FILE__ ->get_equip_effect_callout(me, this_object());
}

// 函数：Sử dụng效果(在线更新)
int get_equip_effect_callout( object me, object item )
{
	//处理时间控制上面的。
	if (item->get_lock_time() == 0)
	{
		item->set_lock_time(time()+14*24*60*60);
		send_user( me, "%c%d%c", 0x31, getoid(item), 0 );
	}
}

//
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

