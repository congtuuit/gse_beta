
#include <ansi.h>
#include <skill.h>
#include <equip.h>

int main(object me, string arg)
{
	mapping skls;
	object* inv, item;
	string cmd0, cmd1, cmd2, cmd3, cmd4, cmd5, cmd6, cmd7, chars;
	string cmd10, cmd20, cmd30, cmd40, cmd50, cmd60, cmd70;
	string* name, file;
	object who;
	int family, level, level2, weapon, armor, skill;
	int p, i, size;

	if (is_player(me))
	{
		return 1;
	}
	if (!is_gm2(me) && !is_god(me))
	{
		return 1;
	}
	if (!arg)
	{
		family = -1;  level = -1;  weapon = -1;
	} else if (sscanf(arg, "%s %d %d %d", chars,  family, level, weapon) == 4);
	else if (sscanf(arg, "%s %d %d", chars,  family, level) == 3)
		weapon = -1;
	else
	{
		family = -1;  level = -1;  weapon = -1;
	}

	who = find_any_char(chars);

	if (family < 0)
	{
		cmd1 = sprintf("family 1 %d\n", level);
		cmd2 = sprintf("family 2 %d\n", level);
		cmd3 = sprintf("family 3 %d\n", level);
		cmd4 = sprintf("family 4 %d\n", level);
		cmd5 = sprintf("family 5 %d\n", level);
		cmd6 = sprintf("family 6 %d\n", level);
		cmd7 = sprintf("family 7 %d\n", level);
		cmd10 = sprintf("family 10 %d\n", level);
		cmd20 = sprintf("family 20 %d\n", level);
		cmd30 = sprintf("family 30 %d\n", level);
		cmd40 = sprintf("family 40 %d\n", level);
		cmd50 = sprintf("family 50 %d\n", level);
		cmd60 = sprintf("family 60 %d\n", level);
		cmd70 = sprintf("family 70 %d\n", level);
		cmd0 = sprintf("family 0 %d\n", level);
		send_user(me, "%c%s", ':', "Cậu muốn đi học kiểu gì?\n"
			ESC "Đào Hoa Nguyên\n" + cmd1 +
			ESC "Thục Sơn\n" + cmd2 +
			ESC "Cấm Vệ Quân\n" + cmd3 +
			ESC "Đường Môn\n" + cmd4 +
			ESC "Mao Sơn\n" + cmd5 +
			ESC "Côn Luân\n" + cmd6 +
			ESC "Vân Mộng Cốc\n" + cmd7 +
			
			ESC "Vô Môn Phái.\n" + cmd0);
		return 1;
	}
	else {
		if (!who)
		{
			tell_user(me, ECHO"Không tìm thấy người này");
			return 1;
		}

		switch (family)
		{
			default: file = "Vô Môn Phái.";  break;
			case 1: case 10: file = "Đào Hoa Nguyên";  break;
			case 2: case 20: file = "Thục Sơn";  break;
			case 3: case 30: file = "Cấm Vệ Quân";  break;
			case 4: case 40: file = "Đường Môn";  break;
			case 5: case 50: file = "Mao Sơn";  break;
			case 6: case 60: file = "Côn Luân";  break;
			case 7: case 70: file = "Vân Mộng Cốc";  break;
		}
	}

	if (level < 0)
	{
		send_user(me, "%c%c%d%s", '?', 1, who->get_max_skill_level_2(), sprintf("Tạo “%s” Kỹ năng。\n\nNhập trình độ kỹ năng：\n"
			ESC "family %d %%s\n", file, family));
		return 1;
	}

	if (mapp(skls = who->get_skill_dbase()) && sizeof(skls))
	{
		name = keys(skls);
		for (i = 0, size = sizeof(name); i < size; i++)
		{
			skill = to_int(name[i]);
			if (skill < 610) who->delete_skill(skill);
		}
	}

	inv = who->get_all_equip();
	for (i = 0, size = sizeof(inv); i < size; i++) if (inv[i])
	{
		inv[i]->remove_from_user();
		destruct(inv[i]);
	}
	who->set_upgrade_exp(0);
	if (level == 0) who->set_exp(0, 0);
	else
		who->set_exp(USER_EXP_D->get_level_exp_low(who->get_reincarnation(), level - 1),
			USER_EXP_D->get_level_exp_high(who->get_reincarnation(), level - 1));

	NPC_ENERGY_2_D->init_family(who, family, level, weapon);
	USER_ENERGY_D->count_all_prop(who);
	USER_ENERGY_D->count_max_yuan(who);
	who->set_max_level(who->get_level());

	who->set_hp(who->get_max_hp());
	who->set_mp(who->get_max_mp());


	return 1;
}
