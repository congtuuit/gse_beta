#include <npc.h>
#include <ansi.h>
#include <equip.h>
#include <effect.h>
#include <cmd.h>
#include <skill.h>
#include <task.h>
#include <action.h>


inherit BADMAN;

int no_die;
int iStart, iFinish;

int is_boss() { return 1; }
int is_nianshou() { return 0; }
int cannot_enter_city() { return 1; }
int get_id_color() { return 0xdd0571; }
int is_caster() { return 0; }
void init_npc(object npc);
void drop_items(object me, object who);


void create()
{
	set_name("Ngưu Tinh");
	set_char_type(FIGHTER_TYPE);
	//set_head_color(0x0);
	set_head_color(0x0000D7FF);
	set_char_picid(0303);

	NPC_ENERGY_D->init_level(this_object(), 150);
	set_walk_speed(4);
	set_attack_speed(4);
	set_max_seek(10);

	set("anti_05311", 1);
	set("no_sk04211", 1);
	set("no_sk04237", 1);
	set("anti_sleep", 1);
	set("anti_no_move", 1);

	set_skill(11001, 120);
	set_skill(11002, 120);

	set_skill(4231, 120);
	set_skill(4232, 120);
	set_skill(4234, 120);
	set_skill(4243, 120);

	set_skill(0104, 120);
	set_skill(0111, 120);
	set_skill(0121, 120);
	set_skill(0131, 120);
	set_skill(0141, 120);
	set_skill(0151, 120);
	set_skill(0161, 120);
	set_skill(0202, 120);
	set_skill(0402, 120);
	set_skill(0403, 120);
	set_skill(0404, 120);
	set_skill(0405, 120);

	set_skill(0430, 8);
	set_skill(0431, 8);
	set_skill(0432, 10);
	set_skill(0433, 8);
	set_skill(0434, 8);
	set_skill(0435, 8);
	set_skill(0436, 8);
	set_skill(0437, 8);
	set_skill(0438, 8);

	set_ap(3000);
	set_max_hp(5550000);

	add_ap(get_ap() * 50 / 100);
	add_cp(get_cp() * 350 / 100);
	add_dp(get_dp() * 350 / 100);
	add_pp(get_pp() * 350 / 100);

	setup();
	set_char_type(FIGHTER_TYPE);

}

int get_weapon_code() { return UNARMED; }

int perform_action(object who) { 
	int rate, x, y, z, p, i, j, x1, y1, x0, y0, z0;
	object me = this_object();


	rate = random(100);

	/*if (rate < 10)
		return "skill/02/02415"->perform_action_npc(me, who);
	else if (rate < 30) {
		return "skill/02/02415"->perform_action_npc(me, who);
	}
	*/

	if (!me->get_effect(me, EFFECT_USER_HURT))
	{
		PF_FILE_03632->cast_done_npc(me);
	}

	if (rate < 15)
		return PF_FILE_04143->perform_action_npc(me, who);
	else if (rate < 30) {
		return "skill/02/02415"->perform_action_npc(me, who);

	}
	else {
		return PF_FILE_01611->perform_action_npc(this_object(), who);
	}

}


string get_short() {
	return get_name();
}

int can_fight(object who)
{
	object owner;
	string leader, id;
	if (get_char_type() == OFFICER_TYPE)
		return 0;
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
	if (get_char_type() == OFFICER_TYPE)
		return 0;
	if (who->is_npc() && objectp(owner = who->get_owner())) who = owner;
	if (who->is_npc())
	{
		set_enemy(0);
		return 0;
	}

	return ::can_be_fighted(who);
}

void win_bonus(object who)
{
	object me = this_object();

	CHAT_D->sys_channel(0, HIY"Nghe nói "HIG"Ngưu Tinh "HIY"đã bị bằng hữu "HIR"" + who->get_name() + " "HIY"đánh đuổi thành công.");


	__FILE__->drop_items(me, who);

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
			item->set_value(10000);
			TEAM_D->drop_item(item, who);
			item->set_user_id(owner);
			item->add_to_scene(z, p / 1000, p % 1000);
			item->set("winner", who);
			item->set("time", time());
		}

		if (p = get_valid_xy(z, x, y, IS_ITEM_BLOCK))
		{
			item = new("/item/std/0001");
			item->set_value(100000);
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

	}

	rateDoanThach = random(100);

	if (rateDoanThach < 70) {
		if (p = get_valid_xy(z, x, y, IS_ITEM_BLOCK))	//随机宠物技能书
		{
			for (i = 0; i < 3; i++) {
				item = new("/item/sell/1032");
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



	for (i = 0; i < 3; i++)
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

	for (i = 0; i < 4; i++)
	{
		if (p = get_valid_xy(z, x, y, IS_ITEM_BLOCK))
		{
			item = new(STONE_FILE->get_diamond_file());
			item->set_level(3);
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
