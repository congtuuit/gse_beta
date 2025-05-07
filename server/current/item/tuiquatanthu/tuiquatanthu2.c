#include <ansi.h>
#include <equip.h>
#include <effect.h>
inherit ITEM;
inherit USABLE;

int get_item_color() { return 2; }
int get_item_value() { return 100; }
int get_item_value_2() { return 100; }

// 函数：构造处理
void create()
{
	set_name("Túi Qùa Tân Thủ (Nâng Cấp)");
	set_picid_1(4980);
	set_picid_2(4981);
	set_value(1000);

	set_no_give(1);
	set_no_sell(1);
	set_no_drop(1);
}

// 函数：获取描述
string get_desc(object me)
{
	return "[Có thể sử dụng] Túi Qùa Tân Thủ (Nâng Cấp).\n Sau khi sử dụng đạt cấp độ 60 và nhận được vật phẩm hỗ trợ.\n";
}

int get_use_effect(object me)
{
	return __FILE__->get_use_effect_callout(me, this_object());
}

int get_use_effect_callout(object who, object gift)
{
	int gender, family, type, i, k, l, m;
	object item, item1, item2, item3;
	string cTmp, cFile, cFile1, cFile2, cFile3, p;

	gift->remove_from_user();
	destruct(gift);

	who->add_cash(100000);

	if (who->get_level() < 60) {
		who->set_level(60);
		tell_user(who, "Chúc mừng bạn đạt cấp độ 60.");
	}

	//

	item1 = new("/item/set/554/set554");
	item1->set_no_give(1);
	item1->set_no_sell(1);

	m = item1->move(who, -1);
	item1->add_to_user(m);

	send_user(who, "%c%s", ';', "Bạn nhận được "HIR "100.000 lượng");
}