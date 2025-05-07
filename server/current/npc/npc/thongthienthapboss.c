#include <npc.h>
#include <ansi.h>
#include <equip.h>
#include <effect.h>
#include <cmd.h>
#include <skill.h>
#include <task.h>
#include <action.h>
#include <music.h>

#define FILE_NPC "npc/boss/00084"
#define FILE_SENDER "npc/event/tower/xaphu_2_chiton"


inherit BADMAN;

int iAtt, iWalk, hptime;
int saytime, hptime, RelaxTime, pTime, pTime1, pTime2, pTime3, iRelax, SumTime;
int i3484, i2415, i2513, i2516, i2618, i3641, i3642;


string* nFamily = ({ "Đào Hoa Nguyên","Thục Sơn","Cấm Vệ Quân","Đường Môn","Mao Sơn","Côn Luân","Vân Mộng Cốc" });

int caster = 0;
int hair = 1006;
int color = 0;//Black hair color
int photo = 2;
int codeArmor = 570000;

void set_caster(int p) { caster = p; }
void set_hair(int p) { hair = p; }
void set_photo(int p) { photo = p; }
void set_armor_code(int p) { codeArmor = p; }


int is_caster() { return 1; }
int get_id_color() { return 0107215; }
int get_hair() { return hair; }
int get_hair_color() { return color; }
int get_photo() { return photo; }

int get_armor_code() { return codeArmor; }
int get_armor_color_1() { return H_YELLOW; } //color armor

int get_weapon_color() { return H_YELLOW; }
int get_weapon_color_2() { return H_RED; }

int get_back() { return 1; }
int get_back2() { return 1; }

int get_back_color() { return 0x00C0C0C0; }
int get_back2_color() { return 0x00C0C0C0; }

int cannot_enter_city() { return 1; }

int set_fight_status(int type, int level, int gender, int hair);
void summon_guard();


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


	send_user( get_scene_object_2(me, USER_TYPE), "%c%d%w%c%c%c", 0x6f, getoid(me), 9009, 1,UNDER_FOOT, PF_LOOP );
	
	CHAR_CHAR_D->send_loop_perform(me, user);
	CHAR_CHAR_D->send_loop_perform_2(me, user);
}


void create()
{
	object me = this_object();
	set_name("Thủ Vệ");
	set_char_picid(1267);

	set_level(50);
	set_max_hp(10000);
	set_max_mp(10000);
	set_ap(1000);
	set_cp(1000);
	set_dp(500);
	set_pp(500);
	set_sp(500);

	set_effect(me, EFFECT_CHAR_BUSY, 2);
	call_out("do_fight", 2);
	set_walk_speed(3);

	//set_fight_status(2, 10, 0, 1);

	setup();
	set_char_type(FIGHTER_TYPE_2);

}

string get_short()
{
	return get_name() + "||||" + PPM"Thập Đại Cao Thủ";
}

