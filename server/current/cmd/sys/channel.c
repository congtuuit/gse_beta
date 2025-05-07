
// 函数：命令处理
int main(object me, string arg)
{
	object item;

	if (!arg)
	{
		notify("您要将哪样东西变成蓝色？");
		return 1;
	}

	if (!(item = find_any_object(arg)))
	{
		notify("无法找到这样东西。");
		return 1;
	}
	if (item == me)
	{
		notify("您连自己都想清除？");
		return 1;
	}

	
	tell_user(me, "%s deleted", item->get_name());
	item->remove_from_user();
	destruct(item);

	return 1;
}


//int is_loggedin(string path, string content) {
//	int i, sizeFile;
//	string* line, * data;
//
//	line = explode(read_file(path, "\n");
//	/*for (i = 0; i < sizeof(line); i++)
//	{
//		if (line[i] == content) {
//			return 1;
//		}
//
//	}*/
//
//	return 0;
//}
//
//void remove_login(string path, object user) {
//	int i, sizeFile;
//	string* line, * data, newContents = "";
//
//	line = explode(read_file(path, "\n");
//	for (i = 0, sizeFile = sizeof(line); i < sizeFile; i++)
//	{
//		data = explode(line[i], ">");
//
//		if (user->get_id() == data[0]) {
//			continue;
//		}
//
//		if (user->get_id() == data[0] + "#2" ||
//			user->get_id() == data[0] + "#3" ||
//			user->get_id() == data[0] + "#4" ||
//			user->get_id() == data[0] + "#5" ||
//			user->get_id() == data[0] + "#6"
//			) {
//			continue;
//		}
//
//		newContents += line[i] + "\n";
//	}
//
//	rm(path);
//	write_file(path, newContents);
//}