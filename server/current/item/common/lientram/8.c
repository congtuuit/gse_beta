#include <ansi.h>
#include <effect.h>
#include <skill.h>
#include <time.h>
#include <equip.h>

inherit TALISMAN;

private int iLienTram = 800;

int set_lientram(int value) {
	return iLienTram = value;
}

int get_lientram() { return iLienTram; }
int is_lientram() { return 1; }

int get_value_by_lientram(int input) {
	int result;

	switch (input)
	{
	case 100:
		result = 100;
		break;
	case 200:
		result = 150;
		break;
	case 300:
		result = 200;
		break;
	case 400:
		result = 250;
		break;
	case 500:
		result = 350;
		break;
	case 600:
		result = 450;
		break;
	case 700:
		result = 550;
		break;
	case 800:
		result = 650;
		break;
	case 900:
		result = 750;
		break;
	case 1000:
		result = 1000;
		break;
	}
	
}

int get_talisman_type() { return 1; }
int is_limit_time_item() { return 1; }

int get_item_value() {return 300 ;}
int get_item_value_2() {return 300 ;}
int get_item_number() {return 10001101 ;}
int get_item_color() {return 3 ;}
int is_sub_item() {return 1;}

void create()
{
        set_name(sprintf("%d Liên Trảm", get_lientram()));
        set_picid_1(1016);
        set_picid_2(1016);
        set_unit("个");
        set_value(50);

        set("time_item",1);

		set("cp%", get_lientram() / 100);
		set("ap%", get_lientram() / 100);

		set("cp", get_lientram()/2);
		set("ap", get_lientram()/2);
		
		set("pp", get_lientram() / 5);
		set("dp", get_lientram() / 5);

        set_no_give(1);
        set_no_sell(1);
        set_max_lasting(35099);

		set_lock_time(time() + 1 * 12 * 60 * 60);
        setup();
          
}  

string get_desc()
{
	return "";
}

string get_short()
{
	return "[Pháp bảo liên trảm]";
}

void start_loop_perform(object me)
{
	CHAR_CHAR_D->init_loop_perform(me);
	send_user(get_scene_object_2(me, USER_TYPE), "%c%d%w%c%c%c", 0x6f, getoid(me), 9009, 1, UNDER_FOOT, PF_LOOP);
	me->add_to_scene(get_z(me), get_x(me), get_y(me), get_d(me));

}
void stop_loop_perform(object me)
{
	CHAR_CHAR_D->init_loop_perform(me);
	send_user(get_scene_object_2(me, USER_TYPE), "%c%d%w%c%c%c", 0x6f, getoid(me), 9009, 1, UNDER_FOOT, PF_STOP);
	me->add_to_scene(get_z(me), get_x(me), get_y(me), get_d(me));
}


int get_equip_effect(object me)
{
	return __FILE__->get_equip_effect_callout(me, this_object());
}

int get_equip_effect_callout(object me, object item)
{
	if (item->get_lock_time() == 0)
	{
		item->set_lock_time(time() + 1 * 12 * 60 * 60);
		send_user(me, "%c%d%c", 0x31, getoid(item), 0);
	}
}

string get_tail_desc()
{
	object item = this_object();
	string desc;

	if (item->get_lock_time() == 0)
	{
		desc = HIG "(Chưa kích hoạt)" NOR "[Thời gian sử dụng 8 tiếng]\n ";
	}

	return desc;
}

