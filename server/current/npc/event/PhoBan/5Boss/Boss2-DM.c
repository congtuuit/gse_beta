#include <npc.h>
#include <ansi.h>
#include <equip.h>
#include <effect.h>
#include <cmd.h>
#include <skill.h>
#include <task.h>
#include <action.h>
#define _DEBUG(x)	tell_user(find_char("971"),x);

inherit BADMAN;

int LEVEL = 75;
int flag;
int saytime, hptime, RelaxTime, pTime, pTime1, pTime2, pTime3, iRelax, i2618, i3641, i3642, SumTime;
//string *nFamily = ({"Đào Hoa Nguyên","Thục Sơn","Cấm Vệ Quân","Đường Môn","Mao Sơn","Côn Luân","Vân Mộng Cốc"});
// 函数：是否不能进城
string* soldier = ({ "Sĩ Binh Nhất Hiệu","Sĩ Binh Nhị Hiệu","Sĩ Binh Tam Hiệu","Sĩ Binh Tứ Hiệu","Sĩ Binh Ngũ Hiệu","Sĩ Binh Lục Hiệu","Sĩ Binh Thất Hiệu","Sĩ Binh Bát Hiệu", });
mapping mpSoldier = ([]);
int cannot_enter_city() { return 1; }
int get_id_color() { return 0107215; }
//int get_id_color() { return 0x800080; }
void drop_items(object me, object who);
int is_caster() { return 1; }
int get_hair() { return 1006; }
int get_hair_color() { return 0x00C0C0C0; }
int get_photo() { return 2; }
//int get_armor_code() { return 570100; }
int get_armor_code() { return 100000; }
int get_armor_color_1() { return 0x42084208; }
int get_weapon_color() { return 0; }
int get_weapon_color_2() { return 0x00C0C0C0; }
int get_back() { return 1; }
int get_back2() { return 1; }
int get_back_color() { return 0x00C0C0C0; }
int get_back2_color() { return 0x00C0C0C0; }

// 函数：列示给新玩家(对方进场景)(NPC 专用)
void show_to_user(object who)
{
	object me = this_object(), map;
	int id = getoid(me);
	int type = 0, armor, speed = 0;
	int gender;
	if (get_invisible(me) == 2 && who != me) return;
	armor = get_armor_code();
	if (get_effect(me, EFFECT_MAGIC_4243))
	{
		type = get_save("pf#4243");
		armor = type;
		speed = 2;
	}
	else
		if (get_effect(me, EFFECT_MAGIC_CARD))
		{
			type = get_save("magic_card");
			armor = type;
			speed = 2;
		}
		else
			if (me->get_save("temp_act"))
			{
				type = me->get_save("temp_act");
				armor = type;
				speed = 2;
			}
			else
				if (me->get("temp_act"))
				{
					type = me->get("temp_act");
					armor = type;
					speed = 2;
				}
				else type = get_head_code();
	if ("/sys/sys/count"->get_new_person()) type = me->get_hair();
	if ("/sys/sys/count"->get_new_person())
		send_user(who, "%c%c%d%w%w%c%c%c%w%d%w%w%w%w%w%w%w%w%w%w%c%c%c%c%d%s", 0x69, 10, id,
			get_x(me), get_y(me), get_d(me), get_char_type(), get_char_action(),
			me->get_photo(), armor, me->get_armor_color_1(),
			type, me->get_hair_color(), me->get_back(), me->get_back_color(), me->get_back2(), me->get_back2_color(),
			get_weapon_code_2(), me->get_weapon_color(), me->get_weapon_color_2(),
			0, 0,
			get_hp_cent(), speed, 0, get_short());
	else
		send_user(who, "%c%c%d%w%w%c%c%c%d%w%w%c%c%c%c%d%s", 0x69, 0, id,
			get_x(me), get_y(me), get_d(me), get_char_type(), get_char_action(),
			armor, get_armor_color_1(), get_weapon_code_2(), 0, 0,
			get_hp_cent(), speed, 0, get_short());

	if (!is_player(me)) send_user(who, "%c%d%d", 0x66, id, 0xff6500);
	if (me->get_id_color()) send_user(who, "%c%d%d", 0x66, id, me->get_id_color());
	if (me->get_ride()) send_user(who, "%c%d%d", 0x62, id, me->get_ride());
	CHAR_CHAR_D->send_loop_perform(me, who);    // 显示持续效果
	CHAR_CHAR_D->send_loop_perform_2(me, who);    // 显示持续图标
}

