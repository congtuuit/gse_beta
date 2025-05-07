#include <ansi.h>
#include <equip.h>
#include <item.h>
#include <effect.h>
#include <public.h>
#include <task.h>
#include <npc.h>
#include <cmd.h>
#include <city.h>

int is_loggedin(string path, string content) {
	int i, sizeFile;
	string* line, *data;

	line = explode(read_file(path, "\n");
	for (i = 0, sizeFile = sizeof(line); i < sizeFile; i++)
	{
		if (line[i] == content) {
			return 1;
		}

	}

	return 0;
}

void remove_login(string path, object user) {
	int i, sizeFile;
	string* line, * data, newContents="";

	line = explode(read_file(path, "\n");
	for (i = 0, sizeFile = sizeof(line); i < sizeFile; i++)
	{
		data = explode(line[i], ">");

		if (user->get_id() == data[0]) {
			continue;
		}

		if (user->get_id() == data[0]+"#2" ||
			user->get_id() == data[0] + "#3"||
			user->get_id() == data[0] + "#4"||
			user->get_id() == data[0] + "#5"||
			user->get_id() == data[0] + "#6"
			) {
			continue;
		}

		newContents += line[i] + "\n";
	}

	rm(path);
	write_file(path, newContents);
}