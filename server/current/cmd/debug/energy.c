
#include <ansi.h>
#define COUND_d "/sys/sys/count"

string get_type_word(int type)
{
	switch (type)
	{
	case 0: return "Khí huyết.";
	case 1: return "Pháp Thuật";
	case 2: return "Tấn công.";
	case 3: return "Phòng Ngự";
	case 4: return "Luật pháp tấn công";
	case 5: return "Luật pháp tấn công";
	default: return "Nhanh nhẹn";
	}
}

string get_fam_word(int type)
{
	switch (type)
	{
	case 0: return "Vô Môn Phái.";
	case 1: return "Đào Hoa Nguyên";
	case 2: return "Thục Sơn";
	case 3: return "Cấm Vệ Quân";
	case 4: return "Đường Môn";
	case 5: return "Mao Sơn";
	case 6: return "Côn Luân";
	default: return "Vân Mộng Cốc";
	}
}

int main(object me, string arg)
{
	object* zombie, soldier;
	string cmd1, cmd2, cmd3, cmd4, cmd5, cmd6, cmd7, cmd8;
	int type, type2, index, value;

	if (me != this_player(1) || is_player(me))
	{
		notify("");
		return 1;
	}

	if (!arg)
	{
		send_user(me, "%c%s", ':', "Những loại thức bạn có muốn nhìn thấy？\n"
			ESC "Khí huyết công thức\nenergy 0\n"
			ESC "Mana thức\nenergy 1\n"
			ESC "Tấn công thức\nenergy 2\n"
			ESC "Phòng thủ chính thức\nenergy 3\n"
			ESC "Luật tấn công chính thức\nenergy 4\n"
			ESC "Luật quốc phòng công thức\nenergy 5\n"
			ESC "Nhanh nhẹn thức\nenergy 6\n"
			ESC "Rời đi\nCLOSE\n");
		return 1;
	}
	if (sscanf(arg, "%d %d %d %d", type, type2, index, value) == 4)
	{
		if (type == 0) COUND_d->set_1(type2, index, value);
		else COUND_d->set_2(type2, index, value);
		"/sys/user/energy"->count_all_prop(me);
		main(me, sprintf("%d", type2));
		return 1;
	}
	if (sscanf(arg, "%d %d %d", type, type2, index) == 3)
	{
		if (type == 0)
			send_user(me, "%c%c%d%s", '?', 1, 999999, sprintf("Bạn có muốn" + get_fam_word(index) + "Của" + get_type_word(type2) + "Bao nhiêu là thay đổi hệ số nhân?\n"
				ESC "energy %d %d %d %%s\n", type, type2, index));
		else
			send_user(me, "%c%c%d%s", '?', 1, 999999, sprintf("Bạn có muốn" + get_fam_word(index) + "Của" + get_type_word(type2) + "Thay đổi thay đổi hệ số là gì?\n"
				ESC "energy %d %d %d %%s\n", type, type2, index));
		return 1;
	}

	if (sscanf(arg, "%d %d", type2, index) == 2)
	{
		cmd1 = sprintf(ESC "Nhân tố\nenergy 0 %d %d\n", type2, index);
		cmd2 = sprintf(ESC "Chia bởi hệ số\nenergy 1 %d %d\n", type2, index);
		send_user(me, "%c%s", ':', "Anh muốn thay đổi" + get_fam_word(index) + " của " + get_type_word(type2) + "Đó giá trị của các công thức？\n"
			+ cmd1 + cmd2 +
			ESC "Rời đi\nCLOSE\n");
		return 1;
	}

	type2 = to_int(arg);
	cmd1 = sprintf(ESC "Vô Môn Phái.: %d/%d\nenergy %d 0\n", COUND_d->get_1(type2, 0), COUND_d->get_2(type2, 0), type2);
	cmd2 = sprintf(ESC "Đào Hoa Nguyên: %d/%d\nenergy %d 1\n", COUND_d->get_1(type2, 1), COUND_d->get_2(type2, 1), type2);
	cmd3 = sprintf(ESC "Thục Sơn: %d/%d\nenergy %d 2\n", COUND_d->get_1(type2, 2), COUND_d->get_2(type2, 2), type2);
	cmd4 = sprintf(ESC "Cấm Vệ Quân: %d/%d\nenergy %d 3\n", COUND_d->get_1(type2, 3), COUND_d->get_2(type2, 3), type2);
	cmd5 = sprintf(ESC "Đường Môn: %d/%d\nenergy %d 4\n", COUND_d->get_1(type2, 4), COUND_d->get_2(type2, 4), type2);
	cmd6 = sprintf(ESC "Mao Sơn: %d/%d\nenergy %d 5\n", COUND_d->get_1(type2, 5), COUND_d->get_2(type2, 5), type2);
	cmd7 = sprintf(ESC "Côn Luân: %d/%d\nenergy %d 6\n", COUND_d->get_1(type2, 6), COUND_d->get_2(type2, 6), type2);
	cmd8 = sprintf(ESC "Vân Mộng Cốc: %d/%d\nenergy %d 7\n", COUND_d->get_1(type2, 7), COUND_d->get_2(type2, 7), type2);
	send_user(me, "%c%s", ':', "Phía dưới " + get_type_word(type2) + "Các công thức：\n"
		+ cmd1 + cmd2 + cmd3 + cmd4 + cmd5 + cmd6 + cmd7 + cmd8 +
		ESC "Rời đi\nCLOSE\n");
	return 1;


	return 1;
}
