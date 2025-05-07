#include <ansi.h>
inherit ITEM;
inherit USABLE;
inherit COMBINED;

int get_item_value() { return 35; }
int get_item_value_2() { return 35; }
int get_item_color() { return 2; }

// 函数：构造处理
void create()
{
	set_name("Túi Quà 500 Vô Song");
	set_picid_1(9995);
	set_picid_2(9995);
	set_value(3);
	//	set_save("knb",30);
	set_amount(1);

}
//int is_usable() {return 1;}
// 函数：获取描述
string get_desc()
{
	return "Túi quà do Vô Song Thành sản xuất\nNghe nói Quân Sư Vô Song Thành biết cách sử dụng";
}

int get_use_effect(object me)
{
	return __FILE__->get_use_effect_callout(me, this_object());
}

int get_use_effect_callout(object who, object gift)
{
	int rate, p, cash, sl1, sl2, sl3, sl4, sl5, sl6, rate2;
	object item, item1, item2, item3, item4, item5, item6;

	if (USER_INVENTORY_D->get_free_count(who) < 1)
	{
		notify("Hành trang không đủ 1 chỗ trống");
		return 0;
	}

	sl1 = 500;

	gift->add_amount(-1);
	if (sl1)
	{
		if (objectp(item1 = present("Vô Song Điểm Phiếu", who, 1, MAX_CARRY * 4)) && item1->get_amount() < 10000)
		{
			item1->add_amount(sl1);
			USER_D->user_channel(sprintf("Bằng hữu "HIR "%s" NOR " mở Túi Quà Vô Song nhận được "HIR "%s "NOR " . ", who->get_name(), item1->get_name()));
		}
		else
		{
			item1 = new("item/test/vosongdiemphieu");
			item1->set_amount(sl1);
			p = item1->move2(who, -1);
			item1->add_to_user(p);
			USER_D->user_channel(sprintf("Bằng hữu "HIR "%s" NOR " mở Túi Quà Vô Song nhận được "HIR "%s "NOR " . ", who->get_name(), item1->get_name()));
		}
	}

	return 0;
}