// 函数：列示给玩家看(新进入场景)(NPC 专用)
varargs void show_to_scene(object* user, int x, int y, int d, int add_pf, int add_pf_2)
{
	object me = this_object(), map;
	int id = getoid(me);
	int type = 0, armor, speed = 0;
	if (get_invisible(me) == 2) return;
	armor = get_armor_code();
	if (get_effect(me, EFFECT_MAGIC_4243))
	{
		type = get_save("pf#4243");
		armor = type;
		speed = 2;
	}
	else
		if (get_effect(me, EFFECT_MAGIC_CARD))
		{
			type = get_save("magic_card");
			armor = type;
			speed = 2;
		}
		else
			if (me->get_save("temp_act"))
			{
				type = me->get_save("temp_act");
				armor = type;
				speed = 2;
			}
			else
				if (me->get("temp_act"))
				{
					type = me->get("temp_act");
					armor = type;
					speed = 2;
				}
				else type = get_head_code();
	if ("/sys/sys/count"->get_new_person()) type = me->get_hair();
	if ("/sys/sys/count"->get_new_person())
	{
		if (!add_pf)
			send_user(user, "%c%c%d%w%w%c%c%c%w%d%w%w%w%w%w%w%w%w%w%w%c%c%c%c%d%s", 0x69, 10, id,
				get_x(me), get_y(me), get_d(me), get_char_type(), get_char_action(),
				me->get_photo(), armor, me->get_armor_color_1(),
				type, me->get_hair_color(), me->get_back(), me->get_back_color(), me->get_back2(), me->get_back2_color(),
				get_weapon_code_2(), me->get_weapon_color(), me->get_weapon_color_2(),
				0, 0,
				get_hp_cent(), speed, 0, get_short());
		else if (!add_pf_2)
			send_user(user, "%c%c%d%w%w%c%c%c%w%d%w%w%w%w%w%w%w%w%w%w%c%c%c%w%c%c%c%d%s", 0x69, 11, id,
				get_x(me), get_y(me), get_d(me), get_char_type(), get_char_action(),
				me->get_photo(), armor, me->get_armor_color_1(),
				type, me->get_hair_color(), me->get_back(), me->get_back_color(), me->get_back2(), me->get_back2_color(),
				get_weapon_code_2(), me->get_weapon_color(), me->get_weapon_color_2(),
				0, 0,
				get_hp_cent(), add_pf, 1, OVER_BODY, speed, 0, get_short());
		else
			send_user(user, "%c%c%d%w%w%c%c%c%w%d%w%w%w%w%w%w%w%w%w%w%c%c%c%w%c%c%w%c%c%c%d%s", 0x69, 12, id,
				get_x(me), get_y(me), get_d(me), get_char_type(), get_char_action(),
				me->get_photo(), armor, me->get_armor_color_1(),
				type, me->get_hair_color(), me->get_back(), me->get_back_color(), me->get_back2(), me->get_back2_color(),
				get_weapon_code_2(), me->get_weapon_color(), me->get_weapon_color_2(),
				0, 0,
				get_hp_cent(), add_pf, 1, OVER_BODY, add_pf_2, 1, OVER_BODY, speed, 0, get_short());
	}
	else
	{
		if (!add_pf)
			send_user(user, "%c%c%d%w%w%c%c%c%d%w%w%c%c%c%c%d%s", 0x69, 0, id,
				x, y, d, get_char_type(), get_char_action(),
				armor, get_armor_color_1(), get_weapon_code_2(), 0, 0,
				get_hp_cent(), speed, 0, get_short());
		else if (!add_pf_2)
			send_user(user, "%c%c%d%w%w%c%c%c%d%w%w%c%c%c%w%c%c%c%d%s", 0x69, 1, id,
				x, y, d, get_char_type(), get_char_action(),
				armor, get_armor_color_1(), get_weapon_code_2(), 0, 0,
				get_hp_cent(), add_pf, 1, OVER_BODY, speed, 0, get_short());
		else    send_user(user, "%c%c%d%w%w%c%c%c%d%w%w%c%c%c%w%c%c%w%c%c%c%d%s", 0x69, 2, id,
			x, y, d, get_char_type(), get_char_action(),
			armor, get_armor_color_1(), get_weapon_code_2(), 0, 0,
			get_hp_cent(), add_pf, 1, OVER_BODY, add_pf_2, 1, OVER_BODY, speed, 0, get_short());

	}
	if (!is_player(me)) send_user(user, "%c%d%d", 0x66, id, 0xff6500);
	if (me->get_id_color()) send_user(user, "%c%d%d", 0x66, id, me->get_id_color());
	if (me->get_ride()) send_user(user, "%c%d%d", 0x62, id, me->get_ride());
	//	send_user( get_scene_object_2(me, USER_TYPE), "%c%d%w%c%c%c", 0x6f, getoid(me), 9325, 1,UNDER_FOOT, PF_LOOP );
	CHAR_CHAR_D->send_loop_perform(me, user);    // 显示持续效果
	CHAR_CHAR_D->send_loop_perform_2(me, user);    // 显示持续图标
}

