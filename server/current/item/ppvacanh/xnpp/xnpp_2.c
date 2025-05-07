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
int level () {return 2;}
string get_code_item() {return "xnpp";}

// 函数：构造处理
void create()
{
        set_name("Xí Nhiệt Phi Phong +2");
        set_picid_1(3021);
        set_picid_2(3021);

        set_level(1);
		set_bind(1);
        set_value(1000);
        set_max_lasting(21599);

        set("ap+", 700);
        set("pp+", 700);
        set("hp+", 1650);
		set("mp+", 1650);
		//set("sp+", 500);
		set("double", 950);

        setup();

        set_gender(2);
        set_back_type(1);
		set_back_color(0xaaaaa);
}

// 函数：获取描述
string get_desc()
{
        return "Áo choàng nữ anh hùng không kém đấng mày râu, mặc áo choàng này lên, sẽ hiện rõ khí chất anh hùng.";
}

int get_equip_effect( object me )
{
	return __FILE__ ->get_equip_effect_callout(me, this_object());
}

// 函数：使用效果(在线更新)
int get_equip_effect_callout( object me, object item )
{
	//处理时间控制上面的。

    CHAR_CHAR_D->init_loop_perform(me);
	send_user( get_scene_object_2(me, USER_TYPE), "%c%d%w%c%c%c", 0x6f, getoid(me), 40812, 1,UNDER_FOOT, PF_LOOP );
    send_user(get_scene_object_2(me, USER_TYPE), "%c%d%w%c%c%c", 0x6f, getoid(me), 4176, 1, OVER_BODY, PF_LOOP);


}
