#include <ansi.h>
#include <item.h>

inherit ITEM;
inherit COMBINED;
inherit LEGEND_ITEM;


// 函数：构造处理
void create()
{
        set_name( "Tượng bùn" );
        set_picid_1(4904);
        set_picid_2(4904);
        set_value(1);
        set_no_give(1);
        set_no_drop(1);
        set_no_sell(1);  
        set_amount(1);
}
// 函数：获取描述
string get_desc() 
{ 
        return "Vật phẩm nhiệm vụ.古董商需要的一种用泥做成的雕塑。"; 
}