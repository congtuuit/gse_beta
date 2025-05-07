#include <ansi.h>
#include <npc.h>
#include <city.h>
#include <skill.h>
#include <effect.h>
#include <equip.h>
#include <item.h>
#include <action.h>
#include <public.h>

#define NGU_HANH "sys/item/itemAttribute.c"
string *ngu_hanh_names = ({"Kim", "Mộc", "Thổ", "Thuỷ", "Hoả"});

// co the danh gm 0: no, 1: yes
int CAN_KILL_GM = 1;

int set_enmity(object who, object enemy, int count);
void SAVE_BINARY() {}

/*
 * NGOAI CONG
 * return damge ngoai cong
 */
int correct_damage(object me, object who, int damage, int ap)
{
	object item;
	int point, change;

	if ((is_gm2(who) || is_god(who) || is_gm3(who)) && CAN_KILL_GM == 0)
	{
		return 0;
	}

	if (get_effect(who, EFFECT_CHAR_DREAM_1))
		return 0;

	if (damage < 1)
		damage = 1;

	if (who->is_user())
	{
		// Giap Mana skill con luan
		if (point = who->get_change_hurt())
		{
			point = damage * point / 100;
			change = point / 2;
			if (change <= who->get_mp())
			{
				who->add_mp(-change);
				damage -= point;
				send_user(get_scene_object_2(who, USER_TYPE), "%c%d%w%c%c%c", 0x6f, getoid(who), 32211, 1, OVER_BODY, PF_ONCE);
				send_user(who, "%c%d%w", 0x6d, getoid(who), change);
			}
			else
			{
				change = who->get_mp();
				point = change * 2;
				who->add_mp(-change);
				damage -= point;
				send_user(get_scene_object_2(who, USER_TYPE), "%c%d%w%c%c%c", 0x6f, getoid(who), 32211, 1, OVER_BODY, PF_ONCE);
				send_user(who, "%c%d%w", 0x6d, getoid(who), change);

				if (get_effect(me, EFFECT_CHAR_CHANGE))
					set_effect(me, EFFECT_CHAR_CHANGE, 1);
			}
		}

		// ti le giam sat thuong ngoai cong
		if (point = who->get_anti_hurt_rate())
			damage -= damage * point / 100;

		// Giam thuong ngoai cong
		if (point = who->get_anti_hurt())
			damage -= point;

		// Phap bao Cuu long than hoa trao
		if (!get_effect(who, EFFECT_CHAR_SUPPRESS) && objectp(item = who->get_equip(HAND_TYPE)) && item->get_talisman_type() == 2 && item->get_lasting() >= 100 && random(100) < item->get_active_rate() && (point = item->get_hp()) > 0)
		{
			if (damage > point)
			{
				item->set_hp(0);
				damage -= point;
			}
			else
			{
				item->add_hp(-damage);
				damage = 0;
			}

			// Giam do ben phap bao
			item->add_lasting(-1);
		}

		// Ti le sat thuong: point
		if ((point = who->get_hurt_rate()) && who->get_mp() >= 6 && random(100) < who->get_hurt_rand())
		{
			send_user(get_scene_object_2(who, USER_TYPE), "%c%d%w%c%c%c", 0x6f, getoid(who), 31711, 1, OVER_BODY, PF_ONCE);
			if (me->get_level() < who->get_skill(SKILL_0317))
				me->add_hp(-damage * point / 100);
			else
				me->add_hp(-damage * point / 100 * who->get_skill(SKILL_0317) / me->get_level());
			who->add_mp(-6);
		}
	}
	else if (who->is_boss())
	{
		if (point = who->get_change_hurt())
		{
			point = damage * point / 100;
			change = point / 2;
			damage -= point;
			send_user(get_scene_object_2(who, USER_TYPE), "%c%d%w%c%c%c", 0x6f, getoid(who), 32211, 1, OVER_BODY, PF_ONCE);
		}

		if (point = who->get_anti_hurt_rate())
			damage -= damage * point / 100;
		if (point = who->get_anti_hurt())
			damage -= point;

		if ((point = who->get_hurt_rate()) && random(100) < who->get_hurt_rand())
		{
			me->add_hp(-damage * point / 100);
		}
	}

	if (me->get_comrade_type() == 82)
	{
		if (who->get_comrade_type() == 95 || who->get_comrade_type() == 80)
			damage = 800;
		else
			damage = 400;
	}

	if (who->get_comrade_type() == 82)
	{
		if (me->get_comrade_type() == 95 || me->get_comrade_type() == 80)
			damage /= 5;
	}

	return damage;
}

/*
 * NOI CONG
 * return damge noi cong
 */
int correct_damage_2(object me, object who, int damage, int cp)
{
	object item;
	int point;

	if ((is_gm2(who) || is_god(who) || is_gm3(who)) && CAN_KILL_GM == 0)
	{
		return 0;
	}

	if (get_effect(who, EFFECT_CHAR_DREAM_1))
		return 0;

	if (damage < 1)
		damage = 1;

	if (who->is_user())
	{
		if (point = who->get_anti_hurt_rate_2())
			damage -= damage * point / 100;
		if (point = who->get_anti_hurt_2())
			damage -= point;

		if (!get_effect(who, EFFECT_CHAR_SUPPRESS) && objectp(item = who->get_equip(HAND_TYPE)) && item->get_talisman_type() == 2 && item->get_lasting() >= 100 && random(100) < item->get_active_rate() && (point = item->get_hp()) > 0)
		{
			if (damage > point)
			{
				item->set_hp(0);
				damage -= point;
			}
			else
			{
				item->add_hp(-damage);
				damage = 0;
			}
			item->add_lasting(-1);
		}

		if ((point = who->get_hurt_rate_2()) && random(100) < who->get_hurt_rand_2())
		{
			me->add_hp(-damage * point / 100);
		}
	}
	else if (who->is_boss())
	{
		if (point = who->get_anti_hurt_rate_2())
			damage -= damage * point / 100;
		if (point = who->get_anti_hurt_2())
			damage -= point;

		if ((point = who->get_hurt_rate_2()) && random(100) < who->get_hurt_rand_2())
		{
			me->add_hp(-damage * point / 100);
		}
	}

	return damage;
}

/*
 * NOI CONG SAT THUONG CHUAN
 * return damge noi cong
 */
// Chức năng: Cố định lỗi chính tả thiệt hại (mảng cờ)
int correct_damage_3(object me, object who, int damage, int cp) // 抄自 correct_damage_2
{
	object item, map;
	int point;

	if ((is_gm2(who) || is_god(who) || is_gm3(who)) && CAN_KILL_GM == 0)
	{
		return 0;
	}

	if (get_effect(who, EFFECT_CHAR_DREAM_1))
		return 0;

	if (damage < 1)
		damage = 1;

	if (who->is_user())
	{
		if (point = who->get_anti_hurt_rate_2())
			damage -= damage * point / 100;
		if (point = who->get_anti_hurt_2())
			damage -= point;

		if (!get_effect(who, EFFECT_CHAR_SUPPRESS)		 // 没有压制
			&& objectp(item = who->get_equip(HAND_TYPE)) // 法宝
			&& item->get_talisman_type() == 2			 // 九龙神火罩
			&& item->get_lasting() >= 100				 // 耐久度
			&& random(100) < item->get_active_rate()	 // 成功率
			&& (point = item->get_hp()) > 0)			 // 气血
		{
			if (damage > point)
			{
				item->set_hp(0);
				damage -= point;
			}
			else
			{
				item->add_hp(-damage);
				damage = 0;
			}
			item->add_lasting(-1);
		}
	}
	else if (who->is_boss())
	{
		if (point = who->get_anti_hurt_rate_2())
			damage -= damage * point / 100;
		if (point = who->get_anti_hurt_2())
			damage -= point;
	}

	return damage;
}

// Chức năng: Thiết bị mất độ bền
void wear_down(object who)
{
	object *inv = who->get_all_equip();

	switch (random(100))
	{
	case 0..14:
		if (objectp(inv[0]))
			inv[0]->add_lasting(-1);
		break;
	case 15..24:
		if (objectp(inv[1]))
			inv[1]->add_lasting(-1);
		break;
	case 25..69:
		if (objectp(inv[3]))
			inv[3]->add_lasting(-1);
		break;
	case 70..84:
		if (objectp(inv[4]))
			inv[4]->add_lasting(-1);
		break;
	case 85..94:
		if (objectp(inv[5]))
			inv[5]->add_lasting(-1);
		break;
		// default : if( objectp( inv[6] ) && inv[6]->get_item_type() == ITEM_TYPE_TALISMAN && !inv[6]->is_limit_time_item() ) inv[6]->add_lasting(-1);  break;
	}
}

// Chức năng: Combat xử lý (hành động)
varargs int attack_action(object me, object who, int pf, int distance)
{
	int act;

	if (!who || !who->can_be_fighted(me) || !me->can_fight(who))
		return 0;

	if ((is_gm2(who) || is_god(who) || is_gm3(who)) && CAN_KILL_GM == 0)
	{
		return 0;
	}

	if (distance_between(me, who) > range_value(distance, 1, MAX_NUMBER))
	{
		return 0;
	}

	me->to_front_xy(get_x(who), get_y(who));

	if (pf > 1000)
	{
		act = pf / 1000;
		pf = pf % 100;
	}
	else if (!(act = pf / 10))
	{
		pf = 0;
		act = 1 + random(3);
	}
	if (me->is_user())
		CHAR_CHAR_D->stop_loop_perform_9(me);

	if (me->get_weapon_code() == THROWING)
		send_user(get_scene_object_2(me, USER_TYPE), "%c%d%d%c%c%c%d", 0x42, getoid(me), time2(), act, pf, get_d(me), getoid(who));
	else
		send_user(get_scene_object_2(me, USER_TYPE), "%c%d%d%c%c%c%d", 0x41, getoid(me), time2(), act, pf, get_d(me), getoid(who));

	return 1;
}

