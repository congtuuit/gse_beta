#include <ansi.h>
#include <equip.h>
#include <effect.h>
inherit ITEM;
inherit USABLE;

int get_item_color() { return 3; }
int get_item_value() {return 100 ;}
int get_item_value_2() {return 100 ;}

// 函数：构造处理
void create()
{
        set_name("Túi Thủy Tinh Thạch");
        set_picid_1(3107);
        set_picid_2(3107);
        set_value(500);
}

// 函数：获取描述
string get_desc( object me ) 
{ 
        return "Sau khi sử dụng sẽ nhận được nguyên bộ Thủy Tinh Thạch.";
}

int get_use_effect( object me ) 
{
	return __FILE__->get_use_effect_callout(me,this_object());	
}

int get_use_effect_callout( object who,object gift) 
{
	int p,gender,fThuyily,type;
	object item;
	string cTmp,cFile;
	gender = who->get_gender() == 1 ? 0 : 1;
//	if (who->get_fThuy_nThuye() == "")
//	{
//	send_user(who,"%c%s",'!',"Gia Nhập Phái đi Bạn.");
 //   		return 0;
//	}
	if(USER_INVENTORY_D->get_free_count(who) < 17 )
	{
	        send_user(who,"%c%s",'!',"Hành trang không đủ 17 chỗ.");
    		return 0;
	}

//	if(who->get_fThuy_nThuye() == "Đào Thuy Nguyên") fThuyily = 1;
//	else if(who->get_fThuy_nThuye() == "Thục Sơn") fThuyily = 2;
//	else if(who->get_fThuy_nThuye() == "Cấm Vệ Quân") fThuyily = 3;
//	else if(who->get_fThuy_nThuye() == "Đường Môn") fThuyily = 4;
//	else if(who->get_fThuy_nThuye() == "Mao Sơn") fThuyily = 5;
//	else if(who->get_fThuy_nThuye() == "Côn Luân") fThuyily = 6;
//	else if(who->get_fThuy_nThuye() == "Vân Mộng Cốc") fThuyily = 7;

	gift->remove_from_user();
	destruct(gift);
//	cTmp = me->get_equip(item_TYPE);
//	item = new(sprintf("item/70/1040"));
//	item->set_hide(0);
//	ITEM_EQUIP_D->init_equip_prop_3(item);
//	p = item->move2(who,-1);
//	item->add_to_user(p);
	item = new(sprintf("item/TuiLinhThach/Thuy/1"));	
	item->set_hide(0);	
	p = item->move2(who,-1);
	item->add_to_user(p);
	item = new(sprintf("item/TuiLinhThach/Thuy/2"));	
	item->set_hide(0);	
	p = item->move2(who,-1);
	item->add_to_user(p);
	item = new(sprintf("item/TuiLinhThach/Thuy/3"));	
	item->set_hide(0);	
	p = item->move2(who,-1);
	item->add_to_user(p);
	item = new(sprintf("item/TuiLinhThach/Thuy/4"));	
	item->set_hide(0);	
	p = item->move2(who,-1);
	item->add_to_user(p);
	item = new(sprintf("item/TuiLinhThach/Thuy/5"));	
	item->set_hide(0);	
	p = item->move2(who,-1);
	item->add_to_user(p);
	item = new(sprintf("item/TuiLinhThach/Thuy/6"));	
	item->set_hide(0);	
	p = item->move2(who,-1);
	item->add_to_user(p);
	item = new(sprintf("item/TuiLinhThach/Thuy/7"));	
	item->set_hide(0);	
	p = item->move2(who,-1);
	item->add_to_user(p);
	item = new(sprintf("item/TuiLinhThach/Thuy/8"));	
	item->set_hide(0);	
	p = item->move2(who,-1);
	item->add_to_user(p);
	item = new(sprintf("item/TuiLinhThach/Thuy/9"));	
	item->set_hide(0);	
	p = item->move2(who,-1);
	item->add_to_user(p);
	item = new(sprintf("item/TuiLinhThach/Thuy/10"));	
	item->set_hide(0);	
	p = item->move2(who,-1);
	item->add_to_user(p);
	item = new(sprintf("item/TuiLinhThach/Thuy/11"));	
	item->set_hide(0);	
	p = item->move2(who,-1);
	item->add_to_user(p);
	item = new(sprintf("item/TuiLinhThach/Thuy/12"));	
	item->set_hide(0);	
	p = item->move2(who,-1);
	item->add_to_user(p);
	item = new(sprintf("item/TuiLinhThach/Thuy/13"));	
	item->set_hide(0);	
	p = item->move2(who,-1);
	item->add_to_user(p);
	item = new(sprintf("item/TuiLinhThach/Thuy/14"));	
	item->set_hide(0);	
	p = item->move2(who,-1);
	item->add_to_user(p);
	item = new(sprintf("item/TuiLinhThach/Thuy/15"));	
	item->set_hide(0);	
	p = item->move2(who,-1);
	item->add_to_user(p);
	item = new(sprintf("item/TuiLinhThach/Thuy/16"));	
	item->set_hide(0);	
	p = item->move2(who,-1);
	item->add_to_user(p);
	
	
	return 0;
}