#include <ansi.h>
#include <item.h>
#include <public.h>
#include <task.h>

inherit COMBINED;
inherit ITEM;
int get_item_value() { return 50; }
int get_item_value_2() { return 50; }
int get_item_color() { return 1; }
int iTime = 30 * 24 * 60 * 60;

void create()
{
	set_name("Cầu Tuyết");
	set_picid_1(12021);
	set_picid_2(12021);
	set_value(300);
	set_amount(1);
}

string get_desc()
{
	return "Vật phẩm trang trí giáng sinh.";
}