// Tang cong vat ly - ngoai cong
// Giam bao ho
//  Chức năng: chế biến Combat --- co ngu hanh
varargs int attack_done(object me, object who, int hit_act, int add_ap, int hit_rate, int damage_rate, int sub_dp_rate, int distance) // hit_rate: 10000 表示全中
{
	object *user, item, item1, item2, item3, item4, item5, item6, owner, pet, map, nguoichoi, nguoichoi1, nguoichoi2, nguoichoi3, ai;
	int ap, ap0, ap2, dp, dp0, dp2, asp, dsp, p;
	int rate, tyle, cap, damage, level, level2, yuan, poison, point, id, random, double_flag;
	int rate_nguhanh;

	if (!who || !who->can_be_fighted(me) || !me->can_fight(who))
		return 0;

	if ((is_gm2(who) || is_god(who) || is_gm3(who)) && CAN_KILL_GM == 0)
	{
		return 0;
	}
	map = get_map_object(get_z(me));
	if (me->is_user() && who->is_user() && (get_z(me) < 885 || map->is_org_map() || map->is_copy_scene() || map->is_pvp()))
	{
		if (me->is_user() && who->is_user() && me->get_attack_mode() != 1 && me->get_pk() < 100 && who->get_pk() < 100 && !get_effect(who, EFFECT_USER_PK))
		{
			me->set_char_type(PK_TYPE);
			set_effect(me, EFFECT_USER_PK, 180);
		}
		else if (me->is_user() && who->is_user() && me->get_attack_mode() != 1 && (me->get_pk() >= 100 || get_effect(who, EFFECT_USER_PK) || who->get_pk() >= 100))
		{
			set_effect(me, EFFECT_USER_PK, 0);
		}
	}
	if (me->is_user() && who->is_pet() && (get_z(me) < 885 || map->is_org_map() || map->is_copy_scene() || map->is_pvp()))
	{
		nguoichoi1 = who->get_owner();
		if (me->is_user() && who->is_pet() && nguoichoi1->is_user() && me->get_attack_mode() != 1 && me->get_pk() < 100 && nguoichoi1->get_pk() < 100 && !get_effect(nguoichoi1, EFFECT_USER_PK))
		{
			me->set_char_type(PK_TYPE);
			set_effect(me, EFFECT_USER_PK, 180);
		}
		else if (me->is_user() && who->is_pet() && nguoichoi1->is_user() && me->get_attack_mode() != 1 && (me->get_pk() >= 100 || get_effect(nguoichoi1, EFFECT_USER_PK) || nguoichoi1->get_pk() >= 100))
		{
			set_effect(me, EFFECT_USER_PK, 0);
		}
	}

	if (me->is_pet() && who->is_user() && (get_z(me) < 885 || map->is_org_map() || map->is_copy_scene() || map->is_pvp()))
	{
		nguoichoi = me->get_owner();
		if (me->is_pet() && nguoichoi->is_user() && who->is_user() && nguoichoi->get_attack_mode() != 1 && nguoichoi->get_pk() < 100 && who->get_pk() < 100 && !get_effect(who, EFFECT_USER_PK))
		{
			nguoichoi->set_char_type(PK_TYPE);
			set_effect(nguoichoi, EFFECT_USER_PK, 180);
		}
		else if (me->is_pet() && nguoichoi->is_user() && who->is_user() && nguoichoi->get_attack_mode() != 1 && (nguoichoi->get_pk() >= 100 || get_effect(who, EFFECT_USER_PK) || who->get_pk() >= 100))
		{
			set_effect(nguoichoi, EFFECT_USER_PK, 0);
		}
	}

	if (me->is_zombie() && who->is_user() && (get_z(me) < 885 || map->is_org_map() || map->is_copy_scene() || map->is_pvp()))
	{
		nguoichoi3 = me->get_owner();

		if (me->is_zombie() && nguoichoi3->is_user() && who->is_user() && nguoichoi3->get_attack_mode() != 1 && nguoichoi3->get_pk() < 100 && who->get_pk() < 100 && !get_effect(who, EFFECT_USER_PK))
		{
			nguoichoi3->set_char_type(PK_TYPE);
			set_effect(nguoichoi3, EFFECT_USER_PK, 180);
		}

		else if (me->is_zombie() && nguoichoi3->is_user() && who->is_user() && nguoichoi3->get_attack_mode() != 1 && (nguoichoi3->get_pk() >= 100 || get_effect(who, EFFECT_USER_PK) || who->get_pk() >= 100))
		{
			set_effect(nguoichoi3, EFFECT_USER_PK, 0);
		}
	}

	if (get_effect(me, EFFECT_CHAR_GOOD_BAD))
		damage_rate += 10;

	if (who->is_npc())
	{
		if (who->get_enemy_4() == me)
			who->set_attack_time(time());
		else if (gone_time(who->get_attack_time()) > 12)
		{
			who->set_enemy_4(me);
			who->set_attack_time(time());
		}
		if (!who->get_max_damage() && who->get_action_mode() == 1)
			who->init_enemy_damage(me, 0);
	}

	if (functionp(me->get_when_enemy_be_hit()))
	{
		evaluate(me->get_when_enemy_be_hit(), me, who, hit_act, distance);
		return;
	}

	asp = me->get_sp();
	dsp = who->get_sp();

	// ti le Than thu
	rate = asp * 86 / range_value(dsp, 1, MAX_NUMBER);

	level2 = who->get_level();
	level = me->get_level();
	rate = 100 - dsp * 100 / (level2 * 90 + 700);
	if (level < level2 && !me->is_comrade() && !who->is_comrade())
		rate = rate * (level + 10) / (level2 + 10);

	rate = range_value(rate, 5, 100);

	rate += me->get_hit_rate() - who->get_dodge_rate() - who->get_2("suit_effect.dodge") + hit_rate;
	if (get_effect(me, EFFECT_CHAR_BLIND))
		rate /= 2;
	if (get_effect(who, EFFECT_DODGE))
		rate -= 20;
	if (get_effect(who, EFFECT_MAGIC_4243))
		rate -= 50;
	if (get_effect(who, EFFECT_CHAR_MOVE))
		rate -= who->get_save("03641");

	if (rate < 1000)
		rate = range_value(rate, 5, 100);
	if (get_effect(me, EFFECT_CHAR_IGNORE) || get_effect(who, EFFECT_CHAR_IGNORE))
		rate = 0;
	random = random100();

	// Tang chinh xac khi co ngu hanh
	/*
	if (me->get_2("nguhanh_rate") > 0) {
		rate += me->get_2("nguhanh_rate");
	}
	*/

	if (random < rate)
	{
		if (who->is_trainer())
		{
			who->beat(me);
			return 1;
		}

		if (get_effect(who, EFFECT_03642))
		{
			"/skill/03/03642"->into_effect(who);
			set_effect(who, EFFECT_03642, 0);
			return 0;
		}

		if (me->get_weapon_code() == THROWING)
		{
			item = me->get_equip(WEAPON_TYPE);
			ap0 = !objectp(item) || item->get_lasting() < 100 ? 0 : item->get("ap");

			if (point = me->get_skill(SKILL_0261))
				ap0 += point;
			else if (point = me->get_skill(SKILL_0161))
				ap0 += point / 2;

			ap = range_value(me->get_ap() - ap0, 0, MAX_NUMBER);
			ap0 = range_value(ap - 35, 0, MAX_NUMBER);
		}
		else
		{
			ap = me->get_ap();
			ap0 = me->get_ap_0();
		}
		if (me->get("sk74221"))
			ap0 = ap;
		if (me->get("sk74127"))
			ap = ap0;
		ap += add_ap;
		ap0 += add_ap;

		dp = who->get_dp();
		dp0 = who->get_dp_0();
		if (me->get("sk74221"))
			dp = dp0;
		if (me->get("sk74127"))
			dp0 = dp;

		dp -= dp * sub_dp_rate / 100;
		dp0 -= dp0 * sub_dp_rate / 100;

		damage = me->get_lucky();
		ap2 = ap0 + (ap - ap0) * damage / 100 + random((ap - ap0) * (100 - damage) / 100);
		dp2 = dp0 + (dp - dp0) * damage / 100 + random((dp - dp0) * (100 - damage) / 100);

		// Đồng môn
		if (me->is_comrade() || who->is_comrade())
		{
			damage = (ap2 - ap2 * dp2 / (40 + dp2)); // 25 / 1000
		}
		else
		{
			damage = (ap2 * 11 + dp2 * 49) / 50;
			damage = ap2 - ap2 * dp2 / range_value(damage, 1, MAX_NUMBER);
		}

		if (!me->is_comrade() && !who->is_comrade())
			damage = damage * (level + 10) / (level2 + 10);

		damage = correct_damage(me, who, range_value(damage, 1, ap2), ap);
		if (p = me->get_skill(0430))
		{
			damage = damage * (100 + p * 2) / 100;
		}

		damage += damage * damage_rate / 100;
		damage += damage * me->get_save("03162#") / 100;
		damage += damage * who->get("sk74124") / 100;

		damage += me->get("add_damage");
		if (me->is_zombie() && who->is_user() && (get_z(me) == 001 || get_z(me) == 289 || get_z(me) == 269 || get_z(me) == 273 || get_z(me) == 165 || get_z(me) == 324 || get_z(me) == 054 || get_z(me) == 080))
		{
			damage = 1;
			me->set_hp(0);
			me->set_die(1);
		}

		rate = me->get_double_rate();

		random = random(10000);
		if (random < rate)
		{
			damage = damage * 2;

			if ((rate = who->get_2("suit_effect.double1")) && (p = who->get_2("suit_effect.double2")))
			{
				double_flag = random(p);
				if (double_flag < rate)
				{
					double_flag = rate;
				}

				damage = (damage / 2) + ((damage / 2) * (100 - double_flag) / 100);
			}

			double_flag = 1;

			// pet hoa su
			// Tang bao kich
			if (me->get_2("jiguan.addRateDouble") > 0 && random(100) <= me->get_2("jiguan.addRateDouble"))
			{
				if (me->get_2("jiguan.addDouble"))
				{
					damage = damage + (damage * me->get_2("jiguan.addDouble") / 100);
				}
			}

			// Giam bao kich
			if (who->get_2("jiguan.subRateDouble") > 0 && random(100) <= who->get_2("jiguan.subRateDouble"))
			{
				if (who->get_2("jiguan.subDouble"))
				{
					damage = damage * who->get_2("jiguan.subDouble") / 100;
				}
			}
		}

		// Bảo hộ-ngoại công
		if (p = who->get_skill(0438))
		{
			damage = damage * (100 - p * 2) / 100;
		}
		if (p = who->get_skill(0431))
		{
			damage = damage * (100 - p * 2) / 100;
		}

		if (is_god(me))
		{
			if (NGU_HANH->get_nguhanh_rate(who, ARMOR_TYPE) > 0 && NGU_HANH->get_nguhanh_rate(me, WEAPON_TYPE) > 0)
			{
				tell_user(me, HIG "%s -> %s %d%% [Giap]", ngu_hanh_names[NGU_HANH->get_nguhanh_rate(me, WEAPON_TYPE) - 1],
						  ngu_hanh_names[NGU_HANH->get_nguhanh_rate(who, ARMOR_TYPE) - 1], NGU_HANH->counting_tuongkhac_giap_rate(me, who));
			}

			if (NGU_HANH->get_nguhanh_rate(who, WEAPON_TYPE) > 0 && NGU_HANH->get_nguhanh_rate(me, WEAPON_TYPE) > 0)
			{
				tell_user(me, HIG "%s -> %s %d%% [Vũ khí]", ngu_hanh_names[NGU_HANH->get_nguhanh_rate(me, WEAPON_TYPE) - 1],
						  ngu_hanh_names[NGU_HANH->get_nguhanh_rate(who, WEAPON_TYPE) - 1], NGU_HANH->counting_tuongkhac_vk_rate(me, who));
			}
		}

		if (is_god(me))
		{
			tell_user(me, HIG "ngũ hành debug Sát thương gốc: %d", damage);
			tell_user(me, HIG "ngũ hành debug me: %d ---- who: %d", NGU_HANH->is_nguhanh(me), NGU_HANH->is_nguhanh(who));
		}

		/*ngu hanh*/
		// if (NGU_HANH->is_nguhanh(me) == 1 && NGU_HANH->is_nguhanh(who) == 0)
		// {
		// 	damage += damage * 150 / 1000;
		// 	if (is_god(me))
		// 	{
		// 		tell_user(me, ECHO "Giá trị ngũ hành: %d%%", 15);
		// 	}
		// }
		// if (NGU_HANH->is_nguhanh(who) == 1 && NGU_HANH->is_nguhanh(me) == 0)
		// {
		// 	damage = damage * 750 / 1000;
		// 	if (is_god(me))
		// 	{
		// 		tell_user(me, ECHO "Giá trị ngũ hành: %d%%", -15);
		// 	}
		// }
		// if (NGU_HANH->counting_nguhanh_rate(me, who) != 0 && NGU_HANH->is_nguhanh(me) == 1 && NGU_HANH->is_nguhanh(who) == 1)
		// {
		// 	rate_nguhanh = NGU_HANH->counting_nguhanh_rate(me, who);
		// 	me->set_2("nguhanh_rate", rate_nguhanh);
		// 	damage += damage * rate_nguhanh * 10 / 1000;

		// 	if (is_god(me))
		// 	{
		// 		tell_user(me, HIG "Giá trị ngũ hành tăng: %d%%", rate_nguhanh);
		// 	}
		// }

		/*ngu hanh*/
		// Show if god
		// if (is_god(me)) tell_user(me, "R %s Tấn công vật lý gần-> %s, Độ chính xác: %d random %02d Thành Công - AP: %d - DP: %d = Thương: %d ", me->get_name(), who->get_name(), rate, random, ap2, dp2, damage);
		// if (is_god(who)) tell_user(who, "R %s Tấn công vật lý gần-> %s, Độ chính xác: %d random %02d Thành Công - AP: %d - DP: %d = Thương: %d ", me->get_name(), who->get_name(), rate, random, ap2, dp2, damage);

		damage += me->get_2("suit_effect.damage1"); // 套装
		damage = damage * (100 - who->get_2("suit_effect.damage_rate1")) / 100;
		if (who->get_perform("05016#"))
			damage = damage * 4 / 5;
		if (damage < 1)
			damage = 1;
		if (get_effect(me, EFFECT_CHAR_POWERFALL))
		{
			if (me->is_user())
				damage = damage * (100 + me->get_save_2("pf.powerfall")) / 100;
			else
				damage = damage * (100 + me->get("pf.powerfall")) / 100;
			if (damage < 0)
				damage = 1;
		}
		if (get_effect(who, EFFECT_CHAR_MISS)) // 灵气甲
		{
			if (damage < who->get_save("pf.miss") && damage < who->get_mp())
			{
				who->add_mp(-damage);
				who->add_save("pf.miss", -damage);
				send_user(get_scene_object_2(who, USER_TYPE), "%c%d%w%c%c%c", 0x6f, getoid(who), 42515, 1, OVER_BODY, PF_ONCE);
				send_user(who, "%c%w%c", 0x82, 4252, 0);
				return 1;
			}
			else if (who->get_mp() > who->get_save("pf.miss"))
			{
				damage -= who->get_save("pf.miss");
				who->add_mp(-who->get_save("pf.miss"));
			}
			else
			{
				damage -= who->get_mp();
				who->set_mp(0);
			}
			"/sys/char/char"->effect_miss_done(who);
			set_effect(who, EFFECT_CHAR_MISS, 0);
		}
		if (get_effect(who, EFFECT_CHAR_MISS2)) // 云梦的灵气甲
		{
			send_user(get_scene_object_2(who, USER_TYPE), "%c%d%w%c%c%c", 0x6f, getoid(who), 42525, 1, OVER_BODY, PF_ONCE);
			if (who->is_user())
			{
				if (who->add_save("05911", -damage) < 0)
				{
					damage = -who->get_save("05911");
					set_effect(who, EFFECT_CHAR_MISS2, 1);
				}
				else
					return 1;
			}
			else
			{
				if (who->add("05911", -damage) < 0)
				{
					damage = -who->get("05911");
					set_effect(who, EFFECT_CHAR_MISS2, 1);
				}
				else
					return 1;
			}
		}
		else
		{
			if (who->is_user() && objectp(item = who->get_equip(WEAPON_TYPE)) &&
				item->get_name() == "Anh Kiệt Quyền Nhẫn" && random100() < 10)
			{
				// who->set_save("05911", 630);
				set_effect(who, EFFECT_CHAR_MISS2, 30);
				send_user(who, "%c%w%w%c", 0x81, 5911, get_effect_3(who, EFFECT_CHAR_MISS2), EFFECT_GOOD);
				send_user(get_scene_object_2(who, USER_TYPE) - ({who}), "%c%d%w%c%c", 0x83, getoid(who), 5911, 1, EFFECT_GOOD);
				send_user(get_scene_object_2(who, USER_TYPE), "%c%d%w%c%c%c", 0x6f, getoid(who), 10711, 1, OVER_BODY, PF_LOOP);
			}
			if (who->is_user() && objectp(item = who->get_equip(WEAPON_TYPE)) &&
				item->is_thanbinh1() && random100() < 5)
			{
				// who->set_save("05911", 1500);
				// set_effect(who, EFFECT_CHAR_MISS2, 30);
				/*send_user(who, "%c%w%w%c", 0x81, 5911, get_effect_3(who, EFFECT_CHAR_MISS2), EFFECT_GOOD);
				send_user(get_scene_object_2(who, USER_TYPE) - ({ who }), "%c%d%w%c%c", 0x83, getoid(who), 5911, 1, EFFECT_GOOD);
				send_user(get_scene_object_2(who, USER_TYPE), "%c%d%w%c%c%c", 0x6f, getoid(who), 10711, 1, OVER_BODY, PF_LOOP);*/
			}
		}
		if (me->is_user() && objectp(item = me->get_equip(WEAPON_TYPE)))
		{
			if (item->get_name() == "Thiên Tôn Bảo Đao" && random100() < 15)
				damage += 200;
			else if (item->get_name() == "Đao Tử Vân" && random100() < 15)
				damage += 200;
			else if (item->is_thanbinh3() && random100() <= 30)
				damage += 600;
			else if (item->get_name() == "Chân Quân Xí Diệm Thương" && random100() < 15 && (-who->get("pf.armorfall")) < 120)
			{
				// 70级的茅山蚀甲
				set_effect(who, EFFECT_CHAR_ARMORFALL, 120);
				send_user(who, "%c%w%w%c", 0x81, 4143, get_effect_3(who, EFFECT_CHAR_ARMORFALL), EFFECT_BAD);
				send_user(get_scene_object_2(who, USER_TYPE) - ({who}), "%c%d%w%c%c", 0x83, getoid(who), 4143, 1, EFFECT_BAD);
				if (who->is_user())
				{
					who->set("pf.armorfall", -120);
					who->set("pf.armorfall2", -85);
					who->set_save_2("pf.armorfall", -120);
					who->set_save_2("pf.armorfall2", -85);
					USER_ENERGY_D->count_pp(who);
					USER_ENERGY_D->count_dp(who);
				}
				else
				{
					who->add_dp(who->set("pf.armorfall", -120));
					who->add_pp(who->set("pf.armorfall2", -85));
				}
			}
			else if (item->get_name() == "Lục Thần Thương" && random100() < 15 && (-who->get("pf.armorfall")) < 160)
			{
				// 70级的茅山蚀甲
				set_effect(who, EFFECT_CHAR_ARMORFALL, 120);
				send_user(who, "%c%w%w%c", 0x81, 4143, get_effect_3(who, EFFECT_CHAR_ARMORFALL), EFFECT_BAD);
				send_user(get_scene_object_2(who, USER_TYPE) - ({who}), "%c%d%w%c%c", 0x83, getoid(who), 4143, 1, EFFECT_BAD);
				if (who->is_user())
				{
					who->set("pf.armorfall", -160);
					who->set("pf.armorfall2", -85);
					who->set_save_2("pf.armorfall", -160);
					who->set_save_2("pf.armorfall2", -85);
					USER_ENERGY_D->count_pp(who);
					USER_ENERGY_D->count_dp(who);
				}
				else
				{
					who->add_dp(who->set("pf.armorfall", -160));
					who->add_pp(who->set("pf.armorfall2", -85));
				}
			}
			else if (item->is_thanbinh4())
			{
				if (random100() < 5)
				{
					if (get_effect(who, EFFECT_CHAR_FAINT))
						return 0;
					if (get_effect(who, EFFECT_CHAR_FAINT_0))
						return 0;
					if (who->is_anti_effect())
						return 0;
					if (who->get("anti_faint"))
						return 0;
					if (who->get_perform("02222#"))
						return 0;

					user = get_scene_object_2(who, USER_TYPE);
					set_effect(who, EFFECT_CHAR_FAINT, 3); // 小心准备 me
					CHAR_CHAR_D->init_loop_perform(who);
					if (get_heart_state(who) == MAGIC_STAT)
						send_user(user, "%c%d%d%c", 0x40, getoid(who), time2(), MAGIC_ACT_END); // 结束施法动作
					send_user(who, "%c%w%w%c", 0x81, 9002, get_effect_3(who, EFFECT_CHAR_FAINT), EFFECT_BAD);
					send_user(user - ({who}), "%c%d%w%c%c", 0x83, getoid(who), 9002, 1, EFFECT_BAD);
					send_user(user, "%c%d%w%c%c%c", 0x6f, getoid(who), 9002, 10, OVER_BODY, PF_LOOP);
					//	return 0;
				}
				else if (random100() < 15 && (-who->get("pf.armorfall")) < 320)
				{
					set_effect(who, EFFECT_CHAR_ARMORFALL, 120);
					send_user(who, "%c%w%w%c", 0x81, 4143, get_effect_3(who, EFFECT_CHAR_ARMORFALL), EFFECT_BAD);
					send_user(get_scene_object_2(who, USER_TYPE) - ({who}), "%c%d%w%c%c", 0x83, getoid(who), 4143, 1, EFFECT_BAD);
					if (who->is_user())
					{
						who->set("pf.armorfall", -320);
						who->set("pf.armorfall2", -85);
						who->set_save_2("pf.armorfall", -320);
						who->set_save_2("pf.armorfall2", -85);
						USER_ENERGY_D->count_pp(who);
						USER_ENERGY_D->count_dp(who);
					}
					else
					{
						who->add_dp(who->set("pf.armorfall", -320));
						who->add_pp(who->set("pf.armorfall2", -85));
					}
					//	return 0;
				}
			}
			else if (item->is_thanbinh5())
			{
				if (random100() < 10 && (-who->get("pf.armorfall")) < 300)
				{
					set_effect(who, EFFECT_CHAR_ARMORFALL, 30);
					send_user(who, "%c%w%w%c", 0x81, 4143, get_effect_3(who, EFFECT_CHAR_ARMORFALL), EFFECT_BAD);
					send_user(get_scene_object_2(who, USER_TYPE) - ({who}), "%c%d%w%c%c", 0x83, getoid(who), 4143, 1, EFFECT_BAD);
					if (who->is_user())
					{
						who->set("pf.armorfall", -300);
						who->set("pf.armorfall2", -85);
						who->set_save_2("pf.armorfall", -300);
						who->set_save_2("pf.armorfall2", -85);
						USER_ENERGY_D->count_pp(who);
						USER_ENERGY_D->count_dp(who);
					}
					else
					{
						who->add_dp(who->set("pf.armorfall", -300));
						who->add_pp(who->set("pf.armorfall2", -85));
					}
				}
				else if (random100() < 20)
				{
					if (get_effect(who, EFFECT_CHAR_FAINT))
						return 0;
					if (get_effect(who, EFFECT_CHAR_FAINT_0))
						return 0;
					if (who->is_anti_effect())
						return 0;
					if (who->get("anti_faint"))
						return 0;
					if (who->get_perform("02222#"))
						return 0;

					user = get_scene_object_2(who, USER_TYPE);
					set_effect(who, EFFECT_CHAR_FAINT, 3); // 小心准备 me
					CHAR_CHAR_D->init_loop_perform(who);
					if (get_heart_state(who) == MAGIC_STAT)
						send_user(user, "%c%d%d%c", 0x40, getoid(who), time2(), MAGIC_ACT_END); // 结束施法动作
					send_user(who, "%c%w%w%c", 0x81, 9002, get_effect_3(who, EFFECT_CHAR_FAINT), EFFECT_BAD);
					send_user(user - ({who}), "%c%d%w%c%c", 0x83, getoid(who), 9002, 1, EFFECT_BAD);
					send_user(user, "%c%d%w%c%c%c", 0x6f, getoid(who), 9002, 10, OVER_BODY, PF_LOOP);
				}
			}
			else if (item->is_thanbinh3() && random100() < 20 && (-who->get("pf.armorfall")) < 300)
			{
				set_effect(who, EFFECT_CHAR_ARMORFALL, 30);
				send_user(who, "%c%w%w%c", 0x81, 4143, get_effect_3(who, EFFECT_CHAR_ARMORFALL), EFFECT_BAD);
				send_user(get_scene_object_2(who, USER_TYPE) - ({who}), "%c%d%w%c%c", 0x83, getoid(who), 4143, 1, EFFECT_BAD);
				if (who->is_user())
				{
					who->set("pf.armorfall", -500);
					who->set("pf.armorfall2", -500);
					who->set_save_2("pf.armorfall", -500);
					who->set_save_2("pf.armorfall2", -500);
					USER_ENERGY_D->count_pp(who);
					USER_ENERGY_D->count_dp(who);
				}
				else
				{
					who->add_dp(who->set("pf.armorfall", -500));
					who->add_pp(who->set("pf.armorfall2", -500));
				}
			}
			else if (item->is_thanbinh1())
			{
				if (random100() < 10 && (-who->get("pf.armorfall")) < 300)
				{
					set_effect(who, EFFECT_CHAR_ARMORFALL, 30);
					send_user(who, "%c%w%w%c", 0x81, 4143, get_effect_3(who, EFFECT_CHAR_ARMORFALL), EFFECT_BAD);
					send_user(get_scene_object_2(who, USER_TYPE) - ({who}), "%c%d%w%c%c", 0x83, getoid(who), 4143, 1, EFFECT_BAD);
					if (who->is_user())
					{
						who->set("pf.armorfall", -300);
						who->set("pf.armorfall2", -85);
						who->set_save_2("pf.armorfall", -300);
						who->set_save_2("pf.armorfall2", -85);
						USER_ENERGY_D->count_pp(who);
						USER_ENERGY_D->count_dp(who);
					}
					else
					{
						who->add_dp(who->set("pf.armorfall", -300));
						who->add_pp(who->set("pf.armorfall2", -85));
					}
				}
				else if (random100() < 20)
				{
					if (get_effect(who, EFFECT_CHAR_FAINT))
						return 0;
					if (get_effect(who, EFFECT_CHAR_FAINT_0))
						return 0;
					if (who->is_anti_effect())
						return 0;
					if (who->get("anti_faint"))
						return 0;
					if (who->get_perform("02222#"))
						return 0;

					user = get_scene_object_2(who, USER_TYPE);
					set_effect(who, EFFECT_CHAR_FAINT, 3);
					CHAR_CHAR_D->init_loop_perform(who);
					if (get_heart_state(who) == MAGIC_STAT)
						send_user(user, "%c%d%d%c", 0x40, getoid(who), time2(), MAGIC_ACT_END); // 结束施法动作
					send_user(who, "%c%w%w%c", 0x81, 9002, get_effect_3(who, EFFECT_CHAR_FAINT), EFFECT_BAD);
					send_user(user - ({who}), "%c%d%w%c%c", 0x83, getoid(who), 9002, 1, EFFECT_BAD);
					send_user(user, "%c%d%w%c%c%c", 0x6f, getoid(who), 9002, 10, OVER_BODY, PF_LOOP);
					//	return 0;
				}
			}
			else if (item->get_name() == "Ngọc La Quyền Thủ" && random100() < 20 &&
					 !get_effect(who, EFFECT_CHAR_FAINT) && !get_effect(who, EFFECT_CHAR_FAINT_0) &&
					 !who->is_anti_effect() && !who->get("anti_faint") && !who->get_perform("02222#"))
			{
				user = get_scene_object_2(who, USER_TYPE);
				set_effect(who, EFFECT_CHAR_FAINT, 2); // 小心准备 me
				CHAR_CHAR_D->init_loop_perform(who);
				if (get_heart_state(who) == MAGIC_STAT)
					send_user(user, "%c%d%d%c", 0x40, getoid(who), time2(), MAGIC_ACT_END); // 结束施法动作
				send_user(who, "%c%w%w%c", 0x81, 9002, get_effect_3(who, EFFECT_CHAR_FAINT), EFFECT_BAD);
				send_user(user - ({who}), "%c%d%w%c%c", 0x83, getoid(who), 9002, 1, EFFECT_BAD);
				send_user(user, "%c%d%w%c%c%c", 0x6f, getoid(who), 9002, 10, OVER_BODY, PF_LOOP);
			}
			else if (item->get_name() == "Càn Khôn Vô Cấp Côn" && random100() < 20 &&
					 !get_effect(who, EFFECT_CHAR_FAINT) && !get_effect(who, EFFECT_CHAR_FAINT_0) &&
					 !who->is_anti_effect() && !who->get("anti_faint") && !who->get_perform("02222#"))
			{
				user = get_scene_object_2(who, USER_TYPE);
				set_effect(who, EFFECT_CHAR_FAINT, 2); // 小心准备 me
				CHAR_CHAR_D->init_loop_perform(who);
				if (get_heart_state(who) == MAGIC_STAT)
					send_user(user, "%c%d%d%c", 0x40, getoid(who), time2(), MAGIC_ACT_END); // 结束施法动作
				send_user(who, "%c%w%w%c", 0x81, 9002, get_effect_3(who, EFFECT_CHAR_FAINT), EFFECT_BAD);
				send_user(user - ({who}), "%c%d%w%c%c", 0x83, getoid(who), 9002, 1, EFFECT_BAD);
				send_user(user, "%c%d%w%c%c%c", 0x6f, getoid(who), 9002, 10, OVER_BODY, PF_LOOP);
			}
			else if (item->get_name() == "Phàn Thiên Côn" && random100() < 20 &&
					 !get_effect(who, EFFECT_CHAR_FAINT) && !get_effect(who, EFFECT_CHAR_FAINT_0) &&
					 !who->is_anti_effect() && !who->get("anti_faint") && !who->get_perform("02222#"))
			{
				user = get_scene_object_2(who, USER_TYPE);
				set_effect(who, EFFECT_CHAR_FAINT, 2); // 小心准备 me
				CHAR_CHAR_D->init_loop_perform(who);
				if (get_heart_state(who) == MAGIC_STAT)
					send_user(user, "%c%d%d%c", 0x40, getoid(who), time2(), MAGIC_ACT_END); // 结束施法动作
				send_user(who, "%c%w%w%c", 0x81, 9002, get_effect_3(who, EFFECT_CHAR_FAINT), EFFECT_BAD);
				send_user(user - ({who}), "%c%d%w%c%c", 0x83, getoid(who), 9002, 1, EFFECT_BAD);
				send_user(user, "%c%d%w%c%c%c", 0x6f, getoid(who), 9002, 10, OVER_BODY, PF_LOOP);
			}
		}
		if (me->is_nianshou())
			damage = random(who->get_level() / 2) + who->get_level() / 2;
		if (who->is_nianshou())
			damage = 1;

		// 显示少血效果
		if (who->is_npc())
			owner = who->get_owner();
		else
			owner = who;
		if (owner)
		{
			if (double_flag == 0)
				send_user(owner, "%c%d%w%c%d%w%c", 0x48, getoid(who), damage, get_d(who), getoid(me),
						  hit_act, hit_act == HIT_NORMAL ? 2 : 1);
			else
				send_user(owner, "%c%d%w%c%d%w%c", 0x4a, getoid(who), damage, get_d(who), getoid(me),
						  hit_act, hit_act == HIT_NORMAL ? 2 : 1);
		}
		if (me->is_user())
			owner = me;
		else
			owner = me->get_owner();
		if (owner)
		{
			if (double_flag == 0)
				send_user(owner, "%c%d%w%c%d%w%c", 0x48, getoid(who), damage, get_d(who), getoid(me),
						  hit_act, hit_act == HIT_NORMAL ? 2 : 1);
			else
				send_user(owner, "%c%d%w%c%d%w%c", 0x4a, getoid(who), damage, get_d(who), getoid(me),
						  hit_act, hit_act == HIT_NORMAL ? 2 : 1);
		}

		if (point = me->get_absorb_hp() && me->get_weapon_code() != SWORD && me->get_weapon_code() != THROWING) // 吸取气血
		{
			point = range_value(damage * point / 100, 0, 10000);
			send_user(get_scene_object_2(me, USER_TYPE), "%c%d%w", 0x68, getoid(me), -point);
			me->add_hp(point);
		}

		if (me->is_user())
		{
			if (objectp(item = me->get_equip(WEAPON_TYPE)) && item->get_lasting() >= 100) // 武器 & 耐久度
			{
				if (((poison = item->get_poison()) && time() < item->get("poison_time")) && !get_effect(who, EFFECT_CHAR_POISON) && !get_effect(who, EFFECT_CHAR_9140) // 辟毒散
					&& random(100) < 40 && random(100) > who->get_anti_poison())
				{
					poison += me->get_2("suit_effect.poison"); // 套装
					who->set_poison(poison / 10);
					set_effect_2(who, EFFECT_CHAR_POISON, 20, 0);
					send_user(who, "%c%w%w%c", 0x81, 9096, get_effect_3(who, EFFECT_CHAR_POISON), EFFECT_BAD);
					send_user(get_scene_object_2(who, USER_TYPE) - ({who}), "%c%d%w%c%c", 0x83, getoid(who), 9096, 1, EFFECT_BAD);
				}
				item->add_lasting(-1); // 击中减少耐久
			}

			if (!get_effect(me, EFFECT_CHAR_SUPPRESS)		// 没有压制
				&& objectp(item = me->get_equip(HAND_TYPE)) // 法宝
				&& item->get_talisman_type() == 3			// 摄魂铃
				&& item->get_lasting() >= 100				// 耐久度
				&& random(100) < item->get_active_rate())	// 成功率
			{
				if (!get_effect(who, EFFECT_CHAR_FAINT) && !get_effect(who, EFFECT_CHAR_FAINT_0) && !get_effect(who, EFFECT_CHAR_9145))
				{
					user = get_scene_object_2(who, USER_TYPE);
					set_effect(who, EFFECT_CHAR_FAINT, 3);
					send_user(who, "%c%w%w%c", 0x81, 9002, get_effect_3(who, EFFECT_CHAR_FAINT), EFFECT_BAD);
					send_user(user - ({who}), "%c%d%w%c%c", 0x83, getoid(who), 9002, 1, EFFECT_BAD);
					send_user(user, "%c%d%w%c%c%c", 0x6f, getoid(who), 9002, 10, OVER_BODY, PF_LOOP);
				}
				item->add_lasting(-1); // 使用减少耐久
			}
			if (me->get_fam_name() == "Côn Luân" && me->get_weapon_code() == BLADE)
			{
				cap = me->get_skill(0426);
				tyle = cap * 10 / 100;
				if (tyle > 1)
				{
					if (random(100) < tyle)
					{
						if (!get_effect(who, EFFECT_CHAR_FAINT) && !get_effect(who, EFFECT_CHAR_FAINT_0) && !who->get_perform("02222#") && !get_effect(who, EFFECT_CHAR_9145))
						{
							user = get_scene_object_2(who, USER_TYPE);
							set_effect(who, EFFECT_CHAR_FAINT, 2);
							send_user(who, "%c%w%w%c", 0x81, 9002, get_effect_3(who, EFFECT_CHAR_FAINT), EFFECT_BAD);
							send_user(user - ({who}), "%c%d%w%c%c", 0x83, getoid(who), 9002, 1, EFFECT_BAD);
							send_user(user, "%c%d%w%c%c%c", 0x6f, getoid(who), 9002, 10, OVER_BODY, PF_LOOP);
						}
					}
				}
			}

			if (point = me->get_absorb_mp()) // 吸取法力
			{
				point = range_value(who->get_hp(), 0, damage) * point / 100;
				point = range_value(point, 0, who->get_mp());
				who->add_mp(-point);
				me->add_mp(point);
			}
		}
		else // NPC 带毒攻击
		{
			if ((poison = me->get("@")) && !get_effect(who, EFFECT_CHAR_POISON) && !get_effect(who, EFFECT_CHAR_9140) // 辟毒散
				&& random(100) < 15 && random(100) > who->get_anti_poison())
			{
				who->set_poison(poison / 10);
				set_effect_2(who, EFFECT_CHAR_POISON, 20, 0);
				send_user(who, "%c%w%w%c", 0x81, 9096, get_effect_3(who, EFFECT_CHAR_POISON), EFFECT_BAD);
				send_user(get_scene_object_2(who, USER_TYPE) - ({who}), "%c%d%w%c%c", 0x83, getoid(who), 9096, 1, EFFECT_BAD);
			}
		}

		if (who->is_user())
		{
			wear_down(who); // 击中减少耐久
			// 被打中一些持续效果中断
			CHAR_CHAR_D->stop_loop_perform_be_attack(who);
		}
		else if (get_effect(who, EFFECT_SLEEP))
			set_effect(who, EFFECT_SLEEP, 1); // 昏迷

		if (get_effect(who, EFFECT_CHAR_ATTACK)									 // 顺势推舟
			&& !who->get_enemy_5()												 // 还没反击对象
			&& me->can_be_fighted(who) && who->can_fight(me) && random(100) < 30 // 30% 成功率
			&& who->get_mp() >= PF_FILE_02321->get_sub_mp_2(who))				 // 扣减法力
		{
			who->set_enemy_5(me); // Thiết lập 反击对象

			if (!who->get_enemy()) // 没有敌手
			{
				who->start_fight(me);
				who->to_front_xy(get_x(me), get_y(me));
			}
		}
		if ((level = me->get_skill(SKILL_0317)) >= 1 || (level = me->get_skill(SKILL_0348)) >= 1) // 护体金罡－集气
		{
			point = me->add_damage_count(damage);
			yuan = me->get_yuan();

			if (point >= yuan * 40 + 60 * (300 - level) / 100)
			{
				me->set_damage_count(0);
				if (me->add_yuan(1) != yuan)
					send_user(me, "%c%d%w%c%c%c", 0x6f, getoid(me), 31711, 1, OVER_BODY, PF_ONCE);
			}
		}
		// 判断死亡条件
		// 灵魂枷锁
		if (who->is_user() && (pet = who->get("showbeast")) && get_effect_3(pet, EFFECT_CHAR_SOUL_LOCK) && inside_screen_2(pet, who))
		{
			send_user(get_scene_object_2(pet, USER_TYPE), "%c%d%w", 0x68, getoid(pet), damage * 2);
			CHAR_DIE_D->is_enemy_die(me, pet, damage * 2);
			return;
		}
		else if (who->is_npc() && get_effect_3(who, EFFECT_CHAR_SOUL_LOCK) && (owner = who->get_owner()) && owner && inside_screen_2(owner, who))
		{
			send_user(get_scene_object_2(owner, USER_TYPE), "%c%d%w", 0x68, getoid(owner), damage / 2);
			CHAR_DIE_D->is_enemy_die(me, owner, damage / 2);
			return;
		}
		else
			CHAR_DIE_D->is_enemy_die(me, who, damage); // 减血
		if (objectp(me) && objectp(who) && me->get_hp() < 1)
			CHAR_DIE_D->is_enemy_die(who, me, 0);
		if (me && me->is_npc() && who)
			me->do_after_attack(who);
		// 护体金罡的反弹伤害

		if (who && me && get_effect(who, EFFECT_REBOUND))
		{

			if (who->is_npc())
			{
				if (me->is_user())
				{
					damage = me->get_ap() * who->get("03173#") / 130;
					owner = who->get_owner();
				}
				else if (me->is_zombie())
				{
					damage = me->get_ap() * who->get("03173#") / 130;
					owner = who->get_owner();
				}
				else if (me->is_pet())
				{
					damage = me->get_ap() * who->get("03173#") / 130;
					owner = who->get_owner();
				}
				else
				{
					damage = 30;
					owner = who->get_owner();
				}
			}
			else
			{
				if (me->is_user())
				{
					damage = me->get_ap() * (who->get_save("03173#") / 100) + who->get_dp() * who->get_save("03173#") / 100;
					if (me->get_fam_name() == "Đường Môn" ||
						me->get_fam_name() == "Vân Mộng Cốc" ||
						me->get_fam_name() == "Mao Sơn" ||
						me->get_fam_name() == "Côn Luân")
					{
						damage /= 2;
					}
					owner = who;
				}

				else if (me->is_zombie())
				{
					damage = me->get_ap() * who->get_save("03173#") / 130;
					owner = who;
				}
				else if (me->is_pet())
				{
					damage = me->get_ap() * who->get_save("03173#") / 130;
					owner = who;
				}
				else
				{
					damage = 30;
					owner = who;
				}
			}
			if (me->is_nianshou())
				damage = 0;
			if (owner)
				send_user(owner, "%c%d%w%c%d%w%c", 0x48, getoid(me), damage, get_d(who), getoid(me),
						  hit_act, hit_act == HIT_NORMAL ? 2 : 1);
			if (me->is_user())
				owner = me;
			else
				owner = me->get_owner();
			if (owner)
				send_user(owner, "%c%d%w%c%d%w%c", 0x48, getoid(me), damage, get_d(who), getoid(me),
						  hit_act, hit_act == HIT_NORMAL ? 2 : 1);
			CHAR_DIE_D->is_enemy_die(who, me, damage);
			if (objectp(me) && objectp(who) && me->get_hp() < 1)
				CHAR_DIE_D->is_enemy_die(who, me, 0);
		}

		if (me && !me->is_die() && who && !who->is_die() && who->get("sk74126") && random(100) < 10 && !get_effect_3(me, EFFECT_CHAR_DREAM)) // 攻击方被梦游
		{
			set_effect_2(me, EFFECT_CHAR_DREAM, 3, 2);
			send_user(me, "%c%w%w%c", 0x81, 9016, get_effect_3(me, EFFECT_CHAR_DREAM), EFFECT_BAD);
			send_user(get_scene_object_2(me, USER_TYPE), "%c%d%w%c%c%c", 0x6f, getoid(me), 53112, 1, OVER_BODY, PF_LOOP);
			send_user(get_scene_object_2(me, USER_TYPE) - ({me}), "%c%d%w%c%c", 0x83, getoid(me), 9016, 1, EFFECT_BAD);
			CHAR_CHAR_D->init_loop_perform(me);
		}
	}
	else
	{
		// if (is_god(me)) tell_user(me, "R %s Tấn công-> %s, Độ chính xác: %d random %d Thất Bại", me->get_name(), who->get_name(), rate, random);
		// if (is_god(who)) tell_user(who, "R %s Tấn công-> %s, Độ chính xác: %d random %d Thất Bại", me->get_name(), who->get_name(), rate, random);

		// 显示躲闪效果
		id = getoid(who);
		if (who->is_npc())
			owner = who->get_owner();
		else
			owner = who;
		if (owner)
			send_user(owner, "%c%d", 0x44, id);
		if (me->is_user())
			owner = me;
		else
			owner = me->get_owner();
		if (owner)
			send_user(owner, "%c%d", 0x44, id);
		return 0;
	}

	return damage;
}

