#include <npc.h>
#include <ansi.h>
#include <cmd.h>
#include <effect.h>
#include <public.h>
#include <map.h>
#include <time.h>
#include <action.h>

#define MAP_ID 892
#define NUMBER_SCUM 7
#define NUMBER_MEM 1
#define MAX_MEM 1

#define FILE_MAP    "map/copy/891"
#define FILE_SENDER "npc/event/lientram/xaphu2"
#define FILE_GUAI    "npc/event/lientram/scum_lientram"

#define DEBUG(who,arg) ;
#define DEBUG2(who,z,x,y);

inherit OFFICER;

object* Map;

int new_copy_scene(object who, object me);
int new_copy_npc(int z, int x, int y);
int  new_copy(object who, object me);
void do_fight(int sec, int z, int level, object who, int luot, int number);

void get_bonus_lientram(object who);

void SAVE_BINARY() { }

int add_npc(object who, int z, int x, int y, int level);
int add_boss(object who, int z, int x, int y, int level);

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
	result = sprintf(me->get_name() + ": Tham gia tích lũy số lần tiêu diệt quái vật để đổi phần thưởng tương ứng.\nQuy tắc:\n1. Mỗi nhân vật tham gia mỗi ngày 1 lần.\n2. Yêu cầu nhân vật có cấp độ 20 trở lên.\n3.Thời gian duy trì giữa 2 lần liên sát là 5 giây.\n4. Phần thưởng nhận tại NPC sau khi kết thúc phó bản.\nPhần thưởng:\nVật phẩm pháp bảo có chỉ số và hiệu ứng đặc biệt theo mỗi 100 liên trảm đã tích lũy được.\n");
	result += sprintf(ESC "Tiến vào Phó bản\ntalk %x# welcome.1\n", getoid(me));
	result += sprintf(ESC "Nhận thưởng\ntalk %x# welcome.111\n", getoid(me));
	result += sprintf(ESC "Rời khỏi");
	send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), result);
}

void do_look2(object who, object me)
{
	string result;

	result = sprintf(me->get_name() + ":\nPhó bản săn pháp bảo Liên Trảm...\n");
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

		if (size > MAX_MEM)
		{
			result = sprintf(me->get_name() + ":\n    Phó bản này chỉ cho phép đi đơn lẻ !\n");
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

			if (team[i]->get_save_2("lientram.today") == (mixTime[TIME_WDAY] + 1) && team[i]->get_save_2("lientram.go") < 1) {
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

		who->set("lientram", 0);
		if (!new_copy(who, me) == 1) return;

		tid = who->get("team_id");
		map = TEAM_D->get_copy_scene(tid, COPY_GUMU);

		if (map)
		{
			z = map->get_id();
			x = 39; y = 30;
			if (!p = get_valid_xy(z, x, y, IS_CHAR_BLOCK)) return;
			x = (p % 1000000) / 1000;  y = p % 1000;
			
			who->set("me_die", 1);
			send_user(who, "%c%c%w%s", 0x5a, 0, 1, "Đang di chuyển……");
			who->set_2("travel.z", z);
			who->set_2("travel.p", p);
			who->set("map", map);

			set_effect(who, EFFECT_TRAVEL, 1);

			level = who->get_level() - 20;
			if (level < 20) {
				level = 20;
			}

			call_out("do_fight", 3, 5, z, level, who, 1, 5);

			who->set_save_2("lientram.today", (mixTime[TIME_WDAY] + 1));
			who->set_save_2("lientram.go", 0);
		}

		break;

	case 2:
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
		who->add_to_scene(080, 293, 184);
		who->set_save("lientram.oldZ", 0);
		who->set_save("lientram.timeout", 0);
		break;
	case 111:
		if (who->get("Maxlientram") >= 100) {
			get_bonus_lientram(who);
		}
		else {
			result = sprintf(me->get_name() + ":\nNgươi chưa đủ điều kiện nhận thưởng.\n");
			result += sprintf(ESC "Rời khỏi");
			send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), result);
		}
		break;
	}

}

