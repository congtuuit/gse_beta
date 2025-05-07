#include <equip.h>
#include <ansi.h>
inherit USABLE;
inherit ITEM;
inherit COMBINED;


int is_key() { return 1; }
int is_key_sp() { return 1; }

int get_item_value() { return 15; }
int get_item_value_2() { return 15; }
int get_item_number() { return 30; }
int get_item_color() { return 1; }

void create()
{
    set_name("Chìa Khoá Đồng");
    set_picid_1(6701);
    set_picid_2(6701);
    set_level(1);
    set_value(200000);
}

string get_desc()
{
    return "Chìa khóa đặc biệt, dùng để mở Hồng Mộc Bảo Rương. \n Khi tra chìa khóa vào, có thể làm "HIR"Hồng Mộc Bảo Rương"NOR" mở ra...";
}
