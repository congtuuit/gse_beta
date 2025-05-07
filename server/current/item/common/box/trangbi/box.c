#include <ansi.h>
#include <equip.h>
inherit USABLE;
inherit ITEM;

inherit COMBINED;

int is_box() { return 1; }
int is_box_sp() { return 1; }
int get_item_value() { return 300; }
int get_item_value_2() { return 300; }
int get_item_color() { return 2; }


void create()
{
    set_name("Rương Trang Bị (Khóa)");
    set_picid_1(6704);
    set_picid_2(6704);
    set_level(2);
    set_value(50);
    set_amount(1);
    set_no_give(1);
    set_no_sell(1);
}

string get_desc()
{
    return "Kho báu được chôn giấu, nghe nói vật phẩm bên trong vô cùng giá trị ( có thể dùng "HIR "Chìa Khoá Thanh Đồng"NOR " mở ra).";
}

int get_use_effect(object me)
{

    send_user(me, "%c%c%c%d", 0x91, 1, 2, getoid(this_object()));

    return 0;
}
