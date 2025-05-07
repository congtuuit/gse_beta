//#include <item.h>
//#include <ansi.h>
//#include <effect.h>
//#include <skill.h>
inherit ITEM;

int get_item_value() { return 15; }
int get_item_value_2() { return 15; }
int get_item_color() { return 1; }

void create()
{
        set_name("Mảnh Ghép Long Châu (1)");
        set_picid_1(12021);
        set_picid_2(12021);
        set_value(300);
        set_save_2("diemnhiemvu.score", 300);
        set_no_sell(1);
        set_no_give(1);
}

// 函数：获取描述
string get_desc() 
{ 
        return "Vật phẩm quý hiếm, có thể tích lũy đổi Long Châu";
}
