
#include <item.h>
#include <ansi.h>

inherit ITEM;
inherit USABLE;

int get_item_value() {return 5 ;}
int get_item_value_2() {return 5 ;}
int get_item_color() { return 2; }


// 函数：构造处理
void create()
{
        set_name("Túi Ngân Lượng");
        set_picid_1(4980);
        set_picid_2(4980);
        set_unit("本");
        set_value(10);
        set_save_2("cqtq.score", 2);

}

// 函数：获取描述
string get_desc() 
{ 
        return "Sử dụng nhận được ngân lượng ngẫu nhiên";
}

// 函数：使用效果
int get_use_effect( object me ) { return __FILE__ ->get_use_effect_callout( me, this_object() ); }

// 函数：使用效果(在线更新)
int get_use_effect_callout( object me, object item )
{
    int value;
    item->remove_from_user();
    destruct(item);

    value = random(200000) + 200000;
	me->add_cash(value);
    send_user(me, "%c%s", '!', "Bạn nhận được " + value + " lượng.");
    tell_user(me, sprintf(ECHO"Bạn nhận được %d lượng", value));
    return 1;
}
