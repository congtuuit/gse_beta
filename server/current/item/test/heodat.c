#include <ansi.h>
#include <effect.h>
inherit ITEM;
inherit USABLE;

int get_item_color() { return 3; }

// 函数：构造处理
void create()
{
        set_name( "Túi quà Lì Xì màu Tím" );
        set_picid_1(3107);
        set_picid_2(3107);
        set_value(500000);
}

// 函数：获取描述
string get_desc() 
{ 
        return "Túi quà Lì Xì chúc Tết đầu năm Mới \n Mở ra sẽ nhận được 5 triệu Việt Nam Đồng.";
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
	        send_user(who,"%c%s",'!',"Hành trang không đủ chỗ.");
    		return 0;
	}

	item = new("item/test/tienvietnamdong");
	item->set_amount(5000);
	gift->remove_from_user();
	destruct(gift);
	send_user(who,"%c%s",';',"Bạn nhận được "HIR "5 triệu Việt Nam Đồng");
	p = item->move2(who,-1);
	item->add_to_user(p);
	return 0;
}