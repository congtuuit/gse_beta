#include <ansi.h>
inherit ITEM;
inherit COMBINED;

int get_item_value() { return 2000; }
int get_item_value_2() { return 2000; }
int get_item_color() { return 2; }

void create()
{
	set_name("Hợp Đồng Trang Bị (7 ngày)");
	set_picid_1(9808);
	set_picid_2(9808);
	set_value(500);
	set_amount(1);
	//set_save_2("diemnhiemvu.score", 20);

	//set_no_sell(1);
	//set_no_give(1);

}

int is_usable() { return 1; }

string get_desc()
{
	return "Loại thẻ mở khóa tính năng đặt biệt, cho phép người chơi sử dụng trang bị vượt quá 10 cấp. Thời gian hiệu lực 7 ngày.";
}

int get_use_effect(object me)
{
	return __FILE__->get_use_effect_callout(me, this_object());
}

int get_use_effect_callout(object who, object gift)
{
	send_user(who, "%c%s", ';', sprintf("Bạn bây giờ có thể sử dụng trang bị vượt hơn 10 cấp độ. Thời gian hiệu lực 7 ngày."));
	who->set_save_2("thetrangbi.time", time() + 7 * 24 * 3600);
	gift->add_amount(-1);
	return 0;
}