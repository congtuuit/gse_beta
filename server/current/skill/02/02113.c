
// 物理技能  TIPS:[PF_HIT]

#include <ansi.h>
#include <skill.h>
#include <effect.h>
#include <equip.h>

#define THIS_SKILL      0211
#define THIS_PERFORM    02113
#define PF_START       "02113"
#define PF_NAME        "Phong Ma Quyết"

#define SKILL_LEVEL     23
#define TIME_INTERVAL   30 - (me->get_skill(THIS_SKILL) - SKILL_LEVEL)/10
#define SUB_MP          0
#define SUB_YUAN        4
#define ADD_AP          0
#define ADD_INTERVAL  	6

#define ADD_ENMITY	600 + (me->get_skill(THIS_SKILL) - SKILL_LEVEL)/10*130 + ret

int SKILL_LEVEL_SQUARE = SKILL_LEVEL * (SKILL_LEVEL - 1);

// 函数:获取法力
int get_sub_mp(object me)
{
	int level = me->get_skill(THIS_SKILL);
	return SUB_MP;
}

// 函数:获取描述
string get_desc(object me)
{
	int level = me->get_skill(THIS_SKILL);
	int cur_level;
	string result;
	if (level < SKILL_LEVEL)
		return HIR + PF_NAME + "\n Võ công yêu cầu: 23 cấp\n    Nội kình bạo phát làm mục tiêu tắc nghẽn kinh mạch, rơi vào trạng thái Trầm Mặc trong 6 giây.";
	cur_level = (level - SKILL_LEVEL) / 10 + 1;
	result = sprintf(HIC" %s (Cấp %d )\n " NOR "Võ công yêu cầu: Cấp %d \n Nguyên khí tiêu hao: %d điểm\n Tái sử dụng sau: %d giây\n    Nội kình bạo phát làm mục tiêu tắc nghẽn kinh mạch, rơi vào trạng thái Trầm Mặc trong 6 giây.\n " HIC"Cấp tiếp theo:\n "NOR"Võ công yêu cầu: " HIR "Cấp %d " NOR"\n    Thời gian tái sử dụng giảm còn %d giây.",
		PF_NAME, cur_level, SKILL_LEVEL, SUB_YUAN, TIME_INTERVAL, cur_level * 10 + SKILL_LEVEL, TIME_INTERVAL - 1);
	return result;
}

// 函数:命令处理
int main(object me, object who, int x, int y, string arg)
{
	int level, mp;

	if ((level = me->get_skill(THIS_SKILL)) < SKILL_LEVEL) return 1;

	if (gone_time(me->get_perform(PF_START)) < TIME_INTERVAL) return 1;    // 小心准备 level

	if (me->get_mp() < (mp = SUB_MP))    // 小心准备 level
	{
		printf(ECHO "Sử dụng \" %s \"cần %d điểm Pháp Lực.", PF_NAME, mp);
		return 1;
	}

	if (me->get_yuan() < SUB_YUAN)
	{
		printf(ECHO "Sử dụng \" %s \"cần %d điểm Nguyên khí.", PF_NAME, SUB_YUAN);
		return 1;
	}

	if (me->get_weapon_code() != UNARMED)
	{
		printf(ECHO "Sử dụng \"" PF_NAME "\" phải trang bị triển thủ");
		return 1;
	}
	if (me->get_gender() != 1 && !CHAR_FIGHT_D->attack_action(me, who, 3030)) return 1;
	else
		if (me->get_gender() == 1 && !CHAR_FIGHT_D->attack_action(me, who, 9030)) return 1;
	me->add_yuan(-SUB_YUAN);
	set_heart_state(me, MAGIC_STAT);
	set_heart_count_2(me, 5);
	me->add_2("go_count.count2", 5);
	me->set_cast_file(__FILE__);
	me->set_cast_arg(sprintf("%s", who->get_char_id()));
	send_user(me, "%c%w%c%w", 0x50, THIS_PERFORM, 0xff, 0);
	me->set_perform(PF_START, time());
	send_user(me, "%c%d%w%c%c%c", 0x6f, getoid(me), 10101, 1, OVER_BODY, PF_LOOP);
	return 1;
}

