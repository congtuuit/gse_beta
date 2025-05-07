#include <npc.h>
#include <ansi.h>
#include <cmd.h>
#include <effect.h>
#include <public.h>
#include <map.h>
#include <time.h>
#include <action.h>
#include <equip.h>

#define MAP_ID 896
#define NUMBER_SCUM 20
#define NUMBER_MEM 1

#define MAX_TOWER 10

#define FILE_MAP    "map/copy/896"
#define FILE_SENDER "npc/event/tower/xaphu_2_chiton"
#define FILE_GUAI    "npc/event/tower/scum_tower"
#define FILE_GUAI_2    "npc/event/tower/scum_tower_2"
#define FILE_BOSS    "npc/copy/thongthienthapboss"

inherit DBASE_F;
inherit SAVE_F;

static object* Map = ({});
static string* nFamily = ({ "Đào Hoa Nguyên","Thục Sơn","Cấm Vệ Quân","Đường Môn","Mao Sơn","Côn Luân","Vân Mộng Cốc" });

int new_copy_scene(object who, object me);
int new_copy_npc(int z, int level);
int next_copy(object who, object me, int map_grade);
int  new_copy(object who, object me);
void do_fight(int sec, int z, int level, object who);
void delete_virtual_map(object map);
int add_npc(object who, int z, int x, int y, int level);

void add_boss(int z, int level, int floor);
void fresh_data(object me);
void time_out(object map);
void update_data(object player, int floor);
void view_data(object me);

object* delete_map(object map);

void SAVE_BINARY() { }
string get_save_file() { return "data/ThapChiTon"SAVE_EXTENSION; }

void create()
{
	restore();
}

void do_look(object who, object me)
{
	string result;
	int z, status, iTime;
	object map;
	mixed* mixTime;

	iTime = time();
	mixTime = localtime(iTime);

	z = who->get_save_2("thap.z");

	result = sprintf(me->get_name() + ":\nTháp Chí Tôn, ngươi có bản lĩnh đánh bại và chinh phục không?\n");
	
	if (z != 0 && map = get_map_object(z) && status = who->get_save_2("thap.status") != 0 && who->get_save_2("tower_power.today") == (mixTime[TIME_WDAY] + 1)) {
		result += sprintf(ESC HIC"Tiếp tục khiêu chiến\ntalk %x# welcome.11\n", getoid(me));
	}
	
	result += sprintf(ESC "Khiêu chiến\ntalk %x# welcome.1\n", getoid(me));

	result += sprintf(ESC "Ta chỉ ghé xem qua thôi.");

	send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), result);
}

void do_look2(object who, object me)
{
	string result;

	result = sprintf(me->get_name() + ":\nTháp Chí Tôn, ngươi có bản lĩnh đánh bại và chinh phục không?\n");
	result += sprintf(ESC HIC"Tầng kế tiếp...\ntalk %x# welcome.2\n", getoid(me));
	result += sprintf(ESC "Về thành\ntalk %x# welcome.3\n", getoid(me));
	result += sprintf(ESC "Hủy");

	send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), result);
}

