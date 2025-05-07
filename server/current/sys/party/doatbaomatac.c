/********************************************************************************************************************************
-----------------------Đoạt Bảo Mã Tặc --------------------
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

#define DoatBaoMaTac 			"npc/event/doatbaomatac"
void check_time2();
void generate_scum();
void generate_scum1();
void generate_scum2();
void generate_scum3();
void generate_scum4();
void generate_scum5();
void destroy_scum();
void generateScum(int mapId, int scrumNumber, int level);
void doat_bao_ma_tac();

string* schoolname = ({ "Đào Hoa Nguyên", "Thục Sơn", "Cấm Vệ Quân", "Đường Môn", "Mao Sơn", "Côn Luân", "Vân Mộng Cốc", });
object* Scum;
mapping mpNianshou;
// 函数：生成二进制码

string* mapNames = ({ });
int* mapIds = ({  });

void SAVE_BINARY() { }

int life_time_mins = 50;
int life_time_sec = life_time_mins * 60;

void create()
{
	//	restore();
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
	if ( mixTime[TIME_WDAY] == 0 ||
		mixTime[TIME_WDAY] == 2 || 
		mixTime[TIME_WDAY] == 4 ||
		mixTime[TIME_WDAY] == 6 
		)
	{
		//	destroy_scum();
		i = 60 * (60 - mixTime[TIME_MIN]);
		call_out("check_time", i + 3600);
		//return;
	}
	else
	{
		i = 60 * (60 - mixTime[TIME_MIN]);
		if (mixTime[TIME_HOUR]% 2 != 0)
		{
			call_out("check_time", i);
		}
		else
		{
			if (mixTime[TIME_HOUR] == 1 || 
				mixTime[TIME_HOUR] == 2 ||
				mixTime[TIME_HOUR] == 3 ||
				mixTime[TIME_HOUR] == 4 ||
				mixTime[TIME_HOUR] == 5 ||
				mixTime[TIME_HOUR] == 6 ||
				mixTime[TIME_HOUR] == 7
				|| mixTime[TIME_HOUR] == 9
				|| mixTime[TIME_HOUR] == 11
				|| mixTime[TIME_HOUR] == 13
				|| mixTime[TIME_HOUR] == 15
				|| mixTime[TIME_HOUR] == 17
				|| mixTime[TIME_HOUR] == 19
				|| mixTime[TIME_HOUR] == 21
				|| mixTime[TIME_HOUR] == 23)
				call_out("check_time", i + 3600);
			else
			{
				if (mixTime[TIME_MIN] >= 45) {
					call_out("check_time", i);
				}
				else {
					doat_bao_ma_tac();
					log_file("boss.txt", short_time() + " Đoạt Bảo tặc\n");
					call_out("check_time", i + 3600);
				}

				
			}
		}
	}

}

void doat_bao_ma_tac() {
	//Create boss
	log_file("boss.txt", short_time() + " Đoạt Bảo Mã Tặc đã xuất hiện\n");
	CHAT_D->sys_channel(0, sprintf("Nghe nói "HIR"Đoạt Bảo Mã Tặc"NOR" đã xuất hiện tại các bản đồ, mọi người hãy kiểm tra xem thực hư ra sao?"));

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

	call_out("check_time2", 2700);

	
}

void generateScum(int mapId, int scrumNumber, int level)
{
	int i, size, z, p, x, y, j;
	object npc;
	object boss;

	for (i = 0; i < scrumNumber; i++)
	{
		if (!(p = efun::get_xy_point(mapId, IS_CHAR_BLOCK)))
			continue;
		x = p / 1000;
		y = p % 1000;
		npc = new(DoatBaoMaTac);

		npc->set_level(level);
		npc->set_char_type(FIGHTER_TYPE_2);
		NPC_ENERGY_D->init_level(npc, level);
		npc->add_max_hp(npc->get_max_hp() * 15);
		npc->add_dp(npc->get_dp() /2);
		npc->add_ap(npc->get_ap() * 3);
		npc->add_pp(npc->get_pp() / 2);

		npc->set_walk_speed(2);
		npc->set_attack_speed(3);
		npc->set_max_seek(6);
		npc->set_walk_step(2);
		npc->set("no_sk04211", 1);
		npc->set("anti_sleep", 1);
		npc->set("anti_blind", 1);
		npc->set_char_type(FIGHTER_TYPE_2);
		npc->add_to_scene(mapId, x, y);
		Scum += ({ npc });
	}

	call_out("check_time2", life_time_sec);
}


//  Random 1
void generate_scum()
{
	int i, size, z, p, x, y, j;
	object npc;

	for (i = 0; i < 10; i++)
	{
		if (!(p = efun::get_xy_point(041, IS_CHAR_BLOCK)))
			continue;
		x = p / 1000;
		y = p % 1000;
		npc = new(DoatBaoMaTac);
		npc->add_to_scene(041, x, y);
		Scum += ({ npc });
	}
	for (i = 0; i < 10; i++)
	{
		if (!(p = efun::get_xy_point(042, IS_CHAR_BLOCK)))
			continue;
		x = p / 1000;
		y = p % 1000;
		npc = new(DoatBaoMaTac);
		npc->add_to_scene(042, x, y);
		Scum += ({ npc });
	}
	for (i = 0; i < 10; i++)
	{
		if (!(p = efun::get_xy_point(043, IS_CHAR_BLOCK)))
			continue;
		x = p / 1000;
		y = p % 1000;
		npc = new(DoatBaoMaTac);
		npc->add_to_scene(043, x, y);
		Scum += ({ npc });
	}

	call_out("check_time2", life_time_sec);

	CHAT_D->sys_channel(0, "Nghe nói có một đám Đoạt Bảo Mã Tặc đã xuất hiện tại Bờ Vô Định Hà, Vô Định Hà 1, Vô Định Hà 2 !");
	CHAT_D->sys_channel(0, "Nghe nói có một đám Đoạt Bảo Mã Tặc đã xuất hiện tại Bờ Vô Định Hà, Vô Định Hà 1, Vô Định Hà 2 !");
	CHAT_D->sys_channel(0, "Nghe nói có một đám Đoạt Bảo Mã Tặc đã xuất hiện tại Bờ Vô Định Hà, Vô Định Hà 1, Vô Định Hà 2 !");
}
//  Random 2
void generate_scum1()
{
	int i, size, z, p, x, y, j;
	object npc;

	for (i = 0; i < 10; i++)
	{
		if (!(p = efun::get_xy_point(151, IS_CHAR_BLOCK)))
			continue;
		x = p / 1000;
		y = p % 1000;
		npc = new(DoatBaoMaTac);
		npc->add_to_scene(151, x, y);
		Scum += ({ npc });
	}
	for (i = 0; i < 10; i++)
	{
		if (!(p = efun::get_xy_point(152, IS_CHAR_BLOCK)))
			continue;
		x = p / 1000;
		y = p % 1000;
		npc = new(DoatBaoMaTac);
		npc->add_to_scene(152, x, y);
		Scum += ({ npc });
	}
	for (i = 0; i < 10; i++)
	{
		if (!(p = efun::get_xy_point(153, IS_CHAR_BLOCK)))
			continue;
		x = p / 1000;
		y = p % 1000;
		npc = new(DoatBaoMaTac);
		npc->add_to_scene(153, x, y);
		Scum += ({ npc });
	}

	call_out("check_time2", life_time_sec);

	CHAT_D->sys_channel(0, "Nghe nói có một đám Đoạt Bảo Mã Tặc đã xuất hiện tại Kênh Trịnh Quốc 1, Kênh Trịnh Quốc 2, Kênh Trịnh Quốc 3 !");
	CHAT_D->sys_channel(0, "Nghe nói có một đám Đoạt Bảo Mã Tặc đã xuất hiện tại Kênh Trịnh Quốc 1, Kênh Trịnh Quốc 2, Kênh Trịnh Quốc 3 !");
	CHAT_D->sys_channel(0, "Nghe nói có một đám Đoạt Bảo Mã Tặc đã xuất hiện tại Kênh Trịnh Quốc 1, Kênh Trịnh Quốc 2, Kênh Trịnh Quốc 3 !");
}
//  Random 3
void generate_scum2()
{
	int i, size, z, p, x, y, j;
	object npc;

	for (i = 0; i < 10; i++)
	{
		if (!(p = efun::get_xy_point(012, IS_CHAR_BLOCK)))
			continue;
		x = p / 1000;
		y = p % 1000;
		npc = new(DoatBaoMaTac);
		npc->add_to_scene(012, x, y);
		Scum += ({ npc });
	}
	for (i = 0; i < 10; i++)
	{
		if (!(p = efun::get_xy_point(013, IS_CHAR_BLOCK)))
			continue;
		x = p / 1000;
		y = p % 1000;
		npc = new(DoatBaoMaTac);
		npc->add_to_scene(013, x, y);
		Scum += ({ npc });
	}
	for (i = 0; i < 10; i++)
	{
		if (!(p = efun::get_xy_point(014, IS_CHAR_BLOCK)))
			continue;
		x = p / 1000;
		y = p % 1000;
		npc = new(DoatBaoMaTac);
		npc->add_to_scene(014, x, y);
		Scum += ({ npc });
	}

	call_out("check_time2", life_time_sec);

	CHAT_D->sys_channel(0, "Nghe nói có một đám Đoạt Bảo Mã Tặc đã xuất hiện tại Bờ Đông Hải, Hải Tân 1, Hải Tân 2 !");
	CHAT_D->sys_channel(0, "Nghe nói có một đám Đoạt Bảo Mã Tặc đã xuất hiện tại Bờ Đông Hải, Hải Tân 1, Hải Tân 2 !");
	CHAT_D->sys_channel(0, "Nghe nói có một đám Đoạt Bảo Mã Tặc đã xuất hiện tại Bờ Đông Hải, Hải Tân 1, Hải Tân 2 !");
}
//  Random 4
void generate_scum3()
{
	int i, size, z, p, x, y, j;
	object npc;

	for (i = 0; i < 10; i++)
	{
		if (!(p = efun::get_xy_point(163, IS_CHAR_BLOCK)))
			continue;
		x = p / 1000;
		y = p % 1000;
		npc = new(DoatBaoMaTac);
		npc->add_to_scene(163, x, y);
		Scum += ({ npc });
	}
	for (i = 0; i < 10; i++)
	{
		if (!(p = efun::get_xy_point(164, IS_CHAR_BLOCK)))
			continue;
		x = p / 1000;
		y = p % 1000;
		npc = new(DoatBaoMaTac);
		npc->add_to_scene(164, x, y);
		Scum += ({ npc });
	}
	for (i = 0; i < 10; i++)
	{
		if (!(p = efun::get_xy_point(261, IS_CHAR_BLOCK)))
			continue;
		x = p / 1000;
		y = p % 1000;
		npc = new(DoatBaoMaTac);
		npc->add_to_scene(261, x, y);
		Scum += ({ npc });
	}

	call_out("check_time2", life_time_sec);

	CHAT_D->sys_channel(0, "Nghe nói có một đám Đoạt Bảo Mã Tặc đã xuất hiện tại Ranh Giới Đầm Lầy, Địa Giới Đầm Lầy, Chân Núi Đại Biệt !");
	CHAT_D->sys_channel(0, "Nghe nói có một đám Đoạt Bảo Mã Tặc đã xuất hiện tại Ranh Giới Đầm Lầy, Địa Giới Đầm Lầy, Chân Núi Đại Biệt !");
	CHAT_D->sys_channel(0, "Nghe nói có một đám Đoạt Bảo Mã Tặc đã xuất hiện tại Ranh Giới Đầm Lầy, Địa Giới Đầm Lầy, Chân Núi Đại Biệt !");
}
//  Random 5
void generate_scum4()
{
	int i, size, z, p, x, y, j;
	object npc;

	for (i = 0; i < 10; i++)
	{
		if (!(p = efun::get_xy_point(141, IS_CHAR_BLOCK)))
			continue;
		x = p / 1000;
		y = p % 1000;
		npc = new(DoatBaoMaTac);
		npc->add_to_scene(141, x, y);
		Scum += ({ npc });
	}
	for (i = 0; i < 10; i++)
	{
		if (!(p = efun::get_xy_point(142, IS_CHAR_BLOCK)))
			continue;
		x = p / 1000;
		y = p % 1000;
		npc = new(DoatBaoMaTac);
		npc->add_to_scene(142, x, y);
		Scum += ({ npc });
	}
	for (i = 0; i < 10; i++)
	{
		if (!(p = efun::get_xy_point(211, IS_CHAR_BLOCK)))
			continue;
		x = p / 1000;
		y = p % 1000;
		npc = new(DoatBaoMaTac);
		npc->add_to_scene(211, x, y);
		Scum += ({ npc });
	}

	call_out("check_time2", life_time_sec);

	CHAT_D->sys_channel(0, "Nghe nói có một đám Đoạt Bảo Mã Tặc đã xuất hiện tại Mã Lăng Đạo, Bạch Mã Trang, Mã Đạp Hồ !");
	CHAT_D->sys_channel(0, "Nghe nói có một đám Đoạt Bảo Mã Tặc đã xuất hiện tại Mã Lăng Đạo, Bạch Mã Trang, Mã Đạp Hồ !");
	CHAT_D->sys_channel(0, "Nghe nói có một đám Đoạt Bảo Mã Tặc đã xuất hiện tại Mã Lăng Đạo, Bạch Mã Trang, Mã Đạp Hồ !");
}
//  Random 6
void generate_scum5()
{
	int i, size, z, p, x, y, j;
	object npc;

	for (i = 0; i < 10; i++)
	{
		if (!(p = efun::get_xy_point(061, IS_CHAR_BLOCK)))
			continue;
		x = p / 1000;
		y = p % 1000;
		npc = new(DoatBaoMaTac);
		npc->add_to_scene(061, x, y);
		Scum += ({ npc });
	}
	for (i = 0; i < 10; i++)
	{
		if (!(p = efun::get_xy_point(062, IS_CHAR_BLOCK)))
			continue;
		x = p / 1000;
		y = p % 1000;
		npc = new(DoatBaoMaTac);
		npc->add_to_scene(062, x, y);
		Scum += ({ npc });
	}
	for (i = 0; i < 10; i++)
	{
		if (!(p = efun::get_xy_point(063, IS_CHAR_BLOCK)))
			continue;
		x = p / 1000;
		y = p % 1000;
		npc = new(DoatBaoMaTac);
		npc->add_to_scene(063, x, y);
		Scum += ({ npc });
	}

	call_out("check_time2", life_time_sec);

	CHAT_D->sys_channel(0, "Nghe nói có một đám Đoạt Bảo Mã Tặc đã xuất hiện tại Sở Phương Thành 1, Sở Phương Thành 2, Sở Phương Thành 3 !");
	CHAT_D->sys_channel(0, "Nghe nói có một đám Đoạt Bảo Mã Tặc đã xuất hiện tại Sở Phương Thành 1, Sở Phương Thành 2, Sở Phương Thành 3 !");
	CHAT_D->sys_channel(0, "Nghe nói có một đám Đoạt Bảo Mã Tặc đã xuất hiện tại Sở Phương Thành 1, Sở Phương Thành 2, Sở Phương Thành 3 !");
}
//Sau 45 phút từ khi Đoạt Bảo xuất hiện sẽ biến mất 
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

	//CHAT_D->sys_channel(0, HIY"Nghe nói đám Đoạt Bảo Mã Tặc đã cao chạy xa bay...!!");

}

void win_bonus_callout(object me, object who)
{
	object owner, * team;
	int level, level2, exp, exp2, pot, alllevel;
	int i, size, status, time, flag, z, x, y, p;
	int knbAmount;
	object item, map;
	string mapName = "";


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
	exp = level * 100;
	pot = level * 5;
	//

	map = get_map_object(get_z(me));
	mapName = map ? map->get_name() : "";

	if (mapName != "") {
		CHAT_D->sys_channel(0, sprintf(HIY"Nghe nói tên "HIG"Đoạt Bảo Mã Tặc"HIY" tại %s đã bị bằng hữu "HIR"%s"HIY" tiêu diệt", mapName, who->get_name()));
	}
	else {
		CHAT_D->sys_channel(0, HIY"Nghe nói tên "HIG"Đoạt Bảo Mã Tặc"HIY" hung hãn đã bị bằng hữu "HIR"" + who->get_name() + ""HIY" tiêu diệt.");
	}

	
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

		//knbAmount = level / 2;
		knbAmount = level;

		if (knbAmount < 1) {
			knbAmount = 1;
		}

		//"sys/sys/test_db"->add_yuanbao_block(team[i], knbAmount / size);

		"sys/sys/test_db"->add_yuanbao(team[i], knbAmount / size);
		write_user(team[i], sprintf(ECHO "Tiêu diệt Đoạt Bảo Mã Tặc nhận được %d Kim Ngân Bảo !", (knbAmount / size)));


		/*write_user(team[i], sprintf(ECHO "Tiêu diệt Đoạt Bảo Mã Tặc nhận được %d Kim Bảo Khóa !", (knbAmount / size) / 10));
		write_user(team[i], sprintf(ECHO "Số dư KNB (Khoá): " + HIY"%d", "sys/sys/test_db"->get_yuanbao_block(team[i])/10));*/
	}

	item = new("/item/common/box/tukim/box");

	z = get_z(me);  x = get_x(me);  y = get_y(me);

	if (p = get_valid_xy(z, x, y, IS_ITEM_BLOCK))
	{
		TEAM_D->drop_item(item, who);
		item->set_user_id(owner);
		item->add_to_scene(z, p / 1000, p % 1000);
		item->set("winner", who);
		item->set("time", time());
	}


	who->delete_save_2("doatbaomatac");
	z = who->get_2("doatbaomatac.z");
	x = who->get_2("doatbaomatac.x");
	y = who->get_2("doatbaomatac.y");
	if (!(p = get_valid_xy(z, x, y, IS_CHAR_BLOCK))) return;
	x = p / 1000;  y = p % 1000;
	who->add_to_scene(z, x, y, 3);
}