// 函数：修正经验奖励
int correct_exp_bonus(int level, int level2, int exp) { return exp; }

// 函数：修正掉宝率
int correct_drop_rate(int level) { return 100; }

// 函数：获取人物名称
string get_short()
{
	return get_name() + "||||" + PPM"Ngũ Hổ Tướng";
	//	return get_name() + "||||" + CRF"Thiên Hạ Đệ Nhất";
}

void init_fight_status()
{
	set_ap(4000);
	set_dp(500);
	set_cp(2000);
	set_pp(500);
	set_sp(1000);
}

// 函数：构造处理
void create()
{
	object me = this_object();
	set_name("Nhạc Phi");
	set_fam_name("Đường Môn");
	//set_skill(0261, LEVEL);
	set_skill(0363, LEVEL);
	set_skill(0364, 1);
	set_skill(0365, LEVEL);
	set_skill(0368, LEVEL);
	set_skill(0381, LEVEL);
	set_skill(0382, LEVEL);
	set_skill(0383, LEVEL);
	set_skill(0384, LEVEL);
	set_skill(0385, LEVEL);
	set_level(LEVEL);
	set_max_hp(6000000);
	set_max_mp(100000000);
	set_weapon_code(THROWING);
	set_weapon_color(13);
	set_double_rate(5000);
	set_hit_rate(200);
	set_hit_rate_3(60);
	set_dodge_rate(60);
	set_dodge_rate_2(30);
	set_skill(0104, LEVEL);
	set_skill(0109, LEVEL);
	set_skill(0111, LEVEL);
	set_skill(0121, LEVEL);
	set_skill(0131, LEVEL);
	set_skill(0141, LEVEL);
	set_skill(0151, LEVEL);
	set_skill(0161, LEVEL);
	set_skill(0202, LEVEL);
	set_skill(0401, LEVEL);
	set_skill(0402, LEVEL);
	set_skill(0403, LEVEL);
	set_skill(0404, LEVEL);
	set_skill(0405, LEVEL);
	set_skill(0430, 5);
	set_skill(0431, 5);
	set_skill(0432, 5);
	set_skill(0433, 5);
	set_skill(0434, 5);
	set_skill(0435, 5);
	set_skill(0436, 5);
	set_skill(0437, 8);
	set_skill(0438, 8);
	init_fight_status();
	set_walk_speed(3);
	set_attack_speed(3);
	set_max_seek(8);
	set_walk_step(2);
	set("no_sk04211", 1);	//变身术对其没有效果
	set("anti_sleep", 1);	//不会昏迷
	set("anti_no_move", 1);	//不会冻结
	set("anti_blind", 1);    //No Blind

	setup();
	set_char_type(FIGHTER_TYPE_2);
	SumTime = 0;

}

