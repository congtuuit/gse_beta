

#include <equip.h>
#include <skill.h>
#include <effect.h>

mapping mpScene = ([

	001:0,
		002 : 0,
		003 : 0,
		004 : 0,
		005 : 0,
		006 : 0,
		007 : 0,
		008 : 0,
		009 : 0,
		161 : 5,
		162 : 5,
		061 : 10,
		062 : 10,
		063 : 10,
		281 : 10,
		282 : 10,
		283 : 10,
		284 : 10,
		081 : 15,
		082 : 15,
		251 : 15,
		021 : 20,
		041 : 20,
		042 : 20,
		043 : 20,
		141 : 20,
		142 : 20,
		211 : 20,
		089 : 25,
		131 : 25,
		132 : 25,
		155 : 25,
		181 : 25,
		182 : 25,
		231 : 25,
		241 : 25,
		242 : 25,
		243 : 25,
		271 : 25,
		272 : 25,
		164 : 30,
		261 : 30,
		262 : 30,
		263 : 30,
		264 : 30,
		111 : 35,
		112 : 35,
		265 : 35,
		266 : 35,
		011 : 40,
		012 : 40,
		013 : 40,
		014 : 40,
		015 : 40,
		151 : 45,
		152 : 45,
		153 : 45,
		501 : 45,
		502 : 45,
		503 : 45,
		171 : 50,
		172 : 50,
		173 : 50,
		174 : 50,
		528 : 50,
		529 : 50,
		530 : 50,
		071 : 55,
		072 : 55,
		073 : 55,
		512 : 55,
		513 : 55,
		031 : 60,
		032 : 60,
		033 : 60,
		510 : 60,
		511 : 60,
		051 : 65,
		052 : 65,
		053 : 65,
		524 : 65,
		525 : 65,
		526 : 65,
		527 : 65,
		321 : 70,
		322 : 70,
		323 : 70,
		516 : 70,
		517 : 70,
		311 : 75,
		312 : 75,
		313 : 75,
		514 : 75,
		515 : 75,
		311 : 75,
		312 : 75,
		313 : 75,
		331 : 80,
		332 : 80,
		333 : 80,
		334 : 80,
		335 : 80,
		504 : 80,
		505 : 80,
		341 : 85,
		342 : 85,
		343 : 85,
		344 : 85,
		345 : 85,
		508 : 85,
		509 : 85,
		291 : 90,
		292 : 90,
		293 : 90,
		506 : 90,
		507 : 90,
		381 : 95,
		383 : 95,
		385 : 95,
		520 : 95,
		522 : 95,
		372 : 100,
		373 : 100,
		374 : 100,
		521 : 100,
		523 : 100,
		091 : 105,
		092 : 105,
		093 : 105,
		531 : 105,
		532 : 105,
		391 : 110,
		392 : 110,
		393 : 110,
		518 : 110,
		519 : 110,

]);

// 函数：生成二进制码
void SAVE_BINARY() { }

// 函数：特技攻击对手
int perform_action(object me, object who)
{
	string file;

	if (stringp(file = me->get_perform_file())
		&& load_object(file)
		&& file->perform_action(me, who) == 2)    // 有特技出招
		return 1;

	// 自动法术
	if (me->get_attack_move())
	{
		switch (me->get_fam_name())
		{
		case "Vân Mộng Cốc":
		case "Mao Sơn":
		case "Thục Sơn":
			if ("/skill/02/02810"->perform_action(me, who) == 2)
				return 1;
			break;
		case "Côn Luân":
			if (me->get_weapon_code() == SWORD)
			{
				if ("/skill/02/02810"->perform_action(me, who) == 2)
					return 1;
			}
			else if (me->get_weapon_code() == BLADE)
			{
				if ("/skill/02/02999"->perform_action(me, who) == 2)
					return 1;
			}
			break;
		case "Đường Môn":
		default:
			if ("/skill/02/02611"->perform_action(me, who) == 2)
			{
				return 1;
			}
			break;
		}
	}
	me->set_perform_file(0);    // 重要：清除非法特技
	switch (me->get_weapon_code())
	{
	case BLADE: if (me->get_perform(PF_FLAG_02214))
	{
		if (PF_FILE_02214->perform_action(me, who) == 2) return 1;
	}
			  break;
	case STICK:
		if (me->get_perform(PF_FLAG_02514))
		{
			if (PF_FILE_02514->perform_action(me, who) == 2) return 1;
		}
		break;
	}

	return 0;
}

