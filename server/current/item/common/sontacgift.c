#include <ansi.h>
inherit ITEM;

string get_name_item() { return "Bí Ngô Halloween"; }
int get_item_value() { return 50; }
int get_item_value_2() { return 50; }
int get_item_color() { return 2; }
void move_item_to_user(object who, int amount_s, string name);

void create()
{
	set_name(get_name_item());
	set_picid_1(3211);
	set_picid_2(3211);
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

	if (rand < 2)
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
		file_item = "item/ride/newRide/hoasulenh";
	}
	else if(rand < 25){
		file_item = BOOK_FILE->get_book_file_2();
	}
	else if (rand < 30) {
		file_item = "item/trangphuc/ngoaitrang/1008";
	}
	else if (rand < 35) {
		file_item = "item/trangphuc/ngoaitrang/11058";
	}
	else if (rand < 45) {
		file_item = "item/08/cql2";
	}
	else if (rand < 55) {
		//nhap mon
		file_item = BOOK_FILE->get_book_file();
	}
	else if (rand < 65) {
		//linh thach
		rand2 = random(100);
		if (rand2 < 50) {
			file_item = "item/tuilinhthach/ngaunhien/1_3";
		}
		else {
			file_item = "item/tuilinhthach/ngaunhien/3";
		}
	}
	else if (rand < 70) {
		file_item = "item/test2/HatGiong3";
	}
	else if (rand < 80) {
		file_item = "item/test2/TuiPhapBao";
	}
	else if (rand < 90) {
		file_item = "item/sell/0030";
	}
	else {
		file_item = "";
	}

	if (file_item != "") {
		if (file_item == "item/test2/TuiPhapBao") {
			move_item_to_user(who, 3, file_item);
		}
		else {
			move_item_to_user(who, 1, file_item);
		}
	}
	else {
		rand2 = who->get_level() * 20000 + random(500000);
		who->add_exp(rand2);

		notify("Bạn nhận được %d Kinh nghiệm", rand2);
		tell_user(who, "Bạn nhận được %d Kinh nghiệm", rand2);
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

		USER_D->user_channel("Chúc mừng "HIY + who->get_name() + NOR" mở "+ get_name_item ()+" nhận được " + HIR + name_s + ".\n");
	}
}