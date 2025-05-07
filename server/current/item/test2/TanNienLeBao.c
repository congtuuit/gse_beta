#include <ansi.h>
inherit ITEM;
inherit COMBINED;

int get_item_value() { return 50; }
int get_item_value_2() { return 50; }
int get_item_color() { return 2; }

// 函数：构造处理
void create()
{
	set_name("Đại Lễ Bao");
	set_picid_1(4981);
	set_picid_2(4981);
	set_value(50);
	//set_save("knb",50);
	set_amount(1);

}
int is_usable() { return 1; }
// 函数：获取描述
string get_desc()
{
	return "Lễ bao chúc phúc, có thể mở ra rất nhiều bảo vật quý hiếm. ";
}

int get_use_effect(object me)
{
	return __FILE__->get_use_effect_callout(me, this_object());
}

int get_use_effect_callout(object who, object gift)
{
	int rate, p, cash;
	object item;

	if (USER_INVENTORY_D->get_free_count(who) < 1)
	{
		notify("Hành trang không đủ 1 chỗ trống");
		return 0;
	}
	rate = random(100);

	if (rate < 20)
	{
		item = new("item/final/15/1525");
		if (!item)
			return 0;
	}
	else if (rate < 30)
	{
		item = new("item/final/15/1528");
		if (!item)
			return 0;
	}
	else if (rate < 40)
	{
		item = new("item/final/15/1527");
		if (!item)
			return 0;
	}
	else if (rate < 50)
	{
		item = new("item/final/15/1529");
		if (!item)
			return 0;
	}
	else if (rate < 60)
	{
		item = new("item/final/15/1524");
		if (!item)
			return 0;
	}
	else if (rate < 70)
	{
		item = new("item/final/15/1526");
		if (!item)
			return 0;
	}
	else if (rate < 80)
	{
		item = new("item/test/tuihoangkimtanthucap60");
		if (!item)
			return 0;
	}
	else 
	{
		item = new("item/test/tuihoangkimtanthucap100");
		if (!item)
			return 0;
	}

	gift->add_amount(-1);
	if (item)
	{
		send_user(who, "%c%s", '!', "Bạn nhận được " + item->get_name());
		p = item->move2(who);
		item->add_to_user(p);
		USER_D->user_channel(sprintf("Bằng hữu "HIR "%s "NOR "mở Đại Lễ Bao nhận được "HIY "%s "NOR ".", who->get_name(), item->get_name()));
	}
	return 0;
}

