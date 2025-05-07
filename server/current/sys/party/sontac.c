/********************************************************************************************************************************
-----------------------Trộm Bảo Phi Tặc --------------------
10 : ({061,001,}),==Sở Phương Thành 1, Tân Thủ Thôn
20 : ({081,089,}),==Thủ Dương Sơn, Hổ Lao Quan
30 : ({163,164,}),==Ranh giới Đầm Lầy, địa giới Đầm Lầy
40 : ({151,011,}),==Đông Hải Ngư Thôn, Kênh Trịnh Quốc 1
50 : ({173,072,}),==Yên Trường Thành 2, Bạch Vân Phòng
60 : ({032,}),==Triệu Trường Thành 2
70 : ({312,322,}),==Linh Cốc Động, Loan Đạo 2
80 : ({291,}),==Khốn Ma Trận 1
90 : ({381,}),==Hư Lăng Động
100: ({372,}),==Cầu Cửu Khúc 1
********************************************************************************************************************************/

#include <time.h>
#include <ansi.h>
#include <cmd.h>

#include <npc.h>
#include <city.h>
#include <action.h>
#include <effect.h>
#include <skill.h>
#include <public.h>

#define SON_TAC 			"npc/event/sontac"

void generateScum(int mapId, int scrumNumber, int level);

void destroy_scum();
void son_tac();

string* schoolname = ({ "Đào Hoa Nguyên", "Thục Sơn", "Cấm Vệ Quân", "Đường Môn", "Mao Sơn", "Côn Luân", "Vân Mộng Cốc", });
object* Scum;
mapping mpNianshou;
void SAVE_BINARY() { }

int life_time_mins = 50;
int life_time_sec = life_time_mins * 60;

void create()
{
	Scum = ({});
	call_out("check_time", 1);
}

void check_time()
{
	int iTime, rate, level, z, p, x, y;
	int i, * nScene, size;
	mixed* mixTime;
	object robber;

	remove_call_out("check_time");
	iTime = time();
	mixTime = localtime(iTime);

	//0	 1	2   3  4  5  6
	//cn t2 t3 t4 t5 t6 t7

	i = 60 * (60 - mixTime[TIME_MIN]);

	if (mixTime[TIME_WDAY] == 1 ||
		mixTime[TIME_WDAY] == 3 ||
		mixTime[TIME_WDAY] == 5 ||
		mixTime[TIME_WDAY] == 0
		)

	{
		if (mixTime[TIME_MIN] >= 45) {
			call_out("check_time", i);
		}
		else {

			if (
				mixTime[TIME_HOUR] == 7 ||
				mixTime[TIME_HOUR] == 9 ||
				mixTime[TIME_HOUR] == 11 ||
				mixTime[TIME_HOUR] == 13 ||
				mixTime[TIME_HOUR] == 15 ||
				mixTime[TIME_HOUR] == 17 ||
				mixTime[TIME_HOUR] == 19 ||
				mixTime[TIME_HOUR] == 21 ||
				mixTime[TIME_HOUR] == 23) {

				son_tac();

				call_out("check_time", i + 3600);
			}
			else {
				call_out("check_time", i);
			}
			
		}
	}
	else
	{
		call_out("check_time", i + 3600);
	}

}

