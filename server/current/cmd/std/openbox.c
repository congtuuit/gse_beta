
#include <ansi.h>
#include <equip.h>

#define PLUNDER_PROTECT_TIME    120

int open_box(object me);

int main(object me, string arg)
{
	object* allitem, item, item2;
	string* args, result;
	int rand, id, i;
	int type, locate, level, color;
	allitem = me->get_2("openbox.item");
	if (!arg)
	{
		if (!allitem) return 1;
		if (sizeof(allitem) != 8) return 1;
		if (me->get_2("openbox.status") != 0) return 1;
		me->set_2("openbox.status", 1);
		call_out("open_box", 7, me);
		send_user(me, "%c%c", 0x91, 4);
		return 1;
	}
	args = explode(arg, " ");
	if (sizeof(args) != 2) return 1;
	if (args[0] == "?")
	{
		if (!allitem) return 1;
		if (sizeof(allitem) != 8) return 1;
		sscanf(args[1], "%x#", id);
		for (i = 0; i < 8; i++)
		{
			if (getoid(allitem[i]) == id)
			{
				item = allitem[i];
				break;
			}
		}
		if (!item) return 1;
		result = ITEM_ITEM_D->get_look_string(me, item);
		send_user(me, "%c%c%d%s", 0x91, 3, getoid(item), result);
		return 1;
	}
	if (!objectp(item = present(args[0], me, 1, MAX_CARRY * 4))) return 1;
	if (!objectp(item2 = present(args[1], me, 1, MAX_CARRY * 4))) return 1;
	if (!item->is_key()) return 1;
	if (!item2->is_box()) return 1;
	
	if (item->get_level() != item2->get_level())
	{
		send_user(me, "%c%s", '!', "Rương và chìa khóa không tương thích！");
		return 1;
	}

	me->set_2("boxLevel", item2->get_level());
	

	allitem = "/quest/box"->get_item(item2->get_level());
	if (!allitem) return 1;
	if (sizeof(allitem) != 8) return 1;
	me->set_2("openbox.item", allitem);

	if (item->is_record())
	{
		result = sprintf("Mở kho báu ra %s,%d,%s,%s @%s %s %s %d %s %d_%d_%d", me->get_name(), me->get_number(), get_ip_name(me), me->get_id(), "", item->get_name(), "/sys/item/item"->get_pawn_save_string(item), 1, item->get_user_id(), get_z(me), get_x(me), get_y(me));
		"/sys/user/cmd"->log_item(result);
	}

	if (item->is_key_sp()) {
		item->add_amount(-1);
	}
	else {
		item->remove_from_user();
		destruct(item);
	}

	
	if (item2->is_record())
	{
		result = sprintf("Mở kho báu ra %s,%d,%s,%s @%s %s %s %d %s %d_%d_%d", me->get_name(), me->get_number(), get_ip_name(me), me->get_id(), "", item2->get_name(), "/sys/item/item"->get_pawn_save_string(item2), 1, item2->get_user_id(), get_z(me), get_x(me), get_y(me));
		"/sys/user/cmd"->log_item(result);
	}

	if (item2->is_box_sp()) {
		item2->add_amount(-1);
	}
	else {
		item2->remove_from_user();
		destruct(item2);
	}

	
	for (i = 0; i < 8; i++) if (item = allitem[i])
	{
		type = item->get_item_type_2();
		locate = item->get_equip_type();
		if (locate > 100) locate -= 100;
		if (item->get_level() > 0) level = item->get_level();
		else level = item->get("level");
		color = item->get_item_color();
		send_user(me, "%c%c%c%d%w%w%c%c%c%c%s", 0x91, 2, i + 1, getoid(item),
			item->get_picid_2(), item->get_amount(), type,
			color, level, locate, item->get_name());
		result = ITEM_ITEM_D->get_look_string(me, item);
		send_user(me, "%c%c%d%s", 0x91, 3, getoid(item), result);
	}
	return 1;
}

