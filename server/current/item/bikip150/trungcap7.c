#include <ansi.h>
#include <equip.h>
#include <effect.h>
inherit ITEM;
inherit USABLE;

int get_item_color() { return 2; }
int get_item_value() {return 100 ;}
int get_item_value_2() {return 100 ;}

// 函数：构造处理
void create()
{
        set_name("Túi Mật Tịch Trung Cấp 150 phái Vân Mộng Cốc");
        set_picid_1(3107);
        set_picid_2(3107);
        set_value(500);
}

// 函数：获取描述
string get_desc( object me ) 
{ 
        return "Sau khi sử dụng sẽ nhận được bí kíp "HIY " Trung Cấp "NOR " cấp 150 phái Vân Mộng Cốc \n "HIY "++ Uỷ Mị Kiếm Pháp ++  \n ";
}

int get_use_effect( object me ) 
{
	return __FILE__->get_use_effect_callout(me,this_object());	
}

int get_use_effect_callout( object who,object gift) 
{
	int p,gender,family,type;
	object item;
	string cTmp,cFile;
	gender = who->get_gender() == 1 ? 0 : 1;
	if (who->get_fam_name() == "")
	{
	send_user(who,"%c%s",'!',"Gia Nhập Phái đi Bạn.");
    		return 0;
	}
	if(USER_INVENTORY_D->get_free_count(who) < 3 )
	{
	        send_user(who,"%c%s",'!',"Hành trang không đủ 3 chỗ.");
    		return 0;
	}

	if(who->get_fam_name() == "Đào Hoa Nguyên") family = 1;
	else if(who->get_fam_name() == "Thục Sơn") family = 2;
	else if(who->get_fam_name() == "Cấm Vệ Quân") family = 3;
	else if(who->get_fam_name() == "Đường Môn") family = 4;
	else if(who->get_fam_name() == "Mao Sơn") family = 5;
	else if(who->get_fam_name() == "Vân Mộng Cốc") family = 6;
	else if(who->get_fam_name() == "Vân Mộng Cốc") family = 7;

	gift->remove_from_user();
	destruct(gift);
//	cTmp = me->get_equip(item_TYPE);
//	item = new(sprintf("item/70/1040"));
//	item->set_hide(0);
//	ITEM_EQUIP_D->init_equip_prop_3(item);
//	p = item->move2(who,-1);
//	item->add_to_user(p);
//	item = new(sprintf("item/skill/04257"));	
//	item->set_hide(0);	
//	p = item->move2(who,-1);
//	item->add_to_user(p);
//	item = new(sprintf("item/skill/04258"));
//	item->set_hide(0);	
//	p = item->move2(who,-1);
//	item->add_to_user(p);
	item = new(sprintf("item/skill/05917"));
	item->set_hide(0);	
	p = item->move2(who,-1);
	item->add_to_user(p);
//	item = new(sprintf("item/skill/04225"));
//	item->set_hide(0);	
//	p = item->move2(who,-1);
//	item->add_to_user(p);
//	item = new(sprintf("item/skill/04259"));
//	item->set_hide(0);	
//	p = item->move2(who,-1);
//	item->add_to_user(p);	
	
	return 0;
}