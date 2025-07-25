#include <ansi.h>
#include <item.h>
#include <equip.h>
#include <effect.h>
#include <skill.h>

inherit ITEM;
inherit USABLE;
inherit "/inh/equip/equip";

#define FASHION_ID	9
int is_aocuoi() { return 1; }
int get_item_value() {return 700;}
int get_item_value_2() {return 700;}
int get_item_color() {return 2 ;}

void create()
{
        set_name("Hôn Sa (Đỏ)");
        set_picid_1(0007);
        set_picid_2(0007);
        set_value(500);
		set_hide(0);

		set_level(1);
		set_bind(4);
		set("time_item", 1);

}

string get_desc() 
{ 
	object item=this_object();
	string desc;
	desc = "[Hiện Đại] Áo cưới tân thời của Nữ, tô điểm sự trong sáng thuần khiết. Khí Huyết +10 % , Phòng Thủ +10 % \n Nhấn chuột phải để sử dụng.";
	if (item->get_lock_time()==0)
	{
		desc+="\n"+"(Sử dụng trong 14 ngày)";
	}
	return desc;
}

int get_use_effect( object me ) { return __FILE__ ->get_use_effect_callout(me, this_object()); }

int get_use_effect_callout( object me, object item )
{
	int type;
	object who, npc;
	int i, size, x, y, z, p;
	
	if(me->get_gender()!=2)
	{
		return 0;
	}

	if (item->get_lock_time() == 0)
	{
		item->set_lock_time(time()+14*24*60*60);
		send_user( me, "%c%d%c", 0x31, getoid(item), 0 );
	}
	if (item->get_lock_time()<time())
	{
		send_user(me, "%c%s", '!', "Trang bị đã quá hạn.");
		return 0;		
	}
	if (me->get_save_2("marry_fashion"))
	{
		me->delete_save_2("marry_fashion");
		if (me->get_save("old_hair")) {
			me->set_hair(me->get_save("old_hair"));
			me->delete_save("old_hair");
		}
		USER_ENERGY_D->count_all_prop(me);
		me->add_to_scene(get_z(me), get_x(me), get_y(me), get_d(me));
		send_user( get_scene_object_2(me, USER_TYPE), "%c%d%w%c%c%c", 0x6f, getoid(me), 42431, 1, OVER_BODY, PF_ONCE );
		return 0;
	}
		me->delete_save_2("marry_fashion");
		me->set_save_2("marry_fashion.time", item->get_lock_time());
		me->set_save_2("marry_fashion.code", FASHION_ID);
		me->set_save_2("marry_fashion.type", 1);
	//	me->set_save("old_hair", me->get_hair());
	//	me->set_hair(1009);
		me->set_save("nonaocuoi",1);
		me->set_save_2("marry_fashion.dp", 10);
		me->set_save_2("marry_fashion.pp", 10);
		me->set_save_2("marry_fashion.hp", 10);
		me->set_save_2("marry_fashion.color", 0x4000);
		me->set_save_2("marry_fashion.double", 200);

		USER_ENERGY_D->count_dp(me);
		USER_ENERGY_D->count_pp(me);
		USER_ENERGY_D->count_max_hp(me);
		USER_ENERGY_D->count_hit_rate(me);

		me->add_to_scene(get_z(me), get_x(me), get_y(me), get_d(me));
		send_user( get_scene_object_2(me, USER_TYPE), "%c%d%w%c%c%c", 0x6f, getoid(me), 42431, 1, OVER_BODY, PF_ONCE );
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