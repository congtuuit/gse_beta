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
        set_picid_2(4980);
        set_value(500);
}

// 函数：获取描述
string get_desc( object me ) 
{ 
        return "Túi Kim Bảo.\n Sau khi sử dụng nhận ngẫu nhiên 10 - 30 KNB\n" ;
}

int get_use_effect( object me ) 
{
	return __FILE__->get_use_effect_callout(me,this_object());	
}

int get_use_effect_callout( object who,object gift) 
{
	int number;
	int rate;

	number = random(30);
	if (number < 10) {
		number = 10;
	}

	rate = random(100);
	if(rate > 50){
		if (number == 30) {
			number = 19;
		}
		else {
			if (number > 22) {
				number = number - random(4);
			}
		}
	}

	if (number < 10) {
		number = 10;
	}

	YUANBAO->add_yuanbao(who, (10) * number);

	gift->remove_from_user();
	destruct(gift);

	send_user(who,"%c%s",';', sprintf("Bạn nhận được "HIR "%d KNB", number));
}