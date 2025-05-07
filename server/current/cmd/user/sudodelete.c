
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