void get_bonus_lientram(object who) {
	int lientram = who->get("Maxlientram")/100;
	object item_lientram;
	
	int result,p;

	switch (lientram)
	{
	case 1:
		result = 100;
		break;
	case 2:
		result = 200;

		break;
	case 3:
		result = 300;
		break;
	case 4:
		result = 400;
		break;
	case 5:
		result = 500;
		break;
	case 6:
		result = 600;
		break;
	case 7:
		result = 700;
		break;
	case 8:
		result = 800;
		break;
	case 9:
		result = 900;
		break;
	case 10:
		result = 1000;
		break;

	}

	if (result != 0) {
		item_lientram = new(sprintf("/item/common/lientram/%d", lientram));
		p = item_lientram->move(who, -1);
		if (p)
		{
			item_lientram->add_to_user(p);
			who->set("Maxlientram", 0);
			tell_user(who, sprintf("Bạn nhận được %s", item_lientram->get_name()));
		}
		else {
			destruct(item_lientram);
			return;
		}

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
	z = COPY_CTROL->new_scene(d, FILE_MAP, "Liên Trảm");
	if (!z) return 0;
	if (!objectp(map = get_map_object(z)) || !map->is_virtual_scene())
		return 0;

	TEAM_D->add_copy_scene(tid, COPY_GUMU, map);

	map->set("copy_id", 1);
	map->set("gumu_map", 1);
	Map += ({ map });

	for (i = 0; i < size; i++)
	{
		team[i]->set("team_id", tid);
		team[i]->set_save("lientram.oldZ", z);
		team[i]->set_save("lientram.timeout", time() + 60);
		map->set_owner(team[i]);
	}

	return z;
}

int is_limited(int totalValue) {
	int result = 0;
	switch (totalValue)
	{
		case 1000:
		case 900:
		case 800:
		case 700:
		case 600:
		case 500:
		case 400:
		case 300:
		case 200:
		case 100:
			result = 1;
			break;
	}

	return result;
}

void create_crum(object who, int level, int z, int number) {
	int i, p, x, y;
	object npc, item, map;
	map = get_map_object(get_z(who));

	if (!map || !map->is_virtual_scene())
		return 0;

	for (i = 0; i < number; i++) {
		npc = new("npc/event/lientram/scum_lientram");
		//npc->set_max_hp(2000);
		npc->set_level(level);
		NPC_ENERGY_D->init_level(npc, level);
		npc->set_fight_status(level);

		if (!(p = efun::get_xy_point(MAP_ID, IS_CHAR_BLOCK)))
			continue;

		x = (p % 1000000) / 1000;  y = p % 1000;
		npc->add_to_scene(z, x, y);

		map->add("copy_npc_amount", 1);
	}
}

void loop_check_lientram(object who) {
	
	if (who->get("lientramTime") > 0) {
		send_user(who, "%c%s", ';', sprintf(HIC"%d "NOR"liên trảm mất sau "HIR"%d "NOR"giây",who->get("lientram"), who->get("lientramTime")));
		who->set("lientramTime", who->get("lientramTime") - 1);
	}
	else {
		if (who->get("lientram") > who->get("Maxlientram")) {
			who->set("Maxlientram", who->get("lientram"));
		}

		who->set("lientram", 0);
		send_user(who, "%c%s", ';', sprintf(""));
	}
	
}

void do_fight(int sec, int z, int level, object who, int luot, int number)
{
	int p, x, y, i, map_level, rate, type, old_level, size;
	object npc, map, * member;
	int each_level = 5;
	p = MAP_ID;

	if (!who && !get_z(who)) {
		return;
	}

	map = get_map_object(get_z(who));
	if (!map)
		return;
	sec--;
	if (sec > 0)
	{
		if (map->get("autoDie") > 100) {
			tell_user(who, HIR"Phó bản thất bại!!");
			COPY_MAP->destruct_virtual_map(map, map->get_id());
			return;
		}

		if (!map->is_virtual_scene())
			return;

		tell_user(who, ECHO"Đợt %d - lính xuất hiện sau %d giây",luot, sec);
		call_out("do_fight", 1, sec, z, level, who, luot, number);
		call_out("loop_check_lientram", 1, who);
	}
	else
	{
		if (map->get("copy_npc_amount") > 99 && is_limited(map->get("copy_npc_amount")) == 1) {
			level++;
			if ((luot +1) % 5 == 0) {
				create_crum(who, level, z, number);
			}
			else {
				create_crum(who, level, z, number);
			}

			do_fight(10, z, level, who, luot + 1, number);
		}
		else {
			if ((luot + 1) % 5) {
				level++;
			}

			create_crum(who, level, z, number);
			do_fight(3, z, level, who, luot + 1, number);
		}

	}
}

int new_copy(object who, object me)
{
	int i, tid, size, z, luot, iTime;
	int level = 0;
	object* team, map;
	mixed* mixTime;

	tid = who->get_team_id();
	if (!tid) return 0;
	if (!team = who->get_team()) return 0;

	////kiem tra luot di trong ngay
	//if (who->get_save_2("lientram.today") && who->get_save_2("lientram.today") == (mixTime[TIME_WDAY] + 1) && who->get_save_2("lientram.go") < 1) {
	//	send_user(who, "%c%c%w%s", ':', 3, me->get_char_picid(), sprintf(" %s :\n Hôm nay bạn sử dụng hết lượt tham gia Phó Bản rồi\n"
	//		ESC"Thoát", me->get_name()));
	//	return 0;
	//}

	level = who->get_level() - 20;

	if (level < 20) {
		level = 20;
	}

	luot = 1;
	z = new_copy_scene(who, me);
	if (!z) return 0;
	if (!objectp(map = get_map_object(z)) || !map->is_virtual_scene())
		return 0;

	map->set("copy_level", level);
	who->set("Maxlientram", 0);
	who->set("lientram", 0);
	who->set("lientramTime", 0);


	return 1;
}

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

