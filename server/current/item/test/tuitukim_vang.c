#include <ansi.h>
#include <effect.h>
#include <equip.h>

inherit ITEM;
inherit USABLE;

int get_item_color() { return 2; }
int get_item_value() { return 100; }
int get_item_value_2() { return 100; }

// 函数：构造处理
void create()
{
	set_name("Túi Tử Kim cấp 55 (Full)");
	set_picid_1(7126);
	set_picid_2(7126);
	set_value(300);
	set_save("qsvst", 1000);
}

string get_desc()
{
	return "Sử dụng nhận được một bộ Trang bị Tử Kim cấp 55 có thể tái tạo.";
}

int get_use_effect(object me)
{
	return __FILE__->get_use_effect_callout(me, this_object());
}

int get_use_effect_callout(object who, object gift)
{
	int p, level;
	object item;
	string* nTmp, cFile;
	level = 60;

	if (who->get_fam_name() == "")
	{
		send_user(who, "%c%s", '!', "Gia Nhập Phái đi Bạn.");
		return 0;
	}
	if (USER_INVENTORY_D->get_free_count(who) < 5)
	{
		notify("Hành trang không đủ 5 chỗ trống");
		return 0;
	}

	gift->remove_from_user();
	destruct(gift);

	/*nTmp = WEAPON_FILE->get_family_equip(who->get_fam_name(), who->get_gender(), level, WEAPON_TYPE);
	cFile = nTmp[random(sizeof(nTmp))];
	if (load_object(cFile))
	{
		item = new(cFile);
		ITEM_EQUIP_D->init_equip_prop_3(item);
		p = item->move2(who, -1);

		item->set("gold_time", time() + 15 * 24 * 3600);
		item->set("goldAP+", 300);
		item->set("goldCP+", 300);
		item->set("goldDP+", 100);
		item->set("goldPP+", 100);

		item->add_to_user(p);
	}*/

	item = new(sprintf("item/%d/%d055", 55, who->get_fam_type()));
	item->set_hide(0);
	item->set_item_color(2);
	p = item->move2(who, -1);
	item->add_to_user(p);

	item = new(sprintf("item/%d/%d055", 56, who->get_fam_type()));
	item->set_hide(0);
	item->set_item_color(2);
	p = item->move2(who, -1);
	item->add_to_user(p);

	item = new(sprintf("item/%d/%d055", 57, who->get_fam_type()));
	item->set_hide(0);
	item->set_item_color(2);
	p = item->move2(who, -1);
	item->add_to_user(p);

	item = new(sprintf("item/%d/%d055", 58, who->get_fam_type()));
	item->set_hide(0);
	item->set_item_color(2);
	p = item->move2(who, -1);
	item->add_to_user(p);

	item = new(sprintf("item/%d/%d055", 59, who->get_fam_type()));
	item->set_hide(0);
	item->set_item_color(2);
	p = item->move2(who, -1);
	item->add_to_user(p);

	return 0;
}