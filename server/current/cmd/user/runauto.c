#include <cmd.h>
#include <ansi.h>
#include <skill.h>
#include <equip.h>
#include <effect.h>
#include <time.h>
#include <city.h>
#include <npc.h>
#include <skill.h>

#define GET "cmd/std/get"

string AUTO = "E100";
int ON = 1;
int OFF = 0;

int findMinIndex(int *arr, int size)
{
	int i, min = arr[0], pos = 0;
	for (i = 1; i < size; i++)
		if (arr[i] < min)
		{
			min = arr[i];
			pos = i;
		}
	return pos;
}

object nearObject(object me)
{
	object *objs, who, best = 0;
	int i, sz, x_me, y_me, bestDist, dist, my_channel;

	objs = get_range_object_2(me, 20, CHAR_TYPE);
	x_me = get_x(me);
	y_me = get_y(me);
	bestDist = 999999;
	my_channel = me->get_channel();
	sz = sizeof(objs);

	for (i = 0; i < sz; i++)
	{
		who = objs[i];
		if (!objectp(who))
			continue;

		if ((who->is_user() || who->is_player()))
			continue;

		if (who->get_channel() != my_channel)
			continue;

		if (!who->can_be_fighted(me))
			continue;

		dist = (get_x(who) - x_me) * (get_x(who) - x_me) + (get_y(who) - y_me) * (get_y(who) - y_me);
		if (dist < bestDist)
		{
			bestDist = dist;
			best = who;
			if (dist == 0)
				break;
		}
	}
	return best;
}

int getItemAround(object me)
{
	object *items, best = 0;
	int i, sz, x_me, y_me, dist, bestDist;

	items = get_range_object_2(me, 8, ITEM_TYPE);
	x_me = get_x(me);
	y_me = get_y(me);
	bestDist = 999999;
	sz = sizeof(items);

	for (i = 0; i < sz; i++)
	{
		if (!objectp(items[i]))
			continue;
		dist = (get_x(items[i]) - x_me) * (get_x(items[i]) - x_me) + (get_y(items[i]) - y_me) * (get_y(items[i]) - y_me);
		if (dist < bestDist)
		{
			bestDist = dist;
			best = items[i];
		}
	}

	if (objectp(best))
	{
		tell_user(me, ECHO "Nhặt vật phẩm: %s", best->get_name());
		GET->main(me, sprintf("%d %d", get_x(best), get_y(best)));
	}
	return 1;
}

int autoRecall(object me)
{
	mapping throttle = ([]);
	int now, z, x, y, p, target_id;
	string dir;
	object target;

	now = time();

	if (throttle[me] && now - throttle[me] < 2)
		return 1;
	throttle[me] = now;

	if (me->get_save_2("autoFarm") - time() < 0)
	{
		me->set_2("autoFarm", OFF);
		__FILE__->removeTitle(me);
		__FILE__->backHome(me);
		return 0;
	}

	if (me->get_2("autoFarm") != ON)
		return 0;

	__FILE__->getItemAround(me);

	target = me->get_2("targetNPC");
	if (objectp(target) && !target->is_die())
	{
		// log_file("_debug.txt", sprintf("LOG autoRecall  11 %s\n", short_time()));

		if (!me->is_fighting(target))
		{
			// log_file("_debug.txt", sprintf("LOG autoRecall  111 %s\n", short_time()));

			me->start_fight(target);
			me->to_front_xy(get_x(target), get_y(target));
		}
		call_out("autoRecall", 2, me);
		return 1;
	}

	target = nearObject(me);

	if (objectp(target) && !target->is_die())
	{
		// log_file("_debug.txt", sprintf("LOG autoRecall  22 %s\n", short_time()));

		target_id = getoid(target);
		z = get_z(target);
		x = get_x(target);
		y = get_y(target);
		p = get_valid_xy(z, x, y, IS_CHAR_BLOCK);
		if (p)
		{
			x = p / 1000;
			y = p % 1000;

			me->add_to_scene(z, x, y, 3); // COMMENT: Dịch chuyển tức thời
		}

		// log_file("_debug.txt", sprintf("LOG autoRecall  222 %s\n", short_time()));

		tell_user(me, ECHO "Tấn công: %s (%d,%d) ID %x", target->get_name(), x, y, target_id);

		me->start_fight(target);
		me->set_2("targetNPC", target);

		call_out("autoRecall", 2, me);
		return 1;
	}
	else
	{
		// log_file("_debug.txt", sprintf("LOG autoRecall KHÔNG TÌM THẤY  2 %s\n", short_time()));
	}

	call_out("autoRecall", 3, me);
	return 1;
}

int main(object me, string arg)
{
	if (arg == "auto")
	{
		me->set_2("autoFarm", ON);
		if (me->get_save_2("autoFarm") - time() > 0)
		{
			__FILE__->getItemAround(me);
			__FILE__->autoRecall(me);
			__FILE__->addTitle(me);
		}
		else
		{
			notify("Bạn đã hết thời gian sử dụng Auto!");
		}
		return 1;
	}

	if (arg == "offauto")
	{
		me->set_2("autoFarm", OFF);
		__FILE__->removeTitle(me);
		return 1;
	}

	return 1;
}

int addTitle(object me)
{
	string cName = TITLE_D->get_titlename(AUTO);
	send_user(me, "%c%s", '!', "" + cName);
	me->add_title(AUTO);
	me->show_title(AUTO);
	MAILBOX->sys_mail(me->get_id(), me->get_number(), HIR + cName);
	return 1;
}

int removeTitle(object me)
{
	string cName;
	me->set_title("", "");
	cName = TITLE_D->get_titlename(AUTO);
	me->hide_title(AUTO);
	me->delete_title(AUTO);
	MAILBOX->sys_mail(me->get_id(), me->get_number(), "Ngưng tự động đánh");
	return 1;
}

int backHome(object me)
{
	removeTitle(me);
	me->set_login_flag(2);
	set_invisible(me, 1);
	set_effect(me, EFFECT_USER_LOGIN, 4);
	me->add_to_scene(80, 293 + random(10), 186 + random(10));
	return 1;
}
