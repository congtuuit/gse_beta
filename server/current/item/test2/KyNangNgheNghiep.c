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
        set_name("Kĩ Năng Nghề Nghiệp");
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
        return "Kĩ năng Nghề Nghiệp \nSau khi sử dụng tất cả kĩ năng Nghề Nghiệp sẽ max";
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
	
	who->set_skill(0610, 150);
	who->set_skill(0620, 150);
	who->set_skill(0630, 150);
	who->set_skill(0640, 150);
	who->set_skill(0650, 150);
	who->set_skill(0660, 150);
/*	who->set_skill(0437, 20);
//	who->set_skill(0438, 20);
	who->set_skill(0104, 150);
	who->set_skill(0109, 150);
	who->set_skill(0161, 150);
	who->set_skill(0202, 150);
	who->set_skill(0401, 150);
	who->set_skill(0403, 150);
	who->set_skill(0404, 150);
	who->set_skill(0405, 150);	*/
	send_user(who,"%c%s",';',"Tất cả kĩ năng "HIR " Nghề Nghiệp "NOR "đã max");
	return 0;
}