
// 自动生成：/make/item/make31c
#include <item.h>
#include <ansi.h>
inherit ITEM;
inherit COMBINED;

int get_item_color() { return 1; }
// 函数：叠加上限
int get_max_combined() { return 30; }

// 函数：可使用物品

// 函数：构造处理
void create()
{
        set_name("Kẹo Đường Hồ Lô");
        set_picid_1(3325);
        set_picid_2(3325);
        set_unit("串");
        set_value(300);
        set_amount(1);
}

// 函数：获取描述
string get_desc() 
{
    return "Vật phẩm sự kiện Quốc Tế Thiếu Nhi";
}

// 函数：使用效果
