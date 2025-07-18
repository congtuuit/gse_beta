/*****劫宝飞贼大搜捕****/

#include <npc.h>
#include <ansi.h>
#include <equip.h>
#include <public.h>
#include <time.h>
#include <action.h>

inherit SAVE_F;
#define FEIZEI "npc/party/0005"							   //	飞贼的文件位置
#define SMART_ALARM_CLOCK_F "/inh/clock/smart_alarm_clock" //	使用闹钟部分功能函数
/*---------------------------------------完毕------------------------------------------*/

/*------------------------------------类私有变量---------------------------------------*/
private int *week_day_can = ({1, 2, 3, 4});
private int day_can_from = 9;
private int day_can_to = 23;
private int slipt_time = 2;
private int alive_time = 2 * 60 * 60 + 10;
private int active_is_open = 1;
private static int broadcast_time = 10;
private static object *nRobber = ({});
private static string *nFamily = ({"Đào Hoa Nguyên", "Thục Sơn", "Cấm Vệ Quân", "Đường Môn", "Mao Sơn", "Côn Luân", "Vân Mộng Cốc"});
private static int *change54 = ({
	0010,
	0011,
	0050,
	0051,
	0052,
	0053,
	0100,
	0101,
	0102,
	0150,
	0151,
	0152,
	0200,
	0201,
	0202,
	0250,
	0251,
	0252,
	0300,
	0301,
	0302,
	0303,
	0304,
	0350,
	0351,
	0352,
	0400,
	0401,
	0402,
	0450,
	0500,
	0502,
	0550,
	0551,
	0552,
	8010,
	8011,
});
private static mapping feizei_info = ([10:([10:({
												   001,
											   }),
											   20:({
													  061,
													  062,
													  063,
													  081,
													  082,
												  }),
											   30:({
													  089,
													  163,
													  164,
													  141,
													  142,
													  211,
												  }),
											   40:({
													  151,
													  152,
													  153,
													  011,
													  012,
													  013,
													  014,
													  015,
												  }),
											   50:({
													  171,
													  172,
													  173,
													  174,
													  071,
													  072,
													  073,
												  }),
											   60:({
													  031,
													  032,
													  033,
													  051,
													  052,
													  053,
												  }),
											   70:({
													  031,
													  032,
													  033,
												  }),
											   80:({
													  321,
													  322,
													  323,
													  051,
													  052,
													  053,
												  }),
											   90:({
													  311,
													  312,
													  313,
													  331,
													  332,
													  333,
													  334,
													  335,
													  341,
													  342,
													  343,
													  344,
													  345,
												  }),
											  100:({
													  391,
													  392,
													  393,
													  372,
													  373,
													  374,
													  381,
												  }),
											  110:({
													  391,
													  392,
													  393,
												  }),

											  //		20 : ({80,61,62,63,284,283,281,282,81,82,251,}),
											  //		30 : ({69,42,43,41,21,141,142,211,89,181,131,271,272,182,242,241,243,132,155,231,}),
											  //		40 : ({501,502,503,}),
											  //		50 : ({528,529,530,512,513,}),
											  //		60 : ({510,511,524,525,526,527,}),
											  //		70 : ({516,517,514,515,}),
											  //		80 : ({504,505,508,509,}),
											  //		90 : ({506,507,520,522,}),
											  //		100: ({521,523,531,532,}),
											  //		110: ({091,092,093,391,392,393,518,519,}),
]),
]);

int turn_on_activity();
int turn_off_activity();
void check_time();
void SAVE_BINARY() {}
string get_save_file()
{
	return "data/feizei" SAVE_EXTENSION;
}

void create()
{
	restore();
	if (active_is_open)
	{
		turn_on_activity();
	}
	else
	{
		turn_off_activity();
	}
}

int turn_on_activity()
{
	active_is_open = 1;
	check_time();
	save();
	return 1;
}

int turn_off_activity()
{
	active_is_open = 0;
	check_time();
	save();
	return 1;
}

int is_active_open()
{
	return active_is_open;
}

