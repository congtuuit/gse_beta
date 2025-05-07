#include <ansi.h>
#include <equip.h>
#include <effect.h>
inherit ITEM;
inherit USABLE;

#define YUANBAO "sys/sys/test_db"
int get_item_color() { return 2; }
int get_item_value() {return 100 ;}
int get_item_value_2() {return 100 ;}

// 函数：构造处理
void create()
{
        set_name("Túi Qùa Từ Admin");
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
        return "[Có thể sử dụng] Tùi quà tặng nhận từ mã CODE.\n" ;
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

	if (USER_INVENTORY_D->count_empty_carry(who) < 4)
	{
		send_user(who, "%c%s", '!', "Hành trang của bạn không đủ chỗ");
		return 0;
	}

	gift->remove_from_user();
	destruct(gift);

	//who->add_exp(3889);
	YUANBAO->add_yuanbao(who, 50 * 10);

	item3 = new("/item/test2/block/TuiQuaVoSong"); 
	item3->set_amount(5);
	m = item3->move(who,-1);
	item3->add_to_user(m);
	
	item1 = new("/item/test2/block/TuiPhapBao");
	item1->set_amount(5);
	k = item1->move(who,-1);
	item1->add_to_user(k);

	item1 = new("/item/common/daotanthu");
	k = item1->move(who, -1);
	item1->add_to_user(k);

}