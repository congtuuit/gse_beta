#include <ansi.h>
inherit ITEM;

string get_name_item() { return "Túi Quà Tôn - Trọng - Đạo"; }
int get_item_value() { return 50; }
int get_item_value_2() { return 50; }
int get_item_color() { return 2; }
void move_item_to_user(object who, int amount_s, string name);

void create()
{
	set_name(get_name_item());
	set_picid_1(7124);
	set_picid_2(7124);
	set_value(5);
}

int is_usable() { return 1; }

string get_desc()
{
	return sprintf("%s, Vật phẩm sự kiện, thu thập đủ bộ chữ có thể nhận được nhiều phần quà giá trị\n(Nhấn chuột phải để sử dụng)", get_name_item());
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

	if (rand < 8)
	{
		file_item = "item/tuilinhthach/ngaunhien/1_3";
	}
	else if (rand < 18)
	{
		file_item = BOOK_FILE->get_book_file_2();
	}
	else if (rand < 28) {
		//nhap mon
		file_item = BOOK_FILE->get_book_file();
	}
	else if (rand < 40) {
		file_item = "exp";
	}
	else if (rand < 52) {
		file_item = "gold";
	}
	else if (rand < 59) {
		file_item = "npc/event/PhoBan/item/manhngoc";
	}
	else if (rand < 66) {
		file_item = "npc/event/PhoBan/item/hoathach";
	}
	else if (rand < 71) {
		file_item = "item/sell/1032";
			//file_item = new ("/item/common/dacuonghoa");
	}
	else if (rand < 76) {
		file_item = "item/sell/0032";
		//file_item = new ("/item/common/dacuonghoa");
	}
	else if (rand < 91) {
		file_item = "item/test2/TuiPhapBao";
	}
	else {
		file_item = "item/sell/0031";
	}

	if (file_item == "exp") {
		rand2 = 500000 + random(500000);
		who->add_exp(rand2);

		notify("Bạn nhận được %d Kinh nghiệm", rand2);
		tell_user(who, "Bạn nhận được %d Kinh nghiệm", rand2);
	}
	else if(file_item == "gold"){
		rand2 = 50000 + random(50000);
		who->add_cash(rand2);

		notify("Bạn nhận được %d lượng", rand2);
		tell_user(who, "Bạn nhận được %d lượng.", rand2);
	}
	else {
		move_item_to_user(who, 1, file_item);
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

		USER_D->user_channel("Chúc mừng "HIY + who->get_name() + NOR" mở " + get_name_item() + " nhận được " + HIR + name_s + ".\n");
	}
}