int set_active_time(string user_time)
{
	int i, l;
	string *seg0, *seg1, *seg2, seg3;
	int *segi1, segi2, segi3, segi4;
	if (!user_time)
	{
		return 0;
	}
	user_time = replace_string(user_time, "\"", "");
	user_time = replace_string(user_time, " ", "");
	user_time = replace_string(user_time, ":", ";");
	seg0 = explode(user_time, ";");
	if (sizeof(seg0) < 2)
	{
		return 0;
	}
	seg1 = explode(seg0[0], ",");
	if (!l = sizeof(seg1) || l > 7)
	{
		return 0;
	}
	segi1 = ({});
	for (i = 0; i < l; i++)
	{
		segi1 += ({to_int(seg1[i]) % 7});
	}
	seg2 = explode(seg0[1], ",");
	if (sizeof(seg2) < 2)
	{
		return 0;
	}
	segi2 = to_int(seg2[0]);
	segi3 = to_int(seg2[1]);
	if (segi2 >= segi3)
	{
		return 0;
	}
	if (sizeof(seg0) == 3)
	{
		segi4 = to_int(seg0[2]);
		if (!segi4)
		{
			return 0;
		}
		slipt_time = segi4;
		alive_time = slipt_time * 60 * 60 + 10;
	}

	week_day_can = segi1;
	day_can_from = segi2;
	day_can_to = segi3;
	check_time();
	save();
	return 1;
}

string get_active_time()
{
	int i;
	string *week_day = ({"Chủ nhật", "Thứ hai", "Thứ ba", "Thứ tư", "Thứ năm", "Thứ sáu", "Thứ bảy"});
	string ret_str = "\nHoạt động này được tổ chức hàng tuần";
	for (i = 0; i < sizeof(week_day_can); i++)
	{
		ret_str += sprintf("%s，", week_day[week_day_can[i]]);
	}

	return ret_str + sprintf(" Mở cửa từ %d giờ đến %d giờ.\nCập nhật lại sau mỗi %d giờ.\nHoạt động hiện tại %s", day_can_from, day_can_to, slipt_time, active_is_open ? "đã mở" : "chưa mở");
	// return ret_str+sprintf(" %d点至%d点开放。\n每隔%d个小时重新刷新。\n当前活动%s",day_can_from,day_can_to,slipt_time,active_is_open ? "已经开启":"还没有开启");
}

int get_alive_time()
{
	return alive_time;
}

void message()
{
	int i, size;
	object *nTmp = ({});
	remove_call_out("message");
	size = sizeof(nRobber);
	if (!size)
	{
		return;
	}
	for (i = 0; i < size; i++)
	{
		if (!objectp(nRobber[i]))
		{
			continue;
		}
		nTmp += ({nRobber[i]});
	}
	if (!sizeof(nTmp))
	{
		nRobber = ({});
		CHAT_D->sys_channel(0, HIY "Mọi người cố gắng, đã thành công tiêu diệt Trộm Bảo Phi Tặc và Phi Tặc không dám xuất hiện nữa !");
		return;
	}

	nRobber = nTmp;
	call_out("message", broadcast_time * 60);
}

void before_destruct()
{
	int i, size;
	for (i = 0, size = sizeof(nRobber); i < size; i++)
	{
		if (!objectp(nRobber[i]))
		{
			continue;
		}
		nRobber[i]->remove_from_scene(FALL_ACT);
		destruct(nRobber[i]);
	}
	nRobber = ({});
}

void make_feizei()
{
	int i, x, y, z, p, num, level;
	mixed *number_keys, *level_keys;
	object robber, map;
	number_keys = keys(feizei_info);
	if (sizeof(number_keys) > 0)
	{
		foreach (num in number_keys)
		{
			level_keys = keys(feizei_info[num]);
			if (sizeof(level_keys) > 0)
			{
				foreach (level in level_keys)
				{
					for (i = 0; i < num; i++)
					{
						z = feizei_info[num][level][random(sizeof(feizei_info[num][level]))];
						if (!(p = get_xy_point(z, IS_CHAR_BLOCK)))
						{
							continue;
						}
						if (!objectp(map = get_map_object(z)) || !map->is_scene())
						{
							continue;
						}
						x = p / 1000;
						y = p % 1000;
						robber = new(FEIZEI);
						if (!robber)
						{
							return;
						}
						robber->set_level(level);
						robber->set_char_type(FIGHTER_TYPE_2);
						NPC_ENERGY_D->init_level(robber, level);
						if (level <= 40)
						{
							robber->add_max_hp(robber->get_max_hp() * 20);
							robber->add_dp(robber->get_dp() / 10);
							robber->add_ap(robber->get_ap() / 10);
							robber->add_pp(robber->get_pp() / 10);
						}
						else
						{
							robber->add_max_hp(robber->get_max_hp() * 40);
							robber->add_dp(robber->get_dp() / 2);
							robber->add_ap(robber->get_ap() * 2 / 5);
							robber->add_pp(robber->get_pp() / 2);
						}
						robber->set("x", x);
						robber->set("y", y);
						map->add_reset(robber);
						robber->add_to_scene(z, x, y);
						nRobber += ({robber});
					}
				}
			}
		}
	}
}

