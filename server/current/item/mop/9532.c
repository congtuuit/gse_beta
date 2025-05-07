
#include <ansi.h>
#include <map.h>
#include <effect.h>
#include <skill.h>

inherit TALISMAN;

int get_item_color() { return 2; }
int get_active_rate() { return 60; }

int get_talisman_type() { return 4; }
int is_sub_item() { return 1; }

void create()
{
	set_name("Linh Tê Hoàn");
	set_picid_1(9531);
	set_picid_2(9531);
	set_unit("个");

	set_level(2);
	set_value(1000);
	set_max_lasting(3099);

	set("dp", 100);
	set("pp", 100);
	set("hp", 300);

	setup();
}

// 函数：获取描述
string get_desc()
{
	return "Vật phẩm đặc biệt có thể triệu hồi người\nchơi khác đến bên cạnh bản thân.";
}

// 函数：可使用法宝
int is_usable_2() { return 1; }

// 函数：使用法宝效果
int get_use_effect_2(object me, object who, string arg) { return __FILE__->get_use_effect_2_callout(me, who, this_object(), arg); }

// 函数：使用法宝效果(在线更新)
int get_use_effect_2_callout(object me, object who, object item, string arg)    // 同步更改“神游”
{
	object map, * team, npc;
	string str1, str2;

	if (!arg || arg == "")
	{
		send_user(me, "%c%c%d%d%s", '?', 3, 0, me->get_save("fly"), "Bạn muốn triệu hồi ai đến ? Hãy nhập vào số ID :\n"
			ESC "pf2 00900.%s\n");
		return 1;
	}
	else
	{
		if (to_int(arg)) me->set_save("fly", to_int(arg));    // 记录前次飞的人

		if (!objectp(who = find_player(arg)))
		{
			send_user(me, "%c%s", '!', "Không tìm thấy người này.");
			return 1;
		}
		if (me == who)
		{
			send_user(me, "%c%s", '!', "Không thể tự triệu hồi chính mình.");
			return 1;
		}

		if (MAP_D->is_inside_city(get_z(me), get_x(me), get_y(me)))
		{
			send_user(me, "%c%s", ';', "Không thể sử dụng trong \"Thành\" !!!");
			return;
		}

		if (!((str1 = me->get_leader()) && (str2 = who->get_leader()) && str1 == str2)
			&& !((str1 = me->get_org_name()) && (str2 = who->get_org_name()) && str1 == str2))
		{
			send_user(me, "%c%s", '!', "Đối phương không phải thành viên trong nhóm hoặc bạn hữu.");
			return 1;
		}

		if (who->get_quest("escort.gold") > 0) {
			notify("Bạn không thể sử dụng lúc này.");
			return 0;
		}

		if (me->get_quest("escort.gold") > 0) {
			notify("Bạn không thể sử dụng lúc này.");
			return 0;
		}

		if (who->get_save_2("51cuanye.time"))
		{
			send_user(me, "%c%s", '!', "Đối phương đã nhận nhiệm vụ không thể truyền tống, không thể triệu hồi.");
			return 1;
		}
		if (who->get_no_fly())
		{
			send_user(me, "%c%s", '!', "Đối phương đã thiết lập cấm phi hành.");
			return 1;
		}
		if (MAP_D->is_inside_city(get_z(me), get_x(me), get_y(me)))
		{
			send_user(me, "%c%s", '!', "Không thể sủ dụng trong thành.");
			return 1;
		}
		if (MAP_D->is_inside_city(get_z(who), get_x(who), get_y(who)))
		{
			send_user(me, "%c%s", '!', "Đối phương đang ở trong thành, không thể sủ dụng Pháp bảo.");
			return 1;
		}
		if (objectp(map = get_map_object(get_z(me))))
		{
			switch (map->get_map_type())
			{
				case CAVE_MAP: send_user(me, "%c%s", '!', "Đối phương đang trong hang động,  không thể sử dụng Pháp bảo");
					return 1;
				case BATTLE_MAP: send_user(me, "%c%s", '!', "Đối phương đang trong Chiến Trường,  không thể sử dụng Pháp bảo");
					return 1;
			}

			if (map->get_id() == 888 || map->get_id() == 889 || map->get_id() == 375 || map->get_id() == 704) {
				send_user(me, "%c%s", '!', "Đối phương đang bận, không thể truyền tống");
				return 1;
			}
		}

		if (objectp(map = get_map_object(get_z(who))))
		{
			switch (map->get_map_type())
			{
			case CAVE_MAP: send_user(me, "%c%s", '!', "Đối phương đang trong hang động,  không thể sử dụng Pháp bảo");
				return 1;
			case BATTLE_MAP: send_user(me, "%c%s", '!', "Đối phương đang trong Chiến Trường,  không thể sử dụng Pháp bảo");
				return 1;
			}

			if (map->get_id() == 888 || map->get_id() == 889 || map->get_id() == 375 || map->get_id() == 704) {
				send_user(me, "%c%s", '!', "Đối phương đang bận, không thể truyền tống");
				return 1;
			}
		}


		if (who->get_login_flag() < 3)
		{
			send_user(me, "%c%s", '!', "Đối phương chưa sẵn sàng.");
			return 1;
		}
		if (who->is_die())
		{
			send_user(me, "%c%s", '!', "Đối phương đã chết.");
			return 1;
		}
		if (who->is_store_open())
		{
			send_user(me, "%c%s", '!', "Đối phương đang mở Cửa hàng bán rong.");
			return 1;
		}
		if (who->get_no_fight())
		{
			send_user(me, "%c%s", '!', "Đối phương đang ở khu vực an toàn.");
			return 1;
		}

		if (present("Tín Phiếu", who, 1, MAX_CARRY))
		{
			send_user(me, "%c%s", '!', "对方身上带着钱票。");
			return 1;
		}
		if (present("Báo vật", who, 1, MAX_CARRY * 4))
		{
			send_user(me, "%c%s", '!', "对方身上带着贵重物品。");
			return 1;
		}
		if (objectp(npc = who->get_quest("escort.robber#")) && npc->is_escort_robber())    // 寻找蒙面人
		{
			send_user(me, "%c%s", '!', "对方刚遇到蒙面人。");
			return 1;
		}


		if (arrayp(team = me->get("pending_fly")))
			me->set("pending_fly", team - ({ who, 0 }) + ({ who }));
		else    me->set("pending_fly", ({ who }));

		who->set("pending_fly", me);

		send_user(who, "%c%s", ':', me->get_name() + "Ngươi nhận được sự triệu hồi từ " HIY "Linh Tê Hoàn" NOR " của bằng hữu, ngươi muốn đến bên cạnh bằng hữu ngươi không ?\n"
			ESC "Chấp nhận\n" + sprintf("pf2 00903 %d\n", me->get_number()) +
			ESC "Không muốn\nCLOSE\n");
		write_user(me, ECHO "Bạn sử dụng " HIY "Linh Tê Hoàn" ECHO ", vui lòng chờ đối phương trả lời.");
	}

	return 1;
}

