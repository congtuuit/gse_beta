void update_dir(object me, string arg);

// 函数：命令处理
int main(object me, string arg)
{
	object obj;
	string file, err;

	if (is_player(me))
	{
		notify("Bạn không có đủ quyền。");
		return 1;
	}

	if (!arg)
	{
		notify("Bạn muốn cập nhật một cái gì đó？");
		return 1;
	}
	if (file_size(arg) == -2)
	{
		log_file("updatefile.txt", short_time() + " thư mục build：" + arg + "\n");
		update_dir(me, arg);
		tell_user(me, "biên dịch ok");
		return 1;
	}
	if (obj = find_any_object(arg)) file = get_file_name(obj) + ".c";
	else if (file_exist(file = absolute_path(me, arg)));
	else if (file_exist(file = absolute_path(me, arg + ".c")));
	else if (file_exist(absolute_path(me, arg + ".cpp"))) file = absolute_path(me, arg + ".c");
	else if (arg == "cwf") file = me->get_cwf();
	else
	{
		notify("Bạn không thể tìm thấy đối tượng này。");
		return 1;
	}

	me->set_cwf(file);
	tell_user(me, "biên dịch lại: " + file);

	if (obj = find_object(file))
	{
		obj->before_destruct();
		destruct(obj);
	}

	if (obj)
	{
		tell_user(me, "Không thể gỡ bỏ các chương trình cũ。");
		return 1;
	}

	if (err = catch (call_other(file, "???")))
		tell_user(me, "Có lỗi xảy ra！\n%s", err);
	else    tell_user(me, "hoàn thành cập nhật！");

	return 1;
}
int update_file(object me, string arg)
{
	object obj;
	string file, err;

	if (obj = find_any_object(arg)) file = get_file_name(obj) + ".c";
	else if (file_exist(file = absolute_path(me, arg)));
	else if (file_exist(file = absolute_path(me, arg + ".c")));
	else if (file_exist(absolute_path(me, arg + ".cpp"))) file = absolute_path(me, arg + ".c");
	else if (arg == "cwf") file = me->get_cwf();
	else
	{
		log_file("updatefile.txt", sprintf("%s %s can't find obj\n", short_time(), arg));
		return 1;
	}

	log_file("updatefile.txt", "Biên dịch " + file + "\n");
	if (obj = find_object(file))
	{
		obj->before_destruct();
		destruct(obj);
	}

	if (obj)
	{
		tell_user(me, "Không thể để hủy bỏ chương trình cũ。");
		return 1;
	}

	if (err = catch (call_other(file, "???")))
		log_file("updatefile.txt", err + "\n");
	return 1;
}
void update_dir(object me, string arg)
{
	int i, size;
	mixed* mxTmp;

	mxTmp = get_dir(arg);
	for (i = 0, size = sizeof(mxTmp); i < size; i++)
	{
		if (mxTmp[i] == ".svn")
			continue;
		if (mxTmp[i] == ".vs")
			continue;
		if (file_size(arg + mxTmp[i]) == -2)
			update_dir(me, arg + mxTmp[i] + "/");
		if (strstr(mxTmp[i], ".c") == -1)
			continue;
		//		tell_user(me,"%s %s",arg,mxTmp[i]);
		update_file(me, arg + mxTmp[i]);
	}
}