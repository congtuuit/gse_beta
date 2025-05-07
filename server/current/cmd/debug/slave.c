
#include <ansi.h>

// 函数：命令处理
int main(object me, string arg)
{
	object* zombie, soldier;
	string result;
	int level, i, j, size;

	if (me != this_player(1) || is_player(me))
	{
		notify("Bạn không có đủ quyền。");
		return 1;
	}

	if (!arg)
	{
		send_user(me, "%c%s", ':', "Có bao nhiêu cấp độ bạn muốn nâng cao con thú gọi?\n"
			ESC "２Cấp\nslave 2\n"
			ESC "３Cấp\nslave 3\n"
			ESC "４Cấp\nslave 4\n"
			ESC "５Cấp\nslave 5\n"
			ESC "Rời đi\nCLOSE\n");
		return 1;
	}

	level = range_value(to_int(arg), 1, 5);

	if (arrayp(zombie = me->get("zombie"))
		&& arrayp(zombie = filter_array(zombie - ({ 0 }), (: $1->get_owner() == $2 : ), me))    // 清除叛变的怪
		&& (size = sizeof(zombie)))    // zombie -= ({ 0 })
		me->set("zombie", zombie);
	else    zombie = ({ });

	if (objectp(soldier = me->get("soldier"))) zombie += ({ soldier });

	result = "";
	size = sizeof(zombie);
	if (size == 0)
	{
		notify("Bạn không gọi con thú đó.");
		return 1;
	}
	for (i = 0; i < size; i++) if (zombie[i])
	{
		for (j = zombie[i]->get_level_2(); j < level; j++)
		{
			zombie[i]->set_level_2(j + 1);
			zombie[i]->upgrade_level(j + 1);
			zombie[i]->upgrade_level_2(j + 1);
		}
		result += sprintf("%s(%x#)Cấp：%d\n", zombie[i]->get_name(), getoid(zombie[i]), zombie[i]->get_level_2());
	}
	tell_user(me, result);

	return 1;
}
