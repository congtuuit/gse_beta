#include <item.h>
#include <ansi.h>
#include <city.h>
inherit ITEM;
//inherit USABLE;   

// 函数：构造处理
void create()
{
        set_name("Giới hạn giấy chứng nhận chéo");
        set_picid_1(9807);
        set_picid_2(9807);
        set_value(50);
        set_no_give(1);
//        set_no_drop(1);
        set_no_sell(1);  	     
	set_no_save(1);		//活动结束，不存盘
}

// 函数：获取描述
string get_desc() 
{
	return "Vật phẩm nhiệm vụ。Hãy chú càng sớm càng tốt với giới hạn về phía đông bắc của phía đông của hòn đảo này thông qua các chức tái xét。";    	
}

//// 函数：使用效果
//int get_use_effect( object me ) 
//{
//	return __FILE__->get_use_effect_callout(me,this_object());	
//}

int get_use_effect_callout( object who,object item) 
{
}