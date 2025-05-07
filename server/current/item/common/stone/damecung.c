#include <item.h>
#include <ansi.h>

inherit ITEM;
inherit COMBINED;

int get_item_color() {return 1 ;}
int get_max_combined() { return 999; }

void create()
{
        set_name("Đá Mê Cung");
        set_picid_1(201);
        set_picid_2(201);
        set_value(500);
		set_amount(1);
		set_record(1);

        set_no_give(1);
        set_no_sell(1);
}

string get_desc() 
{
	return "Vật phẩm dùng để trao đổi";
}
