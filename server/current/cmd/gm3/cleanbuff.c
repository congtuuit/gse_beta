
#include <ansi.h>
#include <skill.h>
#include <action.h>
#include <effect.h>

int main(object me, string arg)
{
	object who;
	int i, size, a1, a2, a3, a4, arg_tmp, z;
	int amount, value;
	int level;
	int time, pos, time2;
	string chars;

	int* all = ({
			EFFECT_CHAR_POWERUP3,
			EFFECT_CHAR_KING_2,
			EFFECT_1811,
			EFFECT_2123_ARMORFALL,
			EFFECT_03484,
			EFFECT_CHAR_ARMORFALL,
			EFFECT_CHAR_HALFGOD2,
			EFFECT_02614,
			EFFECT_02614,
			EFFECT_USER_MP,
			EFFECT_USER_EXCHANGE_HP,
			EFFECT_CHAR_KING,
			EFFECT_USER_HP,
			EFFECT_USER_PP,
			EFFECT_USER_EXCHANGE_CP,
			EFFECT_USER_CP,
			EFFECT_USER_AP,
			EFFECT_CHAR_ADD_DP,
			EFFECT_EXCITE,
			EFFECT_REBOUND,
			EFFECT_USER_DP,
			EFFECT_USER_SP,
			EFFECT_DODGE,
			EFFECT_03484,
			EFFECT_CHAR_MOVE,
			EFFECT_CHAR_HALFGOD2,
			EFFECT_CHAR_POWERUP,
			EFFECT_CHAR_POWERUP2,
			EFFECT_CHAR_BLOOD,
			EFFECT_USER_BURN,
			EFFECT_CHAR_LAZY,
			EFFECT_CHAR_NO_MOVE,
			EFFECT_CHAR_CHAOS,
			EFFECT_CHAR_BLIND,
			EFFECT_02614,
			EFFECT_02616,
			EFFECT_CHAR_POWERFALL,
			EFFECT_CHAR_FALL,
			EFFECT_XUESHI_HP,
			EFFECT_MP_FALL, });

	//int* all = ({ EFFECT_CHAR_ADD_DP, EFFECT_EXCITE, EFFECT_REBOUND, EFFECT_USER_DP, EFFECT_USER_SP, EFFECT_DODGE, EFFECT_03484, EFFECT_CHAR_MOVE, EFFECT_CHAR_HALFGOD2, EFFECT_CHAR_POWERUP, EFFECT_CHAR_POWERUP2, EFFECT_CHAR_POWERUP3, });

	if (is_player(me))
	{
		notify("Ngươi không đủ quyền hạn");
		return 1;
	}
	if (sscanf(arg, "%s", chars) == 1) {
		if (!(who = find_any_char(chars)))
		{
			notify("Không tìm thấy người này");
			return 1;
		}

		send_user(get_scene_object_2(who, USER_TYPE), "%c%d%w%c%c%c", 0x6f, getoid(who), 32531, 1, OVER_BODY, PF_ONCE);
		size = sizeof(all);

		for (z = 0; z < 15; z++) {
			time = 0; pos = -1;
			time2 = 0;
			for (i = 0; i < size; i++) {

				if (who->get_effect(all[i]) ||
					who->get_effect_2(all[i]) ||
					who->get_effect_3(all[i])
					)

				{
					who->set_effect(who, all[i], 0);
					who->set_effect_2(who, all[i], 0);
					who->set_effect_3(who, all[i], 0);
				}

				if (time < get_effect(who, all[i]))
				{
					time = get_effect(who, all[i]);
					time2 = get_effect_3(who, all[i]);

					pos = i;

					who->delete_perform(all[i]);
				}
			}


			for (i = 0; i < size; i++) {
				if (who->get_perform(PF_FLAG_03172))
				{
					if (time() - who->get_perform(PF_FLAG_03172) > time)
					{
						who->delete_perform(PF_FLAG_03172);
						pos = -1;
						CHAR_CHAR_D->init_loop_perform(who);
						send_user(who, "%c%w%w%c", 0x81, 3172, 0, EFFECT_GOOD);
						send_user(get_scene_object_2(who, USER_TYPE) - ({ who }), "%c%d%w%c%c", 0x83, getoid(who), 3172, 0, EFFECT_GOOD);
					}

					if (time() - who->get_perform(PF_FLAG_03172) > time2)
					{
						who->delete_perform(PF_FLAG_03172);
						pos = -1;
						CHAR_CHAR_D->init_loop_perform(who);
						send_user(who, "%c%w%w%c", 0x81, 3172, 0, EFFECT_GOOD);
						send_user(get_scene_object_2(who, USER_TYPE) - ({ who }), "%c%d%w%c%c", 0x83, getoid(who), 3172, 0, EFFECT_GOOD);
					}
				}

				

				if (pos != -1)
				{
					if (all[pos] < 96) set_effect(who, all[pos], 1);
					else set_effect_2(who, all[pos], 1, 1);
				}
			}
		}
		
		who->delete_save("tuzi");
		who->delete_save("tuziHalloween");
		who->delete_save("ChristmasPoint");

		//who->set("temp_attack_speed", 1);

		send_user(who, "%c%w%c%w", 0x50, 03253, 0xff, 0);
		send_user(get_scene_object_2(who, USER_TYPE), "%c%d%w%c%c%c", 0x6f, getoid(who), 32531, 1, OVER_BODY, PF_ONCE);
	}

	return 1;
}