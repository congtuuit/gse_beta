#include <ansi.h>
inherit ITEM;
int get_item_value() {return 100 ;} //giá KNB - như thế này là giá 10 KNB
int get_item_value_2() {return 100 ;} //giá KNB khi sử dụng gói VIP
// 函数：构造处理
void create()
{
        set_name("Túi Qùa Vô Song");
        set_picid_1(4981);
        set_picid_2(4981);
        set_value(1);
        
}
int is_usable() {return 1;}
// 函数：获取描述
string get_desc() 
{ 
        return ""; 
}

int get_use_effect( object me ) 
{
	return __FILE__->get_use_effect_callout(me,this_object());	
}

int get_use_effect_callout( object who,object gift) 
{
	int rate,p,cash;
	object item;
	
	rate = random(100);
	
	if ( rate < 12 )		//战国令
	{
		item = new("item/test/vosongdiemphieu");
		item->set_amount(8);
		if ( !item )
			return 0;
	}
	else if ( rate < 24 )	//战国号角
	{
		item = new("item/test/vosongdiemphieu");
		item->set_amount(10);
		if ( !item )
			return 0;
	else if ( rate < 24 )	//战国号角
	{
		item = new("item/test/vosongdiemphieu");
		item->set_amount(12);
		if ( !item )
			return 0;
	else if ( rate < 24 )	//战国号角
	{
		item = new("item/test/vosongdiemphieu");
		item->set_amount(14);
		if ( !item )
			return 0;
	else if ( rate < 24 )	//战国号角
	{
		item = new("item/test/vosongdiemphieu");
		item->set_amount(16);
		if ( !item )
			return 0;
	}
	else if ( rate < 44 )	//血石
	{
		item = new("item/test/vosongdiemphieu");
		item->set_amount(18);
		if ( !item )
			return 0;
	}
	else if ( rate < 64 )	//法力石
	{
		item = new("item/test/vosongdiemphieu");
		item->set_amount(20);
		if ( !item )
			return 0;

	{
		item = new("item/test/vosongdiemphieu");
		item->set_amount(700);
		if ( !item )
			return 0;
	}
	else 			//乾坤袋
	{
		item = new("item/test/vosongdiemphieu");
		item->set_amount(350);
		if ( !item )
			return 0;
	}
	gift->remove_from_user();
	destruct(gift);
	if ( item )
	{
		send_user(who,"%c%s",'!',"Bạn nhận được "+item->get_name());
		p = item->move2(who);
		item->add_to_user(p);	
	}
	else if (  cash )
	{
		who->add_cash(cash);
		send_user(who,"%c%s",'!',sprintf("Bạn nhận được %d Vô Song Điểm Phiếu",cash));
	}
	return 0;
}

