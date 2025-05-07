#include <item.h>
#include <ansi.h>
inherit ITEM;
inherit USABLE;   

int get_item_value() {return 350 ;}
int get_item_value_2() {return 280 ;}
int get_item_number() {return 23 ;}
int get_item_color() {return 1 ;}

int get_fin_type() { return 1650; }


// 函数：构造处理
void create()
{
        set_name( "百宝囊" );
        set_picid_1(7113);
        set_picid_2(7113);
        set_value(2000);
        set("bag", 12);
        set_record(1);
}

// 函数：获取描述
string get_desc() 
{ 
        return "Gia tăng 12 ô hành trang, sau 30 ngày tự động hỏng。"; 
}

// 函数：使用效果
int get_use_effect( object me ) { return "/cmd/std/bag" ->get_use_effect(me, this_object()); }
