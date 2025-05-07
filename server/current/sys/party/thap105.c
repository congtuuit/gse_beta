#include <npc.h>
#include <ansi.h>
#include <cmd.h>
#include <effect.h>
#include <public.h>
#include <map.h>
#include <time.h>
#include <action.h>

#define MAP_ID 896
#define NUMBER_SCUM 20
#define NUMBER_MEM 2

#define MU_NUMBER 100
#define AO_NUMBER 100
#define HL_NUMBER 100
#define YD_NUMBER 100
#define GIAY_NUMBER 100

#define FILE_MAP    "map/copy/896"
#define FILE_SENDER "npc/event/tower/xaphu2"
#define FILE_GUAI    "npc/event/tower/scum_tower"
#define FILE_GUAI_2    "npc/event/tower/scum_tower_2"
#define FILE_BOSS    "npc/event/tower/boss"

#define DEBUG(who,arg) ;
#define DEBUG2(who,z,x,y);

inherit OFFICER;

object* Map;

int new_copy_scene(object who, object me);
int new_copy_npc(int z, int level);
int next_copy(object who, object me, int map_grade);
int  new_copy(object who, object me);
void do_fight(int sec, int z, int level, object who);
//int add_npc(int z,int x,int y,int level);

// 函数：生成二进制码
void SAVE_BINARY() { }

void delete_virtual_map(object map);
int add_npc(object who, int z, int x, int y, int level);
int add_boss(object who, int z, int x, int y, int level);
//int add_boss(int z,int x,int y,int level);

void create()
{
	Map = ({});
	setup();
}

int check_time() {

}

int open_ticket(object who) {


	return 0;
}

void do_look(object who, object me)
{
	string result;

	result = sprintf(me->get_name() + ":\nTầng càng cao tỉ lệ rơi trang bị giá trị càng cao...\n");
	result += sprintf(ESC "Tiến vào Phó bản\ntalk %x# welcome.1\n", getoid(me));
	result += sprintf(ESC HIY"%d mảnh ghép đổi Túi Huyết Long (Mũ)\ntalk %x# welcome.10\n", MU_NUMBER, getoid(me));
	result += sprintf(ESC HIY"%d mảnh ghép đổi Túi Huyết Long (Áo)\ntalk %x# welcome.11\n", AO_NUMBER, getoid(me));
	result += sprintf(ESC HIY"%d mảnh ghép đổi Túi Huyết Long (Hạng Liên)\ntalk %x# welcome.12\n", HL_NUMBER, getoid(me));
	result += sprintf(ESC HIY"%d mảnh ghép đổi Túi Huyết Long (Yêu Đới)\ntalk %x# welcome.13\n", YD_NUMBER, getoid(me));
	result += sprintf(ESC HIY"%d mảnh ghép đổi Túi Huyết Long (Giày)\ntalk %x# welcome.14\n", GIAY_NUMBER, getoid(me));
	result += sprintf(ESC "Rời khỏi");

	send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), result);
}

void do_look2(object who, object me)
{
	string result;

	result = sprintf(me->get_name() + ":\nNghe nói tầng cao nhất có rất nhiều trang bị giá trị...\n");
	result += sprintf(ESC HIC"Qua tầng kế tiếp...\ntalk %x# welcome.2\n", getoid(me));
	result += sprintf(ESC "Ta muốn rời Phó Bản\ntalk %x# welcome.3\n", getoid(me));
	result += sprintf(ESC "Rời khỏi");

	send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), result);
}

