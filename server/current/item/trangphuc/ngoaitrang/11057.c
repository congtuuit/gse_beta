#include <ansi.h>
#include <equip.h>

inherit "/inh/equip/fashion";

int get_item_value() { return 2550; }
int get_item_value_2() { return 2550; }
int get_item_color() { return 2; }

void create()
{
        set_name("Sát Thủ Tử Y (Nữ)");
		set_picid_1(11057);
		set_picid_2(11057);
		set_level(1);
		set_bind(4);
		set_value(50);
		set_max_lasting(35099);

		set("dp", 150);
		set("pp", 150);
		set("hp", 300);
		set("?%", 500);
		set("ap%", 10);

		setup();
		set_gender(2);
		set_fashion_code(52);
}

string get_desc() 
{ 
	return "Thể hiện một phong cách kute cá tính.";
}
int get_equip_effect(object me)
{
	return __FILE__->get_equip_effect_callout(me, this_object());
}

int get_equip_effect_callout(object me, object item)
{
	if (item->get_lock_time() == 0)
	{
		item->set_lock_time(time() + 14 * 24 * 60 * 60);
		send_user(me, "%c%d%c", 0x31, getoid(item), 0);
	}
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
