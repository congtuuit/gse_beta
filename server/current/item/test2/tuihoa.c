#include <ansi.h>
inherit ITEM;
inherit COMBINED;

int get_item_value() { return 50; }
int get_item_value_2() { return 50; }
int get_item_color() { return 2; }

void create()
{
	set_name("Túi Hoa Chúc Phúc (Sơ)");
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

	if (USER_INVENTORY_D->get_free_count(who) < 1)
	{
		notify("Hành trang không đủ 1 chỗ trống");
		return 0;
	}

	rate = random(100);

	if (rate < 8)
	{
		item = new("/item/sell/0032");
		if (!item)
			return 0;
	}
	else if (rate < 15)
	{
		item = new("/item/sell/1032");

		if (!item)
			return 0;
	}
	else if (rate < 25)
	{
		item = new("/item/test2/HatGiong3");

		if (!item)
			return 0;
	}
	else if (rate < 35)
	{
		//cql2
		item = new("item/diemdanh/cql2");
		if (!item)
			return 0;
	}
	else if (rate < 45)
	{
		//DCP
		item = new("item/sell/0031");
		if (!item)
			return 0;
	}
	else if (rate < 60)
	{
		cash = 100000;
		if (!item)
			return 0;
	}
	else if (rate < 70)
	{
		exp = 1000000;
		if (!item)
			return 0;
	}
	else if (rate < 85)
	{
		item = new("item/test2/TuiQuaVoSong");
		if (!item)
			return 0;
	}else if (rate < 95)
	{
		item = new("item/test2/TuiPhapBao");
		if (!item)
			return 0;
	}
	else
	{
		cash = 100000;
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
		USER_D->user_channel(sprintf("Bằng hữu %s mở "HIG"Túi Hoa Chú Phúc "NOR"nhận được "HIY"%s ", who->get_name(), item->get_name()));
	}

	return 0;
}