int can_fight(object who)
{
	object owner;
	string leader, id;
	if (who->is_die())
	{
		set_enemy(0);
		return 0;
	}
	if (who->is_npc() && objectp(owner = who->get_owner())) who = owner;
	if (who->is_npc())
	{
		set_enemy(0);
		return 0;
	}
	if (who->is_user() && who->get_level() >= 105) {
		set_enemy(0);
		return 0;
	}
	return ::can_fight(who);
}

int can_be_fighted(object who)
{
	object owner;
	string leader, id;
	if (who->is_npc() && objectp(owner = who->get_owner())) who = owner;
	if (who->is_npc())
	{
		set_enemy(0);
		return 0;
	}
	
	return ::can_be_fighted(who);
}

void heart_beat_walk()
{
	int i, x, y, z, x0, y0, z0, p, x1, y1;
	object enemy, me = this_object();

	if (iRelax)
		return;
	enemy = get_enemy();
	if (objectp(enemy))
	{
		if (enemy->is_die())
			set_enemy(0);
		if (gone_time(saytime) >= 60)
		{
			saytime = time();
			if (random(100) < 70)
			{
				SAY_CMD->say(me, "Các ngươi có nhận ra ta là ai không ? #29 ");
			}
		}
	}
	else if (RelaxTime == 0)
	{
		RelaxTime = time();
	}
	//	if ( RelaxTime && gone_time(RelaxTime) >= 120 )
	if (RelaxTime && gone_time(RelaxTime) >= 2000000000)
	{
		RelaxTime = 0;
		init_fight_status();
		iRelax = 1;
	}
	if (!get_effect(me, EFFECT_CHAR_NO_PF_0))		//不沉默
	{
		set_effect(me, EFFECT_CHAR_NO_PF_0, 3600);
	}
	if (!get_effect(me, EFFECT_CHAR_WOUND_0))		//不负伤
	{
		set_effect(me, EFFECT_CHAR_WOUND_0, 3600);
	}
	if (!get_effect(me, EFFECT_CHAR_FAINT_0))		//不眩晕
	{
		set_effect(me, EFFECT_CHAR_FAINT_0, 3600);
	}
	if (!get_effect(me, EFFECT_CHAR_SHUT_0))		//不囚禁
	{
		set_effect(me, EFFECT_CHAR_SHUT_0, 3600);
	}
	if (!get_effect(me, EFFECT_CHAR_DREAM_0))		//不囚禁
	{
		set_effect(me, EFFECT_CHAR_DREAM_0, 3600);
	}
	if (!get_effect(me, EFFECT_CHAR_LAZY_0))		//不延缓
	{
		set_effect(me, EFFECT_CHAR_LAZY_0, 3600);
	}
	if (gone_time(hptime) >= 15)
	{
		hptime = time();
	}

	::heart_beat_walk();
}
void heart_beat_attack()
{
	::heart_beat_attack();

}


