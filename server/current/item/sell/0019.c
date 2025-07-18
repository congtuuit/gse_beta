#include <item.h>
#include <ansi.h>
#include <effect.h>
#include <skill.h>
inherit ITEM;
inherit USABLE;
inherit COMBINED;

int get_item_value() { return 150; }
int get_item_value_2() { return 150; }
int get_item_number() { return 30; }
int get_item_color() {return 1 ;}

// 函数：构造处理
void create()
{
        set_name( "Mẫn Tiệp Tẩy Điểm Hoàn" );
        set_picid_1(9176);
        set_picid_2(9176);
        set_value(50);
        set_amount(1);
        set_record(1);
}

// 函数：获取描述
string get_desc() 
{ 
        return "Đan dược có thể phục hồi tất cả điểm số Mẫn Tiệp.";
}

// 函数：使用效果
int get_use_effect( object me ) { return __FILE__ ->get_use_effect_callout(me); }

// 函数：使用效果(在线更新)
int get_use_effect_callout( object me )
{
        int point;
	point = me->get_dex_2();       
	if (point==0) 
	{
		send_user(me, "%c%s", '!', "Có thể sử dụng để tẩy thuộc tính。");

		return 0;      
	}               
	me->set_dex_2(0);
	me->add_gift_point(point);
	write_user(me, ECHO "Tẩy điểm thành công nhận được %d điểm。", point);

	return 1;	                        
} 