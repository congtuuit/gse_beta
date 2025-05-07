#include <time.h>
#include <ansi.h>
#include <skill.h>
#include <action.h>
#include <effect.h>

varargs int main(object me, string arg, int server)
{
	object map, *user, *user2, *npc, *item, who, currentMap, admin, *seal;
	string chan, id;
	int z0, x0, y0, z1, x1, y1, z, x, y, dx, dy, d, walk, time2, now, dt, chan_time, chan_end, wx, wy, wz;
	int busy, p, i, size;
	int current_count, heart, count;
	int jump, iTime;
	int vaotu, vaotuluc, interval;

	mixed *mixTime;

	if (!arg || arg == "")
		return 1;

	if (sscanf(arg, ">%d", d))
	{
		if (d >= 1 && d <= 8)
		{
			me->to_front(d == 2 ? 2 : d); // vẫn xử lý d == 2 là 2
			return 1;
		}
		else
		{
			me->to_front(2);
			return 1;
		}
	}

	z0 = get_z(me);
	x0 = get_x(me);
	y0 = get_y(me);

	if (me->is_store_open())
	{
		send_user(me, "%c%w%w", 0x07, x0, y0);
		return 1;
	}

	if ((busy = get_effect(me, EFFECT_CHAR_BUSY)) > 0)
	{
		notify("Bạn còn phải bận %d giây", busy);
		send_user(me, "%c%w%w%c", 0x07, x0, y0, 1);
		return 1;
	}

	// Kiểm tra trạng thái không thể di chuyển
	if (
		get_effect(me, EFFECT_CHAR_FAINT) ||
		get_effect(me, EFFECT_CHAR_FAINT_2) ||
		get_effect(me, EFFECT_SLEEP) ||
		get_effect(me, EFFECT_CHAR_NO_MOVE) ||
		get_effect(me, EFFECT_CHAR_FREEZE) ||
		get_effect(me, EFFECT_CHAR_SHUT))
	{
		send_user(me, "%c%w%w%c", 0x07, x0, y0, 2);
		return 1;
	}

	// Kiểm tra trạng thái giấc mơ, chỉ áp dụng nếu không từ server
	if (!server && (get_effect(me, EFFECT_CHAR_DREAM_1) || get_effect(me, EFFECT_CHAR_DREAM)))
	{
		send_user(me, "%c%w%w%c", 0x07, x0, y0, 3);
		return 1;
	}

	CHAR_CHAR_D->stop_loop_perform_go(me);

	if (get_z(me) != z0 || get_x(me) != x0 || get_y(me) != y0)
		return 1;

	if (get_heart_state(me) == FIGHT_STAT)
	{
		me->set_perform_file(0);
		set_heart_state(me, WALK_STAT);
		set_heart_count_2(me, 0);
	}
	else if (get_heart_state(me) == MAGIC_STAT)
	{
		me->set_cast_file(0);
		me->set_cast_arg("");

		user = get_scene_object_2(me, USER_TYPE);
		user = filter_by_channel(user, me->get_channel());

		send_user(user, "%c%d%d%c", 0x40, getoid(me), time2(), MAGIC_ACT_END); // 结束施法动作
		send_user(user, "%c%d%w%c%c%w%c%c%c", 0x6f, getoid(me),
				  41100, 1, UNDER_FOOT, 42100, 1, UNDER_FOOT, PF_STOP); // 结束符法效果  get_cast_seal()

		set_heart_state(me, WALK_STAT);
		set_heart_count_2(me, 0);
	}
	if (get_heart_state(me) == WALK_STAT)
	{
		heart = get_heart_timer(me);
		count = get_heart_count_2(me);
		count = set_heart_count_2(me, count - abs(heart - get_heart_timer_2(me)));
		set_heart_timer_2(me, heart);
	}

	now = time();

	if (sscanf(arg, "%d,%d %s %d", x, y, arg, time2) != 4)
	{
		if (sscanf(arg, "%d,%d %s", x, y, arg) != 3)
		{
			send_user(me, "%c%w%w%c", 0x07, x0, y0, 5);
			return 1;
		}
		time2 = 0; // mặc định nếu không có time2
	}

	// Kiểm tra lệch thời gian tương lai
	dt = time2 - now;
	if (time2 > 0 && dt > 4)
	{
		send_user(me, "%c%w%w%c%w", 0x07, x0, y0, 6, dt);
		return 1;
	}

	// Kiểm tra spam di chuyển
	if (me->get("gotime") == time2)
	{
		count = me->add("gocount", 1);
		if (count > 2 && MAIN_D->get_host_type() < 1000)
		{
			send_user(me, "%c%w%w%c%w", 0x07, x0, y0, 14, count);
			return 1;
		}
	}
	else
	{
		me->set("gocount", 1);
		me->set("gotime", time2);
	}

	// Kiểm tra lệch thời gian quá khứ
	if (time2 > 0 && dt < -10)
	{
		send_user(me, "%c%w%w%c%w", 0x07, x0, y0, 6, dt);
		return 1;
	}

	// Kiểm tra lệch toạ độ client gửi về
	if (x0 != x || y0 != y)
	{
		send_user(me, "%c%w%w%c", 0x07, x0, y0, 7);
		return 1;
	}

	// Chuỗi hướng trống
	if (!arg || arg == "")
	{
		send_user(me, "%c%w%w%c", 0x07, x0, y0, 8);
		return 1;
	}

	// Rút gọn hướng di chuyển
	if (get_effect(me, EFFECT_CHAR_SLOW) ||
		get_effect(me, EFFECT_CHAR_LAZY) ||
		(get_effect(me, EFFECT_CHAR_INVISIBLE) &&
		 !get_effect(me, EFFECT_03643) &&
		 !me->get_save("no_visible")))
	{
		if (sizeof(arg) > 1)
			arg = arg[0..0];
	}
	else if (sizeof(arg) > 3)
		arg = arg[0..3];

	// Tính toán đường đi
	if (!(p = from_here(z0, x0, y0, arg, IS_MAP_BLOCK)))
	{
		send_user(me, "%c%w%w%c", 0x07, x0, y0, 9);
		return 1;
	}

	//
	x = p / 10000;
	y = (p / 10) % 1000; // Tối ưu phép toán modulo và chia
	d = p % 10;

	// Không cần di chuyển nếu không đổi tọa độ
	if (x0 == x && y0 == y)
	{
		send_user(me, "%c%w%w%c", 0x07, x0, y0, 10);
		return 1;
	}

	// Kiểm tra có nằm trong bản đồ
	if (!inside_map(z0, x, y))
	{
		send_user(me, "%c%w%w%c", 0x07, x0, y0, 11);
		return 1;
	}

	// Kiểm tra giới hạn khoảng cách khi có hiệu ứng 'chan'
	if (get_effect(me, EFFECT_CHAR_CHAN))
	{
		chan = me->get_save("pf.chan");
		if (stringp(chan))
		{

			if (sscanf(chan, "%d:(%d,%d)", z1, x1, y1) == 3)
			{
				if (abs(x1 - x) > 2 || abs(y1 - y) > 2)
				{
					send_user(me, "%c%w%w%c", 0x07, x0, y0, 12);
					return 1;
				}
			}
		}
	}

	// Kiểm tra và cập nhật thời gian hiệu ứng 'chan'
	chan_time = me->get_2("pf.chanTime");
	chan_end = me->get_2("pf.chanEnd");

	if (chan_time > 0 || get_effect(me, EFFECT_CHAR_CHAN))
	{
		dt = time() - chan_end;
		if (dt < chan_time)
		{
			interval = chan_time - dt;
			if (interval > 0)
				set_effect(me, EFFECT_CHAR_CHAN, interval);
		}
		else
		{
			me->delete_2("pf.chanTime");
			me->delete_2("pf.chanEnd");
		}
	}

	who = me->get_quest("escort.robber#");

	if (objectp(who) && who->is_escort_robber())
	{
		wx = get_x(who), wy = get_y(who), wz = get_z(who);
		if (!inside_screen(x, y, wx, wy))
		{
			if (get_z(me) != wz)
			{
				who->destruct_npc_callout(who, me);
			}
			else
			{
				notify(who->get_name() + " có vẻ như hành động của bạn bị ảnh hưởng");
				send_user(me, "%c%w%w%c", 0x07, x0, y0, 13);
				return 1;
			}
		}
	}

	// Hủy trạng thái tấn công nếu đang auto fight
	if (me->get_attack_move() && me->get_enemy())
	{
		printf(ECHO "Bạn ngừng giữa chừng “Tự động xạ kích”.");
		me->set_enemy(0);
	}

	if (me->get_char_action() != DEFAULT_ACT)
		me->set_char_action(DEFAULT_ACT);

	dx = abs(x0 - x);
	dy = abs(y0 - y);
	walk = (dx > dy) ? dx : dy;

	me->add_2("gocount.count2", walk);

	if (me->get_2("gocount.time2") == 0)
	{
		me->set_2("gocount.time2", time());
		me->set_2("gocount.count2", 0);
	}

	set_heart_state(me, WALK_STAT);
	if (me->get_attack_move() == 0 && objectp(who = me->get_enemy()))
	{
		if (distance_between(me, who) == 1)
			set_heart_count_2(me, range_value(current_count + 2 * walk, -10, MAX_NUMBER));
	}
	else
	{
		set_heart_count_2(me, range_value(current_count + 4 * walk, -10, MAX_NUMBER));
	}

	dx = (x / AREA_SIZE) - (x0 / AREA_SIZE);
	dy = (y / AREA_SIZE) - (y0 / AREA_SIZE);

	if (dx == 0 && dy == 0)
	{
		remove_block(z0, x0, y0, CHAR_BLOCK);
		set_x(me, x);
		set_y(me, y);
		set_d(me, d);
		set_block(z0, x, y, CHAR_BLOCK);

		user = get_scene_object(z0, x, y, USER_TYPE);
		user = filter_by_channel(user, me->get_channel());

		if (sizeof(arg) == 1)
			send_user(user, "%c%d%d%w%w%s", 0x67, getoid(me), time2(), x0, y0, arg);
		else
			send_user(user, "%c%d%d%w%w%c%c%c%s", 0x47, getoid(me), time2(), x0, y0, x - x0, y - y0, d, arg);

		me->set_no_fight(MAP_D->is_inside_safe_zone(z0, x, y) ? 1 : 0);
	}
	else
	{
		int dx_sign = (dx < 0) ? -1 : (dx > 0) ? 1 : 0;
		int dy_sign = (dy < 0) ? -1 : (dy > 0) ? 1 : 0;

		if (dx_sign == -1 && dy_sign == -1) {
			dx = 0x12e; dy = 0x1d2;
		} else if (dx_sign == -1 && dy_sign == 1) {
			dx = 0x1e8; dy = 0x5e;
		} else if (dx_sign == -1 && dy_sign == 0) {
			dx = 0x128; dy = 0x52;
		} else if (dx_sign == 1 && dy_sign == -1) {
			dx = 0x5e; dy = 0x1e8;
		} else if (dx_sign == 1 && dy_sign == 1) {
			dx = 0x1d2; dy = 0x12e;
		} else if (dx_sign == 1 && dy_sign == 0) {
			dx = 0x52; dy = 0x128;
		} else if (dx_sign == 0 && dy_sign == -1) {
			dx = 0xe; dy = 0x1c0;
		} else if (dx_sign == 0 && dy_sign == 1) {
			dx = 0x1c0; dy = 0xe;
		}

		remove_block(z0, x0, y0, CHAR_BLOCK);

		// user = get_scene_object(z0, x0, y0, USER_TYPE, dx);
		// npc = get_scene_object(z0, x0, y0, CHAR_TYPE, dx);
		// item = get_scene_object(z0, x0, y0, ITEM_TYPE, dx);
		// user->remove_to_user(me);
		// npc->remove_to_user(me);
		// item->remove_to_user(me);

		// item = get_scene_object(z0, x0, y0, SEAL_TYPE, dx);
		// item->remove_to_user_2(me);

		user = get_scene_object(z0, x0, y0, USER_TYPE, dx);
		if (objectp(user)) user->remove_to_user(me);

		npc = get_scene_object(z0, x0, y0, CHAR_TYPE, dx);
		if (objectp(npc)) npc->remove_to_user(me);

		item = get_scene_object(z0, x0, y0, ITEM_TYPE, dx);
		if (objectp(item)) item->remove_to_user(me);

		seal = get_scene_object(z0, x0, y0, SEAL_TYPE, dx);
		if (objectp(seal)) seal->remove_to_user_2(me);


		set_x(me, x);
		set_y(me, y);
		set_d(me, d);
		set_block(z0, x, y, CHAR_BLOCK);
		move_object(me, z0, x, y, USER_TYPE);

		user2 = get_scene_object(z0, x, y, USER_TYPE, dy);
		user2 = filter_by_channel(user2, me->get_channel());

		npc = get_scene_object(z0, x, y, CHAR_TYPE, dy);
		npc = filter_by_channel(npc, me->get_channel());

		item = get_scene_object(z0, x, y, ITEM_TYPE, dy);
		user2->show_to_user(me);
		npc->show_to_user(me);
		item->show_to_user(me);

		item = get_scene_object(z0, x, y, SEAL_TYPE, dy);
		item->show_to_user_2(me);

		me->show_to_scene(user2, x0, y0, d, 0);
		user2 = get_scene_object_2(me, USER_TYPE);
		user2 = filter_by_channel(user2, me->get_channel()) + user;

		if (sizeof(arg) == 1)
			send_user(user2, "%c%d%d%w%w%s", 0x67, getoid(me), time2(), x0, y0, arg);
		else
			send_user(user2, "%c%d%d%w%w%c%c%c%s", 0x47, getoid(me), time2(), x0, y0, x - x0, y - y0, d, arg);

		send_user(user, "%c%d", 0x78, getoid(me));

		if (MAP_D->is_inside_safe_zone(z0, x, y))
		{
			me->set_no_fight(1);
		}
		else
		{
			me->set_no_fight(0);

			npc = get_range_object_2(me, 6, CHAR_TYPE);
			if (sizeof(npc))
				npc->init_heart_beat_idle();
		}
	}

	if ((p = get_jumpout(z0, x, y)) && MAP_D->can_jump(me, z0, z = p / 1000000) && (!objectp(who = me->get_quest("escort.robber#")) || !who->is_escort_robber()))
	{
		x = (p % 1000000) / 1000;
		y = p % 1000;

		if ((who = me->get_quest("escort.npc")) && who->get_owner() == me && inside_screen_2(me, who))
			who->add_to_scene(z, x, y, d);
		if ((who = me->get_2("orgtask2.npc")) && who->get_owner() == me && inside_screen_2(me, who))
			who->add_to_scene(z, x, y, d);

		if (p = get_valid_xy(z, x + random(3) - 1, y + random(3) - 1, IS_CHAR_BLOCK))
		{
			x = p / 1000;
			y = p % 1000;

			me->set_login_flag(2);
			set_invisible(me, 1);
			set_effect(me, EFFECT_USER_LOGIN, 4);

			me->add_to_scene(z, x, y, d);
			jump = z0 * 1000000 + x0 * 1000 + y0;
			if (z != z0)
				if (map = get_map_object(z))
					notify(map->get_name());
		}
	}
	else if (MAP_D->is_inside_battle(z0))
	{
		if (objectp(map = get_map_object(z0)))
		{
			who = me->get_manager();
			d = getoid(me);

			if (map->get_manager() == who)
			{
				user = map->get_user_dbase();
				send_user(user, "%c%c%d%w%w", 0x54, 10, d, x, y);
				// for( i = 0, size = sizeof(user); i < size; i ++ )
				// if( objectp( who = user[i] ) ) send_user( who, "%c%c%d%w%w", 0x54, 10, d, x, y );
			}
			else if (map->get_manager_2() == who) // 防守方
			{
				user = map->get_user_2_dbase();
				send_user(user, "%c%c%d%w%w", 0x54, 10, d, x, y);
				// for( i = 0, size = sizeof(user); i < size; i ++ )
				// if( objectp( who = user[i] ) ) send_user( who, "%c%c%d%w%w", 0x54, 10, d, x, y );
			}
		}
	}
	else if (arrayp(user = me->get_team())) // 更新队员坐标
	{
		user -= ({me, 0});
		user = filter_array(user, ( : $1 && get_z($1) == $2:), z0);
		send_user(user, "%c%c%d%w%w", 0x54, 10, me->get_number(), x, y);
	}
	z0 = get_z(me);
	if (get_block(z0, x, y) & SEAL_BLOCK)
	{
		item = get_range_object_2(me, 0, SEAL_TYPE);
		if (sizeof(item) > 0)
		{
			if (item[0]->is_self_seal())
				item[0]->heart_beat_loop(0, 0, 0, 0, 0, 0, 0, 0);
		}
	}
	if (me->is_leader())
	{
		USER_HEART_D->team_follow(me, jump);
	}
	return 1;
}

