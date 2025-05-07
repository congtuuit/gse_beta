
// 自动生成：/make/item/make49
#include <item.h>
inherit ITEM;
inherit COMBINED;

int get_item_value() { return 15; }
int get_item_value_2() { return 15; }
int get_max_combined() { return 30; }
int get_item_color() { return 2; }

int get_item_type_2() { return ITEM_TYPE_2_USABLE2; }

void create()
{
	set_name("Bùa Hàng Ma");
	set_picid_1(3851);
	set_picid_2(3851);
	set_value(33333);
	set_amount(1);
}

string get_desc()
{
	return "Vật phẩm sự kiện, dùng để thu phục Cương Thi";
}

int get_use_effect(object me, object who) { return __FILE__->get_use_effect_callout(me, who); }

int get_use_effect_callout(object me, object who)
{
	int damage;
	object user, owner, * char;
	int z, x, y, i;
	"/skill/00/00051"->main(me, who, 0, 0, "");
	return 0;
}