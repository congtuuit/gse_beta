#include <item.h>
#include <effect.h>
#include <skill.h>
#include <ansi.h>

inherit ITEM;
inherit USABLE;

inherit "/inh/equip/equip";

#define FASHION_ID	9

int is_aocuoi() { return 1; }
int get_item_value() { return 300; }
int get_item_value_2() { return 300; }
int get_item_color() { return 2; }
int is_specal_move() { return 1; }
int is_fashion() { return 1; }

string get_next_item() { return "/item/trangphuc/ngoaitrang/sp2"; }

void create()
{
        set_name("Hôn Sa");
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
	object item = this_object();
	string desc;
	desc = "\n[Hiện Đại] Áo cưới tân thời của Nam, tràn đầy vẻ hào hoa phong nhã. Khí Huyết +5 % , Phòng Thủ +5 % \n Nhấn chuột phải để sử dụng.";
	if (item->get_lock_time() == 0)
	{
		desc += "\n" + "(Sử dụng trong 14 ngày)" + "\n" + HIC"[Có thể ghép]";
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
		send_user( get_scene_object_2(me, USER_TYPE), "%c%d%w%c%c%c", 0x6f, getoid(me), 42432, 1, OVER_BODY, PF_ONCE );
		return 0;
	}
		me->delete_save_2("marry_fashion");
		me->set_save_2("marry_fashion.time", item->get_lock_time());
		me->set_save_2("marry_fashion.code", FASHION_ID);
		me->set_save_2("marry_fashion.type", 1);
	//	me->set_save("old_hair", me->get_hair());
	//	me->set_hair(1009);
		me->set_save("nonaocuoi",1);
		me->set_save_2("marry_fashion.dp", 5);
		me->set_save_2("marry_fashion.hp", 5);
	//	me->set_save_2("marry_fashion.double", 200);
		USER_ENERGY_D->count_dp(me);
	//	USER_ENERGY_D->count_pp(me);
		USER_ENERGY_D->count_max_hp(me);
	//	USER_ENERGY_D->count_hit_rate(me);
		me->add_to_scene(get_z(me), get_x(me), get_y(me), get_d(me));
		send_user( get_scene_object_2(me, USER_TYPE), "%c%d%w%c%c%c", 0x6f, getoid(me), 42432, 1, OVER_BODY, PF_ONCE );
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

int move_item(object me, object item, object equip)
{
	return __FILE__->move_item_callout(me, item, equip, 1);
}

int move_item_callout(object me, object item, object equip, int type)
{
	string result, forge;
	object item2;
	int i, p, level;

	if (!equip->is_fashion())
	{
		return 0;
	}

	if (type == 1)
	{
		if (i == 0)
		{
			result = sprintf("Ngươi xác định hợp thành không?\n"
				ESC "%c\n" ESC "\nfashionmix ? %x# %x#\n"
				, 1, getoid(item), getoid(equip));
			send_user(me, "%c%c%s", 0x59, 1, result);
		}

		return 1;
	}

	return 1;
}