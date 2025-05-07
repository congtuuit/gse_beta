//#include <item.h>
//#include <ansi.h>
//#include <effect.h>
//#include <skill.h>
inherit ITEM;

int get_item_value() { return 15; }
int get_item_value_2() { return 15; }
int get_item_color() { return 3; }

void create()
{
        set_name("Long Châu");
        set_picid_1(12021);
        set_picid_2(12021);
        set_value(500);
}

// 函数：获取描述
string get_desc() 
{ 
        return "Vật phẩm quý hiếm, nguyên liệu tinh luyện thần khí";
}
