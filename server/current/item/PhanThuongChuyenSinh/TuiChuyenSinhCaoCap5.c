#include <ansi.h>
#include <effect.h>
inherit ITEM;
inherit USABLE;

int get_item_color() { return 2; }

// 函数：构造处理
void create()
{
        set_name( "Túi Chuyển Sinh Cao Cấp lần thứ 5" );
        set_picid_1(3107);
        set_picid_2(3107);
        set_value(10000000);
		set_no_give(1);		
        set_no_sell(1);
		set_no_drop(1);
		
}

// 函数：获取描述
string get_desc() 
{ 
        return "Sau khi sử dụng sẽ nhận được "HIY "Phần Thưởng Chuyển Sinh Cao Cấp 5 lần"NOR " \nVật phẩm nhận được sẽ Khoá.";
}

int get_use_effect( object me ) 
{
	return __FILE__->get_use_effect_callout(me,this_object());	
}

int get_use_effect_callout( object who,object gift) 
{
	int p;
	object item;

	if(USER_INVENTORY_D->get_free_count(who) < 3 )
	{
	        send_user(who,"%c%s",'!',"Hành trang không đủ chỗ.");
    		return 0;
	}

	item = new("item/set10sao/truyenthuyet/set10sao");
	gift->remove_from_user();
	destruct(gift);
	send_user(who,"%c%s",';',"Bạn nhận được "HIR " Túi Hoàng Kim Truyền Thuyết");
	p = item->move2(who,-1);
	item->add_to_user(p);
	return 0;
}