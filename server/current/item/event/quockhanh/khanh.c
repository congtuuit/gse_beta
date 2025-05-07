#include <item.h>
#include <ansi.h>
inherit ITEM;
inherit COMBINED;

int get_max_combined() { return 30; }
int get_item_color() { return 1; }
void create()
{
    set_name("Khánh");
    set_picid_1(3601);
    set_picid_2(3601);
    set_value(50);
    set_amount(1);
}

string get_desc()
{
    return "Vật phẩm sự kiện, thu thập đủ bộ chữ có thể nhận được nhiều phần quà giá trị";
}