#include <equip.h>
#include <ansi.h>
#include <skill.h>
#include <effect.h>
#include <item.h>
#include <map.h>
#include <action.h>

inherit "/inh/equip/back";
int get_item_color() { return 2; }
int get_item_value() {return 1500 ;}
int get_item_value_2() {return 1500 ;}

int is_back_item () {return 1;}
int level () {return 2;}
string get_code_item() {return "canhtrangden";}

void create()
{
        set_name("Thiên Ma Chi Dực +1");
        set_picid_1(3028);
        set_picid_2(3028);

        set_level(1);
		set_bind(1);
        set_value(1500);
        set_max_lasting(21599);
        set("ap+", 450);
        set("cp+", 450);
        set("dp+", 450);
        set("pp+", 450);
        set("hp+", 1300);
        set("mp+", 1300);
        set("sp+", 200);
        set("double", 700);

        setup();

        //set_gender(2);
        set_back_type(7);
		set_back2_type(7);
		set_back_color(0xffff);
        set_back2_color(0x00000000);
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
    CHAR_CHAR_D->init_loop_perform(me);
    send_user(get_scene_object_2(me, USER_TYPE), "%c%d%w%c%c%c", 0x6f, getoid(me), 40812, 1, UNDER_FOOT, PF_LOOP);
    send_user(get_scene_object_2(me, USER_TYPE), "%c%d%w%c%c%c", 0x6f, getoid(me), 4176, 1, OVER_BODY, PF_LOOP);
}