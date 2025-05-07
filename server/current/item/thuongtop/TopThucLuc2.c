#include <ansi.h>
#include <equip.h>
#include <item.h>
#include <effect.h>
#include <city.h>
#include <public.h>
#include <task.h>
#include <npc.h>
inherit ITEM;
inherit USABLE;

int get_item_color() { return 2; }
int get_item_value() {return 100 ;}
int get_item_value_2() {return 100 ;}

// 函数：构造处理
void create()
{
        set_name("Túi Qùa Top Thực Lực (2)");
        set_picid_1(4980);
        set_picid_2(4981);
        set_value(1000);

}

// 函数：获取描述
string get_desc( object me ) 
{ 
        return "[Có thể sử dụng] Túi quà TOP xếp hạng.\n" ;
}

int get_use_effect( object me ) 
{
	return __FILE__->get_use_effect_callout(me,this_object());	
}

int get_use_effect_callout(object who, object gift)
{
	int gender, family, type, i, k, l, m, n;
	object item, item1, item2, item3, item4;
	string cTmp, cFile, cFile1, cFile2, cFile3, p, result;

	if (USER_INVENTORY_D->get_free_count(who) < 6)
	{
		notify("Hành trang không đủ 6 chỗ trống");
		return 0;
	}

	gift->remove_from_user();
	destruct(gift);

	//1 trung cap
	item = new("/item/sell/1032");
	l = item->move(who, -1);
	item->add_to_user(l);

	//1 so cap
	item1 = new("/item/sell/0032");
	m = item1->move(who, -1);
	item1->add_to_user(m);

	//vsdp
	item2 = new ("/item/test/vosongdiemphieu");
	item2->set_amount(100);
	i = item2->move(who, -1);
	item2->add_to_user(i);

	//tuilinhthach2
	item3 = new("/item/TuiLinhThach/NgauNhien/2");
	k = item3->move(who, -1);
	item3->add_to_user(k);

	result = HIY + sprintf("Chúc mừng %s ( %d ) sử dụng "HIR"Túi Qùa Top Thực Lực (2)"HIY" nhận được "HIG"x1 Trung Cấp Đoạn Thạch"HIY", "HIG" x1 Sơ Cấp Đoạn Thạch"HIY", "HIG" x100 Vô Song Điểm Phiếu"HIY", "HIG" 1x Túi Linh Thạch (2)"HIY".", who->get_name(), who->get_number());
	CHAT_D->sys_channel(0, result);

	return 1;
}