void do_welcome(object me, object who, string arg)
{
	int i, flag, size, x, y, z, p, tid, map_grade, iTime, member;
	int level = 0;
	string result;
	object map, * team, old_map, item;
	mixed* mixTime;

	who->set_time("time", 0);
	flag = to_int(arg);

	switch (flag)
	{
	case 1:

		iTime = time();
		mixTime = localtime(iTime);
		mixTime[TIME_WDAY];

		team = who->get_team();
		size = sizeof(team);
		if (!who->is_leader())
		{
			result = sprintf(me->get_name() + ":\n    Hãy gọi đội trưởng tới gặp ta !\n");
			result += sprintf(ESC"Rời khỏi");
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), result);
			return;
		}

		if (size < NUMBER_MEM)
		{
			result = sprintf(me->get_name() + ":\n    Lập tổ đội 2 người trở lên mới đi được !\n");
			result += sprintf(ESC"Rời khỏi");
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), result);
			return;
		}

		for (i = 0; i < size; i++)
		{
			if (!objectp(team[i])) continue;
			if (!inside_screen_2(me, team[i]))
			{
				result = sprintf(me->get_name() + ":\n    Hãy gọi tất cả thành viên đội ngươi tới đây !!\n");
				result += sprintf(ESC "Rời khỏi");
				send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), result);
				return;
			}

			if (team[i]->get_save_2("tower_105.today") == (mixTime[TIME_WDAY] + 1) && team[i]->get_save_2("tower_105.go") < 1) {
				send_user(team[i], "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf(" %s :\n Hôm nay bạn sử dụng hết lượt tham gia Phó Bản rồi\n"
					ESC"Thoát", me->get_name()));

				for (member = 0; member < sizeof(team); member++) {
					if (team[i]->get_number() == team[member]->get_number()) {
						continue;
					}
					send_user(team[member], "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf(" %s :\n Thành viên %s hôm nay đã hết lượt tham gia Phó Bản rồi.\n"
						ESC"Thoát", me->get_name(), team[i]->get_name()));
				}

				return;
			}

		}

		if (!new_copy(who, me) == 1) return;

		tid = who->get("team_id");
		map = TEAM_D->get_copy_scene(tid, COPY_GUMU);

		if (map)
		{
			z = map->get_id();
			x = 28; y = 30;
			if (!p = get_valid_xy(z, x, y, IS_CHAR_BLOCK)) return;
			x = (p % 1000000) / 1000;  y = p % 1000;
			for (i = 0; i < sizeof(team); i++)
			{
				if (team[i]->get_save_2("tower_105.today") == (mixTime[TIME_WDAY] + 1)) {
					if (team[i]->get_save_2("tower_105.go") < 1) {
						send_user(team[i], "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf(" %s :\n Hôm nay bạn sử dụng hết lượt tham gia Phó Bản rồi\n"
							ESC"Thoát", me->get_name()));
						continue;
					}
					else {
						team[i]->add_save_2("tower_105.go", -1);
						team[i]->set_save_2("tower_105.startAt", time());

						team[i]->set("me_die", 1);
						send_user(team[i], "%c%c%w%s", 0x5a, 0, 1, "Đang di chuyển……");
						team[i]->set_2("travel.z", z);
						team[i]->set_2("travel.p", p);
						team[i]->set("map", map);

						set_effect(team[i], EFFECT_TRAVEL, 1);

						if (is_god(team[i]))
						{
							DEBUG(team[i], sprintf("kiểm tra--do_look z=%d,level=%d", z, map->get("copy_level")));
						}
					}
				}
				else {
					team[i]->set_save_2("tower_105.today", (mixTime[TIME_WDAY] + 1));
					team[i]->set_save_2("tower_105.go", 0);
					team[i]->set_save_2("tower_105.startAt", time());

					team[i]->set("me_die", 1);
					send_user(team[i], "%c%c%w%s", 0x5a, 0, 1, "Đang di chuyển……");
					team[i]->set_2("travel.z", z);
					team[i]->set_2("travel.p", p);
					team[i]->set("map", map);

					set_effect(team[i], EFFECT_TRAVEL, 1);

					if (is_god(team[i]))
					{
						DEBUG(team[i], sprintf("kiểm tra--do_look z=%d,level=%d", z, map->get("copy_level")));
					}
				}

			}
		}
		break;

	case 2:
		team = who->get_team();
		size = sizeof(team);
		if (!who->is_leader())
		{
			result = sprintf(me->get_name() + ":\n    Hãy gọi đội trưởng tới gặp ta !\n");
			result += sprintf(ESC"Rời khỏi");
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), result);
			return;
		}

		if (size < NUMBER_MEM)
		{
			result = sprintf(me->get_name() + ":\n    Lập tổ đội 2 người trở lên mới đi được !\n");
			result += sprintf(ESC"Rời khỏi");
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), result);
			return;
		}

		for (i = 0; i < size; i++)
		{
			if (!objectp(team[i])) continue;
			if (!inside_screen_2(me, team[i]))
			{
				result = sprintf(me->get_name() + ":\n    Hãy gọi tất cả thành viên đội ngươi tới đây !!\n");
				result += sprintf(ESC "Rời khỏi");
				send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), result);
				return;
			}
		}


		old_map = get_map_object(get_z(who));

		if (old_map->get("busy") == 1) {
			notify("Chưa mở");
			return;
		}

		map_grade = old_map->get("map_grade");

		if (!next_copy(who, me, old_map->get("map_grade") + 1) == 1) return;

		tid = who->get("team_id");
		map = TEAM_D->get_copy_scene(tid, COPY_GUMU);

		if (map)
		{
			z = map->get_id();
			x = 28; y = 30;
			if (!p = get_valid_xy(z, x, y, IS_CHAR_BLOCK)) return;
			x = (p % 1000000) / 1000;  y = p % 1000;
			for (i = 0; i < sizeof(team); i++)
			{
				notify(sprintf(HIY"Tiến vào tầng %d", map_grade + 1));
				team[i]->set("me_die", 2);

				/*send_user(team[i], "%c%c%w%s", 0x5a, 0, 0, "Đang di chuyển……");
				team[i]->set_2("travel.z", z);
				team[i]->set_2("travel.p", p);*/

				team[i]->set_login_flag(2);
				set_invisible(team[i], 1);
				set_effect(team[i], EFFECT_USER_LOGIN, 4);
				team[i]->add_to_scene(map->get_id(), x, y);

				team[i]->set("map", map);

				set_effect(team[i], EFFECT_TRAVEL, 0);
			}


			//delete map
			//call_out("delete_virtual_map", 10, old_map);
		}
		break;
	case 3:
		result = sprintf(me->get_name() + ":\nNgươi muốn rời Phó bản phải không?\n");
		result += sprintf(ESC "Đồng ý\ntalk %x# welcome.4\n", getoid(me));
		result += sprintf(ESC "Rời khỏi");
		send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), result);
		break;
	case 4:
		who->set_login_flag(2);
		set_invisible(who, 1);
		set_effect(who, EFFECT_USER_LOGIN, 4);
		who->add_to_scene(080, 290, 171);
		who->set_save("tower.oldZ", 0);
		who->set_save("tower.timeout", 0);
		break;
	case 10:

		if (TASK_LEGEND_D->check_task_item_amount(who, "Mảnh Ghép Huyết Long") < MU_NUMBER)
		{
			notify("Vật phẩm không đủ");
			return;
		}

		if (USER_INVENTORY_D->get_free_count(who) < 1)
		{
			notify("Hành trang không đủ 1 chỗ trống");
			return;
		}

		TASK_LEGEND_D->check_task_item1(who, "Mảnh Ghép Huyết Long", MU_NUMBER);

		item = new("npc/event/tower/item/mu");
		p = item->move2(who, -1);
		item->add_to_user(p);
		send_user(who, "%c%s", ';', sprintf("Chúc mừng bạn nhận được "HIY"%s", item->get_name()));
		break;
	case 11:

		if (TASK_LEGEND_D->check_task_item_amount(who, "Mảnh Ghép Huyết Long") < AO_NUMBER)
		{
			notify("Vật phẩm không đủ");
			return;
		}

		if (USER_INVENTORY_D->get_free_count(who) < 1)
		{
			notify("Hành trang không đủ 1 chỗ trống");
			return;
		}

		TASK_LEGEND_D->check_task_item1(who, "Mảnh Ghép Huyết Long", AO_NUMBER);

		item = new("npc/event/tower/item/ao");
		p = item->move2(who, -1);
		item->add_to_user(p);
		send_user(who, "%c%s", ';', sprintf("Chúc mừng bạn nhận được "HIY"%s", item->get_name()));
		break;
	case 12:

		if (TASK_LEGEND_D->check_task_item_amount(who, "Mảnh Ghép Huyết Long") < HL_NUMBER)
		{
			notify("Vật phẩm không đủ");
			return;
		}

		if (USER_INVENTORY_D->get_free_count(who) < 1)
		{
			notify("Hành trang không đủ 1 chỗ trống");
			return;
		}

		TASK_LEGEND_D->check_task_item1(who, "Mảnh Ghép Huyết Long", HL_NUMBER);

		item = new("npc/event/tower/item/hl");
		p = item->move2(who, -1);
		item->add_to_user(p);
		send_user(who, "%c%s", ';', sprintf("Chúc mừng bạn nhận được "HIY"%s", item->get_name()));
		break;
	case 13:

		if (TASK_LEGEND_D->check_task_item_amount(who, "Mảnh Ghép Huyết Long") < YD_NUMBER)
		{
			notify("Vật phẩm không đủ");
			return;
		}

		if (USER_INVENTORY_D->get_free_count(who) < 1)
		{
			notify("Hành trang không đủ 1 chỗ trống");
			return;
		}

		TASK_LEGEND_D->check_task_item1(who, "Mảnh Ghép Huyết Long", YD_NUMBER);
		item = new("npc/event/tower/item/yd");
		p = item->move2(who, -1);
		item->add_to_user(p);
		send_user(who, "%c%s", ';', sprintf("Chúc mừng bạn nhận được "HIY"%s", item->get_name()));
		break;
	case 14:

		if (TASK_LEGEND_D->check_task_item_amount(who, "Mảnh Ghép Huyết Long") < GIAY_NUMBER)
		{
			notify("Vật phẩm không đủ");
			return;
		}

		if (USER_INVENTORY_D->get_free_count(who) < 1)
		{
			notify("Hành trang không đủ 1 chỗ trống");
			return;
		}

		TASK_LEGEND_D->check_task_item1(who, "Mảnh Ghép Huyết Long", GIAY_NUMBER);

		item = new("npc/event/tower/item/giay");
		p = item->move2(who, -1);
		item->add_to_user(p);
		send_user(who, "%c%s", ';', sprintf("Chúc mừng bạn nhận được "HIY"%s", item->get_name()));
		break;
	}

}

