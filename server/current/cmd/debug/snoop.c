
#include <ansi.h>

// 函数：命令处理
int main(object me, string arg)
{
	object who;

	if (is_player(me))
	{
		notify("。");
		return 1;
	}

	if (!arg) return 1;

	if (arg == "none")
	{
		who->set_snooper(0);
		tell_user(me, "您停止监听");
		return 1;
	}

	if (!arg)
	{
		notify("您要监听哪位玩家？");
		return 1;
	}

	if (!(who = find_player(arg)))
	{
		notify("Bạn không thể tìm người đàn ông này.。");
		return 1;
	}
	who->set_snooper(me);
	tell_user(me, "Bạn bắt đầu lắng nghe. %s(%d)。", who->get_name(), who->get_number());


	return 1;
}
