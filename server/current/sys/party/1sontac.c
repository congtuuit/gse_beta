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

#define PhiTac 			"npc/event/sontac"

void generate_scum();
void destroy_scum();
string* schoolname = ({ "Đào Hoa Nguyên", "Thục Sơn", "Cấm Vệ Quân", "Đường Môn", "Mao Sơn", "Côn Luân", "Vân Mộng Cốc", });
object* Scum;
mapping mpNianshou;
void SAVE_BINARY() { }

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
			call_out("check_time", i + 3600);
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
				generate_scum();

				log_file("boss.txt", short_time() + " Sơn tặc\n");
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


void generate_scum()
{
	int i, size, z, p, x, y, j;
	object npc;

	// cấp 70
	for (i = 0; i < 2; i++)
	{
		if (!(p = efun::get_xy_point(312, IS_CHAR_BLOCK)))
			continue;
		x = p / 1000;
		y = p % 1000;
		npc = new(PhiTac);
		npc->set_level(70);
		npc->set_char_type(FIGHTER_TYPE_2);
		NPC_ENERGY_D->init_level(npc, 70);
		npc->add_max_hp(npc->get_max_hp() * 100);
		npc->add_dp(npc->get_dp() / 2);
		npc->add_ap(npc->get_ap() * 2 / 5);
		npc->add_pp(npc->get_pp() / 2);
		npc->add_to_scene(312, x, y);
		Scum += ({ npc });
	}

	for (i = 0; i < 2; i++)
	{
		if (!(p = efun::get_xy_point(322, IS_CHAR_BLOCK)))
			continue;
		x = p / 1000;
		y = p % 1000;
		npc = new(PhiTac);
		npc->set_level(70);
		npc->set_char_type(FIGHTER_TYPE_2);
		NPC_ENERGY_D->init_level(npc, 70);
		npc->add_max_hp(npc->get_max_hp() * 100);
		npc->add_dp(npc->get_dp() / 2);
		npc->add_ap(npc->get_ap() * 2 / 5);
		npc->add_pp(npc->get_pp() / 2);
		npc->add_to_scene(322, x, y);
		Scum += ({ npc });
	}

	// cấp 80
	for (i = 0; i < 2; i++)
	{
		if (!(p = efun::get_xy_point(291, IS_CHAR_BLOCK)))
			continue;
		x = p / 1000;
		y = p % 1000;
		npc = new(PhiTac);
		npc->set_level(80);
		npc->set_char_type(FIGHTER_TYPE_2);
		NPC_ENERGY_D->init_level(npc, 80);
		npc->add_max_hp(npc->get_max_hp() * 100);
		npc->add_dp(npc->get_dp() / 2);
		npc->add_ap(npc->get_ap() * 2 / 3);
		npc->add_pp(npc->get_pp() / 2);
		npc->add_to_scene(291, x, y);
		Scum += ({ npc });
	}
	// cấp 90
	for (i = 0; i < 2; i++)
	{
		if (!(p = efun::get_xy_point(381, IS_CHAR_BLOCK)))
			continue;
		x = p / 1000;
		y = p % 1000;
		npc = new(PhiTac);
		npc->set_level(95);
		npc->set_char_type(FIGHTER_TYPE_2);
		NPC_ENERGY_D->init_level(npc, 95);
		npc->add_max_hp(npc->get_max_hp() * 100);
		npc->add_dp(npc->get_dp() / 2);
		npc->add_ap(npc->get_ap() * 2 / 3);
		npc->add_pp(npc->get_pp() / 2);
		npc->add_to_scene(381, x, y);
		Scum += ({ npc });
	}
	// cấp 100
	for (i = 0; i < 2; i++)
	{
		if (!(p = efun::get_xy_point(372, IS_CHAR_BLOCK)))
			continue;
		x = p / 1000;
		y = p % 1000;
		npc = new(PhiTac);
		npc->set_level(100);
		npc->set_char_type(FIGHTER_TYPE_2);
		NPC_ENERGY_D->init_level(npc, 100);
		npc->add_max_hp(npc->get_max_hp() * 90);
		npc->add_dp(npc->get_dp() / 2);
		npc->add_ap(npc->get_ap() * 2 / 3);
		npc->add_pp(npc->get_pp() / 2);
		npc->add_to_scene(372, x, y);
		Scum += ({ npc });
	}

	for (i = 0; i < 2; i++)
	{
		if (!(p = efun::get_xy_point(091, IS_CHAR_BLOCK)))
			continue;
		x = p / 1000;
		y = p % 1000;
		npc = new(PhiTac);
		npc->set_level(100);
		npc->set_char_type(FIGHTER_TYPE_2);
		NPC_ENERGY_D->init_level(npc, 110);
		npc->add_max_hp(npc->get_max_hp() * 90);
		npc->add_dp(npc->get_dp() / 2);
		npc->add_ap(npc->get_ap() * 2 / 3);
		npc->add_pp(npc->get_pp() / 2);
		npc->add_to_scene(091, x, y);
		Scum += ({ npc });
	}

	for (i = 0; i < 2; i++)
	{
		if (!(p = efun::get_xy_point(092, IS_CHAR_BLOCK)))
			continue;
		x = p / 1000;
		y = p % 1000;
		npc = new(PhiTac);
		npc->set_level(100);
		npc->set_char_type(FIGHTER_TYPE_2);
		NPC_ENERGY_D->init_level(npc, 110);
		npc->add_max_hp(npc->get_max_hp() * 90);
		npc->add_dp(npc->get_dp() / 2);
		npc->add_ap(npc->get_ap() * 2 / 3);
		npc->add_pp(npc->get_pp() / 2);
		npc->add_to_scene(092, x, y);
		Scum += ({ npc });
	}


	for (i = 0; i < 2; i++)
	{
		if (!(p = efun::get_xy_point(093, IS_CHAR_BLOCK)))
			continue;
		x = p / 1000;
		y = p % 1000;
		npc = new(PhiTac);
		npc->set_level(100);
		npc->set_char_type(FIGHTER_TYPE_2);
		NPC_ENERGY_D->init_level(npc, 110);
		npc->add_max_hp(npc->get_max_hp() * 90);
		npc->add_dp(npc->get_dp() / 2);
		npc->add_ap(npc->get_ap() * 2 / 3);
		npc->add_pp(npc->get_pp() / 2);
		npc->add_to_scene(093, x, y);
		Scum += ({ npc });
	}

	for (i = 0; i < 2; i++)
	{
		if (!(p = efun::get_xy_point(391, IS_CHAR_BLOCK)))
			continue;
		x = p / 1000;
		y = p % 1000;
		npc = new(PhiTac);
		npc->set_level(100);
		npc->set_char_type(FIGHTER_TYPE_2);
		NPC_ENERGY_D->init_level(npc, 110);
		npc->add_max_hp(npc->get_max_hp() * 90);
		npc->add_dp(npc->get_dp() / 2);
		npc->add_ap(npc->get_ap() * 2 / 3);
		npc->add_pp(npc->get_pp() / 2);
		npc->add_to_scene(391, x, y);
		Scum += ({ npc });
	}

	for (i = 0; i < 2; i++)
	{
		if (!(p = efun::get_xy_point(392, IS_CHAR_BLOCK)))
			continue;
		x = p / 1000;
		y = p % 1000;
		npc = new(PhiTac);
		npc->set_level(100);
		npc->set_char_type(FIGHTER_TYPE_2);
		NPC_ENERGY_D->init_level(npc, 110);
		npc->add_max_hp(npc->get_max_hp() * 90);
		npc->add_dp(npc->get_dp() / 2);
		npc->add_ap(npc->get_ap() * 2 / 3);
		npc->add_pp(npc->get_pp() / 2);
		npc->add_to_scene(392, x, y);
		Scum += ({ npc });
	}

	for (i = 0; i < 2; i++)
	{
		if (!(p = efun::get_xy_point(393, IS_CHAR_BLOCK)))
			continue;
		x = p / 1000;
		y = p % 1000;
		npc = new(PhiTac);
		npc->set_level(100);
		npc->set_char_type(FIGHTER_TYPE_2);
		NPC_ENERGY_D->init_level(npc, 110);
		npc->add_max_hp(npc->get_max_hp() * 90);
		npc->add_dp(npc->get_dp() / 2);
		npc->add_ap(npc->get_ap() * 2 / 3);
		npc->add_pp(npc->get_pp() / 2);
		npc->add_to_scene(393, x, y);
		Scum += ({ npc });
	}

	//Sơn Động Thần Bí 1
	for (i = 0; i < 2; i++)
	{
		if (!(p = efun::get_xy_point(133, IS_CHAR_BLOCK)))
			continue;
		x = p / 1000;
		y = p % 1000;
		npc = new(PhiTac);
		npc->set_level(120);
		npc->set_char_type(FIGHTER_TYPE_2);
		NPC_ENERGY_D->init_level(npc, 120);
		npc->add_max_hp(npc->get_max_hp() * 80);
		npc->add_dp(npc->get_dp() / 2);
		npc->add_ap(npc->get_ap() * 2 / 3);
		npc->add_pp(npc->get_pp() / 2);
		npc->add_to_scene(133, x, y);
		Scum += ({ npc });
	}

	//Sơn Động Thần Bí 3
	for (i = 0; i < 2; i++)
	{
		if (!(p = efun::get_xy_point(135, IS_CHAR_BLOCK)))
			continue;
		x = p / 1000;
		y = p % 1000;
		npc = new(PhiTac);
		npc->set_level(120);
		npc->set_char_type(FIGHTER_TYPE_2);
		NPC_ENERGY_D->init_level(npc, 120);
		npc->add_max_hp(npc->get_max_hp() * 80);
		npc->add_dp(npc->get_dp() / 2);
		npc->add_ap(npc->get_ap() * 2 / 3);
		npc->add_pp(npc->get_pp() / 2);
		npc->add_to_scene(135, x, y);
		Scum += ({ npc });
	}

	//Sơn Động Thái Sơn 1
	for (i = 0; i < 2; i++)
	{
		if (!(p = efun::get_xy_point(117, IS_CHAR_BLOCK)))
			continue;
		x = p / 1000;
		y = p % 1000;
		npc = new(PhiTac);
		npc->set_level(130);
		npc->set_char_type(FIGHTER_TYPE_2);
		NPC_ENERGY_D->init_level(npc, 130);
		npc->add_max_hp(npc->get_max_hp() * 80);
		npc->add_dp(npc->get_dp() / 2);
		npc->add_ap(npc->get_ap() * 2 / 3);
		npc->add_pp(npc->get_pp() / 2);
		npc->add_to_scene(117, x, y);
		Scum += ({ npc });
	}

	//Sơn Động Thái Sơn 3
	for (i = 0; i < 2; i++)
	{
		if (!(p = efun::get_xy_point(119, IS_CHAR_BLOCK)))
			continue;
		x = p / 1000;
		y = p % 1000;
		npc = new(PhiTac);
		npc->set_level(130);
		npc->set_char_type(FIGHTER_TYPE_2);
		NPC_ENERGY_D->init_level(npc, 130);
		npc->add_max_hp(npc->get_max_hp() * 80);
		npc->add_dp(npc->get_dp() / 2);
		npc->add_ap(npc->get_ap() * 2 / 3);
		npc->add_pp(npc->get_pp() / 2);
		npc->add_to_scene(119, x, y);
		Scum += ({ npc });
	}

	call_out("check_time2", 2700);

	CHAT_D->sys_channel(0, "Bọn Sơn Tặc xuất hiện cướp lấy của cải của người dân, nghe nói chúng có rất nhiều kho báu...");
	CHAT_D->sys_channel(0, HIY"Nghe nói Sơn Tặc đang lẫn trốn ở Linh Cốc Động 2, Loan Đạo 2, Khốn Ma Trận 1, Hư Lăng Động, Cầu Cửu Khúc 1, Tru Tiên Trận 1, Tru Tiên Trận 2, Tru Tiên Trận 3!");
	CHAT_D->sys_channel(0, HIY"Nghe nói Sơn Tặc đang lẫn trốn ở Thiên Môn Trận 1, Thiên Môn Trận 2, Thiên Môn Trận 3, Sơn Động Thần Bí 1, Sơn Động Thần Bí 3, Sơn Động Thái Sơn 1, Sơn Động Thái Sơn 3!");
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
	//	CHAT_D->sys_channel(0,HIY"Trộm Bảo Phi Tặc tạm thời đã sợ hãi rút lui !");		
	//	CHAT_D->sys_channel(0,HIY"Trộm Bảo Phi Tặc tạm thời đã sợ hãi rút lui !");		
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
	object owner, * team;
	int level, level2, exp, exp2, pot, alllevel;
	int i, size, status, time, flag;

	if (!objectp(who = me->get_enemy_4())) return;

	if (owner = who->get_owner()) who = owner;
	if (who->is_npc()) return;
	if (who->get_group_id()) return;

	CHAT_D->sys_channel(0, HIY"Nghe nói Sơn Tặc đã bị bằng hữu "HIR"" + who->get_name() + " "HIY"tiêu diệt");
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