int new_copy_scene(object who, object me)
{
	int z, d, tid, i, size;
	object map, npc, * team;
	d = MAP_ID;
	tid = who->get_team_id();
	if (!tid)return 0;
	team = who->get_team();
	size = sizeof(team);
	z = COPY_CTROL->new_scene(d, FILE_MAP, "Phá Thiên Tháp");
	if (!z) return 0;
	if (!objectp(map = get_map_object(z)) || !map->is_virtual_scene())
		return 0;

	TEAM_D->add_copy_scene(tid, COPY_GUMU, map);

	map->set("copy_id", 1);
	map->set("gumu_map", 1);
	Map += ({ map });

	npc = new(FILE_SENDER);
	if (!npc) return 0;
	//npc->add_to_scene(z, 25, 29, 3);
	npc->add_to_scene(z, 40, 30, 3);

	for (i = 0; i < size; i++)
	{
		team[i]->set("team_id", tid);
		team[i]->set_save("tower.oldZ", z);
		team[i]->set_save("tower.timeout", time() + 60);
		map->set_owner(team[i]);
	}

	return z;
}

void do_fight(int sec, int z, int level, object who)
{
	int p, x, y, i, map_level, rate, type, old_level, size;
	object npc, map, * member;
	int each_level = 5;

	p = MAP_ID;

	if (!who && !get_z(who)) {
		return;
	}

	map = get_map_object(get_z(who));
	map->set("busy", 1);

	sec--;
	if (sec > 0)
	{
		member = "inh/std/scum_map"->get_all_user(map);
		member -= ({ 0 });
		size = sizeof(member);

		for (i = 0; i < size; i++)
		{
			if (get_z(member[i]) != z)
				continue;
			tell_user(member[i], ECHO"Tháp Thủ vệ xuất hiện sau %d giây, mời chuẩn bị ứng chiến!", sec);
		}

		call_out("do_fight", 1, sec, z, level, who);
	}
	else
	{
		if (map->get("map_grade") < 1) {
			map->set("map_grade", 1);
		}
		map_level = map->get("map_grade");

		if (map_level % each_level == 0) {
			for (i = 0; i < 1; i++)
			{
				type = random(4) + 1;
				npc = new(FILE_BOSS);
				npc->set_level(level - 15);
				NPC_ENERGY_D->init_level(npc, level);

				npc->set_max_hp((map_level) * 8000);
				npc->add_max_mp((map_level) * 10000);
				npc->set_ap((level * 2) + map_level * 100);
				npc->set_cp((level * 2) + map_level * 200);

				if (!(p = efun::get_xy_point(MAP_ID, IS_CHAR_BLOCK)))
					continue;

				x = (p % 1000000) / 1000;  y = p % 1000;
				npc->set_fight_status(type, level);
				npc->add_to_scene(z, x, y);

			}
		}
		else {
			for (i = 0; i < NUMBER_SCUM; i++)
			{
				npc = new(FILE_GUAI);
				npc->set_level(level);
				NPC_ENERGY_D->init_level(npc, level);
				npc->set_max_hp((map_level + 1) * 3500);
				npc->set_ap((level * 5) + map_level * 50);

				if (random(100) < 25) {
					npc->set_sp(level*30);
				}

				if (map_level > 6) {
					npc->set_attack_speed(5);
				}
				else {
					npc->set_attack_speed(map_level);
				}

				if (!(p = efun::get_xy_point(MAP_ID, IS_CHAR_BLOCK)))
					continue;
				x = (p % 1000000) / 1000;  y = p % 1000;

				npc->add_to_scene(z, x, y);
			}

			for (i = 0; i < NUMBER_SCUM; i++)
			{
				npc = new(FILE_GUAI_2);
				npc->set_level(level);
				NPC_ENERGY_D->init_level(npc, level);
				npc->set_max_hp((map_level + 1) * 3500);
				npc->set_ap((level * 5) + map_level * 70);
				npc->set_cp((level * 5) + map_level * 100);

				if (random(100) < 35) {
					npc->set_sp(level * 35);
				}

				if (map_level > 6) {
					npc->set_attack_speed(5);
				}
				else {
					npc->set_attack_speed(map_level);
				}

				if (!(p = efun::get_xy_point(MAP_ID, IS_CHAR_BLOCK)))
					continue;
				x = (p % 1000000) / 1000;  y = p % 1000;

				npc->add_to_scene(z, x, y);
			}

			map->set("copy_npc_amount", NUMBER_SCUM*2);
			map->set("copy_npc_die", 0);
		}
		
	}
}