void do_welcome(object me, object who, string arg)
{
	int i, flag, size, x, y, z, p, tid, map_grade, iTime, member, mapLevel, status;
	int level = 0;
	string result;
	object map, * team, old_map, item;
	mixed* mixTime;

	who->set_time("time", 0);
	flag = to_int(arg);

	switch (flag)
	{
	case 270596:
		fresh_data(who);
		break;
	case 2705:
		view_data(who);
		break;
	case 11:
		team = who->get_team();
		size = sizeof(team);

		if (!who->is_leader())
		{
			result = sprintf(me->get_name() + ":\n    Hãy gọi đội trưởng tới gặp ta !\n");
			result += sprintf(ESC"Rời khỏi");
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), result);
			return;
		}

		if (size > NUMBER_MEM)
		{
			result = sprintf(me->get_name() + ":\n    Chỉ có thể tham gia đơn lẻ !\n");
			result += sprintf(ESC"Rời khỏi");
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), result);
			return;
		}

		z = who->get_save_2("thap.z");
		if (z != 0 && map = get_map_object(z) && status = who->get_save_2("thap.status") != 0) {
			x = who->get_save_2("thap.x");
			y = who->get_save_2("thap.y");
			set_effect(who, EFFECT_USER_LOGIN, 2);
			who->add_to_scene(z, x, y);
		}

		break;
	case 1:

		iTime = time();
		mixTime = localtime(iTime);

		team = who->get_team();
		size = sizeof(team);

		//who->delete_save_2("tower_power");

		//"sys/party/thapchiton"->debug_thap(who);


		/*if (size == 0) {
			"cmd/base/team"->main(who, sprintf("+ %d", who->get_number()));
			size = sizeof(team);
		}*/

		if (!who->is_leader())
		{
			result = sprintf(me->get_name() + ":\n    Hãy gọi đội trưởng tới gặp ta !\n");
			result += sprintf(ESC"Rời khỏi");
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), result);
			return;
		}

		if (size > NUMBER_MEM)
		{
			result = sprintf(me->get_name() + ":\n    Chỉ có thể tham gia đơn lẻ !\n");
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

			if (team[i]->get_save_2("tower_power.today") != (mixTime[TIME_WDAY] + 1)) {
				team[i]->set_save_2("tower_power.go", 0);
			}

			if (team[i]->get_save_2("tower_power.today") == (mixTime[TIME_WDAY] + 1) && team[i]->get_save_2("tower_power.go") >= 3) {
				send_user(team[i], "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf(" %s :\n Hôm nay bạn sử dụng hết lượt tham gia rồi\n"
					ESC"Thoát", me->get_name()));

				for (member = 0; member < sizeof(team); member++) {
					if (team[i]->get_number() == team[member]->get_number()) {
						continue;
					}
					send_user(team[member], "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf(" %s :\n Thành viên %s hôm nay đã hết lượt tham gia rồi.\n"
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

			map->set("floor", 1);

			//Setup pos in map
			who->set_save_2("thap.status", 1);
			who->set_save_2("thap.z", get_z(who));
			who->set_save_2("thap.x", get_x(who));
			who->set_save_2("thap.y", get_y(who));


			for (i = 0; i < sizeof(team); i++)
			{
				if (team[i]->get_save_2("tower_power.today") == (mixTime[TIME_WDAY] + 1)) {
					if (team[i]->get_save_2("tower_power.go") >= 3) {
						send_user(team[i], "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf(" %s :\n Hôm nay bạn sử dụng hết lượt tham gia rồi\n"
							ESC"Thoát", me->get_name()));
						continue;
					}
					else {
						team[i]->add_save_2("tower_power.go", 1);
						
						team[i]->set("me_die", 1);
						send_user(team[i], "%c%c%w%s", 0x5a, 0, 1, "Đang di chuyển……");
						team[i]->set_2("travel.z", z);
						team[i]->set_2("travel.p", p);
						team[i]->set("map", map);
						team[i]->set("map_level", 1);

						set_effect(team[i], EFFECT_TRAVEL, 1);
					}
				}
				else {
					team[i]->set_save_2("tower_power.today", (mixTime[TIME_WDAY] + 1));
					team[i]->add_save_2("tower_power.go", 1);
					
					team[i]->set("me_die", 1);
					send_user(team[i], "%c%c%w%s", 0x5a, 0, 1, "Đang di chuyển……");
					team[i]->set_2("travel.z", z);
					team[i]->set_2("travel.p", p);
					team[i]->set("map", map);
					team[i]->set("map_level", 1);

					set_effect(team[i], EFFECT_TRAVEL, 1);
				}

			}


		}

		break;

	case 2:
		team = who->get_team();
		size = sizeof(team);

		if (size == 0) {
			"cmd/base/team"->main(who, sprintf("+ %d", who->get_number()));
			size = sizeof(team);
		}

		if (!who->is_leader())
		{
			result = sprintf(me->get_name() + ":\n    Hãy gọi đội trưởng tới gặp ta !\n");
			result += sprintf(ESC"Rời khỏi");
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), result);
			return;
		}

		if (size > NUMBER_MEM)
		{
			result = sprintf(me->get_name() + ":\n    Chỉ có thể tham gia đơn lẻ !\n");
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
		if (!old_map) return;

		if (old_map->get("busy") == 1) {
			notify("Chưa mở");
			return;
		}

		mapLevel = old_map->get("floor") + 1;

		if (mapLevel > MAX_TOWER) {
			notify("Hiện tại đã là tầng cao nhất rồi!");
			return;
		}

		if (!next_copy(who, me, mapLevel) == 1) return;

		tid = who->get("team_id");
		map = TEAM_D->get_copy_scene(tid, COPY_GUMU);

		if (map)
		{
			z = map->get_id();
			x = 28; y = 30;
			if (!p = get_valid_xy(z, x, y, IS_CHAR_BLOCK)) return;
			x = (p % 1000000) / 1000;  y = p % 1000;

			//Setup pos in map
			who->set_save_2("thap.status", 1);
			who->set_save_2("thap.z", z);
			who->set_save_2("thap.x", x);
			who->set_save_2("thap.y", y);

			for (i = 0; i < sizeof(team); i++)
			{
				notify(sprintf(HIY"Tiến vào tầng %d", mapLevel));
				team[i]->set("me_die", 2);

				team[i]->set_login_flag(2);
				set_invisible(team[i], 1);
				set_effect(team[i], EFFECT_USER_LOGIN, 2);

				
				team[i]->add_to_scene(z, x, y);
				team[i]->set("map", map);
				team[i]->set("map_level", mapLevel);
			}

			map->set("floor", mapLevel);
			//delete map
			call_out("time_out", 15 * 60, map);

			delete_map(old_map);
		}

		break;
	case 3:
		result = sprintf(me->get_name() + ":\nNgươi muốn rời Phó bản phải không? Hệ thống sẽ lưu lại chiến thắng của bạn ở tầng %d.\n", who->get_save("thapchitonowner"));
		result += sprintf(ESC "Đồng ý\ntalk %x# welcome.4\n", getoid(me));
		result += sprintf(ESC "Rời khỏi");
		send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), result);
		break;
	case 4:

		/*if (is_player(who) && who->get_save("thapchitonowner") != 0) {
			update_data(who, who->get_save("thapchitonowner"));
		}*/

		who->set_login_flag(2);
		set_invisible(who, 1);
		set_effect(who, EFFECT_USER_LOGIN, 2);
		map = get_map_object(get_z(who));
		who->delete_save_2("thap");
		time_out(map);

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
	z = COPY_CTROL->new_scene(d, FILE_MAP, "Thông Thiên Tháp");
	if (!z) return 0;
	if (!objectp(map = get_map_object(z)) || !map->is_virtual_scene())
		return 0;

	TEAM_D->add_copy_scene(tid, COPY_GUMU, map);

	map->set("copy_id", 1);
	map->set("gumu_map", 1);

	Map += ({ map });

	npc = new(FILE_SENDER);
	if (npc) {
		npc->add_to_scene(z, 25, 29, 3);
	}

	for (i = 0; i < size; i++)
	{
		team[i]->set("team_id", tid);
		map->set_owner(team[i]);
	}

	return z;
}

