#include <ansi.h>
#include <equip.h>
#include <effect.h>
inherit ITEM;
inherit USABLE;

int get_item_color() { return 2; }
int get_item_value() { return 100; }
int get_item_value_2() { return 100; }

void create()
{
	set_name("Hỗ Trợ Tân Thủ");
	set_picid_1(4981);
	set_picid_2(4981);
	set_value(1000);

	set_no_give(1);
	set_no_sell(1);
	set_no_drop(1);
}

string get_desc(object me)
{
	return "[Có thể sử dụng] Có thể sử dụng sau mỗi 10 cấp.\n";
}

int get_use_effect(object me)
{
	return __FILE__->get_use_effect_callout(me, this_object());
}

int get_use_effect_callout(object who, object gift)
{
	int gender, family, type, i, k, l, m, level;
	object item, item1, item2, item3;
	string cTmp, cFile, cFile1, cFile2, cFile3, p;

	level = who->get_level() / 10;

	if (level < 1) {
		notify("Bạn không đủ điều kiện để sử dụng!");
		return 0;
	}

	if (who->get_save("hotro_tanthu") >= level) {
		notify("Bạn đã nhận phần thưởng rồi!");
		return 0;
	}

	if (USER_INVENTORY_D->get_free_count(who) < 3)
	{
		send_user(who, "%c%s", '!', "Hành trang không đủ 3 chỗ trống.");
		return 0;
	}

	switch (level)
	{
	case 1:
		item = new ("/item/mop/9562");
		item->set_no_give(1);
		item->set_no_sell(1);

		item1 = new ("/item/mop/9522");
		item1->set_no_give(1);
		item1->set_no_sell(1);

		break;
	case 2:
		item = new ("/item/test/tuihoangkimtanthucap20");
		item->set_no_give(1);
		item->set_no_sell(1);

		item1 = new ("/item/30/3027");
		item1->set_no_give(1);
		item1->set_no_sell(1);

		break;
	case 3:
		item = new ("/item/test/tuihoangkimtanthucap30");
		item->set_no_give(1);
		item->set_no_sell(1);

		item1 = new ("/item/diemdanh/cql2");
		item1->set_no_give(1);
		item1->set_no_sell(1);

		break;
	case 4:
		item = new ("/item/test/tuihoangkimtanthucap40");
		item->set_no_give(1);
		item->set_no_sell(1);

		item1 = new ("/item/diemdanh/cql2");
		item1->set_no_give(1);
		item1->set_no_sell(1);
		break;
	case 5:
		item = new("/item/set/554/set554");
		item->set_no_give(1);
		item->set_no_sell(1);

		item1 = new ("/item/diemdanh/cql2");
		item1->set_amount(2);
		item1->set_no_give(1);
		item1->set_no_sell(1);

		break;
	case 6:
		item = new ("/item/test/tuihoangkimtanthucap602");
		item->set_no_give(1);
		item->set_no_sell(1);

		item1 = new ("/item/diemdanh/cql2");
		item1->set_no_give(1);
		item1->set_no_sell(1);
		item1->set_amount(4);

		break;
	case 7:
		item = new ("/item/diemdanh/lenhbaithap");
		item->set_no_give(1);
		item->set_no_sell(1);
		item->set_amount(5);

		item1 = new ("/item/diemdanh/cql2");
		item1->set_no_give(1);
		item1->set_no_sell(1);
		item1->set_amount(4);
		break;
	}

	if (item && item1) {
		if (who->get_level() >= 70) {
			gift->remove_from_user();
			destruct(gift);
			who->delete_save("hotro_tanthu");
		}
		else {
			item3 = new("/item/spitem/tanthuvip");
			k = item3->move(who, -1);
			item3->add_to_user(k);
		}

		p = item->move(who, -1);
		m = item1->move(who, -1);

		item->add_to_user(p);
		item1->add_to_user(m);

		who->set_save("hotro_tanthu", level);

		send_user(who, "%c%s", ';', sprintf("Bạn nhận được %s, %s", item->get_name(), item1->get_name()));
		return 1;
	}
	
	return 0;

}