//Add NPC
int new_copy_npc(int z, int level)
{
	int key, * xy, ap, hp,x,y,p;
	object map, npc;

	//do_fight(10, z, level, who);

	//if (!objectp(map = get_map_object(z)) || !map->is_virtual_scene())
	//	return 0;
	//npc = new(FILE_GUAI);
	//if (!npc) return 0;
	//npc->set_level(level);
	//NPC_ENERGY_D->init_level(npc,level);

	////	npc->set_fight_status(level);
	////	npc->set_name(sprintf("Thủ Mộ Thạch Dũng %d ",key));
	////npc->add_to_scene(z, xy[0], xy[1], 3);

	////x = p / 1000, y = p % 1000;
	////npc->set("f_z", z);
	////npc->set("f_x", x);
	////npc->set("f_y", y);

	////npc->do_fight(16);

	//map->set("copy_npc_sum", 50);
	//map->add("copy_npc_count", 1);

	///*if (!(p = efun::get_xy_point(MAP_ID, IS_CHAR_BLOCK)))
	//	continue;
	//x = (p % 1000000) / 1000;  y = p % 1000;*/
	//npc->add_to_scene(z, 028, 030);

	return 1;
}

int new_copy(object who, object me)
{
	int i, tid, size, z;
	int level = 0;
	object* team, map;
	tid = who->get_team_id();
	if (!tid) return 0;
	if (!team = who->get_team()) return 0;
	for (i = 0, size = sizeof(team); i < size; i++)
		level += team[i]->get_level();
	level = level / size;

	if (level != 60) {
		level = 60;
	}

	z = new_copy_scene(who, me);
	if (!z) return 0;
	if (!objectp(map = get_map_object(z)) || !map->is_virtual_scene())
		return 0;
	if (!new_copy_npc(z, level)) return 0;

	do_fight(10,z,level,who);
	map->set("copy_level", level);
	map->set("map_grade", 1);
	return 1;
}

