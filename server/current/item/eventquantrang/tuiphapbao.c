#include <ansi.h>
#include <effect.h>
inherit ITEM;
inherit USABLE;

int get_item_color() { return 2; }
int get_item_value() {return 50 ;}
int get_item_value_2() {return 50 ;}

// 函数：构造处理
void create()
{
        set_name( "Túi Pháp Bảo" );
        set_picid_1(3107);
        set_picid_2(3107);
        set_value(5);
}

// 函数：获取描述
string get_desc() 
{ 
        return "Túi thần kỳ, có thể mở ra rất nhiều loại Pháp Bảo và vật phẩm đáng giá.";
}

int get_use_effect( object me ) 
{
	return __FILE__->get_use_effect_callout(me,this_object());	
}

int get_use_effect_callout( object who, object gift ) 
{
	int p,rate;
	object item;
	string *nTalisman = ({"9512","9522","9532","9542","9552","9562"});

	rate = random(100);

	if ( rate < 35 )
	{
		item = new(sprintf("/item/mop/%s",nTalisman[random(6)]));
	}
	else if ( rate < 40 )
	{
		item = new("/item/08/0850");
	}
	else if ( rate < 50 )
	{
		item = new("/item/08/0851");
	}
	else if ( rate < 60 )
	{
		item = new("/item/08/0853");
	}
	else if ( rate < 70 )
	{
		item = new("/item/08/0854");
	}
	else if ( rate < 80 )
	{
		item = new("/item/30/3024");
	}
	else if ( rate < 85 )
	{
		item = new("/item/30/3024f");
	}
	else if ( rate < 90 )
	{
		item = new("/item/30/3027");
	}
	else if ( rate < 95 )
	{
		item = new("/item/30/3034");
	}
	else if ( rate < 100 )
	{
		item = new("/item/30/3036");
	}

	gift->remove_from_user();
	destruct(gift);
	p = item->move(who,-1);
	item->add_to_user(p);
	CHAT_D->sys_channel( 0, sprintf(who->get_name()+" sử dụng Túi Pháp Bảo nhận được "+item->get_name()+"."));
	return 0;
}