int main_npc(object me, string arg)
{
	object map, *user, *user2, *npc, who;
	string chan;
	int z0, x0, y0, z1, x1, y1, z, x, y, dx, dy, d, p;

	if (!arg || arg == "")
		return 1;

	if (!me->is_moveable())
		return 1; // 不允许移动

	if (get_effect(me, EFFECT_CHAR_BUSY) || get_effect(me, EFFECT_CHAR_FAINT) || get_effect(me, EFFECT_SLEEP) || get_effect(me, EFFECT_CHAR_NO_MOVE) || get_effect(me, EFFECT_CHAR_FAINT_2) || get_effect(me, EFFECT_CHAR_FREEZE) || get_effect(me, EFFECT_CHAR_SHUT))
		return 1;

	if (sizeof(arg) > 3)
		arg = arg[0..3];

	z0 = get_z(me);
	x0 = get_x(me);
	y0 = get_y(me);

	if (!(p = from_here(z0, x0, y0, arg, IS_CHAR_BLOCK)))
		return 1; // 能否通过？

	x = p / 10000;
	y = (p % 10000) / 10;
	d = p % 10;

	if (x0 == x && y0 == y)
		return 1; // 没有移动

	if (!inside_map(z0, x, y))
		return 1; // 坐标错误

	if (me->cannot_enter_city() && !me->get_owner() && MAP_D->is_inside_safe_zone(z0, x, y))
		return 1; // 怪物不能进城(小心亲友、宠物)

	if (get_effect(me, EFFECT_CHAR_CHAN) && stringp(chan = me->get_save("pf.chan")) && sscanf(chan, "%d:(%d,%d)", z1, x1, y1) == 3 && (abs(x1 - x) > 2 || abs(y1 - y) > 2))
	{
		send_user(me, "%c%w%w%c", 0x07, x0, y0, 12);
		return 1;
	}

	dx = (x / AREA_SIZE) - (x0 / AREA_SIZE);
	dy = (y / AREA_SIZE) - (y0 / AREA_SIZE);

	if (dx == 0 && dy == 0) // 本场景内行走
	{
		remove_block(z0, x0, y0, CHAR_BLOCK);
		set_x(me, x);
		set_y(me, y);
		set_d(me, d);
		set_block(z0, x, y, CHAR_BLOCK);

		user = get_scene_object(z0, x, y, USER_TYPE);
		user = filter_by_channel(user, me->get_channel());

		if (sizeof(arg) == 1)
			send_user(user, "%c%d%d%w%w%s", 0x67, getoid(me), time2(), x0, y0, arg);
		else
			send_user(user, "%c%d%d%w%w%c%c%c%s", 0x47, getoid(me), time2(), x0, y0, x - x0, y - y0, d, arg);

		me->set_no_fight(MAP_D->is_inside_safe_zone(z0, x, y) ? 1 : 0); // 安全区判断
	}
	else
	{
		if (dx < 0)
		{
			if (dy < 0)
			{
				dx = 0x12e;
				dy = 0x1d2;
			}
			else if (dy > 0)
			{
				dx = 0x1e8;
				dy = 0x5e;
			}
			else
			{
				dx = 0x128;
				dy = 0x52;
			}
		}
		else if (dx > 0)
		{
			if (dy < 0)
			{
				dx = 0x5e;
				dy = 0x1e8;
			}
			else if (dy > 0)
			{
				dx = 0x1d2;
				dy = 0x12e;
			}
			else
			{
				dx = 0x52;
				dy = 0x128;
			}
		}
		else
		{
			if (dy < 0)
			{
				dx = 0xe;
				dy = 0x1c0;
			}
			else
			{
				dx = 0x1c0;
				dy = 0xe;
			}
		}

		remove_block(z0, x0, y0, CHAR_BLOCK); // 删除阻挡
		user = get_scene_object(z0, x0, y0, USER_TYPE, dx);
		user = filter_by_channel(user, me->get_channel());

		set_x(me, x);
		set_y(me, y);
		set_d(me, d); // Thiết lập 坐标，增加阻挡
		set_block(z0, x, y, CHAR_BLOCK);
		objectp(who = me->get_owner()) && who->is_user() ? move_object(me, z0, x, y, USER_TYPE) : move_object(me, z0, x, y, CHAR_TYPE); // 移动 NPC

		user2 = get_scene_object(z0, x, y, USER_TYPE, dy);
		user2 = filter_by_channel(user2, me->get_channel());

		me->show_to_scene(user2, x0, y0, d, 0);
		user2 = get_scene_object_2(me, USER_TYPE);
		user2 = filter_by_channel(user2, me->get_channel()) + user;

		if (sizeof(arg) == 1)
			send_user(user2, "%c%d%d%w%w%s", 0x67, getoid(me), time2(), x0, y0, arg);
		else
			send_user(user2, "%c%d%d%w%w%c%c%c%s", 0x47, getoid(me), time2(), x0, y0, x - x0, y - y0, d, arg);

		send_user(user, "%c%d", 0x78, getoid(me));

		if (MAP_D->is_inside_safe_zone(z0, x, y)) // 安全区判断
		{
			me->set_no_fight(1);
		}
		else
		{
			me->set_no_fight(0);

			if (objectp(me->get_owner()))
			{
				npc = get_range_object_2(me, 6, CHAR_TYPE);
				if (sizeof(npc))
					npc->init_heart_beat_idle();
			}
		}
	}

	if (objectp(who = me->get_owner()) && who->is_user())
	{
		if (get_z(who) != get_z(me))
		{
			send_user(who, "%c%c%d%w%w", 0x2c, 7, getoid(me), -1, -1); // 更新召唤兽坐标
		}
		else
			send_user(who, "%c%c%d%w%w", 0x2c, 7, getoid(me), x, y); // 更新召唤兽坐标
	}

	return 1;
}

