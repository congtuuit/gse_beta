#include <ansi.h>
inherit ITEM;
inherit COMBINED;

int get_item_value() { return 50; }
int get_item_value_2() { return 50; }
int get_item_color() { return 2; }

// 函数：构造处理
void create()
{
	set_name("Hoàng Kim Thánh Y Lễ Bao");
	set_picid_1(3107);
	set_picid_2(3107);
	set_value(5);
	set_amount(1);
}

int is_usable() { return 1; }
// 函数：获取描述
string get_desc()
{
	return "Túi thần kỳ nhận được từ nhiệm vụ Hoàng Kim Thánh Y, có thể mở ra rất nhiều loại vật phẩm đáng giá";
}

int get_use_effect(object me)
{
	return __FILE__->get_use_effect_callout(me, this_object());
}

int get_use_effect_callout(object who, object gift)
{
	int rate, p, cash, rate2, knb;
	object item;

	if (USER_INVENTORY_D->get_free_count(who) < 1)
	{
		notify("Hành trang không đủ 1 chỗ trống");
		return 0;
	}

	rate = random(100);

	if (rate < 8)
	{
		item = new("/item/sell/ruongdutru");
		if (!item)
			return 0;
	}
	else if (rate < 16) {
		cash = 150000;
	}
	else if (rate < 24) {
		item = new("/item/test2/TuiPhapBao");
		if (!item)
			return 0;
	}
	else if (rate < 32) {
		//thien ly
		item = new("/item/sell/0012");
		if (!item)
			return 0;
	}
	else if (rate < 40) {
		//huyet thach
		item = new("/item/sell/0002");
		if (!item)
			return 0;
	}
	else if (rate < 48) {
		//phap luc thach
		item = new("/item/sell/0004");
		if (!item)
			return 0;
	}
	else if (rate < 56) {
		//tsd
		item = new("/item/91/9167");
		if (!item)
			return 0;
	}
	else if (rate < 64) {

		//TND

		if (random(100) > 50) {
			item = new("/item/sell/TinhNguyenDon/74216");
		}
		else {
			item = new("/item/sell/TinhNguyenDon/74217");
		}

		if (!item)
			return 0;
	}
	else if (rate < 72) {
		//nhan sam
		item = new("/item/test2/block/0006");
		if (!item)
			return 0;
	}
	else if (rate < 80) {
		//DCP
		item = new("/item/sell/0031");
		if (!item)
			return 0;
	}
	else if (rate < 88) {
		//nhat nguyet
		item = new("/item/mop/9988");
		if (!item)
			return 0;
	}
	else if (rate < 96) {
		//so cap
		item = new("item/sell/0032");
		if (!item)
			return 0;
	}
	else {
		cash = 100000;
	}
	

	gift->add_amount(-1);

	if (cash > 0) {
		who->add_cash(cash);
		USER_D->user_channel(sprintf("Bằng hữu %s mở Hoàng Kim Thánh Y Lễ Bao nhận được %d lượng", who->get_name(), cash));
		return 0;
	}

	if (item)
	{
		send_user(who, "%c%s", '!', "Bạn nhận được " + item->get_name());
		p = item->move2(who);
		item->add_to_user(p);
		USER_D->user_channel(sprintf("Bằng hữu %s mở Hoàng Kim Thánh Y Lễ Bao nhận được %s ", who->get_name(), item->get_name()));
	}
	return 0;
}

