#include <item.h>
#include <effect.h>
#include <skill.h>
inherit ITEM;
inherit COMBINED;
inherit USABLE;

#define ITEM_USE_TYPE 	"add_hp"
#define ITEM_USE_TIME	2

int get_item_value() { return 20; }
int get_item_value_2() { return 20; }
int get_item_number() { return 10001007; }
int get_item_color() { return 1; }
int get_number() { return 3000; }

int get_item_type_2() { return ITEM_TYPE_2_ADD_HP; }

void create()
{
    set_name("Siêu Trị Dược");
    set_picid_1(4255);
    set_picid_2(4255);
    set_value(2);
    set_amount(1);
    set_record(1);

   /* set_no_give(1);
    set_no_sell(1);*/

}

string get_desc()
{
    return sprintf("Bình nhỏ chứa dược thủy rất thần hiệu, khi sử dụng sẽ lập tức hồi phục %d điểm Khí Huyết. Có thể tái sử dụng sau 2 giây.", get_number());
}

int get_use_effect(object me) { return __FILE__->get_use_effect_callout(me); }

int get_use_effect_callout(object me)
{
    int type;
    if (get_item_type_2() == ITEM_TYPE_2_ADD_HP) type = EFFECT_USE_ITEM_1;
    else type = EFFECT_USE_ITEM_2;
    if (get_effect(me, type))
    {
        send_user(me, "%c%s", '!', sprintf("Thời gian đóng băng của vật phẩm còn %d giây", get_effect(me, type)));
        return 0;
    }
    set_effect(me, type, ITEM_USE_TIME);
    send_user(me, "%c%c%c%w", 0x30, get_item_type_2(), 0, ITEM_USE_TIME);
    me->add_hp(get_number() * (100 + me->get_healing_rate()) / 100);
    send_user(get_scene_object_2(me, USER_TYPE), "%c%d%w%c%c%c", 0x6f, getoid(me), 9154, 1, OVER_BODY, PF_ONCE);
    return 1;
}
