#include <ansi.h>
#include <effect.h>
inherit ITEM;
inherit USABLE;

int get_item_color() { return 2; }
int get_item_value() {return 100 ;}
int get_item_value_2() {return 100 ;}

// 函数：构造处理
void create()
{
        set_name( "Túi Thú Cưỡi" );
        set_picid_1(4981);
        set_picid_2(4981);
        set_value(50);
}

// 函数：获取描述
string get_desc() 
{ 
        return "Sau khi sử dụng có thể nhận được một thú cưỡi quí hiếm";
}

int get_use_effect( object me ) 
{
	return __FILE__->get_use_effect_callout(me,this_object());	
}

int get_use_effect_callout( object who,object gift) 
{
	int p;
	object item;

	gift->remove_from_user();
	destruct(gift);
	item = new(sprintf("/item/ride/TuiThanThu/%d",001+ random(11)));
	p = item->move(who,-1);
	item->add_to_user(p);
	return 0;
}