// Giam bao ho
//  Chức năng: ẩn điều trị tấn công vũ khí
// Am khi --- co ngu hanh
varargs int throwing_done(object me, object who, int hit_act, int add_ap, int hit_rate, int damage_rate)
{
	object *user, item, item1, item2, item3, item4, item5, item6, item7, owner, pet, map, nguoichoi, nguoichoi1, nguoichoi2, nguoichoi3, ai;
	int ap, ap0, ap2, dp, dp0, dp2, asp, dsp;
	int rate, damage, poison, point, double_flag, p;
	int z, x0, y0, x1, y1, id, random, level, level2;
	int rate_nguhanh;

	// if( me->get_weapon_code() != THROWING ) return 0;

	if (!who || !who->can_be_fighted(me) || !me->can_fight(who))
		return 0;

	if ((is_gm2(who) || is_god(who) || is_gm3(who)) && CAN_KILL_GM == 0)
	{
		return 0;
	}

	map = get_map_object(get_z(me));
	if (me->is_user() && who->is_user() && (get_z(me) < 885 || map->is_org_map() || map->is_copy_scene() || map->is_pvp()))
	{
		if (me->is_user() && who->is_user() && me->get_attack_mode() != 1 && me->get_pk() < 100 && who->get_pk() < 100 && !get_effect(who, EFFECT_USER_PK))
		{
			me->set_char_type(PK_TYPE);
			set_effect(me, EFFECT_USER_PK, 180);
		}
		else if (me->is_user() && who->is_user() && me->get_attack_mode() != 1 && (me->get_pk() >= 100 || get_effect(who, EFFECT_USER_PK) || who->get_pk() >= 100))
		{
			set_effect(me, EFFECT_USER_PK, 0);
		}
	}
	if (me->is_user() && who->is_pet() && (get_z(me) < 885 || map->is_org_map() || map->is_copy_scene() || map->is_pvp()))
	{
		nguoichoi1 = who->get_owner();
		if (me->is_user() && who->is_pet() && nguoichoi1->is_user() && me->get_attack_mode() != 1 && me->get_pk() < 100 && nguoichoi1->get_pk() < 100 && !get_effect(nguoichoi1, EFFECT_USER_PK))
		{
			me->set_char_type(PK_TYPE); // 主动ＰＫ状态
			set_effect(me, EFFECT_USER_PK, 180);
		}
		else if (me->is_user() && who->is_pet() && nguoichoi1->is_user() && me->get_attack_mode() != 1 && (me->get_pk() >= 100 || get_effect(nguoichoi1, EFFECT_USER_PK) || nguoichoi1->get_pk() >= 100))
		{
			set_effect(me, EFFECT_USER_PK, 0);
		}
	}
	/*if ( me->is_user() && who->is_zombie() && ( get_z(me)<885 || map->is_org_map() || map->is_copy_scene() || map->is_pvp() ) )
	{
	nguoichoi2 = who->get_owner();
	if ( me->is_user() &&  who->is_zombie() && nguoichoi2->is_user() && me->get_attack_mode()!=1 && me->get_pk()<100 && nguoichoi2->get_pk()<100 && !get_effect(nguoichoi2, EFFECT_USER_PK)  )
	{
	me->set_char_type( PK_TYPE );    // 主动ＰＫ状态
	set_effect(me, EFFECT_USER_PK, 180);
	}
	else if ( me->is_user() && who->is_zombie() && nguoichoi2->is_user() && me->get_attack_mode()!=1 && (me->get_pk()>=100||get_effect(nguoichoi2, EFFECT_USER_PK)||nguoichoi2->get_pk()>=100) )
	{
	set_effect(me, EFFECT_USER_PK, 0);
	}
	}*/
	if (me->is_pet() && who->is_user() && (get_z(me) < 885 || map->is_org_map() || map->is_copy_scene() || map->is_pvp()))
	{
		nguoichoi = me->get_owner();
		if (me->is_pet() && nguoichoi->is_user() && who->is_user() && nguoichoi->get_attack_mode() != 1 && nguoichoi->get_pk() < 100 && who->get_pk() < 100 && !get_effect(who, EFFECT_USER_PK))
		{
			nguoichoi->set_char_type(PK_TYPE); // 主动ＰＫ状态
			set_effect(nguoichoi, EFFECT_USER_PK, 180);
		}
		else if (me->is_pet() && nguoichoi->is_user() && who->is_user() && nguoichoi->get_attack_mode() != 1 && (nguoichoi->get_pk() >= 100 || get_effect(who, EFFECT_USER_PK) || who->get_pk() >= 100))
		{
			set_effect(nguoichoi, EFFECT_USER_PK, 0);
		}
	}
	if (me->is_zombie() && who->is_user() && (get_z(me) < 885 || map->is_org_map() || map->is_copy_scene() || map->is_pvp()))
	{
		nguoichoi3 = me->get_owner();
		if (me->is_zombie() && nguoichoi3->is_user() && who->is_user() && nguoichoi3->get_attack_mode() != 1 && nguoichoi3->get_pk() < 100 && who->get_pk() < 100 && !get_effect(who, EFFECT_USER_PK))
		{
			nguoichoi3->set_char_type(PK_TYPE); // 主动ＰＫ状态
			set_effect(nguoichoi3, EFFECT_USER_PK, 180);
		}
		else if (me->is_zombie() && nguoichoi3->is_user() && who->is_user() && nguoichoi3->get_attack_mode() != 1 && (nguoichoi3->get_pk() >= 100 || get_effect(who, EFFECT_USER_PK) || who->get_pk() >= 100))
		{
			set_effect(nguoichoi3, EFFECT_USER_PK, 0);
		}
	}
	/*if ( me->is_zombie() && who->is_user() && (get_z(me)==001||get_z(me)==289||get_z(me)==269||get_z(me)==273||get_z(me)==165||get_z(me)==324||get_z(me)==054||get_z(me)==080) )
	{
	me->set_hp(0);
	me->set_die(1);
	}*/
	z = get_z(me);
	x0 = get_x(me);
	y0 = get_y(me);
	x1 = get_x(who);
	y1 = get_y(who);

	if (!inside_screen_2(me, who))
		return 0;
	if (!from_to(z, x0, y0, x1 - x0, y1 - y0, MAP_BLOCK))
		return 0;

	// 记录伤害对手

	if (who->is_npc())
	{
		if (who->get_enemy_4() == me)
			who->set_attack_time(time());
		else if (gone_time(who->get_attack_time()) > 12)
		{
			who->set_enemy_4(me);
			who->set_attack_time(time());
		}
		if (!who->get_max_damage())
			who->init_enemy_damage(me, 0);
	}

	//      me->set_enemy(who);
	item = me->get_equip(WEAPON_TYPE);

	asp = me->get_sp();
	dsp = who->get_sp();

	level2 = who->get_level();
	level = me->get_level();

	rate = 100 - dsp * 100 / (level2 * 90 + 700);

	if (level < level2 && !me->is_comrade() && !who->is_comrade())
		rate = rate * (level + 10) / (level2 + 10);

	rate = range_value(rate, 5, 100);

	rate += me->get_hit_rate_3() - who->get_dodge_rate() - who->get_2("suit_effect.dodge") + hit_rate;

	if (get_effect(me, EFFECT_CHAR_BLIND))
		rate /= 2;
	if (get_effect(who, EFFECT_DODGE))
		rate -= 20;
	if (get_effect(who, EFFECT_MAGIC_4243))
		rate -= 50;
	if (get_effect(who, EFFECT_CHAR_MOVE))
		rate -= who->get_save("03641");
	if (rate < 1000)
		rate = range_value(rate, 5, 100);

	// Tang chinh xac khi co ngu hanh
	/*
	if (me->get_2("nguhanh_rate") > 0) {
		rate += me->get_2("nguhanh_rate");
	}
	*/

	if (random(100) < rate)
	{
		if (who->is_trainer())
		{
			who->beat(me);
			return 1;
		}
		// 计算 damage
		// 瞬步法 回避一次攻击
		if (get_effect(who, EFFECT_03642))
		{
			"/skill/03/03642"->into_effect(who);
			set_effect(who, EFFECT_03642, 0);
			return 0;
		}
		// 计算 ap, dp

		ap = me->get_ap();
		ap0 = me->get_ap_0();

		ap += add_ap;
		ap0 += add_ap; // 特殊技附加攻击

		dp = who->get_dp();
		dp0 = who->get_dp_0();

		damage = me->get_lucky();

		ap2 = ap0 + (ap - ap0) * damage / 100 + random((ap - ap0) * (100 - damage) / 100);
		dp2 = dp0 + (dp - dp0) * damage / 100 + random((dp - dp0) * (100 - damage) / 100);
		/*
		if( me->is_comrade() || who->is_comrade() )    // 战场战友
		{
		damage = ( ap2 - ap2 * dp2 / (40 + dp2) );    // 25 / 1000
		}
		else
		*/
		{
			damage = (ap2 * 20 + dp2 * 49) / 50;
			damage = ap2 - ap2 * dp2 / range_value(damage, 1, MAX_NUMBER);
		}

		if (!me->is_comrade() && !who->is_comrade())
			damage = damage * (level + 10) / (level2 + 10);
		damage = correct_damage(me, who, range_value(damage, 1, ap2), ap); // 暗器 AP 不修正

		/*		if (p = me->get_skill(0437))
		{
		damage = damage * (100+p*2)/100;		// 帮派的法伤强化
		}*/
		if (p = me->get_skill(0430))
		{
			damage = damage * (100 + p * 2) / 100;
		}

		damage += damage * damage_rate / 100;

		damage += damage * me->get_save("03162#") / 100;
		if (me->is_zombie() && who->is_user() && (get_z(me) == 001 || get_z(me) == 289 || get_z(me) == 269 || get_z(me) == 273 || get_z(me) == 165 || get_z(me) == 324 || get_z(me) == 054 || get_z(me) == 080))
		{
			damage = 1;
			me->set_hp(0);
			me->set_die(1);
		}

		rate = me->get_double_rate();
		random = random(10000);

		// double damage
		if (random < rate)
		{
			damage = damage * 2;

			if ((rate = who->get_2("suit_effect.double1")) && (p = who->get_2("suit_effect.double2")))
			{
				double_flag = random(p);
				if (double_flag < rate)
				{
					double_flag = rate;
				}

				damage = (damage / 2) + ((damage / 2) * (100 - double_flag) / 100);
			}

			double_flag = 1;

			// pet hoa su
			// 50% độc log tiễn tăng thương
			if (random(100) <= 50)
			{
				if (objectp(item = me->get_equip(WEAPON_TYPE)))
				{
					if (item->is_thanbinh2())
					{
						damage = damage + (damage * 25 / 1000);
						send_user(get_scene_object_2(who, USER_TYPE), "%c%d%w%c%c%c", 0x6f, getoid(who), 26151, 1, OVER_BODY, PF_ONCE);
					}
				}
			}

			// Tang bao kich
			if (me->get_2("jiguan.addRateDouble") > 0 && random(100) <= me->get_2("jiguan.addRateDouble"))
			{
				if (me->get_2("jiguan.addDouble"))
				{
					damage = damage + (damage * me->get_2("jiguan.addDouble") / 100);
				}
			}

			// Giam bao kich
			if (who->get_2("jiguan.subRateDouble") > 0 && random(100) <= who->get_2("jiguan.subRateDouble"))
			{
				if (who->get_2("jiguan.subDouble"))
				{
					damage = damage * who->get_2("jiguan.subDouble") / 100;
				}
			}
		}

		damage += me->get("add_damage");

		// Bảo hộ-xạ kích
		if (p = who->get_skill(0438))
		{
			damage = damage * (100 - p * 2) / 100;
		}

		if (p = who->get_skill(0431))
		{
			damage = damage * (100 - p * 2) / 100; // 帮派的法防强化
		}

		if (who->get_perform("05016#"))
			damage = damage * 4 / 5;

		/*ngu hanh*/
		if (NGU_HANH->is_nguhanh(me) == 1 && NGU_HANH->is_nguhanh(who) == 0)
		{
			damage += damage * 150 / 1000;
			if (is_god(me))
			{
				tell_user(me, ECHO "Giá trị ngũ hành: %d%%", 15);
			}
		}
		if (NGU_HANH->is_nguhanh(who) == 1 && NGU_HANH->is_nguhanh(me) == 0)
		{
			damage = damage * 750 / 1000;
			if (is_god(me))
			{
				tell_user(me, ECHO "Giá trị ngũ hành: %d%%", -15);
			}
		}

		if (NGU_HANH->counting_nguhanh_rate(me, who) != 0 && NGU_HANH->is_nguhanh(me) == 1 && NGU_HANH->is_nguhanh(who) == 1)
		{
			rate_nguhanh = NGU_HANH->counting_nguhanh_rate(me, who);
			me->set_2("nguhanh_rate", rate_nguhanh);
			damage += damage * rate_nguhanh * 10 / 1000;

			if (is_god(me))
			{
				tell_user(me, HIG "Giá trị ngũ hành tăng: %d%%", rate_nguhanh);
			}
		}
		/*ngu hanh*/

		// debug độc long tiễn

		// if (is_god(me)) tell_user(me, "r %s Phóng ám khí-> %s , Độ chính xác: %d - AP: %d - DP: %d = Thương: %d ", me->get_name(), who->get_name(), rate, ap2, dp2, damage);
		// if (is_god(who)) tell_user(who, "r %s Phóng ám khí-> %s , Độ chính xác: %d - AP: %d - DP: %d = Thương: %d ", me->get_name(), who->get_name(), rate, ap2, dp2, damage);

		damage = damage * (100 - who->get_2("suit_effect.damage_rate3")) / 100;
		if (damage < 1)
			damage = 1;
		if (get_effect(me, EFFECT_CHAR_POWERFALL))
		{
			if (me->is_user())
				damage = damage * (100 + me->get_save_2("pf.powerfall")) / 100;
			else
				damage = damage * (100 + me->get("pf.powerfall")) / 100;
			if (damage < 0)
				damage = 1;
		}
		if (get_effect(who, EFFECT_CHAR_MISS))
		{
			if (damage < who->get_save("pf.miss") && damage < who->get_mp())
			{
				who->add_mp(-damage);
				who->add_save("pf.miss", -damage);
				send_user(get_scene_object_2(who, USER_TYPE), "%c%d%w%c%c%c", 0x6f, getoid(who), 42515, 1, OVER_BODY, PF_ONCE);
				send_user(who, "%c%w%c", 0x82, 4252, 0);
				return 1;
			}
			else if (who->get_mp() > who->get_save("pf.miss"))
			{
				damage -= who->get_save("pf.miss");
				who->add_mp(-who->get_save("pf.miss"));
			}
			else
			{
				damage -= who->get_mp();
				who->set_mp(0);
			}
			"/sys/char/char"->effect_miss_done(who);
			set_effect(who, EFFECT_CHAR_MISS, 0);
		}
		if (get_effect(who, EFFECT_CHAR_MISS2))
		{
			send_user(get_scene_object_2(who, USER_TYPE), "%c%d%w%c%c%c", 0x6f, getoid(who), 42525, 1, OVER_BODY, PF_ONCE);
			if (who->is_user())
			{
				if (who->add_save("05911", -damage) < 0)
				{
					damage = -who->get_save("05911");
					set_effect(who, EFFECT_CHAR_MISS2, 1);
				}
				else
					return 1;
			}
			else
			{
				if (who->add("05911", -damage) < 0)
				{
					damage = -who->get("05911");
					set_effect(who, EFFECT_CHAR_MISS2, 1);
				}
				else
					return 1;
			}
		}
		else
		{

			// Linh Khi Ho The
			if (who->is_user() && objectp(item = who->get_equip(WEAPON_TYPE)) &&
				item->get_name() == "Anh Kiệt Quyền Nhẫn" && random100() < 10)
			{
				// who->set_save("05911", 630);
				set_effect(who, EFFECT_CHAR_MISS2, 30);
				send_user(who, "%c%w%w%c", 0x81, 5911, get_effect_3(who, EFFECT_CHAR_MISS2), EFFECT_GOOD);
				send_user(get_scene_object_2(who, USER_TYPE) - ({who}), "%c%d%w%c%c", 0x83, getoid(who), 5911, 1, EFFECT_GOOD);
				send_user(get_scene_object_2(who, USER_TYPE), "%c%d%w%c%c%c", 0x6f, getoid(who), 10711, 1, OVER_BODY, PF_LOOP);
			}
			if (who->is_user() && objectp(item = who->get_equip(WEAPON_TYPE)) &&
				item->is_thanbinh1() && random100() < 5)
			{
				// who->set_save("05911", 1500);
				// set_effect(who, EFFECT_CHAR_MISS2, 30);
				// send_user(who, "%c%w%w%c", 0x81, 5911, get_effect_3(who, EFFECT_CHAR_MISS2), EFFECT_GOOD);
				// send_user(get_scene_object_2(who, USER_TYPE) - ({ who }), "%c%d%w%c%c", 0x83, getoid(who), 5911, 1, EFFECT_GOOD);
				// send_user(get_scene_object_2(who, USER_TYPE), "%c%d%w%c%c%c", 0x6f, getoid(who), 10711, 1, OVER_BODY, PF_LOOP);
			}
		}
		if (me->is_user() && objectp(item = me->get_equip(WEAPON_TYPE)))
		{
			if (item->is_thanbinh2())
			{
				// if (random100() < 5)
				//{
				//	if (who->is_anti_effect()) return 0;
				//	if (who->get("anti_blind")) return 0;
				//	set_effect(who, EFFECT_CHAR_BLIND, 6);
				//	send_user(who, "%c%w%w%c", 0x81, 9024, 6, EFFECT_BAD);
				//	send_user(get_scene_object_2(who, USER_TYPE) - ({ who }), "%c%d%w%c%c", 0x83, getoid(who), 9024, 1, EFFECT_BAD);
				//	send_user(who, "%c%c%c", 0x3d, 243, 1);
				//	//	return 0;
				// }
				// else
				if (random100() < 10 && (-who->get("pf.armorfall")) < 100)
				{
					set_effect(who, EFFECT_CHAR_ARMORFALL, 30);
					send_user(who, "%c%w%w%c", 0x81, 4143, get_effect_3(who, EFFECT_CHAR_ARMORFALL), EFFECT_BAD);
					send_user(get_scene_object_2(who, USER_TYPE) - ({who}), "%c%d%w%c%c", 0x83, getoid(who), 4143, 1, EFFECT_BAD);
					if (who->is_user())
					{
						who->set("pf.armorfall", -100);
						who->set("pf.armorfall2", -85);
						who->set_save_2("pf.armorfall", -100);
						who->set_save_2("pf.armorfall2", -85);
						USER_ENERGY_D->count_pp(who);
						USER_ENERGY_D->count_dp(who);
					}
					else
					{
						who->add_dp(who->set("pf.armorfall", -100));
						who->add_pp(who->set("pf.armorfall2", -85));
					}
				}
			}
		}
		if (me->is_nianshou())
			damage = random(who->get_level() / 2) + who->get_level() / 2;
		if (who->is_nianshou())
			damage = 1;

		// 显示少血效果
		if (who->is_npc())
			owner = who->get_owner();
		else
			owner = who;
		if (owner)
		{
			if (double_flag == 0)
				send_user(owner, "%c%d%w%c%d%w%c", 0x48, getoid(who), damage, get_d(who), getoid(me),
						  hit_act, hit_act == HIT_NORMAL ? 2 : 1);
			else
				send_user(owner, "%c%d%w%c%d%w%c", 0x4a, getoid(who), damage, get_d(who), getoid(me),
						  hit_act, hit_act == HIT_NORMAL ? 2 : 1);
		}
		if (me->is_npc())
			owner = me->get_owner();
		else
			owner = me;
		if (owner)
		{
			if (double_flag == 0)
				send_user(owner, "%c%d%w%c%d%w%c", 0x48, getoid(who), damage, get_d(who), getoid(me),
						  hit_act, hit_act == HIT_NORMAL ? 2 : 1);
			else
				send_user(owner, "%c%d%w%c%d%w%c", 0x4a, getoid(who), damage, get_d(who), getoid(me),
						  hit_act, hit_act == HIT_NORMAL ? 2 : 1);
		}
		if (item && (poison = item->get_poison()) && random(100) < 15 && !get_effect(who, EFFECT_CHAR_POISON) && !get_effect(who, EFFECT_CHAR_9140)) // 辟毒散
		{
			poison += me->get_2("suit_effect.poison"); // 套装
			who->set_poison(poison / 10);
			set_effect_2(who, EFFECT_CHAR_POISON, 20, 0);
			send_user(who, "%c%w%w%c", 0x81, 9096, get_effect_3(who, EFFECT_CHAR_POISON), EFFECT_BAD);
			send_user(get_scene_object_2(who, USER_TYPE) - ({who}), "%c%d%w%c%c", 0x83, getoid(who), 9096, 1, EFFECT_BAD);
		}

		if (!get_effect(me, EFFECT_CHAR_SUPPRESS)		 // 没有压制
			&& objectp(item2 = me->get_equip(HAND_TYPE)) // 法宝
			&& item2->get_talisman_type() == 3			 // 摄魂铃
			&& item2->get_lasting() >= 100				 // 耐久度
			&& random(100) < item2->get_active_rate())	 // 成功率
		{
			if (!get_effect(who, EFFECT_CHAR_FAINT) && !get_effect(who, EFFECT_CHAR_FAINT_0) && !get_effect(who, EFFECT_CHAR_9145))
			{
				user = get_scene_object_2(who, USER_TYPE);
				set_effect(who, EFFECT_CHAR_FAINT, 3);
				send_user(who, "%c%w%w%c", 0x81, 9002, get_effect_3(who, EFFECT_CHAR_FAINT), EFFECT_BAD);
				send_user(user - ({who}), "%c%d%w%c%c", 0x83, getoid(who), 9002, 1, EFFECT_BAD);
				send_user(user, "%c%d%w%c%c%c", 0x6f, getoid(who), 9002, 10, OVER_BODY, PF_LOOP);
			}
			item2->add_lasting(-1); // 使用减少耐久
		}

		if (who->is_user())
		{
			wear_down(who);
			CHAR_CHAR_D->stop_loop_perform_be_attack(who);
		}
		else if (get_effect(who, EFFECT_SLEEP))
			set_effect(who, EFFECT_SLEEP, 1);

		if (who->is_user() && (pet = who->get("showbeast")) && get_effect_3(pet, EFFECT_CHAR_SOUL_LOCK) && inside_screen_2(pet, who))
		{
			send_user(get_scene_object_2(pet, USER_TYPE), "%c%d%w", 0x68, getoid(pet), damage * 2);
			CHAR_DIE_D->is_enemy_die(me, pet, damage * 2);
			return;
		}
		else if (who->is_npc() && get_effect_3(who, EFFECT_CHAR_SOUL_LOCK) && (owner = who->get_owner()) && owner && inside_screen_2(owner, who))
		{
			send_user(get_scene_object_2(owner, USER_TYPE), "%c%d%w", 0x68, getoid(owner), damage / 2);
			CHAR_DIE_D->is_enemy_die(me, owner, damage / 2);
			return;
		}
		else
			CHAR_DIE_D->is_enemy_die(me, who, damage);
		if (me && (me->get_hp() < 1))
			CHAR_DIE_D->is_enemy_die(who, me, 0);
		if (me && me->is_npc() && who)
			me->do_after_attack(who);

		if (who && me && get_effect(who, EFFECT_REBOUND))
		{
			if (who->is_npc())
			{
				if (me->is_user())
				{
					damage = me->get_ap() * who->get("03173#") / 120;
					owner = who->get_owner();
				}
				else if (me->is_zombie())
				{
					damage = me->get_ap() * who->get("03173#") / 120;
					owner = who->get_owner();
				}
				else if (me->is_pet())
				{
					damage = me->get_ap() * who->get("03173#") / 120;
					owner = who->get_owner();
				}
				else
				{
					damage = 0;
					owner = who->get_owner();
				}
			}
			else
			{
				if (me->is_user())
				{
					damage = me->get_cp() * (who->get_save("03173#") / 100) + who->get_dp() * who->get_save("03173#") / 100;
					if (me->get_fam_name() == "Đường Môn" ||
						me->get_fam_name() == "Vân Mộng Cốc" ||
						me->get_fam_name() == "Mao Sơn" ||
						me->get_fam_name() == "Côn Luân")
					{
						damage /= 2;
					}
					owner = who;
				}
				else if (me->is_zombie())
				{
					damage = me->get_ap() * who->get_save("03173#") / 120;
					owner = who;
				}
				else if (me->is_pet())
				{
					damage = me->get_ap() * who->get_save("03173#") / 120;
					owner = who;
				}
				else
				{
					damage = 30;
					owner = who;
				}
			}
			if (me->is_nianshou())
				damage = 0;
			if (owner)
				send_user(owner, "%c%d%w%c%d%w%c", 0x48, getoid(me), damage, get_d(who), getoid(me),
						  hit_act, hit_act == HIT_NORMAL ? 2 : 1);
			if (me->is_user())
				owner = me;
			else
				owner = me->get_owner();
			if (owner)
				send_user(owner, "%c%d%w%c%d%w%c", 0x48, getoid(me), damage, get_d(who), getoid(me),
						  hit_act, hit_act == HIT_NORMAL ? 2 : 1);
			CHAR_DIE_D->is_enemy_die(who, me, damage);
			if (objectp(me) && objectp(who) && me->get_hp() < 1)
				CHAR_DIE_D->is_enemy_die(who, me, 0);
		}
	}
	else
	{
		// debug rate
		// if (is_god(me)) tell_user(me, "r %s Phóng ám khí-> %s , Độ chính xác: %d Thất Bại", me->get_name(), who->get_name(), rate);
		// if (is_god(who)) tell_user(who, "r %s Phóng ám khí-> %s , Độ chính xác: %d Thất Bại", me->get_name(), who->get_name(), rate);

		// 显示躲闪效果
		id = getoid(who);
		if (who->is_npc())
			owner = who->get_owner();
		else
			owner = who;
		if (owner)
			send_user(owner, "%c%d", 0x44, id);
		if (me->is_user())
			owner = me;
		else
			owner = me->get_owner();
		if (owner)
			send_user(owner, "%c%d", 0x44, id);
		if (item)
			item->add_lasting(-1);
		return 0;
	}

	if (item)
		item->add_lasting(-1);

	return damage;
}

