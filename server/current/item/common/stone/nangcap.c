#include <item.h>
#include <ansi.h>
#include <equip.h>
#include <public.h>

inherit ITEM;
inherit "/inh/item/diamond";
#define EQUIP "sys/item/equip"

int get_level() { return 1; };
int get_max_hole() { return 3; }
int confirm_sell_item() { return 1; }
int get_item_color() {return 2 ;}
int is_add_hole() { return 1; }
int is_specal_move() { return 1; }

string get_diamond_type() { return "hole"; }

void create()
{
        set_name("Kết Tinh Thạch");
        set_real_name("Hole");
        set_picid_1(8965);
        set_picid_2(8965);
        set_unit("块");
        set_value(500);
        set_level(1);
}

string get_desc() 
{
	return "Là nguyên liệu để nâng cấp ô khảm nạm cho trang bị";
}

int move_item(object me, object item, object equip)
{
	return __FILE__->move_item_callout(me, item, equip, 1 );
}

int move_item2(object me, object item, object equip)
{
	return __FILE__->move_item_callout(me, item, equip, 2 );
}

int move_item_callout(object me, object item, object equip, int type)
{
	string result, forge;
	object item2;
	int i, p, level, rate, hole_number;

	string cmd="";


	/*if( equip->is_equip()==0 && equip->get_real_name()!="Hole" )  return 0;
	
	if( equip->is_equip())
	{
		i=equip->get_equip_type();
		if (i != WEAPON_TYPE && i != ARMOR_TYPE && i != HEAD_TYPE && i != BOOTS_TYPE && i != WAIST_TYPE && i != NECK_TYPE) {
			return 0;
		}
	}
	
	if (type == 1)
	{
		hole_number = EQUIP->get_hole_amount(equip);

		if (hole_number < 1) {
			return 0;
		}

		if (HOLE_D->get_pos_to_mix(equip) == -1) {
			return 0;
		}

		for (i = 0; i < hole_number; i++) {
			cmd += sprintf(ESC"Nâng cấp lỗ khảm %d\nhole %x# %d\n", i+1, getoid(equip),i);
		}

		send_user(me, "%c%c%s", ':', 3, sprintf("    Bạn muốn nâng cấp lỗ khảm?\n%s"ESC"Rời khỏi\nCLOSE\n", cmd));
	}*/

	return 1;
}