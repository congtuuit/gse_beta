#include <ansi.h>
#include <effect.h>
inherit ITEM;
inherit USABLE;

int get_item_color() { return 2; }

// 函数：构造处理
void create()
{
        set_name( "Túi Hỗ Trợ Chuyển Sinh" );
        set_picid_1(3107);
        set_picid_2(3107);
        set_value(10);
}

// 函数：获取描述
string get_desc() 
{ 
        return "Túi Hỗ Trợ Chuyển Sinh \n Mở ra nhận ngay 5 phiếu Chuyển Sinh.";
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

	item = new("item/test/phieuchuyensinh");
	item->set_amount(5);
	gift->remove_from_user();
	destruct(gift);
	send_user(who,"%c%s",';',"Bạn nhận được "HIR "5 Phiếu Chuyển Sinh");
	p = item->move2(who,-1);
	item->add_to_user(p);
	return 0;
}