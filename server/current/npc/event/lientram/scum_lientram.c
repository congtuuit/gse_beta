#include <npc.h>
#include <ansi.h>
#include <equip.h>
#include <effect.h>
#include <cmd.h>
#include <skill.h>
#include <task.h>
#include <action.h>
#include <public.h>

inherit BADMAN;
int* nxy = ({ 080034,087040,094046,101051,109057,116063,074040,081046,089051,097056,105062,111067,069046,077052,085056,092061,100067,107071,064051,072056,081061,087065,096071,0102075,059055,067060,075066,082070,091076,097079,054059,063066,071071,077075,084080,089085,048066,055071,062076,068081,074086,080091, });

private int iAtt, iCast;

int set_attack(int i)
{
	return iAtt = i;
}
int set_caster(int i)
{
	return iCast = i;
}

int is_caster() { return iCast; }
int is_robber() { return 0; }
int is_boss() { return 0; }
void init_npc(object npc);
int get_char_picid() { return 1001; }
void reset();


void create()
{
	set_name("Tinh Vệ");

	set_char_type(FIGHTER_TYPE);
	set_head_color(0x0);
	set_max_seek(10);
	set_max_hp(2000);

	set("anti_05311", 1);

	set_walk_speed(2);
	set_attack_speed(2);
	setup();

	set_char_type(FIGHTER_TYPE);
	set("birthday", time());

	call_out("reset", 1);
}

void reset()
{
	string member;
	object owner, who, oldcity, map;
	int number, oldz;


	if (gone_time(get("birthday")) >= 10)
	{
		map = get_map_object(get_z(this_object()));
		if (map) {
			map->set("autoDie", map->get("autoDie") + 1);
		}

		remove_from_scene();
		destruct(this_object());
		return;
	}

	call_out("reset", 1);
}

int get_weapon_code() { return UNARMED; }
int perform_action(object who) { return 0; }

void drop_items(object who)
{
	__FILE__->drop_items_callout(this_object(), who);
}

void drop_items_callout(object me, object who)
{
	object item, leader, map, * member, npc1, * team, npc;
	string file, owner, id;
	int p, rate, i, size, gold, equip, rate1, tId, level, secs, tmpSec, scumNumber;
	int z, x, y, miss;

	tId = me->get("team_id");
	map = get_map_object(get_z(me));
	if (!map)
		return;

	map->add("copy_npc_die", 1);

	z = map->get_id();
	x = get_x(me);
	y = get_y(me);
	member = "inh/std/scum_map"->get_all_user(map);
	member -= ({ 0 });
	size = sizeof(member);

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

	who->set("lientramTime", 5);
	who->set("lientram", who->get("lientram") + 1);
	if (who->get("lientram") % 100 == 0) {

		if (who->get("lientram") > who->get("Maxlientram")) {
			who->set("Maxlientram", who->get("lientram"));
		}

		tell_user(who, sprintf(HIC"Bạn đang có %d liên trảm!", who->get("lientram")));
		notify(HIC"Bạn đang có %d liên trảm!", who->get("lientram"));
	}
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

void init_npc(object npc)
{
	int p, level;

	level = npc->get_level();
	p = random(100);
	if (p < 20)
	{
		npc->set_skill(348, level);
		npc->set_skill(251, level);
		npc->set_skill(241, level);
		npc->set_char_picid(8011);
		npc->set_walk_speed(3);
		npc->set_attack_speed(10);
		npc->add_dp(-1 * npc->get_dp() / 4);
		npc->add_max_hp(npc->get_max_hp() * 20);
		npc->add_sp(npc->get_sp() * 2);
		npc->add_ap(npc->get_ap() * 4 / 5);
		npc->add_mp(npc->get_mp() / 2);
		npc->set("scum.type", 1);
	}
	else if (p < 40)	//高物防低法防型
	{
		npc->set_skill(221, level);
		npc->set_skill(231, level);
		npc->set_char_picid(0252);
		npc->set_walk_speed(3);
		npc->set_attack_speed(10);
		npc->add_dp(npc->get_dp() * 3);
		npc->add_max_hp(npc->get_max_hp() * 10);
		npc->add_pp(-1 * npc->get_pp() * 3 / 10);
		npc->add_ap(npc->get_ap() * 4 / 5);
		npc->add_mp(npc->get_mp() / 2);
		npc->set("scum.type", 2);
	}
	else if (p < 60)	//高法防低物防型
	{
		npc->set_skill(423, level);
		npc->set_skill(424, level);
		npc->set_skill(425, level);
		npc->set_char_picid(8010);
		npc->set_walk_speed(3);
		npc->set_attack_speed(10);
		npc->add_dp(-1 * npc->get_dp() / 4);
		npc->add_max_hp(npc->get_max_hp() * 10);
		npc->add_sp(npc->get_sp());
		npc->add_pp(npc->get_pp() * 3 / 2);
		npc->add_cp(npc->get_cp());
		npc->add_mp(npc->get_mp() * 6);
		npc->set("scum.type", 3);
	}
	else if (p < 70)	//长血型：拳脚类
	{
		npc->set_skill(211, level);
		npc->set_skill(317, level);
		npc->set_char_picid(8000);
		npc->set_walk_speed(3);
		npc->set_attack_speed(10);
		npc->add_dp(-1 * npc->get_dp() / 5);
		npc->add_max_hp(npc->get_max_hp() * 40);
		npc->add_pp(-1 * npc->get_pp() / 5);
		npc->add_mp(npc->get_mp() / 2);
		npc->add_ap(npc->get_ap() * 9 / 10);
		npc->set("scum.type", 4);
	}
	else if (p < 90)	//长血高物防高法防型：远程暗器类
	{
		npc->set_skill(261, level);
		npc->set_char_picid(8012);
		npc->set_walk_speed(3);
		npc->set_attack_speed(10);
		npc->add_dp(npc->get_dp() * 9 / 20);
		npc->add_max_hp(npc->get_max_hp() * 12);
		npc->add_sp(npc->get_sp() * 3);
		npc->add_pp(npc->get_pp() * 9 / 5);
		npc->add_mp(npc->get_mp());
		npc->add_ap(npc->get_ap() / 2);
		npc->set("scum.type", 5);
	}
	else 	//强攻型加召唤
	{
		npc->set_skill(414, level);
		npc->set_char_picid(8013);
		npc->set_walk_speed(3);
		npc->set_attack_speed(8);
		npc->add_dp(npc->get_dp() * 9 / 20);
		npc->add_ap(npc->get_ap());
		npc->add_max_hp(npc->get_max_hp() * 12);
		npc->add_sp(npc->get_sp() * 3);
		npc->add_pp(npc->get_pp() * 9 / 20);
		npc->add_mp(npc->get_mp() * 3 / 2);
		npc->set("scum.type", 6);
	}
}