// 函数:特殊技处理(动作)
int perform_action(object me, object who)
{
	int level, mp;

	if ((level = me->get_skill(THIS_SKILL)) < SKILL_LEVEL) return 1;

	if (gone_time(me->get_perform(PF_START)) < TIME_INTERVAL) return 1;    // 小心准备 level

	if (me->get_mp() < (mp = SUB_MP))    // 小心准备 level
	{
		printf(ECHO "Sử dụng \" %s \"cần %d điểm Pháp Lực.", PF_NAME, mp);
		return 1;
	}

	if (me->get_yuan() < SUB_YUAN)
	{
		printf(ECHO "Sử dụng \" %s \"cần %d điểm Nguyên khí.", PF_NAME, SUB_YUAN);
		return 1;
	}

	if (me->get_weapon_code() != UNARMED)
	{
		printf(ECHO "Sử dụng \"" PF_NAME "\" phải trang bị triển thủ");
		return 1;
	}

	if (me->get_gender() != 1 && !CHAR_FIGHT_D->attack_action(me, who, 3030)) return 1;
	else
		if (me->get_gender() == 1 && !CHAR_FIGHT_D->attack_action(me, who, 9030)) return 1;

	me->add_mp(-mp);
	me->add_yuan(-SUB_YUAN);
	send_user(me, "%c%w%c%w", 0x50, THIS_PERFORM, 0xff, 0);
	me->set_perform(PF_START, time());
	return 2;    // 执行成功
}

// 函数:特殊技处理
int perform_done(object me, object who)
{
	int level, mp, rate, interval, ret;

	if ((level = me->get_skill(THIS_SKILL)) < SKILL_LEVEL) return 1;

	//      if( gone_time( me->get_perform(PF_START) ) < TIME_INTERVAL ) return 1;    // 小心准备 level

	/*      if( me->get_mp() < ( mp = SUB_MP ) )    // 小心准备 level
			{
					printf( ECHO "Sử dụng \" %s \"cần %d điểm Pháp Lực.", PF_NAME, mp );
					return 1;
			}       */

			/*      if( me->get_yuan() < SUB_YUAN )
					{
							printf( ECHO "Sử dụng \" %s \"cần %d điểm Nguyên khí.", PF_NAME, SUB_YUAN );
							return 1;
					}       */

	if (me->get_weapon_code() != UNARMED)
	{
		printf(ECHO "Sử dụng \"" PF_NAME "\" phải trang bị triển thủ");
		return 1;
	}

	me->set_perform_file(0);
	send_user(me, "%c%d%w%c%c%c", 0x6f, getoid(me), 10101, 1, OVER_BODY, PF_STOP);    // 删除聚气

	send_user(get_scene_object_2(who, USER_TYPE), "%c%d%w%c%c%w%c%c%c", 0x6f, getoid(who), 21131, 1, OVER_BODY, 21132, 1, OVER_BODY, PF_ONCE);

	ret = CHAR_FIGHT_D->attack_done(me, who, HIT_NONE, ADD_AP);

	if (who && !who->is_die())
		CHAR_FIGHT_D->set_enmity(me, who, ADD_ENMITY);

	if (!who) return 2;    // 执行成功
	if (who->is_anti_effect()) return 2;
	if (random(100) < who->get_anti_NoPF()) return 2;	//抗封魔率

	if (get_effect(who, EFFECT_CHAR_NO_PF)
		|| get_effect(who, EFFECT_CHAR_NO_PF_0)) return 2;    // 执行成功
	if (who->get_perform("02221#")) return 2;
	if (ret > 0)
	{
		interval = ADD_INTERVAL;
		set_effect(who, EFFECT_CHAR_NO_PF, interval);    // 小心准备 level
		CHAR_CHAR_D->init_loop_perform(who);
		send_user(who, "%c%w%w%c", 0x81, 9010, get_effect_3(who, EFFECT_CHAR_NO_PF), EFFECT_BAD);
		send_user(get_scene_object_2(who, USER_TYPE) - ({ who }), "%c%d%w%c%c", 0x83, getoid(who), 9010, 1, EFFECT_BAD);
		send_user(get_scene_object_2(who, USER_TYPE), "%c%d%w%c%c%c", 0x6f, getoid(who), 9010, 1, OVER_BODY, PF_LOOP);
	}

	return 2;    // 执行成功
}

