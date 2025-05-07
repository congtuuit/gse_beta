
// 函数：命令处理
int main(object me, string arg)
{
	object obj;
	string name, func, file;

	if (is_player(me))
	{
		notify("。");
		return 1;
	}

	if (!arg || (sscanf(arg, "%s of %s", func, name) != 2
		&& sscanf(arg, "%s %s", name, func) != 2))
	{
		notify("Có chức năng làm bạn muốn tìm？");
		return 1;
	}

	if (!(obj = find_any_object(name)))
	{
		notify("Không thể tìm thấy bất cứ điều gì như thế này.。");
		return 1;
	}

	if (!(file = function_exists(func, obj)))
		tell_user(me, "对象: %O\n函数 %s() 不存在。", obj, func);
	else    tell_user(me, "对象: %O\n定义: %s.c -> %s()。", obj, file, func);

	return 1;
}
