#include <ansi.h>
#include <effect.h>
inherit ITEM;
inherit USABLE;

int get_item_color() { return 2; }
int get_item_value() {return 150 ;}
int get_item_value_2() {return 150 ;}

// 函数：构造处理
void create()
{
        set_name( "Túi Qùa Tân Thủ" );
        set_picid_1(4981);
        set_picid_2(4981);
        set_value(50);

		set_no_give(1);
		set_no_sell(1);
		set_no_drop(1);
}

// 函数：获取描述
string get_desc() 
{ 
        return "Túi Qùa Tân Thủ.\n Sau khi sử dụng nhận được vật phẩm hỗ trợ.\n" ;
}

int get_use_effect( object me ) 
{
	return __FILE__->get_use_effect_callout(me,this_object());	
}

int get_use_effect_callout( object who,object gift) 
{
	int i,k,l,m,d,p;
	object item;

	gift->remove_from_user();
	destruct(gift);

	who->add_cash(30000);
	who->set_level(10);
	//notify( "Thăng cấp!" );
	tell_user( who, "Chúc mừng bạn đạt cấp độ 10.");	

	item = new(sprintf("/item/sell/0002"));
	item->set_amount(5);
	d = item->move(who,-1);
	item->add_to_user(d);

	item = new(sprintf("/item/sell/0004"));
	item->set_amount(5);
	p = item->move(who,-1);
	item->add_to_user(p);

	item = new(sprintf("/item/sell/0008"));
	item->set_amount(50);
	i = item->move(who,-1);
	item->add_to_user(i);

	item = new(sprintf("/item/sell/0010"));
	item->set_amount(50);
	k = item->move(who,-1);
	item->add_to_user(k);
		
	item = new(sprintf("/item/mop/9562"));
	l = item->move(who,-1);
	item->add_to_user(l);
		
	item = new(sprintf("/item/mop/9522")); 
	m = item->move(who,-1);
	item->add_to_user(m);

	send_user(who,"%c%s",';',"Bạn nhận được "HIR "50 Trị Dược + Phục Dược và 30.000 lượng");

	return 0;
}