// Chức năng: điều trị tấn công ma thuật --- co ngu hanh
varargs int cast_done(object me, object who, int add_cp, int damage_rate, int sub_pp_rate)
{
	object *user, item, item1, item2, item3, item4, item5, item6, owner, pet, map, nguoichoi, nguoichoi1, nguoichoi2, nguoichoi3, ai;
	int cp, cp0, cp2, pp, pp0, pp2, asp, dsp, p;
	int rate, damage, id, double_flag, point, random, level, level2, hit_act;
	int rate_nguhanh;

	if (!who || !who->can_be_fighted(me) || !me->can_fight(who))
		return 0;

	if ((is_gm2(who) || is_god(who) || is_gm3(who)) && CAN_KILL_GM == 0)
	{
		return 0;
	}

	map = get_map_object(get_z(me));
	if (me->is_user() && who->is_user() && (get_z(me) < 885 || map->is_org_map() || map->is_copy_scene() || map->is_pvp()))
	{
		if (me->is_user() && who->is_user() && me->get_attack_mode() != 1 && me->get_pk() < 100 && who->get_pk() < 100 && !get_effect(who, EFFECT_USER_PK))
		{
			me->set_char_type(PK_TYPE);
			set_effect(me, EFFECT_USER_PK, 180);
		}
		else if (me->is_user() && who->is_user() && me->get_attack_mode() != 1 && (me->get_pk() >= 100 || get_effect(who, EFFECT_USER_PK) || who->get_pk() >= 100))
		{
			set_effect(me, EFFECT_USER_PK, 0);
		}
	}
	if (me->is_user() && who->is_pet() && (get_z(me) < 885 || map->is_org_map() || map->is_copy_scene() || map->is_pvp()))
	{
		nguoichoi1 = who->get_owner();
		if (me->is_user() && who->is_pet() && nguoichoi1->is_user() && me->get_attack_mode() != 1 && me->get_pk() < 100 && nguoichoi1->get_pk() < 100 && !get_effect(nguoichoi1, EFFECT_USER_PK))
		{
			me->set_char_type(PK_TYPE);
			set_effect(me, EFFECT_USER_PK, 180);
		}
		else if (me->is_user() && who->is_pet() && nguoichoi1->is_user() && me->get_attack_mode() != 1 && (me->get_pk() >= 100 || get_effect(nguoichoi1, EFFECT_USER_PK) || nguoichoi1->get_pk() >= 100))
		{
			set_effect(me, EFFECT_USER_PK, 0);
		}
	}
	/*if ( me->is_user() && who->is_zombie() && ( get_z(me)<885 || map->is_org_map() || map->is_copy_scene() || map->is_pvp() ) )
	{
	nguoichoi2 = who->get_owner();
	if ( me->is_user() &&  who->is_zombie() && nguoichoi2->is_user() && me->get_attack_mode()!=1 && me->get_pk()<100 && nguoichoi2->get_pk()<100 && !get_effect(nguoichoi2, EFFECT_USER_PK)  )
	{
	me->set_char_type( PK_TYPE );    // 主动ＰＫ状态
	set_effect(me, EFFECT_USER_PK, 180);
	}
	else if ( me->is_user() && who->is_zombie() && nguoichoi2->is_user() && me->get_attack_mode()!=1 && (me->get_pk()>=100||get_effect(nguoichoi2, EFFECT_USER_PK)||nguoichoi2->get_pk()>=100) )
	{
	set_effect(me, EFFECT_USER_PK, 0);
	}
	}*/
	if (me->is_pet() && who->is_user() && (get_z(me) < 885 || map->is_org_map() || map->is_copy_scene() || map->is_pvp()))
	{
		nguoichoi = me->get_owner();
		if (me->is_pet() && nguoichoi->is_user() && who->is_user() && nguoichoi->get_attack_mode() != 1 && nguoichoi->get_pk() < 100 && who->get_pk() < 100 && !get_effect(who, EFFECT_USER_PK))
		{
			nguoichoi->set_char_type(PK_TYPE);
			set_effect(nguoichoi, EFFECT_USER_PK, 180);
		}
		else if (me->is_pet() && nguoichoi->is_user() && who->is_user() && nguoichoi->get_attack_mode() != 1 && (nguoichoi->get_pk() >= 100 || get_effect(who, EFFECT_USER_PK) || who->get_pk() >= 100))
		{
			set_effect(nguoichoi, EFFECT_USER_PK, 0);
		}
	}
	if (me->is_zombie() && who->is_user() && (get_z(me) < 885 || map->is_org_map() || map->is_copy_scene() || map->is_pvp()))
	{
		nguoichoi3 = me->get_owner();
		if (me->is_zombie() && nguoichoi3->is_user() && who->is_user() && nguoichoi3->get_attack_mode() != 1 && nguoichoi3->get_pk() < 100 && who->get_pk() < 100 && !get_effect(who, EFFECT_USER_PK))
		{
			nguoichoi3->set_char_type(PK_TYPE);
			set_effect(nguoichoi3, EFFECT_USER_PK, 180);
		}
		else if (me->is_zombie() && nguoichoi3->is_user() && who->is_user() && nguoichoi3->get_attack_mode() != 1 && (nguoichoi3->get_pk() >= 100 || get_effect(who, EFFECT_USER_PK) || who->get_pk() >= 100))
		{
			set_effect(nguoichoi3, EFFECT_USER_PK, 0);
		}
	}
	/*if ( me->is_zombie() && who->is_user() && (get_z(me)==001||get_z(me)==289||get_z(me)==269||get_z(me)==273||get_z(me)==165||get_z(me)==324||get_z(me)==054||get_z(me)==080) )
	{
	me->set_hp(0);
	me->set_die(1);
	}*/

	level = me->get_level();
	level2 = who->get_level();

	if (get_effect(me, EFFECT_CHAR_GOOD_BAD))
		damage_rate += 10;

	if (who->is_npc())
	{
		if (who->get_enemy_4() == me)
			who->set_attack_time(time());
		else if (gone_time(who->get_attack_time()) > 12)
		{
			who->set_enemy_4(me);
			who->set_attack_time(time());
		}
		if (!who->get_max_damage())
			who->init_enemy_damage(me, 0);
	}

	// 判断能否命中
	asp = me->get_sp();
	dsp = who->get_sp();

	// rate = asp * 86 / range_value(dsp, 1, MAX_NUMBER);

	rate = 100;
	if (level < level2 && !me->is_comrade() && !who->is_comrade())
		rate = rate * (level + 10) / (level2 + 10);

	rate = range_value(rate, 5, 100);

	rate += me->get_hit_rate_2() - who->get_dodge_rate_2() - who->get_2("suit_effect.dodge");

	if (get_effect(me, EFFECT_CHAR_BLIND))
		rate /= 2;
	if (get_effect(who, EFFECT_DODGE))
		rate -= 20;
	if (get_effect(who, EFFECT_MAGIC_4243))
		rate -= 50;
	if (get_effect(who, EFFECT_CHAR_MOVE))
		rate -= who->get_save("03641");
	rate = range_value(rate, 5, 100);

	if (get_effect(me, EFFECT_CHAR_IGNORE) || get_effect(who, EFFECT_CHAR_IGNORE))
		rate = 0;

	// Tang chinh xac khi co ngu hanh
	/*
	if (me->get_2("nguhanh_rate") > 0) {
		rate += me->get_2("nguhanh_rate");
	}
	*/

	if (random(100) < rate)
	{
		if (who->is_trainer())
		{
			who->beat(me);
			return 1;
		}

		if (get_effect(who, EFFECT_03642))
		{
			"/skill/03/03642"->into_effect(who);
			set_effect(who, EFFECT_03642, 0);
			return 0;
		}

		cp = me->get_cp();
		cp0 = me->get_cp_0();
		pp = who->get_pp();
		pp0 = who->get_pp_0();
		pp -= pp * sub_pp_rate / 100;
		pp0 -= pp0 * sub_pp_rate / 100;
		if (me->get("sk74221"))
		{
			cp0 = cp;
			pp = pp0;
		}
		if (me->get("sk74127"))
		{
			cp = cp0;
			pp0 = pp;
		}

		cp += add_cp;
		cp0 += add_cp;

		damage = me->get_lucky();
		cp2 = cp0 + (cp - cp0) * damage / 100 + random((cp - cp0) * (100 - damage) / 100);
		pp2 = pp0 + (pp - pp0) * damage / 100 + random((pp - pp0) * (100 - damage) / 100);
		/*
		if( me->is_comrade() || who->is_comrade() )    // 战场战友
		{
		if( me->is_user() && who->is_user() )
		damage = ( cp2 - cp2 * pp2 / (40 + pp2) );    // 15 / 10, 25 / 1000
		else    damage = ( cp2 * 3 / 2 - cp2 * 3 / 2 * pp2 / (40 + pp2) );    // 15 / 10, 25 / 1000
		}
		else
		*/
		{
			damage = (cp2 * 9 + pp2 * 47) / 50;
			damage = cp2 - cp2 * pp2 / range_value(damage, 1, MAX_NUMBER);
		}
		if (!me->is_comrade() && !who->is_comrade())
			damage = damage * (level + 10) / (level2 + 10);
		damage = correct_damage_2(me, who, range_value(damage, 1, cp2), cp);
		damage += damage * me->get_save("03162#") / 100;
		damage += damage * who->get("sk74125") / 100;
		if (me->is_zombie() && who->is_user() && (get_z(me) == 001 || get_z(me) == 289 || get_z(me) == 269 || get_z(me) == 273 || get_z(me) == 165 || get_z(me) == 324 || get_z(me) == 054 || get_z(me) == 080))
		{
			damage = 1;
			me->set_hp(0);
			me->set_die(1);
		}

		rate = me->get_double_rate_2();
		random = random(10000);
		if (random < rate)
		{
			damage = damage * 2;

			if ((rate = who->get_2("suit_effect.double1")) && (p = who->get_2("suit_effect.double2")))
			{
				double_flag = random(p);
				if (double_flag < rate)
				{
					double_flag = rate;
				}

				damage = (damage / 2) + ((damage / 2) * (100 - double_flag) / 100);
			}

			double_flag = 1;

			// pet hoa su
			// Tang bao kich
			if (me->get_2("jiguan.addRateDouble") > 0 && random(100) <= me->get_2("jiguan.addRateDouble"))
			{
				if (me->get_2("jiguan.addDouble"))
				{
					damage = damage + (damage * me->get_2("jiguan.addDouble") / 100);
				}
			}

			// Giam bao kich
			if (who->get_2("jiguan.subRateDouble") > 0 && random(100) <= who->get_2("jiguan.subRateDouble"))
			{
				if (who->get_2("jiguan.subDouble"))
				{
					damage = damage * who->get_2("jiguan.subDouble") / 100;
				}
			}
		}
		damage = damage + damage * damage_rate / 100;
		if (p = me->get_skill(0432))
		{
			damage = damage * (100 + p * 2) / 100; // 帮派的法伤强化
		}

		if (p = who->get_skill(0433))
		{
			damage = damage * (100 - p * 2) / 100; // 帮派的法防强化
		}

		// Bảo hộ-Nội Công
		if (p = who->get_skill(0438))
		{
			damage = damage * (100 - p * 2) / 100;
		}

		/*debug ngu hanh*/
		if (is_god(me))
		{
			if (NGU_HANH->get_nguhanh_rate(who, ARMOR_TYPE) > 0 && NGU_HANH->get_nguhanh_rate(me, WEAPON_TYPE) > 0)
			{
				tell_user(me, HIG "%s -> %s %d%% [Giap]", ngu_hanh_names[NGU_HANH->get_nguhanh_rate(me, WEAPON_TYPE) - 1],
						  ngu_hanh_names[NGU_HANH->get_nguhanh_rate(who, ARMOR_TYPE) - 1], NGU_HANH->counting_tuongkhac_giap_rate(me, who));
			}

			if (NGU_HANH->get_nguhanh_rate(who, WEAPON_TYPE) > 0 && NGU_HANH->get_nguhanh_rate(me, WEAPON_TYPE) > 0)
			{
				tell_user(me, HIG "%s -> %s %d%% [Vũ khí]", ngu_hanh_names[NGU_HANH->get_nguhanh_rate(me, WEAPON_TYPE) - 1],
						  ngu_hanh_names[NGU_HANH->get_nguhanh_rate(who, WEAPON_TYPE) - 1], NGU_HANH->counting_tuongkhac_vk_rate(me, who));
			}
		}

		if (is_god(me))
		{
			tell_user(me, HIG "Sát thương gốc: %d", damage);
		}

		if (NGU_HANH->is_nguhanh(me) == 1 && NGU_HANH->is_nguhanh(who) == 0)
		{
			damage += damage * 150 / 1000;
			if (is_god(me))
			{
				tell_user(me, ECHO "Giá trị ngũ hành: %d%%", 15);
			}
		}
		if (NGU_HANH->is_nguhanh(who) == 1 && NGU_HANH->is_nguhanh(me) == 0)
		{
			damage = damage * 750 / 1000;
			if (is_god(me))
			{
				tell_user(me, ECHO "Giá trị ngũ hành: %d%%", -15);
			}
		}

		if (NGU_HANH->counting_nguhanh_rate(me, who) != 0 && NGU_HANH->is_nguhanh(me) == 1 && NGU_HANH->is_nguhanh(who) == 1)
		{
			rate_nguhanh = NGU_HANH->counting_nguhanh_rate(me, who);
			me->set_2("nguhanh_rate", rate_nguhanh);
			damage += damage * rate_nguhanh * 10 / 1000;

			if (is_god(me))
			{
				tell_user(me, HIG "Giá trị ngũ hành tăng: %d%%", rate_nguhanh);
			}
		}

		/*debug ngu hanh*/
		if (is_god(me))
		{
			tell_user(me, HIY "Sát thương mới: %d", damage);
		}
		//

		// if (is_god(me)) tell_user(me, "C %s Tấn công PHEP từ xa-> %s , CP: %d - PP: %d = Thương: %d ", me->get_name(), who->get_name(), cp2, pp2, damage);
		// if (is_god(who)) tell_user(who, "C %s Tấn công PHEP từ xa-> %s , CP: %d - PP: %d = Thương: %d ", me->get_name(), who->get_name(), cp2, pp2, damage);

		damage += me->get_2("suit_effect.damage2");
		damage += 1 + random(me->get_2("suit_effect.damage_rand2"));
		if (who->get_perform("05016#"))
			damage = damage * 4 / 5;
		if (damage < 1)
			damage = 1;
		if (get_effect(me, EFFECT_CHAR_POWERFALL))
		{
			if (me->is_user())
				damage = damage * (100 + me->get_save_2("pf.powerfall")) / 100;
			else
				damage = damage * (100 + me->get("pf.powerfall")) / 100;
			if (damage < 0)
				damage = 1;
		}
		if (get_effect(who, EFFECT_CHAR_MISS))
		{
			if (damage < who->get_save("pf.miss") && damage < who->get_mp())
			{
				who->add_mp(-damage);
				who->add_save("pf.miss", -damage);
				send_user(get_scene_object_2(who, USER_TYPE), "%c%d%w%c%c%c", 0x6f, getoid(who), 42515, 1, OVER_BODY, PF_ONCE);
				send_user(who, "%c%w%c", 0x82, 4252, 0);
				return 1;
			}
			else if (who->get_mp() > who->get_save("pf.miss"))
			{
				damage -= who->get_save("pf.miss");
				who->add_mp(-who->get_save("pf.miss"));
			}
			else
			{
				damage -= who->get_mp();
				who->set_mp(0);
			}
			"/sys/char/char"->effect_miss_done(who);
			set_effect(who, EFFECT_CHAR_MISS, 0);
		}
		if (get_effect(who, EFFECT_CHAR_MISS2))
		{
			send_user(get_scene_object_2(who, USER_TYPE), "%c%d%w%c%c%c", 0x6f, getoid(who), 42525, 1, OVER_BODY, PF_ONCE);
			if (who->is_user())
			{
				if (who->add_save("05911", -damage) < 0)
				{
					damage = -who->get_save("05911");
					set_effect(who, EFFECT_CHAR_MISS2, 1);
				}
				else
					return 1;
			}
			else
			{
				if (who->add("05911", -damage) < 0)
				{
					damage = -who->get("05911");
					set_effect(who, EFFECT_CHAR_MISS2, 1);
				}
				else
					return 1;
			}
		}
		else
		{
			if (who->is_user() && objectp(item = who->get_equip(WEAPON_TYPE)) &&
				item->get_name() == "Anh Kiệt Quyền Nhẫn" && random100() < 10)
			{
				// who->set_save("05911", 630);
				set_effect(who, EFFECT_CHAR_MISS2, 30);
				send_user(who, "%c%w%w%c", 0x81, 5911, get_effect_3(who, EFFECT_CHAR_MISS2), EFFECT_GOOD);
				send_user(get_scene_object_2(who, USER_TYPE) - ({who}), "%c%d%w%c%c", 0x83, getoid(who), 5911, 1, EFFECT_GOOD);
				send_user(get_scene_object_2(who, USER_TYPE), "%c%d%w%c%c%c", 0x6f, getoid(who), 10711, 1, OVER_BODY, PF_LOOP);
			}
			if (who->is_user() && objectp(item = who->get_equip(WEAPON_TYPE)) &&
				item->is_thanbinh1() && random100() < 5)
			{
				// who->set_save("05911", 1500);
				// set_effect(who, EFFECT_CHAR_MISS2, 30);
				// send_user(who, "%c%w%w%c", 0x81, 5911, get_effect_3(who, EFFECT_CHAR_MISS2), EFFECT_GOOD);
				// send_user(get_scene_object_2(who, USER_TYPE) - ({ who }), "%c%d%w%c%c", 0x83, getoid(who), 5911, 1, EFFECT_GOOD);
				// send_user(get_scene_object_2(who, USER_TYPE), "%c%d%w%c%c%c", 0x6f, getoid(who), 10711, 1, OVER_BODY, PF_LOOP);
			}
		}
		if (me->is_user() && objectp(item = me->get_equip(WEAPON_TYPE)))
		{
			if (item->is_thanbinh6())
			{
				if (random100() < 5)
				{
					if (get_effect(who, EFFECT_CHAR_FAINT))
						return 0;
					if (get_effect(who, EFFECT_CHAR_FAINT_0))
						return 0;
					if (who->is_anti_effect())
						return 0;
					if (who->get("anti_faint"))
						return 0;
					if (who->get_perform("02222#"))
						return 0;

					user = get_scene_object_2(who, USER_TYPE);
					set_effect(who, EFFECT_CHAR_FAINT, 2);
					CHAR_CHAR_D->init_loop_perform(who);
					if (get_heart_state(who) == MAGIC_STAT)
						send_user(user, "%c%d%d%c", 0x40, getoid(who), time2(), MAGIC_ACT_END);
					send_user(who, "%c%w%w%c", 0x81, 9002, get_effect_3(who, EFFECT_CHAR_FAINT), EFFECT_BAD);
					send_user(user - ({who}), "%c%d%w%c%c", 0x83, getoid(who), 9002, 1, EFFECT_BAD);
					send_user(user, "%c%d%w%c%c%c", 0x6f, getoid(who), 9002, 10, OVER_BODY, PF_LOOP);
					//	return 0;
				}
				else if (random100() < 10)
				{
					if (get_effect(who, EFFECT_CHAR_LAZY))
						return 0;
					send_user(who, "%c%c%c", 0x3d, 241, 1);
					set_effect(who, EFFECT_CHAR_LAZY, 4);
					send_user(who, "%c%w%w%c", 0x81, 9013, get_effect_3(who, EFFECT_CHAR_LAZY), EFFECT_BAD);
					send_user(get_scene_object_2(who, USER_TYPE) - ({who}), "%c%d%w%c%c", 0x83, getoid(who), 9013, 1, EFFECT_BAD);
				}
			}
		}

		damage += me->get("add_magic_damage");
		if (me->is_user())
		{
			if (objectp(item = me->get_equip(WEAPON_TYPE)) && item->get_name() == "Ngọc Thần Bảo Kiếm")
				damage += random(51);
			else if (objectp(item = me->get_equip(WEAPON_TYPE)) && item->get_name() == "Lục Tiên Kiếm")
				damage += 50 + random(51);
			else if (objectp(item = me->get_equip(WEAPON_TYPE)) && item->get_name() == "Thủy Long Kiếm")
				damage += 200 + random(101);

			if (objectp(item = me->get_equip(WEAPON_TYPE)) && item->is_thanbinh6())
			{
				damage += 200 + random(101);
			}
		}

		if (who->is_nianshou())
		{
			send_user(me, "%c%s", '!', "Kĩ năng của bạn không có tác dụng");
			damage = 0;
		}

		if (who->is_npc())
			owner = who->get_owner();
		else
			owner = who;
		if (owner)
		{
			if (double_flag == 0)
				send_user(owner, "%c%d%w%c%d%w%c", 0x48, getoid(who), damage, get_d(who), getoid(me), HIT_NORMAL, 2);
			else
				send_user(owner, "%c%d%w%c%d%w%c", 0x4a, getoid(who), damage, get_d(who), getoid(me), HIT_NORMAL, 2);
		}
		if (me->is_npc())
			owner = me->get_owner();
		else
			owner = me;
		if (owner)
		{
			if (double_flag == 0)
				send_user(owner, "%c%d%w%c%d%w%c", 0x48, getoid(who), damage, get_d(who), getoid(me), HIT_NORMAL, 2);
			else
				send_user(owner, "%c%d%w%c%d%w%c", 0x4a, getoid(who), damage, get_d(who), getoid(me), HIT_NORMAL, 2);
		}
		//		if( me->is_user() ) owner = me;
		//		else owner = me->get_owner();
		if (point = me->get_absorb_hp() && me->get_weapon_code() != SWORD && me->get_weapon_code() != THROWING)
		{
			point = range_value(damage * point / 100, 0, 10000);
			send_user(get_scene_object_2(me, USER_TYPE), "%c%d%w", 0x68, getoid(me), -point);
			me->add_hp(point);
		}

		if (point = me->get_absorb_mp())
		{
			point = range_value(who->get_hp(), 0, damage) * point / 100;
			point = range_value(point, 0, who->get_mp());
			who->add_mp(-point);
			me->add_mp(point);
		}

		if (who->is_user())
		{
			wear_down(who);
			CHAR_CHAR_D->stop_loop_perform_be_attack(who);
		}
		else if (get_effect(who, EFFECT_SLEEP))
			set_effect(who, EFFECT_SLEEP, 1);

		if (who->is_user() && (pet = who->get("showbeast")) && get_effect_3(pet, EFFECT_CHAR_SOUL_LOCK) && inside_screen_2(pet, who))
		{
			send_user(get_scene_object_2(pet, USER_TYPE), "%c%d%w", 0x68, getoid(pet), damage * 2);
			CHAR_DIE_D->is_enemy_die(me, pet, damage * 2);
			return;
		}
		else if (who->is_npc() && get_effect_3(who, EFFECT_CHAR_SOUL_LOCK) && (owner = who->get_owner()) && owner && inside_screen_2(owner, who))
		{
			send_user(get_scene_object_2(owner, USER_TYPE), "%c%d%w", 0x68, getoid(owner), damage / 2);
			CHAR_DIE_D->is_enemy_die(me, owner, damage / 2);
			return;
		}
		else
			CHAR_DIE_D->is_enemy_die(me, who, damage);
		if (me && me->get_hp() < 1)
			CHAR_DIE_D->is_enemy_die(who, me, 0);
		if (me && me->is_npc() && who)
			me->do_after_attack(who);

		if (who && me && get_effect(who, EFFECT_REBOUND))
		{

			if (who->is_npc())
			{
				if (me->is_user())
				{
					damage = me->get_ap() * who->get("03173#") / 140;
					owner = who->get_owner();
				}
				else if (me->is_zombie())
				{
					damage = me->get_ap() * who->get("03173#") / 140;
					owner = who->get_owner();
				}
				else if (me->is_pet())
				{
					damage = me->get_ap() * who->get("03173#") / 140;
					owner = who->get_owner();
				}
				else
				{
					damage = 30;
					owner = who->get_owner();
				}
			}
			else
			{
				if (me->is_user())
				{
					damage = me->get_ap() * (who->get_save("03173#") / 100) + who->get_dp() * who->get_save("03173#") / 100;
					if (me->get_fam_name() == "Đường Môn" ||
						me->get_fam_name() == "Vân Mộng Cốc" ||
						me->get_fam_name() == "Mao Sơn" ||
						me->get_fam_name() == "Côn Luân" ||
						me->get_fam_name() == "Thục Sơn")
					{
						damage /= 2;
					}
					owner = who;
				}

				else if (me->is_zombie())
				{
					damage = me->get_ap() * who->get_save("03173#") / 140;
					owner = who;
				}
				else if (me->is_pet())
				{
					damage = me->get_ap() * who->get_save("03173#") / 140;
					owner = who;
				}
				else
				{
					damage = 30;
					owner = who;
				}
			}
			if (me->is_nianshou())
				damage = 0;
			if (owner)
				send_user(owner, "%c%d%w%c%d%w%c", 0x48, getoid(me), damage, get_d(who), getoid(me),
						  hit_act, hit_act == HIT_NORMAL ? 2 : 1);
			if (me->is_user())
				owner = me;
			else
				owner = me->get_owner();
			if (owner)
				send_user(owner, "%c%d%w%c%d%w%c", 0x48, getoid(me), damage, get_d(who), getoid(me),
						  hit_act, hit_act == HIT_NORMAL ? 2 : 1);
			CHAR_DIE_D->is_enemy_die(who, me, damage);
			if (objectp(me) && objectp(who) && me->get_hp() < 1)
				CHAR_DIE_D->is_enemy_die(who, me, 0);
		}
	}
	else
	{
		// if( is_god(me) ) tell_user( me, "r %s Tấn công từ xa-> %s , Trúng pháp thuật: %d Thất Bại", me->get_name(), who->get_name(), rate );
		// if( is_god(who) ) tell_user( who, "r %s Tấn công từ xa-> %s , Trúng pháp thuật: %d Thất Bại", me->get_name(), who->get_name(), rate );
		//  显示躲闪效果
		id = getoid(who);
		if (who->is_npc())
			owner = who->get_owner();
		else
			owner = who;
		if (owner)
			send_user(owner, "%c%d", 0x44, id);
		if (me->is_user())
			owner = me;
		else
			owner = me->get_owner();
		if (owner)
			send_user(owner, "%c%d", 0x44, id);
		return 0;
	}

	return damage;
}

