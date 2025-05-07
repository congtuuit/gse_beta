#include <effect.h>
inherit ITEM;
inherit COMBINED;

int get_item_value() { return 3000; }
int get_item_value_2() { return 3000; }
int get_item_number() { return 30; }
int get_item_color() { return 2; }

// 函数：构造处理
void create()
{
    set_name("Đá Ngũ Sắc");
    set_picid_1(4108);
    set_picid_2(4108);
    set_value(500);
    set_amount(1);
}

// 函数：获取描述
string get_desc()
{
    return "Loại đá đặc biệt dùng để rèn lại thuộc tính ngũ hành cho trang bị.";
}