// 函数:特殊技处理
int cast_done(object me)
{
	int level, mp, rate, interval, ret;
	object who;
	string arg;

	if (!stringp(arg = me->get_cast_arg())) return 1;
	if (!objectp(who = find_char(arg))) return 1;

	send_user(me, "%c%d%w%c%c%c", 0x6f, getoid(me), 10101, 1, OVER_BODY, PF_STOP);    // 删除聚气

	send_user(get_scene_object_2(who, USER_TYPE), "%c%d%w%c%c%w%c%c%c", 0x6f, getoid(who), 21131, 1, OVER_BODY, 21132, 1, OVER_BODY, PF_ONCE);

	ret = CHAR_FIGHT_D->attack_done(me, who, HIT_NONE, ADD_AP);

	if (who && !who->is_die())
		CHAR_FIGHT_D->set_enmity(me, who, ADD_ENMITY);

	if (!who) return 2;    // 执行成功
	if (who->is_anti_effect()) return 2;
	if (random(100) < who->get_anti_NoPF()) return 2;	//抗封魔率

	if (get_effect(who, EFFECT_CHAR_NO_PF)
		|| get_effect(who, EFFECT_CHAR_NO_PF_0)) return 2;    // 执行成功
	if (who->get_perform("02221#")) return 2;
	if (ret > 0)
	{
		interval = ADD_INTERVAL;
		set_effect(who, EFFECT_CHAR_NO_PF, interval);    // 小心准备 level
		CHAR_CHAR_D->init_loop_perform(who);
		send_user(who, "%c%w%w%c", 0x81, 9010, get_effect_3(who, EFFECT_CHAR_NO_PF), EFFECT_BAD);
		send_user(get_scene_object_2(who, USER_TYPE) - ({ who }), "%c%d%w%c%c", 0x83, getoid(who), 9010, 1, EFFECT_BAD);
		send_user(get_scene_object_2(who, USER_TYPE), "%c%d%w%c%c%c", 0x6f, getoid(who), 9010, 1, OVER_BODY, PF_LOOP);
	}

	return 2;    // 执行成功
}

// 函数:获取特技类型
int get_perform_type() { return ON_CHAR; }

// 函数:能否Sử dụng 特技
void can_perform(object me)
{
	int interval;
	string name;

	if (me->get_skill(THIS_SKILL) < SKILL_LEVEL)
	{
		send_user(me, "%c%w%c%w%w%s", 0x50, THIS_PERFORM, 0, 1, 0, PF_NAME);
		return;
	}
	name = sprintf(" %s (Cấp %d )", PF_NAME, (me->get_skill(THIS_SKILL) - SKILL_LEVEL) / 10 + 1);
	interval = TIME_INTERVAL - gone_time(me->get_perform(PF_START));
	if (interval < 0)
		send_user(me, "%c%w%c%w%w%s", 0x50, THIS_PERFORM, get_perform_type(), TIME_INTERVAL, 0, name);
	else    send_user(me, "%c%w%c%w%w%s", 0x50, THIS_PERFORM, get_perform_type(), TIME_INTERVAL, interval, name);
	if (me->get_gender() == 1)
		send_user(me, "%c%w%w%c%c%c%c%c%c", 0x64, THIS_PERFORM, SUB_MP, SUB_YUAN, 1, 9, 30, 5, 0);
	else
		send_user(me, "%c%w%w%c%c%c%c%c%c", 0x64, THIS_PERFORM, SUB_MP, SUB_YUAN, 1, 3, 30, 5, 0);

}



int perform_action_npc(object me, object who)
{
	int ret;

	if (!CHAR_FIGHT_D->attack_action(me, who, 3030)) return 0;

	send_user(me, "%c%d%w%c%c%c", 0x6f, getoid(me), 10101, 1, OVER_BODY, PF_STOP); 

	send_user(get_scene_object_2(who, USER_TYPE), "%c%d%w%c%c%w%c%c%c", 0x6f, getoid(who), 21131, 1, OVER_BODY, 21132, 1, OVER_BODY, PF_ONCE);

	ret = CHAR_FIGHT_D->attack_done(me, who, HIT_NONE, ADD_AP);

	if (who && !who->is_die())
		CHAR_FIGHT_D->set_enmity(me, who, ADD_ENMITY);

	if (!who) return 2;
	if (who->is_anti_effect()) return 2;
	if (random(100) < who->get_anti_NoPF()) return 2;	//

	if (get_effect(who, EFFECT_CHAR_NO_PF)
		|| get_effect(who, EFFECT_CHAR_NO_PF_0)) return 2; 
	if (who->get_perform("02221#")) return 2;
	if (ret > 0)
	{
		set_effect(who, EFFECT_CHAR_NO_PF, 3);
		CHAR_CHAR_D->init_loop_perform(who);
		send_user(who, "%c%w%w%c", 0x81, 9010, get_effect_3(who, EFFECT_CHAR_NO_PF), EFFECT_BAD);
		send_user(get_scene_object_2(who, USER_TYPE) - ({ who }), "%c%d%w%c%c", 0x83, getoid(who), 9010, 1, EFFECT_BAD);
		send_user(get_scene_object_2(who, USER_TYPE), "%c%d%w%c%c%c", 0x6f, getoid(who), 9010, 1, OVER_BODY, PF_LOOP);
	}


	return 1;
}