void summon_guard()
{
	int i, size, x, y, z, count, p;
	object npc, me = this_object();

	x = get_x(me); y = get_y(me); z = get_z(me);
	for (i = 0, size = sizeof(soldier); i < size; i++)
	{
		if (objectp(get(sprintf("guard%d", i))))
			continue;
		p = get_valid_xy(z, x + random(10) - 5, y + random(10) - 5, IS_CHAR_BLOCK);
		if (!p)
			continue;
		npc = new("npc/boss/00031");
		if (!npc)
			break;
		npc->set_name(soldier[i]);
		set(sprintf("guard%d", i), npc);
		add("guard", ({ npc }));
		if (soldier[i] == "Sĩ Binh Nhất Hiệu" || soldier[i] == "Sĩ Binh Nhị Hiệu" || soldier[i] == "Sĩ Binh Tam Hiệu")
		{
			npc->set_char_picid(1243);
			npc->set_max_hp(20000);
			npc->set_ap(620);
			npc->set_dp(1000);
			npc->set_cp(0);
			npc->set_pp(350);
			npc->set_sp(350);
			npc->set_walk_speed(2);
			npc->set_attack_speed(15);
		}
		else if (soldier[i] == "Sĩ Binh Ngũ Hiệu" || soldier[i] == "Sĩ Binh Tứ Hiệu" || soldier[i] == "Sĩ Binh Lục Hiệu")
		{
			npc->set_char_picid(1243);
			npc->set_max_hp(20000);
			npc->set_ap(220);
			npc->set_dp(1000);
			npc->set_cp(820);
			npc->set_pp(880);
			npc->set_sp(700);
			npc->set_walk_speed(5);
			npc->set_attack_speed(10);
			npc->set_perform_2_file("npc/boss/00031");
		}
		else
		{
			npc->set_char_picid(4143);
			npc->set("caster", 1);
			npc->set_weapon_code(THROWING);
			npc->set_max_hp(20000);
			npc->set_ap(600);
			npc->set_dp(500);
			npc->set_cp(0);
			npc->set_pp(380);
			npc->set_sp(1100);
			npc->set_walk_speed(5);
			npc->set_attack_speed(15);
		}
		npc->add_to_scene(z, p / 1000, p % 1000);
		npc->set_owner(me);
		NPC_SLAVE_D->find_enemy(npc);    // 寻找敌人
		send_user(get_scene_object_2(npc, USER_TYPE), "%c%d%w%c%c%w%c%c%w%c%c%c", 0x6f, getoid(npc),
			41311, 1, OVER_BODY, 41312, 1, OVER_BODY, 41313, 1, UNDER_FOOT, PF_ONCE);
	}

}
// 函数：特技攻击对手
int perform_action(object who)
{
	int rate, x, y, z, i, size, ret;
	object me = this_object(), * char;

	if (!who) return 2;
	if (who->is_die()) return 2;
	if (distance_between(me, who) > me->get_max_seek() * 3 / 2)
	{
		return 0;
	}
	RelaxTime = 0;
	iRelax = 0;

	if (!me->get_effect(me, EFFECT_USER_HURT))
	{
		PF_FILE_03632->cast_done_npc(me);
	}

	if (gone_time(i2618) > 4)
	{
		i2618 = time();
		z = get_z(who);  x = get_x(who);  y = get_y(who);
		if (who)
		{
			if (!inside_screen_2(me, who)) return 1;
			z = get_z(who);  x = get_x(who);  y = get_y(who);
			me->set_time("pf", time());
			me->to_front_xy(x, y);
			send_user(get_scene_object_2(me, USER_TYPE), "%c%d%d%c%c%c%d", 0x41, getoid(me), time2(), 1, 70, get_d(me), getoid(who));
		}
		else
		{
			if (!inside_screen(get_x(me), get_y(me), x, y)) return 1;
			z = get_z(me);
			me->set_time("pf", time());
			me->to_front_xy(x, y);
			send_user(get_scene_object_2(me, USER_TYPE), "%c%d%d%c%c%c%d", 0x41, getoid(me), time2(), 1, 70, get_d(me), 0);
		}
		set_heart_state(me, MAGIC_STAT);
		set_heart_count_2(me, 1);
		me->add_2("go_count.count2", 1);
		me->set_cast_file(__FILE__);
		me->set_cast_arg(sprintf("%d,%d,%d,%d,%d", me->get_skill(0261), z, x, y, 2618));
		return 1;
	}
	if (gone_time(i3641) > 20)
	{
		i3641 = time();
		char = get_scene_object_2(me, USER_TYPE);
		set_effect(me, EFFECT_CHAR_MOVE, 15 + (me->get_skill(0364) - 4) / 10 * 2);
		send_user(me, "%c%w%w%c", 0x81, 3641, get_effect_3(me, EFFECT_CHAR_MOVE), EFFECT_GOOD);
		send_user(char - ({ me }), "%c%d%w%c%c", 0x83, getoid(me), 3641, 1, EFFECT_GOOD);
		send_user(char, "%c%d%w%c%c%c", 0x6f, getoid(me), 36411, 1, OVER_BODY, PF_ONCE);
		me->set_save("03641", 30);
		return 1;
	}
	if (gone_time(i3642) > 5)
	{
		i3642 = time();
		CHAR_FIGHT_D->set_enmity1(me, 30);
		set_heart_state(me, MAGIC_STAT);
		set_heart_count_2(me, 9);
		me->add_2("go_count.count2", 9);
		me->set_cast_file("skill/03/03642");
		char = get_scene_object_2(me, USER_TYPE);
		set_effect(me, EFFECT_03642, 5);
		send_user(me, "%c%w%w%c", 0x81, 3642, get_effect_3(me, EFFECT_03642), EFFECT_GOOD);
		send_user(char - ({ me }), "%c%d%w%c%c", 0x83, getoid(me), 3642, 1, EFFECT_GOOD);
		send_user(get_scene_object_2(me, USER_TYPE), "%c%d%w%c%c%c", 0x6f, getoid(me), 3642, 1, OVER_BODY, PF_ONCE);
		return 1;
	}
	if (gone_time(pTime1) > 5)
	{
		pTime1 = time();
		char = get_scene_object_2(me, USER_TYPE) - ({ me });
		if (!sizeof(char))
			return;
		who = char[random(sizeof(char))];
		switch (random(2))
		{
		default:
			"skill/02/02613"->perform_action_npc(me, who);
			break;
		case 1:
			"skill/02/02613"->perform_action_npc(me, who);
			break;
		
		}
		return 1;
	}
	if (gone_time(pTime2) > 15)
	{
		pTime2 = time();
		me->add_hp(2000 * (100 + me->get_healing_rate()) / 100);
		me->add_mp(2000 * (100 + me->get_healing_rate()) / 100);
		send_user(get_scene_object_2(me, USER_TYPE), "%c%d%w%c%c%c", 0x6f, getoid(me), 9154, 1, OVER_BODY, PF_ONCE);
		return 1;
	}
	send_user(get_scene_object_2(me, USER_TYPE), "%c%d%d%c%c%c%d", 0x41, getoid(me), time2(), 1, 10, get_d(me), getoid(who));
	ret = CHAR_FIGHT_D->throwing_done(me, who, HIT_THROWING, 10 + (me->get_skill(0261) - 1) / 10 * 8);
	//if (who->get("anti_faint")) return 2;
	if (ret > 0 && random(100) < 30)
	{
		if (!who) return 1;
		if (get_effect(who, EFFECT_CHAR_FAINT)
			|| get_effect(who, EFFECT_CHAR_FAINT_0)) return 1;    // 执行成功
		if (who->get_perform("02222#")) return 1;
		char = get_scene_object_2(who, USER_TYPE);
		set_effect(who, EFFECT_CHAR_FAINT, 3);    // 小心准备 me
		CHAR_CHAR_D->init_loop_perform(who);
		if (get_heart_state(who) == MAGIC_STAT) send_user(char, "%c%d%d%c", 0x40, getoid(who), time2(), MAGIC_ACT_END);    // 结束施法动作               
		send_user(who, "%c%w%w%c", 0x81, 9002, get_effect_3(who, EFFECT_CHAR_FAINT), EFFECT_BAD);
		send_user(char - ({ who }), "%c%d%w%c%c", 0x83, getoid(who), 9002, 1, EFFECT_BAD);
		send_user(char, "%c%d%w%c%c%c", 0x6f, getoid(who), 9002, 10, OVER_BODY, PF_LOOP);
	}
	return 1;
}

