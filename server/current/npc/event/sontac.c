#include <npc.h>
#include <ansi.h>
#include <equip.h>
#include <public.h>
#include <time.h>

inherit BADMAN;

object robber;
int get_id_color() { return 0107215; }
int get_char_picid() { return 8013; }

void do_bonus();

void create()
{
	set_name(HIY"Sơn Tặc Khăn Vàng");
	set_2("talk", ([
		"bonus":(: do_bonus:),
	]));

	set_char_type(FIGHTER_TYPE_2);
	set("birthday", time());

	setup();
	set_char_type(FIGHTER_TYPE_2);
}

int can_fight(object who)
{
	if (!objectp(this_object()->get_enemy()))
		return 0;
	if (who->is_user() && this_object()->get_level() + 10 < who->get_level()) {
		return 0;
	}

	return 1;
}

int can_be_fighted(object who)
{
	object owner;
	string leader, id;
	if (who->is_npc() && objectp(owner = who->get_owner())) who = owner;
	if (who->is_npc())
	{
		return 0;
	}

	if (who->is_user() && this_object()->get_level() + 10 < who->get_level()) {
		send_user(who, "%c%c%w%s", ':', 3, get_char_picid(), "Ngươi không nhìn thấy ta! Ngươi không nhìn thấy ta! \nHa ha ha ! Ha ha ha !");
		return 0;
	}

	return 1;
}

void win_bonus(object who) { "sys/party/sontac"->win_bonus_callout(this_object(), who); }
