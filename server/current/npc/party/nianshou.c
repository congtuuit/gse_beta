#include <npc.h>
#include <ansi.h>
#include <equip.h>
#include <public.h>
#include <time.h>
#include <effect.h>

inherit NPC;
int is_boss() { return 1; }
int is_nianshou() { return 1; }
int cannot_enter_city() { return 1; }
int get_char_picid() { return 8100; }

void create()
{
	set_name("Niên Thú");

	set_char_type(FIGHTER_TYPE_2);

	set_level(150);
	set_max_hp(2000 + random(1000));
	set_walk_speed(4);
	set_attack_speed(25);

	set("no_sk04211", 1);
	set("anti_sleep", 1);
	set("anti_no_move", 1);

	setup();

	set_char_type(FIGHTER_TYPE_2);

}

void auto_fight(object who) { }

void heart_beat_walk()
{
	object me = this_object();
	
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
	if (!get_effect(me, EFFECT_CHAR_DREAM_0))		//不梦游
	{
		set_effect(me, EFFECT_CHAR_DREAM_0, 3600);
	}
	if (!get_effect(me, EFFECT_CHAR_LAZY_0))		//不延缓
	{
		set_effect(me, EFFECT_CHAR_LAZY_0, 3600);
	}
	if (!get_effect(me, EFFECT_USER_BURN_0))		//不燃烧
	{
		set_effect(me, EFFECT_USER_BURN_0, 3600);
	}
	if (!get_effect(me, EFFECT_CHAR_BLOOD_0))		//不流血
	{
		set_effect(me, EFFECT_CHAR_BLOOD_0, 3600);
	}
	::heart_beat_walk();
}

void win_bonus(object who) { "sys/party/tet"->win_bonus_callout(this_object(), who); }