int next_copy(object who, object me, int map_grade)
{
	int i, tid, size, z, mapLevel;
	int level = 0;
	object* team, map, old_map;
	tid = who->get_team_id();
	if (!tid) return 0;
	if (!team = who->get_team()) return 0;
	for (i = 0, size = sizeof(team); i < size; i++)
		level += team[i]->get_level();
	level = level / size;

	old_map = get_map_object(get_z(who));

	if (level != 60) {
		level = old_map->get("copy_level");
	}

	mapLevel = level + 5;

	z = new_copy_scene(who, me);
	if (!z) return 0;
	if (!objectp(map = get_map_object(z)) || !map->is_virtual_scene())
		return 0;
	if (!new_copy_npc(z, mapLevel)) return 0;

	if (!who && !get_z(who)) {
		return 0;
	}

	do_fight(10, z, mapLevel, who);
	map->set("copy_level", mapLevel);
	map->set("map_grade", map_grade);

	//delete map
	//call_out("delete_virtual_map", 10, old_map);

	return 1;
}

void npc_die(object who, object me)
{
	int z, level, key, * xy, i, size, count, tid;
	string result;
	object map, * team = ({});

	team = who->get_team();
	if (!team) team = ({ who });
	size = sizeof(team);
	tid = who->get("team_id");
	map = who->get("map");
	//	map=TEAM_D->get_copy_scene(tid,COPY_GUMU);
	if (!map) return;
	z = map->get_id();
	level = map->get("copy_level");
	map->add("kill_npc_count", 1);
	key = map->get("kill_npc_count");
	count = map->get("copy_npc_count");
	for (i = 0; i < size; i++)
	{
		send_user(team[i], "%c%s", '!', sprintf("Đã giết được："HIY" %d/50", key));
	}
	
	if (count == 50)
	{
		
		for (i = 0; i < size; i++)
		{
			send_user(team[i], "%c%s", '!', HIY"Đông Phương Bất Bại đã xuất hiện !!!!");
		}
		
		//__FILE__->add_boss(who, z, xy[0], xy[1], level);
	}

}

