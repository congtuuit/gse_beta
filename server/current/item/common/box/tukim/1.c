#include <ansi.h>
#include <equip.h>
inherit USABLE;
inherit ITEM;
inherit COMBINED;

int is_box() { return 1; }
int get_item_value() { return 300; }
int get_item_value_2() { return 300; }
int get_item_color() { return 3; }


void create()
{
    set_name("Rương và Chìa khóa");
    set_picid_1(12328);
    set_picid_2(12328);
    set_level(10);
    set_value(50);
	set_amount(1);

}

string get_desc()
{
    return "";
}

void move_item_to_user(object who, int amount_s, string name)
{
	int p, total, amount;
	object item;
	string name_s;

	item = new(name);

	if (item)
	{
		name_s = item->get_name();
		if (item->get_max_combined() > 1)
		{
			total = amount_s;
			amount = USER_INVENTORY_D->carry_combined_item(who, item, total);
			if (amount > 0 && item->set_amount(amount))
			{
				if (p = item->move(who, -1))
				{
					item->add_to_user(p);
				}
			}
			else
			{
				item->add_amount(-total);
			}
		}
		else
		{
			if (p = item->move(who, -1))
			{
				item->add_to_user(p);
			}
		}

		//USER_D->user_channel("Chúc mừng "HIY + who->get_name() + NOR" mở " + get_name_item() + " nhận được " + HIR + name_s + ".\n");
	}
}

int get_use_effect(object me)
{

	int rand, p, cash, exp, pot, rand2;
	object item;
	string file_item;

	if (USER_INVENTORY_D->get_free_count(me) < 2)
	{
		notify("Hành trang không đủ 2 chỗ trống");
		return 0;
	}

	item = this_object();

	move_item_to_user(me, 1, "item/common/box/tukim/box");
	move_item_to_user(me, 1, "item/common/box/tukim/key");

	item->add_amount(-1);


    return 0;
}