void son_tac() {
	log_file("boss.txt", short_time() + " Sơn tặc \n");

	CHAT_D->sys_channel(0, "Bọn Sơn Tặc xuất hiện cướp lấy của cải của người dân, nghe nói chúng có rất nhiều kho báu. Chúng đang lẩn trốn ở các bản đồ luyện cấp, mau mau đánh đuổi chúng...");

	generateScum(061, 1, 10);
	generateScum(062, 1, 10);
	generateScum(063, 1, 10);
	generateScum(281, 1, 10);
	generateScum(282, 1, 10);
	generateScum(283, 1, 10);
	generateScum(284, 1, 10);
	generateScum(081, 1, 15);
	generateScum(082, 1, 15);
	generateScum(021, 1, 20);
	generateScum(041, 1, 20);
	generateScum(042, 1, 20);
	generateScum(043, 1, 20);
	generateScum(141, 1, 20);
	generateScum(142, 1, 20);
	generateScum(211, 1, 20);
	generateScum(241, 1, 20);
	generateScum(242, 1, 20);
	generateScum(243, 1, 20);
	generateScum(089, 1, 25);
	generateScum(131, 1, 25);
	generateScum(132, 1, 25);
	generateScum(155, 1, 25);
	generateScum(181, 1, 25);
	generateScum(182, 1, 25);
	generateScum(231, 1, 25);
	generateScum(251, 1, 25);
	generateScum(271, 1, 25);
	generateScum(272, 1, 25);
	generateScum(163, 1, 30);
	generateScum(164, 1, 30);
	generateScum(111, 1, 35);
	generateScum(112, 1, 35);
	generateScum(261, 1, 35);
	generateScum(262, 1, 35);
	generateScum(263, 1, 35);
	generateScum(264, 1, 35);
	generateScum(265, 1, 35);
	generateScum(266, 1, 35);
	generateScum(011, 1, 40);
	generateScum(012, 1, 40);
	generateScum(013, 1, 40);
	generateScum(014, 1, 40);
	generateScum(015, 1, 40);
	generateScum(151, 1, 45);
	generateScum(152, 1, 45);
	generateScum(153, 1, 45);
	generateScum(171, 1, 50);
	generateScum(172, 1, 50);
	generateScum(173, 1, 50);
	generateScum(174, 1, 50);
	generateScum(071, 1, 55);
	generateScum(072, 1, 55);
	generateScum(073, 1, 55);
	generateScum(031, 1, 60);
	generateScum(032, 1, 60);
	generateScum(033, 1, 60);
	generateScum(051, 1, 65);
	generateScum(052, 1, 65);
	generateScum(053, 1, 65);
	generateScum(321, 1, 70);
	generateScum(322, 1, 70);
	generateScum(323, 1, 70);
	generateScum(311, 1, 75);
	generateScum(312, 1, 75);
	generateScum(313, 1, 75);
	generateScum(331, 1, 80);
	generateScum(332, 1, 80);
	generateScum(333, 1, 80);
	generateScum(334, 1, 80);
	generateScum(335, 1, 80);
	generateScum(341, 1, 85);
	generateScum(342, 1, 85);
	generateScum(343, 1, 85);
	generateScum(344, 1, 85);
	generateScum(345, 1, 85);
	generateScum(291, 1, 90);
	generateScum(292, 1, 90);
	generateScum(293, 1, 90);
	generateScum(381, 1, 95);
	generateScum(383, 1, 95);
	generateScum(385, 1, 95);
	generateScum(372, 1, 100);
	generateScum(373, 1, 100);
	generateScum(374, 1, 100);
	generateScum(091, 1, 105);
	generateScum(092, 1, 105);
	generateScum(093, 1, 105);
	generateScum(391, 1, 110);
	generateScum(392, 1, 110);
	generateScum(393, 1, 110);

	generateScum(504, 1, 110);
	generateScum(505, 1, 110);
	generateScum(506, 1, 110);
	generateScum(507, 1, 130);
	generateScum(508, 1, 130);
	generateScum(509, 1, 130);
	generateScum(510, 1, 120);
	generateScum(511, 1, 120);

	generateScum(117, 1, 130);
	generateScum(118, 1, 130);
	generateScum(119, 1, 130);

	generateScum(133, 1, 120);
	generateScum(134, 1, 120);
	generateScum(135, 1, 120);


	call_out("check_time2", life_time_sec);
}

