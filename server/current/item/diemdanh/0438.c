#include <item.h>
#include <ansi.h>
inherit ITEM;
inherit COMBINED;

// 函数：物品叠加上限
int get_max_combined() { return 30; }
int get_item_color() { return 1; }
// 函数：构造处理
void create()
{
        set_name("Huân Chương Điểm Danh");
        set_picid_1(3859);
        set_picid_2(3859);
        set_value(50);
        set_amount(1);
        set_no_sell(1);
        set_no_give(1);
        

}

// 函数：获取描述
string get_desc() 
{
	return "Vật phẩm dùng để đổi thưởng。";    	
}