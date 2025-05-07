#include <item.h>
#include <ansi.h>
inherit ITEM;
inherit COMBINED;
inherit USABLE;   

// 函数：可使用物品
int get_item_type_2() { return ITEM_TYPE_2_CON_ALL; }

int get_recover_count() { return 5; }

//圣诞节物品
int is_christmas() { return 1;}

void reset()
{
        if( gone_time( get_drop_time() ) > 7200 )    // 2小时
        {
                remove_from_scene();
                destruct( this_object() );
        }
}
// 函数：构造处理
void create()
{
        set_name("Gà Tây Noel");
        set_picid_1(9982);
        set_picid_2(9982);
        set_unit("只");
        set_value(50);
        set_amount(1);
        set("add_hp", 350);	        
	set("add_mp", 400);	     
}

// 函数：获取描述
string get_desc() 
{
	return "Micro hấp mang đến cho bạn sự ấm áp của gà tây Giáng sinh。\nÔng già Noel món quà được mua lại。\n"HIR"Trong vòng 10 giây hồi phục 350 điểm khí huyết 400 pháp lực。";
}

// 函数：使用效果
int get_use_effect( object me ) { return "/sys/item/food" ->get_use_effect(me, this_object()); }