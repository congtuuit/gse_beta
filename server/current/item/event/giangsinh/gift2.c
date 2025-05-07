#include <ansi.h>
inherit ITEM;

string get_name_item() { return "Quà Giáng Sinh Gà Tây"; }
int get_item_value() { return 50; }
int get_item_value_2() { return 50; }
int get_item_color() { return 2; }
void move_item_to_user(object who, int amount_s, string name);

void create()
{
	set_name(get_name_item());
	set_picid_1(7126);
	set_picid_2(7126);
	set_value(5);
}

int is_usable() { return 1; }

string get_desc()
{
	return sprintf("%s, bên trong có nhiều vật phẩm giá trị. Túi quà dùng Gà Tây đổi thường từ Ông già Noel.", get_name_item());
}

int get_use_effect(object me)
{
	return __FILE__->get_use_effect_callout(me, this_object());
}

int get_use_effect_callout(object who, object giftItem)
{
	int rate, p, exp, pot, money;
	object gift, me;
	string name;

	me = new("npc/party/santaclaus");

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

	giftItem->remove_from_user();
	destruct(giftItem);
	
	rate = random(101);

	if (rate < 10)
	{
		gift = new("item/91/9160");
		name = "Chiến Quốc Lệnh";
	}
	else if (rate < 18)
	{
		gift = new("item/tuilinhthach/ngaunhien/1_3");
		name = "Chiến Quốc Lệnh";
	}
	else if (rate < 25)
	{
		gift = new("item/tuilinhthach/ngaunhien/2");
		name = "Tù Và Chiến Quốc";
	}
	else if (rate < 40)
	{
		gift = new("item/sell/0002");
		name = "Tiểu Huyết Thạch";
	}
	else if (rate < 55)
	{
		gift = new("item/sell/0004");
		name = "Tiểu Pháp Lực Thạch";
	}
	else if (rate < 65)
	{
		gift = new(BOOK_FILE->get_book_file_2());
		name = gift->get_name();
	}
	else if (rate < 75)
	{
		gift = new("item/final/91/1808");
		name = "Phục Sinh Đơn";
	}
	else if (rate < 85)
	{
		gift = new(BOOK_FILE->get_book_file());
	}
	else
	{
		switch (random(3))
		{
		default:
			gift = new("item/04/0415");
			break;
		case 1:
			gift = new("item/04/0416");
			break;
		case 2:
			gift = new("item/04/0417");
			break;
		}
	}

	if (gift)
	{
		p = gift->move(who, -1);
		if (!p)
		{
			destruct(gift);
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n Hành trang của bạn không đủ ô trống !\n"ESC"Rời khỏi", me->get_name()));
			return 0;
		}
		send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf("%s:\n Bạn đã nhận được phần quà "HIR "%s"NOR ", chúc bạn giáng sinh ấm áp\n"ESC"Rời khỏi", me->get_name(), gift->get_name()));
		gift->add_to_user(p);
		if (gift->get_name())
			CHAT_D->sys_channel(0, sprintf(HIR "Xin chúc mừng %s trong mùa Giáng Sinh đạt được %s !", who->get_name(), gift->get_name()));
	}

	return 1;
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