void byebye_feizei()
{
	before_destruct();
}

void check_time()
{
	int iTime, rate, level, next_time;
	int i, num, *nScene, size;
	mixed *mixTime;

	remove_call_out("check_time");
	remove_call_out("message");
	byebye_feizei();
	if (!active_is_open)
	{
		return;
	}
	if (MAIN_D->get_host_type() == 6012)
	{
		return;
	}
	iTime = time();
	mixTime = localtime(iTime);
	if (member_array(mixTime[TIME_WDAY], week_day_can) == -1)
	{
		next_time = SMART_ALARM_CLOCK_F->find_next_time_stamp("week", sprintf("%d %02d:00:02", (mixTime[TIME_WDAY] + 1) % 7, day_can_from), "second");
		if (next_time > 0)
		{
			call_out("check_time", next_time - iTime);
		}
		return;
	}
	if (mixTime[TIME_HOUR] < day_can_from || mixTime[TIME_HOUR] > day_can_to)
	{
		CHAT_D->sys_channel(0, HIY "Mọi người cố gắng, đã thành công tiêu diệt Trộm Bảo Phi Tặc và Phi Tặc không dám xuất hiện nữa !");
		next_time = SMART_ALARM_CLOCK_F->find_next_time_stamp("hour", sprintf("%d:00:02", day_can_from), "second");
		if (next_time > 0)
		{
			call_out("check_time", next_time - iTime);
		}
		return;
	}
	make_feizei();
	CHAT_D->sys_channel(0, HIY "Nghe nói có một đám Trộm Bảo Phi Tặc mang theo rất nhiều bảo vật đã xuất hiện tại các bản đồ luyện cấp！！！！");
	CHAT_D->sys_channel(0, HIY "Nghe nói có một đám Trộm Bảo Phi Tặc mang theo rất nhiều bảo vật đã xuất hiện tại các bản đồ luyện cấp！！！！");
	CHAT_D->sys_channel(0, HIY "Nghe nói có một đám Trộm Bảo Phi Tặc mang theo rất nhiều bảo vật đã xuất hiện tại các bản đồ luyện cấp！！！！");
	message();
	next_time = SMART_ALARM_CLOCK_F->find_next_time_stamp("hour", sprintf("%d:00:02", mixTime[TIME_HOUR] + (slipt_time - ((mixTime[TIME_HOUR] - day_can_from) % slipt_time))), "second");
	if (next_time > 0)
	{
		call_out("check_time", next_time - iTime);
	}
}

object drop_food_wine(int level)
{
	int *nTmp;
	object item;
	mapping mpFood = ([130:({3301, 3302}),
					   110:({3310, 3311}),
						90:({3303, 3304}),
						70:({3320, 3280}),
						50:({3281, 3285}),
						30:({3283, 3284}),
						10:({3282, 3325}),
	]);

	if (random(2)) // 酒
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
	else // 食物
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
	item->set_amount(10);
	return item;
}