void generateScum(int mapId, int scrumNumber, int level)
{
	int i, size, z, p, x, y, j;
	object npc;

	for (i = 0; i < scrumNumber; i++)
	{
		if (!(p = efun::get_xy_point(mapId, IS_CHAR_BLOCK)))
			continue;
		x = p / 1000;
		y = p % 1000;
		npc = new(SON_TAC);

		npc->set_level(level);
		npc->set_char_type(FIGHTER_TYPE_2);
		NPC_ENERGY_D->init_level(npc, level);
		npc->add_max_hp(npc->get_max_hp() * 50);
		npc->add_dp(npc->get_dp() / 2);
		npc->add_ap(npc->get_ap() * 2);
		npc->add_pp(npc->get_pp() / 2);

		npc->set_walk_speed(2);
		npc->set_attack_speed(3);
		npc->set_max_seek(6);
		npc->set_walk_step(2);
		npc->set("no_sk04211", 1);
		npc->set("anti_sleep", 1);
		npc->set("anti_blind", 1);

		npc->add_to_scene(mapId, x, y);
		Scum += ({ npc });
	}

	//call_out("check_time2", life_time_sec);
}
//Sau 45 phút từ khi Phi Tặc xuất hiện, Phi Tặc sẽ tự động biến mất 
void check_time2()
{
	int i, size;

	for (i = 0, size = sizeof(Scum); i < size; i++)
	{
		if (!objectp(Scum[i]))
			continue;

		Scum[i]->remove_from_scene();
		destruct(Scum[i]);
	}

	Scum -= ({ 0 });
	CHAT_D->sys_channel(0, HIY"Sơn Tặc đã đào tẩu trốn thoát cùng nhiều vật phẩm giá trị !!");
}
object drop_food_wine(int level)
{
	int* nTmp;
	object item;
	mapping mpFood = ([
		130:({ 3301,3302 }),
			110 : ({ 3310,3311 }),
			90 : ({ 3303,3304 }),
			70 : ({ 3320,3280 }),
			50 : ({ 3281,3285 }),
			30 : ({ 3283,3284 }),
			10 : ({ 3282,3325 }),
	]);

	if (random(2))	//酒
	{
		if (level >= 130)
			item = new("item/31/3156");
		else if (level >= 110)
			item = new("item/31/3155");
		else if (level >= 90)
			item = new("item/31/3154");
		else if (level >= 70)
			item = new("item/31/3153");
		else if (level >= 50)
			item = new("item/31/3152");
		else if (level >= 30)
			item = new("item/31/3151");
		else
			item = new("item/31/3150");
	}
	else	//食物
	{
		if (level >= 130)
			level = 130;
		else if (level >= 110)
			level = 110;
		else if (level >= 90)
			level = 90;
		else if (level >= 70)
			level = 70;
		else if (level >= 50)
			level = 50;
		else if (level >= 30)
			level = 30;
		else
			level = 10;
		nTmp = mpFood[level];
		level = nTmp[random(sizeof(nTmp))];
		item = new(sprintf("item/%d/%d", level / 100, level));
	}
	if (!objectp(item))
		return;
	item->set_amount(8);
	return item;
}

