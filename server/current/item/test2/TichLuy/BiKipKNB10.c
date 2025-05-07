#include <ansi.h>
#include <equip.h>
#include <effect.h>
#include <skill.h>
inherit ITEM;
inherit COMBINED;
inherit USABLE;

int get_max_combined() { return 10000; }
int get_item_color() { return 2; }
int get_item_value() {return 510 ;}
int get_item_value_2() {return 510 ;}

// 函数：构造处理
void create()
{
        set_name("Bí kíp Kim Nguyên Bảo");
        set_picid_1(0089);
        set_picid_2(0089);
		set_level(1);
        set_value(10000);
		set_amount(1);		

}

// 函数：获取描述
string get_desc( object me ) 
{ 	
		return "Sử dụng nhận được 50 Kim Nguyên Bảo \n-----------Dùng cho giao dịch----------" ;
}

int get_use_effect( object me ) 
{
	return __FILE__->get_use_effect_callout(me,this_object());	
}

int get_use_effect_callout( object who,object gift) 
{
	int gender,family,exp,type;
	object item,item1;
	string cTmp,cFile,p;
		if ( who->get_level() < 1 )
		{
		send_user(who,"%c%s",'!',"Cấp 1 mới có thể sử dụng.");
		    		return 0;

		}		

					"sys/sys/test_db"->add_yuanbao(who,500);
					send_user(who,"%c%s",';',"Bạn nhận được "HIY "50 "NOR "Kim Nguyên Bảo");
		gift->add_amount(-1);			

}