#include <ansi.h>
// 函数：命令处理
int main(object me, string arg)
{
	mixed* dfile, * dfile2;
	string path, file, file2, path2;
	int i, size, size2, j;

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


	for (i = 0; i < size; i++)
	{
		if (path[0..4] == "/BIN/")
		{
			//tell_user(me, "Bỏ qua BIN folder");
			continue;
		}

		if (path[0..4] == "/.vs/")
		{
			tell_user(me, "Bỏ qua .vs folder");
			continue;
		}

		file = path + dfile[i];

		tell_user(me, HIG"Quét các thư mục: %s", path);

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
