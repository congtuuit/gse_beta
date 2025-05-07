#include <ansi.h>
#include <effect.h>
inherit ITEM;
inherit USABLE;

int get_item_color() { return 2; }

// 函数：构造处理
void create()
{
        set_name( "Túi Chuyển Sinh lần thứ 7" );
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
        return "Sau khi sử dụng sẽ nhận được "HIY "Phần Thưởng Chuyển Sinh 7 lần"NOR " \nVật phẩm nhận được sẽ Khoá.";
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

/*	item = new(sprintf("item/bikip150/mattichtrungcap150"));
	item->set_hide(0);	
	p = item->move2(who,-1);
	item->add_to_user(p);*/
	item = new(sprintf("/item/set10sao/tanlang/tuivukhitanlang"));
	item->set_hide(0);	
	p = item->move2(who,-1);
	item->add_to_user(p);
	item = new("item/bikip150/mattichchuyensinh200/tuimattichchuyensinh200");
	gift->remove_from_user();
	destruct(gift);
	send_user(who,"%c%s",';',"Bạn nhận được "HIR "Túi Mật Tịch Đặc Biệt Môn Phái");
	p = item->move2(who,-1);
	item->add_to_user(p);
	return 0;
}