#include <ansi.h>
#include <skill.h>
#include <equip.h>
#include <effect.h>
#include <time.h>
#include <public.h>

#define PF_NAME        "Hỗ trợ thi đấu"
#define MAP_ID        893
#define CLEAR_BUFF		"cmd/gm3/cleanbuff"

void do_fight(object me, int sec);
void menu(object me, int key);
void start(object me, object player_1, object player_2);
void action(object me, string arg);
int main(object me, string arg);
void recovery(object me, string player);

object *Mems = ({});

void menu(object me, int key) {
	switch (key)
	{
	case 1:
		send_user(me, "%c%c%d%s", '?', 16, 12, "Nhập ID vs ID：\n" ESC"pvpsp summon %s\n");
		break;
	}

}

void recovery(object me, string player) {
	object who;

	if (!who = find_any_char(player)) {
		tell_user(me, "Không tìm thấy %s", player);
		return;
	} 
	else {
		CLEAR_BUFF->main(me, player);
		who->set_hp(who->get_max_hp());
		who->set_mp(who->get_max_mp());
		who->set_yuan(who->get_max_yuan());
	}
	
}

void start(object me, object player_1, object player_2) {
	int x, y, p;

	x = 26; y = 31;
	if (!p = get_valid_xy(MAP_ID, x, y, IS_CHAR_BLOCK)) return;
	send_user(player_1, "%c%c%w%s", 0x5a, 0, 1, "Chuẩn bị thi đấu…");
	player_1->set_2("travel.z", MAP_ID);
	player_1->set_2("travel.p", p);
	set_effect(player_1, EFFECT_TRAVEL, 1);

	recovery(me, sprintf("%d", player_1->get_number()));

	x = 52; y = 28;
	if (!p = get_valid_xy(MAP_ID, x, y, IS_CHAR_BLOCK)) return;
	send_user(player_2, "%c%c%w%s", 0x5a, 0, 1, "Chuẩn bị thi đấu…");
	player_2->set_2("travel.z", MAP_ID);
	player_2->set_2("travel.p", p);
	set_effect(player_2, EFFECT_TRAVEL, 1);

	recovery(me, sprintf("%d", player_2->get_number()));

	call_out("do_fight", 2, me, 4);
}

void do_fight(object me, int sec) {
	object map, * mems;

	sec--;

	if (sec > 0) {
		for (int i = 0; i < sizeof(Mems); i++)
		{
			if (get_z(Mems[i]) != MAP_ID)
				continue;
			tell_user(Mems[i], HIC"Trận đấu bắt đầu sau %d giây.", sec);
		}

		tell_user(me, HIC"Trận đấu bắt đầu sau %d giây.", sec);
		call_out("do_fight", 1, me, sec);
	}
	else {
		for (int i = 0; i < sizeof(Mems); i++)
		{
			if (get_z(Mems[i]) != MAP_ID)
				continue;
			tell_user(Mems[i], HIG"BẮT ĐẦU CHIẾN ĐẤU!");
			tell_user(me, HIC"Trận đấu bắt đầu sau %d giây.", sec);

		}
	}
}

void action(object me, string arg) {
	string id_1, id_2;
	object player_1, player_2, map, *mems;
	int x, y, p, flag;

	if (sscanf(arg, "summon %s %s", id_1, id_2) == 2) {
		if (!player_1 = find_any_char(id_1)) {
			tell_user(me, "Không tìm thấy %s", id_1);
			return;
		}

		if (!player_2 = find_any_char(id_2)) {
			tell_user(me, "Không tìm thấy %s", id_2);
			return;
		}

		Mems = ({});

		x = 40; y = 30;
		if (!p = get_valid_xy(MAP_ID, x, y, IS_CHAR_BLOCK)) return;
		send_user(player_1, "%c%c%w%s", 0x5a, 0, 1, "Vào sân thi đấu…");
		player_1->set_2("travel.z", MAP_ID);
		player_1->set_2("travel.p", p);
		set_effect(player_1, EFFECT_TRAVEL, 2);

		recovery(me, id_1);

		x = 42; y = 30;
		if (!p = get_valid_xy(MAP_ID, x, y, IS_CHAR_BLOCK)) return;
		send_user(player_2, "%c%c%w%s", 0x5a, 0, 1, "Vào sân thi đấu…");
		player_2->set_2("travel.z", MAP_ID);
		player_2->set_2("travel.p", p);
		set_effect(player_2, EFFECT_TRAVEL, 2);

		recovery(me, id_2);

		Mems += ({ player_1 });
		Mems += ({ player_2 });

		me->set_2("pvp_1", id_1);
		me->set_2("pvp_2", id_2);

	} 
	else if (arg == "@") {
		id_1 = me->get_2("pvp_1");
		id_2 = me->get_2("pvp_2");

		if (!player_1 = find_any_char(id_1)) {
			tell_user(me, "Không tìm thấy %s", id_1);
			return;
		}

		if (!player_2 = find_any_char(id_2)) {
			tell_user(me, "Không tìm thấy %s", id_2);
			return;
		}

		call_out("start", 1, me, player_1, player_2);
	} 
	else if (arg == "-") {
		for (int i = 0; i < sizeof(Mems); i++)
		{
			if (get_z(Mems[i]) == MAP_ID && is_player(Mems[i])) {
				Mems[i]->set_login_flag(2);
				set_invisible(Mems[i], 1);
				set_effect(Mems[i], EFFECT_USER_LOGIN, 4);
				Mems[i]->add_to_scene(080, 290, 190);
			}
		}

		Mems = ({});
	}
}

int main(object me, string arg)
{
	int key;
	string str;

	if (is_player(me))
	{
		return 1;
	}

	if (sscanf(arg, "? %d", key) == 1) {
		menu(me, key);
	}
	else if (arg != "") {
		action(me, arg);
	}

	return 1;
}