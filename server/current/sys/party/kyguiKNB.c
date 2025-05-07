#include <time.h>
#include <ansi.h>
#include <cmd.h>

#include <npc.h>
#include <city.h>
#include <action.h>
#include <effect.h>
#include <skill.h>
#include <public.h>

inherit DBASE_F;
inherit SAVE_F;

#define YUANBAO "sys/sys/test_db"

void SAVE_BINARY() { }
string get_save_file() { return "data/Halloween"SAVE_EXTENSION; }

void create()
{
	restore();
	call_out("check_time", 1);
}

void napknb() {

	int flag, id, gender, userId, intAmount = 0, intUser, checked, p;
	int i, size;
	object who, item;
	string* line, strAmount = "0", content = "", * data, user = "0";
	string item_name;
	string result;
	int item_number;

	line = explode(read_file(DATA_KNB), "\n");
	for (i = 0, size = sizeof(line); i < size; i++)
	{
		data = explode(line[i], " ");

		/*if (userId == to_int(data[0])) {
			strAmount = data[1];
			user = data[0];
			continue;
		}*/

		if ((who = find_any_char(data[0])))
		{
			strAmount = data[1];
			user = data[0];
			continue;
		}

		content += line[i] + "\n";
	}

	if (user == "0") {
		call_out("check_time", timeRecall);
		return;
	}

	if (!(who = find_any_char(user)))
	{
		call_out("check_time", timeRecall);
		return;
	}


	intAmount = to_int(strAmount);

	intAmount = intAmount + ((intAmount / 100) * rate);

	if (intAmount > 0)
	{
		who->set_save_2("donate.total", who->get_save_2("donate.total") + intAmount);
		YUANBAO->add_yuanbao(who, (intAmount * 10));
		MAILBOX->sys_mail(who->get_id(), who->get_number(), sprintf("Bạn đã nạp thành công %d Kim Nguyên Bảo. Điểm cống hiến tăng %d điểm.", intAmount, intAmount));

		tell_user(who, sprintf(HIY"Bạn đã nạp thành công %d Kim Nguyên Bảo.", intAmount));

		log_file("00NapKNB.txt", short_time() + sprintf("	ID %s Nạp KNB _ %d\n", who->get_id(), intAmount));

	}

	rm(DATA_KNB);
	write_file(DATA_KNB, content);

	call_out("check_time", timeRecall);
}

void check_time()
{
	int iTime, rate, level, z, p, x, y;
	int i, * nScene, size;
	object who;
	mixed* mixTime;
	object robber;
	string errstr, * line, * data, * serverCheck, * dataServerCheck, * line_channel, * data_channel, errstr_channel;
	string content = "", fileData;

	remove_call_out("check_time");

	
	napknb();
}