void drop_items(object me, object who)
{
	int x, y, z, p, i, rate, rate1, level, level2;
	string* nTmp, id, owner, file;
	object item, leader, eventItemThieuNhi;

	level = me->get_level();
	z = get_z(me);  x = get_x(me);  y = get_y(me);
	id = who->get_leader();
	if (!id) {
		owner = who->get_id();
	}
	else {
		if (leader = find_player(id)) {
			owner = leader->get_id();
		}
		else {
			owner = who->get_id();
		}
	}
	for (i = 0; i < 8; i++) {
		if (p = get_valid_xy(z, x, y, IS_ITEM_BLOCK)) {
			item = new("/item/std/0001");
			item->set_value(level * 30);
			TEAM_D->drop_item(item, who);
			item->set_user_id(owner);
			item->add_to_scene(z, p / 1000, p % 1000);
			item->set("winner", who);
			item->set("time", time());
		}
	}

	for (i = 0; i < 10; i++) {
		if (p = get_valid_xy(z, x, y, IS_ITEM_BLOCK)) {
			item = drop_food_wine(level);
			if (!item) {
				continue;
			}
			TEAM_D->drop_item(item, who);
			item->set_user_id(owner);
			item->add_to_scene(z, p / 1000, p % 1000);
			item->set("winner", who);
			item->set("time", time());
		}
	}

	p = get_valid_xy(z, x, y, IS_ITEM_BLOCK);
	if (!p) {
		return;
	}

	rate1 = me->correct_drop_rate(me->get_level() - who->get_level()) * who->get_online_rate() / 100;
	if (rate1 < 40) {
		return;
	}

	rate = random(10000);
	item = 0;

	if (rate < 9946) {
		file = STONE_FILE->get_diamond_file();
		item = new(file);
		if (!item) {
			return 0;
		}
		item->set_level(1);
	}


	if (p = get_valid_xy(z, x, y, IS_ITEM_BLOCK))
	{
		item = new("/item/common/dacuonghoa");
		TEAM_D->drop_item(item, who);
		item->set_user_id(owner);
		item->add_to_scene(z, p / 1000, p % 1000);
		item->set("winner", who);
		item->set("time", time());
	}

	rate = random(100);

	item = new("/item/common/box/ruongdong/box");

	if (p = get_valid_xy(z, x, y, IS_ITEM_BLOCK))
	{
		TEAM_D->drop_item(item, who);
		item->set_user_id(owner);
		item->add_to_scene(z, p / 1000, p % 1000);
		item->set("winner", who);
		item->set("time", time());
	}

	item = new("/item/common/box/tukim/box");

	if (p = get_valid_xy(z, x, y, IS_ITEM_BLOCK))
	{
		TEAM_D->drop_item(item, who);
		item->set_user_id(owner);
		item->add_to_scene(z, p / 1000, p % 1000);
		item->set("winner", who);
		item->set("time", time());
	}

}

void win_bonus_callout(object me, object who)
{
	object owner, * team, map;
	int level, level2, exp, exp2, pot, alllevel;
	int i, size, status, time, flag;
	string mapName = "";

	if (!objectp(who = me->get_enemy_4())) return;

	if (owner = who->get_owner()) who = owner;
	if (who->is_npc()) return;
	if (who->get_group_id()) return;

	map = get_map_object(get_z(me));
	mapName = map ? map->get_name() : "";

	if (mapName != "") {
		CHAT_D->sys_channel(0, sprintf(HIY"Nghe nói Sơn Tặc tại %s đã bị bằng hữu "HIR"%s"HIY" tiêu diệt", mapName, who->get_name()));
	}
	else {
		CHAT_D->sys_channel(0, HIY"Nghe nói Sơn Tặc đã bị bằng hữu "HIR"" + who->get_name() + " "HIY"tiêu diệt");
	}

	if (who->get_online_rate()) {
		drop_items(me, who);
	}

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
	exp = level * 100;
	pot = level * 5;
	for (i = 0; i < size; i++) if (team[i])
	{
		level2 = level - team[i]->get_level();
		exp2 = exp * team[i]->get_level() / alllevel;
		exp2 = me->correct_exp_bonus(level, level2, exp2) * who->get_online_rate() / 100;

		if (exp2 < 5) exp2 = 5;
		exp2 = exp2 * team[i]->get_online_rate() / 100;
		pot = pot * team[i]->get_online_rate() / 100;
		team[i]->add_exp(exp2);
		team[i]->add_potential(pot);

		"sys/sys/test_db"->add_yuanbao(team[i], level / size);

		write_user(team[i], sprintf(ECHO "Bạn tiêu diệt Sơn Tặc cấp %d và nhận được %d Ngân Bảo !", level, level / size));
	}

}