#include <time.h>
#include <ansi.h>
#include <cmd.h>
#include <npc.h>
#include <city.h>
#include <action.h>
#include <effect.h>
#include <skill.h>
#include <public.h>
#include <advance.h>

mapping mpNianshou;
void SAVE_BINARY() { }

void create()
{
	call_out("check_time", 1);
}

void check_time()
{
	int iTime, rate, level, z, p, x, y;
	int i, * nScene, size, hostNumber;
	mixed* mixTime;
	object robber;
	string errstr, * line, * data, * serverCheck, * dataServerCheck, * line_channel, * data_channel, errstr_channel;
	string content = "", fileData, path;

	remove_call_out("check_time");

	// path = HELPERS->get_vip_chat();
	hostNumber = MAIN_D->get_region();
	path = sprintf("%s_%d%s", path, hostNumber, SAVE_EXTENSION);
	if (!file_exist(path)) {
		ghi_file(path, sprintf(""));
	}
	fileData = read_file(path);

	if (strlen(fileData) < 2) {
		call_out("check_time", 1);
		return;
	}

    line = explode(fileData, "\n");
	if (sizeof(line) < 1) {
		call_out("check_time", 1);
		return;
	}

	for (i = 0, size = sizeof(line); i < size; i++)
	{
		if (line[i] == "") {
			continue;
		}

		data = explode(line[i], ";");

		if (MAIN_D->get_region() != to_int(data[0])) {
			"/cmd/base/vipchat_2"->say(data[0], data[1], data[2]);
		}
		else {
			content += line[i] + "\n";
		}

	}

	rm(path);
	write_file(path, content);

	call_out("check_time", 1);
}