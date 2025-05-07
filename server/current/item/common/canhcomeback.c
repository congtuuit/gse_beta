#include <ansi.h>
#include <equip.h>

inherit "/inh/equip/back";
int get_item_color() { return 2; }
int get_item_value() {return 1500 ;}
int get_item_value_2() {return 1500 ;}

int is_back_item () {return 1;}
int level () {return 10;}
string get_code_item() {return "canhnam";}

// 函数：构造处理
void create()
{
        set_name("Thánh Linh Chi Dực·Đỏ Nhạt (Giới Hạn)");
        //set_picid_1(3031);
        //set_picid_2(3031);
		set_picid_1(3029);
        set_picid_2(3029);

        set_level(1);
		set_bind(6);
        set_value(1500);
        set_max_lasting(21599);
		set("time_item", 1);

		set("cp+", 550);
		set("ap+", 500);
        set("hp+", 1450);
		set("mp+", 1450);
		set("sp+", 150);
		set("double", 500);

        setup();

        set_back_type(7);
		set_back2_type(7);
		set_back_color(0x6000);
		set_back2_color(0x6000);

        set_no_sell(1);
        set_no_give(1);
}

string get_desc()
{
        return "Thánh vật của sứ giả Quang Minh, dùng để ngăn cản lực lượng tà ác uy hiếp.";
}

int get_equip_effect(object me)
{
	return __FILE__->get_equip_effect_callout(me, this_object());
}

int get_equip_effect_callout(object me, object item)
{
	if (item->get_lock_time() == 0)
	{
		item->set_lock_time(time() + 7 * 24 * 60 * 60);
		send_user(me, "%c%d%c", 0x31, getoid(item), 0);
	}
}

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
