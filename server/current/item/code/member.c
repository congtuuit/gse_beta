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
        set_name("Túi Qùa Member");
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
        return "[Có thể sử dụng] Túi Qùa Tân Thủ.\n Sau khi sử dụng nhận được vật phẩm hỗ trợ.\n" ;
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

	if (USER_INVENTORY_D->get_free_count(who) < 7)
	{
		notify("Hành trang không đủ 7 chỗ trống");
		return 0;
	}

	if (sizeof_inventory(who, 7, MAX_CARRY) >= MAX_CARRY)
	{
		send_user(who, "%c%s", '!', "Hành trang trên người ngươi không đủ 7 chỗ, lần sau nhận thưởng phải chú ý");
		return;
	}

	who->add_exp(9999999);

	if (who->get_level() < 20) {
		who->set_level(20);
	}


	gift->remove_from_user();
	destruct(gift);


	if (who->get_gender() == 1) {
		item3 = new("/item/trangphuc/ngoaitrang/sp1");
		m = item3->move(who, -1);
		item3->add_to_user(m);
	}
	else {
		item3 = new("/item/trangphuc/ngoaitrang/sp2");
		m = item3->move(who, -1);
		item3->add_to_user(m);
	}

	item2 = new("/item/common/canhcomeback");
	l = item2->move(who, -1);
	item2->add_to_user(l);

	item1 = new("/item/common/tinhthach");
	i = item1->move(who, -1);
	item1->add_to_user(i);

	item1 = new("/item/common/tinhthach");
	i = item1->move(who, -1);
	item1->add_to_user(i);

	item1 = new("/item/common/tinhthach");
	i = item1->move(who, -1);
	item1->add_to_user(i);

	item = new("/item/common/box/tukim/1");
	item->set_amount(50);
	k = item->move(who, -1);
	item->add_to_user(k);

	item = new("/item/common/tui500vsdp");
	item->set_amount(3);
	k = item->move(who, -1);
	item->add_to_user(k);

}