#include <ansi.h>
inherit ITEM;

string get_name_item() { return "Túi Quà Thỏ Ngọc"; }
int get_item_value() { return 50; }
int get_item_value_2() { return 50; }
int get_item_color() { return 2; }
void move_item_to_user(object who, int amount_s, string name);

void create()
{
	set_name(get_name_item());
	set_picid_1(3107);
	set_picid_2(3107);
	set_value(5);
}

int is_usable() { return 1; }

string get_desc()
{
	return sprintf("%s, mở ra có thể nhận được rất nhiều vật phẩm đáng giá", get_name_item());
}

int get_use_effect(object me)
{
	return __FILE__->get_use_effect_callout(me, this_object());
}

int get_use_effect_callout(object who, object gift)
{
	int rand, p, cash, exp, pot;
	object item;

	if (USER_INVENTORY_D->get_free_count(who) < 1)
	{
		notify("Hành trang không đủ 1 chỗ trống");
		return 0;
	}

	if (sizeof_inventory(who, 1, MAX_CARRY) >= MAX_CARRY)
	{
		send_user(who, "%c%s", '!', "Hành trang trên người ngươi không đủ");
		return 0;
	}

	gift->remove_from_user();
	destruct(gift);

	rand = random(1000);

	if (rand < 50)
	{
		//Cao cap doan thach
		move_item_to_user(who, 1, "/item/sell/2032");
	}
	else if (rand < 120)
	{
		//Trung cap doan thach
		move_item_to_user(who, 1, "/item/sell/1032");
	}
	else if (rand < 200)
	{
		//So cap doan thach
		move_item_to_user(who, 1, "/item/sell/0032");
	}
	else if (rand < 330)
	{
		//So tri duoc khoa
		move_item_to_user(who, 5, "/item/test2/block/0007");
	}
	else if (rand < 460)
	{
		//So phuc duoc khoa
		move_item_to_user(who, 5, "/item/test2/block/0009");
	}
	else if (rand < 590)
	{
		//Tui phap bao
		move_item_to_user(who, 3, "/item/test2/TuiPhapBao");
	}
	else if (rand < 720)
	{
		//book
		item = new(BOOK_FILE->get_book_file());
		if (p = item->move(who, -1))
		{
			item->add_to_user(p);

			USER_D->user_channel("Chúc mừng "HIY + who->get_name() + NOR" mở "+ get_name_item() + " nhận được " + HIR + item->get_name() + ".\n");
		}
		
	}
	else if (rand < 850) 
	{
		//Tui Linh thach 1-3
		move_item_to_user(who, 1, "/item/TuiLinhThach/NgauNhien/1_3");
	}
	else if (rand < 940)
	{
		//thu cuoi meo he
		move_item_to_user(who, 1, "/item/ride/013");
	}
	else 
	{
		//Hat Giong hoang kim
		move_item_to_user(who, 1, "/item/test2/HatGiong3");
	}

	return 0;
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

		USER_D->user_channel("Chúc mừng "HIY + who->get_name() + NOR" mở túi quà Tết Trung Thu nhận được " + HIR + name_s + ".\n");
	}
}