
// 自动生成：/make/item/make90
#include <item.h>
inherit ITEM;
inherit COMBINED;

// 函数：叠加上限
int get_max_combined() { return 30; }

// 函数：原料类型
int get_stuff_type() { return 26; }

// 函数：可使用物品
int get_item_type_2() { return ITEM_TYPE_2_STUFF; }

// 函数：原料颜色
int get_item_color() { return 2; }

int get_item_value() { return 100; }
int get_item_value_2() { return 100; }

// 函数：构造处理
void create()
{
    set_name("Mộc Hồn");
    set_picid_1(4115);
    set_picid_2(4115);
    set_value(100);
    set_amount(1);
}

// 函数：获取描述
string get_desc()
{
    return "Vật phẩm tích lũy dùng để đổi thưởng";
}
