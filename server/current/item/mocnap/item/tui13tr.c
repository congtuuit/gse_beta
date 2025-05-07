
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
}

// 函数：获取描述
string get_desc() 
{ 
        return "Sử dụng nhận được 13.000.000 lượng";
}

// 函数：使用效果
int get_use_effect( object me ) { return __FILE__ ->get_use_effect_callout( me, this_object() ); }

// 函数：使用效果(在线更新)
int get_use_effect_callout( object me, object item )
{
    item->remove_from_user();
    destruct(item);

	me->add_cash(13000000);
    notify("Bạn nhận được 13.000.000 lượng");
    return 1;
}
