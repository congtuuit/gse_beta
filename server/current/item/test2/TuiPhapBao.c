#include <ansi.h>
inherit ITEM;
inherit COMBINED;

int get_item_value() { return 50; }
int get_item_value_2() { return 50; }
int get_item_color() { return 2; }

// 函数：构造处理
void create()
{
	set_name("Túi Pháp Bảo");
	set_picid_1(3107);
	set_picid_2(3107);
	set_value(5);
	set_amount(1);
}

int is_usable() { return 1; }
// 函数：获取描述
string get_desc()
{
	return "Túi thần kỳ, có thể mở ra rất nhiều loại Pháp Bảo và vật phẩm đáng giá";
}

int get_use_effect(object me)
{
	return __FILE__->get_use_effect_callout(me, this_object());
}

int get_use_effect_callout(object who, object gift)
{
	int rate, p, cash, rate2;
	object item;

	if (USER_INVENTORY_D->get_free_count(who) < 1)
	{
		notify("Hành trang không đủ 1 chỗ trống");
		return 0;
	}

	rate = random(100);

	if (rate < 2)	//Bao de phu
	{
		//item = new("item/sell/0034");
		item = new("/item/spitem/ve/ve5sao");
		if (!item)
			return 0;
	}
	else if (rate < 10)	//thanthu
	{
		item = new(sprintf("item/ThanThuNew/%d", 0 + random(5)));
		if (!item)
			return 0;
	}

	else if (rate < 27)	//Cao Cấp đoạn thạch
	{
		rate2 = random(100);

		if (rate2 > 65) {
			item = new("item/sell/1032");
		}
		else {
			item = new(sprintf("item/sell/%d032", 0 + random(2)));
		}

		if (!item)
			return 0;
	}

	else if (rate < 40)		//Phap Bao
	{
		//item = new(sprintf("item/mop/95%d2",1+random(5)));

		rate2 = random(100);

		if (rate2 < 17) {
			item = new("item/mop/9512");
		}
		else if (rate2 < 30) {
			item = new("item/mop/9522");
		}
		else if (rate2 < 50) {
			item = new("item/mop/9532");
		}
		else if (rate2 < 70) {
			item = new("item/mop/9562");
		}
		else if (rate2 < 90) {
			item = new("item/mop/9542");
		}
		else
			item = new("item/mop/9552");

		if (!item)
			return 0;
	}
	else if (rate < 50)	//法力石
	{
		rate2 = random(100);

		if (rate2 < 50) {
			item = new("item/30/3034");
		}
		else {
			item = new("item/30/3036");
		}

		if (!item)
			return 0;
	}

	else if (rate < 60)	//法力石
	{
		item = new(sprintf("item/08/085%d", 0 + random(4)));

		if (!item)
			return 0;
	}

	else if (rate < 70)	//法力石
	{
		item = new(sprintf("item/30/302%d", 3 + random(4)));

		if (!item)
			return 0;
	}
	else if (rate < 80)	//Vu khi
	{
		item = new(sprintf("item/%d/1075", 70 + random(6)));
		if (!item)
			return 0;
	}
	else if (rate < 90)	//trang phuc mua he
	{
		rate2 = random(100);

		if (rate2 >= 50) {
			item = new(sprintf("item/100/11051"));
		}
		else {
			item = new(sprintf("item/100/10051"));
		}

		if (!item)
			return 0;
	}
	else
	{
		item = new("item/08/0017");
		if (!item)
			return 0;
	}

	gift->add_amount(-1);

	if (item)
	{
		send_user(who, "%c%s", '!', "Bạn nhận được " + item->get_name());
		p = item->move2(who);
		item->add_to_user(p);
		USER_D->user_channel(sprintf("Bằng hữu %s mở Túi Pháp Bảo nhận được %s ", who->get_name(), item->get_name()));
	}
	return 0;
}