void paihangbang(object player, object npc)
{
	int index, pos, name_size, id, max_blank, i;
	string tmp = "", cmd = "", playername, blank = "";
	blank = repeat_string(" ", 10);

	for (index = 1; index <= 5; index++)
	{
		id = get_save_2(sprintf("record.%d", index));
		if (!id)
		{
			tmp = sprintf(" ""%2d.%s%s%s", index, " ", "", "Chưa cập nhật");
			tmp += blank;
			tmp += sprintf(" ""%2d.%s%s%s", index + 5, " ", "", "Chưa cập nhật");
			tmp += "\n";
		}
		else
		{
			playername = get_save_2(sprintf("player.%d.name", id));
			name_size = strlen(playername);
			if (name_size <= 12)
			{
				playername += repeat_string(" ", 12 - name_size);
			}
			switch (index)
			{
			case 1:
				tmp = sprintf(" ""R""%2d.%12s%4s%3d"NOR, 1, playername, ":", get_save_2(sprintf("player.%d.count", id)));
				max_blank = get_save_2(sprintf("player.%d.count", id));
				break;
			case 2:
				tmp = sprintf(" ""M""%2d.%12s%4s%3d"NOR, 2, playername, ":", get_save_2(sprintf("player.%d.count", id)));
				break;
			case 3:
				tmp = sprintf(" ""B""%2d.%12s%4s%3d"NOR, 3, playername, ":", get_save_2(sprintf("player.%d.count", id)));
				break;
			case 4:
				tmp = sprintf(" ""%2d.%12s%4s%3d", 4, playername, ":", get_save_2(sprintf("player.%d.count", id)));	//+BLK+BLK
				break;
			case 5:
				tmp = sprintf(" ""%2d.%12s%4s%3d", 5, playername, ":", get_save_2(sprintf("player.%d.count", id)));	//+BLK+BLK
				break;
			}

			tmp += blank;
			for (i = 0; i < 4; i++) {
				tmp += " ";
			}

			id = get_save_2(sprintf("record.%d", index + 5));
			if (!id)
			{
				tmp += sprintf(" ""%d.%s%s%s", index + 5, "", "", "Chưa cập nhật");
			}
			else
			{
				playername = get_save_2(sprintf("player.%d.name", id));
				name_size = strlen(playername);
				if (name_size <= 12)
				{
					playername += repeat_string(" ", 12 - name_size);
				}
				tmp += sprintf("""%2d.%8s%4s%3d", index + 5, playername, ":", get_save_2(sprintf("player.%d.count", id)));
			}
			tmp += "\n";
		}
		cmd += tmp;

	}

	send_user(player, "%c%c%w%s", ':', 3, npc->get_char_picid(), sprintf("Bảng xếp hạng Sự kiện Halloween, bây giờ đã nộp "HIR"%d"NOR" Mũ Cương Thi \n", player->get_save("tuziHalloween")) + cmd
		+ ESC "Xác nhận\n");
}

void update_record(object player)
{
	int size, index, pos, oldid, id1, amount, i;
	int id = player->get_number();
	string name = player->get_name();
	amount = player->get_save("tuziHalloween");
	if (get_save_2(sprintf("player.%d", id)))
	{
		if (get_save_2(sprintf("player.%d.name", id)) == name)
		{
			set_save_2(sprintf("player.%d.count", id), amount);
			pos = get_save_2(sprintf("player.%d.pos", id));
		}
	}
	else if ((size = get_save_2(sprintf("record.size"))) < 10)
	{
		pos = size + 1;
		set_save_2("record.size", pos);
		set_save_2(sprintf("record.%d", pos), id);
		set_save_2(sprintf("player.%d.name", id), name);
		set_save_2(sprintf("player.%d.pos", id), pos);
		set_save_2(sprintf("player.%d.count", id), amount);
	}
	else
	{
		oldid = get_save_2(sprintf("record.%d", size));
		if (get_save_2(sprintf("player.%d.count", oldid)) < amount)
		{
			pos = size;
			delete_save_2(sprintf("player.%d", oldid));
			set_save_2(sprintf("record.%d", pos), id);
			set_save_2(sprintf("player.%d.name", id), name);
			set_save_2(sprintf("player.%d.pos", id), pos);
			set_save_2(sprintf("player.%d.count", id), amount);
			set_save_2("record.size", pos);
		}
	}
	if (pos)
	{
		for (index = pos; index > 1; index--)
		{
			id = get_save_2(sprintf("record.%d", index));
			id1 = get_save_2(sprintf("record.%d", index - 1));
			if (get_save_2(sprintf("player.%d.count", id1)) >= get_save_2(sprintf("player.%d.count", id)))
			{
				break;
			}
			set_save_2(sprintf("record.%d", index), id1);
			set_save_2(sprintf("player.%d.pos", id1), index);
			set_save_2(sprintf("record.%d", index - 1), id);
			set_save_2(sprintf("player.%d.pos", id), index - 1);
		}
		save();
	}

}

//Thuong Top
void paihangbang_bonus(int top, int vip, int potential, int cash, object player, object npc)
{
	int flag = 0, iVipTime, iVip, iTime;
	int id = player->get_number();
	mixed* mixTime;

	iTime = get_party_time();

	if (iTime <= iFinish_phoban) {
		send_user(player, "%c%c%w%s", ':', 3, npc->get_char_picid(), npc->get_name() + ":\n	Rất xin lỗi, chưa tới lúc để nhận thưởng" + ESC"Xác nhận\n");
		return;
	}

	if (sizeof_inventory(player, 2, MAX_CARRY) >= MAX_CARRY)
	{
		send_user(player, "%c%c%w%s", ':', 3, npc->get_char_picid(), npc->get_name() + ":\n	Rất xin lỗi, muốn nhận được phần thưởng , vui lòng để trống hành trang. Nếu như kinh nghiệm cùng tiềm năng đạt tới giới hạn, cũng không thể nhận được." + ESC"Xác nhận\n");
		return;
	}

	switch (top)
	{
	case 1:
		give_to_user(player, 1, ITEM_TOP_1);
		break;
	case 2:
		give_to_user(player, 1, ITEM_TOP_2);
		break;
	case 3:
		give_to_user(player, 1, ITEM_TOP_3);
		break;
	default:
		break;
	}

	player->add_potential(potential);
	player->add_cash(cash);
	set_save_2(sprintf("player.%d.bonus", id), 1);
	save();
}