int set_fight_status(int type, int level, int gender, int hair)
{
	int genderCode, uniformCode;

	object me = this_object();
	me->set("type", type);

	genderCode = gender * 100;
	uniformCode = (type + 1) * 10000 + genderCode;

	switch (type)
	{
	case 1:
		set_fam_name("Đào Hoa Nguyên");
		set_skill(3483, level);
		set_skill(2512, level);
		set_skill(2416, level);

		set_absorb_hp(1);
		set_weapon_code(UNARMED);
		set_weapon_color(13);

		set_caster(0);

		break;
	case 2:
		set_fam_name("Thục Sơn");
		set_skill(2216, level);
		set_skill(2313, level);
		set_skill(2314, level);
		set_skill(2214, level);

		set_absorb_hp(3);
		set_weapon_code(BLADE);
		set_weapon_color(13);
		set_hit_rate(2);
		set_double_rate(5000);
		set_caster(0);
		
		break;
	case 3:
		set_fam_name("Cấm Vệ Quân");
		set_skill(4231, level);
		set_skill(4232, level);
		set_skill(4234, level);
		set_skill(4243, level);

		set_skill(0241, level);
		set_skill(0242, level);
		set_skill(0251, level);
		set_skill(0348, level);
		set_skill(0349, level);
		set_skill(0351, level);
		set_skill(0352, level);
		set_skill(0353, level);
		set_skill(0354, level);
		set_skill(0355, level);

		set_absorb_hp(1);
		set_weapon_code(STICK);
		set_weapon_color(13);

		set("anti_sleep", 1);
		set("no_sk04211", 1);
		set_caster(0);

		break;
	case 4:
		set_fam_name("Đường Môn");
		set_skill(0261, level);
		set_skill(0363, level);
		set_skill(0364, level);
		set_skill(0365, level);
		set_skill(0368, level);
		set_skill(0381, level);
		set_skill(0382, level);
		set_skill(0383, level);
		set_skill(0384, level);
		set_skill(0385, level);
		set_weapon_code(THROWING);
		set_weapon_color(13);

		set_caster(1);

		break;
	case 5:
		set_fam_name("Côn Luân");
		set_weapon_code(SWORD);
		set_weapon_color(13);

		set_skill(2118, level);
		set_skill(2114, level);
		set_skill(2115, level);
		set_skill(2616, level);
		set_skill(2615, level);
		set_caster(1);

		break;
	case 6:
		set_fam_name("Mao Sơn");
		set_skill(4143, level);
		set_skill(4144, level);
		set_skill(4145, level);
		set_skill(4148, level);

		set_weapon_code(SWORD);
		set_caster(1);

		break;
	case 7:
		set_fam_name("Vân Mộng Cốc");
		set_skill(2816, level);
		set_skill(2811, level);

		set_weapon_code(SWORD);
		set_skill(2811, level);
		set_caster(1);

		break;
	}

	set_hair(hair);
	//set_hair(1000 + type);
	set_photo(type);
	set_armor_code(uniformCode);

	set_attack_speed(2);
	set_max_seek(6);
	set("anti_sleep", 1);
	set("no_sk04211", 1);
	set_char_type(FIGHTER_TYPE_2);
}



void do_fight()
{
	object me = this_object();
	set_effect(me, EFFECT_CHAR_BUSY, 0);
	me->add_to_scene(get_z(me), get_x(me), get_y(me));
}


int DuongMon(object who)
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
		me->set_save("03641", 10);
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
		switch (random(3))
		{
		default:
			"skill/02/02613"->perform_action_npc(me, who);
			break;
		case 1:
			"skill/02/02614"->perform_action_npc(me, who);
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
		set_effect(who, EFFECT_CHAR_FAINT, 2);    // 小心准备 me
		CHAR_CHAR_D->init_loop_perform(who);
		if (get_heart_state(who) == MAGIC_STAT) send_user(char, "%c%d%d%c", 0x40, getoid(who), time2(), MAGIC_ACT_END);    // 结束施法动作               
		send_user(who, "%c%w%w%c", 0x81, 9002, get_effect_3(who, EFFECT_CHAR_FAINT), EFFECT_BAD);
		send_user(char - ({ who }), "%c%d%w%c%c", 0x83, getoid(who), 9002, 1, EFFECT_BAD);
		send_user(char, "%c%d%w%c%c%c", 0x6f, getoid(who), 9002, 10, OVER_BODY, PF_LOOP);
	}
	return 1;
}

