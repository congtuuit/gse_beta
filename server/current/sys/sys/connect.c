
#include <npc.h>
#include <city.h>
#include <item.h>
#include <equip.h>
#include <skill.h>
#include <effect.h>
#include <ansi.h>

void SAVE_BINARY() {}

void init_user(object me)
{
	object file;
	mapping skls;
	string *name, fam;
	int level, skill, flag;
	int i, size;

	USER_ENERGY_D->count_all_prop(me);
	USER_ENERGY_D->count_max_yuan(me);

	// lv name
	send_user(me, "%c%c%d%s", 0x3d, 160, me->get_number(), me->get_name());
	
	if (me->get_org_name() != "" && me->get_org_position() > 0)
	{
		// chuc vi bang phai
		send_user(me, "%c%c%c%s", 0x3d, 49, me->get_org_position(),
				  me->get_org_name());
	}

	send_user(me, "%c%c%c%s", 0x3d, 161, me->get_gender(),
			  sprintf("%-8s%-8s%-10s%-8s%-8s%-20s",
					  me->get_fam_name() == "" ? "－－" : me->get_fam_name(),
					  me->get_fam_master(),
					  me->get_org_name() == "" ? "－－" : me->get_org_name(),
					  me->get_city_name() == "" ? "－－" : me->get_city_name(),
					  me->get_occupation(), me->get_title()));

	send_user(me, "%c%c%d", 0x3d, 46, me->get_fam_contribute());

	send_user(me, "%c%c%w%w%w%w%w", 0x3d, 162, me->get_con(), me->get_spi(),
			  me->get_str(), me->get_cps(), me->get_dex());

	send_user(me, "%c%c%w%w%w%w%w%w%w%w%w%w%w%w%w%c%c%s", 0x3d, 163, me->get_hp(),
			  me->get_max_hp(), me->get_mp(), me->get_max_mp(), me->get_ap_0(),
			  me->get_ap(), me->get_dp_0(), me->get_dp(), me->get_cp_0(),
			  me->get_cp(), me->get_pp_0(), me->get_pp(), me->get_sp(),
			  me->get_yuan(), me->get_max_yuan(), " PK: " + me->get_pk());

	send_user(me, "%c%c%w%d%d%d%w%w%d%d%d%d", 0x3d, 164, me->get_billion_exp(),
			  me->get_exp(), me->get_potential(), me->get_bonus() / 10,
			  me->get_gift_point(), level = me->get_level(),
			  me->get_upgrade_exp(),
			  USER_EXP_D->get_level_exp(me->get_reincarnation(), level),
			  me->get_cash(), me->get_savings());
	send_user(me, "%c%c%d%d%d%d%d%d%d%d%c%w%d", 0x3d, 165, me->get_gift_ra(),
			  me->get_gift_zy(), me->get_gift_zs(), me->get_gift_cx(),
			  me->get_gift_yg(), me->get_gift_zm(), me->get_repute(),
			  me->get_contribute(), me->get_strength(),
			  me->get_occupation_level(), me->get_occupation_exp());
	send_user(me, "%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 0x3d, 166,
			  me->get_no_give(), me->get_no_fly(), me->get_no_trans(),
			  me->get_no_team(), me->get_no_friend(), me->get_no_tell(),
			  me->get_chat_open(), me->get_rumor_open(), me->get_city_open(), 1,
			  1, me->get_say_open(), 1,
			  1,
			  me->get_id_locked(), me->get_attack_mode(), me->get_no_trade());

	send_user(me, "%c%c%w", 0x3d, 143, me->get_mouse());
	send_user(me, "%c%c%w", 0x3d, 144, me->get_mode());

	fam = me->get_fam_name();
	//if (fam == "Côn Luân" || fam == "Vân Mộng Cốc" || fam == "Thục Sơn")
	if (fam == "Côn Luân" || fam == "Vân Mộng Cốc")
	{
		send_user(me, "%c%c%w", 0x3d, 29, me->get_double_rate_2());
	}
	else
	{
		send_user(me, "%c%c%w", 0x3d, 29, me->get_double_rate());
	}

	send_user(me, "%c%d", 0x74, time2());

	flag = 0;
	USER_INVENTORY_D->send_max_carry_flag(me);
	me->init_beast();
	me->add_pk(0);

	send_user(me, "%c%w", 0x53, 0);

	if (mapp(skls = me->get_skill_dbase()) && sizeof(skls))
	{
		name = sort_array(keys(skls), 1);
		for (i = 0, size = sizeof(name); i < size; i++)
		{
			skill = to_int(name[i]);

			if ((file = load_object(SKILL->get_skill_file(skill))) && file->get_name())
			{
				// an ky nang nghe
				if (file->is_vita_skill())
				{
					if (me->get_save_2("hideSkill") > 0)
					{
						continue;
					}
					else
					{
						send_user(me, "%c%c%w%w%d%s", 0x60, 1, skill, me->get_skill(skill),
								  me->get_skill_degree(skill), file->get_name());
					}
				}
				else if (file->is_basic_skill())
				{
					// help skill
					/*if (me->get_save_2("hideSkill") > 0) {
						continue;
					}
					else*/
					{
						send_user(me, "%c%w%w%d%s", 0x55, skill, me->get_skill(skill),
								  me->get_skill_degree(skill), file->get_name());
					}
				}
				else
				{
					send_user(me, "%c%w%w%d%s", 0x53, skill, me->get_skill(skill),
							  me->get_skill_degree(skill), file->get_name());
				}

				file->can_perform(me);
			}
		}
	}

	switch (me->get_occupation())
	{
	case JOB_ACTOR:
		if (file = load_object(SKILL->get_skill_file(SKILL_ACTOR)))
			file->can_perform(me);
		break;
	case JOB_FARMER:
		if (file = load_object(SKILL->get_skill_file(SKILL_FARMER)))
			file->can_perform(me);
		break;
	case JOB_SOLDIER:
		if (file = load_object(SKILL->get_skill_file(SKILL_SOLDIER)))
			file->can_perform(me);
		break;
	case JOB_SCHOLAR:
		if (file = load_object(SKILL->get_skill_file(SKILL_SCHOLAR)))
			file->can_perform(me);
		break;
	case JOB_TRADER:
		if (file = load_object(SKILL->get_skill_file(SKILL_TRADER)))
			file->can_perform(me);
		break;
	}

	if (file = load_object(SKILL->get_skill_file(SKILL_USER)))
	{
		file->can_perform(me);
	}

	if (objectp(file = me->get_equip(HAND_TYPE)) &&
		file->get_item_type() == ITEM_TYPE_TALISMAN)
		if (file = load_object(SKILL->get_skill_file(SKILL_TALISMAN)))
			file->can_perform(me);

	if (mapp(skls = me->get_save_2("hotkey")) && sizeof(skls))
	{
		name = keys(skls);
		for (i = 0, size = sizeof(name); i < size; i++)
			send_user(me, "%c%c%s", 0x4b, to_int(name[i]), skls[name[i]]);
	}

	CHAR_CHAR_D->stop_loop_perform_8(me);
	CHAR_CHAR_D->init_loop_perform(me);

	// if (me->get_online_time() > 1825 * 3600)
	// 	send_user(me, "%c%c%d%s", 0x43, 10, 0, HIY "Bạn đã tiến vào thời gian phi khoẻ mảnh, hãy out gêm nghỉ ngơi "
	// 											   "5 giờ rồi vào lại !!!");
	// else if (me->get_online_time() > 1095 * 3600)
	// 	send_user(me, "%c%c%d%s", 0x43, 10, 0, HIY "Bạn đã mãn 3 năm online, hãy out ra nghĩ nghơi để hồi phục thân "
	// 											   "thể !!!");
}
