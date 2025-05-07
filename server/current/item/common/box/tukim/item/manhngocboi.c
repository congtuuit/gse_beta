#include <ansi.h>

inherit ITEM;
inherit COMBINED;

int get_max_combined() { return 10000; }
int get_item_color() {return 2 ;}

void create()
{
        set_name( "Mảnh Ghép Ngọc Bội" );
        set_picid_1(4952);
        set_picid_2(4952);
        set_value(10);
		set_save_2("cqtq.score",15);
        set_amount(1);
}

string get_desc() 
{ 
        return "Sau khi thu thập đủ mảnh ghép có thể đến \nSứ Giả Hoạt Động để hợp thành Ngọc Bội Tín Vật.";
}

