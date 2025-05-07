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
        set_name("Túi Mộc Tinh Thạch");
        set_picid_1(3107);
        set_picid_2(3107);
        set_value(500);
}

// 函数：获取描述
string get_desc( object me ) 
{ 
        return "Sau khi sử dụng sẽ nhận được nguyên bộ Mộc Tinh Thạch.";
}

int get_use_effect( object me ) 
{
	return __FILE__->get_use_effect_callout(me,this_object());	
}

int get_use_effect_callout( object who,object gift) 
{
	int p,gender,fMocily,type;
	object item;
	string cTmp,cFile;
	gender = who->get_gender() == 1 ? 0 : 1;
//	if (who->get_fMoc_nMoce() == "")
//	{
//	send_user(who,"%c%s",'!',"Gia Nhập Phái đi Bạn.");
 //   		return 0;
//	}
	if(USER_INVENTORY_D->get_free_count(who) < 17 )
	{
	        send_user(who,"%c%s",'!',"Hành trang không đủ 17 chỗ.");
    		return 0;
	}

//	if(who->get_fMoc_nMoce() == "Đào Moc Nguyên") fMocily = 1;
//	else if(who->get_fMoc_nMoce() == "Thục Sơn") fMocily = 2;
//	else if(who->get_fMoc_nMoce() == "Cấm Vệ Quân") fMocily = 3;
//	else if(who->get_fMoc_nMoce() == "Đường Môn") fMocily = 4;
//	else if(who->get_fMoc_nMoce() == "Mao Sơn") fMocily = 5;
//	else if(who->get_fMoc_nMoce() == "Côn Luân") fMocily = 6;
//	else if(who->get_fMoc_nMoce() == "Vân Mộng Cốc") fMocily = 7;

	gift->remove_from_user();
	destruct(gift);
//	cTmp = me->get_equip(item_TYPE);
//	item = new(sprintf("item/70/1040"));
//	item->set_hide(0);
//	ITEM_EQUIP_D->init_equip_prop_3(item);
//	p = item->move2(who,-1);
//	item->add_to_user(p);
	item = new(sprintf("item/TuiLinhThach/Moc/1"));	
	item->set_hide(0);	
	p = item->move2(who,-1);
	item->add_to_user(p);
	item = new(sprintf("item/TuiLinhThach/Moc/2"));	
	item->set_hide(0);	
	p = item->move2(who,-1);
	item->add_to_user(p);
	item = new(sprintf("item/TuiLinhThach/Moc/3"));	
	item->set_hide(0);	
	p = item->move2(who,-1);
	item->add_to_user(p);
	item = new(sprintf("item/TuiLinhThach/Moc/4"));	
	item->set_hide(0);	
	p = item->move2(who,-1);
	item->add_to_user(p);
	item = new(sprintf("item/TuiLinhThach/Moc/5"));	
	item->set_hide(0);	
	p = item->move2(who,-1);
	item->add_to_user(p);
	item = new(sprintf("item/TuiLinhThach/Moc/6"));	
	item->set_hide(0);	
	p = item->move2(who,-1);
	item->add_to_user(p);
	item = new(sprintf("item/TuiLinhThach/Moc/7"));	
	item->set_hide(0);	
	p = item->move2(who,-1);
	item->add_to_user(p);
	item = new(sprintf("item/TuiLinhThach/Moc/8"));	
	item->set_hide(0);	
	p = item->move2(who,-1);
	item->add_to_user(p);
	item = new(sprintf("item/TuiLinhThach/Moc/9"));	
	item->set_hide(0);	
	p = item->move2(who,-1);
	item->add_to_user(p);
	item = new(sprintf("item/TuiLinhThach/Moc/10"));	
	item->set_hide(0);	
	p = item->move2(who,-1);
	item->add_to_user(p);
	item = new(sprintf("item/TuiLinhThach/Moc/11"));	
	item->set_hide(0);	
	p = item->move2(who,-1);
	item->add_to_user(p);
	item = new(sprintf("item/TuiLinhThach/Moc/12"));	
	item->set_hide(0);	
	p = item->move2(who,-1);
	item->add_to_user(p);
	item = new(sprintf("item/TuiLinhThach/Moc/13"));	
	item->set_hide(0);	
	p = item->move2(who,-1);
	item->add_to_user(p);
	item = new(sprintf("item/TuiLinhThach/Moc/14"));	
	item->set_hide(0);	
	p = item->move2(who,-1);
	item->add_to_user(p);
	item = new(sprintf("item/TuiLinhThach/Moc/15"));	
	item->set_hide(0);	
	p = item->move2(who,-1);
	item->add_to_user(p);
	item = new(sprintf("item/TuiLinhThach/Moc/16"));	
	item->set_hide(0);	
	p = item->move2(who,-1);
	item->add_to_user(p);
	
	
	return 0;
}