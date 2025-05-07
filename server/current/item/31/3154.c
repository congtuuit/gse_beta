
// 自动生成：/make/item/make31c
#include <item.h>
#include <ansi.h>
inherit ITEM;
    inherit COMBINED;
inherit USABLE;   

// 函数：叠加上限
//  int get_max_combined() { return 30; }

// 函数：可使用物品
int get_item_type_2() { return ITEM_TYPE_2_CON_MP; }

// 函数：构造处理
void create()
{
        set_name("Đầm Lầy");
        set_picid_1(3154);
        set_picid_2(3154);
        set_unit("坛");
        set_value(1500);
        set_amount(1);
	set("level", 90);
	set("add_mp", 1600);	
}

// 函数：获取描述
string get_desc() 
{
	string desc;
	desc = "Rượu vang cổ, có nguồn gốc ở Heng Pháp Chuen, các cầu thủ để khôi phục 1600 mana 20 giây。";
	if (this_player()->get_level()<this_object()->get("level"))
        	return sprintf(HIR+desc+"\n"HIR"yêu cầu %d cấp", get("level") ); 
	else
		return sprintf(desc+"\nyêu cầu %d cấp", get("level") ); 
}

// 函数：使用效果
int get_use_effect( object me ) { return "/sys/item/food" ->get_use_effect(me, this_object()); }