// 函数：接收法宝效果
int accept_use_effect_2(object me, object who) { return __FILE__->accept_use_effect_2_callout(me, who); }

// 函数：接收法宝效果(在线更新)
int accept_use_effect_2_callout(object me, object who)    // 同步更改“神游”
{
	object map, npc;
	string str1, str2;
	int z, x0, y0, x, y, p;

	if (me == who)
	{
		send_user(me, "%c%s", '!', "Không thể tự triệu hồi chính mình.");
		return 1;
	}
	/*        if( !( ( str1 = me->get_leader() ) && ( str2 = who->get_leader() ) && str1 == str2 )
			&&  !( ( str1 = me->get_org_name() ) && ( str2 = who->get_org_name() ) && str1 == str2 ) )
			{
					send_user( me, "%c%s", '!', "Đối phương không phải thành viên trong nhóm hoặc bạn hữu." );
					return 1;
			}
	*/
	if (who->get_no_fly())
	{
		send_user(me, "%c%s", '!', "Đối phương đã thiết lập cấm phi hành.");
		return 1;
	}
	if (MAP_D->is_inside_city(get_z(me), get_x(me), get_y(me)))
	{
		send_user(me, "%c%s", '!', "Không thể sủ dụng trong thành.");
		return 1;
	}
	if (MAP_D->is_inside_city(get_z(who), get_x(who), get_y(who)))
	{
		send_user(me, "%c%s", '!', "Đối phương đang ở trong thành, không thể sủ dụng Pháp bảo.");
		return 1;
	}
	if (objectp(map = get_map_object(get_z(me))))
	{
		switch (map->get_map_type())
		{
		case CAVE_MAP: send_user(me, "%c%s", '!', "Trong hang động không thể sử dụng Pháp bảo");
			return 1;
		case BATTLE_MAP: send_user(me, "%c%s", '!', "Trong Chiến Trường  không thể sử dụng Pháp bảo");
			return 1;
		}
	}
	if (objectp(map = get_map_object(get_z(who))))
	{
		switch (map->get_map_type())
		{
		case CAVE_MAP: send_user(me, "%c%s", '!', "Đối phương đang trong hang động,  không thể sử dụng Pháp bảo");
			return 1;
		case BATTLE_MAP: send_user(me, "%c%s", '!', "Đối phương đang trong Chiến Trường,  không thể sử dụng Pháp bảo");
			return 1;
		}
	}
	if (who->get_login_flag() < 3)
	{
		send_user(me, "%c%s", '!', "Đối phương chưa sẵn sàng.");
		return 1;
	}
	if (who->is_die())
	{
		send_user(me, "%c%s", '!', "Đối phương đã chết.");
		return 1;
	}
	if (who->is_store_open())
	{
		send_user(me, "%c%s", '!', "Đối phương đang mở Cửa hàng bán rong.");
		return 1;
	}
	if (who->get_no_fight())
	{
		send_user(me, "%c%s", '!', "Đối phương đang ở khu vực an toàn.");
		return 1;
	}

	if (present("钱票", who, 1, MAX_CARRY))
	{
		send_user(me, "%c%s", '!', "对方身上带着钱票。");
		return 1;
	}
	if (present("贵重物品", who, 1, MAX_CARRY * 4))
	{
		send_user(me, "%c%s", '!', "对方身上带着贵重物品。");
		return 1;
	}
	if (objectp(npc = who->get_quest("escort.robber#")) && npc->is_escort_robber())    // 寻找蒙面人
	{
		send_user(me, "%c%s", '!', "对方刚遇到蒙面人。");
		return 1;
	}

	z = get_z(me);  x0 = get_x(me);  y0 = get_y(me);

	if (p = get_valid_xy(z, x0, y0, IS_CHAR_BLOCK))
	{
		x = p / 1000;  y = p % 1000;
		who->add_to_scene(z, x, y, get_front_xy(x, y, x0, y0), 40971, 0, 40971, 0);
	}

	return 1;
}

void start_loop_perform(object me)
{
	CHAR_CHAR_D->init_loop_perform(me);
	send_user(get_scene_object_2(me, USER_TYPE), "%c%d%w%c%c%c", 0x6f, getoid(me), 9323, 1, UNDER_FOOT, PF_LOOP);
	me->add_to_scene(get_z(me), get_x(me), get_y(me), get_d(me));
}
void stop_loop_perform(object me)
{
	CHAR_CHAR_D->init_loop_perform(me);
	send_user(get_scene_object_2(me, USER_TYPE), "%c%d%w%c%c%c", 0x6f, getoid(me), 9323, 1, UNDER_FOOT, PF_STOP);
	me->add_to_scene(get_z(me), get_x(me), get_y(me), get_d(me));
}
