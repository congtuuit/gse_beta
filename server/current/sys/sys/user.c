
#include <city.h>
#include <equip.h>
#include <item.h>
#include <ansi.h>
#include <action.h>

private
object *Users = ({});
private
object *Gms = ({});
private
object *Players = ({});
private
object *LevelA = ({});
private
object *LevelB = ({});
private
object *LevelC = ({});
private
object *Battle = ({});

void add_user(object who);

void SAVE_BINARY() {}

void create()
{
	object *user;
	int i, size;

	if (arrayp(user = users()))
		for (i = 0, size = sizeof(user); i < size; i++)
		{
			add_user(user[i]);
		}
}

object *get_gm()
{
	Gms -= ({0});
	return copy(Gms);
}

object *get_player()
{
	Players -= ({0});
	return copy(Players);
}

int sizeof_gm()
{
	Gms -= ({0});
	return sizeof(Gms);
}

int sizeof_player()
{
	Players -= ({0});
	return sizeof(Players);
}

void add_gm(object who)
{
	if (objectp(who))
		Gms = Gms - ({who, 0}) + ({who});
}

void add_player(object who)
{
	if (objectp(who))
		Players = Players - ({who, 0}) + ({who});
}

void sub_gm(object who)
{
	if (objectp(who))
		Gms -= ({who, 0});
}

void sub_player(object who)
{
	if (objectp(who))
		Players -= ({who, 0});
}

object *get_level_a_user()
{
	LevelA -= ({0});
	return copy(LevelA);
}

object *get_level_b_user()
{
	LevelB -= ({0});
	return copy(LevelB);
}

object *get_level_c_user()
{
	LevelC -= ({0});
	return copy(LevelC);
}

object *get_battle_user()
{
	Battle -= ({0});
	return copy(Battle);
}

int sizeof_level_a_user()
{
	LevelA -= ({0});
	return sizeof(LevelA);
}

int sizeof_level_b_user()
{
	LevelB -= ({0});
	return sizeof(LevelB);
}

int sizeof_level_c_user()
{
	LevelC -= ({0});
	return sizeof(LevelC);
}

int sizeof_battle_user()
{
	Battle -= ({0});
	return sizeof(Battle);
}

void add_level_a_user(object who)
{
	if (objectp(who))
		LevelA = LevelA - ({who, 0}) + ({who});
}

void add_level_b_user(object who)
{
	if (objectp(who))
		LevelB = LevelB - ({who, 0}) + ({who});
}

void add_level_c_user(object who)
{
	if (objectp(who))
		LevelC = LevelC - ({who, 0}) + ({who});
}

void add_battle_user(object who)
{
	if (objectp(who))
		Battle = Battle - ({who, 0}) + ({who});
}

void sub_level_a_user(object who)
{
	if (objectp(who))
		LevelA -= ({who, 0});
}

void sub_level_b_user(object who)
{
	if (objectp(who))
		LevelB -= ({who, 0});
}

void sub_level_c_user(object who)
{
	if (objectp(who))
		LevelC -= ({who, 0});
}

void sub_battle_user(object who)
{
	if (objectp(who))
		Battle -= ({who, 0});
}

object *get_user()
{
	Users -= ({0});
	return copy(Users);
}

int sizeof_user()
{
	Users -= ({0});
	return sizeof(Users);
}

void add_user(object who)
{
	if (objectp(who) && userp(who))
	{
		Users = Users - ({who, 0}) + ({who});
		if (!is_player(who))
			add_gm(who);
		else
			add_player(who);

		if (!MAP_D->is_inside_battle(get_z(who)))
			switch (who->get_level())
			{
			case 0..9:
				add_level_a_user(who);
				break;
			case 10..29:
				add_level_b_user(who);
				break;
			default:
				add_level_c_user(who);
				break;
			}
		else
			add_battle_user(who);

		// if( who->get_leader() ) TEAM_D->add_member( who->get_leader(), who );

		CHAT_D->add_chat(who);
		CHAT_D->add_rumor(who);
		FAMILY_D->add_family(who);
		FAMILY_D->add_city(who);
		FAMILY_D->add_org(who);
	}
}

