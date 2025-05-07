#include <equip.h>
#include <ansi.h>
inherit USABLE;
inherit ITEM;
inherit COMBINED;


int is_key() { return 1; }
int is_key_sp() { return 1; }

int get_item_value() { return 155; }
int get_item_value_2() { return 155; }
int get_item_number() { return 30; }
int get_item_color() { return 3; }

void create()
{
    set_name("Chìa Khoá Tử Kim");
    set_picid_1(6705);
    set_picid_2(6705);
    set_level(10);
    set_value(1000000);
}

string get_desc()
{
    return "Chìa khóa đặc biệt, dùng để mở Rương Báu Vật. \n Khi tra chìa khóa vào, có thể làm "HIR"Tử Kim Bảo Rương"NOR" mở ra...";
}