//---Co ngu hanh
varargs get_cast_damage(object me, object who, int cp, int cp0, int add_rate)
{
	int rate, random, pp, pp0, asp, dsp, damage, cp2, pp2, double_flag, level, level2, p, hit_act;
	int item1, item7, item3, item4, item5, item6;
	int rate_nguhanh;
	object map, nguoichoi, nguoichoi1, nguoichoi2, nguoichoi3, owner;

	pp = who->get_pp();
	pp0 = who->get_pp_0();
	asp = me->get_sp();
	dsp = who->get_sp();

	if ((is_gm2(who) || is_god(who) || is_gm3(who)) && CAN_KILL_GM == 0)
	{
		return 0;
	}

	map = get_map_object(get_z(me));
	if (me->is_user() && who->is_user() && (get_z(me) < 885 || map->is_org_map() || map->is_copy_scene() || map->is_pvp()))
	{
		if (me->is_user() && who->is_user() && me->get_attack_mode() != 1 && me->get_pk() < 100 && who->get_pk() < 100 && !get_effect(who, EFFECT_USER_PK))
		{
			me->set_char_type(PK_TYPE);
			set_effect(me, EFFECT_USER_PK, 180);
		}
		else if (me->is_user() && who->is_user() && me->get_attack_mode() != 1 && (me->get_pk() >= 100 || get_effect(who, EFFECT_USER_PK) || who->get_pk() >= 100))
		{
			set_effect(me, EFFECT_USER_PK, 0);
		}
	}
	if (me->is_user() && who->is_pet() && (get_z(me) < 885 || map->is_org_map() || map->is_copy_scene() || map->is_pvp()))
	{
		nguoichoi1 = who->get_owner();
		if (me->is_user() && who->is_pet() && nguoichoi1->is_user() && me->get_attack_mode() != 1 && me->get_pk() < 100 && nguoichoi1->get_pk() < 100 && !get_effect(nguoichoi1, EFFECT_USER_PK))
		{
			me->set_char_type(PK_TYPE);
			set_effect(me, EFFECT_USER_PK, 180);
		}
		else if (me->is_user() && who->is_pet() && nguoichoi1->is_user() && me->get_attack_mode() != 1 && (me->get_pk() >= 100 || get_effect(nguoichoi1, EFFECT_USER_PK) || nguoichoi1->get_pk() >= 100))
		{
			set_effect(me, EFFECT_USER_PK, 0);
		}
	}
	/*if ( me->is_user() && who->is_zombie() && ( get_z(me)<885 || map->is_org_map() || map->is_copy_scene() || map->is_pvp() ) )
	{
	nguoichoi2 = who->get_owner();
	if ( me->is_user() &&  who->is_zombie() && nguoichoi2->is_user() && me->get_attack_mode()!=1 && me->get_pk()<100 && nguoichoi2->get_pk()<100 && !get_effect(nguoichoi2, EFFECT_USER_PK)  )
	{
	me->set_char_type( PK_TYPE );    // 主动ＰＫ状态
	set_effect(me, EFFECT_USER_PK, 180);
	}
	else if ( me->is_user() && who->is_zombie() && nguoichoi2->is_user() && me->get_attack_mode()!=1 && (me->get_pk()>=100||get_effect(nguoichoi2, EFFECT_USER_PK)||nguoichoi2->get_pk()>=100) )
	{
	set_effect(me, EFFECT_USER_PK, 0);
	}
	}*/
	if (me->is_pet() && who->is_user() && (get_z(me) < 885 || map->is_org_map() || map->is_copy_scene() || map->is_pvp()))
	{
		nguoichoi = me->get_owner();
		if (me->is_pet() && nguoichoi->is_user() && who->is_user() && nguoichoi->get_attack_mode() != 1 && nguoichoi->get_pk() < 100 && who->get_pk() < 100 && !get_effect(who, EFFECT_USER_PK))
		{
			nguoichoi->set_char_type(PK_TYPE);
			set_effect(nguoichoi, EFFECT_USER_PK, 180);
		}
		else if (me->is_pet() && nguoichoi->is_user() && who->is_user() && nguoichoi->get_attack_mode() != 1 && (nguoichoi->get_pk() >= 100 || get_effect(who, EFFECT_USER_PK) || who->get_pk() >= 100))
		{
			set_effect(nguoichoi, EFFECT_USER_PK, 0);
		}
	}
	if (me->is_zombie() && who->is_user() && (get_z(me) < 885 || map->is_org_map() || map->is_copy_scene() || map->is_pvp()))
	{
		nguoichoi3 = me->get_owner();
		if (me->is_zombie() && nguoichoi3->is_user() && who->is_user() && nguoichoi3->get_attack_mode() != 1 && nguoichoi3->get_pk() < 100 && who->get_pk() < 100 && !get_effect(who, EFFECT_USER_PK))
		{
			nguoichoi3->set_char_type(PK_TYPE); // 主动ＰＫ状态
			set_effect(nguoichoi3, EFFECT_USER_PK, 180);
		}
		else if (me->is_zombie() && nguoichoi3->is_user() && who->is_user() && nguoichoi3->get_attack_mode() != 1 && (nguoichoi3->get_pk() >= 100 || get_effect(who, EFFECT_USER_PK) || who->get_pk() >= 100))
		{
			set_effect(nguoichoi3, EFFECT_USER_PK, 0);
		}
	}
	/*if ( me->is_zombie() && who->is_user() && (get_z(me)==001||get_z(me)==289||get_z(me)==269||get_z(me)==273||get_z(me)==165||get_z(me)==324||get_z(me)==054||get_z(me)==080) )
	{
		me->set_hp(0);
		me->set_die(1);
	}*/
	level = me->get_level();
	level2 = who->get_level();
	rate = 100;
	if (level < level2 && !me->is_comrade() && !who->is_comrade())
		rate = rate * (level + 10) / (level2 + 10);
	rate = range_value(rate, 5, 100);
	rate += me->get_hit_rate_2() - who->get_dodge_rate_2() - who->get_2("suit_effect.dodge");
	if (get_effect(me, EFFECT_CHAR_BLIND))
		rate /= 2;
	if (get_effect(who, EFFECT_DODGE))
		rate -= 20;
	if (get_effect(who, EFFECT_MAGIC_4243))
		rate -= 50;
	if (get_effect(who, EFFECT_CHAR_MOVE))
		rate -= who->get_save("03641");
	rate = range_value(rate, 5, 100);
	rate += add_rate;

	// Tang chinh xac khi co ngu hanh
	/*
	if (me->get_2("nguhanh_rate") > 0) {
		rate += me->get_2("nguhanh_rate");
	}
	*/

	if (random(100) < rate)
	{
		if (get_effect(who, EFFECT_03642))
		{
			"/skill/03/03642"->into_effect(who);
			set_effect(who, EFFECT_03642, 0);
			return 0;
		}
		damage = me->get_lucky();
		cp2 = cp0 + (cp - cp0) * damage / 100 + random((cp - cp0) * (100 - damage) / 100);
		pp2 = pp0 + (pp - pp0) * damage / 100 + random((pp - pp0) * (100 - damage) / 100);

		/*
		if( me->is_comrade() || who->is_comrade() )    // 战场战友
		{
		if( me->is_user() && who->is_user() )
		damage = ( cp2 - cp2 * pp2 / (40 + pp2) );    // 15 / 10, 25 / 1000
		else    damage = ( cp2 * 3 / 2 - cp2 * 3 / 2 * pp2 / (40 + pp2) );    // 15 / 10, 25 / 1000
		}
		else
		*/
		{
			damage = (cp2 * 9 + pp2 * 47) / 50;
			damage = cp2 - cp2 * pp2 / range_value(damage, 1, MAX_NUMBER);
		}
		if (!me->is_comrade() && !who->is_comrade())
			damage = damage * (level + 10) / (level2 + 10);
		damage = correct_damage_2(me, who, range_value(damage, 1, cp2), cp);
		damage += damage * me->get_save("03162#") / 100;
		if (me->is_zombie() && who->is_user() && (get_z(me) == 001 || get_z(me) == 289 || get_z(me) == 269 || get_z(me) == 273 || get_z(me) == 165 || get_z(me) == 324 || get_z(me) == 054 || get_z(me) == 080))
		{
			damage = 1;
			me->set_hp(0);
			me->set_die(1);
		}

		/*ngu hanh*/
		if (NGU_HANH->is_nguhanh(me) == 1 && NGU_HANH->is_nguhanh(who) == 0)
		{
			damage += damage * 150 / 1000;
			if (is_god(me))
			{
				tell_user(me, ECHO "Giá trị ngũ hành: %d%%", 15);
			}
		}
		if (NGU_HANH->is_nguhanh(who) == 1 && NGU_HANH->is_nguhanh(me) == 0)
		{
			damage = damage * 750 / 1000;
			if (is_god(me))
			{
				tell_user(me, ECHO "Giá trị ngũ hành: %d%%", -15);
			}
		}

		if (NGU_HANH->counting_nguhanh_rate(me, who) != 0 && NGU_HANH->is_nguhanh(me) == 1 && NGU_HANH->is_nguhanh(who) == 1)
		{
			rate_nguhanh = NGU_HANH->counting_nguhanh_rate(me, who);
			me->set_2("nguhanh_rate", rate_nguhanh);
			damage += damage * rate_nguhanh * 10 / 1000;

			if (is_god(me))
			{
				tell_user(me, HIG "Giá trị ngũ hành tăng: %d%%", rate_nguhanh);
			}
		}
		/*ngu hanh*/

		// if( is_god(me) ) tell_user( me, "r %s Tấn công từ xa-> %s, CP: %d - PP: %d = Thương: %d ", me->get_name(), who->get_name(), cp2, pp2, damage );
		// if( is_god(who) ) tell_user( who, "r %s Tấn công từ xa-> %s, CP: %d - PP: %d = Thương: %d ", me->get_name(), who->get_name(), cp2, pp2, damage );

		rate = me->get_double_rate_2();
		random = random(10000);
		if (random < rate)
		{
			damage = damage * 2;

			if ((rate = who->get_2("suit_effect.double1")) && (p = who->get_2("suit_effect.double2")))
			{
				double_flag = random(p);
				if (double_flag < rate)
				{
					double_flag = rate;
				}

				damage = (damage / 2) + ((damage / 2) * (100 - double_flag) / 100);
			}

			double_flag = 1;

			// pet hoa su
			// Tang bao kich
			if (me->get_2("jiguan.addRateDouble") > 0 && random(100) <= me->get_2("jiguan.addRateDouble"))
			{
				if (me->get_2("jiguan.addDouble"))
				{
					damage = damage + (damage * me->get_2("jiguan.addDouble") / 100);
				}
			}

			// Giam bao kich
			if (who->get_2("jiguan.subRateDouble") > 0 && random(100) <= who->get_2("jiguan.subRateDouble"))
			{
				if (who->get_2("jiguan.subDouble"))
				{
					damage = damage * who->get_2("jiguan.subDouble") / 100;
				}
			}
		}

		if (p = me->get_skill(0432))
		{
			damage = damage * (100 + p * 2) / 100;
		}

		if (who->get_perform("05016#"))
			damage = damage * 4 / 5;

		if (damage < 1)
			damage = 1;
		if (get_effect(me, EFFECT_CHAR_POWERFALL))
		{
			if (me->is_user())
				damage = damage * (100 + me->get_save_2("pf.powerfall")) / 100;
			else
				damage = damage * (100 + me->get("pf.powerfall")) / 100;
			if (damage < 0)
				damage = 1;
		}
		if (get_effect(who, EFFECT_CHAR_MISS))
		{
			if (damage < who->get_save("pf.miss") && damage < who->get_mp())
			{
				who->add_mp(-damage);
				who->add_save("pf.miss", -damage);
				send_user(get_scene_object_2(who, USER_TYPE), "%c%d%w%c%c%c", 0x6f, getoid(who), 42515, 1, OVER_BODY, PF_ONCE);
				send_user(who, "%c%w%c", 0x82, 4252, 0);
				return 1;
			}
			else if (who->get_mp() > who->get_save("pf.miss"))
			{
				damage -= who->get_save("pf.miss");
				who->add_mp(-who->get_save("pf.miss"));
			}
			else
			{
				damage -= who->get_mp();
				who->set_mp(0);
			}
			"/sys/char/char"->effect_miss_done(who);
			set_effect(who, EFFECT_CHAR_MISS, 0);
		}
		if (get_effect(who, EFFECT_CHAR_MISS2))
		{
			send_user(get_scene_object_2(who, USER_TYPE), "%c%d%w%c%c%c", 0x6f, getoid(who), 42525, 1, OVER_BODY, PF_ONCE);
			if (who->is_user())
			{
				if (who->add_save("05911", -damage) < 0)
				{
					damage = -who->get_save("05911");
					set_effect(who, EFFECT_CHAR_MISS2, 1);
				}
				else
					return 1;
			}
			else
			{
				if (who->add("05911", -damage) < 0)
				{
					damage = -who->get("05911");
					set_effect(who, EFFECT_CHAR_MISS2, 1);
				}
				else
					return 1;
			}
		}
		if (who->get_perform("05016#"))
			damage = damage * 4 / 5;

		return damage;
	}
	else
		return 0;
}

