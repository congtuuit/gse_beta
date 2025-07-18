#include <ansi.h>
#include <equip.h>

inherit "/inh/equip/back";
int get_item_color() { return 2; }
int get_item_value() {return 1500 ;}
int get_item_value_2() {return 1500 ;}

int is_back_item () {return 1;}
int level () {return 10;}
string get_code_item() {return "vgpp";}

// 函数：构造处理
void create()
{
        set_name("Vương Giả Phi Phong (Giới Hạn)");
        set_picid_1(3020);
        set_picid_2(3020);

        set_level(1);
		set_bind(1);
        set_value(1500);
        set_max_lasting(21599);

        set("time_item", 1);

        set("ap+", 300);
        set("pp+", 300);
        set("hp+", 800);
		set("mp+", 800);
		//set("sp+", 100);
		set("double", 500);

		set_hide(0);
        setup();

        set_gender(1);
		set_back_type(1);

        set_no_sell(1);
        set_no_give(1);
}

// 函数：获取描述
string get_desc()
{
        return "Một chiếc áo choàng thần bí kiêu hùng, mặc áo choàng này lên, sẽ hiện lên phong cách của Vương Giả.";
}

// 函数：使用效果
int get_equip_effect(object me)
{
	return __FILE__->get_equip_effect_callout(me, this_object());
}

// 函数：使用效果(在线更新)
int get_equip_effect_callout(object me, object item)
{
	//处理时间控制上面的。
	if (item->get_lock_time() == 0)
	{
		item->set_lock_time(time() + 7 * 24 * 60 * 60);
		send_user(me, "%c%d%c", 0x31, getoid(item), 0);
	}
}

//
string get_tail_desc()
{
	object item = this_object();
	string desc;

	if (item->get_lock_time() == 0)
	{
		desc = HIG "(Chưa kích hoạt)" NOR "[Thời gian sử dụng 7 ngày]\n ";
	}

	return desc;
}
