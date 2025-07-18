#include <item.h>
#include <equip.h>
#include <action.h>

// 函数：命令处理
int main(object me, string arg)
{
	mapping list;
	object city, who, pawn, item, pet;
	string* key, file, name, dtype;
	int what, tax, i, size, price;

	if (!arg) return 1;

	if (sscanf(arg, "%s,%d", arg, what) == 2); 
	if (!objectp(who = find_char(arg))) return 1;

	//Check seller
	if (who->is_seller() != 7000 &&
		who->is_seller() != 7005 &&
		who->is_seller() != 72022 &&
		who->is_seller() != 70021 &&
		who->is_seller() != 71021 &&
		who->is_seller() != 12021 &&
		who->is_seller() != 72021
		) return 1;

	if ((time() - me->get("buy_time") > 300) && !inside_screen_2(me, who))
	{
		notify("Bạn cách %s quá xa rồi.", who->get_name());
		return 1;
	}

	"/quest/help"->send_help_tips(me, 5);

	if (who->is_seller() == 7000)
	{
		if (!mapp(list = who->get_2("good")) || !(size = sizeof(key = keys(list))))
		{
			notify(who->get_name() + " Tất cả đều đã bán hết.");
			return 1;
		}

		if (city = CITY_D->get_city_object(who))
		{
			if (me->get_city_name() == who->get_city_name())
				tax = city->get_buy_tax();
			else    tax = city->get_buy_tax_2();
		}
		tax = 0;
		if (size) key = sort_array(key, 1);
		send_user(me, "%c%c%c%d%s", 0x28, 0, 0, getoid(who), sprintf("%-12s%s", who->get_name(), ""));
		for (i = 0; i < size; i++)
		{
			file = list[key[i]];
			price = who->get_2(sprintf("price.%s", key[i]));
			if (!price) price = file->get_save_2("diemnhiemvu.score");
			dtype = file[< 4.. < 1];
			if (file->get_item_type() == ITEM_TYPE_DIAMOND_3 && who->get_save_2("diamond." + dtype) >= 100)
				send_user(me, "%c%c%d%w%w%c%c%s", 0x28, to_int(key[i]), price * who->get_save_2("diamond." + dtype) / 100,
					file->get_picid_2(), file->get_amount(), 0, file->get_item_color(), file->get_name());
			else
				send_user(me, "%c%c%d%w%w%c%c%s", 0x28, to_int(key[i]), price * (100 + tax) / 100,
					file->get_picid_2(), file->get_amount(), 0, file->get_item_color(), file->get_name());
		}
	} 


	if (who->is_seller() == 7005)
	{
		if (!mapp(list = who->get_2("good")) || !(size = sizeof(key = keys(list))))
		{
			notify(who->get_name() + " Tất cả đều đã bán hết.");
			return 1;
		}

		if (city = CITY_D->get_city_object(who))
		{
			if (me->get_city_name() == who->get_city_name())
				tax = city->get_buy_tax();
			else    tax = city->get_buy_tax_2();
		}
		tax = 0;
		if (size) key = sort_array(key, 1);
		send_user(me, "%c%c%c%d%s", 0x28, 0, 0, getoid(who), sprintf("%-12s%s", who->get_name(), ""));
		for (i = 0; i < size; i++)
		{
			file = list[key[i]];
			price = who->get_2(sprintf("price.%s", key[i]));
			if (!price) price = file->get_save_2("mecung.point");
			dtype = file[< 4.. < 1];
			if (file->get_item_type() == ITEM_TYPE_DIAMOND_3 && who->get_save_2("diamond." + dtype) >= 100)
				send_user(me, "%c%c%d%w%w%c%c%s", 0x28, to_int(key[i]), price * who->get_save_2("diamond." + dtype) / 100,
					file->get_picid_2(), file->get_amount(), 0, file->get_item_color(), file->get_name());
			else
				send_user(me, "%c%c%d%w%w%c%c%s", 0x28, to_int(key[i]), price * (100 + tax) / 100,
					file->get_picid_2(), file->get_amount(), 0, file->get_item_color(), file->get_name());
		}
	}


	if (who->is_seller() == 12021 || who->is_seller() == 72021 || who->is_seller() == 71021 || who->is_seller() == 70021)
	{
		if (!mapp(list = who->get_2("good")) || !(size = sizeof(key = keys(list))))
		{
			notify(who->get_name() + " Tất cả đều đã bán hết.");
			return 1;
		}

		if (city = CITY_D->get_city_object(who))
		{
			if (me->get_city_name() == who->get_city_name())
				tax = city->get_buy_tax();
			else    tax = city->get_buy_tax_2();
		}
		tax = 0;
		if (size) key = sort_array(key, 1);
		send_user(me, "%c%c%c%d%s", 0x28, 0, 0, getoid(who), sprintf("%-12s%s", who->get_name(), ""));
		for (i = 0; i < size; i++)
		{
			file = list[key[i]];
			price = who->get_2(sprintf("price.%s", key[i]));
			if (!price) price = file->get_save_2("cqtq.score");
			dtype = file[< 4.. < 1];
			
			if (file->get_item_type() == ITEM_TYPE_DIAMOND_3 && who->get_save_2("diamond." + dtype) >= 100)
				send_user(me, "%c%c%d%w%w%c%c%s", 0x28, to_int(key[i]), price * who->get_save_2("diamond." + dtype) / 100,
					file->get_picid_2(), file->get_amount(), 0, file->get_item_color(), file->get_name());
			else
				send_user(me, "%c%c%d%w%w%c%c%s", 0x28, to_int(key[i]), price * (100 + tax) / 100,
					file->get_picid_2(), file->get_amount(), 0, file->get_item_color(), file->get_name());
		}
	}

	if (who->is_seller() == 72022)
	{
		if (!mapp(list = who->get_2("good")) || !(size = sizeof(key = keys(list))))
		{
			notify(who->get_name() + " Tất cả đều đã bán hết.");
			return 1;
		}

		if (city = CITY_D->get_city_object(who))
		{
			if (me->get_city_name() == who->get_city_name())
				tax = city->get_buy_tax();
			else    tax = city->get_buy_tax_2();
		}
		tax = 0;
		if (size) key = sort_array(key, 1);
		send_user(me, "%c%c%c%d%s", 0x28, 0, 0, getoid(who), sprintf("%-12s%s", who->get_name(), ""));
		for (i = 0; i < size; i++)
		{
			file = list[key[i]];
			price = who->get_2(sprintf("price.%s", key[i]));
			if (!price) price = file->get_save_2("khobau.score");
			dtype = file[< 4.. < 1];

			if (file->get_item_type() == ITEM_TYPE_DIAMOND_3 && who->get_save_2("diamond." + dtype) >= 100)
				send_user(me, "%c%c%d%w%w%c%c%s", 0x28, to_int(key[i]), price * who->get_save_2("diamond." + dtype) / 100,
					file->get_picid_2(), file->get_amount(), 0, file->get_item_color(), file->get_name());
			else
				send_user(me, "%c%c%d%w%w%c%c%s", 0x28, to_int(key[i]), price * (100 + tax) / 100,
					file->get_picid_2(), file->get_amount(), 0, file->get_item_color(), file->get_name());
		}
	}


	return 1;
}
