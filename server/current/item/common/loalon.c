#include <ansi.h>
#include <equip.h>
#include <effect.h>
inherit ITEM;
inherit COMBINED;

int get_max_combined() { return 30; }
int get_item_color() { return 2; }

int get_item_value() { return 100; }
int get_item_value_2() { return 100; }


void create()
{
	set_name("Loa Lớn");
	set_picid_1(0095);
	set_picid_2(0095);
	set_value(10000);
	set_amount(1);

}

int is_usable() { return 1; }

string get_desc(object me)
{
	return sprintf("Loa lớn truyền tin");
}

int get_use_effect(object me)
{
	return __FILE__->get_use_effect_callout(me, this_object());
}

int get_use_effect_callout(object who, object gift)
{
	int gender, family, exp, type;
	object item, item1;
	string cTmp, cFile, p;

	if (who->get_level() < 1)
	{
		send_user(who, "%c%s", '!', "Cấp 1 mới có thể sử dụng.");
		return 0;
	}

	send_user(who, "%c%c%d%s", '?', 16, 50, "Nhập nội dung：\n" ESC"loalon @ %s " + who->get_number() + "\n");

}

