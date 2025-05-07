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
        set_name( "Túi Thú Cưỡi Nâng Cấp" );
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
	int p, rate;
	object item;

	gift->remove_from_user();
	destruct(gift);

	rate = random(6);

	switch (rate)
	{
	case 0:
		item = new("/item/ride/thanthu2/000");
		break;
	case 1:
		item = new("/item/ride/thanthu2/001");
		break;
	case 2:
		item = new("/item/ride/thanthu2/002");
		break;
	case 3:
		item = new("/item/ride/thanthu2/003");
		break;
	case 4:
		item = new("/item/ride/thanthu2/004");
		break;
	case 5:
		item = new("/item/ride/thanthu2/005");
		break;
	case 6:
		item = new("/item/ride/thanthu2/006");
		break;
	default:
		item = new("/item/ride/thanthu2/006");
		break;
	}

	p = item->move(who,-1);
	item->add_to_user(p);

	return 0;
}