int CVQ(object who) {
	int rate, x, y, z, i, size, ret, type, interval, cp;
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
		//PF_FILE_03632->cast_done_npc(me);
	}

	if (gone_time(i3484) > 30)
	{
		i3484 = time();
		char = get_scene_object_2(me, USER_TYPE);
		set_effect(me, EFFECT_03484, 300);
		send_user(me, "%c%w%w%c", 0x81, 3484, get_effect_3(me, EFFECT_03484), EFFECT_GOOD);
		send_user(char - ({ me }), "%c%d%w%c%c", 0x83, getoid(me), 3484, 1, EFFECT_GOOD);
		send_user(char, "%c%d%w%c%c%c", 0x6f, getoid(me), 32521, 1, OVER_BODY, PF_ONCE);
		me->set_save("3484_1", 300);
		me->set_save("3484_2", 500);
	}
	if (gone_time(i2513) > 15)
	{
		i2513 = time();
		send_user(me, "%c%d%w%c%c%c", 0x6f, getoid(me), 10101, 1, OVER_BODY, PF_STOP);
		send_user(get_scene_object_2(me, USER_TYPE), "%c%d%w%c%c%c", 0x6f, getoid(me), 35139, 1, OVER_BODY, PF_ONCE);
		send_user(get_scene_object_2(who, USER_TYPE), "%c%d%w%c%c%w%c%c%c", 0x6f, getoid(who), 25131, 1, OVER_BODY, 25132, 1, OVER_BODY, PF_ONCE);
		ret = CHAR_FIGHT_D->attack_done(me, who, 10 + (me->get_skill(0251) - 1) / 10 * 8);
		ret += CHAR_FIGHT_D->attack_done(me, who, 10 + (me->get_skill(0251) - 1) / 10 * 8);
		if (who && !who->is_die())
			CHAR_FIGHT_D->set_enmity(me, who, 100);

		if (!who) return 2;
		if (who->is_anti_effect()) return 2;
		if (get_effect(who, EFFECT_NO_WEAPON_0)) return 2;
		if (who->get_2("suit_effect.no_drop")) return 2;

		if (ret > 0)
		{
			send_user(who, "%c%w%w%c", 0x81, 9020, get_effect_3(who, EFFECT_CHAR_WOUND), EFFECT_BAD);
			set_effect(who, EFFECT_NO_WEAPON, 4);
			set_effect(who, EFFECT_NO_WEAPON_0, 6);
			send_user(who, "%c%w%w%c", 0x81, 2114, 4, EFFECT_BAD);
			if (who->is_user())
			{
				USER_ENERGY_D->count_all_prop(who);
				send_user(get_scene_object_2(who, USER_TYPE), "%c%d%w", 0x7c, getoid(who), UNARMED);
			}
			else
			{
				who->set("02114", 500);
				who->add_ap(-500);
			}
		}
	}
	if (gone_time(i2516) > 2)
	{
		i2516 = time();
		send_user(me, "%c%d%w%c%c%c", 0x6f, getoid(me), 10101, 1, OVER_BODY, PF_STOP);

		send_user(get_scene_object_2(who, USER_TYPE), "%c%d%w%c%c%w%c%c%c", 0x6f, getoid(who),
			25163, 1, OVER_BODY, 25164, 1, OVER_BODY, PF_ONCE);
		me->set("add_damage", 150);
		ret = CHAR_FIGHT_D->attack_done(me, who, HIT_NONE);
		ret += CHAR_FIGHT_D->attack_done(me, who, HIT_NONE);
		if (who && !who->is_die())
			CHAR_FIGHT_D->set_enmity(me, who, 80);
		me->set("add_damage", 0);
		if (!who) return 2;

		if (ret > 0)
		{
			if (get_effect_3(who, EFFECT_NO_CLOTH_0)) return 2;
			send_user(get_scene_object_2(who, USER_TYPE), "%c%d%w%c%c%c", 0x6f, getoid(who), 21142, 1, OVER_BODY, PF_ONCE);    // 技能成功
			set_effect(who, EFFECT_NO_CLOTH, 5);
			set_effect(who, EFFECT_NO_CLOTH_0, 7);
			CHAR_CHAR_D->init_loop_perform(who);
			send_user(who, "%c%w%w%c", 0x81, 2516, 5, EFFECT_BAD);
			send_user(get_scene_object_2(who, USER_TYPE) - ({ who }), "%c%d%w%c%c", 0x83, getoid(who), 2516, 1, EFFECT_BAD);
			if (who->is_user())
			{
				USER_ENERGY_D->count_all_prop(who);
			}
			else
			{
				who->set("02516", 500);
				who->add_dp(-500);
			}
		}
	}
	if (gone_time(pTime1) > 4)
	{
		pTime1 = time();
		char = get_scene_object_2(me, USER_TYPE) - ({ me });
		if (!sizeof(char))
			return;
		who = char[random(sizeof(char))];
		switch (random(3))
		{
		default:
			"skill/02/02410"->perform_action_npc(me, who);
			break;
		case 1:
			"skill/02/02512"->perform_action_npc(me, who);
			break;
		case 2:
			"skill/02/02413"->perform_action_npc(me, who);
			break;

		}
		return 1;
	}

	if (gone_time(pTime2) > 3)
	{
		pTime2 = time();
		me->add_hp(2000 * (100 + me->get_healing_rate()) / 100);
		send_user(get_scene_object_2(me, USER_TYPE), "%c%d%w%c%c%c", 0x6f, getoid(me), 9154, 1, OVER_BODY, PF_ONCE);
		return 1;
	}

	send_user(get_scene_object_2(me, USER_TYPE), "%c%d%d%c%c%c%d", 0x41, getoid(me), time2(), 1, 10, get_d(me), getoid(who));
	ret = CHAR_FIGHT_D->attack_done(me, who, HIT_NONE, 10 + (me->get_skill(0423) - 1) / 10 * 8);
	ret += CHAR_FIGHT_D->attack_done(me, who, HIT_NONE, 10 + (me->get_skill(0423) - 1) / 10 * 8);
	
	if (ret > 0 && random(100) < 30)
	{
		if (!who) return 1;
		if (get_effect(who, EFFECT_CHAR_FAINT)
			|| get_effect(who, EFFECT_CHAR_FAINT_0)) return 1;
		if (who->get_perform("02222#")) return 1;
		char = get_scene_object_2(who, USER_TYPE);
		set_effect(who, EFFECT_CHAR_FAINT, 1);
		CHAR_CHAR_D->init_loop_perform(who);
		if (get_heart_state(who) == MAGIC_STAT) send_user(char, "%c%d%d%c", 0x40, getoid(who), time2(), MAGIC_ACT_END);    // 结束施法动作               
		send_user(who, "%c%w%w%c", 0x81, 9002, get_effect_3(who, EFFECT_CHAR_FAINT), EFFECT_BAD);
		send_user(char - ({ who }), "%c%d%w%c%c", 0x83, getoid(who), 9002, 1, EFFECT_BAD);
		send_user(char, "%c%d%w%c%c%c", 0x6f, getoid(who), 9002, 10, OVER_BODY, PF_LOOP);
	}
	
	return 1;

}

