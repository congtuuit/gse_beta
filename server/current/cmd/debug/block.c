
// 函数：命令处理
int main(object me, string arg)
{
	object item;

	if (is_player(me))
	{
		notify("。");
		return 1;
	}

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

	item->set_no_give(1);
	item->set_no_sell(1);
	item->set_no_drop(1);

	tell_user(me, "Đã khóa trang bị %s。", item->get_name());
	send_user(me, "%c%d%c", 0x31, getoid(item), 0);

	return 1;
}
