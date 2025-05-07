#include <ansi.h>
#include <skill.h>

inherit ITEM;

string get_name_item() { return "Túi quà Valentine"; }
int get_item_value() { return 50; }
int get_item_value_2() { return 50; }
int get_item_color() { return 2; }
void move_item_to_user(object who, int amount_s, string name);

void create()
{
	set_name(get_name_item());
	set_picid_1(4981);
	set_picid_2(4981);
	set_value(5);
}

int is_usable() { return 1; }

string get_desc()
{
	return sprintf("%s, bên trong có nhiều vật phẩm giá trị", get_name_item());
}

int get_use_effect(object me)
{
	return __FILE__->get_use_effect_callout(me, this_object());
}

int get_use_effect_callout(object who, object gift)
{
	int rand, p, cash, exp, pot, rand2;
	object item;
	string file_item;

	if (USER_INVENTORY_D->get_free_count(who) < 1)
	{
		notify("Hành trang không đủ 1 chỗ trống");
		return 0;
	}

	if (sizeof_inventory(who, 1, MAX_CARRY) >= MAX_CARRY)
	{
		send_user(who, "%c%s", '!', "Hành trang trên người ngươi không đủ 1 chỗ, lần sau nhận thưởng phải chú ý");
		return 0;
	}


	gift->remove_from_user();
	destruct(gift);
	
	rand = random(100);

	if (rand < 5)
	{
		file_item = "item/sell/0034";
	}
	else if (rand < 14)
	{
		rand2 = random(100);
		if (rand2 > 55) {
			file_item="item/sell/2032";
		}
		else {
			file_item = sprintf("item/sell/%d032", 0 + random(2));
		}
	}
	else if (rand < 20) {
		file_item = "item/tuilinhthach/ngaunhien/1_5";
	}
	else if(rand < 25){
		file_item = BOOK_FILE->get_book_file_2();
	}
	else if (rand < 45) {
		file_item = "item/08/cql2";
	}
	else if (rand < 60) {
		//Siêu cấp
		file_item = sprintf("item/final/15/153%d", 0 + random(6));
	}
	else if (rand < 80) {
		//linh thach
		rand2 = random(100);
		if (rand2 < 50) {
			file_item = "item/tuilinhthach/ngaunhien/5";
		}
		else {
			file_item = "item/tuilinhthach/ngaunhien/3";
		}
	}
	else if (rand < 90) {
		file_item = "npc/event/PhoBan/item/manhngoc";

	} else 
		file_item = "item/test2/TuiPhapBao";



	if (file_item != "") {
		if (file_item == "item/test2/TuiPhapBao") {
			move_item_to_user(who, 3, file_item);
		}
		else {
			move_item_to_user(who, 1, file_item);
		}
	}
	
	send_user(get_scene_object_2(who, USER_TYPE), "%c%d%w%c%c%c", 0x6f, getoid(who), 5915, 3, OVER_BODY, PF_ONCE);

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

		USER_D->user_channel("Chúc mừng "HIY + who->get_name() + NOR" mở "+ HIR"" + get_name_item ()+NOR" nhận được " + HIR + name_s + ".\n");
	}
}