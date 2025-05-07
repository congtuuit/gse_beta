#include <ansi.h>
// 函数：命令处理
int main(object me, string arg)
{
	mixed* dfile;
	string path, file;
	int i, size;

	if (is_player(me))
	{
		notify("Bạn không có đủ quyền。");
		return 1;
	}

	if (!arg) arg = ".";

	path = absolute_path(me, arg); 
	if (directory_exist(path) && path[< 1] != '/') path += "/";

	dfile = get_dir(path) - ({ ".", ".." });

	if (!(size = sizeof(dfile)))
	{
		return 1;
	}

	path = path[0 ..strchr(path, '/', -1) + 1];

	if (path[0..5] == "/data/")
	{
		notify("Không thể quét /data ！");
		return 1;
	}
	if (path[0..4] == "/log/")
	{
		notify("Không thể quét /log ！");
		return 1;
	}

	tell_user(me, "Quét các thư mục: %s", path);

	for (i = 0; i < size; i++)
	{
		file = path + dfile[i];

		tell_user(me, sprintf(HIG"file: %s", dfile[i]));


		if (path[0..4] == "/BIN/")
		{
			continue;
		}

		if (dfile[i] == "debug")
		{
			continue;
		}


		if (directory_exist(file))
		{
			main(me, file + "/");
		}
		else
		{
			if (file[< 2.. < 1] == ".c")
			{
				"/cmd/debug/update"->main(me, file);
			}
		}
	}

	return 1;
}
