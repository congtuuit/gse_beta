#include <effect.h>
inherit ITEM;
inherit COMBINED;

// 函数：叠加上限
int get_max_combined() { return 99; }

int get_item_color() { return 1; }

// 函数：构造处理
void create()
{
        set_name("Hắc Cầu");
        set_picid_1(3565);
        set_picid_2(3565);
        set_value(50);
        set_amount(1);
}

// 函数：获取描述
string get_desc() 
{ 
        return "Dùng sợi tơ đen và trắng mà đan thành cầu, dùng để đổi vật phẩm"; 
}
