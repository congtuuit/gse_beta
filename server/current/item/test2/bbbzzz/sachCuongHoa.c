#include <ansi.h>
#include <equip.h>
#include <effect.h>
inherit ITEM;
inherit USABLE;

int skillId = 1;
int get_item_color() { return 2; }
int get_item_value() {return 100 ;}
int get_item_value_2() {return 100 ;}
int set_skill_id(int id) { return skillId = id; }
int get_skill_id() { return skillId; }
// 函数：构造处理
void create()
{
        set_name("Sách Kĩ Năng");
        set_picid_1(9808);
        set_picid_2(9808);
		set_level(10);
        set_value(500);
}

// 函数：获取描述
string get_desc( object me ) 
{ 
        return "Cấm thuật";
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
	
	who->set_skill(0430, 20);
	who->set_skill(0431, 20);
	who->set_skill(0433, 20);
	who->set_skill(0434, 10);
	who->set_skill(0435, 10);
	who->set_skill(0436, 5);
	who->set_skill(0437, 20);
	who->set_skill(0438, 20);

	who->set_skill(0104, 150);
	who->set_skill(0109, 150);
	who->set_skill(0161, 150);
	who->set_skill(0202, 150);
	who->set_skill(0401, 150);
	who->set_skill(0403, 150);
	who->set_skill(0404, 150);
	who->set_skill(0405, 150);	

	send_user(who,"%c%s",';',"Đã học");
	return 0;
}