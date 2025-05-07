#include <ansi.h>
#include <item.h>
#include <effect.h>
#include <skill.h>
inherit ITEM;
inherit COMBINED;

int get_item_value() { return 30; }
int get_item_value_2() { return 30; }
int get_item_color() { return 2; }

void create()
{
	set_name("Pháo Hoa");
	set_picid_1(9984);
	set_picid_2(9984);
	set_value(1);
	set_amount(1);
	set_no_give(1);
	set_no_sell(1);

}
int is_usable() { return 1; }
string get_desc()
{
	return "Một cây Pháo dùng để Chúc Mừng Năm Mới";
}

int get_use_effect(object me)
{
	return __FILE__->get_use_effect_callout(me, this_object());
}

int get_use_effect_callout(object who, object gift)
{
	int rate, p, cash, exp, knb, tien;
	object item;

	rate = random(100);

	if (rate < 4)
	{
		knb = 200;
	}
	else if (rate < 14)
	{
		knb = 150;
	}
	else if (rate < 24)
	{
		knb = 100;
	}
	else if (rate < 34)
	{
		knb = 50;
	}
	else if (rate < 44)
	{
		exp = 500000;
	}
	else if (rate < 54)
	{
		exp = 400000;
	}
	else if (rate < 64)
	{
		tien = 500000;
	}
	else if (rate < 74)
	{
		tien = 400000;
	}
	else if (rate < 84)
	{
		tien = 300000;
	}
	else if (rate < 94)
	{
		tien = 250000;
	}
	else
	{
		tien = 100000;
	}
	gift->add_amount(-1);
	//Tim
	//send_user(get_scene_object_2(who, USER_TYPE), "%c%d%w%c%c%c", 0x6f, getoid(who), 5915, 3, OVER_BODY, PF_ONCE);

	//phao do
	//send_user(get_scene_object_2(who, USER_TYPE), "%c%d%w%c%c%c", 0x6f, getoid(who), 5914, 3, OVER_BODY, PF_ONCE);

	//No
	//send_user(get_scene_object_2(who, USER_TYPE), "%c%d%w%c%c%c", 0x6f, getoid(who), 5916, 3, OVER_BODY, PF_ONCE);

	if (knb)
	{
		"sys/sys/test_db"->add_yuanbao(who, knb);
		send_user(who, "%c%s", ';', sprintf("Bạn nhận được "HIY"%d Kim Nguyên Bảo "NOR ".", knb / 10));
		//phao do
		send_user(get_scene_object_2(who, USER_TYPE), "%c%d%w%c%c%c", 0x6f, getoid(who), 5917, 3, OVER_BODY, PF_ONCE);
		send_user(get_scene_object_2(who, USER_TYPE), "%c%d%w%c%c%c", 0x6f, getoid(who), 5914, 3, OVER_BODY, PF_ONCE);
		//No
		send_user(get_scene_object_2(who, USER_TYPE), "%c%d%w%c%c%c", 0x6f, getoid(who), 5916, 3, OVER_BODY, PF_ONCE);
	}
	else if (exp)
	{
		who->add_exp(exp);
		send_user(who, "%c%s", ';', sprintf("Bạn nhận được "HIY"%d Kinh nghiệm "NOR ".", exp));
		send_user(get_scene_object_2(who, USER_TYPE), "%c%d%w%c%c%c", 0x6f, getoid(who), 5917, 3, OVER_BODY, PF_ONCE);
	}
	else if (tien)
	{
		who->add_cash(tien);
		send_user(who, "%c%s", ';', sprintf("Bạn nhận được "HIY"%d ngân lượng "NOR ".", tien));
		send_user(get_scene_object_2(who, USER_TYPE), "%c%d%w%c%c%c", 0x6f, getoid(who), 5914, 3, OVER_BODY, PF_ONCE);
	}
	return 0;
}

