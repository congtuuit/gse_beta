#include <npc.h>
#include <ansi.h>
#include <equip.h>
#include <effect.h>
#include <cmd.h>
#include <skill.h>
#include <task.h>
#include <action.h>

inherit BADMAN;

int is_caster() { return 0; }

int get_char_picid() { return 3011; }
void do_fight();

int leiTime;


string get_short()
{
	return get_name();
}

void create()
{
	set_name(HIY"Thiên Long");

	set_char_type(FIGHTER_TYPE);
	set_level(100);
	set_head_color(0x0000D7FF);
	set_max_hp(20000000);
	set_ap(15000);
	set_cp(3000);

	set_dp(2000);
	set_pp(2000);
	//set_max_seek(2);
	set_max_seek(6);
	set_walk_speed(4);

	set_skill(0437, 50);

	set("no_sk04237", 1);
	set("no_sk04211", 1);
	set("anti_sleep", 1);
	set("anti_no_move", 1);

	set_skill(11001, 150);
	set_skill(11002, 150);

	call_out("do_fight", 2);
	setup();

	CHAT_D->sys_channel(0, HIY"Nghe nói Rồng Thần xuất hiện tại "HIR"" + "Phong Thần Đài" + " "HIY", không biết thực hư thế nào?!");
	CHAT_D->sys_channel(0, HIY"Nghe nói Rồng Thần xuất hiện tại "HIR"" + "Phong Thần Đài" + " "HIY", không biết thực hư thế nào?!");
	CHAT_D->sys_channel(0, HIY"Nghe nói Rồng Thần xuất hiện tại "HIR"" + "Phong Thần Đài" + " "HIY", không biết thực hư thế nào?!");

	set_char_type(FIGHTER_TYPE);

	log_file("boss.txt", short_time() + " Long Thần xuất hiện\n");

}

void do_fight()
{
	object me = this_object();
	set_effect(me, EFFECT_CHAR_BUSY, 0);
	me->add_to_scene(get_z(me), get_x(me), get_y(me));
}

void set_lowhp_status()
{
	add_ap(get_ap() / 5);
	add_dp(get_dp() / 5);
	add_cp(get_cp() / 5);
	add_pp(get_pp() / 5);
	add_sp(get_sp() / 5);
}

int get_weapon_code() { return UNARMED; }

void heart_beat_walk()
{
	int i, x, y, z, x0, y0, z0, p, x1, y1;
	object enemy, me = this_object();

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

	if (objectp(enemy = get_enemy()) && gone_time(leiTime) > 30)
	{
		leiTime = time();

		SAY_CMD->say(me, "Thần Long Lôi Điện...");

		if (random(100) < 40) {

			return "skill/boss/11015"->perform_action_npc(me, 0);
		}
		else {
			return "skill/boss/11016"->perform_action_npc(me, 0);
		}

	}

	::heart_beat_walk();
}
void heart_beat_attack()
{
	if (get_char_type() == OFFICER_TYPE)	//普通状态
		return;
	::heart_beat_attack();
}

int perform_action(object who) { return 0; }
//int perform_action(object who) { return PF_FILE_04232->perform_action_npc(this_object(), who); }

void drop_items(object who) { __FILE__->drop_items_callout(this_object(), who); }

void drop_items_callout(object me, object who)
{
	object item, leader;
	string file, owner, id;
	int p, rate, i, size, gold, equip, total, total2;
	int z, x, y;
	int ngoc_dropped;

	ngoc_dropped = 0;
	rate = random(30) + 15;

	z = get_z(me);  x = get_x(me);  y = get_y(me);
	id = who->get_leader();
	if (!id) owner = who->get_id();
	else
	{
		if (leader = find_player(id))
		{
			owner = leader->get_id();
		}
		else
			owner = who->get_id();
	}

	CHAT_D->sys_channel(0, HIY"Nghe nói Rồng Thần đã bị bằng hữu "HIG"" + who->get_name() + " "HIY"tiêu diệt.");

	for (i = 0; i < 150; i++) {

		if (i == rate) {
			if (p = get_valid_xy(z, x, y, IS_ITEM_BLOCK))
			{
				item = new("/item/00/0001");

				/*if (owner && who) {
					TEAM_D->drop_item(item, who);
					item->set_user_id(owner);
					ITEM_EQUIP_D->init_equip_prop(item);
					item->add_to_scene(z, p / 1000, p % 1000);
					item->set("winner", who);
					item->set("time", time());
				}
				else {

					item->add_to_scene(z, p / 1000, p % 1000);
					item->set("time", time());

				}*/

				item->add_to_scene(z, p / 1000, p % 1000);
				item->set("time", time());

				if (who) {
					log_file("rongThan.txt", sprintf("%s %s(%d) %s\n", short_time(), who->get_id(), who->get_number(), item->get_name()));
				}
				else {
					log_file("rongThan.txt", sprintf("%s %s\n", short_time(), item->get_name()));
				}

			}
		}

		if (p = get_valid_xy(z, x, y, IS_ITEM_BLOCK))
		{
			item = new("/item/std/0001");
			item->set_value(10000);
			item->add_to_scene(z, p / 1000, p % 1000);
			item->set("time", time());
		}

		if (i % 5 == 0) {
			switch (random(3))
			{
			case 0: file = WEAPON_FILE->get_weapon_file_2(90);  break;
			case 1: file = WEAPON_FILE->get_weapon_file_2(100);  break;
			case 2: file = WEAPON_FILE->get_weapon_file_2(110);  break;

			default: break;
			}

			if (load_object(file) && (p = get_valid_xy(z, x, y, IS_ITEM_BLOCK)))
			{
				item = new(file);
				//TEAM_D->drop_item(item, who);
				//item->set_user_id(owner);
				ITEM_EQUIP_D->init_equip_prop(item);
				item->add_to_scene(z, p / 1000, p % 1000);
				//item->set("winner", who);
				item->set("time", time());
			}

		}

		if (i % 3 == 0) {
			switch (random(3))
			{
			case 0: file = ARMOR_FILE->get_armor_file_2(90);  break;
			case 1: file = ARMOR_FILE->get_armor_file_2(100);  break;
			case 2: file = ARMOR_FILE->get_armor_file_2(110);  break;

			default: break;
			}

			if (load_object(file) && (p = get_valid_xy(z, x, y, IS_ITEM_BLOCK)))
			{
				item = new(file);
				//TEAM_D->drop_item(item, who);
			   //item->set_user_id(owner);
				ITEM_EQUIP_D->init_equip_prop(item);
				item->add_to_scene(z, p / 1000, p % 1000);
				//item->set("winner", who);
				item->set("time", time());
			}

		}



	}

}
