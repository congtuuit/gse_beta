#include <npc.h>
#include <ansi.h>
#include <equip.h>
#include <public.h>
#include <time.h>
#include <effect.h>

int is_nianshou() { return 1; }
inherit BADMAN;
int get_char_picid() { return 4144; }
int is_yutu() { return 1; }

void create()
{
	set_name("Cương Thi");
	set_char_type(FIGHTER_TYPE);
	set_level(60);
	set_max_hp(10000);
	set_dp(200000);
	set_pp(200000);
	set_walk_speed(4);
	set_max_seek(10);
	set_attack_speed(25);

	set("anti_05311", 1);

	setup();
	set_char_type(FIGHTER_TYPE);
	set("birthday", time());


}

void reset()
{
	string member;
	object owner, who, oldcity;
	int number, oldz;
	if (gone_time(get("birthday")) >= 3600)    // 30 分钟
	{
		remove_from_scene();
		destruct(this_object());
	}
}

int get_weapon_code() { return UNARMED; }
int perform_action(object who) { return 0; }

string get_short() {
	return get_name();
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