void time_out(object map) {
	delete_map(map);
	return;
}

int get_type_boss(string familyName) {
	int type = 1;
	switch (familyName)
	{
	case "Đào Hoa Nguyên":
		type = 1;
		break;
	case "Thục Sơn":
		type = 2;
		break;
	case "Cấm Vệ Quân":
		type = 3;
		break;
	case "Đường Môn":
		type = 4;
		break;
	case "Côn Luân":
		type = 5;
		break;
	case "Mao Sơn":
		type = 6;
		break;
	case "Vân Mộng Cốc":
		type = 7;
		break;
	}

	return type;

}

void add_boss(int z, int level, int floor) {
	int i, type, p, x, y, newLevel;
	int ap, cp, dp, hp, pp, gender, hair, pLevel;
	string pName, familyName;
	object npc;

	if (!get_save_2("towerFloor")) {
		for (i = 0; i < 1; i++)
		{
			type = random(7) + 1;

			npc = new(FILE_BOSS);

			npc->set_name(sprintf("Thủ Vệ"));


			newLevel = (level + (floor * 5));
			if (newLevel >= 120) {
				newLevel = 120;
			}

			npc->set_level(newLevel);
			NPC_ENERGY_D->init_level(npc, newLevel);

			npc->add_max_hp(100000);
			npc->add_max_mp(100000);

			npc->add_ap(npc->get_ap() * 5);
			npc->add_cp(npc->get_cp() * 5);
			npc->add_dp(npc->get_dp() * 5);
			npc->add_pp(npc->get_pp() * 5);

			if (!(p = efun::get_xy_point(MAP_ID, IS_CHAR_BLOCK)))
				continue;

			x = (p % 1000000) / 1000;  y = p % 1000;

			npc->set_fight_status(type, level, 0, random(4) + 1);

			npc->add_to_scene(z, x, y);
		}

	}
	else {

		pName = get_save_2(sprintf("towerFloor.%d.pname", floor));
		familyName = get_save_2(sprintf("towerFloor.%d.family", floor));
		pLevel = get_save_2(sprintf("towerFloor.%d.level", floor));
		gender = get_save_2(sprintf("towerFloor.%d.gender", floor));
		hair = get_save_2(sprintf("towerFloor.%d.hair", floor));

		hp = get_save_2(sprintf("towerFloor.%d.hp", floor));
		ap = get_save_2(sprintf("towerFloor.%d.ap", floor));
		cp = get_save_2(sprintf("towerFloor.%d.cp", floor));
		dp = get_save_2(sprintf("towerFloor.%d.dp", floor));
		pp = get_save_2(sprintf("towerFloor.%d.pp", floor));


		for (i = 0; i < 1; i++)
		{
			type = get_type_boss(familyName);
			npc = new(FILE_BOSS);

			npc->set_name(sprintf(HIY"%s", pName));

			newLevel = (level + (floor * 3));
			if (newLevel >= 120) {
				newLevel = 120;
			}

			npc->set_level(newLevel);
			NPC_ENERGY_D->init_level(npc, newLevel);

			npc->add_max_hp(hp * 2 + (floor * 12000));
			npc->add_max_mp(hp * 5);

			npc->set_ap((ap + cp) / 3);
			npc->set_cp((ap + cp) / 3);

			npc->add_dp(dp/2);
			npc->add_pp(pp/2);

			if (!(p = efun::get_xy_point(MAP_ID, IS_CHAR_BLOCK)))
				continue;

			x = (p % 1000000) / 1000;  y = p % 1000;

			gender = gender - 1;

			if (gender < 0) {
				gender = 0;
			}

			npc->set_fight_status(type, level, gender, hair);

			npc->add_to_scene(z, x, y);
		}

	}

}

