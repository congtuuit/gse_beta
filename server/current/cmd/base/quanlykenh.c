#include <advance.h>
#include <public.h>

int main(object me, string arg)
{
	return 0;
}

int is_loggedin(string path, string content, int region) {
	int i, sizeFile, isExist = 0;
	string* line, * data, fileData;

	if (!file_exist(path)) {
		return 0;
	}

	fileData = read_file(path);
	if (strlen(fileData) < 2) {
		return 0;
	}

	line = explode(fileData, "\n");

	if (sizeof(line) < 1)
		return 0;

	for (i = 0; i < sizeof(line); i++)
	{
		data = explode(line[i], ">");

		if (data[0] == content) {
			if (to_int(data[1]) != region) {
				isExist = to_int(data[1]);
			}
			else {
				isExist = -1;
			}
			break;
		}
	}

	return isExist;
}

int is_logged_other(string userid) {
	int i, sizeFile, isExist = 0;
	string* line, * data, fileData, path, userAccout;
	path = HELPERS->get_login_txt();

	if (!file_exist(path)) {
		return 0;
	}

	fileData = read_file(path);
	if (strlen(fileData) < 2) {
		return 0;
	}

	line = explode(fileData, "\n");
	if (sizeof(line) < 1)
		return 0;

	isExist = 0;
	for (i = 0; i < sizeof(line); i++)
	{
		data = explode(line[i], ">");
		if (userid == data[0] + "#2" ||
			userid == data[0] + "#3" ||
			userid == data[0] + "#4" ||
			userid == data[0] + "#5" ||
			userid == data[0] + "#6"
			) {

			if (to_int(data[1]) != MAIN_D->get_region()) {
				isExist = 1;
				break;
			}
		}
	}

	return isExist;
}

void remove_login(string path, object user) {
	int i, sizeFile;
	string* line, * data, newContents = "", fileData;

	if (!file_exist(path)) {
		return;
	}

	fileData = read_file(path);

	if (strlen(fileData) < 2) {
		return;
	}

	line = explode(fileData, "\n");
	for (i = 0, sizeFile = sizeof(line); i < sizeFile; i++)
	{
		data = explode(line[i], ">");

		if (user->get_id() == data[0]) {
			continue;
		}

		if (user->get_id() == data[0] + "#2" ||
			user->get_id() == data[0] + "#3" ||
			user->get_id() == data[0] + "#4" ||
			user->get_id() == data[0] + "#5" ||
			user->get_id() == data[0] + "#6"
			) {
			continue;
		}

		newContents += line[i] + "\n";
	}

	rm(path);
	write_file(path, newContents);
}

void addVipChat(string name, string chatContents) {
	string filePath, path;
	int hostNumber, totalChannel = 4;

	hostNumber = MAIN_D->get_region();
	filePath = HELPERS->get_vip_chat();
	for (int i = 1; i <= totalChannel; i++) {
		if (hostNumber == i) {
			continue;
		}

		path = sprintf("%s_%d%s", filePath, i, SAVE_EXTENSION);
		if (!file_exist(path)) {
			ghi_file(path, sprintf(""));
		}
		ghi_file(path, sprintf("%d;%s;%s\n", hostNumber, name, chatContents));
	}
}

void addOrgChat(string orgName, string name, string chatContents) {
	string filePath, path;
	int hostNumber, totalChannel = 4;

	hostNumber = MAIN_D->get_region();
	filePath = HELPERS->get_org_chat();
	for (int i = 1; i <= totalChannel; i++) {
		if (hostNumber == i) {
			continue;
		}

		path = sprintf("%s_%d%s", filePath, i, SAVE_EXTENSION);
		if (!file_exist(path)) {
			ghi_file(path, sprintf(""));
		}
		ghi_file(path, sprintf("%d;%s;%s\n", hostNumber, name, chatContents));
	}
	ghi_file(filePath, sprintf("%d;%s;%s;%s\n", hostNumber, orgName,name, chatContents));
}

void baotri(string type) {
	string filePath;
	filePath = HELPERS->get_baotri_txt();
	if (!file_exist(filePath)) {
		ghi_file(filePath, sprintf(""));
	}

	if (type == "on" || type == "true") {
		ghi_file(filePath, "1");
	}
	else {
		rm(filePath);
		ghi_file(filePath, "");
	}
}