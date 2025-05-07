#include <equip.h>
#include <ansi.h>
inherit USABLE;
inherit ITEM;
inherit COMBINED;


int is_key() { return 1; }
int is_key_sp() { return 1; }

int get_item_value() { return 20; }
int get_item_value_2() { return 20; }
int get_item_number() { return 30; }
int get_item_color() { return 2; }

void create()
{
    set_name("Chìa Khóa Thanh Đồng");
    set_picid_1(6703);
    set_picid_2(6703);
    set_level(2);
    set_value(300000);
}

string get_desc()
{
    return "Chìa khóa đặc biệt, dùng để mở Rương Trang Bị. \n Khi tra chìa khóa vào, có thể làm "HIR"Rương Trang Bị"NOR" mở ra...";
}