void do_fight(int sec, int z, int level, object who)
{
	int p, x, y, i, map_level, rate, type, old_level, size;
	object npc, map, * member;
	int each_level = 5;

	p = MAP_ID;

	map = get_map_object(z);
	if (!map) return;

	map->set("busy", 1);

	sec--;
	if (sec > 0)
	{
		member = "inh/std/scum_map"->get_all_user(map);
		member -= ({ 0 });
		size = sizeof(member);

		for (i = 0; i < size; i++)
		{
			if (get_z(member[i]) != z) {
				time_out(map);
				continue;
			}

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

		add_boss(z, level, map_level);

		call_out("time_out", 60 * 15, map);
	}
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

	/*if (level != 60) {
		level = 60;
	}*/

	z = new_copy_scene(who, me);

	if (!z) return 0;
	if (!objectp(map = get_map_object(z)) || !map->is_virtual_scene())
		return 0;

	//if (!new_copy_npc(z, level)) return 0;

	

	do_fight(10, z, level, who);

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

	/*if (level != 60) {
		level = old_map->get("copy_level");
	}*/

	mapLevel = level + 5;

	z = new_copy_scene(who, me);

	if (!z) return 0;
	if (!objectp(map = get_map_object(z)) || !map->is_virtual_scene())
		return 0;


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

void delete_virtual_map(object map) {
	if (!map)
		return;

	COPY_MAP->destruct_virtual_map(map, map->get_id());
}

//void player_exit()
//{
//	int i, j, size1, size2, x, y, z, p;
//	object* member;
//	x = 292; y = 185; z = 80;
//	if (!Map) return;
//	size1 = sizeof(Map);
//	for (i = 0; i < size1; i++)
//	{
//		member = FILE_MAP->get_all_user(Map[i]);
//		if ((size2 = sizeof(member)) < 1) continue;
//		for (j = 0; j < size2; j++)
//		{
//			if (!p = get_valid_xy(z, x, y, IS_CHAR_BLOCK)) return;
//			x = (p % 1000000) / 1000;  y = p % 1000;
//			send_user(member[j], "%c%s", '!', HIY"Ngươi đã vượt qua thời gian đi Phó Bản, vì vậy ngươi bị Đông Phương Bất Bại dùng chưởng lực đánh bay ra khỏi Phó Bản !");
//			call_out("send_player", 3, member[j]);
//		}
//	}
//}
//void send_player(object who)
//{
//	int x, y, z, p;
//	z = 80; x = 320; y = 124;
//	if (!p = get_valid_xy(z, x, y, IS_CHAR_BLOCK)) return;
//	x = (p % 1000000) / 1000;  y = p % 1000;
//	who->add_to_scene(z, x, y);
//}

object* delete_map(object map)
{
	Map -= ({ map });

	if (map) {
		COPY_MAP->destruct_virtual_map(map, map->get_id());
	}

	return Map;
}

void debug_thap(object me) {
	for (int i = 0; i < sizeof(Map); i++) {
		tell_user(me, "number %d", i + 1);
	}
}

void win_bonus_callout(object me, object who)
{
	object owner, * team, npc;
	int level, level2, exp, exp3, exp2, pot, alllevel;
	int i, size, status, time, flag;

	if (!objectp(who = me->get_enemy_4())) return;

	if (owner = who->get_owner()) who = owner;
	if (who->is_npc()) return;
	if (who->get_group_id()) return;

	level = me->get_level();

	if (who->get_leader() && arrayp(team = who->get_team()) && sizeof(team) > 1)
	{
		team = me->correct_bonus_team(team);
		size = sizeof(team);
	}
	else
	{
		team = ({ who });
		size = 1;
	}

	alllevel = 0;
	for (i = 0; i < size; i++) if (team[i])
	{
		alllevel += team[i]->get_level();
	}
	if (alllevel == 0) alllevel = 1;
	pot = level * 2;
	for (i = 0; i < size; i++) if (team[i])
	{
		exp2 = level * 500 + (size * 3000);
		level2 = level - team[i]->get_level();
		if (size < 2)
			exp2 = me->correct_exp_bonus(level, level2, exp2) * who->get_online_rate() / 100;

		if (exp2 < 5) exp2 = 5;
		exp2 = exp2 * team[i]->get_online_rate() / 100;
		pot = pot * team[i]->get_online_rate() / 100;
		team[i]->add_exp(exp2);
		team[i]->add_potential(pot);
	}

	

	who->set_save("thapchitonowner", who->get("map_level"));

	//Update board
	if (is_player(who) && who->get_save("thapchitonowner") != 0) {
		update_data(who, who->get_save("thapchitonowner"));
	}

}


void drop_items(object me, object who)
{
	int x, y, z, p, i, rate, rate1, level, map_grade, n, map_level;
	string* nTmp, id, owner, file;
	object item, leader, item105, item9x, map;

	z = get_z(me);  x = get_x(me);  y = get_y(me);
	level = me->get_level();
	if (!level) level = 30;
	id = who->get_leader();
	if (!id) owner = who->get_id();
	else
	{
		if (leader = find_player(id))
		{
			owner = leader->get_id();
		}
		else
			owner = who->get_id();
	}

	rate1 = me->correct_drop_rate(me->get_level() - who->get_level()) * who->get_online_rate() / 100;
	rate = random(100);
	if (rate < rate1) //必掉
	{
		if (p = get_valid_xy(z, x, y, IS_ITEM_BLOCK))  //随机门派蓝色装备1件
		{
			nTmp = WEAPON_FILE->get_family_equip(nFamily[random(7)], 0, level, HEAD_TYPE + random(6));
			if (sizeof(nTmp))
			{
				item = new(nTmp[random(sizeof(nTmp))]);
				if (!item)
					return;
				ITEM_EQUIP_D->init_equip_prop_1(item);
				TEAM_D->drop_item(item, who);
				item->set_user_id(owner);
				item->add_to_scene(z, p / 1000, p % 1000);
				item->set("winner", who);
				item->set("time", time());
			}
		}
		for (i = 0; i < 5; i++)	//5堆5000金
		{
			if (p = get_valid_xy(z, x, y, IS_ITEM_BLOCK))
			{
				item = new("/item/std/0001");
				item->set_value(5000);
				TEAM_D->drop_item(item, who);
				item->set_user_id(owner);
				item->add_to_scene(z, p / 1000, p % 1000);
				item->set("winner", who);
				item->set("time", time());

			}
		}

	}
	p = get_valid_xy(z, x, y, IS_ITEM_BLOCK);
	if (!p)
		return;
	rate = random(10000);
	if (rate < 200 * rate1 / 100)
	{
		nTmp = WEAPON_FILE->get_family_equip(nFamily[random(7)], 0, 100, HEAD_TYPE + random(6));
		if (sizeof(nTmp))
		{
			item = new(nTmp[random(sizeof(nTmp))]);
			if (!item)
				return;
			ITEM_EQUIP_D->init_equip_prop_3(item);
			TEAM_D->drop_item(item, who);
			item->set_user_id(owner);
			item->add_to_scene(z, p / 1000, p % 1000);
			item->set("winner", who);
			item->set("time", time());
		}
	}
	else if (rate < 2200 * rate1 / 100)		//一级晶石%20
	{
		if (p = get_valid_xy(z, x, y, IS_ITEM_BLOCK))
		{
			item = new(STONE_FILE->get_diamond_file());
			item->set_level(2);
			TEAM_D->drop_item(item, who);
			item->set_user_id(owner);
			item->add_to_scene(z, p / 1000, p % 1000);
			item->set("winner", who);
			item->set("time", time());
		}
	}
	else if (rate < 4400 * rate1 / 100)		//1本对应活动门派进阶书：20%
	{
		if (p = get_valid_xy(z, x, y, IS_ITEM_BLOCK))
		{
			item = new(BOOK_FILE->get_book_file());
			TEAM_D->drop_item(item, who);
			item->set_user_id(owner);
			item->add_to_scene(z, p / 1000, p % 1000);
			item->set("winner", who);
			item->set("time", time());
		}
	}

	rate = who->get("map_level");
	if (rate < 1) {
		rate = 2;
	}

	if (rate >= 6) {
		rate = 6;
	}

	for (i = 0; i < 1; i++) {
		if (p = get_valid_xy(z, x, y, IS_ITEM_BLOCK))
		{
			item = new(STONE_FILE->get_diamond_file());
			item->set_level(random(rate) + 1);
			TEAM_D->drop_item(item, who);
			item->set_user_id(owner);
			item->add_to_scene(z, p / 1000, p % 1000);
			item->set("winner", who);
			item->set("time", time());
		}
	}


}


void update_data(object player, int floor) {
	int size, index, pos, i, pID, gender, ap, cp, dp, pp, hp, hair, pLevel;
	string pName, familyName, oldPID;
	object oldWho;

	pID = player->get_number();
	pName = player->get_name();
	gender = player->get_gender();
	familyName = player->get_fam_name();
	hair = player->get_hair();

	ap = player->get_ap();
	cp = player->get_cp();
	dp = player->get_dp();
	pp = player->get_pp();
	hp = player->get_max_hp() * 2;
	pLevel = player->get_level();

	oldPID = get_save_2(sprintf("towerFloor.%d.pid", floor));

	if (oldPID != "" && oldWho = find_any_char(oldPID)) {
		MAILBOX->sys_mail(oldWho->get_id(), oldWho->get_number(), sprintf("Bạn đã bị đánh bại bởi %s và chiếm giữ tầng %d Thông Thiên Tháp!", player->get_name(), floor));
	}

	set_save_2(sprintf("towerFloor.%d.pid", floor), sprintf("%d", pID));
	set_save_2(sprintf("towerFloor.%d.pname", floor), pName);
	set_save_2(sprintf("towerFloor.%d.family", floor), familyName);
	set_save_2(sprintf("towerFloor.%d.level", floor), pLevel);

	set_save_2(sprintf("towerFloor.%d.gender", floor), gender);
	set_save_2(sprintf("towerFloor.%d.hair", floor), hair);

	set_save_2(sprintf("towerFloor.%d.hp", floor), hp);
	set_save_2(sprintf("towerFloor.%d.ap", floor), ap);
	set_save_2(sprintf("towerFloor.%d.cp", floor), cp);
	set_save_2(sprintf("towerFloor.%d.dp", floor), dp);
	set_save_2(sprintf("towerFloor.%d.pp", floor), pp);


	//A900
	//"sys/sys/title"->delete_title();
	save();
}


void fresh_data(object me) {
	int i, pID, pLevel, hp, ap, cp, dp, pp, hair, gender, floor;
	string pName = "CQFREE", familyName;

	pID = 1;

	hp = 100000;
	ap = 1000;
	cp = 1500;
	dp = 500;
	pp = 500;


	for (i = 1; i <= 10; i++) {
		floor = i;

		familyName = nFamily[random(sizeof(nFamily))];
		pLevel = (i * 5) + 15;
		gender = random(2) + 1;
		hair = random(5) + 1;

		hp = hp + i * 1000;
		ap = ap + i * 300;
		cp = cp + i * 300;
		dp = dp + i * 100;
		dp = dp + i * 100;

		set_save_2(sprintf("towerFloor.%d.pid", floor), sprintf("%d", pID));
		set_save_2(sprintf("towerFloor.%d.pname", floor), pName);
		set_save_2(sprintf("towerFloor.%d.family", floor), familyName);
		set_save_2(sprintf("towerFloor.%d.level", floor), pLevel);

		set_save_2(sprintf("towerFloor.%d.gender", floor), gender);
		set_save_2(sprintf("towerFloor.%d.hair", floor), hair);

		set_save_2(sprintf("towerFloor.%d.hp", floor), hp);
		set_save_2(sprintf("towerFloor.%d.ap", floor), ap);
		set_save_2(sprintf("towerFloor.%d.cp", floor), cp);
		set_save_2(sprintf("towerFloor.%d.dp", floor), dp);
		set_save_2(sprintf("towerFloor.%d.pp", floor), pp);

	}

	save();
	tell_user(me, ECHO"Generated data!");

}


void view_data(object me) {
	int i, type, p, x, y, newLevel, sizeData, index, floor;
	int ap, cp, dp, hp, pp, gender, hair, pLevel, nHP, nAP,nCP;
	string pName, familyName, result = "";
	object npc;

	if (!get_save_2("towerFloor")) {
		for (i = 0; i < 1; i++)
		{
			type = random(7) + 1;
			result += "Mặc định\n";
		}

	}
	else {
		for (index = 1; index <= MAX_TOWER; index++)
		{
			floor = index;

			pName = get_save_2(sprintf("towerFloor.%d.pname", floor));
			familyName = get_save_2(sprintf("towerFloor.%d.family", floor));
			pLevel = get_save_2(sprintf("towerFloor.%d.level", floor));
			gender = get_save_2(sprintf("towerFloor.%d.gender", floor));
			hair = get_save_2(sprintf("towerFloor.%d.hair", floor));

			hp = get_save_2(sprintf("towerFloor.%d.hp", floor));
			ap = get_save_2(sprintf("towerFloor.%d.ap", floor));
			cp = get_save_2(sprintf("towerFloor.%d.cp", floor));
			dp = get_save_2(sprintf("towerFloor.%d.dp", floor));
			pp = get_save_2(sprintf("towerFloor.%d.pp", floor));

			newLevel = (pLevel + (floor * 2));
			if (newLevel >= 120) {
				newLevel = 120;
			}

			nHP = hp * 2 + (floor * 10000);
			nAP = (ap + cp) / 4;
			nCP = (ap + cp) / 4;


			result += sprintf("%d. Name: %s - Level %d - hp:%d_ap:%d_cp:%d_dp:%d_pp:%d - Phái: %s \n", floor, pName, pLevel, hp, ap, cp, dp, pp, familyName);
			result += sprintf("-> Boss: Level %d - hp:%d_ap:%d_cp:%d_dp:%d_pp:%d \n\n", newLevel, nHP, nAP, nCP, dp/2, pp/2);

		}

		tell_user(me, result);

	}

}