#include <effect.h>
#include <map.h>
#include <ansi.h>
inherit ITEM;
inherit USABLE;

int main(object me, string arg)
{
	object who, item, item2, npc, map, map1, map2;
	int z, x, y, x0, y0, p;
	string arg1, arg2;
	string positionX;
	string positionY;
	int isExits;

	if (sscanf(arg, "%s.%s", arg1, arg2) != 2) return 1;
	if (arg1 == "?")			// 使用Thiên Lý Hữu Tình的人
	{
		item2 = present("Thiên Lý Hữu Tình", me, 1, MAX_CARRY);
		if (!item2) return 1;
		if (!(who = find_any_char(arg2)))
		{
			notify("Bạn đưa vào số ID ko có hiệu lực");
			return 1;
		}
		if (!who->is_user())
		{
			notify("Bạn đưa vào số ID ko phải người chơi");
			return 1;
		}
		if (me == who)
		{
			send_user(me, "%c%s", '!', "Không thể tự gọi chính mình");
			return 1;
		}
		if (!me->get_leader() || me->get_leader() != who->get_leader())
		{
			notify("Số ID bạn đưa vào không phải thành viên trong nhóm");
			return 1;
		}
		if (objectp(map = get_map_object(get_z(who))))
		{
			switch (map->get_map_type())
			{
				case BATTLE_MAP: send_user(me, "%c%s", '!', "Đối phương ở Chiến Trường, không thể truyền tống");
					return 1;
				/*case FIELD_MAP: send_user(me, "%c%s", '!', "Đối phương đang bận, không thể truyền tống");
					return 1;*/
			}

			if (map->get_id() == 888 || map->get_id() == 889 || map->get_id()== 375 || map->get_id()== 704) {
				send_user(me, "%c%s", '!', "Đối phương đang bận, không thể truyền tống");
				return 1;
			}

		}
		else return 1;

		if (objectp(map2 = get_map_object(get_z(me))))
		{
			switch (map2->get_map_type())
			{
				case BATTLE_MAP: send_user(me, "%c%s", '!', "Không thể sử dụng lúc này");
					return 1;
				/*case FIELD_MAP: send_user(me, "%c%s", '!', "Không thể sử dụng lúc này");
					return 1;*/
			}

			if (map2->get_id() == 888 || map2->get_id() == 889) {
				send_user(me, "%c%s", '!', "Không thể sử dụng lúc này");
				return 1;
			}
		}

		if (who->get_login_flag() < 3)
		{
			send_user(me, "%c%s", '!', "Đối phương còn chưa chuẩn bị");
			return 1;
		}
		if (who->is_die())
		{
			send_user(me, "%c%s", '!', "Đối phương đã chết");
			return 1;
		}
		if (who->is_store_open())
		{
			send_user(me, "%c%s", '!', "Đối phương đang bán hàng rong");
			return 1;
		}
		if (present("贵重物品", who, 1, MAX_CARRY * 4))
		{
			send_user(me, "%c%s", '!', "Nhau và với vật có giá trị。");
			return 1;
		}
		if (objectp(npc = who->get_quest("escort.robber#")) && npc->is_escort_robber())    // 寻找蒙面人
		{
			send_user(me, "%c%s", '!', "Chỉ cần gặp mỗi người đàn ông đeo mặt nạ khác。");
			return 1;
		}
		who->set("goto2_fly", me);
		/*send_user(who, "%c%s", ':', me->get_name() + " đang ở " + map->get_name() + " kêu gọi bạn đến bên cạnh, bạn muốn đến không ?\n"
			ESC "Đồng ý。\n" + sprintf("goto2byThienLy !.%d\n", me->get_number()) +
			ESC "Hủy bỏ。\nCLOSE\n");*/

		isExits = TASK_LEGEND_D->check_task_item_amount(me, "Thiên Lý Hữu Tình");
		if (isExits > 0) {

			if (TASK_LEGEND_D->check_task_item1(me, "Thiên Lý Hữu Tình", 1)) {
				send_user(who, "%c%s", ':', me->get_name() + "sử dụng Thiên Lý Hữu Tình kêu gọi bạn đến bên cạnh, bạn muốn đến không ?\n"
					ESC "Đồng ý.\n" + sprintf("goto2byThienLy !.%d\n", me->get_number()) +
					ESC "Hủy bỏ.\nCLOSE\n");

				write_user(me, ECHO "Bạn sử dụng" HIY "Thiên Lý Hữu Tình" ECHO ", xin chờ hồi đáp");

				who->set_save_2(sprintf("called.%d", me->get_number()), 1);
			}
		}
		

		return 1;
	}
	if (arg1 == "!")
	{
		if (!(who = find_any_char(arg2)))
		{
			return 1;
		}
		if (!who->is_user())
		{
			return 1;
		}
		if (me == who)
		{
			send_user(me, "%c%s", '!', "Không thể tự gọi chính mình");
			return 1;
		}
		if (me->get("goto2_fly") != who) return 1;
		if (!me->get_leader() || me->get_leader() != who->get_leader())
		{
			notify("Bạn không thể truyền tống đến chỗ đội hữu");
			return 1;
		}
		if (objectp(map = get_map_object(get_z(me))))
		{
			switch (map->get_map_type())
			{
				case BATTLE_MAP: send_user(me, "%c%s", '!', "Bạn ở Chiến Trường, không thể truyền tống");
					return 1;
			}
		}
		else return 1;
		if (objectp(map1 = get_map_object(get_z(who))))
		{
			if (map1->is_copy_scene())
			{
				send_user(me, "%c%s", '!', "Không thể truyền tống lúc đang trong Phó bản");
				return 1;
			}
		}
		else return 1;
		if (me->is_die())
		{
			return 1;
		}
		if (me->is_store_open())
		{
			send_user(me, "%c%s", '!', "Bạn đang bán hàng rong");
			return 1;
		}
		if (present("贵重物品", me, 1, MAX_CARRY * 4))
		{
			send_user(me, "%c%s", '!', "Bạn thực hiện với vật có giá trị。");
			return 1;
		}
		if (objectp(npc = me->get_quest("escort.robber#")) && npc->is_escort_robber())    // 寻找蒙面人
		{
			send_user(me, "%c%s", '!', "Bạn chỉ gặp những người đàn ông đeo mặt nạ。");
			return 1;
		}
		z = get_z(who);  x0 = get_x(who);  y0 = get_y(who);
		if (p = get_valid_xy(z, x0, y0, IS_CHAR_BLOCK))
		{
			x = p / 1000;  y = p % 1000;

			isExits = me->get_save_2(sprintf("called.%d", who->get_number()));

			if (isExits > 0) {

				me->set_save_2(sprintf("called.%d", who->get_number()), 0);

				me->set_login_flag(2);
				set_invisible(me, 1);
				set_effect(me, EFFECT_USER_LOGIN, 4);

				send_user(me, "%c%c%w%s", 0x5a, 0, 2, "Đang di chuyển……");
				me->set_2("travel.z", z);
				me->set_2("travel.p", p);
				me->set_2("travel.money", 0);

				set_effect(me, EFFECT_TRAVEL, 2);

			}
			

			/*me->set_login_flag(2);
			set_invisible(me, 1);
			set_effect(me, EFFECT_USER_LOGIN, 4);

			send_user(me, "%c%c%w%s", 0x5a, 0, 2, "Đang di chuyển……");
			me->set_2("travel.z", z);
			me->set_2("travel.p", p);
			me->set_2("travel.money", 0);

			set_effect(me, EFFECT_TRAVEL, 2);*/

			//tell_user(me, "Bạn đi đến: %d (%d, %d)", z, x, y);
			
			return 1;
		}
		else
		{
			if (who)
				notify("Bạn không tới được nơi %s .", who->get_name());
			else
				notify("Bạn không tới được nơi đó");
			return 1;
		}
	}
	return 1;
}
