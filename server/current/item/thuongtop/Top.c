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
        set_name("Túi Qùa Top Xếp Hạng");
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

	//vsdp
	item2 = new ("/item/test/vosongdiemphieu");
	item2->set_amount(100);
	i = item2->move(who, -1);
	item2->add_to_user(i);

	result = HIY + sprintf("Chúc mừng %s ( %d ) sử dụng "HIR"Túi Qùa Top Xếp Hạng"HIY" nhận được"HIG" x100 Vô Song Điểm Phiếu"HIY".", who->get_name(), who->get_number());
	CHAT_D->sys_channel(0, result);

	return 1;
}