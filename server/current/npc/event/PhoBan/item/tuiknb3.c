#include <ansi.h>

inherit ITEM;
inherit USABLE;
#define YUANBAO "sys/sys/test_db"

int get_item_color() { return 2; }
int get_item_value() {return 100 ;}
int get_item_value_2() {return 100 ;}

// 函数：构造处理
void create()
{
        set_name("Túi Kim Bảo");
        set_picid_1(4980);
        set_picid_2(4981);
        set_value(500);
}

// 函数：获取描述
string get_desc( object me ) 
{ 
        return "Túi Kim Bảo.\n Sau khi sử dụng nhận 1-3 KNB\n" ;
}

int get_use_effect( object me ) 
{
	return __FILE__->get_use_effect_callout(me,this_object());	
}

int get_use_effect_callout( object who,object gift) 
{
	int number, rate;

	rate = random(100);
	number = random(3);
	if (number < 1) {
		number = 1;
	}

	if (rate < 10) {
		number = 2;
	}

	YUANBAO->add_yuanbao(who, (10) * number);

	gift->remove_from_user();
	destruct(gift);

	send_user(who,"%c%s",';', sprintf("Bạn nhận được "HIR "%d KNB", number));
}