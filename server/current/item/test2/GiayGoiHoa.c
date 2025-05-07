#include <ansi.h>
inherit ITEM;
inherit COMBINED;

int get_item_value() { return 500; }
int get_item_value_2() { return 500; }
int get_item_color() { return 2; }

void create()
{
	set_name("Giấy Gói Hoa");
	set_picid_1(0401);
	set_picid_2(0401);
	set_value(2);
	set_amount(1);

}
int is_usable() { return 0; }

string get_desc()
{
	return "Vật phẩm sự kiện Tiên Hoa.";
}