// Thiết lập giá trị của lòng căm thù
int set_enmity(object who, object enemy, int count)
{
	int enmity, enmity1;
	string id, id1;
	mapping mpTmp;
	object enemy1;

	if (!who || !enemy)
		return 0;
	if (!enemy->get_enmity_flag()) // 有仇恨Thiết lập 才进行处理
		return 0;
	if (!enemy->can_be_fighted(who) || !who->can_fight(enemy))
		return 0;

	if ((is_gm2(who) || is_god(who) || is_gm3(who)) && CAN_KILL_GM == 0)
	{
		return 0;
	}

	if (who->is_npc())
		id = sprintf("%x#", getoid(who));
	else
		id = sprintf("%d", getoid(who));
	enmity = enemy->set_enmity(id, enemy->get_enmity(id) + count);
	enemy1 = enemy->get_enemy();
	if (!objectp(enemy1))
		enemy->start_fight(who);
	else if (enemy1 != who)
	{
		if (enemy1->is_npc())
			id1 = sprintf("%x#", getoid(enemy1));
		else
			id1 = sprintf("%d", getoid(enemy1));
		enmity1 = enemy->get_enmity(id1);
		if (enmity > enmity1 * 11 / 10) // 仇恨超过当前攻击对象的10％，则转换攻击对象
		{
			enemy->start_fight(who);
			enemy->set_enemy(who);
			enemy->set("2122", time());
			enemy->follow_user();
		}
	}
	return enmity;
}

