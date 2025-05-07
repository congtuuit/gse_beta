
// 自动生成：/make/item/make49
#include <item.h>
inherit ITEM;
inherit COMBINED;

int get_item_value() { return 15; }
int get_item_value_2() { return 15; }
int get_max_combined() { return 30; }
int get_item_color() { return 2; }

void create()
{
	set_name("Mũ Cương Thi");
	set_picid_1(4063);
	set_picid_2(4063);
	set_value(100);
	set_amount(1);
}

string get_desc()
{
	return "Vật phẩm sự kiện";
}