int main_fly(object me, int x, int y, int d, int flag)
{
	object map, *user, *user2, *npc, *item, who;
	int z0, x0, y0, z, dx, dy;
	int p, i, size;

	z0 = get_z(me);
	x0 = get_x(me);
	y0 = get_y(me);

	if (abs(x - x0) > 10 || abs(y - y0) > 10)
		return 1; // 距离过远
	if (!inside_map(z0, x, y))
		return 1; // 坐标非法
	if (get_block(z0, x, y) & IS_CHAR_BLOCK)
		return 1; // 无法落脚
	if (!from_to(z0, x0, y0, x - x0, y - y0, MAP_BLOCK))
		return 1; // 无法穿越

	if (objectp(who = me->get_quest("escort.robber#"))								// 寻找蒙面人
		&& who->is_escort_robber() && !inside_screen(x, y, get_x(who), get_y(who))) // 移动受限制  // !inside_screen_2(me, who)
		return 1;

	dx = (x / AREA_SIZE) - (x0 / AREA_SIZE);
	dy = (y / AREA_SIZE) - (y0 / AREA_SIZE);

	if (dx == 0 && dy == 0) // 本场景内瞬移
	{
		remove_block(z0, x0, y0, CHAR_BLOCK);
		set_x(me, x);
		set_y(me, y);
		set_d(me, d);
		set_block(z0, x, y, CHAR_BLOCK);

		user = get_scene_object(z0, x, y, USER_TYPE);
		// send_user( user, "%c%d%d%w%w%w%w%c%c", 0x87, getoid(me), time2(), x0, y0, x, y, d, flag );

		me->set_no_fight(MAP_D->is_inside_safe_zone(z0, x, y) ? 1 : 0); // 安全区判断
	}
	else // 跨越场景瞬移
	{
		if (dx < 0)
		{
			if (dy < 0)
			{
				dx = 0x12e;
				dy = 0x1d2;
			}
			else if (dy > 0)
			{
				dx = 0x1e8;
				dy = 0x5e;
			}
			else
			{
				dx = 0x128;
				dy = 0x52;
			}
		}
		else if (dx > 0)
		{
			if (dy < 0)
			{
				dx = 0x5e;
				dy = 0x1e8;
			}
			else if (dy > 0)
			{
				dx = 0x1d2;
				dy = 0x12e;
			}
			else
			{
				dx = 0x52;
				dy = 0x128;
			}
		}
		else
		{
			if (dy < 0)
			{
				dx = 0xe;
				dy = 0x1c0;
			}
			else
			{
				dx = 0x1c0;
				dy = 0xe;
			}
		}

		remove_block(z0, x0, y0, CHAR_BLOCK); // 删除阻挡

		user = get_scene_object(z0, x0, y0, USER_TYPE, dx); // 删除对象
		npc = get_scene_object(z0, x0, y0, CHAR_TYPE, dx);
		item = get_scene_object(z0, x0, y0, ITEM_TYPE, dx);
		user->remove_to_user(me);
		npc->remove_to_user(me);
		item->remove_to_user(me);

		item = get_scene_object(z0, x0, y0, SEAL_TYPE, dx);
		item->remove_to_user_2(me);

		set_x(me, x);
		set_y(me, y);
		set_d(me, d); // Thiết lập 坐标，增加阻挡
		set_block(z0, x, y, CHAR_BLOCK);
		move_object(me, z0, x, y, USER_TYPE); // 移动玩家

		user2 = get_scene_object(z0, x, y, USER_TYPE, dy); // 新增对象
		user2 = filter_by_channel(user2, me->get_channel());

		npc = get_scene_object(z0, x, y, CHAR_TYPE, dy);
		npc = filter_by_channel(npc, me->get_channel());

		item = get_scene_object(z0, x, y, ITEM_TYPE, dy);

		user2->show_to_user(me);
		npc->show_to_user(me);
		item->show_to_user(me);

		item = get_scene_object(z0, x, y, SEAL_TYPE, dy);
		item->show_to_user_2(me);

		me->show_to_scene(user2, x0, y0, d, 0);
		user2 = get_scene_object_2(me, USER_TYPE) + user;
		send_user(user2, "%c%d%d%w%w%w%w%c%c", 0x87, getoid(me), time2(), x0, y0, x, y, d, flag);

		send_user(user, "%c%d", 0x78, getoid(me));

		if (MAP_D->is_inside_safe_zone(z0, x, y)) // 安全区判断
		{
			me->set_no_fight(1);
		}
		else
		{
			me->set_no_fight(0);

			npc = get_range_object_2(me, 6, CHAR_TYPE);
			if (sizeof(npc))
				npc->init_heart_beat_idle();
		}
	}

	if (!MAP_D->is_inside_copy(z0) && (p = get_jumpout(z0, x, y))						  // 跳转另一场景
		&& (!objectp(who = me->get_quest("escort.robber#")) || !who->is_escort_robber())) // 寻找蒙面人
	{
		z = p / 1000000;
		x = (p % 1000000) / 1000;
		y = p % 1000; // get_jumpout 内含 z

		if ((who = me->get_quest("escort.npc")) // 运镖人物
			&& who->get_owner() == me && inside_screen_2(me, who))
			who->add_to_scene(z, x, y, d);

		if (p = get_valid_xy(z, x + random(3) - 1, y + random(3) - 1, IS_CHAR_BLOCK))
		{
			x = p / 1000;
			y = p % 1000;

			me->set_login_flag(2); // 跳转保护
			set_invisible(me, 1);
			set_effect(me, EFFECT_USER_LOGIN, 4);

			me->add_to_scene(z, x, y, d);

			// if( z != z0 ) if( map = get_map_object(z) ) notify( map->get_name() );    // 显示地图名
		}
	}
	else if (MAP_D->is_inside_battle(z0)) // 战场
	{
		if (objectp(map = get_map_object(z0))) // 获取战场对象
		{
			who = me->get_manager();
			d = getoid(me);

			if (map->get_manager() == who) // 攻击方
			{
				user = map->get_user_dbase();
				send_user(user, "%c%c%d%w%w", 0x54, 10, d, x, y);
				//                              for( i = 0, size = sizeof(user); i < size; i ++ )
				//                                      if( objectp( who = user[i] ) ) send_user( who, "%c%c%d%w%w", 0x54, 10, d, x, y );
			}
			else if (map->get_manager_2() == who) // 防守方
			{
				user = map->get_user_2_dbase();
				send_user(user, "%c%c%d%w%w", 0x54, 10, d, x, y);
				//                              for( i = 0, size = sizeof(user); i < size; i ++ )
				//                                      if( objectp( who = user[i] ) ) send_user( who, "%c%c%d%w%w", 0x54, 10, d, x, y );
			}
		}
	}
	else if (arrayp(user = me->get_team())) // 更新队员坐标
	{
		user -= ({me, 0});
		user = filter_array(user, ( : $1 && get_z($1) == $2:), z0);
		send_user(user, "%c%c%d%w%w", 0x54, 10, me->get_number(), x, y);
	}

	if (get_effect(me, EFFECT_CHAR_CHAN))
		set_effect(me, EFFECT_CHAR_CHAN, 1); // 移除粘手效果
	z0 = get_z(me);
	if (get_block(z0, x, y) & SEAL_BLOCK)
	{
		item = get_range_object_2(me, 0, SEAL_TYPE);
		if (sizeof(item) > 0)
		{
			if (item[0]->is_self_seal())
				item[0]->heart_beat_loop(0, 0, 0, 0, 0, 0, 0, 0);
		}
	}
	return 1;
}