int perform_action(object who)
{
	int rate, type, ret, i, size, *xy, x,y,z;
	object me = this_object(), * char, soldier;

	if (get_z(who) != get_z(me) || !inside_screen_2(me, who))
		return 0;
	rate = random(100);
	type = me->get("type");

	if (soldier = who->get("soldier")) {
		if (get_effect(me, EFFECT_CHAR_CHANGE) < 1)
		{
			PF_FILE_04251->cast_done_npc(me);
		}

		if (rate < 10) {
			return "skill/11/11015"->perform_action_npc(me, 0);
		}
		else {
			me->add_cp(2000);
			return PF_FILE_04231->perform_action_npc(me, soldier);
		}
	} else
		
	switch (type)
	{
	case 1:
		if (rate < 16)
			return "/skill/02/02114"->perform_action_npc(me, who);
		else if (rate < 32)
			return "/skill/02/02117"->perform_action_npc(me, who);
		else if (rate < 48)
			return "/skill/02/02119"->perform_action_npc(me, who);
		else if (rate < 65) 
			return "/skill/02/02110"->perform_action_npc(me, who);
		else if (rate < 70) 
			return "/skill/02/02116"->perform_action_npc(me, who);
		else if(rate < 75)
			return "/skill/02/02113"->perform_action_npc(me, who);

		//return "/skill/03/03637"->perform_action_npc(me, who); //doc
		break;
	case 2:
		if (rate < 20)
			return PF_FILE_02216->perform_action_npc(me, who);
		else if (rate < 35)
			return PF_FILE_02313->perform_action_npc(me, who);
		else if (rate < 45)
			return PF_FILE_02314->perform_action_npc(me, who);
		else if (rate < 55) 
			return "skill/02/02216"->perform_action_npc(me, who);
		else if (rate < 60)
			return "skill/02/02214"->perform_action_npc(me, who);

		break;
	case 3:
		CVQ(who);
		break;
	case 4:
		DuongMon(who);
		break;
	case 5:
		//Con luan

		if (get_effect(me, EFFECT_CHAR_NO_PF)) return 0;
		if (get_effect(me, EFFECT_CHAR_CHANGE) < 1)
		{
			PF_FILE_04251->cast_done_npc(me);
		}

		if (rate < 40) {
			return PF_FILE_04231->perform_action_npc(me, who);
		} else

		switch (random(8))
		{
		case 1:
		case 2:
		case 3:
			"skill/04/04235"->perform_action_npc(me, who);
			break;
		case 4:
			"skill/04/04233"->perform_action_npc(me, who);
			break;
		case 5:
			"skill/04/04234"->perform_action_npc(me, who);
			break;
		case 6:
		case 7:
		case 8:
			"skill/02/02415"->perform_action_npc(me, who);
			break;
		}

		break;
	case 6:
		//Mao son
		
		if (get_effect(me, EFFECT_CHAR_NO_PF)) return 0;
		
		if (rate < 12)
			return PF_FILE_04143->perform_action_npc(me, who);
		else if (rate < 24)
			return PF_FILE_04144->perform_action_npc(me, who);
		else if (rate < 34)
			return PF_FILE_04145->perform_action_npc(me, who);
		else if (rate < 44)
			return "skill/04/04148"->perform_action_npc(me, who);
		else if (rate < 50) 
			summon_guard();
		else if (rate < 60)
		{
			if (!me->get_effect(me, EFFECT_USER_HURT))
			{
				PF_FILE_03632->cast_done_npc(me);
			}

			return "skill/11/11015"->perform_action_npc(me, 0);
		}

		break;
	case 7:
		//VMC
		if (!me->get_effect(me, EFFECT_USER_HURT))
		{
			PF_FILE_03632->cast_done_npc(me);
		}

		if (rate < 15)
			return "skill/02/02816"->perform_action_npc(me, who);
		else if (rate < 30)
			return "skill/02/02811"->perform_action_npc(me, who);
		else if (rate < 35)
			return "skill/11/11015"->perform_action_npc(me, 0);

		break;
	}

	
	return 0;
}


