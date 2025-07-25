#include <item.h>
#include <ansi.h>
#include <effect.h>
#include <skill.h>
inherit ITEM;
inherit USABLE;
inherit COMBINED;

int get_item_value() {return 150;}
int get_item_value_2() {return 150;}
int get_item_number() {return 30;}
int get_item_color() {return 1 ;}

// 函数：构造处理
void create()
{
        set_name( "Tinh Thần Tẩy Điểm Hoàn" );
        set_picid_1(9167);
        set_picid_2(9167);
        set_value(50);
		set_save("knb",20);
        set_amount(1);
        set_record(1);
}

// 函数：获取描述
string get_desc() 
{ 
        return "Đan dược có thể phục hồi tất cả điểm số Tinh Thần.";
}

// 函数：使用效果
int get_use_effect( object me ) { return __FILE__ ->get_use_effect_callout(me); }

// 函数：使用效果(在线更新)
int get_use_effect_callout( object me )
{
        int point;
	point = me->get_spi_2();             
	if (point==0) 
	{
		send_user(me, "%c%s", '!', "Bạn chưa phân phối điểm Tinh Thần, không thể sử dụng.");
		return 0;      
	}        
	me->set_spi_2(0);
	me->add_gift_point(point);
	write_user(me, ECHO "Bạn thành công tẩy %d điểm Tinh Thần.", point);
	return 1;	                        
} 