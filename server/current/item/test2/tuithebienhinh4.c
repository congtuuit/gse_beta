#include <ansi.h>
#include <effect.h>
inherit ITEM;
inherit USABLE;

int get_item_value() {return 10 ;}
int get_item_value_2() {return 10 ;}
int get_item_color() { return 2; }

// 函数：构造处理
void create()
{
        set_name( "Túi Thẻ Biến Hình 3" );
        set_picid_1(3107);
        set_picid_2(3107);
        set_value(500);
}

// 函数：获取描述
string get_desc() 
{ 
        return "Sử dụng .";
}

int get_use_effect( object me ) 
{
	return __FILE__->get_use_effect_callout(me,this_object());	
}

int get_use_effect_callout( object who,object gift) 
{
	int p;
	object item;

	if(USER_INVENTORY_D->get_free_count(who) < 2 )
	{
	        send_user(who,"%c%s",'!',"Hành trang không đủ chỗ.");
    		return 0;
	}

	item = new("item/test2/thebienhinh4");
	item->set_amount(500);
	gift->remove_from_user();
	destruct(gift);
	send_user(who,"%c%s",';',"Bạn nhận được "HIY "500 Thẻ Biến Hình 4");
	p = item->move2(who,-1);
	item->add_to_user(p);
	return 0;
}