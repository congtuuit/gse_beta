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
        set_name("Gói quà");
        set_picid_1(4980);
        set_picid_2(4981);
        set_value(1000);

		set_no_give(1);		
        set_no_sell(1);
		set_no_drop(1);
}

// 函数：获取描述
string get_desc( object me ) 
{ 
        return "[Có thể sử dụng] Phần thưởng từ Server Test.\n" ;
}

int get_use_effect( object me ) 
{
	return __FILE__->get_use_effect_callout(me,this_object());	
}

int get_use_effect_callout( object who,object gift) 
{
	int gender,family,type,i,k,l,m;
	object item,item1,item2,item3;
	string cTmp,cFile,cFile1,cFile2,cFile3,p;

	gift->remove_from_user();
	destruct(gift);

	if (USER_INVENTORY_D->get_free_count(who) < 3)
	{
		notify("Hành trang không đủ 3 chỗ trống");
		return 0;
	}

	who->add_cash(500000);

	item = new("/item/ThuongTest/cql");
	if (item) {
		item->set_amount(10);
		p = item->move2(who, -1);
		item->add_to_user(p);
	}
	
	item1 = new("/item/ThuongTest/tui50knb");
	if (item1) {
		item1->set_no_give(1);
		item1->set_no_sell(1);
		p = item1->move2(who, -1);
		item1->add_to_user(p);
	}

	send_user(who,"%c%s",';',"Bạn nhận được "HIR "Túi Kim Bảo, 500.000 lượng và Chiến Quốc Lệnh x10");
}