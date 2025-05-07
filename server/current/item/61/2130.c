
#include <equip.h>
#include <effect.h>
#include <skill.h>

inherit ARMOR;

// 函数：适用门派
int get_family() { return 2; }

// 函数：构造处理
void create()
{
        set_name("Huyền Ma Thần Giáp");
        set_picid_1(6162);
        set_picid_2(6162);
        set_unit("件");

        set_level(130);
        set_value(66000);
        set_max_lasting(46599);
        set("dp", 228);
        set("pp", 175);
  //      set("spec.hp", 235);
   //     set("spec.mp", 195);
    //    set("spec.-*%", 14);

        setup();

        set_gender(2);
        set_armor_code(F_ZHANJIA);
//        set_armor_color_1(0x48ed5908);
 //       set_armor_color_2(0x00004208);
}

// 函数：获取描述
string get_desc()
{
        return "Huyền Ma Thần Giáp";
}
void start_loop_perform( object me )
{
	CHAR_CHAR_D->init_loop_perform(me);
	//send_user( get_scene_object_2(me, USER_TYPE), "%c%d%w%c%c%c", 0x6f, getoid(me), 2416, 1,UNDER_FOOT, PF_LOOP );
	//send_user( get_scene_object_2(me, USER_TYPE), "%c%d%w%c%c%c", 0x6f, getoid(me), 24155, 1,UNDER_FOOT, PF_LOOP );
	me->add_to_scene(get_z(me), get_x(me), get_y(me), get_d(me));
}
void stop_loop_perform( object me )
{
	CHAR_CHAR_D->init_loop_perform(me);
	//send_user( get_scene_object_2(me, USER_TYPE), "%c%d%w%c%c%c", 0x6f, getoid(me), 2416, 1, UNDER_FOOT, PF_STOP );
	//send_user( get_scene_object_2(me, USER_TYPE), "%c%d%w%c%c%c", 0x6f, getoid(me), 24155, 1, UNDER_FOOT, PF_STOP );
	me->add_to_scene(get_z(me), get_x(me), get_y(me), get_d(me));
}