// 函数：判断可以战斗
int can_fight(object me, object who)
{
	object owner, map;
	string name1, name2;
	int z, z1;
	int levelMap, mapId;

	if (me->is_die() || me->is_store_open()) return 0;
	if (is_gm(me)) return 0;
	//    if( me->get_no_fight() && !who->cannot_enter_city() ) return 0;    // 在安全区，且NPC 能进城(使玩家能打本不应进城的怪)
	if (me->get_no_fight()) return 0;
	if (me->get_save("khongthepk") >= 1) return 0;

	if (me == who) return 0;
	if (get_effect(me, EFFECT_MAGIC_4243)) return 0;
	z1 = get_z(me);
	map = get_map_object(z1);
	if (!map) return 0;
	if (get_z(me) == 704) return 0;

	if (map->is_pvp())	//pvp地图
	{
		if (objectp(owner = who->get_owner())) who = owner;
		if (who == me) return 0;
		if (who->is_user())
		{
			if ((z = who->get_team_id()) && z == me->get_team_id())	//队伍保护
				return 0;
			if ((z = who->get_group_id()) && z == me->get_group_id())	//队伍保护
				return 0;
		}
		return 1;
	}

	if (map->is_wushuang() || map->is_wushuang_palace())	//无双城
	{
		if (objectp(owner = who->get_owner())) who = owner;
		if (who->is_user())
		{
			if (USER_INVENTORY_D->get_free_count(me) < 1)
				return 0;
			if (sizeof(name1 = me->get_org_name()) &&
				sizeof(name2 = who->get_org_name()) &&
				name1 == name2)	//帮派保护
				return 0;
		}
		return 1;
	}
	if (map->is_changping())	//长平之战
	{
		if (objectp(owner = who->get_owner())) who = owner;
		if (who->is_user())
		{
			if ((z = who->get_2("changping.warid")) && z != me->get_2("changping.warid")) 	//战场ID
				return 0;
			if (who->get_2("changping.country") == me->get_2("changping.country"))	//国家
				return 0;
		}
		return 1;
	}
	if (MAP_D->is_inside_battle(z1))
	{
		if (me->get_manager() == who->get_manager()) return 0;
		return 1;
	}
	else
	{
		z = get_z(who);
		if (objectp(owner = who->get_owner())) who = owner;
		if (who == me) return 0;
		if (map->get_no_fight() && who->is_user()) return 0;
		if (map->is_virtual_scene() && (me->get("no_fight") || who->get("no_fight"))) return 0;
		if (map->is_virtual_scene() && map->get_forbbit()) return 0;
		if (map->is_virtual_scene() == 2) return 1;
		if (who->is_user()
			&& ((name1 = me->get_leader()) && (name2 = who->get_leader())
				&& name1 != "" && name1 != 0 && name1 == name2)) return 0;
		if (is_gm3(me)) return 1;
		if (map->get_client_id() == 885) return 1;
		if (map->get_client_id() == 893) return 1;
		
		mapId = map->get_id();
		if (undefinedp(levelMap = mpScene[mapId]))
		{
		}

		//check 39
		if (who->is_user() && (who->get_level() < 30 || me->get_level() < 30) &&
			((who->get_attack_mode() != 0 || who->get_attack_mode() != 2 || who->get_attack_mode() != 3)
				|| (me->get_attack_mode() != 0 || me->get_attack_mode() != 2 || me->get_attack_mode() != 3))) return 0;

		switch (me->get_attack_mode())
		{
		case 0:
			//check 39
			if (who->is_user() && (who->get_level() < 30)) return 0;
			break;
		default:
			if (who->is_user()) return 0;
			break;
		case 2: if (who->is_user()
			&& (who->get_level() < 30 || (me->get_org_name() == who->get_org_name())
				)) return 0;
			break;
		case 3: if (who->is_user()
			&& (who->get_level() < 30 || (me->get_city_name() == who->get_city_name())
				)) return 0;
			break;
		}

		if (who->is_npc() && me->get_level() < 40 && who->get_level() > 85) {
			return 0;
		}

		return 1;
	}
}

// 函数：可以接受战斗
int can_be_fighted(object me, object who)
{
	if (me->is_die() || me->is_store_open() || me->get_no_fight() || me->get_save("khongthepk") >= 1 || get_z(me) == 704) return 0;
	if (is_gm3(me)) return 1;
	if (is_gm(me)) return 0;
	return 1;
}

// 判断法术是否可用
int can_use_help(object me, object who)
{
	object owner, map;
	string name1, name2;
	int z;
	map = get_map_object(get_z(me));
	if (!map) return 1;		// 如果地图出错的话         
	if (me->is_die() || me->is_store_open()) return 1;
	if (is_gm(me)) return 1;
	if (!who) return 0;

	if (who->can_be_fighted(me) && me->can_fight(who)) return 0;
	z = get_z(who);
	if (objectp(owner = who->get_owner())) who = owner;
	if (who == me) return 1;
	if (MAP_D->is_inside_battle(get_z(me)))
	{
		if (me->get_manager() == who->get_manager()) return 1;    // 禁止攻击帮众    // get_org_name() 是字串运算
		return 0;
	}
	if (map->is_changping())
	{
		if (me->get_2("changping.country") && who->get_2("changping.country") &&
			me->get_2("changping.country") == who->get_2("changping.country"))
			return 1;
		return 0;
	}
	if (z == 885)
	{
		if (who->is_user()    // 队友保护：攻击ＮＰＣ及非队友玩家
			&& ((name1 = me->get_leader()) && (name2 = who->get_leader())
				&& name1 != "" && name1 == name2)) return 1;
		return 0;
	}
	if (who->get_attack_mode() == 0)
	{
		if (me->get_attack_mode() != 0) return 0;
	}
	return 1;
}