void win_bonus(object who)
{
	object owner, * team, * team2, map;
	object me = this_object();
	string id, id2;
	int i, size, level;
	if (!me->can_be_fighted(who)) return;
	if (owner = who->get_owner()) who = owner;
	if (who->is_npc()) return;
	team = who->get_team();
	if (sizeof(team) < 1) team = ({ who });
	team = me->correct_bonus_team(team);
	if ((size = sizeof(team)) < 1) return;
	if (!objectp(map = get_map_object(get_z(me))) || !map->is_scene()) return;
	for (i = 0; i < size; i++)
	{
		team[i]->add_exp(1000 + random(9999));
	}

	map->set("busy", 0);

	//__FILE__->drop_items(me, who);

	"sys/party/thapchiton"->drop_items(this_object(), who);
	"sys/party/thapchiton"->win_bonus_callout(this_object(), who);

	return;
}


void heart_beat_walk()
{
	string robber;
	object* member, who, owner;
	object me = this_object(), enemy;
	int x, y, z, x0, y0, z0, x1, y1, p, i;
	if ((iWalk++) % 3)
	{
		::heart_beat_walk();
		return;
	}
	if (gone_time(hptime) >= 20 + random(21))
	{
		hptime = time();
		enemy = get_enemy();
		if (objectp(enemy))
		{
			z = get_z(enemy); z0 = get_z(me);

			if (z == z0 && distance_between(me, enemy) < 20)
			{
				x = get_x(enemy); y = get_y(enemy);
				x0 = get_x(me); y0 = get_y(me);
				for (i = 0; i < 10; i++)
				{
					if (p = get_valid_xy(z, abs(x + random(3) - 1), abs(y + random(3) - 1), IS_CHAR_BLOCK))
					{
						x1 = p / 1000;  y1 = p % 1000;  break;
					}
				}
				if (x1 && y1 && z && !MAP_D->is_inside_city(z, x1, y1))
				{
					send_user(get_scene_object_2(me, USER_TYPE), "%c%w%w%w%c%c%c", 0x4f, x0, y0, 9413, 1, OVER_BODY, PF_ONCE);    // 补发指令
					me->add_to_scene(z, x1, y1);
					me->to_front_xy(x, y);
				}
			}

		}
	}
	member = get_range_object_2(me, me->get_max_seek(), CHAR_TYPE) + get_range_object_2(me, me->get_max_seek(), USER_TYPE) - ({ me });
	if (sizeof(member) != 0)
	{
		robber = sprintf("%x#", getoid(me));
		foreach(who in member)
		{

			if (who->is_die())
				continue;
			if ((owner = who->get_owner()) && (owner->get_task("robber") != robber))
			{
				continue;
			}
			else if (!(owner = who->get_owner()) && who->get_task("robber") != robber)
				continue;
			me->set_main_enemy(who);
			::heart_beat_walk();
			return;
		}
	}
	owner = me->get_enemy();
	if (!objectp(owner))
		return;
	if (get_z(owner) != get_z(me) || distance_between(me, owner) > 20)
	{
		me->set_enemy(0);
		return;
	}

}