int open_box(object me)
{
	object* allitem, item;
	int rand, total, amount, i, count, p;

	allitem = me->get_2("openbox.item");
	if (!allitem) return 1;
	if (sizeof(allitem) != 8) return 1;
	rand = random(10000);
	if (rand < 500) rand = 0;
	else
		if (rand < 1500) rand = 1;
		else
			if (rand < 3000) rand = 2;
			else
				rand = (rand - 3001) % 5 + 3;

	//tile quay
	if (me->get_2("boxLevel") == 10) {
		if (me->get_2("roundTotal") % 20 == 0) {
			if (rand > 3) {
				rand = random(4);
			}
		}
	}
	else {
		if (me->get_2("roundTotal") != me->get_2("boxLevel")) {
			me->set_2("roundTotal", 1);
		}

		if (me->get_2("roundTotal") % 20 == 0 && me->get_2("boxLevel") != 1) {
			if (rand > 3) {
				rand = random(4);
			}
		}
		else {
			if (me->get_2("roundTotal") % 20 == 0) {
				if (rand > 3) {
					rand = random(4);
				}
			}
		}
	}
	

	if (is_god(me))
	{
		if (me->get("lb") > 0) rand = me->get("lb") - 1;
		if (rand > 8) rand = 7;
	}

	me->set_2("roundTotal", me->get_2("roundTotal") + 1);
	me->set_2("roundLevel", me->get_2("boxLevel"));

	item = allitem[rand];

	send_user(me, "%c%c%c", 0x91, 5, rand + 1);

	me->set_save_2("openedbox.total", me->get_save_2("openedbox.total") + 1);

	if (me->get_save_2("openedbox.title") == 0 && me->get_save_2("openedbox.total") >= 1000) {
		me->add_title(sprintf("%s", "A999"));
		me->show_title(sprintf("%s", "A999"));
		me->set_save_2("openedbox.title", 1);
	}

	if (item->is_cash())
	{
		i = item->get_value();
		me->add_cash(i);
		call_out("message_box", 1, me, 1, sprintf(" %d lượng", i));
		for (i = 0; i < sizeof(allitem); i++) destruct(allitem[i]);
		me->delete_2("openbox");
		return;
	}

	if ((total = USER_INVENTORY_D->can_carry_3(me, item)) < 1)
	{
		send_user(me, "%c%s", '!', "Hành trang không đủ chỗ trống！");
		p = get_valid_xy(get_z(me), get_x(me), get_y(me), IS_ITEM_BLOCK);
		item->set_user_id(me->get_id());
		item->add_to_scene(get_z(me), p / 1000, p % 1000);
		item->set("winner", me);
		item->set("time", time());
		allitem -= ({ item });
		for (i = 0; i < sizeof(allitem); i++) destruct(allitem[i]);
		me->delete_2("openbox");
		return;
	}

	if (me->get_2("boxLevel") == 10 || me->get_2("boxLevel") == 1 || me->get_2("boxLevel") == 2|| me->get_2("boxLevel") == 3) {
		call_out("message_box", 1, me, 3,  item->get_name());
	}
	else {
		if (rand <= 2)
			call_out("message_box", 1, me, 2, item->get_name());
		else
			call_out("message_box", 1, me, 1, item->get_name());
	}
	

	allitem -= ({ item });
	count = item->get_amount();
	if (item->get_max_combined() > 1)
	{
		total = count;
		amount = USER_INVENTORY_D->carry_combined_item(me, item, total);
		if (amount > 0 && item->set_amount(amount))
		{
			if (p = item->move2(me))
			{
				item->add_to_user(p);
			}
		}
		else    item->add_amount(-total);
	}
	else
	{
		if (p = item->move2(me))
		{
			item->add_to_user(p);
		}
	}

	for (i = 0; i < sizeof(allitem); i++) destruct(allitem[i]);
	me->delete_2("openbox");
}

int message_box(object me, int type, string name)
{
	send_user(me, "%c%s", ';', sprintf("Chúc mừng bạn nhận được"HIR" %s "NOR".", name));
	if (type == 3) {
		USER_D->user_channel(sprintf(HIG"Người chơi "HIY"%s"HIG" mở rương nhận được "HIR" %s "HIG"！", me->get_name(), name));
	} else 
	if (type == 2) 
		USER_D->user_channel(sprintf("Chúc mừng %s mở rương nhận được "HIR" %s "NOR"，Chúng ta hãy chúc mừng họ！", me->get_name(), name));
}

void before_quit(object me)
{
	object* allitem, item;
	int i;
	allitem = me->get_2("openbox.item");
	if (!allitem) return;
	for (i = 0; i < sizeof(allitem); i++) destruct(allitem[i]);
	me->delete_2("openbox");
}