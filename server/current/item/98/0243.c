#include <ansi.h>
#include <item.h>

inherit ITEM;
inherit LEGEND_ITEM;

// 函数：构造处理
void create()
{
        set_name( "Bản đồ bí mật下部" );
        set_picid_1(8004);
        set_picid_2(8004);
        set_value(1);
        set_no_give(1);
        set_no_drop(1);
        set_no_sell(1);  
}
// 函数：获取描述
string get_desc() 
{ 
        return "Vật phẩm nhiệm vụ.Bản đồ bí mật下部碎片。"; 
}
