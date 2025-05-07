#include <ansi.h>
#include <equip.h>
#include <effect.h>
inherit ITEM;
inherit USABLE;

int get_item_color() { return 2; }
int get_item_value() {return 100 ;}
int get_item_value_2() {return 100 ;}

// 函数：构造处理
void create()
{
        set_name("Kĩ Năng Điêu Khắc");
        set_picid_1(9808);
        set_picid_2(9808);
		set_level(10);
        set_value(500);
		set_no_give(0);		
        set_no_sell(1);
		set_no_drop(0);
}

// 函数：获取描述
string get_desc( object me ) 
{ 
        return "Kĩ năng Điêu Khắc \nSau khi sử dụng kĩ năng Điêu Khắc sẽ max";
}

int get_use_effect( object me ) 
{
	return __FILE__->get_use_effect_callout(me,this_object());	
}

int get_use_effect_callout( object who,object gift) 
{
	int p,gender,family,type;
	object item;
	string cTmp,cFile;
	gender = who->get_gender() == 1 ? 0 : 1;


	gift->remove_from_user();
	destruct(gift);
	
	who->set_skill(0650, 150);
	send_user(who,"%c%s",';',"Kĩ năng "HIR "Điêu Khắc "NOR "đã max");
	return 0;
}