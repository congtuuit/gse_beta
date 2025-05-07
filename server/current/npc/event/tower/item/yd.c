#include <ansi.h>
#include <equip.h>
#include <effect.h>
#include <time.h>

inherit ITEM;
inherit USABLE;

int get_item_color() { return 2; }
int get_item_value() { return 100; }
int get_item_value_2() { return 100; }

// 函数：构造处理
void create()
{
	set_name("Túi Huyết Long (Yêu Đới)");
	set_picid_1(3104);
	set_picid_2(3104);
	set_level(105);
	set_value(10000);
}

string get_desc(object me)
{
	return "Túi Huyết Long, sau khi sử dụng nhận được trang bị Huyết Long theo môn phái";
}

int get_use_effect(object me)
{
	return __FILE__->get_use_effect_callout(me, this_object());
}

int get_use_effect_callout(object who, object gift)
{
	int gender, family, type, i, k, l, m;
	object item, item1, item2, item3;
	string cTmp, cFile, p;
	gender = who->get_gender() == 1 ? 1 : 2;

	if (who->get_fam_name() == "")
	{
		send_user(who, "%c%s", '!', "Gia Nhập Phái đi Bạn.");
		return 0;
	}

	if (who->get_level() < 105)
	{
		if (who->get_save_2("thetrangbi.time") - time() < 0 || (105 - who->get_level() > 10)) {
			send_user(who, "%c%s", '!', "Cấp 105 mới có thể sử dụng.");
			return 0;
		}
	}

	if (USER_INVENTORY_D->get_free_count(who) < 1)
	{
		notify("Hành trang không đủ 1 chỗ trống");
		return 0;
	}

	gift->remove_from_user();
	destruct(gift);
	//gift->add_amount(-1);

	switch (who->get_fam_type())
	{
	case 1:
		item = new (sprintf("item/trangbi110/dhn/3"));
		break;
	case 2:
		item = new (sprintf("item/trangbi110/ts/3"));
		break;
	case 3:
		item = new (sprintf("item/trangbi110/cvq/3"));
		break;
	case 4:
		item = new (sprintf("item/trangbi110/dm/3"));
		break;
	case 5:
		item = new (sprintf("item/trangbi110/ms/3"));
		break;
	case 6:
		item = new (sprintf("item/trangbi110/cl/3"));
		break;
	case 7:
		item = new (sprintf("item/trangbi110/vmc/3"));
		break;
	}

	k = item->move2(who, -1);
	item->add_to_user(k);

	send_user(who, "%c%s", ';', sprintf("Bạn nhận được "HIY"%s", item->get_name()));

	return 1;
}