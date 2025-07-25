#include <item.h>
#include <ansi.h>
inherit ITEM;
inherit COMBINED;
inherit USABLE;

int is_zhongqiu() { return 1; }
int get_item_type_2() { return ITEM_TYPE_2_CON_ALL; }
int get_recover_count() { return 10; }
// 函数：构造处理
void create()
{
    set_name("Bánh Kem");
    set_picid_1(3019);
    set_picid_2(3019);
    set_unit("个");
    set_value(100);
    set_amount(1);
    set("add_hp", 400);
    set("add_mp", 400);
    /*set_no_give(1);
    set_no_sell(1);*/

}

void reset()
{
    if (gone_time(get_drop_time()) > 3000)    // 50分钟
    {
        remove_from_scene();
        destruct(this_object());
    }
}

// 函数：获取描述
string get_desc()
{
    return "Sử dụng sẽ hồi phục 400 điểm khí huyết, 400 điểm pháp lực trong 20 giây .";
}

// 函数：使用效果
int get_use_effect(object me) { return "/sys/item/food"->get_use_effect(me, this_object()); }