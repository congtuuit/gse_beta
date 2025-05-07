
#include <item.h>
#include <ansi.h>

inherit ITEM;
inherit USABLE;

int get_item_value() {return 5 ;}
int get_item_value_2() {return 5 ;}
int get_item_color() { return 2; }


void create()
{
        set_name("Túi Chiến Quốc Điểm Phiếu (x50)");
        set_picid_1(4980);
        set_picid_2(4980);
        set_unit("本");
        set_value(10);
}

string get_desc() 
{ 
        return "Sử dụng nhận được 50 Chiến Quốc Điểm Phiếu";
}

int get_use_effect( object me ) { return __FILE__ ->get_use_effect_callout( me, this_object() ); }

// 函数：使用效果(在线更新)
int get_use_effect_callout( object me, object item )
{
    object new_item;
    int p;

    if (USER_INVENTORY_D->get_free_count(me) < 1)
    {
        send_user(me, "%c%s", '!', "Hành trang không đủ chỗ.");
        return 0;
    }


    item->remove_from_user();
    destruct(item);

    new_item = new("item/common/box/tukim/item/cqdp");
    new_item->set_amount(50);

    p = new_item->move2(me, -1);
    new_item->add_to_user(p);

    return 1;
}
