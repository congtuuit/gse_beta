
// 函数：命令处理
int main(object me, string arg)
{
	object item;

	if (is_player(me))
	{
		notify("Bạn không có đủ quyền。");
		return 1;
	}

	if (!arg)
	{
		notify("Bạn muốn biến vàng thành gì?");
		return 1;
	}

	if (!(item = find_any_object(arg)))
	{
		notify("Không thể tìm thấy một cái gì đó như thế này。");
		return 1;
	}
	if (item == me)
	{
		notify("Bạn muốn làm rõ chính mình？");
		return 1;
	}
	if (item->get_equip_type() == 0)
	{
		notify("Chỉ có thể biến bánh răng thành vàng");
		return 1;
	}

	tell_user(me, "Bạn sẽ %s thành hoàng kim。", item->get_name());

	"/sys/item/equip"->init_equip_prop_3(item);
	send_user(me, "%c%d%c", 0x31, getoid(item), 0);

	return 1;
}
