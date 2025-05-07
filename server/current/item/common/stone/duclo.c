#include <item.h>
#include <ansi.h>
#include <equip.h>

inherit ITEM;
inherit COMBINED;
inherit "/inh/item/diamond";

#define EQUIP "sys/item/equip"

int get_level() { return 1; };
int get_max_hole() { return 3; }
int confirm_sell_item() { return 1; }
int get_item_color() {return 1 ;}
int is_add_hole() { return 1; }
int get_max_combined() { return 999; }

string get_diamond_type() { return "hole"; }

void create()
{
        set_name("Lạc Thanh Chi Tiễn");
        set_real_name("Hole");
        set_picid_1(6889);
        set_picid_2(6889);
        set_value(500);
		set_amount(1);
		set_record(1);
		set_save_2("mecung.point", 1);
}

string get_desc() 
{
	return "Ánh sáng lấp lánh như lưu tinh, thần tiễn mang sức mạnh phi thường. \nTương truyền có thể sử dụng để đục lỗ trang bị";
}