void sub_user(object who)
{
	if (objectp(who) && userp(who))
	{
		if (sizeof(Users))
			Users -= ({who, 0});
		if (!is_player(who))
			sub_gm(who);
		else
			sub_player(who);

		if (!MAP_D->is_inside_battle(get_z(who)))
			switch (who->get_level())
			{
			case 0..9:
				sub_level_a_user(who);
				break;
			case 10..29:
				sub_level_b_user(who);
				break;
			default:
				sub_level_c_user(who);
				break;
			}
		else
			sub_battle_user(who);

		// if( who->get_leader() ) TEAM_D->remove_member( who->get_leader(), who );

		CHAT_D->sub_chat(who);
		CHAT_D->sub_rumor(who);
		FAMILY_D->sub_family(who);
		FAMILY_D->sub_city(who);
		FAMILY_D->sub_org(who);
	}
}

void user_channel(string chat)
{
	Users -= ({0});
	if (sizeof(Users))
		send_user(Users, "%c%c%d%s", 0x43, 10, 0, chat);
}

void gm_channel(string chat)
{
	Gms -= ({0});
	if (sizeof(Gms))
		send_user(Gms, "%c%s", '>', chat);
}

void rumor_gm_channel(string chat)
{
	Gms -= ({0});
	if (sizeof(Gms))
		send_user(Gms, "%c%c%d%s", 0x43, 2, 0, chat);
}

