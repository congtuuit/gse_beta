#include <ansi.h>
inherit ITEM;
inherit COMBINED;

int get_item_value() { return 50; }
int get_item_value_2() { return 50; }
int get_item_color() { return 2; }

void create()
{
	set_name("Túi Hoa Chúc Phúc (Cao)");
	set_picid_1(3107);
	set_picid_2(3107);
	set_value(5);
	set_amount(1);
}

int is_usable() { return 1; }

string get_desc()
{
	return "Mở túi nhận có cơ hội nhận được nhiều vật phẩm đáng giá";
}

int get_use_effect(object me)
{
	return __FILE__->get_use_effect_callout(me, this_object());
}

int get_use_effect_callout(object who, object gift)
{
	int rate, p, cash, rate2, exp;
	object item;

	if (USER_INVENTORY_D->get_free_count(who) < 5)
	{
		notify("Hành trang không đủ 5 chỗ trống");
		return 0;
	}

	rate = random(100);

	if (rate < 6)
	{
		item = new("/item/sell/0034");
		if (!item)
			return 0;
	}
	else if (rate < 14)
	{
		item = new("/item/sell/1032");

		if (!item)
			return 0;
	}
	else if (rate < 25)
	{
		item = new("/item/sell/0032");

		if (!item)
			return 0;
	}
	else if (rate < 37)
	{
		item = new("/item/test2/HatGiong3");
		item->set_amount(2);
		if (!item)
			return 0;
	}
	else if (rate < 53)
	{
		item = new("item/diemdanh/cql2");
		item->set_amount(3);
		item->set_no_sell(0);
		item->set_no_give(0);

		if (!item)
			return 0;
	}
	else if (rate < 69)
	{
		cash = 500000;
		if (!item)
			return 0;
	}
	else if (rate < 85)
	{
		exp = 5000000;
		if (!item)
			return 0;
	}
	else 
	{
		item = new("item/test2/TuiPhapBao");
		item->set_amount(5);
		if (!item)
			return 0;
	}

	gift->add_amount(-1);

	if (cash > 0) {
		send_user(who, "%c%s", '!', "Bạn nhận được " + cash + " lượng");
		who->add_cash(cash);
	}

	if (exp > 0) {
		send_user(who, "%c%s", '!', "Bạn nhận được " + exp + " kinh nghiệm");
		who->add_exp(exp);
	}

	if (item)
	{
		send_user(who, "%c%s", '!', "Bạn nhận được " + item->get_name());
		p = item->move2(who);
		item->add_to_user(p);
		USER_D->user_channel(sprintf("Bằng hữu %s mở "HIG"Túi Hoa Chú Phúc (Cao) "NOR"nhận được "HIY"%s ", who->get_name(), item->get_name()));
	}

	return 0;
}

