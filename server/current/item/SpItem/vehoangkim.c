#include <item.h>
#include <ansi.h>
#include <equip.h>

inherit ITEM;
inherit "/inh/item/diamond";


int get_item_value() { return 3000; }
int get_item_value_2() { return 3000; }

int is_diamond_2() { return 1; }

int confirm_sell_item() { return 1; }

int get_item_color() {return 3 ;}

string get_diamond_type() { return "forge"; }

string get_forge_index() {return "5";}

int is_specal_move() {return 1;}

string item_str_name() {
	return "Thẻ Hoàng Kim";
}

int level_type() {
	return 5;
}

void create()
{
        set_name(item_str_name());
        set_real_name("Đoạn Thạch");
        set_picid_1(3811);
        set_picid_2(3811);
        set_unit("块");
        set_value(500);
}

string get_desc() 
{
	return sprintf("Khảm thẻ hoàng kim vào trang bị có thể khiến thay đổi phẩm chất thành hoàng kim");
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
	int i, p, level, rate, color;	
	if( equip->is_equip()==0 && equip->get_real_name()!="Đoạn Thạch" )  return 0;
	if( equip->is_equip())
	{
		i=equip->get_equip_type();
		if ( i!=WEAPON_TYPE&&i!=ARMOR_TYPE&&i!=HEAD_TYPE&&i!=BOOTS_TYPE&&i!=WAIST_TYPE&&i!=NECK_TYPE)
			return 0;
	}

	if (equip->get_real_name()=="Đoạn Thạch" )
	{
		return 0;
	}

	/*color = equip->get_item_color();
	if (color >= 2) {
		tell_user(me, "Trang bị này không thể tăng phẩm chất");
		return 0;
	}*/
	
	if (type==1)
	{
		item2 = new(get_file_name(equip));
		item2->set_item_color(2);
		p = item2->move(me, -1);
		item2->add_to_user(p);

		equip->remove_from_user();
		destruct(equip);

		TASK_LEGEND_D->check_task_item1(me, item_str_name(), 1);

		return 1;
	}		
	return 1;
}