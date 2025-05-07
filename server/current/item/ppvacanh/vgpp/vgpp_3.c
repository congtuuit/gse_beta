#include <equip.h>
#include <ansi.h>
#include <skill.h>
#include <effect.h>
#include <item.h>
#include <map.h>
#include <action.h>

inherit "/inh/equip/back";
int get_item_color() { return 2; }
int get_item_value() {return 1000 ;}
int get_item_value_2() {return 1000 ;}

int is_back_item () {return 1;}
int level () {return 3;}
string get_code_item() {return "vgpp";}

// 函数：构造处理
void create()
{
        set_name("Vương Giả Phi Phong +3");
        set_picid_1(3020);
        set_picid_2(3020);

        set_level(1);
		set_bind(1);
        set_value(1000);
        set_max_lasting(21599);

        set("ap+", 1050);
        set("pp+", 950);
        set("hp+", 2150);
		set("mp+", 2150);
		//set("sp+", 750);
		set("double", 1100);

		set_hide(0);
        setup();

        set_gender(1);
		set_back_type(1);

        //set_back_color(0x00C0C0C0);
}

// 函数：获取描述
string get_desc()
{
        return "Một chiếc áo choàng thần bí kiêu hùng, mặc áo choàng này lên, sẽ hiện lên phong cách của Vương Giả.";
}

int get_equip_effect( object me )
{
	return __FILE__ ->get_equip_effect_callout(me, this_object());
}

int get_equip_effect_callout( object me, object item )
{
	//处理时间控制上面的。

    CHAR_CHAR_D->init_loop_perform(me);
	send_user( get_scene_object_2(me, USER_TYPE), "%c%d%w%c%c%c", 0x6f, getoid(me), 40812, 1,UNDER_FOOT, PF_LOOP );
    send_user(get_scene_object_2(me, USER_TYPE), "%c%d%w%c%c%c", 0x6f, getoid(me), 4176, 1, OVER_BODY, PF_LOOP);
}