void heart_beat_attack()
{
	string robber;
	object who;
	object me = this_object();
	if ((iAtt++) % 3)
	{
		::heart_beat_attack();
		return;
	}
	who = me->get_enemy();
	if (!objectp(who))
		return;
	if (get_z(who) != get_z(me) || distance_between(me, who) > 20 || !who->can_fight(me))
	{
		me->set_enemy(0);
		return;
	}

	::heart_beat_attack();

}

void summon_guard()
{
	int i, size, x, y, z, count, p, level, mp;
	object npc, me = this_object();

	x = get_x(me); y = get_y(me); z = get_z(me);
	mp = me->get_mp();
	level = get_level() - 5;
	for (i = 0; i < 5; i++)
	{
		if (objectp(get(sprintf("guard%d", i))))
			continue;
		p = get_valid_xy(z, x + random(10) - 5, y + random(10) - 5, IS_CHAR_BLOCK);
		if (!p)
			continue;
		if (!(mp >= 10)) continue;
		npc = new(FILE_NPC);
		if (!npc)
			break;
		me->add_mp(-10);
		set(sprintf("guard%d", i), npc);
		add("guard", ({ npc }));
		NPC_ENERGY_D->init_level(npc, level);
		npc->set_fight_status(level);
		npc->add_to_scene(z, p / 1000, p % 1000);
		npc->set_owner(me);
		NPC_SLAVE_D->find_enemy(npc);
		send_user(get_scene_object_2(npc, USER_TYPE), "%c%d%w%c%c%w%c%c%w%c%c%c", 0x6f, getoid(npc),
			41311, 1, OVER_BODY, 41312, 1, OVER_BODY, 41313, 1, UNDER_FOOT, PF_ONCE);
	}

}