// Thiết lập giá trị của lòng căm thù (không có mục tiêu để tấn công)
int set_enmity1(object who, int count)
{
	int x, y, z, i, size;
	object *char;

	if ((is_gm2(who) || is_god(who) || is_gm3(who)) && CAN_KILL_GM == 0)
	{
		return 0;
	}

	z = get_z(who);
	x = get_x(who);
	y = get_y(who);
	char = get_range_object(z, x, y, 10, USER_TYPE) + get_range_object(z, x, y, 10, CHAR_TYPE) - ({who, 0});

	for (i = 0, size = sizeof(char); i < size; i++)
	{
		set_enmity(who, char[i], count);
	}
	return count;
}

// Thiết lập giá trị của lòng căm thù (không có mục tiêu để tấn công, có đối tượng cứu trợ)
int set_enmity2(object who, object help, int count)
{
	int x, y, z, i, size;
	object *char;

	if ((is_gm2(who) || is_god(who) || is_gm3(who)) && CAN_KILL_GM == 0)
	{
		return 0;
	}

	z = get_z(help);
	x = get_x(help);
	y = get_y(help);
	char = get_range_object(z, x, y, 10, USER_TYPE) + get_range_object(z, x, y, 10, CHAR_TYPE) - ({who, help, 0});
	for (i = 0, size = sizeof(char); i < size; i++)
	{
		set_enmity(who, char[i], count);
	}
	return count;
}