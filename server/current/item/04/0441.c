#include <item.h>
#include <ansi.h>
#include <city.h>
inherit ITEM;
//inherit USABLE;   

// 函数：构造处理
void create()
{
        set_name("Đá Thử Nghiệm");
        set_picid_1(8901);
        set_picid_2(8901);
        set_value(50);
        set_no_give(1);
//        set_no_drop(1);
        set_no_sell(1);
          	     
	set_no_save(1);		//活动结束，不存盘
}

// 函数：获取描述
string get_desc() 
{
	return "Chất đầy ma vật 100 và đưa chúng cho các hoạt động của May Day để gửi người ta trao đổi phần thưởng.";    	
}

//// 函数：使用效果
//int get_use_effect( object me ) 
//{
//	return __FILE__->get_use_effect_callout(me,this_object());	
//}

int get_use_effect_callout( object who,object item) 
{
}