// 函数：复位处理
void reset()
{

}

// --------------------------------------------------------------- 远程调用 ----

// 函数：死亡奖励
void win_bonus(object who) { __FILE__->win_bonus_callout(this_object(), who); }

// 函数：死亡奖励(在线更新)
void win_bonus_callout(object me, object who)
{
	object owner, * team;
	int level, level2, exp, exp2, pot, alllevel;
	int i, size, status, time, flag, kk;

	if (!objectp(who = me->get_enemy_4())) return;

	if (owner = who->get_owner()) who = owner;
	if (who->is_npc()) return;

	//owner
	CHAT_D->sys_channel(0, HIY"Nghe nói tướng quân "HIG"Nhạc Phi "HIY"đã bị bằng hữu "HIR"" + who->get_name() + " "HIY"đánh bại.");

	drop_items(me, who);

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
	exp = 1000;
	for (i = 0; i < size; i++) if (team[i])
	{
		level2 = level - team[i]->get_level();
		exp2 = exp * team[i]->get_level() / alllevel;
		exp2 = me->correct_exp_bonus(level, level2, exp2) * who->get_online_rate() / 100;

		if (exp2 < 5) exp2 = 5;
		team[i]->add_potential(10000);
		team[i]->add_exp(1000000);
		team[i]->add_cash(300000);
	}
}

