#include <time.h>
#include <ansi.h>
#include <cmd.h>

#include <npc.h>
#include <city.h>
#include <action.h>
#include <effect.h>
#include <skill.h>
#include <public.h>

#define DATA_KNB "data/KnbDatabase.dat"
#define YUANBAO "sys/sys/test_db"

void SAVE_BINARY() {}

int timeRecall = 10;
int rate = 0;

void create()
{
	call_out("check_time", 1);
}

void napknb()
{
	int flag, id, gender, userId, intAmount = 0, intUser, checked, p;
	int i, size;
	object who, item;
	string *line, strAmount = "0", content = "", *data, user = "0";
	string item_name;
	string result;
	int item_number, totalValue;

	if (!file_exist(DATA_KNB))
	{
		ghi_file(DATA_KNB, sprintf(""));
	}

	// Định dạng nội dung
	// ID KNB
	line = explode(read_file(DATA_KNB), "\n");
	for (i = 0, size = sizeof(line); i < size; i++)
	{
		data = explode(line[i], " ");
		if ((who = find_any_char(data[0])))
		{
			strAmount = data[1];
			user = data[0];
			continue;
		}

		content += line[i] + "\n";
	}

	if (user == "0")
	{
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
		totalValue = (intAmount * 10);
		YUANBAO->add_yuanbao(who, totalValue);
		MAILBOX->sys_mail(who->get_id(), who->get_number(), sprintf("Bạn đã nạp thành công %d Kim Nguyên Bảo. Điểm cống hiến tăng %d điểm.", totalValue / 10, totalValue / 10));
		tell_user(who, sprintf(HIY "Bạn đã nạp thành công %d Kim Nguyên Bảo.", totalValue / 10));
		log_file("00NapKNB.txt", short_time() + sprintf("	ID %s Nạp KNB _ %d\n", who->get_id(), totalValue / 10));
	}

	rm(DATA_KNB);
	write_file(DATA_KNB, content);

	call_out("check_time", timeRecall);
}

void check_time()
{
	int iTime, rate, level, z, p, x, y;
	int i, *nScene, size;
	object who;
	mixed *mixTime;
	object robber;
	string errstr, *line, *data, *serverCheck, *dataServerCheck, *line_channel, *data_channel, errstr_channel;
	string content = "", fileData;

	remove_call_out("check_time");

	napknb();
}