void save_all_data()
{
	object *user, who, me, obj, *inv, map, item, zom, *zombie, ben;
	mapping org;
	int time, time2, i, size, level, cash, saving, size2, p, x, y, z, x1, y1, n;
	string id, order;

	if (arrayp(user = users()))
		for (i = 0, size = sizeof(user); i < size; i++)
		{
			if (!objectp(who = user[i]))
				continue;
			if (!stringp(who->get_id()))
				continue;
			if (who->get_login_flag() < 2)
				continue;

			if (who->get_level() >= 55)
			{
				//    if((item = who->get_equip(WEAPON_TYPE))&&item->get_item_color()==3) who->remove_equip(WEAPON_TYPE);
				if ((item = who->get_equip(ARMOR_TYPE)) && item->get_item_color() == 3)
					who->remove_equip(ARMOR_TYPE);
				if ((item = who->get_equip(HEAD_TYPE)) && item->get_item_color() == 3)
					who->remove_equip(HEAD_TYPE);
				if ((item = who->get_equip(NECK_TYPE)) && item->get_item_color() == 3)
					who->remove_equip(NECK_TYPE);
				if ((item = who->get_equip(WAIST_TYPE)) && item->get_item_color() == 3)
					who->remove_equip(WAIST_TYPE);
				if ((item = who->get_equip(BOOTS_TYPE)) && item->get_item_color() == 3)
					who->remove_equip(BOOTS_TYPE);
				// who->hide_title();
			}
			if (random(100) < 30)
				who->add_to_scene(80, 352, 196);
			else if (random(100) < 40)
				who->add_to_scene(80, 387, 196);
			else if (random(100) < 50)
				who->add_to_scene(80, 361, 146);
			else if (random(100) < 60)
				who->add_to_scene(80, 340, 132);
			else if (random(100) < 70)
				who->add_to_scene(80, 197, 227);
			else if (random(100) < 80)
				who->add_to_scene(80, 287, 215);
			else
				who->add_to_scene(80, 244, 124);
			z = get_z(who);
			x = get_x(who);
			y = get_y(who);
			map = get_map_object(z);
			for (i = 0; i < 500; i++)
			{
				inv = all_inventory(who, 1, MAX_CARRY * 4);
				if (!(size2 = sizeof(inv)))
					break;
				if (!(p = get_valid_xy(z, x + random(3) - 1, y + random(3) - 1, IS_ITEM_BLOCK)))
					continue;
				{

					x1 = p / 1000;
					y1 = p % 1000;

					n = random(size2);
					if (inv[n]->get_name() != "Cờ Hiệu Vô Song Thành")
						continue;
					inv[n]->remove_from_user();
					inv[n]->add_to_scene(z, x1, y1);
					inv[n]->set_owner(0);
					CHAT_D->sys_channel(0, sprintf(HIY "%s " HIR "đã làm rơi Cờ Hiệu Vô Song Thành ngay tại " HIY "%s ( %d, %d )", who->get_name(), map->get_name(), x, y));
				}
			}
			if (zom = who->get("soldier"))
			{
				zom->remove_from_scene(FALL_ACT);
				destruct(zom);
			}
			if (arrayp(zombie = who->get("zombie")) && (size = sizeof(zombie)))
			{
				for (i = 0; i < size; i++)
					if (zombie[i])
					{
						zombie[i]->remove_from_scene(FALL_ACT);
						destruct(zombie[i]);
					}
			}
			if (ben = who->get_save("trongcayabcxyz"))
			{
				who->delete_save("trongcayabcxyz2");
				who->set_save("trongcayhh", 1);
				ben->remove_from_scene();
				destruct(ben);
				who->delete_save("trongcayabcxyz");
			}
			if (ben = who->get_save("trongcayabcxyz3"))
			{
				who->delete_save("trongcayabcxyz4");
				who->set_save("trongcayhh", 1);
				ben->remove_from_scene();
				destruct(ben);
				who->delete_save("trongcayabcxyz3");
			}
			time = gone_time(who->get_login_time());
			who->set_game_time(who->get_game_time() + time);
			who->add_save("login_count", -1);
			level = who->get_level();
			cash = who->get_cash();
			saving = who->get_savings();
			if (!is_player(who))
			{
				level = 0;
				cash = 0;
				saving = 0;
			}

			me = who;

			if (MAIN_D->get_host_type() == 4 || MAIN_D->get_host_type() == 0 || MAIN_D->get_host_type() == 6012 || MAIN_D->get_host_type() == 1000)
			{
				/*db_user_fee(me, sprintf(MAIN_D->get_php_ip() + ":80\n"
					"GET http://%s/logout.php?t=%s&u=%d&r=%d&h=%d\r\n",
					MAIN_D->get_php_ip(), short_time_2(), me->get_acountid(), MAIN_D->get_region(), MAIN_D->get_host()));*/

				obj = new ("/inh/user/list");
				id = me->get_id();
				obj->set_owner(me->get_real_id());
				if (me->get_real_id() == id)
					order = "1";
				else
					order = id[ < 1.. < 1];
				obj->set_save_2(order + ".number", me->get_number());
				obj->set_save_2(order + ".shape", me->get_armor_code());
				obj->set_save_2(order + ".level", me->get_level());
				obj->set_save_2(order + ".gold", cash + saving);
				obj->set_save_2(sprintf("%s.armor", order), me->get_armor_code());
				obj->set_save_2(sprintf("%s.armorc", order), me->get_armor_color_1());
				obj->set_save_2(sprintf("%s.hair", order), me->get_hair());
				obj->set_save_2(sprintf("%s.hairc", order), me->get_hair_color());
				obj->set_save_2(sprintf("%s.back", order), me->get_back());
				obj->set_save_2(sprintf("%s.backc", order), me->get_back_color());
				obj->set_save_2(sprintf("%s.back2", order), me->get_back2());
				obj->set_save_2(sprintf("%s.back2c", order), me->get_back2_color());
				obj->set_save_2(sprintf("%s.weapon", order), me->get_weapon_code_2());
				obj->set_save_2(sprintf("%s.weaponc", order), me->get_weapon_color());
				obj->set_save_2(sprintf("%s.weaponc2", order), me->get_weapon_color_2());
				obj->set_save_2(sprintf("%s.family", order), me->get_fam_name());
				obj->save();
				destruct(obj);
			}
			else
			{
				// db_user_fee(who, sprintf(MAIN_D->get_php_ip() + ":80\n"
				// 												"GET /xq2/fee.php?id=%s&start=%d&end=%d&time=%d&count=%d&region=%d&host=%d&shape=%d&level=%d&gold=%d&ip=%s\r\n",
				// 						 rawurlencode(who->get_id()), who->get_login_time(), who->get_login_time() + time, time, who->get_feetime(), MAIN_D->get_region(), MAIN_D->get_host(), who->get_armor_code(), level, cash + saving, get_ip_name(who))); // 扣费！
			}
			time2 = who->get_feetime() + time;
			if (time2 >= FEE_TIME)
			{
				who->set_fee_start(time());
				who->set_feetime(time2 % FEE_TIME);
			}
			else
				who->set_feetime(time2);

			who->set_quit_time(time());
			who->set_quit_ip(get_ip_name(who));

			who->save();
			send_user(who, "%c%c", 0x49, 0xff);
		}

	CITY_QI->save();
	CITY_HAN->save();
	CITY_ZHAO->save();
	CITY_WEI->save();
	CITY_QIN->save();
	CITY_CHU->save();
	CITY_YAN->save();
	CITY_ZHOU->save();

	if (mapp(org = CITY_ZHOU->get_2("org")) && arrayp(user = values(org)))
		for (i = 0, size = sizeof(user); i < size; i++)
			if (user[i])
				user[i]->save();
}
