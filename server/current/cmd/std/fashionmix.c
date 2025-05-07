#include <item.h>
#include <ansi.h>

int mix1(object me, object* item);
int mix_limit_time_item(object item1, object item2);

int main(object me, string arg)
{
	object* item, who, item1, item2;
	string name, file, result;
	int* id;
	int i, level, d;
	if (!arg) return 1;

	item = ({ 0, 0, });  id = ({ 0, 0, });

	if (sscanf(arg, "? %x# %x#", id[0], id[1]) != 2)
	{
		notify("Bạn muốn hợp thành đồ gì?");
		return 1;
	}

	for (i = 0; i < 2; i++)
	{
		if (!objectp(item[i] = present(sprintf("%x#", id[i]), me, 1, MAX_CARRY * 4)))    // 物品是否存在？
		{
			return 1;
		}
	}

	if (item[0] == item[1]) return 1;

	if (name == "time_limit") return mix_limit_time_item(item[0], item[1]);

	//Kiem tra
	//if (item1 = objectp(item[0]) && item2 = objectp(item[1])) {
	if (!item[0]->is_fashion() || !item[1]->is_fashion()) {
		tell_user(me, ECHO"Trang bị này không thể hợp thành!");
		return 1;
	}
		
	if (item[0]->get_lock_time() != 0 || item[1]->get_lock_time() != 0) {
		tell_user(me, ECHO"Trang bị đã kích hoạt, không thể hợp thành!");
		return 1;
	}

	return mix1(me, item);
}

int mix1(object me, object* item)
{
	object newItem;
	string file, result, index, name;
	int level, d, rate;

	file = item[0]->get_next_item();
	name = item[0]->get_name();
	rate = random(100);

	d = get_d(item[1]);
	item[1]->remove_from_user();
	destruct(item[1]);

	if (me->get_vip()) {
		rate -= 5;
	}

	if (rate <= 20) {
		newItem = new (file);
		if (d = newItem->move(me, d))
		{
			newItem->add_to_user(d);
		}

		tell_user(me, HIG"Hợp thành thành công!");
		result = sprintf("[FASHION Thành công] Tổng hợp biến mất %s,%d,%s,%s @%s %s %s %d %s %d_%d_%d", me->get_name(), me->get_number(), get_ip_name(me), me->get_id(), "", item[0]->get_name(), "/sys/item/item"->get_pawn_save_string(item[0]), 1, item[0]->get_user_id(), get_z(me), get_x(me), get_y(me));
		"/sys/user/cmd"->log_item(result);
	}
	else {
		tell_user(me, ECHO"Hợp thành thất bại!");
		result = sprintf("[FASHION] Tổng hợp biến mất %s,%d,%s,%s @%s %s %s %d %s %d_%d_%d", me->get_name(), me->get_number(), get_ip_name(me), me->get_id(), "", item[0]->get_name(), "/sys/item/item"->get_pawn_save_string(item[0]), 1, item[0]->get_user_id(), get_z(me), get_x(me), get_y(me));
		"/sys/user/cmd"->log_item(result);
	}


	if (is_god(me)) {
		tell_user(me, "Rate_%d vip_%d", rate, me->get_vip());
	}

	return 1;
}


int mix_limit_time_item(object item1, object item2)
{
	int d, time, time1, time2;


	if (item1->is_limit_time_item() && item2->is_limit_time_item()
		&& get_file_name(item1) == get_file_name(item2))
	{
		if (item1->get_lock_time() == 0)	item1->get_desc();
		time1 = item1->get_lock_time() - time();
		if (item2->get_lock_time() == 0)	item2->get_desc();
		time2 = item2->get_lock_time() - time();

		if (time1 < 0) time1 = 0;
		if (time2 < 0) time2 = 0;
		time = time1 + time2;

		item1->remove_from_user();
		destruct(item1);

		if (time <= 0)
		{
			item2->remove_from_user();
			destruct(item2);
		}
		else
		{
			item2->set_lock_time(time() + time);
			d = get_d(item2);
			item2->add_to_user(d);
		}
		return 1;
	}
}
