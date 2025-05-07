#include <ansi.h>
#include <effect.h>
inherit ITEM;
inherit USABLE;

int get_item_color() { return 2; }
int get_item_value() { return 150; }
int get_item_value_2() { return 150; }

// 函数：构造处理
void create()
{
        set_name( "Túi Dây Bắt Thỏ (x25)" );
        set_picid_1(3107);
        set_picid_2(3107);
		set_save("tppc",10);
        set_value(2000);
}

// 函数：获取描述
string get_desc() 
{ 
        return "Sử dụng nhận được 25 Dây Bắt Thỏ.";
}

int get_use_effect( object me ) 
{
	return __FILE__->get_use_effect_callout(me,this_object());	
}

int get_use_effect_callout( object who,object gift) 
{
	int p;
	object item;

	if(USER_INVENTORY_D->get_free_count(who) < 1 )
	{
	        send_user(who,"%c%s",'!',"Hành trang không đủ chỗ trống.");
    		return 0;
	}

	item = new("item/event/trungthu/daybattho");
	item->set_amount(25);
	gift->remove_from_user();
	destruct(gift);
	send_user(who,"%c%s",';',"Bạn nhận được "HIY "25 Dây Bắt Thỏ");
	p = item->move2(who,-1);
	item->add_to_user(p);
	return 0;
}