
#include <item.h>
#include <ansi.h>
inherit ITEM;
inherit COMBINED;

int get_max_combined() { return 30; }

int get_item_value() { return 450; }
int get_item_value_2() { return 450; }
int get_item_number() { return 30; }
int get_item_color() { return 1; }

void create()
{
    set_name("Linh Thủy");
    set_picid_1(9991);
    set_picid_2(9991);
    set_unit("个");
    set_value(500);
    set_amount(1);
}


string get_desc()
{
    string desc;
    return desc = "Một loại nước tiên cho cây, dùng để chăm bón cây. Tăng tuổi thọ và khả năng phát triển cho cây.";
}