void drop_items(object me, object who)
{
	int x, y, z, p, i, rate, rate1, level, level2;
	string *nTmp, id, owner, file;
	object item, leader;

	level = me->get_level();
	z = get_z(me);
	x = get_x(me);
	y = get_y(me);
	id = who->get_leader();
	if (!id)
	{
		owner = who->get_id();
	}
	else
	{
		if (leader = find_player(id))
		{
			owner = leader->get_id();
		}
		else
		{
			owner = who->get_id();
		}
	}

	for (i = 0; i < 10; i++)
	{
		if (p = get_valid_xy(z, x, y, IS_ITEM_BLOCK))
		{
			item = new("/item/std/0001");
			item->set_value(level * 50);
			TEAM_D->drop_item(item, who);
			item->set_user_id(owner);
			item->add_to_scene(z, p / 1000, p % 1000);
			item->set("winner", who);
			item->set("time", time());
		}
	}

	for (i = 0; i < 5; i++)
	{
		if (p = get_valid_xy(z, x, y, IS_ITEM_BLOCK))
		{
			item = drop_food_wine(level);
			if (!item)
			{
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
	if (!p)
	{
		return;
	}

	rate1 = me->correct_drop_rate(me->get_level() - who->get_level()) * who->get_online_rate() / 100;
	if (rate1 < 40)
	{
		return;
	}

	rate = random(10000);
	item = 0;
	if (rate < 1000)
	{
		file = file = WEAPON_FILE->get_weapon_file_2((level / 10) * 10);
		item = new(file);
		if (!item)
		{
			return 0;
		}
		ITEM_EQUIP_D->init_equip_prop_1(item);
	}
	else if (rate < 2000)
	{
		file = ARMOR_FILE->get_armor_file_2((level / 10) * 10);
		item = new(file);
		if (!item)
		{
			return 0;
		}
		ITEM_EQUIP_D->init_equip_prop_1(item);
	}
	else if (rate < 3000)
	{
		item = new("/item/44/4403");
	}
	else if (rate < 3500)
	{
		item = new(sprintf("/item/01/020%d", random(3)));
	}
	else if (rate < 4000)
	{
		item = new("/item/91/9167");
	}
	else if (rate < 8300)
	{
		level2 = me->get_level() / 10 * 10;
		if (level2 > 120)
		{
			level2 = 120;
		}
		if (load_object(file = "/quest/product2"->get_random_level_product(level2, level2)))
		{
			item = new(file);
		}
		else
		{
			return 0;
		}
	}
	else if (rate < 9871)
	{
		item = new(BOOK_FILE->get_book_file());
	}
	else if (rate < 9946)
	{
		file = STONE_FILE->get_diamond_file();
		item = new(file);
		if (!item)
		{
			return 0;
		}
		item->set_level(1);
	}
	else if (rate < 9951)
	{
		item = new("/item/08/0003");
	}
	else if (rate < 9956)
	{
		item = new("/item/08/0004");
	}
	else if (rate < 9962)
	{
		item = new("/item/08/0002");
	}
	else if (rate < 9969)
	{
		item = new("/item/44/4403");
	}
	else if (rate < 9970)
	{
		item = new("/item/08/0001");
	}
	else if (rate < 9985)
	{
		item = new("/item/sell/0007");
	}
	else if (rate < 10000)
	{
		item = new("/item/sell/0009");
	}
	if (!item)
	{
		return 0;
	}

	TEAM_D->drop_item(item, who);
	item->set_user_id(owner);
	item->add_to_scene(z, p / 1000, p % 1000);
	item->set("winner", who);
	item->set("time", time());
}

void win_bonus_callout(object me, object who)
{
	object owner, *team;
	int level, level2, exp, exp2, pot, alllevel;
	int i, size, status, time, flag;

	if (!objectp(who = me->get_enemy_4()))
		return;

	if (owner = who->get_owner())
		who = owner;
	if (who->is_npc())
		return;
	if (who->get_group_id())
		return;

	//"sys/sys/test_db"->add_yuanbao(who, 10);
	CHAT_D->sys_channel(0, HIY "Nghe nói tên Trộm Bảo Phi Tặc đã bị bằng hữu " + who->get_name() + " tiêu diệt");
	if (who->get_online_rate())
	{
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
		team = ({who});
		size = 1;
	}

	alllevel = 0;
	for (i = 0; i < size; i++)
		if (team[i])
		{
			alllevel += team[i]->get_level();
		}
	if (alllevel == 0)
		alllevel = 1;
	exp = level * 500;
	pot = level * 5;
	for (i = 0; i < size; i++)
		if (team[i])
		{
			level2 = level - team[i]->get_level();
			exp2 = exp * team[i]->get_level() / alllevel;
			exp2 = me->correct_exp_bonus(level, level2, exp2) * who->get_online_rate() / 100;

			if (exp2 < 5)
				exp2 = 5;
			exp2 = exp2 * team[i]->get_online_rate() / 100;
			pot = pot * team[i]->get_online_rate() / 100;
			team[i]->add_exp(exp2);
			team[i]->add_potential(pot);
			
			//"sys/sys/test_db"->add_yuanbao(team[i], level);
			//write_user(team[i], sprintf(ECHO "Bạn tiêu diệt Phi Tặc cấp %d và nhận được %d Kim Bảo !", level, level / 10));
		}
}