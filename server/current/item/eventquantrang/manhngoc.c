#include <ansi.h>
#include <item.h>
#include <skill.h>

inherit ITEM;
inherit COMBINED;

int get_item_value() { return 200; }
int get_item_value_2() { return 200; }

int get_max_combined() { return 99; }
int get_stuff_type() { return 26; }
int get_item_color() { return 2; }

void create()
{
    set_name("Mảnh Vỡ Ngọc Bội");
    set_picid_1(906);
    set_picid_2(906);
    set_amount(1);
    set_value(200);
}

// 函数：获取描述
string get_desc()
{
    return "Mảnh vỡ ngọc bội của một vị tướng quân. \nĐây là một mảnh vỡ ngọc bội quí hiếm có thể dùng để trao đổi vật phẩm.";
}
