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
        set_name("Túi Qùa Tân Thủ");
        set_picid_1(4980);
        set_picid_2(4981);
		set_level(10);
        set_value(10000);
		        set_no_give(1);		
        set_no_sell(1);
		set_no_drop(1);
}

// 函数：获取描述
string get_desc( object me ) 
{ 
        return "Túi Qùa Tân Thủ.\n Sau khi sử dụng nhận được : \n " HIC"Tân Thủ Kĩ Năng + 1 \n " HIC"Ngân Lượng + 1 triệu  \n"HIC" Trị Dược (10.000 bình)\n"HIC" Phục Dược (10.000 bình)\n" ;
}

int get_use_effect( object me ) 
{
	return __FILE__->get_use_effect_callout(me,this_object());	
}

int get_use_effect_callout( object who,object gift) 
{
	int gender,family,type,i,k,l,m;
	object item,item1,item2,item3;
	string cTmp,cFile,p;
	gender = who->get_gender() == 1 ? 1 : 2;
	if ( who->get_level() < 10 )
	{
		        send_user(who,"%c%s",'!',"Cấp 10 có thể sử dụng.");
    		return 0;
	}
	TASK_LEGEND_D->check_task_item1(who,"Túi Qùa Tân Thủ",1);
	TASK_LEGEND_D->check_task_item2(who,"Túi Qùa Tân Thủ",1);
	TASK_LEGEND_D->check_task_item3(who,"Túi Qùa Tân Thủ",1);

	who->add_cash(1000000);
//	who->set_level(10);
	cFile = "item/tuiquatanthuhieu/TanThuKiNang";
		item = new(cFile);
			i = item->move2(who,-1);
			item->add_to_user(i);
		
		item1 = new(sprintf("item/ngoai_trang/ngoaitrang%d",gender));
	k = item1->move2(who,-1);
	item1->add_to_user(k);
	
	item2 = new("item/sell/0008");
			item2->set_amount(10000);
	l = item2->move2(who,-1);
		item2->add_to_user(l);
		
		item3 = new("item/sell/0010");
			item3->set_amount(10000);
	m = item3->move2(who,-1);
		item3->add_to_user(m);
		send_user(who,"%c%s",';',"Bạn nhận được "HIR "10000 Trị Dược + Phục Dược. 1 triệu ngân lượng");

}