int main_fly_npc(object me, int x, int y, int d, int flag)
{
	object map, *user, *user2, *npc, who;
	int z0, x0, y0, z, dx, dy;
	int p, i, size;

	z0 = get_z(me);
	x0 = get_x(me);
	y0 = get_y(me);

	if (abs(x - x0) > 10 || abs(y - y0) > 10)
		return 1; // 距离过远
	if (!inside_map(z0, x, y))
		return 1; // 坐标非法
	if (get_block(z0, x, y) & IS_CHAR_BLOCK)
		return 1; // 无法落脚
	if (!from_to(z0, x0, y0, x - x0, y - y0, MAP_BLOCK))
		return 1; // 无法穿越

	dx = (x / AREA_SIZE) - (x0 / AREA_SIZE);
	dy = (y / AREA_SIZE) - (y0 / AREA_SIZE);

	if (dx == 0 && dy == 0) // 本场景内行走
	{
		remove_block(z0, x0, y0, CHAR_BLOCK);
		set_x(me, x);
		set_y(me, y);
		set_d(me, d);
		set_block(z0, x, y, CHAR_BLOCK);

		user = get_scene_object(z0, x, y, USER_TYPE);
		send_user(user, "%c%d%d%w%w%w%w%c%c", 0x87, getoid(me), time2(), x0, y0, x, y, d, flag);

		me->set_no_fight(MAP_D->is_inside_safe_zone(z0, x, y) ? 1 : 0); // 安全区判断
	}
	else // 跨越场景行走
	{
		if (dx < 0)
		{
			if (dy < 0)
			{
				dx = 0x12e;
				dy = 0x1d2;
			}
			else if (dy > 0)
			{
				dx = 0x1e8;
				dy = 0x5e;
			}
			else
			{
				dx = 0x128;
				dy = 0x52;
			}
		}
		else if (dx > 0)
		{
			if (dy < 0)
			{
				dx = 0x5e;
				dy = 0x1e8;
			}
			else if (dy > 0)
			{
				dx = 0x1d2;
				dy = 0x12e;
			}
			else
			{
				dx = 0x52;
				dy = 0x128;
			}
		}
		else
		{
			if (dy < 0)
			{
				dx = 0xe;
				dy = 0x1c0;
			}
			else
			{
				dx = 0x1c0;
				dy = 0xe;
			}
		}

		remove_block(z0, x0, y0, CHAR_BLOCK); // 删除阻挡
		user = get_scene_object(z0, x0, y0, USER_TYPE, dx);

		set_x(me, x);
		set_y(me, y);
		set_d(me, d); // Thiết lập 坐标，增加阻挡
		set_block(z0, x, y, CHAR_BLOCK);
		objectp(who = me->get_owner()) && who->is_user() ? move_object(me, z0, x, y, USER_TYPE) : move_object(me, z0, x, y, CHAR_TYPE); // 移动 NPC
		user2 = get_scene_object(z0, x, y, USER_TYPE, dy);

		me->show_to_scene(user2, x0, y0, d, 0);
		user2 = get_scene_object_2(me, USER_TYPE) + user;
		send_user(user2, "%c%d%d%w%w%w%w%c%c", 0x87, getoid(me), time2(), x0, y0, x, y, d, flag);

		send_user(user, "%c%d", 0x78, getoid(me));

		if (MAP_D->is_inside_safe_zone(z0, x, y)) // 安全区判断
		{
			me->set_no_fight(1);
		}
		else
		{
			me->set_no_fight(0);

			if (objectp(me->get_owner()))
			{
				npc = get_range_object_2(me, 6, CHAR_TYPE);
				if (sizeof(npc))
					npc->init_heart_beat_idle();
			}
		}
	}
	if (objectp(who = me->get_owner()) && who->is_user())
	{
		if (get_z(who) != get_z(me))
		{
			send_user(who, "%c%c%d%w%w", 0x2c, 7, getoid(me), -1, -1); // 更新召唤兽坐标
			me->set_owner(0);
		}
		else
			send_user(who, "%c%c%d%w%w", 0x2c, 7, getoid(me), x, y); // 更新召唤兽坐标
	}

	if (get_effect(me, EFFECT_CHAR_CHAN))
		set_effect(me, EFFECT_CHAR_CHAN, 1); // 移除粘手效果

	return 1;
}
