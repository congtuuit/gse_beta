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
        set_name("Túi Chuyển Sinh Cao Cấp lần thứ 10");
        set_picid_1(3107);
        set_picid_2(3107);
		set_level(0);
        set_value(10000);
		        set_no_give(1);		
        set_no_sell(1);
		set_no_drop(1);
}

// 函数：获取描述
string get_desc( object me ) 
{ 
        return "Sau khi sử dụng sẽ nhận được "HIY "Phần Thưởng Chuyển Sinh Cao Cấp 10 lần"NOR ". \n" ;
}

int get_use_effect( object me ) 
{
	return __FILE__->get_use_effect_callout(me,this_object());	
}

int get_use_effect_callout( object who,object gift) 
{
	int gender,family,type,i,k,l,m,y,t;
	object item,item1,item2,item3,item4,item5;
	string cTmp,cFile,p;
	gender = who->get_gender() == 1 ? 1 : 2;
	if ( who->get_level() < 100 )
	{
		        send_user(who,"%c%s",'!',"Cấp 100 có thể sử dụng.");
    		return 0;
	}
	if(who->get_fam_name() == "Đào Hoa Nguyên") family = 1;
	else if(who->get_fam_name() == "Thục Sơn") family = 2;
	else if(who->get_fam_name() == "Cấm Vệ Quân") family = 3;
	else if(who->get_fam_name() == "Đường Môn") family = 4;
	else if(who->get_fam_name() == "Mao Sơn") family = 5;
	else if(who->get_fam_name() == "Côn Luân") family = 6;
	else if(who->get_fam_name() == "Vân Mộng Cốc") family = 7;
	
	who->add_cash(20000000);
	cFile = "item/bikip150/mattichbavuong";
		item = new(cFile);
			i = item->move2(who,-1);
			item->add_to_user(i);
		
		item1 = new(sprintf("item/ngoai_trang/vip%d",gender));
	item1->set_hide(0);	
	k = item1->move2(who,-1);
	item1->add_to_user(k);
	
	item2 = new(sprintf("item/ppvacanh/phiphong/phiphong%d",gender));
	item2->set_hide(0);
	l = item2->move2(who,-1);
		item2->add_to_user(l);
		
		item3 = new(sprintf("item/ppvacanh/canh/canh%d",gender));
	item3->set_hide(0);	
	m = item3->move2(who,-1);
		item3->add_to_user(m);
		
	item4 = new("/item/set10sao/bavuong/tuivukhibavuong");
	y = item4->move2(who,-1);
		item4->add_to_user(y);	
		send_user(who,"%c%s",';',"Bạn nhận được "HIY " Phần Thưởng Chuyển Sinh Cao Cấp lần thứ 10");
	gift->remove_from_user();
	destruct(gift);
}