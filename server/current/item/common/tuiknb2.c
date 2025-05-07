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
        set_picid_1(4981);
        set_picid_2(4981);
        set_value(500);
}

// 函数：获取描述
string get_desc( object me ) 
{ 
        return "Túi Kim Bảo.\n Sau khi sử dụng nhận ngẫu nhiên 1 - 7 KNB, tỉ lệ tùy theo cấp độ\n" ;
}

int get_use_effect( object me ) 
{
	return __FILE__->get_use_effect_callout(me,this_object());	
}

int get_use_effect_callout( object who,object gift) 
{
	int number, rate;
	int rate2;
	int level;

	level = who->get_level();
	if (level > 89) {
		level = 70;
		number = random(level);
		rate = random(100);

		if (rate > 10) {
			if (number > 50) {
				number = 30;
			}
		}

		if (number > 50) {
			number = (random(5) + 1) * 10;
		}

		if (rate < 5) {
			number = 70;
		}

	}
	else {
		number = 20;
	}

	if (number < 20) {
		number = 20;
	}
	

	YUANBAO->add_yuanbao(who, number);

	gift->remove_from_user();
	destruct(gift);

	send_user(who,"%c%s",';', sprintf("Bạn nhận được "HIR "%d KNB", number / 10));
}