#include <item.h>
#include <ansi.h>
inherit ITEM;
inherit COMBINED;

int get_max_combined() { return 30; }
int get_item_color() { return 2; }

int get_item_value() { return 50; }
int get_item_value_2() { return 50; }

void create()
{
        set_name("Sư");
        set_picid_1(4983);
        set_picid_2(4983);
        set_value(50);
        set_amount(1);
}

string get_desc() 
{
	return "Vật phẩm sự kiện, thu thập đủ bộ chữ có thể nhận được nhiều phần quà giá trị";    	
}