void drop_items(object me, object who)
{
	int x, y, z, p, i, rate, rate1, e1, e2, e3, e4, e5, index, rateDoanThach, rateTinVat;
	string* nTmp, id, owner;
	object item, leader, item1, item2, item3, item4;
	int manhNgoc;

	z = get_z(me);
	x = get_x(me);
	y = get_y(me);
	id = who->get_leader();

	if (!id)
		owner = who->get_id();
	else {
		if (leader = find_player(id)) {
			owner = leader->get_id();
		}
		else
			owner = who->get_id();
	}
	rate1 = me->correct_drop_rate(me->get_level() - who->get_level()) * who->get_online_rate() / 100;
	rate = random(100);
	
	p = get_valid_xy(z, x, y, IS_ITEM_BLOCK);

	//Tiền
	for (i = 0; i < 10; i++)
	{
		if (p = get_valid_xy(z, x, y, IS_ITEM_BLOCK))
		{
			item = new ("/item/std/0001");
			item->set_value(50000);
			TEAM_D->drop_item(item, who);
			item->set_user_id(owner);
			item->add_to_scene(z, p / 1000, p % 1000);
			item->set("winner", who);
			item->set("time", time());
		}

		if (p = get_valid_xy(z, x, y, IS_ITEM_BLOCK))
		{
			item = new("/item/std/0001");
			item->set_value(50000);
			TEAM_D->drop_item(item, who);
			item->set_user_id(owner);
			item->add_to_scene(z, p / 1000, p % 1000);
			item->set("winner", who);
			item->set("time", time());
		}

		if (p = get_valid_xy(z, x, y, IS_ITEM_BLOCK))
		{
			item = new("/item/91/9167");
			TEAM_D->drop_item(item, who);
			item->set_user_id(owner);
			item->add_to_scene(z, p / 1000, p % 1000);
			item->set("winner", who);
			item->set("time", time());
		}


			if (p = get_valid_xy(z, x, y, IS_ITEM_BLOCK))
			{
				item = new("/npc/event/PhoBan/item/tuiknb");
				TEAM_D->drop_item(item, who);
				item->set_user_id(owner);
				item->add_to_scene(z, p / 1000, p % 1000);
				item->set("winner", who);
				item->set("time", time());
			}

	}

	manhNgoc = random(5);
	manhNgoc += 5;

	for (i = 0; i < manhNgoc; i++)
	{
		item = new ("/npc/event/PhoBan/item/manhngoc");

		if (p = get_valid_xy(z, x, y, IS_ITEM_BLOCK))
		{
			TEAM_D->drop_item(item, who);
			item->set_user_id(owner);
			item->add_to_scene(z, p / 1000, p % 1000);
			item->set("winner", who);
			item->set("time", time());
		}
	}

	rateDoanThach = random(100);

	if (rateDoanThach < 50) {
		if (p = get_valid_xy(z, x, y, IS_ITEM_BLOCK))	//随机宠物技能书
		{
			for (i = 0; i < 2; i++) {
				item = new("/item/sell/0032");
				if (!item)
					return;

				if (p = get_valid_xy(z, x, y, IS_ITEM_BLOCK))
				{
					TEAM_D->drop_item(item, who);
					item->set_user_id(owner);
					item->add_to_scene(z, p / 1000, p % 1000);
					item->set("winner", who);
					item->set("time", time());
				}

			}
		}
	}
	else {
		item = new("/item/sell/2032");
		if (!item)
			return;
		if (p = get_valid_xy(z, x, y, IS_ITEM_BLOCK))
		{
			TEAM_D->drop_item(item, who);
			item->set_user_id(owner);
			item->add_to_scene(z, p / 1000, p % 1000);
			item->set("winner", who);
			item->set("time", time());
		}
	}

	
	for (i = 0; i < 5; i++)	//随机1级晶石5个
	{
		if (p = get_valid_xy(z, x, y, IS_ITEM_BLOCK))
		{
			item = new(STONE_FILE->get_diamond_file());
			item->set_level(1);

			if (p = get_valid_xy(z, x, y, IS_ITEM_BLOCK))
			{
				TEAM_D->drop_item(item, who);
				item->set_user_id(owner);
				item->add_to_scene(z, p / 1000, p % 1000);
				item->set("winner", who);
				item->set("time", time());
			}
		}
	}

	

	for (i = 0; i < 3; i++)
	{
		if (p = get_valid_xy(z, x, y, IS_ITEM_BLOCK))
		{
			item = new(STONE_FILE->get_diamond_file());
			item->set_level(4);
			if (p = get_valid_xy(z, x, y, IS_ITEM_BLOCK))
			{
				TEAM_D->drop_item(item, who);
				item->set_user_id(owner);
				item->add_to_scene(z, p / 1000, p % 1000);
				item->set("winner", who);
				item->set("time", time());
			}
		}
	}

	item = new("/npc/event/PhoBan/item/0");

	if (p = get_valid_xy(z, x, y, IS_ITEM_BLOCK))
	{
		TEAM_D->drop_item(item, who);
		item->set_user_id(owner);
		item->add_to_scene(z, p / 1000, p % 1000);
		item->set("winner", who);
		item->set("time", time());
	}

	item = new("/npc/event/PhoBan/item/1");
	if (p = get_valid_xy(z, x, y, IS_ITEM_BLOCK))
	{
		TEAM_D->drop_item(item, who);
		item->set_user_id(owner);
		item->add_to_scene(z, p / 1000, p % 1000);
		item->set("winner", who);
		item->set("time", time());
	}

	item = new("/npc/event/PhoBan/item/3");
	if (p = get_valid_xy(z, x, y, IS_ITEM_BLOCK))
	{
		TEAM_D->drop_item(item, who);
		item->set_user_id(owner);
		item->add_to_scene(z, p / 1000, p % 1000);
		item->set("winner", who);
		item->set("time", time());
	}

	item = new("/npc/event/PhoBan/item/2");
	if (p = get_valid_xy(z, x, y, IS_ITEM_BLOCK))
	{
		TEAM_D->drop_item(item, who);
		item->set_user_id(owner);
		item->add_to_scene(z, p / 1000, p % 1000);
		item->set("winner", who);
		item->set("time", time());
	}

	if (!p)
		return;
	
}