void delete_virtual_map(object map) {
	COPY_MAP->destruct_virtual_map(map, map->get_id());
}

int add_npc(object who, int z, int x, int y, int level) //加入小怪
{
	int ap, hp, i, size, tid;
	object map, npc, * team;

	//who=this_player();
	tid = who->get("team_id");
	DEBUG(who, "add_npc test");
	//if(!map=TEAM_D->get_copy_scene(tid,COPY_GUMU)) return;
	if (!map = who->get("map")) return;
	if (!(map->get("copy_npc_count") <= map->get("copy_npc_sum")))
	{
		send_user(who, "%c%s", '!', HIY"Đông Phương Bất Bại đã xuất hiện !!!!");
		return;
	}
	npc = new(FILE_GUAI);
	if (!npc) return 0;
	npc->set_level(level);
	//	NPC_ENERGY_D->init_level(npc,level);
	npc->set_fight_status(level);
	map->add("copy_npc_count", 1);
	//npc->set_name(sprintf("Thủ Mộ Thạch Dũng %d ",map->get("copy_npc_count")));	//用于测试
	npc->add_to_scene(z, x, y, 3);
	return 1;
}

//int new_scene(int d, string mapname,string name) //新增副本场景
//{
//	int z;
//	object map;
//	if( ( z = find_map_flag(COPY_MAP_BEGIN, COPY_MAP_END, 0) ) > 0 )
//	{
//		init_virtual_map(z, d);
//		map = new(mapname);
//		if(!map) return;
//		map->set_client_id(d);
//		map->set("gumu_map",1);
//		set_map_object( map, map->set_id(z) );
//		Map+=({map});
//	}
//	return z;
//}

int add_boss(object who, int z, int x, int y, int level)  //加入大boss
{
	int ap, hp, rate, type, tid;
	object map, npc;
	//who=this_player();
	tid = who->get("team_id");
	//if(!map=TEAM_D->get_copy_scene(tid,COPY_GUMU)) return;
	if (!map = who->get("map")) return;
	rate = random100();
	npc = new(FILE_BOSS);
	if (!npc) return;
	/*	if(rate<20)      type=1;
		else if(rate<40) type=2;
		else if(rate<60) type=3;
		else if(rate<70) type=4;
		else if(rate<90) type=5;
		else type=6;*/

	npc->set_level(level);
	//	NPC_ENERGY_D->init_level(npc,level);
	//	npc->set_fight_status(type,level);
	npc->add_to_scene(z, x, y, 3, 9413);
	return 1;
}

//24:00时退出还在古墓的所有玩家
void player_exit()
{
	int i, j, size1, size2, x, y, z, p;
	object* member;
	x = 320; y = 124; z = 80;
	if (!Map) return;
	size1 = sizeof(Map);
	for (i = 0; i < size1; i++)
	{
		member = FILE_MAP->get_all_user(Map[i]);
		if ((size2 = sizeof(member)) < 1) continue;
		for (j = 0; j < size2; j++)
		{
			if (!p = get_valid_xy(z, x, y, IS_CHAR_BLOCK)) return;
			x = (p % 1000000) / 1000;  y = p % 1000;
			send_user(member[j], "%c%s", '!', HIY"Ngươi đã vượt qua thời gian đi Phó Bản, vì vậy ngươi bị Đông Phương Bất Bại dùng chưởng lực đánh bay ra khỏi Phó Bản !");
			call_out("send_player", 3, member[j]);
		}
	}
}

void send_player(object who)
{
	int x, y, z, p;
	z = 80; x = 320; y = 124;
	if (!p = get_valid_xy(z, x, y, IS_CHAR_BLOCK)) return;
	x = (p % 1000000) / 1000;  y = p % 1000;
	who->add_to_scene(z, x, y);
}

object* delete_map(object map)
{
	Map -= ({ map });
	return Map;
}