//杀死一个敌人加10000气血
void stop_fight()
{
	object enemy;
	enemy = get_enemy();
	if (enemy && enemy->get_hp() == 0)
	{
		if (this_object()->get("killed") >= 10)
		{
			SAY_CMD->say(this_object(), "Yêu quá cơ #24");
		}
		else
		{
			SAY_CMD->say(this_object(), "Yếu sinh lý thế #1");
		}
		add_hp(10000);
		this_object()->add("killed", 1);
	}
	::stop_fight();
}

// 函数：法术处理
int cast_done_npc(object me)
{
	object who, * char;
	string arg;
	int z, x, y;
	int type, level, i, size, count;

	if (!stringp(arg = me->get_cast_arg())) return 1;
	if (sscanf(arg, "%d,%d,%d,%d 2618", level, z, x, y) == 4)
	{
		char = get_scene_object(z, x, y, USER_TYPE);
		send_user(char, "%c%w%w%w%c%c%c", 0x4f, x, y, 26171, 1, OVER_BODY, PF_ONCE);
		char = get_range_object(z, x, y, 3, USER_TYPE) + get_range_object(z, x, y, 3, CHAR_TYPE) - ({ me });
		for (i = 0, size = sizeof(char); i < size; i++)
			if (who = char[i])
			{
				if (!who->can_be_fighted(me) || !me->can_fight(who)) continue;
				count++;
				if (count <= 1)
					send_user(get_scene_object_2(who, USER_TYPE), "%c%d%w%c%c%c", 0x6f, getoid(who), 2618, 1, OVER_BODY, PF_ONCE);
				CHAR_FIGHT_D->throwing_done(me, who, HIT_THROWING, 30 + (level - 40) / 10 * 8);
				if (who && !who->is_die())
					CHAR_FIGHT_D->set_enmity(me, who, 80);

			}
	}
	return 2;    // 执行成功
}